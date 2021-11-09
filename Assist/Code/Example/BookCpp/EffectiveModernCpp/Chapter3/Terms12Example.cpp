///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/04 16:10)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms12.h"
#include "Terms12Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Terms12Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms12, Terms12Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::DoWorkExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    std::unique_ptr<Example0::Base> upb = std::make_unique<Example0::Derived>();  // ��������ָ�룬ָ�浽���������

#include STSTEM_WARNING_POP

    // ͨ������ָ�����DoWork������������ຯ��������
    upb->DoWork();
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example0::Widget w;  // ��ͨ������ֵ��

    // ...

    w.DoWork();  // ����ֵ����Widget::DoWork����Widget::DoWork&��
    Example0::MakeWidget().DoWork();  // ����ֵ����Widget::DoWork����Widget::DoWork&&��
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example1::Widget w;

    // ...

    auto vals1 = w.Data();  // ��w.values���Ƶ�vals1

    auto vals2 = Example1::MakeWidget().Data();  // ��Widget�е�values���Ƶ�vals2
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms12::Terms12Example::Widget2Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_9;

    Example2::Widget w;

    // ��Widget::Data����ֵ���ذ汾��
    // vals1���ø��ƹ�����ɳ�ʼ����
    auto vals1 = w.Data();  

    // ��Widget::Data����ֵ���ذ汾��
    // vals2�����ƶ�������ɳ�ʼ����
    auto vals2 = Example2::MakeWidget().Data();  
}
