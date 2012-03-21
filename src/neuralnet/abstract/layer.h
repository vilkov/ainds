#ifndef LAYER_H_
#define LAYER_H_

#include "neuron.h"


NEURAL_NET_NS_BEGIN

class Layer
{
public:
	typedef Neuron::Input           Input;
	typedef QVector<Neuron::Output> Output;

public:
	virtual ~Layer();

	virtual const Output &compute(const Input &input) = 0;
};

NEURAL_NET_NS_END

#endif /* LAYER_H_ */
