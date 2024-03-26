/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 14:21)

#include "FileSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Security/CreateSecurity.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FileSecurityTesting::FileSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      existingFileName{ SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt") },
      setFileName{ SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt") }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileSecurityTesting)

void System::FileSecurityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileSecurityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileSecurityTest);
}

void System::FileSecurityTesting::FileSecurityTest()
{
    for (auto securityRequestedInformation : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoFileSecurityTest, securityRequestedInformation);
    }
}

void System::FileSecurityTesting::DoFileSecurityTest(SecurityRequestedInformation securityRequestedInformation)
{
    WindowsDWord neededLength{ 0 };
    ASSERT_FALSE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, nullptr, 0, &neededLength));

    BufferType buffer(boost::numeric_cast<size_t>(neededLength + 1));

    WindowsDWord resultNeededLength{ 0 };
    ASSERT_TRUE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, buffer.data(), neededLength, &resultNeededLength));
    ASSERT_EQUAL(resultNeededLength, neededLength);

    ASSERT_NOT_THROW_EXCEPTION_2(SetSystemFileSecurityTest, securityRequestedInformation, buffer);
}

void System::FileSecurityTesting::SetSystemFileSecurityTest(SecurityRequestedInformation securityRequestedInformation, BufferType& buffer)
{
    if (GetTokenIsElevated())
    {
        ASSERT_TRUE(SetSystemFileSecurity(setFileName, securityRequestedInformation, buffer.data()));
    }
}
