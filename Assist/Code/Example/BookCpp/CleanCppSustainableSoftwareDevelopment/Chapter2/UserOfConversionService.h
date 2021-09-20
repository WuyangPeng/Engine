///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_USER_OF_CONVERSION_SERVICE_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_USER_OF_CONVERSION_SERVICE_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CurrencyConverter;

        class UserOfConversionService final
        {
        public:
            using ClassType = UserOfConversionService;

        public:
            UserOfConversionService() = delete;
            explicit UserOfConversionService(const std::shared_ptr<CurrencyConverter>& conversionService) noexcept;

            CLASS_INVARIANT_DECLARE;

            void DoSomething();
            // More of the public class interface follows here...

        private:
            std::shared_ptr<CurrencyConverter> conversionService;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_USER_OF_CONVERSION_SERVICE_H
