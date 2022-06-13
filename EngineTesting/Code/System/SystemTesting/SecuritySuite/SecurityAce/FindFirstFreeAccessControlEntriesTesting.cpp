///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/13 10:27)

#include "FindFirstFreeAccessControlEntriesTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAce.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Security/Using/SecurityAceUsing.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::FindFirstFreeAccessControlEntriesTesting::FindFirstFreeAccessControlEntriesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FindFirstFreeAccessControlEntriesTesting)

void System::FindFirstFreeAccessControlEntriesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FindFirstFreeAccessControlEntriesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FindFirstFreeAccessControlEntriesTest);
}

void System::FindFirstFreeAccessControlEntriesTesting::FindFirstFreeAccessControlEntriesTest()
{
    WindowsDWord lengthNeeded{ 0 };
    ASSERT_FALSE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, nullptr, 0, &lengthNeeded));

    ASSERT_LESS(0u, lengthNeeded);
    vector<char> buffer(lengthNeeded);

    WindowsDWord newLengthNeeded{ 0 };
    ASSERT_TRUE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, buffer.data(), lengthNeeded, &newLengthNeeded));

    ASSERT_EQUAL(newLengthNeeded, lengthNeeded);

    WindowsBool daclPresent{ gFalse };
    AccessCheckACLPtr dacl{ nullptr };
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorDiscretionaryAccessControlList(buffer.data(), &daclPresent, &dacl, &daclDefaulted));

    SecurityAclSizeInformation aclSizeInformation{};
    ASSERT_TRUE(GetAccessControlListInformation(dacl, &aclSizeInformation));

    const auto newAclSize = aclSizeInformation.AclBytesInUse + sizeof(AccessAllowedAce) + GetLengthSid(buffer.data()) - sizeof(WindowsDWord);
    vector<char> aclbuffer(newAclSize);

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    auto acl = reinterpret_cast<AccessCheckACLPtr>(aclbuffer.data());

#include STSTEM_WARNING_POP

    ASSERT_TRUE(InitializeAccessControlList(acl, boost::numeric_cast<WindowsDWord>(newAclSize), AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    WindowsVoidPtr ace{ nullptr };
    ASSERT_TRUE(FindFirstFreeAccessControlEntries(acl, &ace));
}
