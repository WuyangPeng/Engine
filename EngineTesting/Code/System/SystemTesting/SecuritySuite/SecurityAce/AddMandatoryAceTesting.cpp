///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/13 10:22)

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
using std::max;
using std::vector;

System::AddMandatoryAceTesting::AddMandatoryAceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      controlACEInheritanceFlags{ ControlACEInheritance::ObjectInheritAce,
                                  ControlACEInheritance::ContainerInheritAce,
                                  ControlACEInheritance::NoPropagateInheritAce,
                                  ControlACEInheritance::InheritOnlyAce,
                                  ControlACEInheritance::InheritedAce,
                                  ControlACEInheritance::ValidInheritFlags },
      mandatoryPolicyFlags{ MandatoryPolicy::LabelNoWriteUp,
                            MandatoryPolicy::LabelNoReadUp,
                            MandatoryPolicy::LabelNoExecuteUp },
      randomEngine{ GetEngineRandomSeed() },
      maxSize{ max(controlACEInheritanceFlags.size(), mandatoryPolicyFlags.size()) }
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
    shuffle(controlACEInheritanceFlags.begin(), controlACEInheritanceFlags.end(), randomEngine);
    shuffle(mandatoryPolicyFlags.begin(), mandatoryPolicyFlags.end(), randomEngine);

    ASSERT_NOT_THROW_EXCEPTION_0(GetAccessControlEntriesTest);

    return true;
}

void System::AddMandatoryAceTesting::GetAccessControlEntriesTest()
{
    constexpr WindowsDWord newAclSize{ 512 };

    array<char, newAclSize> aclbuffer{};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto acl = reinterpret_cast<AccessCheckACLPtr>(aclbuffer.data());

#include STSTEM_WARNING_POP

    ASSERT_TRUE(InitializeAccessControlList(acl, newAclSize, AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    SecuritySID sid{};

    SecuritySIDIndentifierAuthority identifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY;

    constexpr WindowsByte subAuthorityCount{ 1 };

    ASSERT_TRUE(InitializeSecurityIdentifier(&sid, &identifierAuthority, subAuthorityCount));
    ASSERT_TRUE(IsSecurityIdentifierValid(&sid));

    for (auto index = 0u; index < maxSize; ++index)
    {
        auto controlACEInheritance = controlACEInheritanceFlags.at(index % controlACEInheritanceFlags.size());
        auto mandatoryPolicy = mandatoryPolicyFlags.at(index % mandatoryPolicyFlags.size());

        ASSERT_TRUE(AddMandatoryAccessControlEntries(acl, AccessControlListRevision::Revision, controlACEInheritance, mandatoryPolicy, &sid));
    }
}