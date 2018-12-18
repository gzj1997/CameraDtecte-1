#include "CameraDtecte1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	
	try 
	{
		PylonAutoInitTerm autoInitTerm;
		Pylon::PylonInitialize();
		QApplication a(argc, argv);
		CameraDtecte1 w;
		w.show();
		a.exec();
	}
	catch (exception e ) {

		qDebug() << e.what();
	}
	Pylon::PylonTerminate();
	return 0;
}
