///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:26)

#include "ModuleExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/AnimationTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/ArtificialIntellegenceTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/AssistToolsTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/CoreToolsTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/DatabaseTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/FrameworkTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/ImagicsTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/InputOutputTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/MathematicsTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/NetworkTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/PhysicsTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/RenderingTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/ResourceManagerTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/ScriptTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/SoundEffectTestExportMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Module/UserInterfaceTestExportMacro.h"

CoreTools::ModuleExportMacroTesting::ModuleExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ModuleExportMacroTesting)

void CoreTools::ModuleExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ModuleExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkExportTest);
}

void CoreTools::ModuleExportMacroTesting::CoreToolsExportTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::NetworkExportTest()
{
    constexpr auto count = 10;
    Network::NetworkTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::DatabaseExportTest()
{
    constexpr auto count = 10;
    Database::DatabaseTestExportMacro lhsMacro{ count };

    ASSERT_EQUAL(lhsMacro.GetCount(), count);

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::ScriptExportTest()
{
    constexpr auto count = 10;
    Script::ScriptTestExportMacro lhsMacro{ count };

    ASSERT_EQUAL(lhsMacro.GetCount(), count);

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::MathematicsExportTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::SoundEffectExportTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::InputOutputExportTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::ResourceManagerExportTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::RenderingExportTest()
{
    constexpr auto count = 10;
    Rendering::RenderingTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::PhysicsExportTest()
{
    constexpr auto count = 10;
    Physics::PhysicsTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::ImagicsExportTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::AnimationExportTest()
{
    constexpr auto count = 10;
    Animation::AnimationTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::ArtificialIntellegenceExportTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::UserInterfaceExportTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::AssistToolsExportTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::FrameworkExportTest()
{
    constexpr auto count = 10;
    Framework::FrameworkTestExportMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}
