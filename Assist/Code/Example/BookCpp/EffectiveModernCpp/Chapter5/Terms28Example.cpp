///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/17 21:04)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms28.h"
#include "Terms28Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Terms28Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms28, Terms28Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Widget0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Widget w;  // 变量（左值）

    Example0::Func(w);  // 调用func并传入左值：T的推导结果型别为Widget&

    // void Func(Widget& && param);

    Example0::Func(Example0::WidgetFactory());  // 调用func并传入左值：T的推导结果型别为Widget
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::RefExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr int x{};

    // ...

    // auto& & rx = x;  // 错误！不可以声明“引用的引用”
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::AutoExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Widget w;  // 变量（左值）

    Example0::Func(w);  // 以左值调用函数，T的推导结果型别为Widget&

    Example0::Func(Example0::WidgetFactory());  // 以右值调用函数，T的推导结果型别为Widget

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& w1 = w;

    // Widget& && w1 = w;

    // Widget& w1 = w;

    MAYBE_UNUSED auto&& w2 = Example0::WidgetFactory();

    // Widget&& w2 = Example0::WidgetFactory();

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Widget1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED Example1::Widget<int&> w;

    // typedef int& && RvalueRefToT;
    // typedef int& RvalueRefToT;
}
