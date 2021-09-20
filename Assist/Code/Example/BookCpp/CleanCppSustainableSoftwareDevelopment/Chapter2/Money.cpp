///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "Money.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

BookAdvanced::CleanCppSustainableSoftwareDevelopment::Money::Money(double value) noexcept
    : value{ value }
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Money)

double BookAdvanced::CleanCppSustainableSoftwareDevelopment::Money::GetValue() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return value;
}

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::operator<(const Money& lhs, const Money& rhs) noexcept
{
    return lhs.GetValue() < rhs.GetValue();
}

bool BookAdvanced::CleanCppSustainableSoftwareDevelopment::operator==(const Money& lhs, const Money& rhs) noexcept
{
    return lhs.GetValue() == rhs.GetValue();
}