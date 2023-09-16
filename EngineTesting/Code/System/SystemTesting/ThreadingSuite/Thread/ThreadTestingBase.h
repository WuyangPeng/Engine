///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:38)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TESTING_BASE_H
#define SYSTEM_THREADING_SUITE_THREAD_TESTING_BASE_H

#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadTestingBase;
        using ParentType = UnitTest;

    public:
        explicit ThreadTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void CloseThreadTest(ThreadHandle threadHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TESTING_BASE_H