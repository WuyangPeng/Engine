/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:21)

#include "CreateSecurityTestingBase.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateSecurityTestingBase::CreateSecurityTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationContainer{ SecurityRequestedInformation::Owner,
                                             SecurityRequestedInformation::Group,
                                             SecurityRequestedInformation::Dacl,
                                             SecurityRequestedInformation::Label },
      securityAutoInherits{ SecurityAutoInherit::DaclAutoInherit,
                            SecurityAutoInherit::SaclAutoInherit,
                            SecurityAutoInherit::DefaultDescriptorForObject,
                            SecurityAutoInherit::AvoidPrivilegeCheck,
                            SecurityAutoInherit::AvoidOwnerCheck,
                            SecurityAutoInherit::MaclNoWriteUp,
                            SecurityAutoInherit::MaclNoReadUp,
                            SecurityAutoInherit::MaclNoExecuteUp,
                            SecurityAutoInherit::AvoidOwnerRestriction,
                            SecurityAutoInherit::MaclValidFlags },
      tokenIsElevated{ IsSystemTokenElevated() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateSecurityTestingBase)

System::CreateSecurityTestingBase::SecurityRequestedInformationContainerConstIter System::CreateSecurityTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securityRequestedInformationContainer.cbegin();
}

System::CreateSecurityTestingBase::SecurityRequestedInformationContainerConstIter System::CreateSecurityTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securityRequestedInformationContainer.cend();
}

System::CreateSecurityTestingBase::SecurityAutoInheritContainerConstIter System::CreateSecurityTestingBase::GetSecurityAutoInheritBegin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securityAutoInherits.cbegin();
}

System::CreateSecurityTestingBase::SecurityAutoInheritContainerConstIter System::CreateSecurityTestingBase::GetSecurityAutoInheritEnd() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securityAutoInherits.cend();
}

bool System::CreateSecurityTestingBase::GetTokenIsElevated() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return tokenIsElevated;
}

System::WindowsHandle System::CreateSecurityTestingBase::OpenProcessToken()
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSystemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(tokenHandle, "Token句柄获取失败。");

    return tokenHandle;
}

void System::CreateSecurityTestingBase::CloseProcessTokenTest(WindowsHandle tokenHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}

void System::CreateSecurityTestingBase::CreatePrivateObjectSecurity(WindowsHandle tokenHandle, SecurityDescriptorPtr& descriptor)
{
    SYSTEM_CLASS_IS_VALID_1;

    auto genericMapping = GetAccessCheckGenericMapping();

    ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, nullptr, &descriptor, false, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(descriptor);
}

void System::CreateSecurityTestingBase::DestroyPrivateObjectSecurityTest(SecurityDescriptorPtr descriptor)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&descriptor));
}

 