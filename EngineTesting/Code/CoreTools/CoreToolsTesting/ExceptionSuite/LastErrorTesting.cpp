/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:03)

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
    constexpr auto fileNotFound = WindowError::FileNotFound;

    ASSERT_NOT_THROW_EXCEPTION_1(DoLastError0, fileNotFound);

    ASSERT_NOT_THROW_EXCEPTION_0(DoLastError1);
}

void CoreTools::LastErrorTesting::DoLastError0(const WindowError fileNotFound)
{
    SetPlatformLastError(fileNotFound);

    const LastError lastError{};

    ASSERT_EQUAL(lastError.GetLastError(), fileNotFound);
}

void CoreTools::LastErrorTesting::DoLastError1()
{
    const LastError lastError{};

    ASSERT_EQUAL(lastError.GetLastError(), System::WindowError::Success);
}