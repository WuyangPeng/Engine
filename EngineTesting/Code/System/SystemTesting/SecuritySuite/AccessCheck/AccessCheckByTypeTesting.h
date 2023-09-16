///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:38)

#ifndef SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BY_TYPE_H
#define SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BY_TYPE_H

#include "AccessCheckTestingBase.h"

namespace System
{
    class AccessCheckByTypeTesting final : public AccessCheckTestingBase
    {
    public:
        using ClassType = AccessCheckByTypeTesting;
        using ParentType = AccessCheckTestingBase;

    public:
        explicit AccessCheckByTypeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AccessCheckByTypeTest();

        void DuplicateTokenTest(WindowsHandle tokenHandle);
        void DoAccessCheckByTypeTest(WindowsHandle impersonatedToken);
        void GetAccessCheckTest(FileHandleDesiredAccess accessMask, BufferType& buffer, WindowsHandle impersonatedToken);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_TESTING_BY_TYPE_H