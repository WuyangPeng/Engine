/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:23)

#include "WindowsExtensionPrototypesTesting.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WindowsExtensionPrototypesTesting::WindowsExtensionPrototypesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsExtensionPrototypesTesting)

void System::WindowsExtensionPrototypesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockStartUpTest);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(WinSockCleanupTest);
}

void System::WindowsExtensionPrototypesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockLastErrorTest);
}

void System::WindowsExtensionPrototypesTesting::WinSockLastErrorTest()
{
    const auto errorSuccess = GetWinSockLastError();
    ASSERT_EQUAL(WinSockLastError::ErrorSuccess, errorSuccess);

    SetWinSockLastError(WinSockLastError::Cancelled);
    const auto lastError = GetWinSockLastError();
    ASSERT_EQUAL(WinSockLastError::Cancelled, lastError);
}
