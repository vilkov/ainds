#include <QtGui/QApplication>
#include <QtGui/QGenericMatrix>
#include <QtGui/QMessageBox>
#include "../neuralnet/hopfield/hopfieldneuralnet.h"


int main(int argc, char *argv[])
{
	using namespace Aidns::NeuralNet;

	HopfieldNeuralNet::Patterns p;

	p << (Neuron::Input() <<  1 <<  1 << -1 <<  1);
	p << (Neuron::Input() <<  1 << -1 << -1 <<  1);
	p << (Neuron::Input() << -1 <<  1 <<  1 <<  1);

	HopfieldNeuralNet net(p);


	QApplication app(argc, argv);

	qDebug() << net.compute(Neuron::Input() <<  1 <<  1 << -1 <<  1);

	return app.exec();
}
