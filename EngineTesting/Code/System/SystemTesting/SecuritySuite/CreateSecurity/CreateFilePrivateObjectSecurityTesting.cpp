///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/29 21:37)

#include "CreateFilePrivateObjectSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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

using std::vector;
using namespace std::literals;

System::CreateFilePrivateObjectSecurityTesting::CreateFilePrivateObjectSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateFilePrivateObjectSecurityTesting)

void System::CreateFilePrivateObjectSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateFilePrivateObjectSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreatePrivateObjectSecurityTest);
}

void System::CreateFilePrivateObjectSecurityTesting::CreatePrivateObjectSecurityTest()
{
    const auto setFileName = SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt"s);
    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    const auto tokenIsElevated = IsSystemTokenElevated();

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSysemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    for (auto securityRequestedInformation : securityRequestedInformationFlags)
    {
        WindowsDWord neededLength{ 0 };
        ASSERT_FALSE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, nullptr, 0, &neededLength));

        vector<char> buffer(boost::numeric_cast<size_t>(neededLength + 1));

        WindowsDWord newNeededLength{ 0 };
        ASSERT_TRUE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, buffer.data(), neededLength, &newNeededLength));
        ASSERT_EQUAL(newNeededLength, neededLength);

        AccessCheckGenericMapping genericMapping{};
        genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
        genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
        genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
        genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

        SecurityDescriptorPtr newDescriptor{ nullptr };

        ASSERT_TRUE(CreateSystemPrivateObjectSecurity(nullptr, buffer.data(), &newDescriptor, false, tokenHandle, &genericMapping));
        ASSERT_UNEQUAL_NULL_PTR(newDescriptor);

        if (tokenIsElevated != g_False)
        {
            ASSERT_TRUE(SetSystemFileSecurity(setFileName.c_str(), securityRequestedInformation, newDescriptor));
        }

        ASSERT_TRUE(DestroySystemPrivateObjectSecurity(&newDescriptor));
    }

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}
