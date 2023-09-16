///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:49)

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
        void DoRunUnitTest() override;
        void MainTest();

        void QuerySecurityAccessMaskTest();

        void DoQuerySecurityAccessMaskTest(SecurityRequestedInformation securityRequestedInformation);

    private:
        using SecurityRequestedInformationContainer = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationContainer securityRequestedInformationContainer;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_QUERY_SECURITY_ACCESS_MASK_TESTING_H