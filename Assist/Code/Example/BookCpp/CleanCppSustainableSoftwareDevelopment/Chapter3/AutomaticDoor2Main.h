///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR2_MAIN_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR2_MAIN_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        class CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_DEFAULT_DECLARE AutomaticDoor2Main final
        {
        public:
            using ClassType = AutomaticDoor2Main;

        public:
            AutomaticDoor2Main() noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD int Main() const noexcept;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR2_MAIN_H