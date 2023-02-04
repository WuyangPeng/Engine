///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:54)

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
        void DoRunUnitTest() final;
        void MainTest();

        void GetSubAuthorityTest();

        void DoGetSubAuthorityTest(SecuritySIDIndentifierAuthority& identifierAuthority);
        void NextSubAuthorityCountTest(WindowsUCharPtr securityIdentifierSubAuthorityCount, SecuritySID& sid);
        void GetSecurityIdentifierSubAuthorityTest(const WindowsUChar* nextSubAuthorityCount, const WindowsUChar* securityIdentifierSubAuthorityCount, SecuritySID& sid);
        NODISCARD SecuritySID GetSecuritySID(SecuritySIDIndentifierAuthority& identifierAuthority);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_SUB_AUTHORITY_TESTING_H