///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 21:05)

#include "DelayCopyUnsharedExportMacroTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/AnimationDelayCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/DelayCopyUnshared/ArtificialIntelligenceDelayCopyUnsharedMacro.h"
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
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DelayCopyUnsharedExportMacroTesting)

void CoreTools::DelayCopyUnsharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DelayCopyUnsharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<ExportDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<CoreToolsDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Network::NetworkDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Database::DatabaseDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Script::ScriptDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Mathematics::MathematicsDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<SoundEffect::SoundEffectDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<InputOutput::InputOutputDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<ResourceManager::ResourceManagerDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Rendering::RenderingDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Physics::PhysicsDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Imagics::ImagicsDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Animation::AnimationDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<ArtificialIntelligence::ArtificialIntelligenceDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<UserInterface::UserInterfaceDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<AssistTools::AssistToolsDelayCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(DelayCopyUnsharedExportTest<Framework::FrameworkDelayCopyUnsharedMacro>);
}
