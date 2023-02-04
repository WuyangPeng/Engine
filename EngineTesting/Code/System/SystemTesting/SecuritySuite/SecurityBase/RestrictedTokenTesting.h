///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 15:21)

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
        using SecuritySIDBufferType = std::array<SecuritySID, securityBufferSize * 2>;
        using SecuritySidAndAttributesBufferType = std::array<SecuritySidAndAttributes, securityBufferSize>;
        using LUIDAndAttributesBufferType = std::array<LUIDAndAttributes, securityBufferSize>;

        using SpecifiesAdditionalPrivilegeOptionsContainer = std::vector<SpecifiesAdditionalPrivilegeOptions>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateRestrictedTokenTest();

        void DoCreateRestrictedTokenTest(WindowsHandle tokenHandle);
        NODISCARD SecuritySidAndAttributesBufferType GetSidsToDisable(SecuritySIDBufferType& sid);
        void InitializeSecurityIdentifierTest(SecuritySIDBufferType& sid,
                                              int count,
                                              SecuritySidAndAttributes& securitySidAndAttributes);
        NODISCARD LUIDAndAttributesBufferType GetPrivilegesToDelete();
        void GetLookupPrivilegeValueTest(LUIDAndAttributes& lUIDAndAttributes);
        NODISCARD SecuritySidAndAttributesBufferType GetSidsToRestrict(SecuritySIDBufferType& sid);
        void RestrictedTest(WindowsHandle tokenHandle,
                            SecuritySidAndAttributesBufferType& sidsToDisable,
                            LUIDAndAttributesBufferType& privilegesToDelete,
                            SecuritySidAndAttributesBufferType& sidsToRestrict);
        void DoRestrictedTest(WindowsHandle tokenHandle,
                              SpecifiesAdditionalPrivilegeOptions specifiesAdditionalPrivilegeOptions,
                              SecuritySidAndAttributesBufferType& sidsToDisable,
                              LUIDAndAttributesBufferType& privilegesToDelete,
                              SecuritySidAndAttributesBufferType& sidsToRestrict);

    private:
        SpecifiesAdditionalPrivilegeOptionsContainer specifiesAdditionalPrivilegeOptionses;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_RESTRICTED_TOKEN_TESTING_H