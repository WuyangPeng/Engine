// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:38)

#include "VisualEffectInstanceTesting.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Shaders/VisualEffectInstance.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


#include <boost/lexical_cast.hpp>

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualEffectInstanceTesting) 

void Rendering::VisualEffectInstanceTesting
	::MainTest()
{ 
	CoreTools::InitTerm::ExecuteInitializers();

	RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);

	RendererManager::Destroy();

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::VisualEffectInstanceTesting
	::InitTest()
{
	VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5,4, 6));

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

		vertexShader->SetLodBias(i,static_cast<float>(i));
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
		pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));

		pixelShader->SetLodBias(i,static_cast<float>(i));
		pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
		pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
			                                    static_cast<float>(i + 1) / 10.0f,
												static_cast<float>(i + 2) / 10.0f, 
												static_cast<float>(i + 3) / 10.0f));
	}

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
	 
	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);

	firstVisualTechnique->InsertPass(firstVisualPass);

	VisualEffectSharedPtr visualEffect(new VisualEffect); 

	visualEffect->InsertTechnique(firstVisualTechnique);

	VisualEffectInstanceSharedPtr visualEffectInstance(new VisualEffectInstance(visualEffect, 0));

	ASSERT_EQUAL(visualEffectInstance->GetEffect(), visualEffect);
	ASSERT_EQUAL(visualEffectInstance->GetTechniqueIndex(), 0);
	ASSERT_EQUAL(visualEffectInstance->GetNumPasses(), visualEffect->GetNumPasses(0));
	ASSERT_EQUAL(visualEffectInstance->GetConstPass(0), visualEffect->GetPass(0, 0));

	ConstShaderParametersSharedPtr firstConstShaderParameters = visualEffectInstance->GetVertexParameters(0);

	ASSERT_EQUAL(firstConstShaderParameters->GetNumConstants(), 4);
	ASSERT_EQUAL(firstConstShaderParameters->GetNumTextures(), 6);

	ConstShaderParametersSharedPtr secondConstShaderParameters = visualEffectInstance->GetPixelParameters(0);

	ASSERT_EQUAL(secondConstShaderParameters->GetNumConstants(), 6);
	ASSERT_EQUAL(secondConstShaderParameters->GetNumTextures(), 7);

	for (int i = 0; i < 4; i++)
	{
		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));
		
		visualEffectInstance->SetVertexConstant(0, "VertexConstant" + boost::lexical_cast<string>(i), firstShaderFloat);

		ASSERT_EQUAL(visualEffectInstance->GetVertexConstant(0, i), firstShaderFloat);

		ShaderFloatSharedPtr secondShaderFloat(new ShaderFloat((i + 1) * 4));

		visualEffectInstance->SetVertexConstant(0, i, secondShaderFloat);

		ASSERT_EQUAL(visualEffectInstance->GetVertexConstant(0, "VertexConstant" + boost::lexical_cast<string>(i)), secondShaderFloat);
	}

	for (int i = 0; i < 6; i++)
	{
		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));

		visualEffectInstance->SetPixelConstant(0, "PixelConstant" + boost::lexical_cast<string>(i), firstShaderFloat);

		ASSERT_EQUAL(visualEffectInstance->GetPixelConstant(0, i), firstShaderFloat);

		ShaderFloatSharedPtr secondShaderFloat(new ShaderFloat((i + 1) * 4));

		visualEffectInstance->SetPixelConstant(0, i, secondShaderFloat);

		ASSERT_EQUAL(visualEffectInstance->GetPixelConstant(0, "PixelConstant" + boost::lexical_cast<string>(i)), secondShaderFloat);
	}

	for (int i = 0; i < 6; i++)
	{
		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4,5,0));

		visualEffectInstance->SetVertexTexture(0, "VertexTexture" + boost::lexical_cast<string>(i), firstTexture);

		ASSERT_EQUAL(visualEffectInstance->GetVertexTexture(0, i), firstTexture);

		TextureSharedPtr secondTexture(new Texture1D(TextureFormat::A4R4G4B4, 6, 0));

		visualEffectInstance->SetVertexTexture(0, i, secondTexture);

		ASSERT_EQUAL(visualEffectInstance->GetVertexTexture(0, "VertexTexture" + boost::lexical_cast<string>(i)), secondTexture);
	}

	for (int i = 0; i < 7; i++)
	{
		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4, 5, 0));

		visualEffectInstance->SetPixelTexture(0, "PixelTexture" + boost::lexical_cast<string>(i), firstTexture);

		ASSERT_EQUAL(visualEffectInstance->GetPixelTexture(0, i), firstTexture);

		TextureSharedPtr secondTexture(new Texture1D(TextureFormat::A4R4G4B4, 6, 0));

		visualEffectInstance->SetPixelTexture(0, i, secondTexture);

		ASSERT_EQUAL(visualEffectInstance->GetPixelTexture(0, "PixelTexture" + boost::lexical_cast<string>(i)), secondTexture);
	}
}

