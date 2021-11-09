///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms6.h"
#include "Terms6Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::Terms6Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter2::Terms6, Terms6Example)

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::VectorExample() const
{
    Widget w;
    //...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // ��ʽ����highPriority���ͱ�
    bool highPriority = Features(w)[5];  // w���и����ȼ���

#include STSTEM_WARNING_POP
    //...

    ProcessWidget(w, highPriority);  // ����w�����ȼ�������֮
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::AutoErrorExample() const
{
    Widget w;
    //...

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // highPriority���ͱ����Ƶ�����
    MAYBE_UNUSED const auto highPriority = Features(w)[5];  // w���и����ȼ���
    //...

#include STSTEM_WARNING_POP

    // ProcessWidget(w, highPriority);  // δ������Ϊ��
    // highPriority���п���ָ��
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::MatrixExample() const noexcept
{
    Matrix m1;
    Matrix m2;
    Matrix m3;
    Matrix m4;

    Matrix sum = m1 + m2 + m3 + m4;
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::StaticCastExample() const
{
    Widget w;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    MAYBE_UNUSED auto highPriority = static_cast<bool>(Features(w)[5]);

#include STSTEM_WARNING_POP

    Matrix m1;
    Matrix m2;
    Matrix m3;
    Matrix m4;

    const Matrix sum = static_cast<Matrix>(m1 + m2 + m3 + m4);
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::CalcEpsilonExample() const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)
    MAYBE_UNUSED const float ep = CalcEpsilon();  // ���д�double��float����ʽ�ͱ�ת��
#include STSTEM_WARNING_POP

    MAYBE_UNUSED const auto ep0 = static_cast<float>(CalcEpsilon());
}

void BookExperience::EffectiveModernCpp::Chapter2::Terms6::Terms6Example::IndexExample() const noexcept
{
    std::vector<int> c;
    constexpr double d = 0.5;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(4244)
    MAYBE_UNUSED const int index = d * c.size();
#include STSTEM_WARNING_POP

    MAYBE_UNUSED const auto index0 = static_cast<int>(d * c.size());
}
