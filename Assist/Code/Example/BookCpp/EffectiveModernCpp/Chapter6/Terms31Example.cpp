///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/11/29 21:31)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms31.h"
#include "Terms31Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

BookExperience::EffectiveModernCpp::Chapter6::Terms31::Terms31Example::Terms31Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter6::Terms31, Terms31Example)

void BookExperience::EffectiveModernCpp::Chapter6::Terms31::Terms31Example::AddDivisorFilterExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    using FilterContainer = std::vector<std::function<bool(int)>>;

    FilterContainer filters;  // Ԫ��Ϊɸѡ����������

    filters.emplace_back([](int value) {
        return value % 5 == 0;
    });

    AddDivisorFilter();

    Example0::WorkWithContainer(std::vector<int>{ 1, 5, 9 });

    Example1::WorkWithContainer(std::vector<int>{ 1, 5, 9 });
}
