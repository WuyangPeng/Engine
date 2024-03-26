/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:05)

#ifndef SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H

#include "ProcessTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <vector>

namespace System
{
    class CreateProcessTesting final : public ProcessTestingBase
    {
    public:
        using ClassType = CreateProcessTesting;
        using ParentType = ProcessTestingBase;

    public:
        explicit CreateProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ProcessTest();
        void DoProcessTest(ProcessCreation processCreation);

    private:
        using ProcessCreationContainer = std::vector<ProcessCreation>;

    private:
        ProcessCreationContainer processCreations;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_PROCESS_TESTING_H