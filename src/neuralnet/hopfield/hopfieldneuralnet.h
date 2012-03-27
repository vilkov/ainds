#ifndef HOPFIELDNEURALNET_H_
#define HOPFIELDNEURALNET_H_

#include "hopfieldlayer.h"
#include "../abstract/neuralnet.h"


NEURAL_NET_NS_BEGIN

class HopfieldNeuralNet : public NeuralNet
{
public:
	typedef HopfieldLayer::Patterns Patterns;

public:
	HopfieldNeuralNet(const Patterns &patterns);

	virtual void addLayer(quint32 dimension);
    virtual const Output &compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* HOPFIELDNEURALNET_H_ */
