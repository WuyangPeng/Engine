/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 18:27)

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
    ASSERT_NOT_THROW_EXCEPTION_0(CloseCoreToolsMaxTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MacroExistTest);

    ObjectManager::Destroy();
}

void CoreTools::UserMacroTesting::IsValidTest() noexcept(!gOpenClassInvariant)
{
#ifdef OPEN_CLASS_INVARIANT

    const auto nameMacro = NameMacro::Create("");
    ASSERT_TRUE(nameMacro->IsValid());

    const NameMacroBase nameMacroBase{};
    ASSERT_TRUE(nameMacroBase.IsValid());

    const NameMacroImpl nameMacroImpl{};
    ASSERT_TRUE(nameMacroImpl.IsValid());

    const NameFinalMacro nameFinalMacro{ "" };
    ASSERT_TRUE(nameFinalMacro.IsValid());

    const PureVirtualFinal pureVirtualFinal{};
    ASSERT_TRUE(pureVirtualFinal.IsValid());

#endif  // OPEN_CLASS_INVARIANT
}

void CoreTools::UserMacroTesting::CloseCoreToolsMaxTest()
{
    ASSERT_EQUAL(CLOSE_ASSERT | CLOSE_CLASS_INVARIANT | CLOSE_USE_IMPORTANT_EXCEPTION_ASSERT | CLOSE_USE_SAFETY_LIMIT | CLOSE_USE_OPEN_XLSX, CLOSE_CORE_TOOLS_MAX);
}

void CoreTools::UserMacroTesting::MacroExistTest() noexcept(!gOpenClassInvariant)
{
#ifdef OPEN_ASSERT

    SYSTEM_PLATFORM_WIN32;

#endif  // OPEN_ASSERT

#ifdef OPEN_CLASS_INVARIANT

    ASSERT_EQUAL(_DEBUG, 1);
    SYSTEM_PLATFORM_WIN32;

#endif  // OPEN_CLASS_INVARIANT

#ifdef OPEN_IMPORTANT_EXCEPTION_ASSERT

    SYSTEM_PLATFORM_WIN32;

#endif  // OPEN_IMPORTANT_EXCEPTION_ASSERT

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

    SYSTEM_PLATFORM_WIN32;
    TCRE_USE_MSVC;

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_OUTPUT_WINDOW

#ifdef CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

    SYSTEM_PLATFORM_WIN32;
    TCRE_USE_MSVC;

#endif  // CORE_TOOLS_USE_ASSERT_WRITE_TO_MESSAGE_BOX

#ifdef BUILDING_CORE_TOOLS_STATIC

    BUILDING_STATIC;

#endif  // BUILDING_CORE_TOOLS_STATIC

    BOOST_LIB_DIAGNOSTIC;
}
