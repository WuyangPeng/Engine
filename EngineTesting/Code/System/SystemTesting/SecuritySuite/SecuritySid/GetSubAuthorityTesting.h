///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:31)

#ifndef SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class GetSubAuthorityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetSubAuthorityTesting;
        using ParentType = UnitTest;

    public:
        explicit GetSubAuthorityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void Init();

        void GetSubAuthorityTest();

        void DoGetSubAuthorityTest(SecuritySIDIndentifierAuthority identifierAuthority);

    private:
        using SecuritySIDIndentifierAuthorityContainer = std::vector<SecuritySIDIndentifierAuthority>;

    private:
        SecuritySIDIndentifierAuthorityContainer securitySIDIndentifierAuthority;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H