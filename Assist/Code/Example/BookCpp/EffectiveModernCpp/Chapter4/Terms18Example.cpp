///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/10 21:11)

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppExport.h"

#include "Terms18.h"
#include "Terms18Example.h"
#include "System/Helper/PragmaWarning.h"
#include "Example/BookCpp/EffectiveModernCpp/Helper/EffectiveModernCppClassInvariantMacro.h"

#include <vector>

BookExperience::EffectiveModernCpp::Chapter4::Terms18::Terms18Example::Terms18Example() noexcept
{
    EFFECTIVE_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookExperience::EffectiveModernCpp::Chapter4::Terms18, Terms18Example)

void BookExperience::EffectiveModernCpp::Chapter4::Terms18::Terms18Example::MakeInvestmentExample() const noexcept
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto arguments = 0;
    // ...

    // pInvestment���ͱ���std::unique_ptr<Investment>
    auto pInvestment = Example0::MakeInvestment(arguments);

    // ...
    // *pInvestment�ڴ�������
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms18::Terms18Example::SharedPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto arguments = 0;

    // ��std::unique_ptr�ͱ�Ķ���ת��Ϊstd::shared_ptr�ͱ�
    std::shared_ptr<Investment> sp = Example2::MakeInvestment(arguments);
}
