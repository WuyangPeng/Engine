///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/05 12:25)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms4Derive.h"
#include "Terms4Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <iostream>

BookExperience::EffectiveModernCpp::Chapter1::Terms4::Terms4Example::Terms4Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter1::Terms4, Terms4Example)

void BookExperience::EffectiveModernCpp::Chapter1::Terms4::Terms4Example::Derivation() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    constexpr int theAnswer = 42;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    auto x = theAnswer;  // x���ͱ��Ƶ������int

#include STSTEM_WARNING_POP

    auto y = &theAnswer;  // y����const int*

    // TD<decltype(x)> xType;  // �շ�����x��y���ͱ�Ĵ�����Ϣ
    // TD<decltype(y)> yType;

    std::cout << typeid(x).name() << '\n';  // ��ӡx��y������
    std::cout << typeid(y).name() << '\n';

    const auto vw = CreateVec();  // ʹ�ù�����������ֵ��ʼ��vw

    if (!vw.empty())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        F(&vw[0]);  // ����F12
#include STSTEM_WARNING_POP
        // ...
    }
}

void BookExperience::EffectiveModernCpp::Chapter1::Terms4::Terms4Example::TypeIndex() const
{
    const auto vw = CreateVec();  // ʹ�ù�����������ֵ��ʼ��vw

    if (!vw.empty())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        F13(&vw[0]);  // ����F13
#include STSTEM_WARNING_POP
        // ...
    }
}
