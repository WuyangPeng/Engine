///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:47)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_ACHIEVE_H

#include "Bisect2Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Bisect2Root<Real>::Bisect2Root() noexcept
    : xRoot{}, yRoot{}, bisectRootType{ BisectRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect2Root<Real>::Bisect2Root(Real xRoot, Real yRoot, BisectRootType type) noexcept
    : xRoot{ xRoot }, yRoot{ yRoot }, bisectRootType{ type }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Bisect2Root<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect2Root<Real>::GetXRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (bisectRootType != BisectRootType::NoSolution)
    {
        return xRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"s))
    }
}

template <typename Real>
Real Mathematics::Bisect2Root<Real>::GetYRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (bisectRootType != BisectRootType::NoSolution)
    {
        return yRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"s))
    }
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect2Root<Real>::GetBisectRootType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bisectRootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT2_ROOT_ACHIEVE_H
