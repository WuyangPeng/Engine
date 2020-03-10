// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 14:22)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H

#include "TriangleProjectOntoAxis.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::TriangleProjectOntoAxis<Real>
	::TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis)
	:m_Min{}, m_Max{}
{
	Project(triangle, axis);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
} 

// private
template <typename Real>
void Mathematics::TriangleProjectOntoAxis<Real>
	::Project(const Triangle3& triangle, const Vector3D& axis)
{
	std::vector<Real> dot{ Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0)),
						   Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1)),
						   Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

	auto minmaxElement = minmax_element(dot.begin(), dot.end());

	m_Min = *minmaxElement.first;
	m_Max = *minmaxElement.second; 
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TriangleProjectOntoAxis<Real>
	::IsValid() const noexcept
{
	if (m_Min <= m_Max)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>
	::GetMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Min;
}

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>
	::GetMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Max;
}

#endif // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H