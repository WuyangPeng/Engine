///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:41)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_DENIED_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_DENIED_ACE_TESTING_H

#include "AddAccessTestingBase.h"

namespace System
{
    class AddAccessDeniedAceTesting final : public AddAccessTestingBase
    {
    public:
        using ClassType = AddAccessDeniedAceTesting;
        using ParentType = AddAccessTestingBase;

    public:
        explicit AddAccessDeniedAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAccessDeniedAceTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(size_t index, AccessCheckAclPtr acl, AccessControlListRevision accessControlListRevision, SecuritySid& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_DENIED_ACE_TESTING_H