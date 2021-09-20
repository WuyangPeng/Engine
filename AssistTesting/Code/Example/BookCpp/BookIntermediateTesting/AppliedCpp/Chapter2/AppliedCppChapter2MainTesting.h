///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.0.0 (2021/01/27 0:10)

#ifndef BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H
#define BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookIntermediate
{
    namespace AppliedCpp
    {
        class AppliedCppChapter2MainTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = AppliedCppChapter2MainTesting;
            using ParentType = UnitTest;

        public:
            explicit AppliedCppChapter2MainTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest();
        };
    }
}

#endif  // BOOK_INTERMEDIATE_APPLIED_CPP_CHAPTER2_MAIN_TESTING_H