///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/04/22 21:59)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR1_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR1_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        // ������Ϣ�ϲ�ķ�װ�ࡣ
        class AutomaticDoor1 final
        {
        public:
            using ClassType = AutomaticDoor1;

        public:
            enum class State
            {
                Closed = 1,
                Opening,
                Open,
                Closing
            };

        private:
            State state;
            // ...more attributes here...

        public:
            State GetState() const noexcept;
            // ... more member functions here...

            CLASS_INVARIANT_DECLARE;
        };
    }
}

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR1_H
