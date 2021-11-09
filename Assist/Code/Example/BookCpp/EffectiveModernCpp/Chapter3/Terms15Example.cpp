///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/05 14:26)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms15.h"
#include "Terms15Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <array>
#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Terms15Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms15, Terms15Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::ConstexprExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED int sz = 0;  // 非constexpr变量

#include STSTEM_WARNING_POP

    // ...

    // constexpr auto arraySize1 = sz;  // 错误！sz的值在编译期未知

    // std::array<int, sz> data1;  // 错误！一样的问题

    constexpr auto arraySize2 = 10;  //没问题，10是编译期常量

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED std::array<int, arraySize2> data2{};  // 没问题，arraySize2是个constexpr

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::ConstExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    int sz = 0;  // 仍是非constexpr变量

#include STSTEM_WARNING_POP

    // ...

    const auto arraySize = sz;  // 没问题，arraySize是sz的一个const副本

    // std::array<int, arraySize> data1;  // 错误！arraySize的值非编译期可知
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Pow0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr auto numConds = 5;  // 条件数量

    // result有3^numConds个元素
    const std::array<int, Example0::Pow(3, numConds)> result{};
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Pow1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 在执行期取得这些值
    auto base = Example0::ReadFromDB("base");
    auto exp = Example0::ReadFromDB("exponent");

    MAYBE_UNUSED const auto baseToExp = Example0::Pow(base, exp);  // pow函数在执行期被调用
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Point0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr Example0::Point p1(9.4, 27.7);  // 没问题，在编译期“运行”constexpr构造函数

    constexpr Example0::Point p2(28.8, 5.3);  // 同样没问题

    constexpr auto mid = Midpoint(p1, p2);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms15::Terms15Example::Point1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr Example1::Point p1(9.4, 27.7);  // 同上

    constexpr Example1::Point p2(28.8, 5.3);  // 同上

    constexpr auto mid = Midpoint(p1, p2);

    constexpr auto reflectedMid = Reflection(mid);  // reflectedMid的值为（-19.1，-16.5），且在编译期就已知
}
