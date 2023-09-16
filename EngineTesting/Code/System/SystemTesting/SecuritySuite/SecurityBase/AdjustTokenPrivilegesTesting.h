///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:48)

#ifndef SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_PRIVILEGES_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_PRIVILEGES_TESTING_H

#include "SecurityBaseTestingBase.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"

namespace System
{
    class AdjustTokenPrivilegesTesting final : public SecurityBaseTestingBase
    {
    public:
        using ClassType = AdjustTokenPrivilegesTesting;
        using ParentType = SecurityBaseTestingBase;

    public:
        explicit AdjustTokenPrivilegesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetAdjustTokenPrivilegesTest();

        void DoGetAdjustTokenPrivilegesTest(WindowsHandle tokenHandle);
        void PrivilegesTest(const String& lookupPrivilegeName, WindowsHandle tokenHandle);

    private:
        using LookupPrivilegeNameContainer = std::vector<String>;

    private:
        LookupPrivilegeNameContainer lookupPrivilegeNames;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_PRIVILEGES_TESTING_H