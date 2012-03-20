#ifndef CHAOSHOPFIELDLAYER_H_
#define CHAOSHOPFIELDLAYER_H_

#include "../../abstract/layer.h"


NEURAL_NET_NS_BEGIN

class ChaosHopfieldLayer : public Layer
{
public:
	ChaosHopfieldLayer(quint32 dimension);
	ChaosHopfieldLayer(const Weights &weights);

	virtual const Output &compute(const Input &input);

private:
	Output m_output;
};

NEURAL_NET_NS_END

#endif /* CHAOSHOPFIELDLAYER_H_ */
