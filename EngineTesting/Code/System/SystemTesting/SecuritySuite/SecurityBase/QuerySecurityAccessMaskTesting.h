///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 15:55)

#ifndef SYSTEM_SECURITY_SUITE_QUERY_SECURITY_ACCESS_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_QUERY_SECURITY_ACCESS_MASK_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class QuerySecurityAccessMaskTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = QuerySecurityAccessMaskTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySecurityAccessMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void QuerySecurityAccessMaskTest();

        void DoQuerySecurityAccessMaskTest(SecurityRequestedInformation SecurityRequestedInformation);

    private:
        using SecurityRequestedInformationContainer = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationContainer securityRequestedInformations;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_QUERY_SECURITY_ACCESS_MASK_TESTING_H