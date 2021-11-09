///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/24 20:35)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms22Example.h"
#include "Widget.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms22::Terms22Example::Terms22Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms22, Terms22Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms22::Terms22Example::Widget0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // Example2::Widget w;  // 错误！
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms22::Terms22Example::Widget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example3::Widget w;
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms22::Terms22Example::Widget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example4::Widget w;
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms22::Terms22Example::SharedPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example8::Widget w1;

    auto w2(std::move(w1));  // 针对w2实施移动构造

    w1 = std::move(w2);  // 针对w2实施移动赋值
}
