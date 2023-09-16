///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:40)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H

#include "AddAccessTestingBase.h"

namespace System
{
    class AddAccessAllowedAceTesting final : public AddAccessTestingBase
    {
    public:
        using ClassType = AddAccessAllowedAceTesting;
        using ParentType = AddAccessTestingBase;

    public:
        explicit AddAccessAllowedAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AddAccessAllowedAccessControlEntriesTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SpecificAccess specificAccess, SecuritySid& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H