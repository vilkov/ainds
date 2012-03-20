#include "layer.h"


NEURAL_NET_NS_BEGIN

Layer::Layer(quint32 dimension) :
	m_neurons(dimension)
{
	Q_ASSERT(dimension);
}

Layer::Layer(const Weights &weights) :
	m_neurons(weights.size())
{
	Q_ASSERT(weights.size());
}

Layer::~Layer()
{
	qDeleteAll(m_neurons);
}

NEURAL_NET_NS_END
