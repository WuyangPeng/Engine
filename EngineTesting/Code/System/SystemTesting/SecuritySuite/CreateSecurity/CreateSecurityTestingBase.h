///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/25 13:46)

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