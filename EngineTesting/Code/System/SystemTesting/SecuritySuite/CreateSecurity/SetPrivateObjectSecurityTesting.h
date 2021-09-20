///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/27 19:57)

#ifndef SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SetPrivateObjectSecurityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetPrivateObjectSecurityTesting;
        using ParentType = UnitTest;

    public:
        explicit SetPrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetPrivateObjectSecurityTest();

    private:
        using SecurityRequestedInformationFlagsCollection = std::vector<SecurityRequestedInformation>;
        using SecurityAutoInheritFlagsCollection = std::vector<SecurityAutoInherit>;

    private:
        SecurityRequestedInformationFlagsCollection securityRequestedInformationFlags;
        SecurityAutoInheritFlagsCollection securityAutoInheritFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H