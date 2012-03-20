#include "chaoshopfieldneuralnet.h"
#include "chaoshopfieldlayer.h"


NEURAL_NET_NS_BEGIN

ChaosHopfieldNeuralNet::ChaosHopfieldNeuralNet(quint32 dimension) :
	NeuralNet()
{
	layers().push_back(new ChaosHopfieldLayer(dimension));
}

ChaosHopfieldNeuralNet::ChaosHopfieldNeuralNet(const Layer::Weights &weights) :
	NeuralNet()
{
	layers().push_back(new ChaosHopfieldLayer(weights));
}

void ChaosHopfieldNeuralNet::addLayer(quint32 dimension)
{
	Q_ASSERT_X(false, "ChaosHopfieldNeuralNet::addLayer", "Hopfield neural net is one layer net!");
}

void ChaosHopfieldNeuralNet::addLayer(const Layer::Weights &weights)
{
	Q_ASSERT_X(false, "ChaosHopfieldNeuralNet::addLayer", "Hopfield neural net is one layer net!");
}

const ChaosHopfieldNeuralNet::Output &ChaosHopfieldNeuralNet::compute(const Input &input)
{
	Q_ASSERT(layers().size() == 1);
	return layers().at(0)->compute(input);
}

NEURAL_NET_NS_END
