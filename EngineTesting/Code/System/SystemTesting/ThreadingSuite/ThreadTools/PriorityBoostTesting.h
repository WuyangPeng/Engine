/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:08)

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
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void DoThreadTest(WindowsHandle mutexHandle);
        void ResultTest(WindowsHandle threadHandle, WindowsDWord threadId, WindowsHandle mutexHandle);

        static WindowsDWord SYSTEM_WIN_API ThreadStartRoutine(void* threadParameter) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H