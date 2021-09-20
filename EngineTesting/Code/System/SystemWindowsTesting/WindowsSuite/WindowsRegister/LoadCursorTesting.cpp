///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/07 10:56)

#include "LoadCursorTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemWindowsTesting/resource.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadCursorTesting::LoadCursorTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadCursorTesting)

void System::LoadCursorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadCursorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadCursorTest);
}

void System::LoadCursorTesting::LoadCursorTest()
{
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_Arrow));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_Ibeam));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_Wait));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_Cross));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_UpArrow));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_SizeNwse));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_SizeNesw));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_SizeWe));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_SizeNs));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_SizeAll));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_No));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_IDCHand));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_AppStarting));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemCursor(nullptr, g_Help));

    ASSERT_UNEQUAL_NULL_PTR(System::LoadSystemCursor(instance, MakeIntreSource(IDC_TEST_CURSOR)));
}
