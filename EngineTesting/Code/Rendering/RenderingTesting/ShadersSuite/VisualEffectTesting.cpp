///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 19:29)

#include "VisualEffectTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/VisualEffect.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualEffectTesting)

void Rendering::VisualEffectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VisualEffectTesting::InitTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(std::make_shared<PixelShader>("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);

    VisualPassSharedPtr firstVisualPass(std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable));

    firstVisualPass->SetVertexShader(vertexShader);
    firstVisualPass->SetPixelShader(pixelShader);
    firstVisualPass->SetAlphaState(alphaState);
    firstVisualPass->SetCullState(cullState);
    firstVisualPass->SetDepthState(depthState);
    firstVisualPass->SetOffsetState(offsetState);
    firstVisualPass->SetStencilState(stencilState);
    firstVisualPass->SetWireState(wireState);

    VisualPassSharedPtr secondVisualPass(std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable));

    VisualTechniqueSharedPtr firstVisualTechnique(std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable));

    firstVisualTechnique->InsertPass(firstVisualPass);
    firstVisualTechnique->InsertPass(secondVisualPass);

    VisualTechniqueSharedPtr secondVisualTechnique(std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable));

    secondVisualTechnique->InsertPass(secondVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);

    VisualEffectSharedPtr visualEffect(std::make_shared<VisualEffect>(CoreTools::DisableNotThrow::Disable));

    ASSERT_EQUAL(visualEffect->GetNumTechniques(), 0);

    visualEffect->InsertTechnique(firstVisualTechnique);
    ASSERT_EQUAL(visualEffect->GetNumTechniques(), 1);

    visualEffect->InsertTechnique(secondVisualTechnique);
    ASSERT_EQUAL(visualEffect->GetNumTechniques(), 2);

    ASSERT_EQUAL(visualEffect->GetPass(0, 0), firstVisualPass);
    ASSERT_EQUAL(visualEffect->GetPass(0, 1), secondVisualPass);
    ASSERT_EQUAL(visualEffect->GetPass(1, 0), secondVisualPass);
    ASSERT_EQUAL(visualEffect->GetPass(1, 1), firstVisualPass);
    ASSERT_EQUAL(visualEffect->GetPass(1, 2), firstVisualPass);

    ASSERT_EQUAL(visualEffect->GetNumPasses(0), 2);
    ASSERT_EQUAL(visualEffect->GetNumPasses(1), 3);

    ASSERT_EQUAL(visualEffect->GetVertexShader(0, 0), vertexShader);
    ASSERT_EQUAL(visualEffect->GetPixelShader(0, 0), pixelShader);
    ASSERT_EQUAL(visualEffect->GetAlphaState(0, 0), alphaState);
    ASSERT_EQUAL(visualEffect->GetCullState(0, 0), cullState);
    ASSERT_EQUAL(visualEffect->GetDepthState(0, 0), depthState);
    ASSERT_EQUAL(visualEffect->GetOffsetState(0, 0), offsetState);
    ASSERT_EQUAL(visualEffect->GetStencilState(0, 0), stencilState);
    ASSERT_EQUAL(visualEffect->GetWireState(0, 0), wireState);

    ASSERT_EQUAL(visualEffect->GetVertexShader(1, 1), vertexShader);
    ASSERT_EQUAL(visualEffect->GetPixelShader(1, 1), pixelShader);
    ASSERT_EQUAL(visualEffect->GetAlphaState(1, 1), alphaState);
    ASSERT_EQUAL(visualEffect->GetCullState(1, 1), cullState);
    ASSERT_EQUAL(visualEffect->GetDepthState(1, 1), depthState);
    ASSERT_EQUAL(visualEffect->GetOffsetState(1, 1), offsetState);
    ASSERT_EQUAL(visualEffect->GetStencilState(1, 1), stencilState);
    ASSERT_EQUAL(visualEffect->GetWireState(1, 1), wireState);

    ASSERT_EQUAL(visualEffect->GetVertexShader(1, 2), vertexShader);
    ASSERT_EQUAL(visualEffect->GetPixelShader(1, 2), pixelShader);
    ASSERT_EQUAL(visualEffect->GetAlphaState(1, 2), alphaState);
    ASSERT_EQUAL(visualEffect->GetCullState(1, 2), cullState);
    ASSERT_EQUAL(visualEffect->GetDepthState(1, 2), depthState);
    ASSERT_EQUAL(visualEffect->GetOffsetState(1, 2), offsetState);
    ASSERT_EQUAL(visualEffect->GetStencilState(1, 2), stencilState);
    ASSERT_EQUAL(visualEffect->GetWireState(1, 2), wireState);
}

