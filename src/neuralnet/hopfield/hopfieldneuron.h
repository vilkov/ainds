#ifndef HOPFIELDNEURON_H_
#define HOPFIELDNEURON_H_

#include "../abstract/neuron.h"


NEURAL_NET_NS_BEGIN

class HopfieldNeuron : public Neuron
{
public:
	HopfieldNeuron(quint32 dimension);
	HopfieldNeuron(const Weights &weights);

    virtual Output compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* HOPFIELDNEURON_H_ */
