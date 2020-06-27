// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 19:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H

#include "DistanceContactTimeResult.h"
#include "DistanceResultImplDetail.h"

template <typename Real, typename Vector>
Mathematics::DistanceContactTimeResult<Real, Vector>
	::DistanceContactTimeResult(Real distance, Real contactTime)
	:ParentType{ distance }, m_ContactTime{ contactTime }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, typename Vector>
Mathematics::DistanceContactTimeResult<Real, Vector>
	::~DistanceContactTimeResult()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, typename Vector>
bool Mathematics::DistanceContactTimeResult<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real, typename Vector>
Real Mathematics::DistanceContactTimeResult<Real, Vector>
	::GetContactTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ContactTime;
}

template <typename Real, typename Vector>
void Mathematics::DistanceContactTimeResult<Real, Vector>
	::SetContactTime(Real contactTime)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_ContactTime = contactTime;
}

template <typename Real, typename Vector>
typename Mathematics::DistanceContactTimeResult<Real, Vector>::ImplTypePtr Mathematics::DistanceContactTimeResult<Real, Vector>
	::Clone() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

template <typename Real, typename Vector>
bool Mathematics::DistanceContactTimeResult<Real, Vector>
	::isHaveContactTime() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return true;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CONTACT_TIME_RESULT_DETAIL_H
