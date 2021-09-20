///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_REALTIME_CURRENCY_CONVERSION_SERVICE_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_REALTIME_CURRENCY_CONVERSION_SERVICE_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CurrencyConverter.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class RealtimeCurrencyConversionService : public CurrencyConverter
        {
        public:
            using ClassType = RealtimeCurrencyConversionService;
            using ParentType = CurrencyConverter;

        public:
            CLASS_INVARIANT_OVERRIDE_DECLARE;

            long double GetConversionFactor() const noexcept override;
            // ...more members here that are required to access the service...
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_REALTIME_CURRENCY_CONVERSION_SERVICE_H
