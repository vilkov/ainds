#ifndef HOPFIELDLAYER_H_
#define HOPFIELDLAYER_H_

#include "../abstract/layer.h"
#include "../../tools/matrix/matrix.h"


NEURAL_NET_NS_BEGIN

class HopfieldLayer : public Layer
{
public:
	typedef QVector<Neuron::Input> Patterns;

public:
	HopfieldLayer(const Patterns &patterns);

	virtual const Output &compute(const Input &input);

private:
	Output m_output;
	Tools::VectorN m_neurons;
	Tools::MatrixNxN m_weights;
};

NEURAL_NET_NS_END

#endif /* HOPFIELDLAYER_H_ */
