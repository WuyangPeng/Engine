///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 0:02)

#include "CopyModuleExportMacroTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/AnimationTestExportCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyModule/ArtificialIntelligenceTestExportCopyMacro.h"
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
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyModuleExportMacroTesting)

void CoreTools::CopyModuleExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyModuleExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<CoreToolsTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Network::NetworkTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Database::DatabaseTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Script::ScriptTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Mathematics::MathematicsTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<SoundEffect::SoundEffectTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<InputOutput::InputOutputTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<ResourceManager::ResourceManagerTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Rendering::RenderingTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Physics::PhysicsTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Imagics::ImagicsTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Animation::AnimationTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<ArtificialIntelligence::ArtificialIntelligenceTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<UserInterface::UserInterfaceTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<AssistTools::AssistToolsTestExportCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyModuleExportTest<Framework::FrameworkTestExportCopyMacro>);
}
