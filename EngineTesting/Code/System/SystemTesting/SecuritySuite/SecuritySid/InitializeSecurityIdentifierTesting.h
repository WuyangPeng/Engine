///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 21:31)

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
        void DoRunUnitTest() final;
        void MainTest();

        void InitializeSidTest();

        void DoInitializeSidTest(SecuritySIDIndentifierAuthority& identifierAuthority);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_IDENTIFIER_TESTING_H