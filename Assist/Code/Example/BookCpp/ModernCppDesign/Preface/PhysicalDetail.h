///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/13 20:28)

#ifndef MODERN_CPP_DESIGN_PREFACE_PHYSICAL_DETAIL_H
#define MODERN_CPP_DESIGN_PREFACE_PHYSICAL_DETAIL_H

#include "Physical.h"
#include "Example/BookCpp/ModernCppDesign/Helper/ModernCppDesignClassInvariantMacro.h"

template <int M, int L, int T>
BookAdvanced::ModernCppDesign::Physical<M, L, T>::Physical(int value) noexcept
    : value{ value }
{
    MODERN_CPP_DESIGN_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <int M, int L, int T>
bool BookAdvanced::ModernCppDesign::Physical<M, L, T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int M, int L, int T>
int BookAdvanced::ModernCppDesign::Physical<M, L, T>::Value() const noexcept
{
    MODERN_CPP_DESIGN_CLASS_IS_VALID_CONST_9;

    return value;
}

template <int M, int L, int T>
BookAdvanced::ModernCppDesign::Physical<M, L, T>& BookAdvanced::ModernCppDesign::Physical<M, L, T>::operator*=(int rhs) noexcept
{
    MODERN_CPP_DESIGN_CLASS_IS_VALID_9;

    value *= rhs;

    return *this;
}

template <int M, int L, int T>
BookAdvanced::ModernCppDesign::Physical<M, L, T> BookAdvanced::ModernCppDesign::Physical<M, L, T>::unit{ 1 };

template <int M, int L, int T>
BookAdvanced::ModernCppDesign::Physical<M, L, T> BookAdvanced::ModernCppDesign::operator*(Physical<M, L, T> lhs, int rhs) noexcept
{
    Physical<M, L, T> result{ lhs };

    result *= rhs;

    return result;
}

template <int M1, int L1, int T1, int M2, int L2, int T2>
BookAdvanced::ModernCppDesign::Physical<M1 + M2, L1 + L2, T1 + T2> BookAdvanced::ModernCppDesign::operator*(Physical<M1, L1, T1> lhs, Physical<M2, L2, T2> rhs) noexcept
{
    return Physical<M1 + M2, L1 + L2, T1 + T2>::unit * lhs.Value() * rhs.Value();
}

#endif  // MODERN_CPP_DESIGN_PREFACE_PHYSICAL_DETAIL_H
