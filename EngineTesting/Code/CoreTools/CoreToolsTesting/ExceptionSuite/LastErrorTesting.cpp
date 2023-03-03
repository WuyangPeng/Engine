///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/01 15:14)

#include "LastErrorTesting.h"
#include "System/Windows/Flags/PlatformErrorFlags.h"
#include "System/Windows/LastPlatformError.h"
#include "CoreTools/Exception/LastError.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LastErrorTesting::LastErrorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LastErrorTesting)

void CoreTools::LastErrorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LastErrorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LastErrorTest);
}

void CoreTools::LastErrorTesting::LastErrorTest()
{
    constexpr auto fileNotFound = System::WindowError::FileNotFound;

    SetPlatformLastError(fileNotFound);

    {
        const LastError lastError{};

        ASSERT_ENUM_EQUAL(lastError.GetLastError(), fileNotFound);
    }

    {
        const LastError lastError{};

        ASSERT_ENUM_EQUAL(lastError.GetLastError(), System::WindowError::Success);
    }
}
