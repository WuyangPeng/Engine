///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 19:17)

#include "CreatePrivateObjectSecurityTesting.h"
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

System::CreatePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreatePrivateObjectSecurityTesting)

void System::CreatePrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreatePrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreatePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTest()
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

    SecurityDescriptorPtr newDescriptor{ nullptr };
    ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, nullptr, &newDescriptor, false, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(newDescriptor);

    if (tokenIsElevated != gFalse)
    {
        for (auto securityRequestedInformation : securityRequestedInformationFlags)
        {
            ASSERT_TRUE(SetSystemFileSecurity(setFileName.c_str(), securityRequestedInformation, newDescriptor));
        }
    }

    ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&newDescriptor));
    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
