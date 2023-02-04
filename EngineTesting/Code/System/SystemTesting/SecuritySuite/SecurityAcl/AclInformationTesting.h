///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:35)

#ifndef SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AclInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AclInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit AclInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InformationTest(AccessControlListRevision accessControlListRevision);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H