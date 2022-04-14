// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:27)

#include "LoadVisualEffectTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/LoadVisualEffect.h"
#include "Rendering/Shaders/SaveVisualEffect.h"

#include "System/Helper/PragmaWarning/LexicalCast.h"

using std::string;
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26414)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, LoadVisualEffectTesting)

void Rendering::LoadVisualEffectTesting::MainTest()
{
    CoreTools::InitTerm::ExecuteInitializers();

    RendererManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CreateVisualEffectFile);
    ASSERT_NOT_THROW_EXCEPTION_0(VertexShaderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PixelShaderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AlphaStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CullStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DepthStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OffsetStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StencilStateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WireStateTest);

    RendererManager::Destroy();

    CoreTools::InitTerm::ExecuteTerminators();
}

void Rendering::LoadVisualEffectTesting::CreateVisualEffectFile()
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
        vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));

        vertexShader->SetLodBias(i, static_cast<float>(i));
        vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    }

    ShaderProfileDataSharedPtr vertexProfile(new ShaderProfileData(4, 6));

    for (int i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            vertexProfile->SetBaseRegister(i, registerIndex, i * 10 + registerIndex);
        }

        for (int textureUnitIndex = 0; textureUnitIndex < 6; ++textureUnitIndex)
        {
            vertexProfile->SetTextureUnit(i, textureUnitIndex, i * 10 + textureUnitIndex);
        }

        vertexProfile->SetProgram(i, "VertexProgram" + boost::lexical_cast<string>(i));
    }

    vertexShader->SetProfile(vertexProfile);

    PixelShaderSharedPtr pixelShader(new PixelShader("PixelShader", 4, 5, 6, 7));

    for (int i = 0; i < 4; ++i)
    {
        pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
                              ShaderFlags::VariableType(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
                               ShaderFlags::VariableType(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i), i);
    }

    for (int i = 0; i < 7; ++i)
    {
        pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
                                ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
        pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));

        pixelShader->SetLodBias(i, static_cast<float>(i));
        pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
        pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                     static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    }

    ShaderProfileDataSharedPtr pixelProfile(new ShaderProfileData(6, 7));

    for (int i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (int registerIndex = 0; registerIndex < 6; ++registerIndex)
        {
            pixelProfile->SetBaseRegister(i, registerIndex, i * 10 + registerIndex);
        }

        for (int textureUnitIndex = 0; textureUnitIndex < 7; ++textureUnitIndex)
        {
            pixelProfile->SetTextureUnit(i, textureUnitIndex, i * 10 + textureUnitIndex);
        }

        pixelProfile->SetProgram(i, "PixelProgram" + boost::lexical_cast<string>(i));
    }

    pixelShader->SetProfile(pixelProfile);

    AlphaStateSharedPtr alphaState(new AlphaState);
    alphaState->SetBlendEnabled(true);
    alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    alphaState->SetCompareEnabled(true);
    alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    alphaState->SetReference(0.5f);
    alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));

    CullStateSharedPtr cullState(new CullState);

    cullState->SetEnabled(false);
    cullState->SetCCWOrder(false);

    DepthStateSharedPtr depthState(new DepthState);
    depthState->SetEnabled(false);
    depthState->SetWritable(false);
    depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);

    OffsetStateSharedPtr offsetState(new OffsetState);

    offsetState->SetFillEnabled(true);
    offsetState->SetLineEnabled(true);
    offsetState->SetPointEnabled(true);
    offsetState->SetScale(1.5f);
    offsetState->SetBias(1.6f);

    StencilStateSharedPtr stencilState(new StencilState);

    stencilState->SetEnabled(true);
    stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    stencilState->SetReference(5);
    stencilState->SetMask(0xFFFEEFFE);
    stencilState->SetWriteMask(0xFDFEEFFE);
    stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);

    WireStateSharedPtr wireState(new WireState);

    wireState->SetEnabled(true);

    VisualPassSharedPtr firstVisualPass(new VisualPass);

    firstVisualPass->SetVertexShader(vertexShader);
    firstVisualPass->SetPixelShader(pixelShader);
    firstVisualPass->SetAlphaState(alphaState);
    firstVisualPass->SetCullState(cullState);
    firstVisualPass->SetDepthState(depthState);
    firstVisualPass->SetOffsetState(offsetState);
    firstVisualPass->SetStencilState(stencilState);
    firstVisualPass->SetWireState(wireState);

    VisualPassSharedPtr secondVisualPass(new VisualPass);

    VertexShaderSharedPtr secondVertexShader(new VertexShader("VertexShader2", 4, 3, 4, 6));
    secondVertexShader->SetProfile(vertexProfile);
    PixelShaderSharedPtr secondPixelShader(new PixelShader("PixelShader2", 2, 8, 6, 7));
    secondPixelShader->SetProfile(pixelProfile);

    secondVisualPass->SetVertexShader(secondVertexShader);
    secondVisualPass->SetPixelShader(secondPixelShader);
    secondVisualPass->SetAlphaState(AlphaStateSharedPtr(new AlphaState));
    secondVisualPass->SetCullState(CullStateSharedPtr(new CullState));
    secondVisualPass->SetDepthState(DepthStateSharedPtr(new DepthState));
    secondVisualPass->SetOffsetState(OffsetStateSharedPtr(new OffsetState));
    secondVisualPass->SetStencilState(StencilStateSharedPtr(new StencilState));
    secondVisualPass->SetWireState(WireStateSharedPtr(new WireState));

    VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);

    firstVisualTechnique->InsertPass(firstVisualPass);
    firstVisualTechnique->InsertPass(secondVisualPass);

    VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique);

    secondVisualTechnique->InsertPass(secondVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);
    secondVisualTechnique->InsertPass(firstVisualPass);

    VisualEffectSharedPtr visualEffect(new VisualEffect);
    visualEffect->InsertTechnique(firstVisualTechnique);
    visualEffect->InsertTechnique(secondVisualTechnique);

    const SaveVisualEffect saveVisualEffect(visualEffect, SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));
}

