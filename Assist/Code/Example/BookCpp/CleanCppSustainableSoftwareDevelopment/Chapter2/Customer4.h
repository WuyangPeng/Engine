///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER4_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER4_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class DataAccessObject;

        class Customer4 final
        {
        public:
            using ClassType = Customer4;

        public:
            Customer4() = delete;  // C++11���﷨��ָʾ������������Customer()�Ĺ��캯��
            Customer4(DataAccessObject& dataAccessObject) noexcept;

            CLASS_INVARIANT_DECLARE;

            void Save() noexcept;

        private:
            DataAccessObject& dataAccessObject;
            // ...
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER4_H
