#ifndef CHAOSHOPFIELDNEURALNET_H_
#define CHAOSHOPFIELDNEURALNET_H_

#include "../../abstract/neuralnet.h"


NEURAL_NET_NS_BEGIN

class ChaosHopfieldNeuralNet : public NeuralNet
{
public:
	ChaosHopfieldNeuralNet(quint32 dimension);
	ChaosHopfieldNeuralNet(const Layer::Weights &weights);

	virtual void addLayer(quint32 dimension);
	virtual void addLayer(const Layer::Weights &weights);

    virtual const Output &compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* CHAOSHOPFIELDNEURALNET_H_ */
