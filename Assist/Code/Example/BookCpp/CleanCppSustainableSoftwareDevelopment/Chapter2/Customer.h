///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE Customer final
        {
        public:
            using ClassType = Customer;

        public:
            CLASS_INVARIANT_DECLARE;

            std::string Main1(const std::string& value) const;
            void Main2() const;
            void Main3() const noexcept;
            void Main4() const noexcept;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER_H
