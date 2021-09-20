///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/09 21:20)

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
            Customer4() = delete;  // C++11的语法，指示编译器不生成Customer()的构造函数
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
