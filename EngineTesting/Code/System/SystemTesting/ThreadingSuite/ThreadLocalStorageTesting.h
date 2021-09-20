///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/11 15:33)

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
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_LOCAL_STORAGE_TESTING_H