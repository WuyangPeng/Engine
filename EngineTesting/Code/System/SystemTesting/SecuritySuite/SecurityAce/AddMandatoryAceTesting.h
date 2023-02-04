///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 16:03)

#ifndef SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void GetAccessControlEntriesTest();
        void DoGetAccessControlEntriesTest(size_t index, AccessCheckACLPtr acl, SecuritySID& sid);

    private:
        static constexpr auto aclSize = 512u;

        using ControlACEInheritanceContainer = std::vector<ControlACEInheritance>;
        using MandatoryPolicyContainer = std::vector<MandatoryPolicy>;
        using ACLBuffer = std::array<char, aclSize>;

    private:
        NODISCARD SecuritySID GetSecuritySID();
        NODISCARD ACLBuffer GetACL();
        NODISCARD AccessCheckACLPtr GetAccessCheckACLPtr(ACLBuffer& buffer) const noexcept;

    private:
        ControlACEInheritanceContainer controlACEInheritances;
        MandatoryPolicyContainer mandatoryPolicies;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H