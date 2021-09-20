///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/30 21:25)

#ifndef SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H
#define SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class InitializeSecurityIdentifierTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitializeSecurityIdentifierTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeSecurityIdentifierTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void Init();

        void InitializeSidTest();
        void AllocateTest();

    private:
        using SecuritySIDIndentifierAuthorityCollection = std::vector<SecuritySIDIndentifierAuthority>;

    private:
        SecuritySIDIndentifierAuthorityCollection securitySIDIndentifierAuthority;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H