#ifndef NEURALNET_H_
#define NEURALNET_H_

#include "layer.h"


NEURAL_NET_NS_BEGIN

class NeuralNet
{
public:
	typedef Layer::Input     Input;
	typedef Layer::Output    Output;
	typedef QVector<Layer *> Layers;

public:
	NeuralNet();
	virtual ~NeuralNet();

	const Layers &layers() const { return m_layers; }

	virtual void addLayer(quint32 dimension) = 0;
	virtual void addLayer(const Layer::Weights &weights) = 0;

    virtual const Output &compute(const Input &input) = 0;

protected:
	Layers &layers() { return m_layers; }

private:
	Layers m_layers;
};

NEURAL_NET_NS_END

#endif /* NEURALNET_H_ */
