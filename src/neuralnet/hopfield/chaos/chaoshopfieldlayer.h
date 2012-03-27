#ifndef CHAOSHOPFIELDLAYER_H_
#define CHAOSHOPFIELDLAYER_H_

#include "../../abstract/layer.h"
#include "../../../tools/matrix/matrix.h"


NEURAL_NET_NS_BEGIN

class ChaosHopfieldLayer : public Layer
{
public:
	typedef Output                 Neurons;
	typedef QVector<Neuron::Input> Patterns;

public:
	ChaosHopfieldLayer(const Patterns &patterns);

	virtual const Output &compute(const Input &input);

private:
	Neurons m_neurons;
	Tools::MatrixNxN m_weights;
};

NEURAL_NET_NS_END

#endif /* CHAOSHOPFIELDLAYER_H_ */
