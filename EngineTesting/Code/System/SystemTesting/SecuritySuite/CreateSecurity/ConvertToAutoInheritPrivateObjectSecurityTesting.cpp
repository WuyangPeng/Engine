///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:48)

#include "ConvertToAutoInheritPrivateObjectSecurityTesting.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ConvertToAutoInheritPrivateObjectSecurityTesting::ConvertToAutoInheritPrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ConvertToAutoInheritPrivateObjectSecurityTesting)

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertToAutoInheritPrivateObjectSecurityTest);
}

void System::ConvertToAutoInheritPrivateObjectSecurityTesting::ConvertToAutoInheritPrivateObjectSecurityTest()
{
    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    AccessCheckGenericMapping genericMapping{};
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

    SecurityDescriptorPtr descriptor0{ nullptr };
    ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, nullptr, &descriptor0, false, tokenHandle, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(descriptor0);

    SecurityDescriptorPtr newDescriptor{ nullptr };
    ASSERT_TRUE(SystemConvertToAutoInheritPrivateObjectSecurity(nullptr, descriptor0, &newDescriptor, nullptr, false, &genericMapping));
    ASSERT_UNEQUAL_NULL_PTR(newDescriptor);

    ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&descriptor0));
    ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&newDescriptor));
    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
