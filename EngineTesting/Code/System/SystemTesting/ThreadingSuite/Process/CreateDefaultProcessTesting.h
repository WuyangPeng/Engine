///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 16:55)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_PROCESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateDefaultProcessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateDefaultProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateDefaultProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ProcessTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_PROCESS_TESTING_H