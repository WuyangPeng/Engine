///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER2_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER2_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "DataAccessObject.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        // ��Ҫ�������Դ���Ͳ�Ʒ����
        using DataAccessObjectPtr = std::unique_ptr<DataAccessObject>;

        class Customer2 final
        {
        public:
            using ClassType = Customer2;

        public:
            Customer2() noexcept;
            explicit Customer2(bool testMode) noexcept;

            CLASS_INVARIANT_DECLARE;

            void Save();

        private:
            DataAccessObjectPtr GetDataAccessObject() const;

            // ... more operations here...

            bool inTestMode{ false };

            // ...more attributes here...
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_CUSTOMER2_H
