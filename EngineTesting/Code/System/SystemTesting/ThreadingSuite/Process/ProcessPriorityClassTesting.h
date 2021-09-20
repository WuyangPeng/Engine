///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/11 19:02)

#ifndef SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H
#define SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ProcessPriorityClassTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProcessPriorityClassTesting;
        using ParentType = UnitTest;

    public:
        explicit ProcessPriorityClassTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void PriorityClassTest();
        void BackgroundProcessingTest();

    private:
        using ProcessCreationFlagsCollection = std::vector<ProcessCreation>;

    private:
        ProcessCreationFlagsCollection processCreationFlags;
        String processFullPath;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H