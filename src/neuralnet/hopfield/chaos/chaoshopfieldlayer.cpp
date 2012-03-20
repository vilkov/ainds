#include "chaoshopfieldlayer.h"
#include "chaoshopfieldneuron.h"


NEURAL_NET_NS_BEGIN

ChaosHopfieldLayer::ChaosHopfieldLayer(quint32 dimension) :
	Layer(dimension)
{
	for (quint32 i = 0; i < dimension; ++i)
		neurons().push_back(new ChaosHopfieldNeuron(dimension));
}

ChaosHopfieldLayer::ChaosHopfieldLayer(const Weights &weights) :
	Layer(weights)
{
	for (Weights::size_type i = 0, size = weights.size(); i < size; ++i)
		neurons().push_back(new ChaosHopfieldNeuron(weights.at(i)));
}

const ChaosHopfieldLayer::Output &ChaosHopfieldLayer::compute(const Input &input)
{
	for (Neurons::size_type i = 0, size = neurons().size(); i < size; ++i)
		m_output[i] = neurons().at(i)->compute(input);

	return m_output;
}

NEURAL_NET_NS_END
