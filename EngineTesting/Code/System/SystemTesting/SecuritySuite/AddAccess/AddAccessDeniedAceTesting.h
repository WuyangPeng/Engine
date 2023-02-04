///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 13:34)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAccessDeniedAceTest(AccessControlListRevision accessControlListRevision);
        void AddAccessTest(size_t index, AccessCheckACLPtr acl, AccessControlListRevision accessControlListRevision, SecuritySID& sid);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_DENIED_ACE_TESTING_H