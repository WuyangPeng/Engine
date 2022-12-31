///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/17 18:44)

#ifndef SYSTEM_TESTING_HELPER_SUITE_SECURITY_SID_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_SECURITY_SID_MACRO_TESTING_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecuritySidMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecuritySidMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SecuritySidMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NullSecuritySidTest();
        void WorldSecuritySidTest();
        void LocalSecuritySidTest();
        void CreatorSecuritySidTest();
        void NonUniqueSecurityTest();
        void NtSecurityTest();
        void ResourceManagerSecurityTest();
        void MandatoryLabelSecurityTest();

        void SecurityTest(const SecuritySIDIndentifierAuthority& identifierAuthority, uint32_t endValue);

    private:
        static constexpr auto securitySidSize = 6;
        static constexpr auto endSecuritySidIndex = securitySidSize - 1;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_SECURITY_SID_MACRO_TESTING_H
