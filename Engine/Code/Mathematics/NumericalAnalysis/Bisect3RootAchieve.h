///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/19 17:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H

#include "Bisect3Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Bisect3Root<Real>::Bisect3Root() noexcept
    : m_XRoot{}, m_YRoot{}, m_ZRoot{}, m_BisectRootType{ BisectRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect3Root<Real>::Bisect3Root(Real xRoot, Real yRoot, Real zRoot, BisectRootType type) noexcept
    : m_XRoot{ xRoot }, m_YRoot{ yRoot }, m_ZRoot{ zRoot }, m_BisectRootType{ type }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Bisect3Root<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Bisect3Root<Real>::GetXRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_BisectRootType != BisectRootType::NoSolution)
    {
        return m_XRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"s));
    }
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>::GetYRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_BisectRootType != BisectRootType::NoSolution)
    {
        return m_YRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"s));
    }
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>::GetZRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (m_BisectRootType != BisectRootType::NoSolution)
    {
        return m_ZRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("方程是无解的！"s));
    }
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect3Root<Real>::GetBisectRootType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_BisectRootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H
