///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/09 21:20)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_DATA_ACCESS_OBJECT_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_DATA_ACCESS_OBJECT_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class DataAccessObject
        {
        public:
            using ClassType = DataAccessObject;

        public:
            DataAccessObject() noexcept = default;
            virtual ~DataAccessObject() noexcept = default;
            DataAccessObject(const DataAccessObject& rhs) noexcept = default;
            DataAccessObject& operator=(const DataAccessObject& rhs) noexcept = default;
            DataAccessObject(DataAccessObject&& rhs) noexcept = default;
            DataAccessObject& operator=(DataAccessObject&& rhs) noexcept = default;

            CLASS_INVARIANT_VIRTUAL_DECLARE;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_DATA_ACCESS_OBJECT_H
