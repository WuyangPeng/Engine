///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 14:03)

#ifndef SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ReleaseSemaphoreTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReleaseSemaphoreTesting;
        using ParentType = UnitTest;

    public:
        explicit ReleaseSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InitReleaseTest();
        void WaitForSemaphoreTest(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H