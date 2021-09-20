///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/14 18:15)

#include "NonCopyExportMacroTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/AnimationNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ArtificialIntellegenceNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/AssistToolsNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/CoreToolsNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/DatabaseNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ExportNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/FrameworkNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ImagicsNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/InputOutputNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/MathematicsNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/NetworkNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/PhysicsNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/RenderingNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ResourceManagerNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ScriptNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/SoundEffectNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/UserInterfaceNonCopyMacro.h"

CoreTools::NonCopyExportMacroTesting::NonCopyExportMacroTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NonCopyExportMacroTesting)

void CoreTools::NonCopyExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NonCopyExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ExportNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CoreToolsNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MathematicsNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SoundEffectNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InputOutputNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RenderingNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PhysicsNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ImagicsNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AnimationNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArtificialIntellegenceNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UserInterfaceNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AssistToolsNonCopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameworkNonCopyTest);
}

void CoreTools::NonCopyExportMacroTesting::ExportNonCopyTest()
{
    constexpr auto count = 10;
    CoreTools::ExportNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::CoreToolsNonCopyTest()
{
    constexpr auto count = 10;
    CoreTools::CoreToolsNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::NetworkNonCopyTest()
{
    constexpr auto count = 10;
    Network::NetworkNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::DatabaseNonCopyTest()
{
    constexpr auto count = 10;
    Database::DatabaseNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::ScriptNonCopyTest()
{
    constexpr auto count = 10;
    Script::ScriptNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::MathematicsNonCopyTest()
{
    constexpr auto count = 10;
    Mathematics::MathematicsNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::SoundEffectNonCopyTest()
{
    constexpr auto count = 10;
    SoundEffect::SoundEffectNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::InputOutputNonCopyTest()
{
    constexpr auto count = 10;
    InputOutput::InputOutputNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::ResourceManagerNonCopyTest()
{
    constexpr auto count = 10;
    ResourceManager::ResourceManagerNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::RenderingNonCopyTest()
{
    constexpr auto count = 10;
    Rendering::RenderingNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::PhysicsNonCopyTest()
{
    constexpr auto count = 10;
    Physics::PhysicsNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::ImagicsNonCopyTest()
{
    constexpr auto count = 10;
    Imagics::ImagicsNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::AnimationNonCopyTest()
{
    constexpr auto count = 10;
    Animation::AnimationNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::ArtificialIntellegenceNonCopyTest()
{
    constexpr auto count = 10;
    ArtificialIntellegence::ArtificialIntellegenceNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::UserInterfaceNonCopyTest()
{
    constexpr auto count = 10;
    UserInterface::UserInterfaceNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::AssistToolsNonCopyTest()
{
    constexpr auto count = 10;
    AssistTools::AssistToolsNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}

void CoreTools::NonCopyExportMacroTesting::FrameworkNonCopyTest()
{
    constexpr auto count = 10;
    Framework::FrameworkNonCopyMacro macro{ count };

    ASSERT_EQUAL(macro.GetCount(), count);
}
