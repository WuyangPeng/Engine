/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:27)

#ifndef SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H

#include "SecuritySidTestingBase.h"

namespace System
{
    class GetSubAuthorityTesting final : public SecuritySidTestingBase
    {
    public:
        using ClassType = GetSubAuthorityTesting;
        using ParentType = SecuritySidTestingBase;

    public:
        explicit GetSubAuthorityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr WindowsByte subAuthorityCount{ 5 };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetSubAuthorityTest();

        void DoGetSubAuthorityTest(SecuritySidIdentifierAuthority& identifierAuthority);
        void NextSubAuthorityCountTest(WindowsUCharPtr securityIdentifierSubAuthorityCount, SecuritySid& sid);
        void GetSecurityIdentifierSubAuthorityTest(const WindowsUChar* nextSubAuthorityCount, const WindowsUChar* securityIdentifierSubAuthorityCount, SecuritySid& sid);
        NODISCARD SecuritySid GetSecuritySid(SecuritySidIdentifierAuthority& identifierAuthority);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H