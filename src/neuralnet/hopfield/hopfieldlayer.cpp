#include "hopfieldlayer.h"
#include "hopfieldneuron.h"


NEURAL_NET_NS_BEGIN

HopfieldLayer::HopfieldLayer(quint32 dimension) :
	Layer(dimension)
{
	for (quint32 i = 0; i < dimension; ++i)
		neurons().push_back(new HopfieldNeuron(dimension));
}

HopfieldLayer::HopfieldLayer(const Weights &weights) :
	Layer(weights)
{
	for (Weights::size_type i = 0, size = weights.size(); i < size; ++i)
		neurons().push_back(new HopfieldNeuron(weights.at(i)));
}

const HopfieldLayer::Output &HopfieldLayer::compute(const Input &input)
{
	for (Neurons::size_type i = 0, size = neurons().size(); i < size; ++i)
		m_output[i] = neurons().at(i)->compute(input);

	return m_output;
}

NEURAL_NET_NS_END
