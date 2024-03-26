/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:25)

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