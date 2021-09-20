///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:55)

#ifndef BOOK_WINDOWS_API_THE_OLD_NEW_THING_PLACEHOLDER_TESTING_H
#define BOOK_WINDOWS_API_THE_OLD_NEW_THING_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookWindowsAPI
{
    namespace TheOldNewThing
    {
        class TheOldNewThingPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = TheOldNewThingPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit TheOldNewThingPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_WINDOWS_API_THE_OLD_NEW_THING_PLACEHOLDER_TESTING_H