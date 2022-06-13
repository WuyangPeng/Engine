///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 13:39)

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

    System::SetPlatformLastError(fileNotFound);

    {
        LastError lastError{};

        ASSERT_ENUM_EQUAL(lastError.GetLastError(), fileNotFound);
    }

    {
        LastError lastError{};

        ASSERT_ENUM_EQUAL(lastError.GetLastError(), System::WindowError::Success);
    }
}
