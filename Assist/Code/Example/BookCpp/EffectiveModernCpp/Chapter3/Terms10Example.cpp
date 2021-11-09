///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms10.h"
#include "Terms10Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>
#include <string>

BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Terms10Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms10, Terms10Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // black、white、red所在作用域和Color相同
    enum Color
    {
        black,
        white,
        red
    };

    // auto white = false;  // 错误！white已在范围内被声明过了
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumClassExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // black、white、red所在作用域被限定在Color内
    enum class Color
    {
        black,
        white,
        red
    };

    MAYBE_UNUSED constexpr auto white = false;  // 没问题，范围内并无其他“white”

    // Color c0 = white;  // 错误，范围内并无名为“white”的枚举量

    MAYBE_UNUSED const Color c1 = Color::white;  // 没问题

    MAYBE_UNUSED const auto c2 = Color::white;  // 同样没问题
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumConversionExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 限定范围的枚举型别
    enum Color
    {
        black,
        white,
        red
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26812)

    Color c = red;

#include STSTEM_WARNING_POP
    // ...

    // 将Color型别和double型别值比较（！）
    if (c < 14.5)
    {
        // 计算一个Color型别的质因数（！）
        auto factors = PrimeFactors(c);

        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::EnumClassConversionExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 不限作用域的枚举型别
    enum class Color
    {
        black,
        white,
        red
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    // 同前，但现在要加上范围限定饰词
    Color c = Color::red;

#include STSTEM_WARNING_POP

    // ...

    // 错误！不能将Color型别和double型别值比较
    // if (c < 14.5)
    {
        // 错误！不能将Color型别传入要求std::size_t型别形参的函数
        // auto factors = PrimeFactors(c);

        // ...
    }

    // 不自然的代码，但合法
    if (static_cast<double>(c) < 14.5)
    {
        // 合法性可疑，但是能够通过编译
        auto factors = PrimeFactors(static_cast<std::size_t>(c));

        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string,  // 名字
                                std::string,  // 电子邮件
                                std::size_t>;  // 声望值

    UserInfo uInfo;  // std::tuple型别对象

    // ...

    auto val = std::get<1>(uInfo);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;  // 同前

    // ...

    auto val = std::get<uiEmail>(uInfo);  // 啊！取得电子邮件对应的域了
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum class UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;  // 同前

    // ...

    auto val = std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uInfo);
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms10::Terms10Example::Tuple3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    enum class UserInfoFields
    {
        uiName,
        uiEmail,
        uiReputation
    };

    UserInfo uInfo;

    auto val = std::get<Example2::ToUType(UserInfoFields::uiEmail)>(uInfo);
}
