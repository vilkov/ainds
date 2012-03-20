#include "hopfieldneuralnet.h"
#include "hopfieldlayer.h"


NEURAL_NET_NS_BEGIN

HopfieldNeuralNet::HopfieldNeuralNet(quint32 dimension) :
	NeuralNet()
{
	layers().push_back(new HopfieldLayer(dimension));
}

HopfieldNeuralNet::HopfieldNeuralNet(const Layer::Weights &weights) :
	NeuralNet()
{
	layers().push_back(new HopfieldLayer(weights));
}

void HopfieldNeuralNet::addLayer(quint32 dimension)
{
	Q_ASSERT_X(false, "HopfieldNeuralNet::addLayer", "Hopfield neural net is one layer net!");
}

void HopfieldNeuralNet::addLayer(const Layer::Weights &weights)
{
	Q_ASSERT_X(false, "HopfieldNeuralNet::addLayer", "Hopfield neural net is one layer net!");
}

const HopfieldNeuralNet::Output &HopfieldNeuralNet::compute(const Input &input)
{
	Q_ASSERT(layers().size() == 1);
	return layers().at(0)->compute(input);
}

NEURAL_NET_NS_END
