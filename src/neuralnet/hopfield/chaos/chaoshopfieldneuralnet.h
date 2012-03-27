#ifndef CHAOSHOPFIELDNEURALNET_H_
#define CHAOSHOPFIELDNEURALNET_H_

#include "chaoshopfieldlayer.h"
#include "../../abstract/neuralnet.h"


NEURAL_NET_NS_BEGIN

class ChaosHopfieldNeuralNet : public NeuralNet
{
public:
	typedef ChaosHopfieldLayer::Patterns Patterns;

public:
	ChaosHopfieldNeuralNet(const Patterns &patterns);

	virtual void addLayer(quint32 dimension);
    virtual const Output &compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* CHAOSHOPFIELDNEURALNET_H_ */
