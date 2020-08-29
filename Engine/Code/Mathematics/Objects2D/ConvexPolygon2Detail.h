// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/19 16:53)

#ifndef MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H

#include "ConvexPolygon2.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ConvexPolygon2<Real>
	::ConvexPolygon2(int verticesNumber, Vector2DPtr verticesPtr, LinePtr lines)
	:ParentType{ verticesNumber,verticesPtr }, m_Lines{ lines }, m_SharingEdges{}
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
	if (ParentType::IsValid())
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
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(), "��Ҫ�����߶Σ�");

	return m_Lines;
}

template <typename Real>
typename const Mathematics::ConvexPolygon2<Real>::Line& Mathematics::ConvexPolygon2<Real>
	::GetLine(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < this->GetNumVertices(), "��������");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(), "��Ҫ�����߶Σ�");

	return m_Lines[index];
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::SetVertex(int index, const Vector2D& vertex)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	ParentType::SetVertex(index, vertex);

	// �����������Ĺ���ߡ�
	// ��Щ�߻����Ժ���¡�
	// ��������������ı�i��E[i] = <V[i],V[i+1]> �� E[i-1] = <V[i-1],V[i]>��
	// ����i+1 �� i-1������Ϊ��������ģ��
	m_SharingEdges.insert((index - 1) % this->GetNumVertices());
	m_SharingEdges.insert(index);
}

template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::UpdateLines()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (IsUpdateLines())
	{
		auto average = this->ComputeVertexAverage();
		for (auto i = 0; i < this->GetNumVertices(); ++i)
		{
			UpdateLine(i, average);
		}

		m_SharingEdges.clear();
	}
}

// private
template <typename Real>
void Mathematics::ConvexPolygon2<Real>
	::UpdateLine(int index, const Vector2D& average)
{
	const auto& vertex0 = this->GetVertex(index);
	const auto& vertex1 = this->GetVertex((index + 1) % this->GetNumVertices());

	auto diff = average - vertex0;
	auto edge = vertex1 - vertex0;
	auto normal = Vector2DTools::GetPerp(-edge);
	auto length = Vector2DTools::VectorMagnitude(normal);
	if (Math::GetZeroTolerance() < length)
	{
		normal /= length;
		auto dot = Vector2DTools::DotProduct(normal, diff);
		MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= dot, "�������Ϊ�Ǹ���\n");
		if (dot < Math::GetValue(0))
		{
			normal = -normal;
		}
	}
	else
	{
		// ��Ե�˻���ʹ�á�normal��ָ��ƽ��ֵ����
		normal = diff;
		normal.Normalize();
	}

	// ���߾�����ָ��ķ��ߡ�
	m_Lines[index].first = normal;
	m_Lines[index].second = Vector2DTools::DotProduct(normal, vertex0);
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
	::IsConvex(Real threshold) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold����Ϊ��ֵ��");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(), "��Ҫ�����߶Σ�");

	auto maxDistance = -Math::sm_MaxReal;
	auto minDistance = Math::sm_MaxReal;

	for (auto j = 0; j < this->GetNumVertices(); ++j)
	{
		const auto& line = m_Lines[j];
		for (auto i = 0; i < this->GetNumVertices(); ++i)
		{
			auto distance = Vector2DTools::DotProduct(line.first,this->GetVertex(i)) - line.second;
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
	::Contains(const typename Vector2D& point, Real threshold) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(threshold <= Math::GetValue(0), "threshold����Ϊ��ֵ��");
	MATHEMATICS_ASSERTION_1(m_SharingEdges.empty(), "��Ҫ�����߶Σ�");

	for (auto i = 0; i < this->GetNumVertices(); ++i)
	{
		const auto& line = m_Lines[i];
		auto distance = Vector2DTools::DotProduct(line.first, point) - line.second;

		if (distance < threshold)
		{
			return false;
		}
	}

	return true;
}

#endif // MATHEMATICS_OBJECTS2D_CONVEX_POLYGON2_DETAIL_H

