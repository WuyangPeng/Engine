///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 18:21)

#include "PerformanceUnsharedExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/AnimationPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ArtificialIntellegencePerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/AssistToolsPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/CoreToolsPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/DatabasePerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ExportPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/FrameworkPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ImagicsPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/InputOutputPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/MathematicsPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/NetworkPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/PhysicsPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/RenderingPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ResourceManagerPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ScriptPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/SoundEffectPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/UserInterfacePerformanceUnsharedMacro.h"

CoreTools::PerformanceUnsharedExportMacroTesting::PerformanceUnsharedExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PerformanceUnsharedExportMacroTesting)

void CoreTools::PerformanceUnsharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabasePerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegencePerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfacePerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsPerformanceUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkPerformanceUnsharedTest);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::ExportPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::ExportPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::CoreToolsPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::NetworkPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Network::NetworkPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::DatabasePerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Database::DatabasePerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::ScriptPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Script::ScriptPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::MathematicsPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::SoundEffectPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::InputOutputPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::ResourceManagerPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::RenderingPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Rendering::RenderingPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::PhysicsPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Physics::PhysicsPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::ImagicsPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::AnimationPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Animation::AnimationPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::ArtificialIntellegencePerformanceUnsharedTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegencePerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::UserInterfacePerformanceUnsharedTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfacePerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::AssistToolsPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::PerformanceUnsharedExportMacroTesting::FrameworkPerformanceUnsharedTest()
{
    constexpr auto count = 10;
    Framework::FrameworkPerformanceUnsharedMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}
