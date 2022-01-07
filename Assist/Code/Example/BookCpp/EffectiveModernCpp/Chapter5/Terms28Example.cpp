///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/17 21:04)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms28.h"
#include "Terms28Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Terms28Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms28, Terms28Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Widget0Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Widget w;  // ��������ֵ��

    Example0::Func(w);  // ����func��������ֵ��T���Ƶ�����ͱ�ΪWidget&

    // void Func(Widget& && param);

    Example0::Func(Example0::WidgetFactory());  // ����func��������ֵ��T���Ƶ�����ͱ�ΪWidget
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::RefExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED constexpr int x{};

    // ...

    // auto& & rx = x;  // ���󣡲��������������õ����á�
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::AutoExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Widget w;  // ��������ֵ��

    Example0::Func(w);  // ����ֵ���ú�����T���Ƶ�����ͱ�ΪWidget&

    Example0::Func(Example0::WidgetFactory());  // ����ֵ���ú�����T���Ƶ�����ͱ�ΪWidget

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    MAYBE_UNUSED auto&& w1 = w;

    // Widget& && w1 = w;

    // Widget& w1 = w;

    MAYBE_UNUSED auto&& w2 = Example0::WidgetFactory();

    // Widget&& w2 = Example0::WidgetFactory();

#include STSTEM_WARNING_POP
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms28::Terms28Example::Widget1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    MAYBE_UNUSED Example1::Widget<int&> w;

    // typedef int& && RvalueRefToT;
    // typedef int& RvalueRefToT;
}
