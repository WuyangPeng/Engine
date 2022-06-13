///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 19:17)

#include "FileSecurityTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Security/CreateSecurity.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
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

System::FileSecurityTesting::FileSecurityTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Label }
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
    const auto tokenIsElevated = IsSystemTokenElevated();

    const auto existingFileName = SYSTEM_TEXT("Resource/FileTesting/CreateExistingFile.txt"s);
    const auto setFileName = SYSTEM_TEXT("Resource/AttributesTesting/AttributesTestFile.txt"s);

    for (auto securityRequestedInformation : securityRequestedInformationFlags)
    {
        WindowsDWord neededLength{ 0 };
        ASSERT_FALSE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, nullptr, 0, &neededLength));

        vector<char> buffer(boost::numeric_cast<size_t>(neededLength + 1));

        WindowsDWord newNeededLength{ 0 };
        ASSERT_TRUE(GetSystemFileSecurity(existingFileName, securityRequestedInformation, buffer.data(), neededLength, &newNeededLength));
        ASSERT_EQUAL(newNeededLength, neededLength);

        if (tokenIsElevated)
        {
            ASSERT_TRUE(SetSystemFileSecurity(setFileName.c_str(), securityRequestedInformation, buffer.data()));
        }
    }
}
