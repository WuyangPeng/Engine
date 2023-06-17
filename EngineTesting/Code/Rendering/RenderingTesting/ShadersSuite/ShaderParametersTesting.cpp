///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:06)

#include "ShaderParametersTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Shaders/ShaderParameters.h"
#include "Rendering/Shaders/VertexShader.h"

Rendering::ShaderParametersTesting::ShaderParametersTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ShaderParametersTesting)

void Rendering::ShaderParametersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ShaderParametersTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::ShaderParametersTesting::InitTest()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

    auto shader = std::make_shared<VertexShader>("Shader", 1, 1, 5, 4);

#include STSTEM_WARNING_POP

    shader->SetConstant(0, "Constant0", 1);
    shader->SetConstant(1, "Constant1", 1);
    shader->SetConstant(2, "Constant2", 2);
    shader->SetConstant(3, "Constant3", 3);
    shader->SetConstant(4, "Constant4", 4);

    shader->SetSampler(0, "Texture0", ShaderFlags::SamplerType::Sampler1D);
    shader->SetSampler(1, "Texture1", ShaderFlags::SamplerType::Sampler1D);
    shader->SetSampler(2, "Texture2", ShaderFlags::SamplerType::Sampler1D);
    shader->SetSampler(3, "Texture3", ShaderFlags::SamplerType::Sampler1D);
}

void Rendering::ShaderParametersTesting::CopyTest() noexcept
{
}

void Rendering::ShaderParametersTesting::StreamTest() noexcept
{
}
