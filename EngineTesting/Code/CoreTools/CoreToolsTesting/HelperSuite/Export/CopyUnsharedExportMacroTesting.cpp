/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/13 10:40)

#include "CopyUnsharedExportMacroTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/AnimationCopyUnsharedMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/CopyUnshared/ArtificialIntelligenceCopyUnsharedMacro.h"
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
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyUnsharedExportMacroTesting)

void CoreTools::CopyUnsharedExportMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyUnsharedExportMacroTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<ExportCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<CoreToolsCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Network::NetworkCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Database::DatabaseCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Script::ScriptCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Mathematics::MathematicsCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<SoundEffect::SoundEffectCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<InputOutput::InputOutputCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<ResourceManager::ResourceManagerCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Rendering::RenderingCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Physics::PhysicsCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Imagics::ImagicsCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Animation::AnimationCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<ArtificialIntelligence::ArtificialIntelligenceCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<UserInterface::UserInterfaceCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<AssistTools::AssistToolsCopyUnsharedMacro>);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyUnsharedExportTest<Framework::FrameworkCopyUnsharedMacro>);
}
