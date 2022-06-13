///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 18:43)

#include "SaveVisualEffectTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/LoadVisualEffect.h"
#include "Rendering/Shaders/SaveVisualEffect.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, SaveVisualEffectTesting)

void Rendering::SaveVisualEffectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateVisualEffectFile);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveFile);
    ASSERT_NOT_THROW_EXCEPTION_0(SaveTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::SaveVisualEffectTesting::CreateVisualEffectFile() noexcept
{
}

void Rendering::SaveVisualEffectTesting::SaveFile()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/FirstSaveVisualEffect.trve"));

    const SaveVisualEffect saveVisualEffect(*visualEffect, SYSTEM_TEXT("Resource/ShadersSuite/SecondSaveVisualEffect.trve"));
}

void Rendering::SaveVisualEffectTesting::SaveTest()
{
    CoreTools::IFStreamManager firstFile(SYSTEM_TEXT("Resource/ShadersSuite/FirstSaveVisualEffect.trve"));
    CoreTools::IFStreamManager secondFile(SYSTEM_TEXT("Resource/ShadersSuite/SecondSaveVisualEffect.trve"));

    ASSERT_EQUAL(firstFile.GetFileContent(), secondFile.GetFileContent());
}
