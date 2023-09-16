///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:37)

#ifndef SYSTEM_SECURITY_SUITE_ACCESS_CHECK_BY_TYPE_RESULT_LIST_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACCESS_CHECK_BY_TYPE_RESULT_LIST_TESTING_H

#include "AccessCheckTestingBase.h"
#include "System/Security/Using/SecuritySidUsing.h"

namespace System
{
    class AccessCheckByTypeResultListTesting final : public AccessCheckTestingBase
    {
    public:
        using ClassType = AccessCheckByTypeResultListTesting;
        using ParentType = AccessCheckTestingBase;

    public:
        explicit AccessCheckByTypeResultListTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AccessCheckByTypeResultListTest();

        void DuplicateTokenTest(WindowsHandle tokenHandle);
        void DoAccessCheckTest(WindowsHandle impersonatedToken);
        void GetAccessCheckTest(FileHandleDesiredAccess accessMask, BufferType& buffer, WindowsHandle impersonatedToken);
        NODISCARD SecuritySid GetSecuritySid();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_BY_TYPE_RESULT_LIST_TESTING_H