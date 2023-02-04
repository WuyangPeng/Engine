///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 14:52)

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
        void DoRunUnitTest() final;
        void MainTest();

        void GetAccessControlEntriesTest();
        void ResultTest(const SecurityAclSizeInformation& aclSizeInformation, AccessCheckACLPtr dacl, AccessCheckACLPtr acl);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_CONTROL_ENTRIES_TESTING_H