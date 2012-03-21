#include "hopfieldlayer.h"
#include "hopfieldneuron.h"


NEURAL_NET_NS_BEGIN

HopfieldLayer::HopfieldLayer(const Patterns &patterns) :
	m_output(patterns.at(0).size()),
	m_neurons(patterns.at(0).size()),
	m_weights(patterns.at(0).size())
{

}

const HopfieldLayer::Output &HopfieldLayer::compute(const Input &input)
{

	for (Neurons::size_type i = 0, size = neurons().size(); i < size; ++i)
		m_output[i] = neurons().at(i)->compute(input);

	return m_output;
}

NEURAL_NET_NS_END
