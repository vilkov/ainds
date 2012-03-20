#ifndef HOPFIELDLAYER_H_
#define HOPFIELDLAYER_H_

#include "../abstract/layer.h"


NEURAL_NET_NS_BEGIN

class HopfieldLayer : public Layer
{
public:
	HopfieldLayer(quint32 dimension);
	HopfieldLayer(const Weights &weights);

	virtual const Output &compute(const Input &input);

private:
	Output m_output;
};

NEURAL_NET_NS_END

#endif /* HOPFIELDLAYER_H_ */
