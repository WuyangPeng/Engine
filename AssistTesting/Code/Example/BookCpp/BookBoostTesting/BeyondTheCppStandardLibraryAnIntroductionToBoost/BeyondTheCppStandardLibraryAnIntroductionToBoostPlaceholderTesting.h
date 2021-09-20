///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 21:44)

#ifndef BOOK_BOOST_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_PLACEHOLDER_TESTING_H
#define BOOK_BOOST_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookBoost
{
    namespace BeyondTheCppStandardLibraryAnIntroductionToBoost 
    {
        class BeyondTheCppStandardLibraryAnIntroductionToBoostPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = BeyondTheCppStandardLibraryAnIntroductionToBoostPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit BeyondTheCppStandardLibraryAnIntroductionToBoostPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_BOOST_BEYOND_THE_CPP_STANDARD_LIBRARY_AN_INTRODUCTION_TO_BOOST_PLACEHOLDER_TESTING_H