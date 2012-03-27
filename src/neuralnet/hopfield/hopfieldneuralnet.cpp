#include "hopfieldneuralnet.h"


NEURAL_NET_NS_BEGIN

HopfieldNeuralNet::HopfieldNeuralNet(const Patterns &patterns) :
	NeuralNet()
{
	layers().push_back(new HopfieldLayer(patterns));
}

void HopfieldNeuralNet::addLayer(quint32 dimension)
{
	Q_ASSERT_X(false, "HopfieldNeuralNet::addLayer", "Hopfield neural net is one layer net!");
}

const HopfieldNeuralNet::Output &HopfieldNeuralNet::compute(const Input &input)
{
	Q_ASSERT(layers().size() == 1);
	return layers().at(0)->compute(input);
}

NEURAL_NET_NS_END
