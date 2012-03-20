#ifndef LAYER_H_
#define LAYER_H_

#include "neuron.h"


NEURAL_NET_NS_BEGIN

class Layer
{
public:
	typedef Neuron::Input            Input;
	typedef QVector<Neuron::Output>  Output;
	typedef QVector<Neuron *>        Neurons;
	typedef QVector<Neuron::Weights> Weights;

public:
	Layer(quint32 dimension);
	Layer(const Weights &weights);
	virtual ~Layer();

	const Neurons &neurons() const { return m_neurons; }

	virtual const Output &compute(const Input &input) = 0;

protected:
	Neurons &neurons() { return m_neurons; }

private:
	Neurons m_neurons;
};

NEURAL_NET_NS_END

#endif /* LAYER_H_ */
