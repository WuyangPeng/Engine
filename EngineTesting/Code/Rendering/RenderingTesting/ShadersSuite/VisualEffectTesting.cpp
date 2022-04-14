// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:38)

#include "VisualEffectTesting.h"
#include "Rendering/Shaders/VisualEffect.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


#include "System/Helper/PragmaWarning/LexicalCast.h"

using std::string;
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26409)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualEffectTesting) 

void Rendering::VisualEffectTesting
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
 
void Rendering::VisualEffectTesting
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

	VisualPassSharedPtr secondVisualPass(new VisualPass);
	 
	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);

	firstVisualTechnique->InsertPass(firstVisualPass);
	firstVisualTechnique->InsertPass(secondVisualPass);

	VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique);

	secondVisualTechnique->InsertPass(secondVisualPass);
	secondVisualTechnique->InsertPass(firstVisualPass);
	secondVisualTechnique->InsertPass(firstVisualPass);

	VisualEffectSharedPtr visualEffect(new VisualEffect);

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

	ASSERT_EQUAL(visualEffect->GetVertexShader(0,0), vertexShader);
	ASSERT_EQUAL(visualEffect->GetPixelShader(0, 0), pixelShader);
	ASSERT_EQUAL(visualEffect->GetAlphaState(0, 0), alphaState);
	ASSERT_EQUAL(visualEffect->GetCullState(0, 0), cullState);
	ASSERT_EQUAL(visualEffect->GetDepthState(0, 0), depthState);
	ASSERT_EQUAL(visualEffect->GetOffsetState(0, 0), offsetState);
	ASSERT_EQUAL(visualEffect->GetStencilState(0, 0), stencilState);
	ASSERT_EQUAL(visualEffect->GetWireState(0, 0), wireState);

// 	ASSERT_TRUE(visualEffect->GetVertexShader(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetPixelShader(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetAlphaState(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetCullState(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetDepthState(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetOffsetState(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetStencilState(0, 1).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetWireState(0, 1).IsNullPtr());
// 
// 	ASSERT_TRUE(visualEffect->GetVertexShader(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetPixelShader(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetAlphaState(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetCullState(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetDepthState(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetOffsetState(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetStencilState(1, 0).IsNullPtr());
// 	ASSERT_TRUE(visualEffect->GetWireState(1, 0).IsNullPtr());

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

