///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.7 (2021/11/30 21:58)

#ifndef BOOK_ADVANCED_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_PLACEHOLDER_TESTING_H
#define BOOK_ADVANCED_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace ThrivingInACrowdedAndChangingWorld
    {
        class ThrivingInACrowdedAndChangingWorldPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = ThrivingInACrowdedAndChangingWorldPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit ThrivingInACrowdedAndChangingWorldPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_THRIVING_IN_A_CROWDED_AND_CHANGING_WORLD_PLACEHOLDER_TESTING_H