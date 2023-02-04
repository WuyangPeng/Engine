///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 14:41)

#include "SecurityAceTestingBase.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/Flags/SecurityAclFlags.h"
#include "System/Security/SecurityAcl.h"
#include "System/Security/SecurityDescriptor.h"
#include "System/Security/SecuritySid.h"
#include "System/Security/Using/SecurityAceUsing.h"
#include "System/Threading/Thread.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecurityAceTestingBase::SecurityAceTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecurityAceTestingBase)

System::SecurityAceTestingBase::UserObjectSecurityBuffer System::SecurityAceTestingBase::GetUserObjectSecurity()
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsDWord lengthNeeded{ 0 };
    ASSERT_FALSE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, nullptr, 0, &lengthNeeded));

    ASSERT_LESS(0u, lengthNeeded);
    UserObjectSecurityBuffer buffer(lengthNeeded);

    WindowsDWord newLengthNeeded{ 0 };
    ASSERT_TRUE(GetUserObjectSystemSecurity(GetCurrentSystemThread(), SecurityRequestedInformation::Dacl, buffer.data(), lengthNeeded, &newLengthNeeded));

    ASSERT_EQUAL(newLengthNeeded, lengthNeeded);

    return buffer;
}

System::AccessCheckACLPtr System::SecurityAceTestingBase::GetDacl(UserObjectSecurityBuffer& buffer)
{
    SYSTEM_CLASS_IS_VALID_1;

    auto daclPresent = false;
    AccessCheckACLPtr dacl{ nullptr };
    auto daclDefaulted = false;
    ASSERT_TRUE(GetSecurityDescriptorDiscretionaryAccessControlList(buffer.data(), &daclPresent, &dacl, &daclDefaulted));

    return dacl;
}

System::SecurityAceTestingBase::ACLBuffer System::SecurityAceTestingBase::GetACL(UserObjectSecurityBuffer& buffer, WindowsDWord aclBytesInUse)
{
    SYSTEM_CLASS_IS_VALID_1;

    const auto aclSize = aclBytesInUse + sizeof(AccessAllowedAce) + GetLengthSecurityIdentifier(buffer.data()) - sizeof(WindowsDWord);
    ACLBuffer aclbuffer(aclSize);

    auto acl = GetAccessCheckACLPtr(aclbuffer);

    ASSERT_TRUE(InitializeAccessControlList(acl, boost::numeric_cast<WindowsDWord>(aclSize), AccessControlListRevision::Revision));
    ASSERT_TRUE(IsAccessControlListValid(acl));

    return aclbuffer;
}

System::AccessCheckACLPtr System::SecurityAceTestingBase::GetAccessCheckACLPtr(ACLBuffer& buffer) const noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<AccessCheckACLPtr>(buffer.data());

#include STSTEM_WARNING_POP
}
