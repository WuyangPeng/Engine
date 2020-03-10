// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/06 11:20)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H

#include "ConvexPolygon2.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ConvexPolygon2<Real>
	::ConvexPolygon2( int verticesNumber, Vector2DPtr verticesPtr, LinePtr lines )
	:ParentType{ verticesNumber,verticesPtr },m_Lines{ lines }, m_SharingEdges{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::ConvexPolygon2<Real>
	::~ConvexPolygon2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ConvexPolygon2<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::ConvexPolygon2<Real>::LinePtr Mathematics::ConvexPolygon2<Real>
	::GetLines() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(),"需要更新线段！");
	
	return m_Lines;
}

template <typename Real>
typename const Mathematics::ConvexPolygon2<Real>::Line& Mathematics::ConvexPolygon2<Real>
	::GetLine( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetNumVertices(),"索引错误！");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(),"需要更新线段！");

	return m_Lines[index]; 
}


template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::SetVertex( int index, const Vector2D& vertex )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	ParentType::SetVertex(index, vertex);

	// 跟踪这个顶点的共享边。
	// 这些边会在稍后更新。
	// 顶点索引相关联的边i是E[i] = <V[i],V[i+1]> 和 E[i-1] = <V[i-1],V[i]>，
	// 其中i+1 和 i-1被计算为顶点数的模。
	m_SharingEdges.insert((index - 1) % GetNumVertices());
	m_SharingEdges.insert(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::UpdateLines()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (IsUpdateLines())
	{
		auto average = ComputeVertexAverage();
		for (auto i = 0; i < GetNumVertices(); ++i)
		{
			UpdateLine(i, average);
		}

		m_SharingEdges.clear();
	}	
}

// private
template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::UpdateLine( int index, const Vector2D& average )
{
	const auto& vertex0 = GetVertex(index);
	const auto& vertex1 = GetVertex((index + 1) % GetNumVertices());

	auto diff = average - vertex0;
	auto edge = vertex1 - vertex0;
	auto normal = Vector2DTools::GetPerp(-edge);
	auto length = Vector2DTools::VectorMagnitude(normal);
	if (Math::sm_ZeroTolerance < length)
	{
		normal /= length;
		auto dot = Vector2DTools::DotProduct(normal,diff);
		MATHEMATICS_ASSERTION_1(Real{} <= dot, "点积必须为非负数\n");
		if (dot < Real{})
		{
			normal = -normal;
		}
	}
	else
	{
		// 边缘退化。使用“normal”指向平均值朝向。
		normal = diff;
		normal.Normalize();
	}

	// 此线具有内指向的法线。
	m_Lines[index].first = normal;
	m_Lines[index].second = Vector2DTools::DotProduct(normal,vertex0);
}


template <typename Real>
bool Mathematics::ConvexPolygon2<Real>
	::IsUpdateLines() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return !m_SharingEdges.empty();
}

template <typename Real>
bool Mathematics::ConvexPolygon2<Real>
	::IsConvex( Real threshold ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(threshold <= Real{}, "threshold必须为负值！");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(),"需要更新线段！");

	auto maxDistance = -Math::sm_MaxReal;
	auto minDistance = Math::sm_MaxReal;

	for (auto j = 0; j < GetNumVertices(); ++j)
	{
		const auto& line = m_Lines[j];
		for (auto i = 0; i < GetNumVertices(); ++i)
		{
			auto distance = Vector2DTools::DotProduct(line.first,GetVertex(i)) - line.second;
			if (distance < minDistance)
			{
				minDistance = distance;
			}
			if (maxDistance < distance)
			{
				maxDistance = distance;
			}
			if (distance < threshold)
			{
				return false;
			}
		}
	}

	return true;
}


template <typename Real>
bool Mathematics::ConvexPolygon2<Real>
	::Contains( const typename Vector2D& point, Real threshold ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(threshold <= Real{}, "threshold必须为负值！");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(),"需要更新线段！");

	for (auto i = 0; i < GetNumVertices(); ++i)
	{
		const auto& line = m_Lines[i];
		auto distance = Vector2DTools::DotProduct(line.first,point) - line.second;

		if (distance < threshold)
		{
			return false;
		}
	}

	return true;
}

#endif // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H

