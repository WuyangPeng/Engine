///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/29 21:31)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms32.h"
#include "Terms32Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>
#include <functional>

BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Terms32Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6::Terms32, Terms32Example)

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto pw = std::make_unique<Example0::Widget>();  // 创建Widget

    // ...
    // 配置*pw

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = [pw = std::move(pw)] {
        return pw->IsValidated() && pw->IsArchived();
    };  // 采用std::move(pw)初始化闭包类的数据成员

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = [pw = std::make_unique<Example0::Widget>()] {
        return pw->IsValidated() && pw->IsArchived();
    };  // 径以make_unique的调用结果初始化闭包类的成员

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::IsValAndArchExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED auto func = Example0::IsValAndArch(std::make_unique<Example0::Widget>());
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // 欲移入闭包的对象

    // ...
    // 灌入数据

    auto func = [data = std::move(data)] {
        /* 对数据加以运用 */
    };
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // 同前

    // ...
    // 同前

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    // C++11中模拟初始化捕获的部分
    auto func = std::bind([](const std::vector<double> data) { /* 对数据加以运用 */ },
                          std::move(data));

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Vector2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<double> data;  // 同前

    // ...
    // 同前

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    // C++11中针对可变lambda式模拟初始化捕获的部分
    auto func = std::bind([](std::vector<double> data) mutable { /* 对数据加以运用 */ },
                          std::move(data));

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms32::Terms32Example::Widget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)

    auto func = std::bind([](const std::unique_ptr<Example0::Widget>& pw) {
        return pw->IsValidated() && pw->IsArchived();
    },
                          std::make_unique<Example0::Widget>());

#include STSTEM_WARNING_POP
}
