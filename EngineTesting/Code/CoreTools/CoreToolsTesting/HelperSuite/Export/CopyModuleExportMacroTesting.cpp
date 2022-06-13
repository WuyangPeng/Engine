///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:25)

#include "CopyModuleExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/AnimationTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/ArtificialIntellegenceTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/AssistToolsTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/CoreToolsTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/DatabaseTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/FrameworkTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/ImagicsTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/InputOutputTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/MathematicsTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/NetworkTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/PhysicsTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/RenderingTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/ResourceManagerTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/ScriptTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/SoundEffectTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/UserInterfaceTestExportCopyMacro.h"

CoreTools::CopyModuleExportMacroTesting::CopyModuleExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyModuleExportMacroTesting)

void CoreTools::CopyModuleExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyModuleExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsCopyExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkCopyExportTest);
}

void CoreTools::CopyModuleExportMacroTesting::CoreToolsCopyExportTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::NetworkCopyExportTest()
{
    constexpr auto count = 10;
    Network::NetworkTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::DatabaseCopyExportTest()
{
    constexpr auto count = 10;
    Database::DatabaseTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::ScriptCopyExportTest()
{
    constexpr auto count = 10;
    Script::ScriptTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::MathematicsCopyExportTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::SoundEffectCopyExportTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::InputOutputCopyExportTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::ResourceManagerCopyExportTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::RenderingCopyExportTest()
{
    constexpr auto count = 10;
    Rendering::RenderingTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::PhysicsCopyExportTest()
{
    constexpr auto count = 10;
    Physics::PhysicsTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::ImagicsCopyExportTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::AnimationCopyExportTest()
{
    constexpr auto count = 10;
    Animation::AnimationTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::ArtificialIntellegenceCopyExportTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::UserInterfaceCopyExportTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::AssistToolsCopyExportTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyModuleExportMacroTesting::FrameworkCopyExportTest()
{
    constexpr auto count = 10;
    Framework::FrameworkTestExportCopyMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}
