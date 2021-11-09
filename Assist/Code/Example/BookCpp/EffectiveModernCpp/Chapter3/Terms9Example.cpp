///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/02 21:07)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms9.h"
#include "Terms9Example.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter3::Terms9::Terms9Example::Terms9Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter3::Terms9, Terms9Example)

void BookExperience::EffectiveModernCpp::Chapter3::Terms9::Terms9Example::MyAllocList0Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example0::MyAllocList<Widget> lw;  // �ͻ�����
}

void BookExperience::EffectiveModernCpp::Chapter3::Terms9::Terms9Example::MyAllocList1Example() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    Example1::MyAllocList<Widget>::Type lw;  // �ͻ�����
}
