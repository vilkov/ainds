#include "chaoshopfieldlayer.h"


NEURAL_NET_NS_BEGIN

ChaosHopfieldLayer::ChaosHopfieldLayer(const Patterns &patterns) :
	m_neurons(patterns.at(0).size()),
	m_weights(Tools::MatrixNxN::correlation(patterns).setDiagonal(0))
{}

const ChaosHopfieldLayer::Output &ChaosHopfieldLayer::compute(const Input &input)
{
	return m_neurons;
}

NEURAL_NET_NS_END
