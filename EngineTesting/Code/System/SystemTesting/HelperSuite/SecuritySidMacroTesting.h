///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 09:41)

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
        void DoRunUnitTest() override;
        void MainTest();

        void NullSecuritySidTest();
        void WorldSecuritySidTest();
        void LocalSecuritySidTest();
        void CreatorSecuritySidTest();
        void NonUniqueSecurityTest();
        void NtSecurityTest();
        void ResourceManagerSecurityTest();
        void MandatoryLabelSecurityTest();

        void SecurityTest(const SecuritySidIdentifierAuthority& identifierAuthority, uint32_t endValue);

    private:
        static constexpr auto securitySidSize = 6;
        static constexpr auto endSecuritySidIndex = securitySidSize - 1;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_SECURITY_SID_MACRO_TESTING_H
