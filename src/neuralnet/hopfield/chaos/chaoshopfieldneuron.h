#ifndef CHAOSHOPFIELDNEURON_H_
#define CHAOSHOPFIELDNEURON_H_

#include "../../abstract/neuron.h"


NEURAL_NET_NS_BEGIN

class ChaosHopfieldNeuron : public Neuron
{
public:
	ChaosHopfieldNeuron(quint32 dimension);
	ChaosHopfieldNeuron(const Weights &weights);

    virtual Output compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* CHAOSHOPFIELDNEURON_H_ */
