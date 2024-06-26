/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:24)

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
        void DoRunUnitTest() override;
        void MainTest();

        void InformationTest(AccessControlListRevision accessControlListRevision);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H