///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 23:35)

#include "PerformanceUnsharedExportMacroTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/AnimationPerformanceUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/PerformanceUnshared/ArtificialIntelligencePerformanceUnsharedMacro.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<ExportPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<CoreToolsPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Network::NetworkPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Database::DatabasePerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Script::ScriptPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Mathematics::MathematicsPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<SoundEffect::SoundEffectPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<InputOutput::InputOutputPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<ResourceManager::ResourceManagerPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Rendering::RenderingPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Physics::PhysicsPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Imagics::ImagicsPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Animation::AnimationPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<ArtificialIntelligence::ArtificialIntelligencePerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<UserInterface::UserInterfacePerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<AssistTools::AssistToolsPerformanceUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(PerformanceUnsharedExportTest<Framework::FrameworkPerformanceUnsharedMacro>);
}
