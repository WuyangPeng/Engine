// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:30)

#include "SaveVisualEffectTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Shaders/LoadVisualEffect.h"
#include "Rendering/Shaders/SaveVisualEffect.h"

#include "CoreTools/FileManager/IFStreamManager.h"

#include "System/Helper/PragmaWarning/LexicalCast.h"

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
    // 	 VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5,4, 6));
    //
    // 	for (int i = 0; i < 3; ++i)
    // 	{
    // 		vertexShader->SetInput(i, "VertexInput" + boost::lexical_cast<string>(i),
    // 			                   ShaderFlags::VariableType(i),ShaderFlags::VariableSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 5; ++i)
    // 	{
    // 		vertexShader->SetOutput(i, "VertexOutput" + boost::lexical_cast<string>(i),
    // 			                    ShaderFlags::VariableType(i),ShaderFlags::VariableSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 4; ++i)
    // 	{
    // 		vertexShader->SetConstant(i, "VertexConstant" + boost::lexical_cast<string>(i),i);
    // 	}
    //
    // 	for (int i = 0; i < 6; ++i)
    // 	{
    // 		vertexShader->SetSampler(i, "VertexTexture" + boost::lexical_cast<string>(i),ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		vertexShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
    // 		vertexShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		vertexShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		vertexShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    //
    // 		vertexShader->SetLodBias(i,static_cast<float>(i));
    // 		vertexShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
    // 		vertexShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,static_cast<float>(i + 1) / 10.0f,
    // 													  static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    // 	}
    //
    // 	ShaderProfileDataSharedPtr vertexProfile(new ShaderProfileData(4, 6));
    //
    // 	for (int i = 0; i < ShaderFlags::MaxProfiles;++i)
    // 	{
    // 		for (int registerIndex = 0; registerIndex < 4;++registerIndex)
    // 		{
    // 			vertexProfile->SetBaseRegister(i, registerIndex, i * 10 + registerIndex);
    // 		}
    //
    // 		for (int textureUnitIndex = 0; textureUnitIndex < 6; ++textureUnitIndex)
    // 		{
    // 			vertexProfile->SetTextureUnit(i, textureUnitIndex, i * 10 + textureUnitIndex);
    // 		}
    //
    // 		vertexProfile->SetProgram(i, "VertexProgram" + boost::lexical_cast<string>(i));
    // 	}
    //
    // 	vertexShader->SetProfile(vertexProfile);
    //
    // 	PixelShaderSharedPtr pixelShader(new PixelShader("PixelShader", 4, 5, 6, 7));
    //
    // 	for (int i = 0; i < 4; ++i)
    // 	{
    // 		pixelShader->SetInput(i, "PixelInput" + boost::lexical_cast<string>(i),
    // 			                  ShaderFlags::VariableType(i),ShaderFlags::VariableSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 5; ++i)
    // 	{
    // 		pixelShader->SetOutput(i, "PixelOutput" + boost::lexical_cast<string>(i),
    // 			                   ShaderFlags::VariableType(i),ShaderFlags::VariableSemantic(i));
    // 	}
    //
    // 	for (int i = 0; i < 6; ++i)
    // 	{
    // 		pixelShader->SetConstant(i, "PixelConstant" + boost::lexical_cast<string>(i),i);
    // 	}
    //
    // 	for (int i = 0; i < 7; ++i)
    // 	{
    // 		pixelShader->SetSampler(i, "PixelTexture" + boost::lexical_cast<string>(i),
    // 			                    ShaderFlags::SamplerType(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		pixelShader->SetFilter(i, ShaderFlags::SamplerFilter(i));
    // 		pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    // 		pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
    //
    // 		pixelShader->SetLodBias(i,static_cast<float>(i));
    // 		pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
    // 		pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,static_cast<float>(i + 1) / 10.0f,
    // 												     static_cast<float>(i + 2) / 10.0f, static_cast<float>(i + 3) / 10.0f));
    // 	}
    //
    // 	ShaderProfileDataSharedPtr pixelProfile(new ShaderProfileData(6, 7));
    //
    // 	for (int i = 0; i < ShaderFlags::MaxProfiles; ++i)
    // 	{
    // 		for (int registerIndex = 0; registerIndex < 6; ++registerIndex)
    // 		{
    // 			pixelProfile->SetBaseRegister(i, registerIndex, i * 10 + registerIndex);
    // 		}
    //
    // 		for (int textureUnitIndex = 0; textureUnitIndex < 7; ++textureUnitIndex)
    // 		{
    // 			pixelProfile->SetTextureUnit(i, textureUnitIndex, i * 10 + textureUnitIndex);
    // 		}
    //
    // 		pixelProfile->SetProgram(i, "PixelProgram" + boost::lexical_cast<string>(i));
    // 	}
    //
    // 	pixelShader->SetProfile(pixelProfile);
    //
    // 	AlphaStateSharedPtr alphaState(new AlphaState);
    // 	alphaState->SetBlendEnabled(true);
    // 	alphaState->SetSourceBlend(AlphaStateFlags::SourceBlendMode::DestinationColor);
    // 	alphaState->SetDestinationBlend(AlphaStateFlags::DestinationBlendMode::One);
    // 	alphaState->SetCompareEnabled(true);
    // 	alphaState->SetCompare(AlphaStateFlags::CompareMode::Less);
    // 	alphaState->SetReference(0.5f);
    // 	alphaState->SetConstantColor(Colour<float>(0.5f, 0.1f, 0.4f, 0.2f));
    //
    // 	CullStateSharedPtr cullState(new CullState);
    //
    // 	cullState->SetEnabled(false);
    // 	cullState->SetCCWOrder(false);
    //
    // 	DepthStateSharedPtr depthState(new DepthState);
    // 	depthState->SetEnabled(false);
    // 	depthState->SetWritable(false);
    // 	depthState->SetCompare(DepthStateFlags::CompareMode::GreaterEqual);
    //
    // 	OffsetStateSharedPtr offsetState(new OffsetState);
    //
    // 	offsetState->SetFillEnabled(true);
    // 	offsetState->SetLineEnabled(true);
    // 	offsetState->SetPointEnabled(true);
    // 	offsetState->SetScale(1.5f);
    // 	offsetState->SetBias(1.6f);
    //
    // 	StencilStateSharedPtr stencilState(new StencilState);
    //
    // 	stencilState->SetEnabled(true);
    // 	stencilState->SetCompare(StencilStateFlags::CompareMode::Greater);
    // 	stencilState->SetReference(5);
    // 	stencilState->SetMask(0xFFFEEFFE);
    // 	stencilState->SetWriteMask(0xFDFEEFFE);
    // 	stencilState->SetOnFail(StencilStateFlags::OperationType::Invert);
    // 	stencilState->SetOnZFail(StencilStateFlags::OperationType::Increment);
    // 	stencilState->SetOnZPass(StencilStateFlags::OperationType::Zero);
    //
    // 	WireStateSharedPtr wireState(new WireState);
    //
    // 	wireState->SetEnabled(true);
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
    // 	VertexShaderSharedPtr secondVertexShader(new VertexShader("VertexShader", 2, 3, 4, 6));
    // 	secondVertexShader->SetProfile(vertexProfile);
    // 	PixelShaderSharedPtr secondPixelShader(new PixelShader("PixelShader", 2, 5, 6, 7));
    // 	secondPixelShader->SetProfile(pixelProfile);
    //
    // 	secondVisualPass->SetVertexShader(secondVertexShader);
    // 	secondVisualPass->SetPixelShader(secondPixelShader);
    // 	secondVisualPass->SetAlphaState(AlphaStateSharedPtr(new AlphaState));
    // 	secondVisualPass->SetCullState(CullStateSharedPtr(new CullState));
    // 	secondVisualPass->SetDepthState(DepthStateSharedPtr(new DepthState));
    // 	secondVisualPass->SetOffsetState(OffsetStateSharedPtr(new OffsetState));
    // 	secondVisualPass->SetStencilState(StencilStateSharedPtr(new StencilState));
    // 	secondVisualPass->SetWireState(WireStateSharedPtr(new WireState));
    //
    // 	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);
    //
    // 	firstVisualTechnique->InsertPass(firstVisualPass);
    // 	firstVisualTechnique->InsertPass(secondVisualPass);
    //
    // 	VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique);
    //
    // 	secondVisualTechnique->InsertPass(secondVisualPass);
    // 	secondVisualTechnique->InsertPass(firstVisualPass);
    // 	secondVisualTechnique->InsertPass(firstVisualPass);
    //
    // 	VisualEffectSharedPtr visualEffect(new VisualEffect);
    // 	visualEffect->InsertTechnique(firstVisualTechnique);
    // 	visualEffect->InsertTechnique(secondVisualTechnique);
    //
    // 	SaveVisualEffect saveVisualEffect(visualEffect,SYSTEM_TEXT("Resource/ShadersSuite/FirstSaveVisualEffect.trve"));
}

void Rendering::SaveVisualEffectTesting::SaveFile()
{
    VisualEffectSharedPtr visualEffect = LoadVisualEffect::Load(SYSTEM_TEXT("Resource/ShadersSuite/FirstSaveVisualEffect.trve"));

    const SaveVisualEffect saveVisualEffect(visualEffect, SYSTEM_TEXT("Resource/ShadersSuite/SecondSaveVisualEffect.trve"));
}

void Rendering::SaveVisualEffectTesting::SaveTest()
{
    CoreTools::IFStreamManager firstFile(SYSTEM_TEXT("Resource/ShadersSuite/FirstSaveVisualEffect.trve"));
    CoreTools::IFStreamManager secondFile(SYSTEM_TEXT("Resource/ShadersSuite/SecondSaveVisualEffect.trve"));

    ASSERT_EQUAL(firstFile.GetFileContent(), secondFile.GetFileContent());
}