void Rendering::VisualEffectTesting
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

	VisualPassSharedPtr secondVisualPass(new VisualPass);

	VisualTechniqueSharedPtr firstVisualTechnique(new VisualTechnique);

	firstVisualTechnique->InsertPass(firstVisualPass);
	firstVisualTechnique->InsertPass(secondVisualPass);

	VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique);

	secondVisualTechnique->InsertPass(secondVisualPass);
	secondVisualTechnique->InsertPass(firstVisualPass);
	secondVisualTechnique->InsertPass(firstVisualPass);

	VisualEffectSharedPtr firstVisualEffect(new VisualEffect);
	firstVisualEffect->InsertTechnique(firstVisualTechnique);
	firstVisualEffect->InsertTechnique(secondVisualTechnique);

	VisualEffectSharedPtr secondVisualEffect(new VisualEffect(*firstVisualEffect));
	
	ASSERT_EQUAL(firstVisualEffect->GetNumTechniques(),secondVisualEffect->GetNumTechniques());
	
	 for (int i = 0;i < 2;++i)
	 {
		 ASSERT_EQUAL(firstVisualEffect->GetTechnique(i),
			          secondVisualEffect->GetTechnique(i));
		  ASSERT_EQUAL(firstVisualEffect->GetNumPasses(i),
			           secondVisualEffect->GetNumPasses(i));
	 }

	 for (int i = 0;i < 2;++i)
	 {
		 int max = 2;
		 if(i == 1)
			 max = 3;
		 for (int k = 0;k < max;++k)
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

void Rendering::VisualEffectTesting
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
// 	firstVisualTechnique->InsertPass(secondVisualPass);
// 
// 	VisualTechniqueSharedPtr secondVisualTechnique(new VisualTechnique);
// 
// 	secondVisualTechnique->InsertPass(secondVisualPass);
// 	secondVisualTechnique->InsertPass(firstVisualPass);
// 	secondVisualTechnique->InsertPass(firstVisualPass);
// 
// 	VisualEffectSharedPtr firstVisualEffect(new VisualEffect);
// 	firstVisualEffect->InsertTechnique(firstVisualTechnique);
// 	firstVisualEffect->InsertTechnique(secondVisualTechnique);
// 
// 	outTopLevel.Insert(firstVisualEffect);
// 
// 	CoreTools::BufferOutStream outStream(outTopLevel);
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 
// 	VisualEffectSharedPtr secondVisualEffect =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualEffectSharedPtr>();
// 
// 	ASSERT_EQUAL(firstVisualEffect->GetNumTechniques(),secondVisualEffect->GetNumTechniques());
// 	
// 	 for (int i = 0;i < 2;++i)
// 	 {
// 		  ASSERT_EQUAL(firstVisualEffect->GetNumPasses(i),
// 			           secondVisualEffect->GetNumPasses(i));
// 	 }
// 	
// 	// VertexShader
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,1),secondVisualEffect->GetVertexShader(0,1));
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(1,0),secondVisualEffect->GetVertexShader(1,0));
// 
// 	ASSERT_EQUAL(secondVisualEffect->GetVertexShader(0,0),secondVisualEffect->GetVertexShader(1,1));
// 	ASSERT_EQUAL(secondVisualEffect->GetVertexShader(1,2),secondVisualEffect->GetVertexShader(1,1));
// 
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetNumInputs(), secondVisualEffect->GetVertexShader(0,0)->GetNumInputs());
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetNumOutputs(), secondVisualEffect->GetVertexShader(0,0)->GetNumOutputs());
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetNumConstants(), secondVisualEffect->GetVertexShader(0,0)->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetNumSamplers(), secondVisualEffect->GetVertexShader(0,0)->GetNumSamplers());
// 		
// 	for (int i = 0; i < 3;++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetInputName(i), secondVisualEffect->GetVertexShader(0,0)->GetInputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetInputType(i), secondVisualEffect->GetVertexShader(0,0)->GetInputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetInputSemantic(i), secondVisualEffect->GetVertexShader(0,0)->GetInputSemantic(i));
// 	}
//  
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetOutputName(i), secondVisualEffect->GetVertexShader(0,0)->GetOutputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetOutputType(i), secondVisualEffect->GetVertexShader(0,0)->GetOutputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetOutputSemantic(i), secondVisualEffect->GetVertexShader(0,0)->GetOutputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetConstantName(i), secondVisualEffect->GetVertexShader(0,0)->GetConstantName(i));
// 		ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetNumRegistersUsed(i), secondVisualEffect->GetVertexShader(0,0)->GetNumRegistersUsed(i));
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetSamplerName(i), secondVisualEffect->GetVertexShader(0,0)->GetSamplerName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetSamplerType(i), secondVisualEffect->GetVertexShader(0,0)->GetSamplerType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetFilter(i), secondVisualEffect->GetVertexShader(0,0)->GetFilter(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 0), secondVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 0));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 1), secondVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 1));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 2), secondVisualEffect->GetVertexShader(0,0)->GetCoordinate(i, 2));
// 		ASSERT_APPROXIMATE(firstVisualEffect->GetVertexShader(0,0)->GetLodBias(i), secondVisualEffect->GetVertexShader(0,0)->GetLodBias(i), 1e-8f);
// 		ASSERT_APPROXIMATE(firstVisualEffect->GetVertexShader(0,0)->GetAnisotropy(i), secondVisualEffect->GetVertexShader(0,0)->GetAnisotropy(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualEffect->GetVertexShader(0,0)->GetBorderColor(i),
// 										secondVisualEffect->GetVertexShader(0,0)->GetBorderColor(i), 1e-8f);
// 	}
// 
// 	// PixelShader
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,1),secondVisualEffect->GetPixelShader(0,1));
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(1,0),secondVisualEffect->GetPixelShader(1,0));
// 
// 	ASSERT_EQUAL(secondVisualEffect->GetPixelShader(0,0),secondVisualEffect->GetPixelShader(1,1));
// 	ASSERT_EQUAL(secondVisualEffect->GetPixelShader(1,2),secondVisualEffect->GetPixelShader(1,1));
// 
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetNumInputs(), secondVisualEffect->GetPixelShader(0,0)->GetNumInputs());
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetNumOutputs(), secondVisualEffect->GetPixelShader(0,0)->GetNumOutputs());
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetNumConstants(), secondVisualEffect->GetPixelShader(0,0)->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetNumSamplers(), secondVisualEffect->GetPixelShader(0,0)->GetNumSamplers());
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetInputName(i), secondVisualEffect->GetPixelShader(0,0)->GetInputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetInputType(i), secondVisualEffect->GetPixelShader(0,0)->GetInputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetInputSemantic(i), secondVisualEffect->GetPixelShader(0,0)->GetInputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetOutputName(i), secondVisualEffect->GetPixelShader(0,0)->GetOutputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetOutputType(i), secondVisualEffect->GetPixelShader(0,0)->GetOutputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetOutputSemantic(i), secondVisualEffect->GetPixelShader(0,0)->GetOutputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetConstantName(i), secondVisualEffect->GetPixelShader(0,0)->GetConstantName(i));
// 		ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetNumRegistersUsed(i), secondVisualEffect->GetPixelShader(0,0)->GetNumRegistersUsed(i));
// 	}
// 
// 	for (int i = 0; i < 7; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetSamplerName(i), secondVisualEffect->GetPixelShader(0,0)->GetSamplerName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetSamplerType(i), secondVisualEffect->GetPixelShader(0,0)->GetSamplerType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetFilter(i), secondVisualEffect->GetPixelShader(0,0)->GetFilter(i));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 0), secondVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 0));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 1), secondVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 1));
// 		ASSERT_ENUM_EQUAL(firstVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 2), secondVisualEffect->GetPixelShader(0,0)->GetCoordinate(i, 2));
// 		ASSERT_APPROXIMATE(firstVisualEffect->GetPixelShader(0,0)->GetLodBias(i), secondVisualEffect->GetPixelShader(0,0)->GetLodBias(i), 1e-8f);
// 		ASSERT_APPROXIMATE(firstVisualEffect->GetPixelShader(0,0)->GetAnisotropy(i), secondVisualEffect->GetPixelShader(0,0)->GetAnisotropy(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualEffect->GetPixelShader(0,0)->GetBorderColor(i),
// 										secondVisualEffect->GetPixelShader(0,0)->GetBorderColor(i), 1e-8f);
// 	}
// 
// 	// AlphaState
// 	ASSERT_EQUAL(firstVisualEffect->GetAlphaState(0,1),secondVisualEffect->GetAlphaState(0,1));
// 	ASSERT_EQUAL(firstVisualEffect->GetAlphaState(1,0),secondVisualEffect->GetAlphaState(1,0));
// 
// 	ASSERT_EQUAL(secondVisualEffect->GetAlphaState(0,0),secondVisualEffect->GetAlphaState(1,1));
// 	ASSERT_EQUAL(secondVisualEffect->GetAlphaState(1,2),secondVisualEffect->GetAlphaState(1,1));
// 
// 	ASSERT_EQUAL(firstVisualEffect->GetAlphaState(0,0)->IsBlendEnabled(), secondVisualEffect->GetAlphaState(0,0)->IsBlendEnabled());
// 	ASSERT_ENUM_EQUAL(firstVisualEffect->GetAlphaState(0,0)->GetSourceBlend(), secondVisualEffect->GetAlphaState(0,0)->GetSourceBlend());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetAlphaState(0,0)->GetDestinationBlend(), secondVisualEffect->GetAlphaState(0,0)->GetDestinationBlend());
// 	 ASSERT_EQUAL(firstVisualEffect->GetAlphaState(0,0)->IsCompareEnabled(), secondVisualEffect->GetAlphaState(0,0)->IsCompareEnabled());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetAlphaState(0,0)->GetCompare(), secondVisualEffect->GetAlphaState(0,0)->GetCompare());
// 	 ASSERT_APPROXIMATE(firstVisualEffect->GetAlphaState(0,0)->GetReference(), secondVisualEffect->GetAlphaState(0,0)->GetReference(), 1e-8f);
// 	 ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualEffect->GetAlphaState(0,0)->GetConstantColor(),
// 			                         secondVisualEffect->GetAlphaState(0,0)->GetConstantColor(),1e-8f);
// 
// 	 // CullState
// 	 ASSERT_EQUAL(firstVisualEffect->GetCullState(0,1),secondVisualEffect->GetCullState(0,1));
// 	 ASSERT_EQUAL(firstVisualEffect->GetCullState(1,0),secondVisualEffect->GetCullState(1,0));
// 
// 	 ASSERT_EQUAL(secondVisualEffect->GetCullState(0,0),secondVisualEffect->GetCullState(1,1));
// 	 ASSERT_EQUAL(secondVisualEffect->GetCullState(1,2),secondVisualEffect->GetCullState(1,1));
// 
// 	 ASSERT_EQUAL(firstVisualEffect->GetCullState(0,0)->IsEnabled(), secondVisualEffect->GetCullState(0,0)->IsEnabled());
// 	 ASSERT_EQUAL(firstVisualEffect->GetCullState(0,0)->IsCCWOrder(), secondVisualEffect->GetCullState(0,0)->IsCCWOrder());
// 
// 	 // DepthState
// 	 ASSERT_EQUAL(firstVisualEffect->GetDepthState(0,1),secondVisualEffect->GetDepthState(0,1));
// 	 ASSERT_EQUAL(firstVisualEffect->GetDepthState(1,0),secondVisualEffect->GetDepthState(1,0));
// 
// 	 ASSERT_EQUAL(secondVisualEffect->GetDepthState(0,0),secondVisualEffect->GetDepthState(1,1));
// 	 ASSERT_EQUAL(secondVisualEffect->GetDepthState(1,2),secondVisualEffect->GetDepthState(1,1));
// 
// 
// 	 ASSERT_EQUAL(firstVisualEffect->GetDepthState(0,0)->IsEnabled(), secondVisualEffect->GetDepthState(0,0)->IsEnabled());
// 	 ASSERT_EQUAL(firstVisualEffect->GetDepthState(0,0)->IsWritable(), secondVisualEffect->GetDepthState(0,0)->IsWritable());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetDepthState(0,0)->GetCompare(), secondVisualEffect->GetDepthState(0,0)->GetCompare());
// 
// 	 // OffsetState
// 	 ASSERT_EQUAL(firstVisualEffect->GetOffsetState(0,1),secondVisualEffect->GetOffsetState(0,1));
// 	 ASSERT_EQUAL(firstVisualEffect->GetOffsetState(1,0),secondVisualEffect->GetOffsetState(1,0));
// 
// 	 ASSERT_EQUAL(secondVisualEffect->GetOffsetState(0,0),secondVisualEffect->GetOffsetState(1,1));
// 	 ASSERT_EQUAL(secondVisualEffect->GetOffsetState(1,2),secondVisualEffect->GetOffsetState(1,1)); 
// 
// 	 ASSERT_EQUAL(firstVisualEffect->GetOffsetState(0,0)->IsFillEnabled(), secondVisualEffect->GetOffsetState(0,0)->IsFillEnabled());
// 	 ASSERT_EQUAL(firstVisualEffect->GetOffsetState(0,0)->IsLineEnabled(), secondVisualEffect->GetOffsetState(0,0)->IsLineEnabled());
// 	 ASSERT_EQUAL(firstVisualEffect->GetOffsetState(0,0)->IsPointEnabled(), secondVisualEffect->GetOffsetState(0,0)->IsPointEnabled());
// 	 ASSERT_APPROXIMATE(firstVisualEffect->GetOffsetState(0,0)->GetScale(), secondVisualEffect->GetOffsetState(0,0)->GetScale(), 1e-8f);
// 	 ASSERT_APPROXIMATE(firstVisualEffect->GetOffsetState(0,0)->GetBias(), secondVisualEffect->GetOffsetState(0,0)->GetBias(), 1e-8f);
// 
// 	 // StencilState
// 	  ASSERT_EQUAL(firstVisualEffect->GetStencilState(0,1),secondVisualEffect->GetStencilState(0,1));
// 	  ASSERT_EQUAL(firstVisualEffect->GetStencilState(1,0),secondVisualEffect->GetStencilState(1,0));
// 
// 	  ASSERT_EQUAL(secondVisualEffect->GetStencilState(0,0),secondVisualEffect->GetStencilState(1,1));
// 	  ASSERT_EQUAL(secondVisualEffect->GetStencilState(1,2),secondVisualEffect->GetStencilState(1,1)); 
// 
// 	 ASSERT_EQUAL(firstVisualEffect->GetStencilState(0,0)->IsEnabled(), secondVisualEffect->GetStencilState(0,0)->IsEnabled());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetCompare(), secondVisualEffect->GetStencilState(0,0)->GetCompare());
// 	 ASSERT_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetReference(), secondVisualEffect->GetStencilState(0,0)->GetReference());
// 	 ASSERT_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetMask(), secondVisualEffect->GetStencilState(0,0)->GetMask());
// 	 ASSERT_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetWriteMask(), secondVisualEffect->GetStencilState(0,0)->GetWriteMask());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetOnFail(), secondVisualEffect->GetStencilState(0,0)->GetOnFail());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetOnZFail(), secondVisualEffect->GetStencilState(0,0)->GetOnZFail());
// 	 ASSERT_ENUM_EQUAL(firstVisualEffect->GetStencilState(0,0)->GetOnZPass(), secondVisualEffect->GetStencilState(0,0)->GetOnZPass());
// 	 
// 	 // WireState	 
// 	 ASSERT_EQUAL(firstVisualEffect->GetWireState(0,1),secondVisualEffect->GetWireState(0,1));
// 	 ASSERT_EQUAL(firstVisualEffect->GetWireState(1,0),secondVisualEffect->GetWireState(1,0));
// 	 
// 	 ASSERT_EQUAL(secondVisualEffect->GetWireState(0,0),secondVisualEffect->GetWireState(1,1));
// 	 ASSERT_EQUAL(secondVisualEffect->GetWireState(1,2),secondVisualEffect->GetWireState(1,1)); 
// 
// 	 ASSERT_EQUAL(firstVisualEffect->GetWireState(0,0)->IsEnabled(), secondVisualEffect->GetWireState(0,0)->IsEnabled()); 

}
