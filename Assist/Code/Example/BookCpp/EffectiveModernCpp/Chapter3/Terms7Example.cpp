///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms7.h"
#include "Terms7Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Terms7Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms7, Terms7Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::InitExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr int x(0);  // 初始化物在小括号内

    MAYBE_UNUSED constexpr int y = 0;  // 初始化物在等号之后

    MAYBE_UNUSED constexpr int z{ 0 };  // 初始化物在大括号内

    MAYBE_UNUSED constexpr int z1 = { 0 };  // 使用等号和大括号来指定初始化物
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Widget w1;  // 调用的是默认构造函数

    const Widget w2 = w1;  // 并非赋值，调用的是复制构造函数

    w1 = w2;  // 并非赋值，调用的是复制赋值运算符
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Vector0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v{ 1, 3, 5 };  // v的初始内容为1，3，5
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::AtomicExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const std::atomic<int> ai1{ 0 };  // 可行

    const std::atomic<int> ai2(0);  // 可行

    const std::atomic<int> ai3 = 0;  // 不可行（VS可通过编译）
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::SumExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr double x = 0.0, y = 0.0, z = 0.0;

    // ...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)

    // int sum1{ x + y + z };  // 错误！double型别之和可能无法用int表达
    MAYBE_UNUSED constexpr int sum2(x + y + z);  // 没问题（表达式的值被截断为int）
    MAYBE_UNUSED constexpr int sum3 = x + y + z;  // 同上

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example0::Widget w1(10);  // 调用Widget的构造函数，传入形参10

    // 最令人苦恼之解析语法现身！
    // 这个语句声明了一个名为w2，返回一个Widget型别对象的函数。
    // Example1::Widget w2();

    const Example0::Widget w3{};  // 调用没有形参的Widget构造函数
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example1::Widget w1(10, true);  // 调用的是第一个构造函数

    const Example1::Widget w2{ 10, true };  // 调用的还是第一个构造函数

    const Example1::Widget w3(10, 5.0);  // 调用的是第二个构造函数

    const Example1::Widget w4{ 10, 5.0 };  // 调用的还是第二个构造函数
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example2::Widget w1(10, true);  // 使用小括号，同前，调用的是第一个构造函数

    // 使用大括号，调用的是带有std::initializer_list型别形参的构造函数
    // （10和true被强制转换成long double）
    const Example2::Widget w2{ 10, true };

    const Example2::Widget w3(10, 5.0);  // 使用小括号，同前，调用的是第二个构造函数

    // 使用大括号，调用的是带有std::initializer_list型别形参的构造函数
    // （10和5.0被强制转换成long double）
    const Example2::Widget w4{ 10, 5.0 };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction3Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example3::Widget w4{ 10, 5.0 };

    const Example3::Widget w5(w4);  // 使用小括号，调用的是复制构造函数

    // 使用大括号，调用的是带有std::initializer_list型别形参的构造函数
    // （w4的返回值被强制转换成float，随后float又被强制转换成long double）
    const Example3::Widget w6{ w4 };

    const Example3::Widget w7(std::move(w4));  // 使用小括号，调用的是移动构造函数

    // 使用大括号，调用的是带有std::initializer_list型别形参的构造函数
    // （和w6的结果理由相同）
    // VS并没有调用带有std::initializer_list型别形参的构造函数。
    const Example3::Widget w8{ std::move(w4) };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction4Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // const Example4::Widget{ 10, 5.0 };  // 错误！要求窄式型别转换
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction5Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    const Example5::Widget w1(10, true);  // 使用小括号，调用的是第一个构造函数

    const Example5::Widget w2{ 10, true };  // 使用大括号，变成调用第一个构造函数

    const Example5::Widget w3(10, 5.0);  // 使用小括号，调用的仍是第二个构造函数

    const Example5::Widget w4{ 10, 5.0 };  // 使用大括号，变成调用第二个构造函数
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::WidgetConstruction6Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED const Example6::Widget w1;  // 调用的是默认构造函数

    const Example6::Widget w2{};  // 调用的仍是默认构造函数

    // Example6::Widget w3();  // 最令人苦恼的解析语法现身！变成函数声明语句

    const Example6::Widget w4({});  // 带有std::initializer_list型别形参的构造函数，传入一个空的std::initializer_list

    const Example6::Widget w5{ {} };  // 构造函数使用单元素std::initializer_list调用，而不是空的。
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::Vector1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // 调用了形参中没有任何一个具备std::initializer_list型别的构造函数
    // 结果是：创建了一个含有10个元素的std::vector所有的元素的值都是20
    std::vector<int> v1(10, 20);

    // 调用了形参中含有std::initializer_list型别的构造函数，
    // 结果是，创建了一个含有2个元素的std::vector，元素的值分别是10和20
    std::vector<int> v2{ 10, 20 };
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms7::Terms7Example::DoSomeWorkExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    std::vector<int> v;

    // ...

    DoSomeWork<std::vector<int>>(10, 20);
}
