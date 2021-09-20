///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.2 (2021/08/29 15:02)

#ifndef EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_DETAIL_H
#define EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_DETAIL_H

#include "ConstructorTemplateArgumentDeduction.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

template <typename T0, typename T1, typename T2>
BookExperience::EffectiveModernCpp::Preface::ConstructorTemplateArgumentDeduction<T0, T1, T2>::ConstructorTemplateArgumentDeduction(T0 t0, T1 t1, T2 t2) noexcept
    : t0{ t0 }, t1{ t1 }, t2{ t2 }
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T0, typename T1, typename T2>
bool BookExperience::EffectiveModernCpp::Preface::ConstructorTemplateArgumentDeduction<T0, T1, T2>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // EFFECTIVE_MODERN_CPP_PREFACE_CONSTRUCTOR_TEMPLATE_ARGUMENT_DEDUCTION_DETAIL_H
