///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:25)

#include "DelayCopyUnsharedExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/AnimationDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ArtificialIntellegenceDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/AssistToolsDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/CoreToolsDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/DatabaseDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ExportDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/FrameworkDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ImagicsDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/InputOutputDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/MathematicsDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/NetworkDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/PhysicsDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/RenderingDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ResourceManagerDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ScriptDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/SoundEffectDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/UserInterfaceDelayCopyUnsharedMacro.h"

CoreTools::DelayCopyUnsharedExportMacroTesting::DelayCopyUnsharedExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DelayCopyUnsharedExportMacroTesting)

void CoreTools::DelayCopyUnsharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsDelayCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkDelayCopyUnsharedTest);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::ExportDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::ExportDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::CoreToolsDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::NetworkDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Network::NetworkDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::DatabaseDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Database::DatabaseDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::ScriptDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Script::ScriptDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::MathematicsDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::SoundEffectDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::InputOutputDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::ResourceManagerDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::RenderingDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Rendering::RenderingDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::PhysicsDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Physics::PhysicsDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::ImagicsDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::AnimationDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Animation::AnimationDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::ArtificialIntellegenceDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::UserInterfaceDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::AssistToolsDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::FrameworkDelayCopyUnsharedTest()
{
    constexpr auto count = 10;
    Framework::FrameworkDelayCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}
