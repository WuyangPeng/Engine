///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:35)

#ifndef SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H
#define SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H

#include "ProcessTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <vector>

namespace System
{
    class ProcessPriorityClassTesting final : public ProcessTestingBase
    {
    public:
        using ClassType = ProcessPriorityClassTesting;
        using ParentType = ProcessTestingBase;

    public:
        explicit ProcessPriorityClassTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PriorityClassTest();
        void BackgroundProcessingTest();

        void DoPriorityClassTest(ProcessCreation processPriority);

    private:
        using ProcessCreationContainer = std::vector<ProcessCreation>;

    private:
        ProcessCreationContainer processCreations;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PROCESS_PRIORITY_CLASS_TESTING_H