void Rendering::VisualEffectInstanceTesting
	::CopyTest()
{ 
	VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5,4, 6));

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

		vertexShader->SetLodBias(i,static_cast<float>(i));
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
		pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));

		pixelShader->SetLodBias(i,static_cast<float>(i));
		pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
		pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
			                                    static_cast<float>(i + 1) / 10.0f,
												static_cast<float>(i + 2) / 10.0f, 
												static_cast<float>(i + 3) / 10.0f));
	}

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
	 
	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);

	firstVisualTechnique->InsertPass(firstVisualPass);	 

	VisualEffectSharedPtr firstVisualEffect(new VisualEffect);
	firstVisualEffect->InsertTechnique(firstVisualTechnique); 

	VisualEffectInstanceSharedPtr firstVisualEffectInstance(new VisualEffectInstance(firstVisualEffect, 0));

	for (int i = 0; i < 4; i++)
	{
		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));

		firstVisualEffectInstance->SetVertexConstant(0, "VertexConstant" + boost::lexical_cast<string>(i), firstShaderFloat);
	}

	for (int i = 0; i < 6; i++)
	{
		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));

		firstVisualEffectInstance->SetPixelConstant(0, "PixelConstant" + boost::lexical_cast<string>(i), firstShaderFloat);

	}

	for (int i = 0; i < 6; i++)
	{
		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4, 5, 0));

		firstVisualEffectInstance->SetVertexTexture(0, "VertexTexture" + boost::lexical_cast<string>(i), firstTexture);

	}

	for (int i = 0; i < 7; i++)
	{
		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4, 5, 0));

		firstVisualEffectInstance->SetPixelTexture(0, "PixelTexture" + boost::lexical_cast<string>(i), firstTexture);

	}

	VisualEffectInstanceSharedPtr secondVisualEffectInstance(new VisualEffectInstance(*firstVisualEffectInstance));

	ASSERT_EQUAL(firstVisualEffectInstance->GetEffect(), secondVisualEffectInstance->GetEffect());
	ASSERT_EQUAL(firstVisualEffectInstance->GetTechniqueIndex(), secondVisualEffectInstance->GetTechniqueIndex());
	ASSERT_EQUAL(firstVisualEffectInstance->GetNumPasses(), secondVisualEffectInstance->GetNumPasses());
	ASSERT_EQUAL(firstVisualEffectInstance->GetConstPass(0), secondVisualEffectInstance->GetConstPass(0));

	ASSERT_UNEQUAL(firstVisualEffectInstance->GetVertexParameters(0), secondVisualEffectInstance->GetVertexParameters(0));
	ASSERT_UNEQUAL(firstVisualEffectInstance->GetPixelParameters(0), secondVisualEffectInstance->GetPixelParameters(0));

	ASSERT_EQUAL(firstVisualEffectInstance->GetVertexParameters(0)->GetNumConstants(), secondVisualEffectInstance->GetVertexParameters(0)->GetNumConstants());
	ASSERT_EQUAL(firstVisualEffectInstance->GetVertexParameters(0)->GetNumTextures(), secondVisualEffectInstance->GetVertexParameters(0)->GetNumTextures());
	 
	ASSERT_EQUAL(firstVisualEffectInstance->GetPixelParameters(0)->GetNumConstants(), secondVisualEffectInstance->GetPixelParameters(0)->GetNumConstants());
	ASSERT_EQUAL(firstVisualEffectInstance->GetPixelParameters(0)->GetNumTextures(), secondVisualEffectInstance->GetPixelParameters(0)->GetNumTextures());
}

