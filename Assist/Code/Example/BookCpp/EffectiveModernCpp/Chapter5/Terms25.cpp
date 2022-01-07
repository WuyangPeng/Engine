///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/11/04 21:06)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms25.h"
#include "System/Helper/PragmaWarning.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Widget::Widget(Widget&& rhs) noexcept
    : name(std::move(rhs.name)),  // rhs�Ǹ���ֵ����
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
    name = newName;  //  �ӳ�����ֵȡ�ø�ֵ
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example4::Widget::SetName(std::string&& newName) noexcept
{
    name = std::move(newName);  //  ����ֵȡ�ø�ֵ
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
    return std::move(lhs);  //��lhs���뷵��ֵ
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix& BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix::operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept
{
    return *this;
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::Matrix BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example1::operator+(Matrix&& lhs, const Matrix& rhs) noexcept
{
    lhs += rhs;
    return lhs;  //��lhs�����뷵��ֵ
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26497)

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example6::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example6::MakeWidget() noexcept
{
    Widget w;  // �ֲ�����

    // ...
    // ����w

    return w;  // ��w�����ơ��뷵��ֵ
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example7::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example7::MakeWidget() noexcept
{
    Widget w;  // �ֲ�����

    // ...

#include STSTEM_WARNING_PUSH

#if defined(TCRE_USE_MSVC)
    #pragma warning(disable : 26479)
#endif  // TCRE_USE_MSVC

    return std::move(w);  // ��w���뷵��ֵ��������������

#include STSTEM_WARNING_POP
}

BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example8::Widget BookExperience::EffectiveModernCpp::Chapter5::Terms25::Example8::MakeWidget(Widget w) noexcept
{
    // ...

    return w;
    // ���������봦��������δ��룬��ʹ���������´���ȼ�
    // return std::move(w); // ��w��Ϊ��ֵ����
}

#include STSTEM_WARNING_POP