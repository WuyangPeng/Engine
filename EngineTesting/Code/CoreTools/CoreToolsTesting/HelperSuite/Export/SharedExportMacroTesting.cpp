/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 10:43)

#include "SharedExportMacroTestingDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/AnimationMacroShared.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Shared/ArtificialIntelligenceMacroShared.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<ExportMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<CoreToolsMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Network::NetworkMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Database::DatabaseMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Script::ScriptMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Mathematics::MathematicsMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<SoundEffect::SoundEffectMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<InputOutput::InputOutputMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<ResourceManager::ResourceManagerMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Rendering::RenderingMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Physics::PhysicsMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Imagics::ImagicsMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Animation::AnimationMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<ArtificialIntelligence::ArtificialIntelligenceMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<UserInterface::UserInterfaceMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<AssistTools::AssistToolsMacroShared>);
    ASSERT_NOT_THROW_EXCEPTION_0(SharedExportTest<Framework::FrameworkMacroShared>);
}
