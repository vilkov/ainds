#include <QtGui/QApplication>
#include <QtGui/QGenericMatrix>
#include <QtGui/QMessageBox>
#include "../neuralnet/hopfield/hopfieldneuralnet.h"


int main(int argc, char *argv[])
{
	Aidns::NeuralNet::HopfieldNeuralNet net(100);



	QApplication app(argc, argv);


    return app.exec();
}
