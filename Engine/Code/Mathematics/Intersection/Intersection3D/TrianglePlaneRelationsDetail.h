// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 14:21)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H

#include "TrianglePlaneRelations.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::TrianglePlaneRelations<Real>
	::TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, const Real epsilon)
	:m_Distance{}, m_Sign{}, m_Positive{ 0 }, m_Negative{ 0 }, m_Zero{ 0 }
{
	 
	m_Sign.fill(NumericalValueSymbol::Zero);

	Relations(triangle, plane, epsilon);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
} 

// private
template <typename Real>
void Mathematics::TrianglePlaneRelations<Real>
	::Relations(const Triangle3& triangle, const Plane3& plane, const Real epsilon)
{
	// 计算三角形顶点到平面的带符号距离。 使用epsilon平面测试。

	for (auto i = 0; i < sm_Size; ++i)
	{
		m_Distance[i] = plane.DistanceTo(triangle.GetVertex(i));
		
		if (epsilon < m_Distance[i])
		{
			m_Sign[i] = NumericalValueSymbol::Positive;
			++m_Positive;			
		}
		else if (m_Distance[i] < -epsilon)
		{
			m_Sign[i] = NumericalValueSymbol::Negative;
			++m_Negative;
		}
		else
		{
			m_Distance[i] = Real{ };
			m_Sign[i] = NumericalValueSymbol::Zero;
			++m_Zero;
		}
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TrianglePlaneRelations<Real>
	::IsValid() const noexcept
{
	if(0 <= m_Positive && 0 <= m_Negative && 0 <= m_Zero)
		return true;
	else
		return false;	 
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
Real Mathematics::TrianglePlaneRelations<Real>
	::GetDistance(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Distance.size()), "索引错误！");

	return m_Distance[index];
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::TrianglePlaneRelations<Real>
	::GetSign(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < static_cast<int>(m_Distance.size()), "索引错误！");

	return m_Sign[index];
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>
	::GetPositive() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Positive;
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>
	::GetNegative() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Negative;
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>
	::GetZero() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Zero;
}

#endif // MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H