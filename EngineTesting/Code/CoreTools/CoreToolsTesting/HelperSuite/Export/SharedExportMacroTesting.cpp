///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 18:24)

#include "SharedExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/AnimationMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ArtificialIntellegenceMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/AssistToolsMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/CoreToolsMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/DatabaseMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ExportMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/FrameworkMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ImagicsMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/InputOutputMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/MathematicsMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/NetworkMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/PhysicsMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/RenderingMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ResourceManagerMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ScriptMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/SoundEffectMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/UserInterfaceMacroShared.h"

CoreTools::SharedExportMacroTesting::SharedExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedExportMacroTesting)

void CoreTools::SharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsSharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkSharedTest);
}

void CoreTools::SharedExportMacroTesting::ExportSharedTest()
{
    constexpr auto count = 10;
    CoreTools::ExportMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::CoreToolsSharedTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::NetworkSharedTest()
{
    constexpr auto count = 10;
    Network::NetworkMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::DatabaseSharedTest()
{
    constexpr auto count = 10;
    Database::DatabaseMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::ScriptSharedTest()
{
    constexpr auto count = 10;
    Script::ScriptMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::MathematicsSharedTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::SoundEffectSharedTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::InputOutputSharedTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::ResourceManagerSharedTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::RenderingSharedTest()
{
    constexpr auto count = 10;
    Rendering::RenderingMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::PhysicsSharedTest()
{
    constexpr auto count = 10;
    Physics::PhysicsMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::ImagicsSharedTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::AnimationSharedTest()
{
    constexpr auto count = 10;
    Animation::AnimationMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::ArtificialIntellegenceSharedTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::UserInterfaceSharedTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::AssistToolsSharedTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}

void CoreTools::SharedExportMacroTesting::FrameworkSharedTest()
{
    constexpr auto count = 10;
    Framework::FrameworkMacroShared lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), 0);
}
