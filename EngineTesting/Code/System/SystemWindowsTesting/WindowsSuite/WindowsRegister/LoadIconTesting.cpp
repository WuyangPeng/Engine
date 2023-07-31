///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 21:12)

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
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gApplication));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gIdiHand));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gQuestion));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gExclamation));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gAsterisk));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gWinLogo));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gShield));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gWarning));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gError));
    ASSERT_UNEQUAL_NULL_PTR(LoadSystemIcon(nullptr, gInformation));

    ASSERT_UNEQUAL_NULL_PTR(System::LoadSystemIcon(instance, MakeIntreSource(IDI_TEST_ICON)));
}
