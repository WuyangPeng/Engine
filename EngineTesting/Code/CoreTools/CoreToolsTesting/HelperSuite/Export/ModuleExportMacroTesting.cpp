///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 22:50)

#include "ModuleExportMacroTestingDetail.h"
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
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ModuleExportMacroTesting)

void CoreTools::ModuleExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ModuleExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<CoreToolsTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Network::NetworkTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DatabaseExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ScriptExportTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Mathematics::MathematicsTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<SoundEffect::SoundEffectTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<InputOutput::InputOutputTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<ResourceManager::ResourceManagerTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Rendering::RenderingTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Physics::PhysicsTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Imagics::ImagicsTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Animation::AnimationTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<ArtificialIntellegence::ArtificialIntellegenceTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<UserInterface::UserInterfaceTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<AssistTools::AssistToolsTestExportMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(ModuleExportTest<Framework::FrameworkTestExportMacro>);
}

void CoreTools::ModuleExportMacroTesting::DatabaseExportTest()
{
    constexpr auto count = 10;
    Database::DatabaseTestExportMacro original{ count };

    ASSERT_EQUAL(original.GetCount(), count);

    const auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
}

void CoreTools::ModuleExportMacroTesting::ScriptExportTest()
{
    constexpr auto count = 10;
    Script::ScriptTestExportMacro original{ count };

    ASSERT_EQUAL(original.GetCount(), count);

    const auto copy = original;

    ASSERT_EQUAL(copy.GetCount(), count);
}
