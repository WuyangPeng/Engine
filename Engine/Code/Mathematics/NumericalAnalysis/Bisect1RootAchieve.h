///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_ACHIEVE_H

#include "Bisect1Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Bisect1Root<Real>::Bisect1Root() noexcept
    : root{}, bisect1RootType{ BisectRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect1Root<Real>::Bisect1Root(Real root, BisectRootType type) noexcept
    : root{ root }, bisect1RootType{ type }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect1Root<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect1Root<Real>::GetRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (bisect1RootType != BisectRootType::NoSolution)
    {
        return root;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s))
    }
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect1Root<Real>::GetBisect1RootType() const noexcept
{
    CLASS_IS_VALID_CONST;

    return bisect1RootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT1_ROOT_ACHIEVE_H
