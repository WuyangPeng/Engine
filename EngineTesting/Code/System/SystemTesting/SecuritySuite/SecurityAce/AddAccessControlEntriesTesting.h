///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:45)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_CONTROL_ENTRIES_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_CONTROL_ENTRIES_TESTING_H

#include "SecurityAceTestingBase.h"
#include "System/Security/Using/SecurityAclUsing.h"

namespace System
{
    class AddAccessControlEntriesTesting final : public SecurityAceTestingBase
    {
    public:
        using ClassType = AddAccessControlEntriesTesting;
        using ParentType = SecurityAceTestingBase;

    public:
        explicit AddAccessControlEntriesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetAccessControlEntriesTest();
        void ResultTest(const SecurityAclSizeInformation& aclSizeInformation, AccessCheckAclPtr dacl, AccessCheckAclPtr acl);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_CONTROL_ENTRIES_TESTING_H