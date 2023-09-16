///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:45)

#ifndef SYSTEM_SECURITY_SUITE_ADD_MANDATORY_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_MANDATORY_ACE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityAclUsing.h"
#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>
#include <random>
#include <vector>

namespace System
{
    class AddMandatoryAceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddMandatoryAceTesting;
        using ParentType = UnitTest;

    public:
        explicit AddMandatoryAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void GetAccessControlEntriesTest();
        void DoGetAccessControlEntriesTest(size_t index, AccessCheckAclPtr acl, SecuritySid& sid);

    private:
        static constexpr auto aclSize = 512u;

        using ControlAceInheritanceContainer = std::vector<ControlAceInheritance>;
        using MandatoryPolicyContainer = std::vector<MandatoryPolicy>;
        using AclBuffer = std::array<char, aclSize>;

    private:
        NODISCARD SecuritySid GetSecuritySid();
        NODISCARD AclBuffer GetAcl();
        NODISCARD AccessCheckAclPtr GetAccessCheckAclPtr(AclBuffer& buffer) const noexcept;

    private:
        ControlAceInheritanceContainer controlAceInheritances;
        MandatoryPolicyContainer mandatoryPolicies;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_MANDATORY_ACE_TESTING_H