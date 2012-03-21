#ifndef MATRIX_H_
#define MATRIX_H_

#include <QtCore/QVector>
#include <QtCore/QSharedData>
#include "../tools_ns.h"


TOOLS_NS_BEGIN

template <typename Base>
class Expression
{
public:
	typedef quint32 size_type;
	typedef qreal   value_type;
	typedef qreal & reference;

public:
	size_type size() const { return static_cast<const Base &>(*this).size(); }
	value_type operator[](size_type i) const { return static_cast<const Base &>(*this)[i]; }

	operator Base &() { return static_cast<Base &>(*this); }
	operator const Base &() const { return static_cast<const Base &>(*this); }
};


template <typename E1, typename E2>
class Difference : public Expression<Difference<E1, E2> >
{
public:
	typedef Expression<Difference<E1, E2> > base_class;
	typedef typename base_class::size_type  size_type;
	typedef typename base_class::value_type value_type;

public:
	Difference(const Expression<E1> &u, const Expression<E2> &v) :
		m_u(u),
		m_v(v)
	{
		Q_ASSERT(u.size() == v.size());
	}

	value_type operator[](size_type i) const { return m_u[i] - m_v[i]; }
	size_type size() const { return m_v.size(); }

private:
	const E1 &m_u;
	const E2 &m_v;
};


template <typename E>
class Scaled : public Expression<Scaled<E> >
{
public:
	typedef Expression<Scaled<E> >          base_class;
	typedef typename base_class::size_type  size_type;
	typedef typename base_class::value_type value_type;

public:
	Scaled(qreal alpha, const Expression<E> &v) :
		m_alpha(alpha),
		m_v(v)
	{}

	value_type operator[](size_type i) const { return m_alpha * m_v[i]; }
	size_type size() const { return m_v.size(); }

private:
	double m_alpha;
	const E &m_v;
};


template <typename T>
class Squared
{
public:
	typedef typename Expression<T>::size_type  size_type;
	typedef typename Expression<T>::value_type value_type;

public:
	Squared(const T &u) :
		m_u(u)
	{}

	value_type at(size_type i, size_type q) const { return m_u[i] * m_u[q]; }
	size_type size() const { return m_u.size(); }

private:
	const T &m_u;
};


/**
 * MatrixNxN
 */
class MatrixNxN
{
public:
	MatrixNxN(quint32 dimension);
	MatrixNxN(quint32 dimension, bool cleanup);

	const qreal (&operator[](quint32 index) const) []
    { Q_ASSERT(index < m_data->dimension); return (const qreal (&)[])m_data->array[index * sizeof(qreal)]; }

	qreal (&operator[](quint32 index)) []
    { Q_ASSERT(index < m_data->dimension); return (qreal (&)[])m_data->array[index * sizeof(qreal)]; }

	MatrixNxN &operator+=(const MatrixNxN &other)
	{
		Q_ASSERT(m_data->dimension == other.m_data->dimension);
		quint32 index;

		for (quint32 i = 0, size = m_data->dimension; i < size; ++i)
			for (quint32 q = 0; q < size; ++q)
			{
				index = i * sizeof(qreal) + q;
				m_data->array[index] += other.m_data->array[index];
			}

		return *this;
	}


	template <typename T>
	MatrixNxN &operator+=(const Squared<T> &other)
	{
		Q_ASSERT(m_data->dimension == other.size());

		for (quint32 i = 0, size = m_data->dimension; i < size; ++i)
			for (quint32 q = 0; q < size; ++q)
				m_data->array[i * sizeof(qreal) + q] += other.at(i, q);

		return *this;
	}

	quint32 dimension() const { return m_data->dimension; }

private:
	struct Data : public QSharedData
	{
		Data(quint32 dimension) :
			QSharedData(),
			dimension(dimension)
		{}

		quint32 dimension;
		qreal array[1];
	};

private:
	typedef QExplicitlySharedDataPointer<Data> Holder;
	Holder m_data;
};


/**
 * VectorN
 */
class VectorN
{
public:
	VectorN(quint32 dimension);
	VectorN(quint32 dimension, bool cleanup);

	const qreal &operator[](quint32 index) const
	{ Q_ASSERT(index < m_data->dimension); return m_data->array[index]; }

	qreal &operator[](quint32 index)
	{ Q_ASSERT(index < m_data->dimension); return m_data->array[index]; }

	quint32 dimension() const { return m_data->dimension; }

private:
	struct Data : public QSharedData
	{
		Data(quint32 dimension) :
			QSharedData(),
			dimension(dimension)
		{}

		quint32 dimension;
		qreal array[1];
	};

private:
	typedef QExplicitlySharedDataPointer<Data> Holder;
	Holder m_data;
};


/***********************************************************************************************************/
MatrixNxN correlation(const QVector<QVector<qreal> > &input)
{
	MatrixNxN res(input.at(0).size(), true);

	for (quint32 i = 0, size = input.size(); i < size; ++i)
		res += Squared<QVector<qreal> >(input.at(i));

	return res;
}

TOOLS_NS_END

#endif /* MATRIX_H_ */
