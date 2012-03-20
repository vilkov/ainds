#ifndef NEURON_H_
#define NEURON_H_

#include <QtCore/QVector>
#include "../neuralnet_ns.h"


NEURAL_NET_NS_BEGIN

class Neuron
{
public:
	typedef QVector<qreal> Input;
	typedef qreal          Output;
	typedef Input          Weights;

public:
	Neuron(quint32 dimension);
	Neuron(const Weights &weights);
	virtual ~Neuron();

	const Weights &weights() const { return m_weights; }
	Output output() const { return m_output; }

    virtual Output compute(const Input &input) = 0;

protected:
	Weights &weights() { return m_weights; }

protected:
	Output m_output;

private:
	Weights m_weights;
};

NEURAL_NET_NS_END

#endif /* NEURON_H_ */
