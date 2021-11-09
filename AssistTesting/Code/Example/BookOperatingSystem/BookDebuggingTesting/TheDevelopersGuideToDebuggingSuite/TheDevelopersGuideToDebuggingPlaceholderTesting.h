///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.4 (2021/10/10 19:54)

#ifndef BOOK_DEBUGGING_TESTING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_TESTING_H
#define BOOK_DEBUGGING_TESTING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDebugging
{
    namespace TheDevelopersGuideToDebugging
    {
        class TheDevelopersGuideToDebuggingPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = TheDevelopersGuideToDebuggingPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit TheDevelopersGuideToDebuggingPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_DEBUGGING_TESTING_THE_DEVELOPERS_GUIDE_TO_DEBUGGING_PLACEHOLDER_TESTING_H