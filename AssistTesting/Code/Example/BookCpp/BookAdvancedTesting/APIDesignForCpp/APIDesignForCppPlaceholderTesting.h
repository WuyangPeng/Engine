///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.1 (2021/03/20 20:09)

#ifndef BOOK_ADVANCED_API_DESIGN_FOR_CPP_PLACEHOLDER_TESTING_H
#define BOOK_ADVANCED_API_DESIGN_FOR_CPP_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace APIDesignForCpp
    {
        class APIDesignForCppPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = APIDesignForCppPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit APIDesignForCppPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ADVANCED_API_DESIGN_FOR_CPP_PLACEHOLDER_TESTING_H