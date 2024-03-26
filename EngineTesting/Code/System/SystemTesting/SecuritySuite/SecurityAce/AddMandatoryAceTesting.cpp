/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:23)

#include "AddMandatoryAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/SecurityAceFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAce.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecuritySid.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

System::AddMandatoryAceTesting::AddMandatoryAceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      controlAceInheritances{ ControlAceInheritance::ObjectInheritAce,
                              ControlAceInheritance::ContainerInheritAce,
                              ControlAceInheritance::NoPropagateInheritAce,
                              ControlAceInheritance::InheritOnlyAce,
                              ControlAceInheritance::InheritedAce,
                              ControlAceInheritance::ValidInheritFlags },
      mandatoryPolicies{ MandatoryPolicy::LabelNoWriteUp,
                         MandatoryPolicy::LabelNoReadUp,
                         MandatoryPolicy::LabelNoExecuteUp },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(controlAceInheritances.size(), mandatoryPolicies.size()) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AddMandatoryAceTesting)

void System::AddMandatoryAceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AddMandatoryAceTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RandomShuffleFlags);
}

bool System::AddMandatoryAceTesting::RandomShuffleFlags()
{
    std::ranges::shuffle(controlAceInheritances, randomEngine);
    std::ranges::shuffle(mandatoryPolicies, randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(GetAccessControlEntriesTest);

    return true;
}

void System::AddMandatoryAceTesting::GetAccessControlEntriesTest()
{
    auto aclBuffer = GetAcl();

    auto acl = GetAccessCheckAclPtr(aclBuffer);

    auto sid = GetSecuritySid();

    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoGetAccessControlEntriesTest, index, acl, sid);
    }
}

System::AddMandatoryAceTesting::AclBuffer System::AddMandatoryAceTesting::GetAcl()
{
    AclBuffer aclBuffer{};

    const auto acl = GetAccessCheckAclPtr(aclBuffer);

    ASSERT_TRUE(InitializeAccessControlList(acl, aclSize, AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    return aclBuffer;
}

System::SecuritySid System::AddMandatoryAceTesting::GetSecuritySid()
{
    SecuritySid sid{};

    SecuritySidIdentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 1 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}

System::AccessCheckAclPtr System::AddMandatoryAceTesting::GetAccessCheckAclPtr(AclBuffer& buffer) const noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<AccessCheckAclPtr>(buffer.data());

#include SYSTEM_WARNING_POP
}

void System::AddMandatoryAceTesting::DoGetAccessControlEntriesTest(size_t index, AccessCheckAclPtr acl, SecuritySid& sid)
{
    const auto controlAceInheritance = controlAceInheritances.at(index % controlAceInheritances.size());
    const auto mandatoryPolicy = mandatoryPolicies.at(index % mandatoryPolicies.size());

    ASSERT_TRUE(AddMandatoryAccessControlEntries(acl, AccessControlListRevision::Revision, controlAceInheritance, mandatoryPolicy, &sid));
}
