///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:10)

#include "VisualEffectTesting.h"
#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/LoadVisualEffect.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/PixelShader.h"
#include "Rendering/Shaders/SaveVisualEffect.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/VertexShader.h"
#include "Rendering/Shaders/VisualPass.h"
#include "Rendering/Shaders/VisualTechnique.h"
#include "Rendering/Shaders/WireState.h"

Rendering::VisualEffectTesting::VisualEffectTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, VisualEffectTesting)

void Rendering::VisualEffectTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::VisualEffectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializer();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminator();
}

void Rendering::VisualEffectTesting::InitTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<std::string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<std::string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<std::string>(i),
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
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<std::string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<std::string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<std::string>(i),
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
}

void Rendering::VisualEffectTesting::CopyTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<std::string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<std::string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<std::string>(i),
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
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<std::string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<std::string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<std::string>(i),
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
}

void Rendering::VisualEffectTesting::StreamTest()
{
    VertexShaderSharedPtr vertexShader(std::make_shared<VertexShader>("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<std::string>(i),
                                ShaderFlags::VariableType{ i },
                                ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<std::string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<std::string>(i),
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
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<std::string>(i),
                              ShaderFlags::VariableType{ i },
                              ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<std::string>(i),
                               ShaderFlags::VariableType{ i },
                               ShaderFlags::VariableSemantic{ i });
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<std::string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<std::string>(i),
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
