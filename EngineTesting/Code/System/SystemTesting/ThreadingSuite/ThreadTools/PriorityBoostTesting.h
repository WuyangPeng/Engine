///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 20:07)

#ifndef SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H
#define SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H

#include "ThreadToolsTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class PriorityBoostTesting final : public ThreadToolsTestingBase
    {
    public:
        using ClassType = PriorityBoostTesting;
        using ParentType = ThreadToolsTestingBase;

    public:
        explicit PriorityBoostTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();

        void DoThreadTest(WindowsHandle mutexHandle);
        void ResultTest(WindowsHandle threadHandle, WindowsDWord threadID, WindowsHandle mutexHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H