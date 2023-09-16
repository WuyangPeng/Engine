///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:42)

#ifndef SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H

#include "AddAccessTestingBase.h"

namespace System
{
    class AddAuditAccessObjectAceTesting final : public AddAccessTestingBase
    {
    public:
        using ClassType = AddAuditAccessObjectAceTesting;
        using ParentType = AddAccessTestingBase;

    public:
        explicit AddAuditAccessObjectAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAuditAccessObjectAceTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H