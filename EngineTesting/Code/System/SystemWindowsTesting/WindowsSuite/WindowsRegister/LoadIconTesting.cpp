///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 10:56)

#include "LoadIconTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemWindowsTesting/resource.h"
#include "System/Windows/Using/WindowsRegistryUsing.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadIconTesting::LoadIconTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream }, instance{ instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadIconTesting)

void System::LoadIconTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadIconTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadIconTest);
}

void System::LoadIconTesting::LoadIconTest()
{
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Application));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_IDIHand));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Question));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Exclamation));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Asterisk));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_WinLogo));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Shield));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Warning));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Error));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, g_Information));

    ASSERT_UNEQUAL_NULL_PTR(System::LoadSystemIcon(instance, MakeIntreSource(IDI_TEST_ICON)));
}
