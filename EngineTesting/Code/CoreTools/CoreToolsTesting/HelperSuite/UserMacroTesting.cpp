///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:39)

#include "UserMacroTesting.h"
#include "Detail/NameFinalMacro.h"
#include "Detail/NameMacro.h"
#include "Detail/NameMacroBase.h"
#include "Detail/NameMacroImpl.h"
#include "Detail/PureVirtualFinal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UserMacroTesting::UserMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UserMacroTesting)

void CoreTools::UserMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UserMacroTesting::MainTest()
{
    ObjectManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(IsValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CloseSystemMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);

    ObjectManager::Destroy();
}

void CoreTools::UserMacroTesting::IsValidTest() noexcept(!g_OpenClassInvariant)
{
#ifdef OPEN_CLASS_INVARIANT

    auto nameMacro = NameMacro::Create("");
    ASSERT_TRUE(nameMacro->IsValid());

    NameMacroBase nameMacroBase{};
    ASSERT_TRUE(nameMacroBase.IsValid());

    const NameMacroImpl nameMacroImpl{ 0 };
    ASSERT_TRUE(nameMacroImpl.IsValid());

    NameFinalMacro nameFinalMacro{ "" };
    ASSERT_TRUE(nameFinalMacro.IsValid());

    PureVirtualFinal pureVirtualFinal{};
    ASSERT_TRUE(pureVirtualFinal.IsValid());

#endif  // OPEN_CLASS_INVARIANT
}

void CoreTools::UserMacroTesting::CloseSystemMaxTest()
{
    ASSERT_EQUAL(CLOSE_ASSERT | CLOSE_CLASS_INVARIANT | CLOSE_USE_IMPORTANT_EXCPTION_ASSERT | CLOSE_USE_SAFETY_LIMIT | CLOSE_USE_OPENXLSX, CLOSE_CORE_TOOLS_MAX);
}

void CoreTools::UserMacroTesting::MacroExistTest() noexcept(!g_OpenClassInvariant)
{
#ifdef OPEN_USE_MEMORY

    ASSERT_EQUAL(_DEBUG, 1);

#endif  // OPEN_USE_MEMORY

#ifdef OPEN_ASSERT

    SYSTEM_PLATFORM_WIN32;

#endif  // OPEN_ASSERT

#ifdef OPEN_CLASS_INVARIANT

    ASSERT_EQUAL(_DEBUG, 1);
    SYSTEM_PLATFORM_WIN32;

#endif  // OPEN_CLASS_INVARIANT

#ifdef CORE_TOOLS_MEMORY_ALWAYS_CREATE

    ASSERT_EQUAL(_DEBUG, 1);

#endif  // CORE_TOOLS_MEMORY_ALWAYS_CREATE

#ifdef BUILDING_CORE_TOOLS_STATIC

    BUILDING_STATIC;

#endif  // BUILDING_CORE_TOOLS_STATIC
}
