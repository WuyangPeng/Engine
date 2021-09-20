///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE Service final
        {
        public:
            using ClassType = Service;

        public:
            CLASS_INVARIANT_DECLARE;

            void RealtimeCurrencyConversionServiceMain() const;
            void CurrencyConversionServiceMockMain() const;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_SERVICE_H
