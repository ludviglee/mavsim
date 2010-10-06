/*
 * MainWindow.cpp * Copyright (C) James Goppert 2010 <james.goppert@gmail.com>
 * * MainWindow.cpp is free software: you can redistribute it and/or modify it * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MainWindow.cpp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MainWindow.hpp"
#include <QFileDialog>

namespace oooark
{

MainWindow::MainWindow() : 
	earthManipulator(new osgEarthUtil::EarthManipulator), objectPlacer()//, comm(NULL), serial(NULL), stream(NULL)
{
	setupUi(this);
	map->setCameraManipulator(new osgEarthUtil::EarthManipulator);
	map->setSceneData(new osg::Group);
	map->show();

}

MainWindow::~MainWindow()
{
	delete map;
}

//Communication
void MainWindow::updateComm()
{
	comm->update();
}

// control

void MainWindow::on_pushButton_getGains_clicked()
{
	std::cout << "get gains" << std::endl;
}

void MainWindow::on_pushButton_sendGains_clicked()
{
	std::cout << "send gains" << std::endl;
}

void MainWindow::on_pushButton_returnHome_clicked()
{
	std::cout << "return home" << std::endl;
}

void MainWindow::on_pushButton_loiter_clicked()
{
	std::cout << "loiter" << std::endl;
}

void MainWindow::on_pushButton_land_clicked()
{
	std::cout << "land" << std::endl;
}

void MainWindow::on_pushButton_killThrottle_clicked()
{
	std::cout << "kill throttle" << std::endl;
}

// configuration
void MainWindow::on_comboBox_units_activated()
{
	std::cout << "units" << std::endl;
}

void MainWindow::on_pushButton_gainsSendFile_clicked()
{
	std::cout << "send gains file" << std::endl;
}

void MainWindow::on_pushButton_gainsRequestFile_clicked()
{
	std::cout << "get gains file" << std::endl;
}

void MainWindow::on_pushButton_cameraDevice_clicked()
{
	std::cout << "select camera device" << std::endl;
}

void MainWindow::on_pushButton_vehicleFile_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Vehicle Model File"),
       ".", tr("3D Model Files (*.osg *.ac)"));

    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
    if (!loadedModel)
    {
        std::cout << "model not loaded" << std::endl;
    }
	map->getSceneData()->asGroup()->addChild(loadedModel);

	//Setup Comm
	if(serial) delete serial;
	if(stream) delete stream;
	if(comm) delete comm;
	if(timer) delete timer;

	serial = new BufferedAsyncSerial(device,baud);
	stream = new Stream(serial);
	comm = new BinComm(handlerTable, stream);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateComm()));
	timer->start(99);
}

void MainWindow::on_pushButton_mapFile_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open OSGEarth Map File"),
       ".", tr("OSGEarth Files (*.earth)"));

    osg::ref_ptr<osg::Node> loadedMap = osgDB::readNodeFile(fileName.toStdString());
    if (!loadedMap)
    {
        std::cout << "map not loaded" << std::endl;
    }
	if(loadedMap.valid())
	{
		if (map->getSceneData()) map->setSceneData(NULL);
		map->setSceneData(loadedMap);
		objectPlacer = new osgEarthUtil::ObjectPlacer(loadedMap);
	}
	else
	{
		std::cout<<"map not valid"<<std::endl;
	}

}

void MainWindow::on_pushButton_telemetryPort_clicked()
{
	std::cout << "select telemetry port" << std::endl;
}

// terminal
void MainWindow::on_pushButton_sendCommand_clicked()
{
	std::cout << "send command" << std::endl;
}

// guidance
void MainWindow::on_pushButton_getFlightPlan_clicked()
{
	std::cout << "get flight plan" << std::endl;
}

void MainWindow::on_pushButton_sendFlightPlan_clicked()
{
	std::cout << "send flight plan" << std::endl;
}

void MainWindow::on_pushButton_clearFlightPlan_clicked()
{
	std::cout << "clear flight plan" << std::endl;
}

void MainWindow::on_pushButton_loadFlightPlan_clicked()
{
	std::cout << "load flight plan" << std::endl;
}

} // oooark


// vim:ts=4:sw=4
