///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 11:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_DETAIL_H

#include "SortItem.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::SortItem<Real>::SortItem() noexcept
    : eigenvalue{}, index{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SortItem<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::SortItem<Real>::GetEigenvalue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return eigenvalue;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SortItem<Real>::SetEigenvalue(Real aEigenvalue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    eigenvalue = aEigenvalue;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::SortItem<Real>::GetIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SortItem<Real>::SetIndex(int aIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    index = aIndex;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SORT_ITEM_DETAIL_H
