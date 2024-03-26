/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:18)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAuditAccessAceTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_ACE_TESTING_H