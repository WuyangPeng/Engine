///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/29 21:37)

#include "CreatePrivateObjectSecurityUseAutoInheritTesting.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "System/Security/Using/CreateSecurityUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreatePrivateObjectSecurityUseAutoInheritTesting::CreatePrivateObjectSecurityUseAutoInheritTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityAutoInheritFlags{ SecurityAutoInherit::DaclAutoInherit,
                                SecurityAutoInherit::SaclAutoInherit,
                                SecurityAutoInherit::DefaultDescriptorForObject,
                                SecurityAutoInherit::AvoidPrivilegeCheck,
                                SecurityAutoInherit::AvoidOwnerCheck,
                                SecurityAutoInherit::MaclNoWriteUp,
                                SecurityAutoInherit::MaclNoReadUp,
                                SecurityAutoInherit::MaclNoExecuteUp,
                                SecurityAutoInherit::AvoidOwnerRestriction,
                                SecurityAutoInherit::MaclValidFlags }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreatePrivateObjectSecurityUseAutoInheritTesting)

void System::CreatePrivateObjectSecurityUseAutoInheritTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreatePrivateObjectSecurityUseAutoInheritTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreatePrivateObjectSecurityUseAutoInheritTesting::CreatePrivateObjectSecurityTest()
{
    const auto setFileName = SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt"s);

    const auto tokenIsElevated = IsSystemTokenElevated();

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    AccessCheckGenericMapping genericMapping{};
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

    for (auto securityAutoInherit : securityAutoInheritFlags)
    {
        SecurityDescriptorPtr newDescriptor{ nullptr };
        ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, nullptr, &newDescriptor, nullptr, false, securityAutoInherit, tokenHandle, &genericMapping));
        ASSERT_UNEQUAL_NULL_PTR(newDescriptor);

        if (tokenIsElevated != g_False)
        {
            ASSERT_TRUE(SetSystemFileSecurity(setFileName.c_str(), SecurityRequestedInformation::Owner, newDescriptor));
        }

        ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&newDescriptor));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
