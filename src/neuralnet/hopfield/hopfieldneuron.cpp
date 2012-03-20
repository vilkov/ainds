#include "hopfieldneuron.h"


NEURAL_NET_NS_BEGIN

HopfieldNeuron::HopfieldNeuron(quint32 dimension) :
	Neuron(dimension)
{
	for (Weights::size_type i = 0, size = weights().size(); i < size; ++i)
		weights()[i] = qrand();
}

HopfieldNeuron::HopfieldNeuron(const Weights &weights) :
	Neuron(weights)
{}

HopfieldNeuron::Output HopfieldNeuron::compute(const Input &input)
{
	Q_ASSERT_X(weights().size() == input.size(), "HopfieldNeuron::compute", "Dimension mismatch!");

	m_output = 0;

	for (Input::size_type i = 0, size = input.size(); i < size; ++i)
		m_output += weights().at(i) * input.at(i);

	if (m_output > 0)
		m_output = 1;
	else
		if (m_output < 0)
			m_output = -1;

	return m_output;
}

NEURAL_NET_NS_END
