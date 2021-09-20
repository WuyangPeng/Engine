///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERTER_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERTER_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CurrencyConverter
        {
        public:
            using ClassType = CurrencyConverter;

        public:
            CurrencyConverter() noexcept = default;
            virtual ~CurrencyConverter() noexcept = default;
            CurrencyConverter(const CurrencyConverter& rhs) noexcept = default;
            CurrencyConverter& operator=(const CurrencyConverter& rhs) noexcept = default;
            CurrencyConverter(CurrencyConverter&& rhs) noexcept = default;
            CurrencyConverter& operator=(CurrencyConverter&& rhs) noexcept = default;

            CLASS_INVARIANT_VIRTUAL_DECLARE;

            virtual long double GetConversionFactor() const = 0;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CURRENCY_CONVERTER_H
