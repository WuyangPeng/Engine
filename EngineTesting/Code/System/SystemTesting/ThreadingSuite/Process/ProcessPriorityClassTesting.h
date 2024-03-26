/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:05)

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