///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/20 21:47)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms30.h"
#include "Terms30Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::Terms30Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms30, Terms30Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::BracesExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example2::F({ 1, 2, 3 });  // 没问题，“{ 1, 2, 3 }”会隐式转换为std::vector<int>

    // Example2::Fwd({ 1, 2, 3 });  // 错误！无法通过编译

    auto il = { 1, 2, 3 };  // il的型别推导结果为std::initializer_list<int>

    Example2::Fwd(il);  // 没问题，将il完美转发给F
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::StaticExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> widgetData;

    widgetData.reserve(Example3::Widget::MinVals);  // 此处用到了MinVals

    Example3::F(Example3::Widget::MinVals);  // 没问题，当F(28)处理

    Example3::Fwd(Example3::Widget::MinVals);  // 错误！应该无法链接
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::ProcessValExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example5::F(Example5::ProcessVal);  // 没问题

    // Example5::Fwd(Example5::ProcessVal);  // 错误！哪个ProcessVal重载版本？

    // Example5::Fwd(Example5::WorkOnVal);  // 错误！WorkOnVal的哪个实例

    using ProcessFuncType = int (*)(int);  // 相当于创建一个typedef

    ProcessFuncType processValPTr = Example5::ProcessVal;

    Example5::Fwd(processValPTr);  // 没问题

    Example5::Fwd(static_cast<ProcessFuncType>(Example5::WorkOnVal));  // 也没问题
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms30::Terms30Example::IPv4Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example6::IPv4Header h{};

    // ...

    Example6::F(h.totalLength);  // 没问题

    //  Example6::Fwd(h.totalLength);  // 错误！

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26472)

    auto length = static_cast<std::uint16_t>(h.totalLength);

#include STSTEM_WARNING_POP

    Example6::Fwd(length);  // 转发该副本
}
