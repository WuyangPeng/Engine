///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:53)

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