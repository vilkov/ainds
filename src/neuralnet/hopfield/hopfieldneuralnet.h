#ifndef HOPFIELDNEURALNET_H_
#define HOPFIELDNEURALNET_H_

#include "../abstract/neuralnet.h"


NEURAL_NET_NS_BEGIN

class HopfieldNeuralNet : public NeuralNet
{
public:
	HopfieldNeuralNet(quint32 dimension);
	HopfieldNeuralNet(const Layer::Weights &weights);

	virtual void addLayer(quint32 dimension);
	virtual void addLayer(const Layer::Weights &weights);

    virtual const Output &compute(const Input &input);
};

NEURAL_NET_NS_END

#endif /* HOPFIELDNEURALNET_H_ */
