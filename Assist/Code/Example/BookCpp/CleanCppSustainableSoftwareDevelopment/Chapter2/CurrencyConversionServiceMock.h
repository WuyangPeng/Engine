///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERSION_SERVICE_MOCK_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERSION_SERVICE_MOCK_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CurrencyConverter.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CurrencyConversionServiceMock : public CurrencyConverter
        {
        public:
            using ClassType = CurrencyConversionServiceMock;
            using ParentType = CurrencyConverter;

        public:
            CLASS_INVARIANT_OVERRIDE_DECLARE;

            long double GetConversionFactor() const noexcept override;
            void SetConversionFactor(const long double value) noexcept;

        private:
            long double conversionFactor{ 0.5 };
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERSION_SERVICE_MOCK_H
