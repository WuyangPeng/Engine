///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/29 21:29)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms31.h"
#include "System/Helper/PragmaWarning.h"

#include <functional>
#include <vector>

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::AddDivisorFilter()
{
    using FilterContainer = std::vector<std::function<bool(int)>>;

    FilterContainer filters;

    const auto calc1 = ComputeSomeValue1();
    const auto calc2 = ComputeSomeValue2();

    auto divisor = ComputeDivisor(calc1, calc2);

    // 危险！对divisor的指涉可能空悬！
    filters.emplace_back([&](int value) {
        return value % divisor == 0;
    });

    // 危险！对divisor的指涉仍然可能空悬！
    filters.emplace_back([&divisor](int value) {
        return value % divisor == 0;
    });

    // 现在divisor不会空悬
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });
}

int BookExperience::EffectiveModernCpp::Chapter6::Terms31::ComputeSomeValue1() noexcept
{
    return 1;
}

int BookExperience::EffectiveModernCpp::Chapter6::Terms31::ComputeSomeValue2() noexcept
{
    return 2;
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example0::Widget::AddFilter() const
{
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::DoSomeWork()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto pw = std::make_unique<Widget>();  // 创建Widget

#include STSTEM_WARNING_POP

    pw->AddFilter();  // 添加使用了Widget::divisor的筛选函数

    // ...
    // Widget被销毁，filters现在持有空悬指针。
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::Widget::AddFilter() const
{
    // 错误！没有可捕获的divisor
    /*
    filters.emplace_back([](int value) {
        return value % divisor == 0;
    });
    */

    // 错误！局部没有可捕获的divisor
    /*
    filters.emplace_back([divisor](int value) {
        return value % divisor == 0;
    });
     */

    auto currentObjectPtr = this;

    filters.emplace_back([currentObjectPtr](int value) {
        return value % currentObjectPtr->divisor == 0;
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example2::Widget::AddFilter() const
{
    const auto divisorCopy = divisor;  // 复制成员变量

    filters.emplace_back([divisorCopy](int value) {  // 捕获副本
        return value % divisorCopy == 0;  // 使用副本
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example3::Widget::AddFilter() const
{
    const auto divisorCopy = divisor;  // 复制成员变量

    filters.emplace_back([=](int value) {  // 捕获副本
        return value % divisorCopy == 0;  // 使用副本
    });
}

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::FilterContainer BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::filters;

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example4::Widget::AddFilter() const
{
    // C++14
    filters.emplace_back([divisor = divisor](int value) {  // 将divisor复制入闭包
        return value % divisor == 0;  // 使用副本
    });
}

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Example1::AddDivisorFilter()
{
    static auto calc1 = ComputeSomeValue1();  // 现在以static饰词声明
    static auto calc2 = ComputeSomeValue2();  // 现在以static饰词声明

    static auto divisor = ComputeDivisor(calc1, calc2);  // 现在以static饰词声明

    // 未捕获任何东西！
    // 指涉到前述以static饰词声明的对象
    filters.emplace_back([=](int value) {
        return value % divisor == 0;
    });

    ++divisor;  // 意外修改了divisor
}