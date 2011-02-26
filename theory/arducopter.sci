clc; clear;
mode(-1);

// dependencies
exec utilities.sci;
exec quadForwardFlightDesign.sci;
exec quadHoverDesign.sci;

// constants
g=9.81; // m/s^2

// trim conditions
beta=0; // trim
wy=0; //trim
wz=0; //trim
wx=0; //trim
phi=0; //trim
psi=0; // trim
gamma=0; // flight path angle,for level flight is zero
// airframe
m=1;  //kg
Jy=0.05; // guess , moments of inertia
Jz=0.05; // guess
Jx=0.05; // guess

// aerodynamics
rho=1.225; // kg/m^3
rBlade=0.125; // metres
Cd0=0.42; // guess
K_cd_cl=0.02; //guess
s_frame=.1; //guess in m^2
s_frame_side=.1; // guess in m^2

// motor
KV=850 // rpm/Volts 
batVolt=11.1; //Volts
dm=.3; // guess in metres, motor moment arm
tau_motor=18; // guess, motor pole (rad/s)
T_max = 5; // max motor thrust in newtons
torque_max = 1; // max motor thrust in newton-m
C_T = T_max / (rho*%pi*rBlade^4*(KV*2*%pi/60*batVolt)^2);
C_Q = torque_max / (rho*%pi*rBlade^4*(KV*2*%pi/60*batVolt)^2);

// design controllers

// forward flight
//Vt=3; // airspeed, in m/s
//// output _ input
//Hf.wx_LR 		= 1*(%s+18)/(%s+40);
//Hf.wy_FB 		= 1*(%s+18)/(%s+40); 
//Hf.wz_LR_FB 	= 1*(%s+18)/(%s+40);
//Hf.phi_wx 		= 2.5; 		
//Hf.theta_wy 	= 2.5; 		
//Hf.psi_phi 		= 1.0; 		
//Hf.Vt_Sum 		= 0.001; 
//Hf.h_theta 		= 1.0;

//qwd = quadForwardFlightDesign(Hf);

//hover
U = 0; V = 0; W = 0; // hover
// output _ input
lowPassCut = 10*2*%pi; // 10 Hz cut freq
lowPass = lowPassCut/(%s+lowPassCut);
pd = (%s+tau_motor)/tau_motor;
Hh.wx_LR 		= 0.76*pd*lowPass;
Hh.wy_FB 		= 0.76*pd*lowPass;
Hh.W_Sum 		= -1.15*pd*lowPass;
Hh.wz_LR_FB 	= 2.3*pd*lowPass; 
Hh.phi_wx 		= 4.5*lowPass;
Hh.theta_wy 	= 4.5*lowPass;
Hh.psi_wz 		= 1*lowPass;
Hh.U_theta 		= -0.1*lowPass;
Hh.V_phi 		= 0.1*lowPass;
Hh.h_W 			= -1.1*lowPass;

qhd = quadHoverDesign(Hh);
