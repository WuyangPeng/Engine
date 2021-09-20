///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.2 (2021/04/22 21:59)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR1_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_CHAPTER2_AUTOMATIC_DOOR1_H

#include "Example/BookCpp/CleanCppSustainableSoftwareDevelopment/CleanCppSustainableSoftwareDevelopmentDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace BookAdvanced
{
    namespace CleanCppSustainableSoftwareDevelopment
    {
        // 隐藏信息较差的封装类。
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
