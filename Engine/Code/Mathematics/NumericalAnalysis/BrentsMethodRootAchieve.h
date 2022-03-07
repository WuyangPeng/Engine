///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/14 14:54)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_ACHIEVE_H

#include "BrentsMethodRoot.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::BrentsMethodRoot<Real>::BrentsMethodRoot() noexcept
    : root{}, function{}, brentsMethodRootType{ BrentsMethodRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::BrentsMethodRoot<Real>::BrentsMethodRoot(Real root, Real function, BrentsMethodRootType type) noexcept
    : root{ root }, function{ function }, brentsMethodRootType{ type }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BrentsMethodRoot<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::BrentsMethodRoot<Real>::GetRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (brentsMethodRootType != BrentsMethodRootType::NoSolution)
    {
        return root;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s));
    }
}

template <typename Real>
Real Mathematics::BrentsMethodRoot<Real>::GetFunction() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (brentsMethodRootType != BrentsMethodRootType::NoSolution)
    {
        return function;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s));
    }
}

template <typename Real>
Mathematics::BrentsMethodRootType Mathematics::BrentsMethodRoot<Real>::GetBrentsMethodRootType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return brentsMethodRootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BRENTS_METHOD_ROOT_ACHIEVE_H
