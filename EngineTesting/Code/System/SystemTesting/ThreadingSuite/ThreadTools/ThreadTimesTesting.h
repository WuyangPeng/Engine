/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:09)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadTimesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadTimesTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadTimesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTimeTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TIMES_TESTING_H