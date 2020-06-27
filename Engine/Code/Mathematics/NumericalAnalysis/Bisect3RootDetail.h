// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:44)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_DETAIL_H

#include "Bisect3Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect3Root<Real>
	::Bisect3Root()
	:m_XRoot{}, m_YRoot{}, m_ZRoot{}, m_BisectRootType{ BisectRootType::NoSolution }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect3Root<Real>
	::Bisect3Root(Real xRoot, Real yRoot, Real zRoot, BisectRootType type)
	:m_XRoot{ xRoot }, m_YRoot{ yRoot }, m_ZRoot{ zRoot }, m_BisectRootType{ type }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Root<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect3Root<Real>
	::GetXRoot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_BisectRootType != BisectRootType::NoSolution)
	{
		return m_XRoot;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>
	::GetYRoot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_BisectRootType != BisectRootType::NoSolution)
	{
		return m_YRoot;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>
	::GetZRoot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (m_BisectRootType != BisectRootType::NoSolution)
	{
		return m_ZRoot;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect3Root<Real>
	::GetBisectRootType() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_BisectRootType;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_DETAIL_H

