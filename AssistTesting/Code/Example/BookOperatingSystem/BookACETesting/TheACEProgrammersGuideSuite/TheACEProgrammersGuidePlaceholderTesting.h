///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.4 (2021/06/12 13:08)

#ifndef BOOK_ACE_THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_TESTING_H
#define BOOK_ACE_THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookACE
{
    namespace TheACEProgrammersGuide
    {
        class TheACEProgrammersGuidePlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = TheACEProgrammersGuidePlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit TheACEProgrammersGuidePlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ACE_THE_ACE_PROGRAMMERS_GUIDE_PLACEHOLDER_TESTING_H