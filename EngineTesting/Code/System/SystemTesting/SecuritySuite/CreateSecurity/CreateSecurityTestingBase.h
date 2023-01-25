///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/25 13:46)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateSecurityTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateSecurityTestingBase;
        using ParentType = UnitTest;

    public:
        explicit CreateSecurityTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using SecurityRequestedInformationContainer = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationContainer securityRequestedInformations;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H