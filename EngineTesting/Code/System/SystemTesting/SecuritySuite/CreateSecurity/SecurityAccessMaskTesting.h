///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/30 0:29)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecurityAccessMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityAccessMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityAccessMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetSecurityAccessMaskTest();

    private:
        using SecurityRequestedInformationFlagsCollection = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationFlagsCollection securityRequestedInformationFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H