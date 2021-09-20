///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/07 14:51)

#include "WindowsExtensionPrototypesTesting.h"
#include "System/Helper/WindowsMacro.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsExtensionPrototypesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WinSockLastErrorTest);
}

void System::WindowsExtensionPrototypesTesting::WinSockLastErrorTest()
{
    WinSockData wsaData{};

    constexpr auto versionRequested = MakeWord(2, 2);
    const auto startUp = WinSockStartUp(versionRequested, &wsaData);

    ASSERT_ENUM_EQUAL(startUp, WinSockStartUpReturn::Successful);

    auto lastError = GetWinSockLastError();
    ASSERT_ENUM_EQUAL(WinSockLastError::ErrorSuccess, lastError);

    SetWinSockLastError(WinSockLastError::Cancelled);
    lastError = GetWinSockLastError();
    ASSERT_ENUM_EQUAL(WinSockLastError::Cancelled, lastError);

    const auto cleanup = WinSockCleanup();
    ASSERT_ENUM_EQUAL(cleanup, WinSockCleanupReturn::Successful);
}
