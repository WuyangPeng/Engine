///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/11/04 21:06)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms24.h"
#include "Terms24Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Terms24Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms24, Terms24Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::UniversalReference0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget&& var1 = Widget();  // 右值引用

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& var2 = var1;  // 非右值引用

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::UniversalReference1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 不涉及型别推导，var1是个右值引用
    Widget&& var1 = Widget();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    // var2是个万能引用
    MAYBE_UNUSED auto&& var2 = var1;

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Universa1Reference2Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w;

    // 左值被传递给F;
    // param的型别是Widget&（即一个左值引用）
    Example2::F(w);

    // 右值被传递给F;
    // param的型别是Widget&&（即一个右值引用）
    Example2::F(std::move(w));
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Vector0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;
    // Example3::F(v);  // 错误！不能给右值引用绑定一个左值
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::Vector1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<Widget> v;
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms24::Terms24Example::TimeFuncInvocationExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto timeFuncInvocation = [](auto&& func, auto&&... params)  // C++14
    {
        // 计时器启动;
        std::forward<decltype(func)>(func)(  // 调用func
            std::forward<decltype(params)>(params)...  // 调用params
        );

        // 计时器念上并记录流逝的时间。
    };
}
