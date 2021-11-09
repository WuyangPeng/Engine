///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:11)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms19.h"
#include "Terms19Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::Terms19Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms19, Terms19Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 自定义析构器
    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // 析构器型别是智能指针型别的一部分
    std::unique_ptr<Example0::Widget, decltype(loggingDel)> upw(new Example0::Widget, loggingDel);

    // 析构器型别不是智能指针型别的一部分
    std::shared_ptr<Example0::Widget> spw(new Example0::Widget, loggingDel);

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 自定义析构器各有不同型别
    const auto customDeleter1 = [](Example0::Widget* pw) noexcept {
        // ...
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

    const auto customDeleter2 = [](Example0::Widget* pw) noexcept {
        // ...
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    std::shared_ptr<Example0::Widget> pw1(new Example0::Widget, customDeleter1);
    std::shared_ptr<Example0::Widget> pw2(new Example0::Widget, customDeleter2);

#include STSTEM_WARNING_POP

    std::vector<std::shared_ptr<Example0::Widget>> vpw{ pw1, pw2 };
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::ErrorSharedPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26403)
#include SYSTEM_WARNING_DISABLE(26409)

    auto pw = new Example0::Widget;  // pw是个裸指针

#include STSTEM_WARNING_POP

    // ...

    // 为*pw创建一个控制块
    std::shared_ptr<Example0::Widget> spw1(pw, loggingDel);

    // ...

    // 为*pw创建第二个控制块。
    // std::shared_ptr<Widget> spw2(pw, loggingDel);
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms19::Terms19Example::SharedPtr2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const auto loggingDel = [](Example0::Widget* pw) noexcept {
        MakeLogEntry(pw);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26401)
#include SYSTEM_WARNING_DISABLE(26409)

        delete pw;

#include STSTEM_WARNING_POP
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)

    // 直接传递new表达式
    std::shared_ptr<Example0::Widget> spw1(new Example0::Widget, loggingDel);

#include STSTEM_WARNING_POP

    // spw2使用的是和spw1同一个控制块。
    std::shared_ptr<Example0::Widget> spw2(spw1);
}
