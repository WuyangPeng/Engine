///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/07 22:25)

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
    ASSERT_ENUM_EQUAL(WinSockLastError::ErrorSuccess, errorSuccess);

    SetWinSockLastError(WinSockLastError::Cancelled);
    const auto lastError = GetWinSockLastError();
    ASSERT_ENUM_EQUAL(WinSockLastError::Cancelled, lastError);
}
