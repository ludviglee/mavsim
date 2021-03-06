#! /usr/bin/env python
# encoding: utf-8
# WARNING! Do not edit! http://waf.googlecode.com/svn/docs/wafbook/single.html#_obtaining_the_waf_file

import sys
if sys.hexversion < 0x020400f0: from sets import Set as set
import copy,re
from waflib import Logs,Utils
re_imp=re.compile('^(#)*?([^#=]*?)\ =\ (.*?)$',re.M)
class ConfigSet(object):
	__slots__=('table','parent')
	def __init__(self,filename=None):
		self.table={}
		if filename:
			self.load(filename)
	def __contains__(self,key):
		if key in self.table:return True
		try:return self.parent.__contains__(key)
		except AttributeError:return False
	def keys(self):
		keys=set()
		cur=self
		while cur:
			keys.update(cur.table.keys())
			cur=getattr(cur,'parent',None)
		keys=list(keys)
		keys.sort()
		return keys
	def __str__(self):
		return"\n".join(["%r %r"%(x,self.__getitem__(x))for x in self.keys()])
	def __getitem__(self,key):
		try:
			while 1:
				x=self.table.get(key,None)
				if not x is None:
					return x
				self=self.parent
		except AttributeError:
			return[]
	def __setitem__(self,key,value):
		self.table[key]=value
	def __delitem__(self,key,value):
		del self.table[key]
	def __getattr__(self,name):
		if name in self.__slots__:
			return object.__getattr__(self,name)
		else:
			return self[name]
	def __setattr__(self,name,value):
		if name in self.__slots__:
			object.__setattr__(self,name,value)
		else:
			self[name]=value
	def __delattr__(self,name):
		if name in self.__slots__:
			object.__delattr__(self,name)
		else:
			del self[name]
	def derive(self):
		newenv=ConfigSet()
		newenv.parent=self
		return newenv
	def detach(self):
		tbl=self.get_merged_dict()
		try:
			delattr(self,'parent')
		except AttributeError:
			pass
		else:
			keys=tbl.keys()
			for x in keys:
				tbl[x]=copy.deepcopy(tbl[x])
			self.table=tbl
	def get_flat(self,key):
		s=self[key]
		if isinstance(s,str):return s
		return' '.join(s)
	def _get_list_value_for_modification(self,key):
		try:
			value=self.table[key]
		except KeyError:
			try:value=self.parent[key]
			except AttributeError:value=[]
			if isinstance(value,list):
				value=value[:]
			else:
				value=[value]
		else:
			if not isinstance(value,list):
				value=[value]
		self.table[key]=value
		return value
	def append_value(self,var,val):
		current_value=self._get_list_value_for_modification(var)
		if isinstance(val,str):
			val=[val]
		current_value.extend(val)
	def prepend_value(self,var,val):
		if isinstance(val,str):
			val=[val]
		self.table[var]=val+self._get_list_value_for_modification(var)
	def append_unique(self,var,val):
		if isinstance(val,str):
			val=[val]
		current_value=self._get_list_value_for_modification(var)
		for x in val:
			if x not in current_value:
				current_value.append(x)
	def get_merged_dict(self):
		table_list=[]
		env=self
		while 1:
			table_list.insert(0,env.table)
			try:env=env.parent
			except AttributeError:break
		merged_table={}
		for table in table_list:
			merged_table.update(table)
		return merged_table
	def store(self,filename):
		f=None
		try:
			f=open(filename,'w')
			merged_table=self.get_merged_dict()
			keys=list(merged_table.keys())
			keys.sort()
			for k in keys:
				if k!='undo_stack':
					f.write('%s = %r\n'%(k,merged_table[k]))
		finally:
			if f:
				f.close()
	def load(self,filename):
		tbl=self.table
		code=Utils.readf(filename)
		for m in re_imp.finditer(code):
			g=m.group
			tbl[g(2)]=eval(g(3))
		Logs.debug('env: %s'%str(self.table))
	def update(self,d):
		for k,v in d.items():
			self[k]=v
	def stash(self):
		self.undo_stack=self.undo_stack+[self.table]
		self.table=self.table.copy()
	def revert(self):
		self.table=self.undo_stack.pop(-1)
