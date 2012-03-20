#include "neuralnet.h"


NEURAL_NET_NS_BEGIN

NeuralNet::NeuralNet()
{}

NeuralNet::~NeuralNet()
{
	qDeleteAll(m_layers);
}

NEURAL_NET_NS_END
