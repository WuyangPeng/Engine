///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/15 20:29)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms26.h"
#include "Terms26Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Terms26Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms26, Terms26Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");

    Example0::LogAndAdd(petName);  // 传递左值std::string

    Example0::LogAndAdd(std::string("Persephone"));  // 传递右值std::string

    Example0::LogAndAdd("Patty Dog");  // 传递字符串字面量
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");  // 一如此前

    Example1::LogAndAdd(petName);  // 一如此前，将左值复制入multiset

    Example1::LogAndAdd(std::string("Persephone"));  // 对右值实施移动而非复制

    Example1::LogAndAdd("Patty Dog");  // 在multiset中直接构造一个std::string对象，而非复制一个std::string 型别的临时对象
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Log2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::string petName("Darla");  // 一如此前

    Example2::LogAndAdd(petName);  // 一如此前，这三个调用语句都调用了形参型别为T&&的重载版本
    Example2::LogAndAdd(std::string("Persephone"));
    Example2::LogAndAdd("Patty Dog");

    Example2::LogAndAdd(22);  // 本句调用了形参型别为int的重载版本

    MAYBE_UNUSED constexpr short nameIdx = 0;
    // 赋值给nameIdx

    //  Example2::LogAndAdd(nameIdx);  // 错误！
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Person0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Person p("Nancy");

    // auto clonePfP(p);  // 由p出发创建新的Person型别对象；
    // 上述代码无法通过编译
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms26::Terms26Example::Person1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example1::Person p("Nancy");  // 对象变成常量

    auto clonePfP(p);  // 这回调用的是复制构造函数
}
