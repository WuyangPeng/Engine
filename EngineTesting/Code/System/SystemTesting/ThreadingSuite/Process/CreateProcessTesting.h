///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:52)

#ifndef SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateProcessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ProcessTest();

    private:
        using ProcessCreationFlagsContainer = std::vector<ProcessCreation>;

    private:
        ProcessCreationFlagsContainer processCreationFlags;
        String processFullPath;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H