/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:35)

#include "AccessCheckTestingBase.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "System/Threading/Flags/ThreadToolsFlags.h"
#include "System/Threading/Process.h"
#include "System/Threading/ProcessTools.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::AccessCheckTestingBase::AccessCheckTestingBase(const OStreamShared& stream)
    : ParentType{ stream },
      fileHandleDesiredAccesses{ FileHandleDesiredAccess::Read,
                                 FileHandleDesiredAccess::Write,
                                 FileHandleDesiredAccess::Execute,
                                 FileHandleDesiredAccess::ReadWrite }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessCheckTestingBase)

System::AccessCheckTestingBase::FileHandleDesiredAccessContainerConstIter System::AccessCheckTestingBase::begin() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return fileHandleDesiredAccesses.cbegin();
}

System::AccessCheckTestingBase::FileHandleDesiredAccessContainerConstIter System::AccessCheckTestingBase::end() const noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return fileHandleDesiredAccesses.cend();
}

System::CharBufferType System::AccessCheckTestingBase::GetFileSecurityBuffer()
{
    SYSTEM_CLASS_IS_VALID_1;

    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);

    constexpr auto requestedInformation = (SecurityRequestedInformation::Owner) | (SecurityRequestedInformation::Group) | (SecurityRequestedInformation::Dacl);

    WindowsDWord neededLength{ 0 };
    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, requestedInformation, nullptr, 0, &neededLength));

    ASSERT_LESS_FAILURE_THROW(boost::numeric_cast<int>(neededLength), defaultBufferSize, "需增加array大小通过测试。");

    CharBufferType buffer{};
    WindowsDWord resultNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, requestedInformation, buffer.data(), neededLength, &resultNeededLength));
    ASSERT_EQUAL(resultNeededLength, neededLength);

    return buffer;
}

void System::AccessCheckTestingBase::CloseTokenTest(WindowsHandle tokenHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    ASSERT_TRUE(CloseTokenHandle(tokenHandle));
}

System::WindowsHandle System::AccessCheckTestingBase::OpenProcessToken()
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsHandle tokenHandle{ nullptr };
    ASSERT_TRUE(OpenSystemProcessToken(GetCurrentProcessHandle(), TokenStandardAccess::Default, TokenSpecificAccess::AllAccess, &tokenHandle));

    return tokenHandle;
}

System::WindowsHandle System::AccessCheckTestingBase::DuplicateToken(WindowsHandle tokenHandle)
{
    SYSTEM_CLASS_IS_VALID_1;

    WindowsHandle impersonatedToken{ nullptr };
    ASSERT_TRUE(DuplicateSystemToken(tokenHandle, SecurityImpersonation, &impersonatedToken));

    return impersonatedToken;
}
