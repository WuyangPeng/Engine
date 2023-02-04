///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 21:05)

#ifndef SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_GROUPS_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_GROUPS_TESTING_H

#include "SecurityBaseTestingBase.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"

namespace System
{
    class AdjustTokenGroupsTesting final : public SecurityBaseTestingBase
    {
    public:
        using ClassType = AdjustTokenGroupsTesting;
        using ParentType = SecurityBaseTestingBase;

    public:
        explicit AdjustTokenGroupsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetAdjustTokenGroupsTest();

        void DoGetAdjustTokenGroupsTest(WindowsHandle tokenHandle);
        void GroupsTest(SecurityTokenAttributesGroup securityTokenAttributesGroup, WindowsHandle tokenHandle);

    private:
        using SecurityTokenAttributesGroupContainer = std::vector<SecurityTokenAttributesGroup>;

    private:
        SecurityTokenAttributesGroupContainer securityTokenAttributesGroups;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_GROUPS_TESTING_H