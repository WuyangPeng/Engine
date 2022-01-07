///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/16 20:44)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms27.h"
#include "Terms27Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter5::Terms27::Terms27Example::Terms27Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter5::Terms27, Terms27Example)

void BookExperience::EffectiveModernCpp::Chapter5::Terms27::Terms27Example::Person0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::Person p("Nancy");

    auto cloneOfP(p);  // ����ֵ�������г�ʼ��
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms27::Terms27Example::Person1Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // Example4::Person p(u"onrad Zuse");  // "Konrad Zusz" ��char16_t�ͱ���ַ����
}

void BookExperience::EffectiveModernCpp::Chapter5::Terms27::Terms27Example::Person2Example() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    // Example5::Person p(u"onrad Zuse");  // "Konrad Zusz" ��char16_t�ͱ���ַ����
}
