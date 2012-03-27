#include "hopfieldlayer.h"


NEURAL_NET_NS_BEGIN

HopfieldLayer::HopfieldLayer(const Patterns &patterns) :
	m_neurons(patterns.at(0).size()),
	m_weights(Tools::MatrixNxN::correlation(patterns).setDiagonal(0))
{}

const HopfieldLayer::Output &HopfieldLayer::compute(const Input &input)
{
	qreal value;
	Output output(m_neurons.size());

	for (Neurons::size_type i = 0, size = m_neurons.size(); i < size; ++i)
		m_neurons[i] = input.at(i);

	do
	{
		for (Neurons::size_type i = 0, size = m_neurons.size(); i < size; ++i)
			output[i] = m_neurons[i];

		for (Neurons::size_type e, q, i = 0, size = m_neurons.size(); i < size; ++i)
		{
			for (value = 0, q = 0; q < size; ++q)
				for (e = 0; e < size; ++e)
					value += output[q] * m_weights[q][e];

			m_neurons[i] = value > 0 ? 1 : -1;
		}
	}
	while (output != m_neurons);

	return m_neurons;
}

NEURAL_NET_NS_END
