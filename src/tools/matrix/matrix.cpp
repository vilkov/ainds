#include "matrix.h"
#include <stdlib.h>
#include <new>


TOOLS_NS_BEGIN

MatrixNxN::MatrixNxN(quint32 dimension)
{
	if (char *mem = static_cast<char *>(malloc(sizeof(Data) + sizeof(qreal) * dimension * dimension)))
		m_data = new (mem) Data(dimension);
}

MatrixNxN::MatrixNxN(quint32 dimension, bool cleanup)
{
	if (char *mem = static_cast<char *>(calloc(1, sizeof(Data) + sizeof(qreal) * dimension * dimension)))
		m_data = new (mem) Data(dimension);
}

VectorN::VectorN(quint32 dimension)
{
	if (char *mem = static_cast<char *>(malloc(sizeof(Data) + sizeof(qreal) * dimension)))
		m_data = new (mem) Data(dimension);
}

VectorN::VectorN(quint32 dimension, bool cleanup)
{
	if (char *mem = static_cast<char *>(calloc(1, sizeof(Data) + sizeof(qreal) * dimension)))
		m_data = new (mem) Data(dimension);
}

TOOLS_NS_END
