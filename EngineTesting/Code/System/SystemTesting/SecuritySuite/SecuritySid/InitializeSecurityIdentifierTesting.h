/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:27)

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