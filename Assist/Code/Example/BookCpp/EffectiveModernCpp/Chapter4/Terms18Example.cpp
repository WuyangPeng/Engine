///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/10 21:11)

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

    // pInvestment是型别是std::unique_ptr<Investment>
    auto pInvestment = Example0::MakeInvestment(arguments);

    // ...
    // *pInvestment在此析构。
}

void BookExperience::EffectiveModernCpp::Chapter4::Terms18::Terms18Example::SharedPtrExample() const
{
    EFFECTIVE_MODERN_CPP_CLASS_IS_VALID_CONST_9;

    auto arguments = 0;

    // 将std::unique_ptr型别的对象转换为std::shared_ptr型别
    std::shared_ptr<Investment> sp = Example2::MakeInvestment(arguments);
}
