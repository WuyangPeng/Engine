///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:29)

#ifndef SYSTEM_THREADING_SUITE_THREAD_LOCAL_STORAGE_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_LOCAL_STORAGE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadLocalStorageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadLocalStorageTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadLocalStorageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();

        void ThreadLocalStorageThread(WindowsDWord threadLocalStorageIndex);
        void CreateThread(int threadCount, WindowsDWord threadLocalStorageIndex);
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_LOCAL_STORAGE_TESTING_H