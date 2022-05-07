// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:39)

#include "VisualTechniqueTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/VisualTechnique.h"

#include "System/Helper/PragmaWarning/LexicalCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualTechniqueTesting)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26409)
void Rendering::VisualTechniqueTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::VisualTechniqueTesting::InitTest()
{
    VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType(i),
                                ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(new PixelShader("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType(i),
                              ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(new AlphaState(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(new CullState(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(new DepthState(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(new OffsetState(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(new StencilState(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(new WireState(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);

    VisualPassSharedPtr firstVisualPass(new VisualPass(CoreTools::DisableNotThrow::Disable));

    firstVisualPass->SetVertexShader(vertexShader);
    firstVisualPass->SetPixelShader(pixelShader);
    firstVisualPass->SetAlphaState(alphaState);
    firstVisualPass->SetCullState(cullState);
    firstVisualPass->SetDepthState(depthState);
    firstVisualPass->SetOffsetState(offsetState);
    firstVisualPass->SetStencilState(stencilState);
    firstVisualPass->SetWireState(wireState);

    VisualPassSharedPtr secondVisualPass(new VisualPass(CoreTools::DisableNotThrow::Disable));

    VisualTechniqueSharedPtr visualTechnique(new VisualTechnique(CoreTools::DisableNotThrow::Disable));

    ASSERT_EQUAL(visualTechnique->GetNumPasses(), 0);

    visualTechnique->InsertPass(firstVisualPass);

    ASSERT_EQUAL(visualTechnique->GetNumPasses(), 1);

    visualTechnique->InsertPass(secondVisualPass);

    ASSERT_EQUAL(visualTechnique->GetNumPasses(), 2);

    ASSERT_EQUAL(visualTechnique->GetPass(0), firstVisualPass);
    ASSERT_EQUAL(visualTechnique->GetPass(1), secondVisualPass);

    ASSERT_EQUAL(visualTechnique->GetVertexShader(0), vertexShader);
    ASSERT_EQUAL(visualTechnique->GetPixelShader(0), pixelShader);
    ASSERT_EQUAL(visualTechnique->GetAlphaState(0), alphaState);
    ASSERT_EQUAL(visualTechnique->GetCullState(0), cullState);
    ASSERT_EQUAL(visualTechnique->GetDepthState(0), depthState);
    ASSERT_EQUAL(visualTechnique->GetOffsetState(0), offsetState);
    ASSERT_EQUAL(visualTechnique->GetStencilState(0), stencilState);
    ASSERT_EQUAL(visualTechnique->GetWireState(0), wireState);

    // 	ASSERT_TRUE(visualTechnique->GetVertexShader(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetPixelShader(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetAlphaState(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetCullState(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetDepthState(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetOffsetState(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetStencilState(1).IsNullPtr());
    // 	ASSERT_TRUE(visualTechnique->GetWireState(1).IsNullPtr());
}

void Rendering::VisualTechniqueTesting::CopyTest()
{
    VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType(i),
                                ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(new PixelShader("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType(i),
                              ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(new AlphaState(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(new CullState(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(new DepthState(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(new OffsetState(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(new StencilState(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(new WireState(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);

    VisualPassSharedPtr firstVisualPass(new VisualPass(CoreTools::DisableNotThrow::Disable));

    firstVisualPass->SetVertexShader(vertexShader);
    firstVisualPass->SetPixelShader(pixelShader);
    firstVisualPass->SetAlphaState(alphaState);
    firstVisualPass->SetCullState(cullState);
    firstVisualPass->SetDepthState(depthState);
    firstVisualPass->SetOffsetState(offsetState);
    firstVisualPass->SetStencilState(stencilState);
    firstVisualPass->SetWireState(wireState);

    VisualPassSharedPtr secondVisualPass(new VisualPass(CoreTools::DisableNotThrow::Disable));

    VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique(CoreTools::DisableNotThrow::Disable));

    firstVisualTechnique->InsertPass(firstVisualPass);
    firstVisualTechnique->InsertPass(secondVisualPass);

    VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique(*firstVisualTechnique));

    ASSERT_EQUAL(firstVisualTechnique->GetNumPasses(), secondVisualTechnique->GetNumPasses());

    for (int i = 0; i < 2; ++i)
    {
        ASSERT_EQUAL(firstVisualTechnique->GetPass(i),
                     secondVisualTechnique->GetPass(i));

        ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(i),
                     secondVisualTechnique->GetVertexShader(i));
        ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(i),
                     secondVisualTechnique->GetPixelShader(i));
        ASSERT_EQUAL(firstVisualTechnique->GetAlphaState(i),
                     secondVisualTechnique->GetAlphaState(i));
        ASSERT_EQUAL(firstVisualTechnique->GetCullState(i),
                     secondVisualTechnique->GetCullState(i));
        ASSERT_EQUAL(firstVisualTechnique->GetDepthState(i),
                     secondVisualTechnique->GetDepthState(i));
        ASSERT_EQUAL(firstVisualTechnique->GetOffsetState(i),
                     secondVisualTechnique->GetOffsetState(i));
        ASSERT_EQUAL(firstVisualTechnique->GetStencilState(i),
                     secondVisualTechnique->GetStencilState(i));
        ASSERT_EQUAL(firstVisualTechnique->GetWireState(i),
                     secondVisualTechnique->GetWireState(i));
    }

    VisualPassSharedPtr thirdVisualPass(new VisualPass(CoreTools::DisableNotThrow::Disable));
    secondVisualTechnique->InsertPass(thirdVisualPass);

    ASSERT_EQUAL(firstVisualTechnique->GetNumPasses(), 2);
    ASSERT_EQUAL(secondVisualTechnique->GetNumPasses(), 3);
}

void Rendering::VisualTechniqueTesting::StreamTest()
{
    VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5, 4, 6));

    for (int i = 0; i < 3; ++i)
    {
        vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
                                ShaderFlags::VariableType(i),
                                ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 4; ++i)
    {
        vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),
                                  i);
    }

    for (int i = 0; i < 6; ++i)
    {
        vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),
                                 ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        vertexShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                      static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f,
                                                      static_cast<float>(i + 3) / 10.0f));
    }

    PixelShaderSharedPtr pixelShader(new PixelShader("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType(i),
                              ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i),
                               ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),
                                 i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerCoordinate::Quantity)));

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
                                                     static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f,
                                                     static_cast<float>(i + 3) / 10.0f));
    }

    AlphaStateSharedPtr alphaState(new AlphaState(CoreTools::DisableNotThrow::Disable));
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(new CullState(CoreTools::DisableNotThrow::Disable));

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(new DepthState(CoreTools::DisableNotThrow::Disable));
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(new OffsetState(CoreTools::DisableNotThrow::Disable));

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(new StencilState(CoreTools::DisableNotThrow::Disable));

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(new WireState(CoreTools::DisableNotThrow::Disable));

    wireState->SetEnabled(true);

    // 	CoreTools::OutTopLevel outTopLevel;
    //
    // 	VisualPassSharedPtr firstVisualPass(new VisualPass);
    //
    // 	firstVisualPass->SetVertexShader(vertexShader);
    // 	firstVisualPass->SetPixelShader(pixelShader);
    // 	firstVisualPass->SetAlphaState(alphaState);
    // 	firstVisualPass->SetCullState(cullState);
    // 	firstVisualPass->SetDepthState(depthState);
    // 	firstVisualPass->SetOffsetState(offsetState);
    // 	firstVisualPass->SetStencilState(stencilState);
    // 	firstVisualPass->SetWireState(wireState);
    //
    // 	VisualPassSharedPtr secondVisualPass(new VisualPass);
    //
    // 	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);
    //
    // 	firstVisualTechnique->InsertPass(firstVisualPass);
    // 	firstVisualTechnique->InsertPass(secondVisualPass);
    //
    // 	outTopLevel.Insert(firstVisualTechnique);
    //
    // 	CoreTools::BufferOutStream outStream(outTopLevel);
    //
    // 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
    //
    // 	CoreTools::BufferInStream inStream(fileBufferPtr);
    //
    // 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
    //
    // 	VisualTechniqueSharedPtr secondVisualTechnique =	inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualTechniqueSharedPtr>();
    //
    // 	ASSERT_EQUAL(firstVisualTechnique->GetNumPasses(),secondVisualTechnique->GetNumPasses());
    //
    //
    // 	// VertexShader
    // 	ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(1),secondVisualTechnique->GetVertexShader(1));
    //
    // 	ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetNumInputs(), secondVisualTechnique->GetVertexShader(0)->GetNumInputs());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetNumOutputs(), secondVisualTechnique->GetVertexShader(0)->GetNumOutputs());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetNumConstants(), secondVisualTechnique->GetVertexShader(0)->GetNumConstants());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetNumSamplers(), secondVisualTechnique->GetVertexShader(0)->GetNumSamplers());
    //
    // 	for (int i = 0; i < 3;++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetInputName(i), secondVisualTechnique->GetVertexShader(0)->GetInputName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetInputType(i), secondVisualTechnique->GetVertexShader(0)->GetInputType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetInputSemantic(i), secondVisualTechnique->GetVertexShader(0)->GetInputSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 5; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetOutputName(i), secondVisualTechnique->GetVertexShader(0)->GetOutputName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetOutputType(i), secondVisualTechnique->GetVertexShader(0)->GetOutputType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetOutputSemantic(i), secondVisualTechnique->GetVertexShader(0)->GetOutputSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 4; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetConstantName(i), secondVisualTechnique->GetVertexShader(0)->GetConstantName(i));
    // 		ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetNumRegistersUsed(i), secondVisualTechnique->GetVertexShader(0)->GetNumRegistersUsed(i));
    // 	}
    //
    // 	for (int i = 0; i < 5; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetSamplerName(i), secondVisualTechnique->GetVertexShader(0)->GetSamplerName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetSamplerType(i), secondVisualTechnique->GetVertexShader(0)->GetSamplerType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetFilter(i), secondVisualTechnique->GetVertexShader(0)->GetFilter(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 0), secondVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 0));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 1), secondVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 1));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 2), secondVisualTechnique->GetVertexShader(0)->GetCoordinate(i, 2));
    // 		ASSERT_APPROXIMATE(firstVisualTechnique->GetVertexShader(0)->GetLodBias(i), secondVisualTechnique->GetVertexShader(0)->GetLodBias(i), 1e-8f);
    // 		ASSERT_APPROXIMATE(firstVisualTechnique->GetVertexShader(0)->GetAnisotropy(i), secondVisualTechnique->GetVertexShader(0)->GetAnisotropy(i), 1e-8f);
    // 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualTechnique->GetVertexShader(0)->GetBorderColor(i),
    // 										secondVisualTechnique->GetVertexShader(0)->GetBorderColor(i), 1e-8f);
    // 	}
    //
    // 	// PixelShader
    // 	ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(1),secondVisualTechnique->GetPixelShader(1));
    //
    // 	ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetNumInputs(), secondVisualTechnique->GetPixelShader(0)->GetNumInputs());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetNumOutputs(), secondVisualTechnique->GetPixelShader(0)->GetNumOutputs());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetNumConstants(), secondVisualTechnique->GetPixelShader(0)->GetNumConstants());
    // 	ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetNumSamplers(), secondVisualTechnique->GetPixelShader(0)->GetNumSamplers());
    //
    // 	for (int i = 0; i < 4; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetInputName(i), secondVisualTechnique->GetPixelShader(0)->GetInputName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetInputType(i), secondVisualTechnique->GetPixelShader(0)->GetInputType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetInputSemantic(i), secondVisualTechnique->GetPixelShader(0)->GetInputSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 5; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetOutputName(i), secondVisualTechnique->GetPixelShader(0)->GetOutputName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetOutputType(i), secondVisualTechnique->GetPixelShader(0)->GetOutputType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetOutputSemantic(i), secondVisualTechnique->GetPixelShader(0)->GetOutputSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 6; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetConstantName(i), secondVisualTechnique->GetPixelShader(0)->GetConstantName(i));
    // 		ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetNumRegistersUsed(i), secondVisualTechnique->GetPixelShader(0)->GetNumRegistersUsed(i));
    // 	}
    //
    // 	for (int i = 0; i < 7; ++i)
    // 	{
    // 		ASSERT_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetSamplerName(i), secondVisualTechnique->GetPixelShader(0)->GetSamplerName(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetSamplerType(i), secondVisualTechnique->GetPixelShader(0)->GetSamplerType(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetFilter(i), secondVisualTechnique->GetPixelShader(0)->GetFilter(i));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 0), secondVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 0));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 1), secondVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 1));
    // 		ASSERT_ENUM_EQUAL(firstVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 2), secondVisualTechnique->GetPixelShader(0)->GetCoordinate(i, 2));
    // 		ASSERT_APPROXIMATE(firstVisualTechnique->GetPixelShader(0)->GetLodBias(i), secondVisualTechnique->GetPixelShader(0)->GetLodBias(i), 1e-8f);
    // 		ASSERT_APPROXIMATE(firstVisualTechnique->GetPixelShader(0)->GetAnisotropy(i), secondVisualTechnique->GetPixelShader(0)->GetAnisotropy(i), 1e-8f);
    // 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualTechnique->GetPixelShader(0)->GetBorderColor(i),
    // 										secondVisualTechnique->GetPixelShader(0)->GetBorderColor(i), 1e-8f);
    // 	}
    //
    // 	// AlphaState
    // 	ASSERT_EQUAL(firstVisualTechnique->GetAlphaState(1),secondVisualTechnique->GetAlphaState(1));
    //
    //
    // 	ASSERT_EQUAL(firstVisualTechnique->GetAlphaState(0)->IsBlendEnabled(), secondVisualTechnique->GetAlphaState(0)->IsBlendEnabled());
    // 	ASSERT_ENUM_EQUAL(firstVisualTechnique->GetAlphaState(0)->GetSourceBlend(), secondVisualTechnique->GetAlphaState(0)->GetSourceBlend());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetAlphaState(0)->GetDestinationBlend(), secondVisualTechnique->GetAlphaState(0)->GetDestinationBlend());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetAlphaState(0)->IsCompareEnabled(), secondVisualTechnique->GetAlphaState(0)->IsCompareEnabled());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetAlphaState(0)->GetCompare(), secondVisualTechnique->GetAlphaState(0)->GetCompare());
    // 	 ASSERT_APPROXIMATE(firstVisualTechnique->GetAlphaState(0)->GetReference(), secondVisualTechnique->GetAlphaState(0)->GetReference(), 1e-8f);
    // 	 ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualTechnique->GetAlphaState(0)->GetConstantColor(),
    // 			                         secondVisualTechnique->GetAlphaState(0)->GetConstantColor(),1e-8f);
    //
    // 	 // CullState
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetCullState(1),secondVisualTechnique->GetCullState(1));
    //
    //
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetCullState(0)->IsEnabled(), secondVisualTechnique->GetCullState(0)->IsEnabled());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetCullState(0)->IsCCWOrder(), secondVisualTechnique->GetCullState(0)->IsCCWOrder());
    //
    // 	 // DepthState
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetDepthState(1),secondVisualTechnique->GetDepthState(1));
    //
    //
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetDepthState(0)->IsEnabled(), secondVisualTechnique->GetDepthState(0)->IsEnabled());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetDepthState(0)->IsWritable(), secondVisualTechnique->GetDepthState(0)->IsWritable());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetDepthState(0)->GetCompare(), secondVisualTechnique->GetDepthState(0)->GetCompare());
    //
    // 	 // OffsetState
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetOffsetState(1),secondVisualTechnique->GetOffsetState(1));
    //
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetOffsetState(0)->IsFillEnabled(), secondVisualTechnique->GetOffsetState(0)->IsFillEnabled());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetOffsetState(0)->IsLineEnabled(), secondVisualTechnique->GetOffsetState(0)->IsLineEnabled());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetOffsetState(0)->IsPointEnabled(), secondVisualTechnique->GetOffsetState(0)->IsPointEnabled());
    // 	 ASSERT_APPROXIMATE(firstVisualTechnique->GetOffsetState(0)->GetScale(), secondVisualTechnique->GetOffsetState(0)->GetScale(), 1e-8f);
    // 	 ASSERT_APPROXIMATE(firstVisualTechnique->GetOffsetState(0)->GetBias(), secondVisualTechnique->GetOffsetState(0)->GetBias(), 1e-8f);
    //
    // 	 // StencilState
    // 	  ASSERT_EQUAL(firstVisualTechnique->GetStencilState(1),secondVisualTechnique->GetStencilState(1));
    //
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetStencilState(0)->IsEnabled(), secondVisualTechnique->GetStencilState(0)->IsEnabled());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetStencilState(0)->GetCompare(), secondVisualTechnique->GetStencilState(0)->GetCompare());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetStencilState(0)->GetReference(), secondVisualTechnique->GetStencilState(0)->GetReference());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetStencilState(0)->GetMask(), secondVisualTechnique->GetStencilState(0)->GetMask());
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetStencilState(0)->GetWriteMask(), secondVisualTechnique->GetStencilState(0)->GetWriteMask());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetStencilState(0)->GetOnFail(), secondVisualTechnique->GetStencilState(0)->GetOnFail());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetStencilState(0)->GetOnZFail(), secondVisualTechnique->GetStencilState(0)->GetOnZFail());
    // 	 ASSERT_ENUM_EQUAL(firstVisualTechnique->GetStencilState(0)->GetOnZPass(), secondVisualTechnique->GetStencilState(0)->GetOnZPass());
    //
    // 	 // WireState
    // 	 	  ASSERT_EQUAL(firstVisualTechnique->GetWireState(1),secondVisualTechnique->GetWireState(1));
    //
    // 	 ASSERT_EQUAL(firstVisualTechnique->GetWireState(0)->IsEnabled(), secondVisualTechnique->GetWireState(0)->IsEnabled());
}
