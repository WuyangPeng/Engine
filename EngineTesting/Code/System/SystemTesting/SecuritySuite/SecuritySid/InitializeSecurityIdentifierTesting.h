///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:53)

#ifndef SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H
#define SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H

#include "SecuritySidTestingBase.h"

namespace System
{
    class InitializeSecurityIdentifierTesting final : public SecuritySidTestingBase
    {
    public:
        using ClassType = InitializeSecurityIdentifierTesting;
        using ParentType = SecuritySidTestingBase;

    public:
        explicit InitializeSecurityIdentifierTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitializeSidTest();

        void DoInitializeSidTest(SecuritySidIdentifierAuthority& identifierAuthority);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H