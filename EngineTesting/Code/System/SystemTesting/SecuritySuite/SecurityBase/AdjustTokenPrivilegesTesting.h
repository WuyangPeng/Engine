/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:25)

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