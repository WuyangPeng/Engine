///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 09:50)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H

#include "Bisect3Root.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Bisect3Root<Real>::Bisect3Root() noexcept
    : xRoot{}, yRoot{}, zRoot{}, bisectRootType{ BisectRootType::NoSolution }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Bisect3Root<Real>::Bisect3Root(Real xRoot, Real yRoot, Real zRoot, BisectRootType type) noexcept
    : xRoot{ xRoot }, yRoot{ yRoot }, zRoot{ zRoot }, bisectRootType{ type }
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

    if (bisectRootType != BisectRootType::NoSolution)
    {
        return xRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s))
    }
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>::GetYRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (bisectRootType != BisectRootType::NoSolution)
    {
        return yRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s))
    }
}

template <typename Real>
Real Mathematics::Bisect3Root<Real>::GetZRoot() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (bisectRootType != BisectRootType::NoSolution)
    {
        return zRoot;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������޽�ģ�"s))
    }
}

template <typename Real>
Mathematics::BisectRootType Mathematics::Bisect3Root<Real>::GetBisectRootType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bisectRootType;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BISECT3_ROOT_ACHIEVE_H
