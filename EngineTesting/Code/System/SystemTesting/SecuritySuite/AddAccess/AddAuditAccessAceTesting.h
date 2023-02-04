///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 13:56)

#ifndef SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_ACE_TESTING_H

#include "AddAccessTestingBase.h"

namespace System
{
    class AddAuditAccessAceTesting final : public AddAccessTestingBase
    {
    public:
        using ClassType = AddAuditAccessAceTesting;
        using ParentType = AddAccessTestingBase;

    public:
        explicit AddAuditAccessAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAuditAccessAceTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(size_t index, AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SecuritySID& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_ACE_TESTING_H