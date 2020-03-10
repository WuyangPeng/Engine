// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/09 16:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_DETAIL_H

#include "CoreTools/Exception/Error.h"
#include "BrentsMethodRoot.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::BrentsMethodRoot<Real>
	::BrentsMethodRoot()
	:m_Root{}, m_Function{}, m_BrentsMethodRootType{ BrentsMethodRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BrentsMethodRoot<Real>
	::BrentsMethodRoot (Real root,Real function,BrentsMethodRootType type)
	:m_Root{ root }, m_Function{ function }, m_BrentsMethodRootType{ type }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BrentsMethodRoot<Real>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::BrentsMethodRoot<Real>
	::GetRoot () const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	if (m_BrentsMethodRootType != BrentsMethodRootType::NoSolution)
	{
		return m_Root;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Real Mathematics::BrentsMethodRoot<Real>
	::GetFunction () const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
    
	if (m_BrentsMethodRootType != BrentsMethodRootType::NoSolution)
	{
		return m_Function;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"));
	}
}

template <typename Real>
Mathematics::BrentsMethodRootType Mathematics::BrentsMethodRoot<Real>
	::GetBrentsMethodRootType () const
{
    CLASS_IS_VALID_CONST;
    
    return m_BrentsMethodRootType;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_DETAIL_H

