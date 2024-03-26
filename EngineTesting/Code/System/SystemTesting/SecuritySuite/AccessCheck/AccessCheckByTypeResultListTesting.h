/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:10)

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
        void GetAccessCheckTest(FileHandleDesiredAccess accessMask, CharBufferType& buffer, WindowsHandle impersonatedToken);
        NODISCARD SecuritySid GetSecuritySid();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACCESS_CHECK_BY_TYPE_RESULT_LIST_TESTING_H