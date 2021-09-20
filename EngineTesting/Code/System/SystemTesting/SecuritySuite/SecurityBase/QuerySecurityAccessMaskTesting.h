///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/04 13:51)

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

    private:
        using SecurityRequestedInformationFlagsCollection = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationFlagsCollection securityRequestedInformationFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_QUERY_SECURITY_ACCESS_MASK_TESTING_H