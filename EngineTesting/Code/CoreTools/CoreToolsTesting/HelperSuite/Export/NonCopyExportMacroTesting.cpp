///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/11 23:17)

#include "NonCopyExportMacroTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/AnimationNonCopyMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/NonCopy/ArtificialIntelligenceNonCopyMacro.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<ExportNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<CoreToolsNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Network::NetworkNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Database::DatabaseNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Script::ScriptNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Mathematics::MathematicsNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<SoundEffect::SoundEffectNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<InputOutput::InputOutputNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<ResourceManager::ResourceManagerNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Rendering::RenderingNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Physics::PhysicsNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Imagics::ImagicsNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Animation::AnimationNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<ArtificialIntelligence::ArtificialIntelligenceNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<UserInterface::UserInterfaceNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<AssistTools::AssistToolsNonCopyMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(NonCopyExportTest<Framework::FrameworkNonCopyMacro>);
}
