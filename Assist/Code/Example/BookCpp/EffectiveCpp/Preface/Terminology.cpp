///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/16 17:47)

#include "Example/BookCpp/EffectiveCpp/EffectiveCppExport.h"

#include "Terminology.h"
#include "TerminologyDeclaration.h"
#include "Example/BookCpp/EffectiveCpp/Helper/EffectiveCppClassInvariantMacro.h"

#include <iostream>

BookExperience::EffectiveCpp::Terminology::Terminology() noexcept
{
    EFFECTIVE_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveCpp, Terminology)

void BookExperience::EffectiveCpp::Terminology::Main() const noexcept
{
    EFFECTIVE_CPP_CLASS_IS_VALID_CONST_9;

    const B bObj1;
    DoSomething(bObj1);
    const B bObj2(28);

#if 0
    // ���󣬲�û����ʽת����
    doSomething(28);
#endif

    DoSomething(B(28));

    Widget w1;
    const Widget w2(w1);
    w1 = w2;
    const Widget w3 = w2;

    Widget widget;
    if (HasAcceptableQuality(widget))
    {
    }

#if 0 
    // ����ȷ��Ϊ
    const int* p = nullptr;
    std::cout << *p;
#endif

#if 0
    // ����ȷ��Ϊ
     const char name[] = "Darla";
    [[maybe_unused]] const char c = name[10];
#endif
}

std::size_t BookExperience::EffectiveCpp::Terminology::NumDigits(int number) const noexcept
{
    EFFECTIVE_CPP_CLASS_IS_VALID_CONST_9;

    return BookExperience::EffectiveCpp::NumDigits(number);
}