void Rendering::VisualEffectInstanceTesting
	::StreamTest()
{
 	VertexShaderSharedPtr vertexShader(new VertexShader("VertexShader", 3, 5,4, 6));

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

		vertexShader->SetLodBias(i,static_cast<float>(i));
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
		pixelShader->SetCoordinate(i, 0, ShaderFlags::SamplerCoordinate(i % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 1, ShaderFlags::SamplerCoordinate((i + 1) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));
		pixelShader->SetCoordinate(i, 2, ShaderFlags::SamplerCoordinate((i + 2) % System::EnumCastUnderlying(ShaderFlags::SamplerType::Quantity)));

		pixelShader->SetLodBias(i,static_cast<float>(i));
		pixelShader->SetAnisotropy(i, static_cast<float>(i * 2.0f));
		pixelShader->SetBorderColor(i, Colour<float>(static_cast<float>(i) / 10.0f,
			                                    static_cast<float>(i + 1) / 10.0f,
												static_cast<float>(i + 2) / 10.0f, 
												static_cast<float>(i + 3) / 10.0f));
	}

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
// 
// 	VisualEffectSharedPtr firstVisualEffect(new VisualEffect);
// 	firstVisualEffect->InsertTechnique(firstVisualTechnique);
// 
// 	VisualEffectInstanceSharedPtr firstVisualEffectInstance(new VisualEffectInstance(firstVisualEffect, 0));
// 
// 	for (int i = 0; i < 4; i++)
// 	{
// 		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));
// 
// 		firstVisualEffectInstance->SetVertexConstant(0, "VertexConstant" + boost::lexical_cast<string>(i), firstShaderFloat);
// 	}
// 
// 	for (int i = 0; i < 6; i++)
// 	{
// 		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat((i + 1) * 4));
// 
// 		firstVisualEffectInstance->SetPixelConstant(0, "PixelConstant" + boost::lexical_cast<string>(i), firstShaderFloat);
// 
// 	}
// 
// 	for (int i = 0; i < 6; i++)
// 	{
// 		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4, 5, 0));
// 
// 		firstVisualEffectInstance->SetVertexTexture(0, "VertexTexture" + boost::lexical_cast<string>(i), firstTexture);
// 
// 	}
// 
// 	for (int i = 0; i < 7; i++)
// 	{
// 		TextureSharedPtr firstTexture(new Texture1D(TextureFormat::A4R4G4B4, 5, 0));
// 
// 		firstVisualEffectInstance->SetPixelTexture(0, "PixelTexture" + boost::lexical_cast<string>(i), firstTexture);
// 
// 	}
// 
// 	outTopLevel.Insert(firstVisualEffectInstance);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	VisualEffectInstanceSharedPtr secondVisualEffectInstance = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualEffectInstanceSharedPtr>();
// 
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetTechniqueIndex(), secondVisualEffectInstance->GetTechniqueIndex());
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetNumPasses(), secondVisualEffectInstance->GetNumPasses());
// 	
// 	ASSERT_UNEQUAL(firstVisualEffectInstance->GetVertexParameters(0), secondVisualEffectInstance->GetVertexParameters(0));
// 	ASSERT_UNEQUAL(firstVisualEffectInstance->GetPixelParameters(0), secondVisualEffectInstance->GetPixelParameters(0));
// 
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetVertexParameters(0)->GetNumConstants(), secondVisualEffectInstance->GetVertexParameters(0)->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetVertexParameters(0)->GetNumTextures(), secondVisualEffectInstance->GetVertexParameters(0)->GetNumTextures());
// 
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetPixelParameters(0)->GetNumConstants(), secondVisualEffectInstance->GetPixelParameters(0)->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualEffectInstance->GetPixelParameters(0)->GetNumTextures(), secondVisualEffectInstance->GetPixelParameters(0)->GetNumTextures());

}
