// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 16:56)

#ifndef MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H

#include "Polygon2.h"

#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Polygon2<Real>
	::Polygon2(int verticesNumber, Vector2DPtr verticesPtr)
	:m_VerticesNumber{ verticesNumber }, m_Vertices{ verticesPtr }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Polygon2<Real>
	::~Polygon2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Polygon2<Real>
	::IsValid() const noexcept
{
	if (4 <= m_VerticesNumber && m_Vertices != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::Polygon2<Real>
	::GetNumVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_VerticesNumber;
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::Vector2DPtr Mathematics::Polygon2<Real>
	::GetVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Vertices;
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::Vector2D& Mathematics::Polygon2<Real>
	::GetVertex(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_VerticesNumber, "À˜“˝¥ÌŒÛ£°");

	return m_Vertices[index];
}

template <typename Real>
void Mathematics::Polygon2<Real>
	::SetVertex(int index, const Vector2D& vertex)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_VerticesNumber, "À˜“˝¥ÌŒÛ£°");

	m_Vertices[index] = vertex;
}

template <typename Real>
const typename Mathematics::Polygon2<Real>::Vector2D Mathematics::Polygon2<Real>
	::ComputeVertexAverage() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto average = m_Vertices[0];
	for (auto i = 1; i < m_VerticesNumber; ++i)
	{
		average += m_Vertices[i];
	}
	average /= static_cast<Real>(m_VerticesNumber);

	return average;
}

template <typename Real>
Real Mathematics::Polygon2<Real>
	::ComputePerimeterLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto perimeterLength = Vector2DTools::VectorMagnitude(m_Vertices[0] - m_Vertices[m_VerticesNumber - 1]);
	for (auto i = 1; i < m_VerticesNumber; ++i)
	{
		auto edge = m_Vertices[i] - m_Vertices[i - 1];
		perimeterLength += Vector2DTools::VectorMagnitude(edge);
	}

	return perimeterLength;
}

template <typename Real>
Real Mathematics::Polygon2<Real>
	::ComputeArea() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	const auto last = m_VerticesNumber - 1;
	auto area = m_Vertices[0][0] * (m_Vertices[1][1] - m_Vertices[last][1]) + m_Vertices[last][0] * (m_Vertices[0][1] - m_Vertices[last - 1][1]);

	for (auto i = 1; i < last; ++i)
	{
		area += m_Vertices[i][0] * (m_Vertices[i + 1][1] - m_Vertices[i - 1][1]);
	}

	area *= static_cast<Real>(0.5);

	return area;
}

#endif // MATHEMATICS_OBJECTS2D_POLYGON2_DETAIL_H
