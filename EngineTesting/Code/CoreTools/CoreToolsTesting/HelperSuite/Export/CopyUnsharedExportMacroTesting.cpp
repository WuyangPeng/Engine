///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:25)

#include "CopyUnsharedExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/AnimationCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ArtificialIntellegenceCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/AssistToolsCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/CoreToolsCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/DatabaseCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ExportCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/FrameworkCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ImagicsCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/InputOutputCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/MathematicsCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/NetworkCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/PhysicsCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/RenderingCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ResourceManagerCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ScriptCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/SoundEffectCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/UserInterfaceCopyUnsharedMacro.h"

CoreTools::CopyUnsharedExportMacroTesting::CopyUnsharedExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyUnsharedExportMacroTesting)

void CoreTools::CopyUnsharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyUnsharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsCopyUnsharedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkCopyUnsharedTest);
}

void CoreTools::CopyUnsharedExportMacroTesting::ExportCopyUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::ExportCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::CoreToolsCopyUnsharedTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::NetworkCopyUnsharedTest()
{
    constexpr auto count = 10;
    Network::NetworkCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::DatabaseCopyUnsharedTest()
{
    constexpr auto count = 10;
    Database::DatabaseCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::ScriptCopyUnsharedTest()
{
    constexpr auto count = 10;
    Script::ScriptCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::MathematicsCopyUnsharedTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::SoundEffectCopyUnsharedTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::InputOutputCopyUnsharedTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::ResourceManagerCopyUnsharedTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::RenderingCopyUnsharedTest()
{
    constexpr auto count = 10;
    Rendering::RenderingCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::PhysicsCopyUnsharedTest()
{
    constexpr auto count = 10;
    Physics::PhysicsCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::ImagicsCopyUnsharedTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::AnimationCopyUnsharedTest()
{
    constexpr auto count = 10;
    Animation::AnimationCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::ArtificialIntellegenceCopyUnsharedTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::UserInterfaceCopyUnsharedTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::AssistToolsCopyUnsharedTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}

void CoreTools::CopyUnsharedExportMacroTesting::FrameworkCopyUnsharedTest()
{
    constexpr auto count = 10;
    Framework::FrameworkCopyUnsharedMacro lhsMacro{ count };

    auto rhsMacro = lhsMacro;

    ASSERT_EQUAL(rhsMacro.GetCount(), count);

    lhsMacro.SetCount(0);

    ASSERT_EQUAL(lhsMacro.GetCount(), 0);
    ASSERT_EQUAL(rhsMacro.GetCount(), count);
}
