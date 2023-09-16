///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:53)

#ifndef SYSTEM_SECURITY_SUITE_COPY_SECURITY_IDENTIFIER_TESTING_H
#define SYSTEM_SECURITY_SUITE_COPY_SECURITY_IDENTIFIER_TESTING_H

#include "SecuritySidTestingBase.h"

namespace System
{
    class CopySecurityIdentifierTesting final : public SecuritySidTestingBase
    {
    public:
        using ClassType = CopySecurityIdentifierTesting;
        using ParentType = SecuritySidTestingBase;

    public:
        explicit CopySecurityIdentifierTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CopySecurityIdentifierTest();

        void DoCopySecurityIdentifierTest(SecuritySidIdentifierAuthority& identifierAuthority);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_COPY_SECURITY_IDENTIFIER_TESTING_H