void Rendering::VisualEffectTesting::CopyTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(std::make_shared<PixelShader>("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);

    VisualPassSharedPtr firstVisualPass(std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable));

    firstVisualPass->SetVertexShader(vertexShader);
    firstVisualPass->SetPixelShader(pixelShader);
    firstVisualPass->SetAlphaState(alphaState);
    firstVisualPass->SetCullState(cullState);
    firstVisualPass->SetDepthState(depthState);
    firstVisualPass->SetOffsetState(offsetState);
    firstVisualPass->SetStencilState(stencilState);
    firstVisualPass->SetWireState(wireState);

    VisualPassSharedPtr secondVisualPass(std::make_shared<VisualPass>(CoreTools::DisableNotThrow::Disable));

    VisualTechniqueSharedPtr firstVisualTechnique(std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable));

    firstVisualTechnique->InsertPass(firstVisualPass);
    firstVisualTechnique->InsertPass(secondVisualPass);

    VisualTechniqueSharedPtr secondVisualTechnique(std::make_shared<VisualTechnique>(CoreTools::DisableNotThrow::Disable));

    secondVisualTechnique->InsertPass(secondVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);

    VisualEffectSharedPtr firstVisualEffect(std::make_shared<VisualEffect>(CoreTools::DisableNotThrow::Disable));
    firstVisualEffect->InsertTechnique(firstVisualTechnique);
    firstVisualEffect->InsertTechnique(secondVisualTechnique);

    VisualEffectSharedPtr secondVisualEffect(std::make_shared<VisualEffect>(*firstVisualEffect));

    ASSERT_EQUAL(firstVisualEffect->GetNumTechniques(), secondVisualEffect->GetNumTechniques());

    for (int i = 0; i < 2; ++i)
    {
        ASSERT_EQUAL(firstVisualEffect->GetTechnique(i),
                     secondVisualEffect->GetTechnique(i));
        ASSERT_EQUAL(firstVisualEffect->GetNumPasses(i),
                     secondVisualEffect->GetNumPasses(i));
    }

    for (int i = 0; i < 2; ++i)
    {
        int max = 2;
        if (i == 1)
            max = 3;
        for (int k = 0; k < max; ++k)
        {
            ASSERT_EQUAL(firstVisualEffect->GetPass(i, k),
                         secondVisualEffect->GetPass(i, k));

            ASSERT_EQUAL(firstVisualEffect->GetVertexShader(i, k),
                         secondVisualEffect->GetVertexShader(i, k));

            ASSERT_EQUAL(firstVisualEffect->GetPixelShader(i, k), secondVisualEffect->GetPixelShader(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetAlphaState(i, k), secondVisualEffect->GetAlphaState(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetCullState(i, k), secondVisualEffect->GetCullState(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetDepthState(i, k), secondVisualEffect->GetDepthState(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetOffsetState(i, k), secondVisualEffect->GetOffsetState(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetStencilState(i, k), secondVisualEffect->GetStencilState(i, k));
            ASSERT_EQUAL(firstVisualEffect->GetWireState(i, k), secondVisualEffect->GetWireState(i, k));
        }
    }
}

void Rendering::VisualEffectTesting::StreamTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(std::make_shared<PixelShader>("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter{ i });
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate{ i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate{ (i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate{ (i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity) });

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);
}
