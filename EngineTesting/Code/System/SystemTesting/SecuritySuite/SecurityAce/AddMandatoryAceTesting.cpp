///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/28 16:00)

#include "AddMandatoryAceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/SecuritySidMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/SecurityAceFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAce.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Security/SecuritySid.h"
#include "System/Security/Using/SecurityAceUsing.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

using std::vector;

System::AddMandatoryAceTesting::AddMandatoryAceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      controlACEInheritances{ ControlACEInheritance::ObjectInheritAce,
                              ControlACEInheritance::ContainerInheritAce,
                              ControlACEInheritance::NoPropagateInheritAce,
                              ControlACEInheritance::InheritOnlyAce,
                              ControlACEInheritance::InheritedAce,
                              ControlACEInheritance::ValidInheritFlags },
      mandatoryPolicies{ MandatoryPolicy::LabelNoWriteUp,
                         MandatoryPolicy::LabelNoReadUp,
                         MandatoryPolicy::LabelNoExecuteUp },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ std::max(controlACEInheritances.size(), mandatoryPolicies.size()) }
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
    shuffle(controlACEInheritances.begin(), controlACEInheritances.end(), randomEngine);
    shuffle(mandatoryPolicies.begin(), mandatoryPolicies.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(GetAccessControlEntriesTest);

    return true;
}

void System::AddMandatoryAceTesting::GetAccessControlEntriesTest()
{
    auto aclbuffer = GetACL();

    auto acl = GetAccessCheckACLPtr(aclbuffer);

    auto sid = GetSecuritySID();

    for (auto index = 0u; index < maxSize; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(DoGetAccessControlEntriesTest, index, acl, sid);
    }
}

System::AddMandatoryAceTesting::ACLBuffer System::AddMandatoryAceTesting::GetACL()
{
    ACLBuffer aclbuffer{};

    auto acl = GetAccessCheckACLPtr(aclbuffer);

    ASSERT_TRUE(InitializeAccessControlList(acl, aclSize, AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    return aclbuffer;
}

System::SecuritySID System::AddMandatoryAceTesting::GetSecuritySID()
{
    SecuritySID sid{};

    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 1 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    return sid;
}

System::AccessCheckACLPtr System::AddMandatoryAceTesting::GetAccessCheckACLPtr(ACLBuffer& buffer) const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<AccessCheckACLPtr>(buffer.data());

#include STSTEM_WARNING_POP
}

void System::AddMandatoryAceTesting::DoGetAccessControlEntriesTest(size_t index, AccessCheckACLPtr acl, SecuritySID& sid)
{
    auto controlACEInheritance = controlACEInheritances.at(index % controlACEInheritances.size());
    auto mandatoryPolicy = mandatoryPolicies.at(index % mandatoryPolicies.size());

    ASSERT_TRUE(AddMandatoryAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, mandatoryPolicy, &sid));
}
