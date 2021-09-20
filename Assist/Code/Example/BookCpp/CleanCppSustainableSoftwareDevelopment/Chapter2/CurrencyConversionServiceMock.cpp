///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentExport.h"

#include "CurrencyConversionServiceMock.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, CurrencyConversionServiceMock)

long double BookAdvanced::CleanCppSustainableSoftwareDevelopment::CurrencyConversionServiceMock::GetConversionFactor() const noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    return conversionFactor;
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::CurrencyConversionServiceMock::SetConversionFactor(const long double value) noexcept
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_9;

    conversionFactor = value;
}
