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
#include "CurrencyConverter.h"
#include "RealtimeCurrencyConversionService.h"
#include "Service.h"
#include "UserOfConversionService.h"
#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/Helper/CleanCppSustainableSoftwareDevelopmentClassInvariantMacro.h"

CLASS_INVARIANT_STUB_DEFINE(BookAdvanced::CleanCppSustainableSoftwareDevelopment, Service)

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Service::RealtimeCurrencyConversionServiceMain() const
{
    CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CLASS_IS_VALID_CONST_9;

    std::shared_ptr<CurrencyConverter> conversionService = std::make_shared<RealtimeCurrencyConversionService>();

    UserOfConversionService userOfConversionService{ conversionService };
    userOfConversionService.DoSomething();
}

void BookAdvanced::CleanCppSustainableSoftwareDevelopment::Service::CurrencyConversionServiceMockMain() const
{
    std::shared_ptr<CurrencyConverter> conversionService = std::make_shared<CurrencyConversionServiceMock>();

    UserOfConversionService userOfConversionService{ conversionService };
    userOfConversionService.DoSomething();
}
