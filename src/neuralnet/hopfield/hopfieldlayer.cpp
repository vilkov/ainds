#include "hopfieldlayer.h"
#include "hopfieldneuron.h"


NEURAL_NET_NS_BEGIN

HopfieldLayer::HopfieldLayer(const Patterns &patterns) :
	m_neurons(patterns.at(0).size()),
	m_weights(Tools::MatrixNxN::correlation(patterns).setDiagonal(0))
{}

const HopfieldLayer::Output &HopfieldLayer::compute(const Input &input)
{
	Output output(m_neurons.size());

	for (Neurons::size_type i = 0, size = m_neurons.size(); i < size; ++i)
		m_neurons[i] = input.at(i);

	do
	{
		for (Neurons::size_type i = 0, size = m_neurons.size(); i < size; ++i)
			output[i] = m_neurons[i];

		for (Neurons::size_type q, i = 0, size = m_neurons.size(); i < size; ++i)
			for (q = 0; q < size; ++q)
				m_neurons[i] += output[i] * m_weights[i][q];
	}
	while (output != m_neurons);

	return m_neurons;
}

NEURAL_NET_NS_END
