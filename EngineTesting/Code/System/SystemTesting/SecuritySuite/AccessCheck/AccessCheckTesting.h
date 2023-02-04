///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/26 21:24)

#ifndef SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H

#include "AccessCheckTestingBase.h"

namespace System
{
    class AccessCheckTesting final : public AccessCheckTestingBase
    {
    public:
        using ClassType = AccessCheckTesting;
        using ParentType = AccessCheckTestingBase;

    public:
        explicit AccessCheckTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AccessCheckTest();

        void DuplicateTokenTest(WindowsHandle tokenHandle);
        void DoAccessCheckTest(WindowsHandle impersonatedToken);
        void GetAccessCheckTest(FileHandleDesiredAccess accessMask, BufferType& buffer, WindowsHandle impersonatedToken);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_H