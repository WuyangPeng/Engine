///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/03 21:07)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TESTING_MULTITHREADING_APPLICATIONS_IN_WIN32_TESTING_H
#define BOOK_CONCURRENT_PROGRAMMING_TESTING_MULTITHREADING_APPLICATIONS_IN_WIN32_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookConcurrentProgramming
{
    namespace MultithreadingApplicationsInWin32
    {
        class MultithreadingApplicationsInWin32Testing final : public CoreTools::UnitTest
        {
        public:
            using ClassType = MultithreadingApplicationsInWin32Testing;
            using ParentType = UnitTest;

        public:
            explicit MultithreadingApplicationsInWin32Testing(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;
            void MainTest() noexcept;
        };
    }
}

#endif  // BOOK_CONCURRENT_PROGRAMMING_TESTING_MULTITHREADING_APPLICATIONS_IN_WIN32_TESTING_H