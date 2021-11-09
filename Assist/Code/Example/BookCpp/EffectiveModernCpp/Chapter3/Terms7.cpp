///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:38)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms7.h"

using std::cout;

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example0::Widget::Widget(MAYBE_UNUSED int x) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example1::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example1::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example2::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d)
{
    cout << "double构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example2::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b)
{
    cout << "bool构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example2::Widget::Widget(MAYBE_UNUSED std::initializer_list<long double> i1)
{
    cout << "initializer_list构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example3::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d)
{
    cout << "double构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example3::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b)
{
    cout << "bool构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example3::Widget::Widget(MAYBE_UNUSED std::initializer_list<long double> i1)
{
    cout << "initializer_list构造函数被调用\n";
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example3::Widget::operator float() const noexcept
{
    return 0.0f;
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example4::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example4::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example4::Widget::Widget(MAYBE_UNUSED std::initializer_list<bool> i1) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example5::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example5::Widget::Widget(MAYBE_UNUSED std::initializer_list<std::string> i1) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example5::Widget::Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter3::Terms7::Example6::Widget::Widget(std::initializer_list<int> i1)
{
    cout << "initializer_list构造函数被调用，大小为：" << i1.size() << '\n';
}
