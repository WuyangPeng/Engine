// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/09 13:42)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_DETAIL_H

#include "Bisect1Root.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Bisect1Root<Real>
	::Bisect1Root ()
	:m_Root{}, m_Bisect1RootType{ BisectRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect1Root<Real>
	::Bisect1Root (Real root,BisectRootType type)
	:m_Root{ root }, m_Bisect1RootType{ type }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect1Root<Real>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect1Root<Real>
	::GetRoot () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	if (m_Bisect1RootType != BisectRootType::NoSolution)
	{
		return m_Root;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect1Root<Real>
	::GetBisect1RootType () const
{
    CLASS_IS_VALID_CONST;
    
    return m_Bisect1RootType;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_DETAIL_H

