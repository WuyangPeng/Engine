///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 18:36)

#include "PixelShaderTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Textures/Texture1D.h"
#include "Rendering/Shaders/PixelShader.h"
#include "Rendering/Shaders/VertexShader.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, PixelShaderTesting)

void Rendering::PixelShaderTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::PixelShaderTesting::InitTest()
{
    ShaderBaseSharedPtr shader(std::make_shared<PixelShader>("Shader", 4, 5, 6, 7));

    ASSERT_EQUAL(shader->GetNumInputs(), 4);

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(shader->GetInputName(i), "");
        ASSERT_ENUM_EQUAL(shader->GetInputType(i), ShaderFlags::VariableType::None);
        ASSERT_ENUM_EQUAL(shader->GetInputSemantic(i), ShaderFlags::VariableSemantic::None);
    }

    ASSERT_EQUAL(shader->GetNumOutputs(), 5);

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_EQUAL(shader->GetOutputName(i), "");
        ASSERT_ENUM_EQUAL(shader->GetOutputType(i), ShaderFlags::VariableType::None);
        ASSERT_ENUM_EQUAL(shader->GetOutputSemantic(i), ShaderFlags::VariableSemantic::None);
    }

    ASSERT_EQUAL(shader->GetNumConstants(), 6);

    for (int i = 0; i < 6; ++i)
    {
        ASSERT_EQUAL(shader->GetConstantName(i), "");
        ASSERT_EQUAL(shader->GetNumRegistersUsed(i), 0);
    }

    ASSERT_EQUAL(shader->GetNumSamplers(), 7);

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(shader->GetSamplerName(i), "");
        ASSERT_ENUM_EQUAL(shader->GetSamplerType(i), ShaderFlags::SamplerType::None);
        ASSERT_ENUM_EQUAL(shader->GetFilter(i), ShaderFlags::SamplerFilter::Nearest);
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate::ClampEdge);
        ASSERT_APPROXIMATE(shader->GetLodBias(i), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(shader->GetAnisotropy(i), 1.0f, 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, shader->GetBorderColor(i), Colour<float>(0.0f, 0.0f, 0.0f, 0.0f), 1e-8f);
    }

    for (int i = 0; i < 4; ++i)
    {
        shader->SetInput(i, "Input" + boost::lexical_cast<string>(i), ShaderFlags::VariableType{ i }, ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        shader->SetOutput(i, "Output" + boost::lexical_cast<string>(i), ShaderFlags::VariableType{ i }, ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        shader->SetConstant(i, "Constant" + boost::lexical_cast<string>(i), i);
    }

    for (int i = 0; i < 7; ++i)
    {
        shader->SetSampler(i, "Texture" + boost::lexical_cast<string>(i), ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        shader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        shader->SetLodBias(i, static_cast<float>(i));
        shader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        shader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    }

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(shader->GetInputName(i), "Input" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(shader->GetInputType(i), ShaderFlags::VariableType{ i });
        ASSERT_ENUM_EQUAL(shader->GetInputSemantic(i), ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_EQUAL(shader->GetOutputName(i), "Output" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(shader->GetOutputType(i), ShaderFlags::VariableType{ i });
        ASSERT_ENUM_EQUAL(shader->GetOutputSemantic(i), ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        ASSERT_EQUAL(shader->GetConstantName(i), "Constant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(shader->GetNumRegistersUsed(i), i);
    }

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(shader->GetSamplerName(i), "Texture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(shader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(shader->GetFilter(i), ShaderFlags::SamplerFilter{ i });
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(shader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(shader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, shader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);
    }
}

void Rendering::PixelShaderTesting::CopyTest()
{
    PixelShaderSharedPtr shader(std::make_shared<PixelShader>("Shader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        shader->SetInput(i, "Input" + boost::lexical_cast<string>(i), ShaderFlags::VariableType{ i }, ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        shader->SetOutput(i, "Output" + boost::lexical_cast<string>(i), ShaderFlags::VariableType{ i }, ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        shader->SetConstant(i, "Constant" + boost::lexical_cast<string>(i), i);
    }

    for (int i = 0; i < 7; ++i)
    {
        shader->SetSampler(i, "Texture" + boost::lexical_cast<string>(i), ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        shader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        shader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        shader->SetLodBias(i, static_cast<float>(i));
        shader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        shader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    }

    ShaderBaseSharedPtr secondShader(std::make_shared<PixelShader>(*shader));

    ASSERT_EQUAL(shader->GetNumInputs(), secondShader->GetNumInputs());
    ASSERT_EQUAL(shader->GetNumOutputs(), secondShader->GetNumOutputs());
    ASSERT_EQUAL(shader->GetNumConstants(), secondShader->GetNumConstants());
    ASSERT_EQUAL(shader->GetNumSamplers(), secondShader->GetNumSamplers());

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(shader->GetInputName(i), secondShader->GetInputName(i));
        ASSERT_ENUM_EQUAL(shader->GetInputType(i), secondShader->GetInputType(i));
        ASSERT_ENUM_EQUAL(shader->GetInputSemantic(i), secondShader->GetInputSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_EQUAL(shader->GetOutputName(i), secondShader->GetOutputName(i));
        ASSERT_ENUM_EQUAL(shader->GetOutputType(i), secondShader->GetOutputType(i));
        ASSERT_ENUM_EQUAL(shader->GetOutputSemantic(i), secondShader->GetOutputSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        ASSERT_EQUAL(shader->GetConstantName(i), secondShader->GetConstantName(i));
        ASSERT_EQUAL(shader->GetNumRegistersUsed(i), secondShader->GetNumRegistersUsed(i));
    }

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(shader->GetSamplerName(i), secondShader->GetSamplerName(i));
        ASSERT_ENUM_EQUAL(shader->GetSamplerType(i), secondShader->GetSamplerType(i));
        ASSERT_ENUM_EQUAL(shader->GetFilter(i), secondShader->GetFilter(i));
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 0), secondShader->GetCoordinate(i, 0));
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 1), secondShader->GetCoordinate(i, 1));
        ASSERT_ENUM_EQUAL(shader->GetCoordinate(i, 2), secondShader->GetCoordinate(i, 2));
        ASSERT_APPROXIMATE(shader->GetLodBias(i), secondShader->GetLodBias(i), 1e-8f);
        ASSERT_APPROXIMATE(shader->GetAnisotropy(i), secondShader->GetAnisotropy(i), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, shader->GetBorderColor(i), secondShader->GetBorderColor(i), 1e-8f);
    }
}

void Rendering::PixelShaderTesting::StreamTest() noexcept
{
}
