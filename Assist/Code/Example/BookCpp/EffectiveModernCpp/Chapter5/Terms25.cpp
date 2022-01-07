///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/11/04 21:06)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms25.h"
#include "System/Helper/PragmaWarning.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Widget::Widget(Widget&& rhs) noexcept
    : name(std::move(rhs.name)),  // rhs是个右值引用
      p(std::move(rhs.p))
{
    // ...
}

std::string BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example3::GetWidgetName()
{
    return "Terms25";
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example4::Widget::SetName(const std::string& newName)
{
    name = newName;  //  从常量左值取得赋值
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example4::Widget::SetName(std::string&& newName) noexcept
{
    name = std::move(newName);  //  从右值取得赋值
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example5::Sign::SetText(MAYBE_UNUSED const std::string& text) noexcept
{
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example5::Sign::Add(MAYBE_UNUSED const std::chrono::time_point<std::chrono::system_clock>& now, MAYBE_UNUSED const std::string& text) noexcept
{
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example0::Matrix& BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example0::Matrix::operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept
{
    return *this;
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example0::Matrix BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example0::operator+(Matrix&& lhs, const Matrix& rhs) noexcept
{
    lhs += rhs;
    return std::move(lhs);  //将lhs移入返回值
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix& BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix::operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept
{
    return *this;
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::operator+(Matrix&& lhs, const Matrix& rhs) noexcept
{
    lhs += rhs;
    return lhs;  //将lhs复制入返回值
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26497)

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example6::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example6::MakeWidget() noexcept
{
    Widget w;  // 局部变量

    // ...
    // 操作w

    return w;  // 将w“复制”入返回值
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example7::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example7::MakeWidget() noexcept
{
    Widget w;  // 局部变量

    // ...

#include STSTEM_WARNING_PUSH

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26479)
#endif  // TCRE_USE_MSVC

    return std::move(w);  // 将w移入返回值（别这样做！）

#include STSTEM_WARNING_POP
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example8::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example8::MakeWidget(Widget w) noexcept
{
    // ...

    return w;
    // 编译器必须处理上面这段代码，以使它们与以下代码等价
    // return std::move(w); // 将w作为右值处理
}

#include STSTEM_WARNING_POP