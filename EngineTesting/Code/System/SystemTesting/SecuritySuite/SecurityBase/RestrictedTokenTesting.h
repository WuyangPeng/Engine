/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:25)

#ifndef SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H
#define SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H

#include "SecurityBaseTestingBase.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Security/Using/AccessCheckUsing.h"

#include <array>

namespace System
{
    class RestrictedTokenTesting final : public SecurityBaseTestingBase
    {
    public:
        using ClassType = RestrictedTokenTesting;
        using ParentType = SecurityBaseTestingBase;

    public:
        explicit RestrictedTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto securityBufferSize = 2u;
        static constexpr auto securitySidBufferSize = securityBufferSize * 2;
        using SecuritySidBufferType = std::array<SecuritySid, securitySidBufferSize>;
        using SecuritySidAndAttributesBufferType = std::array<SecuritySidAndAttributes, securityBufferSize>;
        using LocallyUniqueIdentifierAndAttributesBufferType = std::array<LocallyUniqueIdentifierAndAttributes, securityBufferSize>;
        using SpecifiesAdditionalPrivilegeOptionsContainer = std::vector<SpecifiesAdditionalPrivilegeOptions>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateRestrictedTokenTest();

        void DoCreateRestrictedTokenTest(WindowsHandle tokenHandle);
        NODISCARD SecuritySidAndAttributesBufferType GetSidsToDisable(SecuritySidBufferType& sid);
        void InitializeSecurityIdentifierTest(SecuritySidBufferType& sid,
                                              int count,
                                              SecuritySidAndAttributes& securitySidAndAttributes);
        NODISCARD LocallyUniqueIdentifierAndAttributesBufferType GetPrivilegesToDelete();
        void GetLookupPrivilegeValueTest(LocallyUniqueIdentifierAndAttributes& locallyUniqueIdentifierAndAttributes);
        NODISCARD SecuritySidAndAttributesBufferType GetSidsToRestrict(SecuritySidBufferType& sid);
        void RestrictedTest(WindowsHandle tokenHandle,
                            SecuritySidAndAttributesBufferType& sidsToDisable,
                            LocallyUniqueIdentifierAndAttributesBufferType& privilegesToDelete,
                            SecuritySidAndAttributesBufferType& sidsToRestrict);
        void DoRestrictedTest(WindowsHandle tokenHandle,
                              SpecifiesAdditionalPrivilegeOptions specifiesAdditionalPrivilegeOptions,
                              SecuritySidAndAttributesBufferType& sidsToDisable,
                              LocallyUniqueIdentifierAndAttributesBufferType& privilegesToDelete,
                              SecuritySidAndAttributesBufferType& sidsToRestrict);

    private:
        SpecifiesAdditionalPrivilegeOptionsContainer specifiesAdditionalPrivilegeOptionsContainer;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H