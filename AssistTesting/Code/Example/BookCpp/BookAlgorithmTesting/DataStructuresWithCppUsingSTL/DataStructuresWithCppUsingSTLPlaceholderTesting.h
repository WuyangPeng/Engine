///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.1 (2021/02/15 13:55)

#ifndef BOOK_ALGORITHM_DATA_STRUCTURES_WITH_CPP_USING_STL_PLACEHOLDER_TESTING_H
#define BOOK_ALGORITHM_DATA_STRUCTURES_WITH_CPP_USING_STL_PLACEHOLDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAlgorithm
{
    namespace DataStructuresWithCppUsingSTL
    {
        class DataStructuresWithCppUsingSTLPlaceholderTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = DataStructuresWithCppUsingSTLPlaceholderTesting;
            using ParentType = UnitTest;

        public:
            explicit DataStructuresWithCppUsingSTLPlaceholderTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_ALGORITHM_DATA_STRUCTURES_WITH_CPP_USING_STL_PLACEHOLDER_TESTING_H