void Rendering::LoadVisualEffectTesting::VertexShaderTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstVertexShaderSharedPtr firstVertexShader = visualEffect->GetVertexShader(0, 0);
    ConstVertexShaderSharedPtr secondVertexShader = visualEffect->GetVertexShader(0, 1);
    ConstVertexShaderSharedPtr thirdVertexShader = visualEffect->GetVertexShader(1, 0);
    ConstVertexShaderSharedPtr fourthVertexShader = visualEffect->GetVertexShader(1, 1);
    ConstVertexShaderSharedPtr fifthVertexShader = visualEffect->GetVertexShader(1, 2);
    ConstVertexShaderSharedPtr sixthVertexShader(new VertexShader("VertexShader2", 4, 3, 4, 6));

    ASSERT_EQUAL(firstVertexShader->GetNumInputs(), 3);
    ASSERT_EQUAL(firstVertexShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(firstVertexShader->GetNumConstants(), 4);
    ASSERT_EQUAL(firstVertexShader->GetNumSamplers(), 6);
    ASSERT_EQUAL(firstVertexShader->GetName(), "VertexShader");

    ASSERT_EQUAL(secondVertexShader->GetNumInputs(), 4);
    ASSERT_EQUAL(secondVertexShader->GetNumOutputs(), 3);
    ASSERT_EQUAL(secondVertexShader->GetNumConstants(), 4);
    ASSERT_EQUAL(secondVertexShader->GetNumSamplers(), 6);
    ASSERT_EQUAL(secondVertexShader->GetName(), "VertexShader2");

    ASSERT_EQUAL(thirdVertexShader->GetNumInputs(), 4);
    ASSERT_EQUAL(thirdVertexShader->GetNumOutputs(), 3);
    ASSERT_EQUAL(thirdVertexShader->GetNumConstants(), 4);
    ASSERT_EQUAL(thirdVertexShader->GetNumSamplers(), 6);
    ASSERT_EQUAL(thirdVertexShader->GetName(), "VertexShader2");

    ASSERT_EQUAL(fourthVertexShader->GetNumInputs(), 3);
    ASSERT_EQUAL(fourthVertexShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(fourthVertexShader->GetNumConstants(), 4);
    ASSERT_EQUAL(fourthVertexShader->GetNumSamplers(), 6);
    ASSERT_EQUAL(fourthVertexShader->GetName(), "VertexShader");

    ASSERT_EQUAL(fifthVertexShader->GetNumInputs(), 3);
    ASSERT_EQUAL(fifthVertexShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(fifthVertexShader->GetNumConstants(), 4);
    ASSERT_EQUAL(fifthVertexShader->GetNumSamplers(), 6);
    ASSERT_EQUAL(fifthVertexShader->GetName(), "VertexShader");

    for (int i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(firstVertexShader->GetInputName(i), "VertexInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fourthVertexShader->GetInputName(i), "VertexInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fifthVertexShader->GetInputName(i), "VertexInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(secondVertexShader->GetInputName(i), sixthVertexShader->GetInputName(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetInputType(i), sixthVertexShader->GetInputType(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetInputSemantic(i), sixthVertexShader->GetInputSemantic(i));

        ASSERT_EQUAL(thirdVertexShader->GetInputName(i), sixthVertexShader->GetInputName(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetInputType(i), sixthVertexShader->GetInputType(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetInputSemantic(i), sixthVertexShader->GetInputSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_EQUAL(firstVertexShader->GetOutputName(i), "VertexOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fourthVertexShader->GetOutputName(i), "VertexOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fifthVertexShader->GetOutputName(i), "VertexOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(secondVertexShader->GetOutputName(i), sixthVertexShader->GetOutputName(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetOutputType(i), sixthVertexShader->GetOutputType(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetOutputSemantic(i), sixthVertexShader->GetOutputSemantic(i));

        ASSERT_EQUAL(thirdVertexShader->GetOutputName(i), sixthVertexShader->GetOutputName(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetOutputType(i), sixthVertexShader->GetOutputType(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetOutputSemantic(i), sixthVertexShader->GetOutputSemantic(i));
    }

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(firstVertexShader->GetConstantName(i), "VertexConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(firstVertexShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(fourthVertexShader->GetConstantName(i), "VertexConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fourthVertexShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(fifthVertexShader->GetConstantName(i), "VertexConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fifthVertexShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(secondVertexShader->GetConstantName(i), sixthVertexShader->GetConstantName(i));
        ASSERT_EQUAL(secondVertexShader->GetNumRegistersUsed(i), sixthVertexShader->GetNumRegistersUsed(i));

        ASSERT_EQUAL(thirdVertexShader->GetConstantName(i), sixthVertexShader->GetConstantName(i));
        ASSERT_EQUAL(thirdVertexShader->GetNumRegistersUsed(i), sixthVertexShader->GetNumRegistersUsed(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        ASSERT_EQUAL(firstVertexShader->GetSamplerName(i), "VertexTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstVertexShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(firstVertexShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(firstVertexShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVertexShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(fourthVertexShader->GetSamplerName(i), "VertexTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthVertexShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(fourthVertexShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(fourthVertexShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fourthVertexShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(fifthVertexShader->GetSamplerName(i), "VertexTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthVertexShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(fifthVertexShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(fifthVertexShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fifthVertexShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(secondVertexShader->GetSamplerName(i), sixthVertexShader->GetSamplerName(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetSamplerType(i), sixthVertexShader->GetSamplerType(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetFilter(i), sixthVertexShader->GetFilter(i));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetCoordinate(i, 0), sixthVertexShader->GetCoordinate(i, 0));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetCoordinate(i, 1), sixthVertexShader->GetCoordinate(i, 1));
        ASSERT_ENUM_EQUAL(secondVertexShader->GetCoordinate(i, 2), sixthVertexShader->GetCoordinate(i, 2));
        ASSERT_APPROXIMATE(secondVertexShader->GetLodBias(i), sixthVertexShader->GetLodBias(i), 1e-8f);
        ASSERT_APPROXIMATE(secondVertexShader->GetAnisotropy(i), sixthVertexShader->GetAnisotropy(i), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, secondVertexShader->GetBorderColor(i), sixthVertexShader->GetBorderColor(i), 1e-8f);

        ASSERT_EQUAL(thirdVertexShader->GetSamplerName(i), sixthVertexShader->GetSamplerName(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetSamplerType(i), sixthVertexShader->GetSamplerType(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetFilter(i), sixthVertexShader->GetFilter(i));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetCoordinate(i, 0), sixthVertexShader->GetCoordinate(i, 0));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetCoordinate(i, 1), sixthVertexShader->GetCoordinate(i, 1));
        ASSERT_ENUM_EQUAL(thirdVertexShader->GetCoordinate(i, 2), sixthVertexShader->GetCoordinate(i, 2));
        ASSERT_APPROXIMATE(thirdVertexShader->GetLodBias(i), sixthVertexShader->GetLodBias(i), 1e-8f);
        ASSERT_APPROXIMATE(thirdVertexShader->GetAnisotropy(i), sixthVertexShader->GetAnisotropy(i), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, thirdVertexShader->GetBorderColor(i), sixthVertexShader->GetBorderColor(i), 1e-8f);
    }

    for (int i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
        {
            ASSERT_EQUAL(firstVertexShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(secondVertexShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(thirdVertexShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(fourthVertexShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(fifthVertexShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
        }

        for (int textureUnitIndex = 0; textureUnitIndex < 6; ++textureUnitIndex)
        {
            ASSERT_EQUAL(firstVertexShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(secondVertexShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(thirdVertexShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(fourthVertexShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(fifthVertexShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
        }

        ASSERT_EQUAL(firstVertexShader->GetProfile()->GetProgram(i), "VertexProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(secondVertexShader->GetProfile()->GetProgram(i), "VertexProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(thirdVertexShader->GetProfile()->GetProgram(i), "VertexProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fourthVertexShader->GetProfile()->GetProgram(i), "VertexProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fifthVertexShader->GetProfile()->GetProgram(i), "VertexProgram" + boost::lexical_cast<string>(i));
    }
}

void Rendering::LoadVisualEffectTesting::PixelShaderTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstPixelShaderSharedPtr firstPixelShader = visualEffect->GetPixelShader(0, 0);
    ConstPixelShaderSharedPtr secondPixelShader = visualEffect->GetPixelShader(0, 1);
    ConstPixelShaderSharedPtr thirdPixelShader = visualEffect->GetPixelShader(1, 0);
    ConstPixelShaderSharedPtr fourthPixelShader = visualEffect->GetPixelShader(1, 1);
    ConstPixelShaderSharedPtr fifthPixelShader = visualEffect->GetPixelShader(1, 2);
    ConstPixelShaderSharedPtr sixthPixelShader(new PixelShader("PixelShader2", 2, 8, 6, 7));

    ASSERT_EQUAL(firstPixelShader->GetNumInputs(), 4);
    ASSERT_EQUAL(firstPixelShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(firstPixelShader->GetNumConstants(), 6);
    ASSERT_EQUAL(firstPixelShader->GetNumSamplers(), 7);
    ASSERT_EQUAL(firstPixelShader->GetName(), "PixelShader");

    ASSERT_EQUAL(secondPixelShader->GetNumInputs(), 2);
    ASSERT_EQUAL(secondPixelShader->GetNumOutputs(), 8);
    ASSERT_EQUAL(secondPixelShader->GetNumConstants(), 6);
    ASSERT_EQUAL(secondPixelShader->GetNumSamplers(), 7);
    ASSERT_EQUAL(secondPixelShader->GetName(), "PixelShader2");

    ASSERT_EQUAL(thirdPixelShader->GetNumInputs(), 2);
    ASSERT_EQUAL(thirdPixelShader->GetNumOutputs(), 8);
    ASSERT_EQUAL(thirdPixelShader->GetNumConstants(), 6);
    ASSERT_EQUAL(thirdPixelShader->GetNumSamplers(), 7);
    ASSERT_EQUAL(thirdPixelShader->GetName(), "PixelShader2");

    ASSERT_EQUAL(fourthPixelShader->GetNumInputs(), 4);
    ASSERT_EQUAL(fourthPixelShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(fourthPixelShader->GetNumConstants(), 6);
    ASSERT_EQUAL(fourthPixelShader->GetNumSamplers(), 7);
    ASSERT_EQUAL(fourthPixelShader->GetName(), "PixelShader");

    ASSERT_EQUAL(fifthPixelShader->GetNumInputs(), 4);
    ASSERT_EQUAL(fifthPixelShader->GetNumOutputs(), 5);
    ASSERT_EQUAL(fifthPixelShader->GetNumConstants(), 6);
    ASSERT_EQUAL(fifthPixelShader->GetNumSamplers(), 7);
    ASSERT_EQUAL(fifthPixelShader->GetName(), "PixelShader");

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(firstPixelShader->GetInputName(i), "PixelInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fourthPixelShader->GetInputName(i), "PixelInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fifthPixelShader->GetInputName(i), "PixelInput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetInputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetInputSemantic(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 2; ++i)
    {
        ASSERT_EQUAL(secondPixelShader->GetInputName(i), sixthPixelShader->GetInputName(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetInputType(i), sixthPixelShader->GetInputType(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetInputSemantic(i), sixthPixelShader->GetInputSemantic(i));

        ASSERT_EQUAL(thirdPixelShader->GetInputName(i), sixthPixelShader->GetInputName(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetInputType(i), sixthPixelShader->GetInputType(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetInputSemantic(i), sixthPixelShader->GetInputSemantic(i));
    }

    for (int i = 0; i < 5; ++i)
    {
        ASSERT_EQUAL(firstPixelShader->GetOutputName(i), "PixelOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fourthPixelShader->GetOutputName(i), "PixelOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));

        ASSERT_EQUAL(fifthPixelShader->GetOutputName(i), "PixelOutput" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetOutputType(i), ShaderFlags::VariableType(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetOutputSemantic(i), ShaderFlags::VariableSemantic(i));
    }

    for (int i = 0; i < 8; ++i)
    {
        ASSERT_EQUAL(secondPixelShader->GetOutputName(i), sixthPixelShader->GetOutputName(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetOutputType(i), sixthPixelShader->GetOutputType(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetOutputSemantic(i), sixthPixelShader->GetOutputSemantic(i));

        ASSERT_EQUAL(thirdPixelShader->GetOutputName(i), sixthPixelShader->GetOutputName(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetOutputType(i), sixthPixelShader->GetOutputType(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetOutputSemantic(i), sixthPixelShader->GetOutputSemantic(i));
    }

    for (int i = 0; i < 6; ++i)
    {
        ASSERT_EQUAL(firstPixelShader->GetConstantName(i), "PixelConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(firstPixelShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(fourthPixelShader->GetConstantName(i), "PixelConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fourthPixelShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(fifthPixelShader->GetConstantName(i), "PixelConstant" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fifthPixelShader->GetNumRegistersUsed(i), i);

        ASSERT_EQUAL(secondPixelShader->GetConstantName(i), sixthPixelShader->GetConstantName(i));
        ASSERT_EQUAL(secondPixelShader->GetNumRegistersUsed(i), sixthPixelShader->GetNumRegistersUsed(i));

        ASSERT_EQUAL(thirdPixelShader->GetConstantName(i), sixthPixelShader->GetConstantName(i));
        ASSERT_EQUAL(thirdPixelShader->GetNumRegistersUsed(i), sixthPixelShader->GetNumRegistersUsed(i));
    }

    for (int i = 0; i < 7; ++i)
    {
        ASSERT_EQUAL(firstPixelShader->GetSamplerName(i), "PixelTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(firstPixelShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(firstPixelShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(firstPixelShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstPixelShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(fourthPixelShader->GetSamplerName(i), "PixelTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fourthPixelShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(fourthPixelShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(fourthPixelShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fourthPixelShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(fifthPixelShader->GetSamplerName(i), "PixelTexture" + boost::lexical_cast<string>(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetSamplerType(i), ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetFilter(i), ShaderFlags::SamplerFilter(i));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetCoordinate(i, 0), ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetCoordinate(i, 1), ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_ENUM_EQUAL(fifthPixelShader->GetCoordinate(i, 2), ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
        ASSERT_APPROXIMATE(fifthPixelShader->GetLodBias(i), static_cast<float>(i), 1e-8f);
        ASSERT_APPROXIMATE(fifthPixelShader->GetAnisotropy(i), static_cast<float>(i * 2.0f), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fifthPixelShader->GetBorderColor(i),
                                        Colour<float>(static_cast<float>(i) / 10.0f, static_cast<float>(i + 1) / 10.0f,
                                                      static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f),
                                        1e-8f);

        ASSERT_EQUAL(secondPixelShader->GetSamplerName(i), sixthPixelShader->GetSamplerName(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetSamplerType(i), sixthPixelShader->GetSamplerType(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetFilter(i), sixthPixelShader->GetFilter(i));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetCoordinate(i, 0), sixthPixelShader->GetCoordinate(i, 0));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetCoordinate(i, 1), sixthPixelShader->GetCoordinate(i, 1));
        ASSERT_ENUM_EQUAL(secondPixelShader->GetCoordinate(i, 2), sixthPixelShader->GetCoordinate(i, 2));
        ASSERT_APPROXIMATE(secondPixelShader->GetLodBias(i), sixthPixelShader->GetLodBias(i), 1e-8f);
        ASSERT_APPROXIMATE(secondPixelShader->GetAnisotropy(i), sixthPixelShader->GetAnisotropy(i), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, secondPixelShader->GetBorderColor(i), sixthPixelShader->GetBorderColor(i), 1e-8f);

        ASSERT_EQUAL(thirdPixelShader->GetSamplerName(i), sixthPixelShader->GetSamplerName(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetSamplerType(i), sixthPixelShader->GetSamplerType(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetFilter(i), sixthPixelShader->GetFilter(i));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetCoordinate(i, 0), sixthPixelShader->GetCoordinate(i, 0));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetCoordinate(i, 1), sixthPixelShader->GetCoordinate(i, 1));
        ASSERT_ENUM_EQUAL(thirdPixelShader->GetCoordinate(i, 2), sixthPixelShader->GetCoordinate(i, 2));
        ASSERT_APPROXIMATE(thirdPixelShader->GetLodBias(i), sixthPixelShader->GetLodBias(i), 1e-8f);
        ASSERT_APPROXIMATE(thirdPixelShader->GetAnisotropy(i), sixthPixelShader->GetAnisotropy(i), 1e-8f);
        ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, thirdPixelShader->GetBorderColor(i), sixthPixelShader->GetBorderColor(i), 1e-8f);
    }

    for (int i = 0; i < System::EnumCastUnderlying(ShaderFlags::Profiles::MaxProfiles); ++i)
    {
        for (int registerIndex = 0; registerIndex < 6; ++registerIndex)
        {
            ASSERT_EQUAL(firstPixelShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(secondPixelShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(thirdPixelShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(fourthPixelShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
            ASSERT_EQUAL(fifthPixelShader->GetProfile()->GetBaseRegister(i, registerIndex), i * 10 + registerIndex);
        }

        for (int textureUnitIndex = 0; textureUnitIndex < 7; ++textureUnitIndex)
        {
            ASSERT_EQUAL(firstPixelShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(secondPixelShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(thirdPixelShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(fourthPixelShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
            ASSERT_EQUAL(fifthPixelShader->GetProfile()->GetTextureUnit(i, textureUnitIndex), i * 10 + textureUnitIndex);
        }

        ASSERT_EQUAL(firstPixelShader->GetProfile()->GetProgram(i), "PixelProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(secondPixelShader->GetProfile()->GetProgram(i), "PixelProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(thirdPixelShader->GetProfile()->GetProgram(i), "PixelProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fourthPixelShader->GetProfile()->GetProgram(i), "PixelProgram" + boost::lexical_cast<string>(i));
        ASSERT_EQUAL(fifthPixelShader->GetProfile()->GetProgram(i), "PixelProgram" + boost::lexical_cast<string>(i));
    }
}

void Rendering::LoadVisualEffectTesting::AlphaStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstAlphaStateSharedPtr firstAlphaState = visualEffect->GetAlphaState(0, 0);
    ConstAlphaStateSharedPtr secondAlphaState = visualEffect->GetAlphaState(0, 1);
    ConstAlphaStateSharedPtr thirdAlphaState = visualEffect->GetAlphaState(1, 0);
    ConstAlphaStateSharedPtr fourthAlphaState = visualEffect->GetAlphaState(1, 1);
    ConstAlphaStateSharedPtr fifthAlphaState = visualEffect->GetAlphaState(1, 2);
    ConstAlphaStateSharedPtr sixthAlphaState(new AlphaState);

    ASSERT_TRUE(firstAlphaState->IsBlendEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::SourceBlendMode::DestinationColor, firstAlphaState->GetSourceBlend());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::DestinationBlendMode::One, firstAlphaState->GetDestinationBlend());
    ASSERT_TRUE(firstAlphaState->IsCompareEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::CompareMode::Less, firstAlphaState->GetCompare());
    ASSERT_APPROXIMATE(0.5f, firstAlphaState->GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstAlphaState->GetConstantColor(), Colour<float>(0.5f, 0.1f, 0.4f, 0.2f), 1e-8f);

    ASSERT_TRUE(fourthAlphaState->IsBlendEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::SourceBlendMode::DestinationColor, fourthAlphaState->GetSourceBlend());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::DestinationBlendMode::One, fourthAlphaState->GetDestinationBlend());
    ASSERT_TRUE(fourthAlphaState->IsCompareEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::CompareMode::Less, fourthAlphaState->GetCompare());
    ASSERT_APPROXIMATE(0.5f, firstAlphaState->GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fourthAlphaState->GetConstantColor(), Colour<float>(0.5f, 0.1f, 0.4f, 0.2f), 1e-8f);

    ASSERT_TRUE(fifthAlphaState->IsBlendEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::SourceBlendMode::DestinationColor, fifthAlphaState->GetSourceBlend());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::DestinationBlendMode::One, fifthAlphaState->GetDestinationBlend());
    ASSERT_TRUE(fifthAlphaState->IsCompareEnabled());
    ASSERT_ENUM_EQUAL(AlphaStateFlags::CompareMode::Less, fifthAlphaState->GetCompare());
    ASSERT_APPROXIMATE(0.5f, fifthAlphaState->GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, fifthAlphaState->GetConstantColor(), Colour<float>(0.5f, 0.1f, 0.4f, 0.2f), 1e-8f);

    ASSERT_EQUAL(secondAlphaState->IsBlendEnabled(), sixthAlphaState->IsBlendEnabled());
    ASSERT_ENUM_EQUAL(secondAlphaState->GetSourceBlend(), sixthAlphaState->GetSourceBlend());
    ASSERT_ENUM_EQUAL(secondAlphaState->GetDestinationBlend(), sixthAlphaState->GetDestinationBlend());
    ASSERT_EQUAL(secondAlphaState->IsCompareEnabled(), sixthAlphaState->IsCompareEnabled());
    ASSERT_ENUM_EQUAL(secondAlphaState->GetCompare(), sixthAlphaState->GetCompare());
    ASSERT_APPROXIMATE(sixthAlphaState->GetReference(), secondAlphaState->GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, secondAlphaState->GetConstantColor(), sixthAlphaState->GetConstantColor(), 1e-8f);

    ASSERT_EQUAL(thirdAlphaState->IsBlendEnabled(), sixthAlphaState->IsBlendEnabled());
    ASSERT_ENUM_EQUAL(thirdAlphaState->GetSourceBlend(), sixthAlphaState->GetSourceBlend());
    ASSERT_ENUM_EQUAL(thirdAlphaState->GetDestinationBlend(), sixthAlphaState->GetDestinationBlend());
    ASSERT_EQUAL(thirdAlphaState->IsCompareEnabled(), sixthAlphaState->IsCompareEnabled());
    ASSERT_ENUM_EQUAL(thirdAlphaState->GetCompare(), sixthAlphaState->GetCompare());
    ASSERT_APPROXIMATE(sixthAlphaState->GetReference(), thirdAlphaState->GetReference(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, thirdAlphaState->GetConstantColor(), sixthAlphaState->GetConstantColor(), 1e-8f);
}

void Rendering::LoadVisualEffectTesting::CullStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstCullStateSharedPtr firstCullState = visualEffect->GetCullState(0, 0);
    ConstCullStateSharedPtr secondCullState = visualEffect->GetCullState(0, 1);
    ConstCullStateSharedPtr thirdCullState = visualEffect->GetCullState(1, 0);
    ConstCullStateSharedPtr fourthCullState = visualEffect->GetCullState(1, 1);
    ConstCullStateSharedPtr fifthCullState = visualEffect->GetCullState(1, 2);
    ConstCullStateSharedPtr sixthCullState(new CullState);

    ASSERT_FALSE(firstCullState->IsEnabled());
    ASSERT_FALSE(firstCullState->IsCCWOrder());

    ASSERT_FALSE(fourthCullState->IsEnabled());
    ASSERT_FALSE(fourthCullState->IsCCWOrder());

    ASSERT_FALSE(fifthCullState->IsEnabled());
    ASSERT_FALSE(fifthCullState->IsCCWOrder());

    ASSERT_EQUAL(secondCullState->IsEnabled(), sixthCullState->IsEnabled());
    ASSERT_EQUAL(secondCullState->IsCCWOrder(), sixthCullState->IsCCWOrder());

    ASSERT_EQUAL(thirdCullState->IsEnabled(), sixthCullState->IsEnabled());
    ASSERT_EQUAL(thirdCullState->IsCCWOrder(), sixthCullState->IsCCWOrder());
}

void Rendering::LoadVisualEffectTesting::DepthStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstDepthStateSharedPtr firstDepthState = visualEffect->GetDepthState(0, 0);
    ConstDepthStateSharedPtr secondDepthState = visualEffect->GetDepthState(0, 1);
    ConstDepthStateSharedPtr thirdDepthState = visualEffect->GetDepthState(1, 0);
    ConstDepthStateSharedPtr fourthDepthState = visualEffect->GetDepthState(1, 1);
    ConstDepthStateSharedPtr fifthDepthState = visualEffect->GetDepthState(1, 2);
    ConstDepthStateSharedPtr sixthDepthState(new DepthState);

    ASSERT_FALSE(firstDepthState->IsEnabled());
    ASSERT_FALSE(firstDepthState->IsWritable());
    ASSERT_ENUM_EQUAL(firstDepthState->GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);

    ASSERT_FALSE(fourthDepthState->IsEnabled());
    ASSERT_FALSE(fourthDepthState->IsWritable());
    ASSERT_ENUM_EQUAL(fourthDepthState->GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);

    ASSERT_FALSE(fifthDepthState->IsEnabled());
    ASSERT_FALSE(fifthDepthState->IsWritable());
    ASSERT_ENUM_EQUAL(fifthDepthState->GetCompare(), DepthStateFlags::CompareMode::GreaterEqual);

    ASSERT_EQUAL(secondDepthState->IsEnabled(), sixthDepthState->IsEnabled());
    ASSERT_EQUAL(secondDepthState->IsWritable(), sixthDepthState->IsWritable());
    ASSERT_ENUM_EQUAL(secondDepthState->GetCompare(), sixthDepthState->GetCompare());

    ASSERT_EQUAL(thirdDepthState->IsEnabled(), sixthDepthState->IsEnabled());
    ASSERT_EQUAL(thirdDepthState->IsWritable(), sixthDepthState->IsWritable());
    ASSERT_ENUM_EQUAL(thirdDepthState->GetCompare(), sixthDepthState->GetCompare());
}

void Rendering::LoadVisualEffectTesting::OffsetStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstOffsetStateSharedPtr firstOffsetState = visualEffect->GetOffsetState(0, 0);
    ConstOffsetStateSharedPtr secondOffsetState = visualEffect->GetOffsetState(0, 1);
    ConstOffsetStateSharedPtr thirdOffsetState = visualEffect->GetOffsetState(1, 0);
    ConstOffsetStateSharedPtr fourthOffsetState = visualEffect->GetOffsetState(1, 1);
    ConstOffsetStateSharedPtr fifthOffsetState = visualEffect->GetOffsetState(1, 2);
    ConstOffsetStateSharedPtr sixthOffsetState(new OffsetState);

    ASSERT_TRUE(firstOffsetState->IsFillEnabled());
    ASSERT_TRUE(firstOffsetState->IsLineEnabled());
    ASSERT_TRUE(firstOffsetState->IsPointEnabled());
    ASSERT_APPROXIMATE(firstOffsetState->GetScale(), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(firstOffsetState->GetBias(), 1.6f, 1e-8f);

    ASSERT_TRUE(fourthOffsetState->IsFillEnabled());
    ASSERT_TRUE(fourthOffsetState->IsLineEnabled());
    ASSERT_TRUE(fourthOffsetState->IsPointEnabled());
    ASSERT_APPROXIMATE(fourthOffsetState->GetScale(), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthOffsetState->GetBias(), 1.6f, 1e-8f);

    ASSERT_TRUE(fifthOffsetState->IsFillEnabled());
    ASSERT_TRUE(fifthOffsetState->IsLineEnabled());
    ASSERT_TRUE(fifthOffsetState->IsPointEnabled());
    ASSERT_APPROXIMATE(fifthOffsetState->GetScale(), 1.5f, 1e-8f);
    ASSERT_APPROXIMATE(fifthOffsetState->GetBias(), 1.6f, 1e-8f);

    ASSERT_EQUAL(secondOffsetState->IsFillEnabled(), sixthOffsetState->IsFillEnabled());
    ASSERT_EQUAL(secondOffsetState->IsLineEnabled(), sixthOffsetState->IsLineEnabled());
    ASSERT_EQUAL(secondOffsetState->IsPointEnabled(), sixthOffsetState->IsPointEnabled());
    ASSERT_APPROXIMATE(secondOffsetState->GetScale(), sixthOffsetState->GetScale(), 1e-8f);
    ASSERT_APPROXIMATE(secondOffsetState->GetBias(), sixthOffsetState->GetBias(), 1e-8f);

    ASSERT_EQUAL(thirdOffsetState->IsFillEnabled(), sixthOffsetState->IsFillEnabled());
    ASSERT_EQUAL(thirdOffsetState->IsLineEnabled(), sixthOffsetState->IsLineEnabled());
    ASSERT_EQUAL(thirdOffsetState->IsPointEnabled(), sixthOffsetState->IsPointEnabled());
    ASSERT_APPROXIMATE(thirdOffsetState->GetScale(), sixthOffsetState->GetScale(), 1e-8f);
    ASSERT_APPROXIMATE(thirdOffsetState->GetBias(), sixthOffsetState->GetBias(), 1e-8f);
}

void Rendering::LoadVisualEffectTesting::StencilStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstStencilStateSharedPtr firstStencilState = visualEffect->GetStencilState(0, 0);
    ConstStencilStateSharedPtr secondStencilState = visualEffect->GetStencilState(0, 1);
    ConstStencilStateSharedPtr thirdStencilState = visualEffect->GetStencilState(1, 0);
    ConstStencilStateSharedPtr fourthStencilState = visualEffect->GetStencilState(1, 1);
    ConstStencilStateSharedPtr fifthStencilState = visualEffect->GetStencilState(1, 2);
    ConstStencilStateSharedPtr sixthStencilState(new StencilState);

    ASSERT_TRUE(firstStencilState->IsEnabled());
    ASSERT_ENUM_EQUAL(firstStencilState->GetCompare(), StencilStateFlags::CompareMode::Greater);
    ASSERT_EQUAL(firstStencilState->GetReference(), 5u);
    ASSERT_EQUAL(firstStencilState->GetMask(), 0xFFFEEFFE);
    ASSERT_EQUAL(firstStencilState->GetWriteMask(), 0xFDFEEFFE);
    ASSERT_ENUM_EQUAL(firstStencilState->GetOnFail(), StencilStateFlags::OperationType::Invert);
    ASSERT_ENUM_EQUAL(firstStencilState->GetOnZFail(), StencilStateFlags::OperationType::Increment);
    ASSERT_ENUM_EQUAL(firstStencilState->GetOnZPass(), StencilStateFlags::OperationType::Zero);

    ASSERT_TRUE(fourthStencilState->IsEnabled());
    ASSERT_ENUM_EQUAL(fourthStencilState->GetCompare(), StencilStateFlags::CompareMode::Greater);
    ASSERT_EQUAL(fourthStencilState->GetReference(), 5u);
    ASSERT_EQUAL(fourthStencilState->GetMask(), 0xFFFEEFFE);
    ASSERT_EQUAL(fourthStencilState->GetWriteMask(), 0xFDFEEFFE);
    ASSERT_ENUM_EQUAL(fourthStencilState->GetOnFail(), StencilStateFlags::OperationType::Invert);
    ASSERT_ENUM_EQUAL(fourthStencilState->GetOnZFail(), StencilStateFlags::OperationType::Increment);
    ASSERT_ENUM_EQUAL(fourthStencilState->GetOnZPass(), StencilStateFlags::OperationType::Zero);

    ASSERT_TRUE(fifthStencilState->IsEnabled());
    ASSERT_ENUM_EQUAL(fifthStencilState->GetCompare(), StencilStateFlags::CompareMode::Greater);
    ASSERT_EQUAL(fifthStencilState->GetReference(), 5u);
    ASSERT_EQUAL(fifthStencilState->GetMask(), 0xFFFEEFFE);
    ASSERT_EQUAL(fifthStencilState->GetWriteMask(), 0xFDFEEFFE);
    ASSERT_ENUM_EQUAL(fifthStencilState->GetOnFail(), StencilStateFlags::OperationType::Invert);
    ASSERT_ENUM_EQUAL(fifthStencilState->GetOnZFail(), StencilStateFlags::OperationType::Increment);
    ASSERT_ENUM_EQUAL(fifthStencilState->GetOnZPass(), StencilStateFlags::OperationType::Zero);

    ASSERT_EQUAL(secondStencilState->IsEnabled(), sixthStencilState->IsEnabled());
    ASSERT_ENUM_EQUAL(secondStencilState->GetCompare(), sixthStencilState->GetCompare());
    ASSERT_EQUAL(secondStencilState->GetReference(), sixthStencilState->GetReference());
    ASSERT_EQUAL(secondStencilState->GetMask(), sixthStencilState->GetMask());
    ASSERT_EQUAL(secondStencilState->GetWriteMask(), sixthStencilState->GetWriteMask());
    ASSERT_ENUM_EQUAL(secondStencilState->GetOnFail(), sixthStencilState->GetOnFail());
    ASSERT_ENUM_EQUAL(secondStencilState->GetOnZFail(), sixthStencilState->GetOnZFail());
    ASSERT_ENUM_EQUAL(secondStencilState->GetOnZPass(), sixthStencilState->GetOnZPass());

    ASSERT_EQUAL(thirdStencilState->IsEnabled(), sixthStencilState->IsEnabled());
    ASSERT_ENUM_EQUAL(thirdStencilState->GetCompare(), sixthStencilState->GetCompare());
    ASSERT_EQUAL(thirdStencilState->GetReference(), sixthStencilState->GetReference());
    ASSERT_EQUAL(thirdStencilState->GetMask(), sixthStencilState->GetMask());
    ASSERT_EQUAL(thirdStencilState->GetWriteMask(), sixthStencilState->GetWriteMask());
    ASSERT_ENUM_EQUAL(thirdStencilState->GetOnFail(), sixthStencilState->GetOnFail());
    ASSERT_ENUM_EQUAL(thirdStencilState->GetOnZFail(), sixthStencilState->GetOnZFail());
    ASSERT_ENUM_EQUAL(thirdStencilState->GetOnZPass(), sixthStencilState->GetOnZPass());
}

void Rendering::LoadVisualEffectTesting::WireStateTest()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/LoadVisualEffect.trve"));

    ConstWireStateSharedPtr firstWireState = visualEffect->GetWireState(0, 0);
    ConstWireStateSharedPtr secondWireState = visualEffect->GetWireState(0, 1);
    ConstWireStateSharedPtr thirdWireState = visualEffect->GetWireState(1, 0);
    ConstWireStateSharedPtr fourthWireState = visualEffect->GetWireState(1, 1);
    ConstWireStateSharedPtr fifthWireState = visualEffect->GetWireState(1, 2);
    ConstWireStateSharedPtr sixthWireState(new WireState);

    ASSERT_TRUE(firstWireState->IsEnabled());
    ASSERT_TRUE(fourthWireState->IsEnabled());
    ASSERT_TRUE(fifthWireState->IsEnabled());
    ASSERT_EQUAL(secondWireState->IsEnabled(), sixthWireState->IsEnabled());
    ASSERT_EQUAL(thirdWireState->IsEnabled(), sixthWireState->IsEnabled());
}
