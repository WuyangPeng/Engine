///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 16:35)

#ifndef SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H
#define SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitializeAclTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitializeAclTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeAclTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RevisionInitializeAclTest(AccessControlListRevision accessControlListRevision);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_ACL_TESTING_H