// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 19:02)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RESLUT_IMPL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_RESLUT_IMPL_DETAIL_H

#include "DistanceResultImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, typename Vector>
Mathematics::DistanceResultImpl<Real, Vector>
	::DistanceResultImpl(Real distance)
	:m_Distance{ distance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceResultImpl<Real, Vector>
	::~DistanceResultImpl()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceResultImpl<Real, Vector>
	::IsValid() const noexcept
{
	if (Math::sm_Zero <= m_Distance)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>
	::GetDistance() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Distance;
}

template <typename Real, typename Vector>
Real  Mathematics::DistanceResultImpl<Real, Vector>
	::GetContactTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Math::sm_Zero;
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResultImpl<Real, Vector>
	::GetLhsClosestPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return GetLhsClosestPoint(0);
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResultImpl<Real, Vector>
	::GetRhsClosestPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return GetRhsClosestPoint(0);
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResultImpl<Real, Vector>
	::GetLhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetLhsClosestPointSize(), "距离结果不包含最近相交点！\n");

	SYSTEM_UNUSED_ARG(index);

	return Vector{};
}

template <typename Real, typename Vector>
const Vector Mathematics::DistanceResultImpl<Real, Vector>
	::GetRhsClosestPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetRhsClosestPointSize(), "距离结果不包含最近相交点！\n");

	SYSTEM_UNUSED_ARG(index);

	return Vector{};
}

template <typename Real, typename Vector>
int Mathematics::DistanceResultImpl<Real, Vector>
	::GetLhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return sm_ClosestPointZeroSize;
}

template <typename Real, typename Vector>
int Mathematics::DistanceResultImpl<Real, Vector>
	::GetRhsClosestPointSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return sm_ClosestPointZeroSize;
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>
	::SetDistance(Real distance)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Distance = distance;
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>
	::SetSqrtDistance()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Distance = Math::Sqrt(m_Distance);
}

template <typename Real, typename Vector>
void Mathematics::DistanceResultImpl<Real, Vector>
	::SetContactTime(Real contactTime)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(false, "距离结果不包含接触时间！\n");

	SYSTEM_UNUSED_ARG(contactTime);
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>
	::GetLhsParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(false, "距离结果不包含接触参数！\n");

	return 0;
}

template <typename Real, typename Vector>
Real Mathematics::DistanceResultImpl<Real, Vector>
	::GetRhsParameter() const
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_2(false, "距离结果不包含接触参数！\n");

	return 0;
}

template <typename Real, typename Vector>
bool Mathematics::DistanceResultImpl<Real, Vector>
	::isHaveContactTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return false;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceResultImpl<Real, Vector>::ImplTypePtr Mathematics::DistanceResultImpl<Real, Vector>
	::Clone() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RESLUT_DETAIL_H
