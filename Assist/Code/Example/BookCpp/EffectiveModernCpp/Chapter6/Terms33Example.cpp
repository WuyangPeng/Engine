///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/12/02 21:54)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms33.h"
#include "Terms33Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter6::Terms33::Terms33Example::Terms33Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6::Terms33, Terms33Example)

void BookExperience::EffectiveModernCpp::Chapter6::Terms33::Terms33Example::Lambda0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto f = [](auto x) {
        return Func(Normalize(x));
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms33::Terms33Example::Lambda1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto f = [](auto&& x) {
        return Func(Normalize(std::forward<???>(x)));
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms33::Terms33Example::Lambda2Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto f = [](auto&& param) {
        return Func(Normalize(std::forward<decltype(param)>(param)));
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms33::Terms33Example::Lambda3Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto f = [](auto&&... param) {
        return Func(Normalize(std::forward<decltype(param)>(param)...));
    };
}
