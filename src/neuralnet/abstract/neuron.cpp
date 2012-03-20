#include "neuron.h"


NEURAL_NET_NS_BEGIN

Neuron::Neuron(quint32 dimension) :
	m_output(0),
	m_weights(dimension)
{
	Q_ASSERT(dimension);
}

Neuron::Neuron(const Weights &weights) :
	m_output(0),
	m_weights(weights)
{
	Q_ASSERT(m_weights.size());
}

Neuron::~Neuron()
{}

NEURAL_NET_NS_END
