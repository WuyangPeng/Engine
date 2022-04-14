// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/07 14:38)

#include "VisualPassTesting.h"
#include "Rendering/Shaders/VisualPass.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"


#include "System/Helper/PragmaWarning/LexicalCast.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, VisualPassTesting) 
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26409)
void Rendering::VisualPassTesting
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
 
void Rendering::VisualPassTesting
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

	VisualPass visualPass; 

// 	ASSERT_TRUE(visualPass.GetVertexShader().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetPixelShader().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetAlphaState().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetCullState().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetDepthState().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetOffsetState().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetStencilState().IsNullPtr());
// 	ASSERT_TRUE(visualPass.GetWireState().IsNullPtr()); 

	visualPass.SetVertexShader(vertexShader);
	visualPass.SetPixelShader( pixelShader);
	visualPass.SetAlphaState(alphaState);
	visualPass.SetCullState(cullState);
	visualPass.SetDepthState(depthState);
	visualPass.SetOffsetState(offsetState);
	visualPass.SetStencilState(stencilState);
	visualPass.SetWireState(wireState);

	ASSERT_EQUAL(visualPass.GetVertexShader(),vertexShader);
	ASSERT_EQUAL(visualPass.GetPixelShader(),pixelShader);
	ASSERT_EQUAL(visualPass.GetAlphaState(),alphaState);
	ASSERT_EQUAL(visualPass.GetCullState(),cullState);
	ASSERT_EQUAL(visualPass.GetDepthState(),depthState);
	ASSERT_EQUAL(visualPass.GetOffsetState(),offsetState);
	ASSERT_EQUAL(visualPass.GetStencilState(),stencilState);
	ASSERT_EQUAL(visualPass.GetWireState(),wireState);
}

void Rendering::VisualPassTesting
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

	VisualPass firstVisualPass;	

	firstVisualPass.SetVertexShader(vertexShader);
	firstVisualPass.SetPixelShader(pixelShader);
	firstVisualPass.SetAlphaState(alphaState);
	firstVisualPass.SetCullState(cullState);
	firstVisualPass.SetDepthState(depthState);
	firstVisualPass.SetOffsetState(offsetState);
	firstVisualPass.SetStencilState(stencilState);
	firstVisualPass.SetWireState(wireState);

	VisualPass secondVisualPass(firstVisualPass);

	ASSERT_EQUAL(firstVisualPass.GetVertexShader(), secondVisualPass.GetVertexShader());
	ASSERT_EQUAL(firstVisualPass.GetPixelShader(), secondVisualPass.GetPixelShader());
	ASSERT_EQUAL(firstVisualPass.GetAlphaState(), secondVisualPass.GetAlphaState());
	ASSERT_EQUAL(firstVisualPass.GetCullState(), secondVisualPass.GetCullState());
	ASSERT_EQUAL(firstVisualPass.GetDepthState(), secondVisualPass.GetDepthState());
	ASSERT_EQUAL(firstVisualPass.GetOffsetState(), secondVisualPass.GetOffsetState());
	ASSERT_EQUAL(firstVisualPass.GetStencilState(), secondVisualPass.GetStencilState());
	ASSERT_EQUAL(firstVisualPass.GetWireState(), secondVisualPass.GetWireState());

	secondVisualPass.SetAlphaState(AlphaStateSharedPtr());

	ASSERT_UNEQUAL(firstVisualPass.GetAlphaState(), secondVisualPass.GetAlphaState());

}

void Rendering::VisualPassTesting
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
// 	outTopLevel.Insert(firstVisualPass);
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
// 	VisualPassSharedPtr secondVisualPass =
// 		inTopLevel[0].PolymorphicDowncastObjectSharedPtr<VisualPassSharedPtr>();
// 
// 	// VertexShader
// 	ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetNumInputs(), secondVisualPass->GetVertexShader()->GetNumInputs());
// 	ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetNumOutputs(), secondVisualPass->GetVertexShader()->GetNumOutputs());
// 	ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetNumConstants(), secondVisualPass->GetVertexShader()->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetNumSamplers(), secondVisualPass->GetVertexShader()->GetNumSamplers());
// 
// 	for (int i = 0; i < 3;++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetInputName(i), secondVisualPass->GetVertexShader()->GetInputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetInputType(i), secondVisualPass->GetVertexShader()->GetInputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetInputSemantic(i), secondVisualPass->GetVertexShader()->GetInputSemantic(i));
// 	}
//  
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetOutputName(i), secondVisualPass->GetVertexShader()->GetOutputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetOutputType(i), secondVisualPass->GetVertexShader()->GetOutputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetOutputSemantic(i), secondVisualPass->GetVertexShader()->GetOutputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetConstantName(i), secondVisualPass->GetVertexShader()->GetConstantName(i));
// 		ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetNumRegistersUsed(i), secondVisualPass->GetVertexShader()->GetNumRegistersUsed(i));
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetVertexShader()->GetSamplerName(i), secondVisualPass->GetVertexShader()->GetSamplerName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetSamplerType(i), secondVisualPass->GetVertexShader()->GetSamplerType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetFilter(i), secondVisualPass->GetVertexShader()->GetFilter(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetCoordinate(i, 0), secondVisualPass->GetVertexShader()->GetCoordinate(i, 0));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetCoordinate(i, 1), secondVisualPass->GetVertexShader()->GetCoordinate(i, 1));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetVertexShader()->GetCoordinate(i, 2), secondVisualPass->GetVertexShader()->GetCoordinate(i, 2));
// 		ASSERT_APPROXIMATE(firstVisualPass->GetVertexShader()->GetLodBias(i), secondVisualPass->GetVertexShader()->GetLodBias(i), 1e-8f);
// 		ASSERT_APPROXIMATE(firstVisualPass->GetVertexShader()->GetAnisotropy(i), secondVisualPass->GetVertexShader()->GetAnisotropy(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualPass->GetVertexShader()->GetBorderColor(i),
// 										secondVisualPass->GetVertexShader()->GetBorderColor(i), 1e-8f);
// 	}
// 
// 	// PixelShader
// 	ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetNumInputs(), secondVisualPass->GetPixelShader()->GetNumInputs());
// 	ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetNumOutputs(), secondVisualPass->GetPixelShader()->GetNumOutputs());
// 	ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetNumConstants(), secondVisualPass->GetPixelShader()->GetNumConstants());
// 	ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetNumSamplers(), secondVisualPass->GetPixelShader()->GetNumSamplers());
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetInputName(i), secondVisualPass->GetPixelShader()->GetInputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetInputType(i), secondVisualPass->GetPixelShader()->GetInputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetInputSemantic(i), secondVisualPass->GetPixelShader()->GetInputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetOutputName(i), secondVisualPass->GetPixelShader()->GetOutputName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetOutputType(i), secondVisualPass->GetPixelShader()->GetOutputType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetOutputSemantic(i), secondVisualPass->GetPixelShader()->GetOutputSemantic(i));
// 	}
// 
// 	for (int i = 0; i < 6; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetConstantName(i), secondVisualPass->GetPixelShader()->GetConstantName(i));
// 		ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetNumRegistersUsed(i), secondVisualPass->GetPixelShader()->GetNumRegistersUsed(i));
// 	}
// 
// 	for (int i = 0; i < 7; ++i)
// 	{
// 		ASSERT_EQUAL(firstVisualPass->GetPixelShader()->GetSamplerName(i), secondVisualPass->GetPixelShader()->GetSamplerName(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetSamplerType(i), secondVisualPass->GetPixelShader()->GetSamplerType(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetFilter(i), secondVisualPass->GetPixelShader()->GetFilter(i));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetCoordinate(i, 0), secondVisualPass->GetPixelShader()->GetCoordinate(i, 0));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetCoordinate(i, 1), secondVisualPass->GetPixelShader()->GetCoordinate(i, 1));
// 		ASSERT_ENUM_EQUAL(firstVisualPass->GetPixelShader()->GetCoordinate(i, 2), secondVisualPass->GetPixelShader()->GetCoordinate(i, 2));
// 		ASSERT_APPROXIMATE(firstVisualPass->GetPixelShader()->GetLodBias(i), secondVisualPass->GetPixelShader()->GetLodBias(i), 1e-8f);
// 		ASSERT_APPROXIMATE(firstVisualPass->GetPixelShader()->GetAnisotropy(i), secondVisualPass->GetPixelShader()->GetAnisotropy(i), 1e-8f);
// 		ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualPass->GetPixelShader()->GetBorderColor(i),
// 										secondVisualPass->GetPixelShader()->GetBorderColor(i), 1e-8f);
// 	}
// 
// 	// AlphaState
// 	ASSERT_EQUAL(firstVisualPass->GetAlphaState()->IsBlendEnabled(), secondVisualPass->GetAlphaState()->IsBlendEnabled());
// 	ASSERT_ENUM_EQUAL(firstVisualPass->GetAlphaState()->GetSourceBlend(), secondVisualPass->GetAlphaState()->GetSourceBlend());
// 	ASSERT_ENUM_EQUAL(firstVisualPass->GetAlphaState()->GetDestinationBlend(), secondVisualPass->GetAlphaState()->GetDestinationBlend());
// 	 ASSERT_EQUAL(firstVisualPass->GetAlphaState()->IsCompareEnabled(), secondVisualPass->GetAlphaState()->IsCompareEnabled());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetAlphaState()->GetCompare(), secondVisualPass->GetAlphaState()->GetCompare());
// 	 ASSERT_APPROXIMATE(firstVisualPass->GetAlphaState()->GetReference(), secondVisualPass->GetAlphaState()->GetReference(), 1e-8f);
// 	 ASSERT_APPROXIMATE_USE_FUNCTION(Approximate<float>, firstVisualPass->GetAlphaState()->GetConstantColor(),
// 			                         secondVisualPass->GetAlphaState()->GetConstantColor(),1e-8f);
// 
// 	 // CullState
// 	 ASSERT_EQUAL(firstVisualPass->GetCullState()->IsEnabled(), secondVisualPass->GetCullState()->IsEnabled());
// 	 ASSERT_EQUAL(firstVisualPass->GetCullState()->IsCCWOrder(), secondVisualPass->GetCullState()->IsCCWOrder());
// 
// 	 // DepthState
// 	 ASSERT_EQUAL(firstVisualPass->GetDepthState()->IsEnabled(), secondVisualPass->GetDepthState()->IsEnabled());
// 	 ASSERT_EQUAL(firstVisualPass->GetDepthState()->IsWritable(), secondVisualPass->GetDepthState()->IsWritable());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetDepthState()->GetCompare(), secondVisualPass->GetDepthState()->GetCompare());
// 
// 	 // OffsetState
// 	 ASSERT_EQUAL(firstVisualPass->GetOffsetState()->IsFillEnabled(), secondVisualPass->GetOffsetState()->IsFillEnabled());
// 	 ASSERT_EQUAL(firstVisualPass->GetOffsetState()->IsLineEnabled(), secondVisualPass->GetOffsetState()->IsLineEnabled());
// 	 ASSERT_EQUAL(firstVisualPass->GetOffsetState()->IsPointEnabled(), secondVisualPass->GetOffsetState()->IsPointEnabled());
// 	 ASSERT_APPROXIMATE(firstVisualPass->GetOffsetState()->GetScale(), secondVisualPass->GetOffsetState()->GetScale(), 1e-8f);
// 	 ASSERT_APPROXIMATE(firstVisualPass->GetOffsetState()->GetBias(), secondVisualPass->GetOffsetState()->GetBias(), 1e-8f);
// 
// 	 // StencilState
// 	 ASSERT_EQUAL(firstVisualPass->GetStencilState()->IsEnabled(), secondVisualPass->GetStencilState()->IsEnabled());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetStencilState()->GetCompare(), secondVisualPass->GetStencilState()->GetCompare());
// 	 ASSERT_EQUAL(firstVisualPass->GetStencilState()->GetReference(), secondVisualPass->GetStencilState()->GetReference());
// 	 ASSERT_EQUAL(firstVisualPass->GetStencilState()->GetMask(), secondVisualPass->GetStencilState()->GetMask());
// 	 ASSERT_EQUAL(firstVisualPass->GetStencilState()->GetWriteMask(), secondVisualPass->GetStencilState()->GetWriteMask());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetStencilState()->GetOnFail(), secondVisualPass->GetStencilState()->GetOnFail());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetStencilState()->GetOnZFail(), secondVisualPass->GetStencilState()->GetOnZFail());
// 	 ASSERT_ENUM_EQUAL(firstVisualPass->GetStencilState()->GetOnZPass(), secondVisualPass->GetStencilState()->GetOnZPass());
// 	 
// 	 // WireState
// 	 ASSERT_EQUAL(firstVisualPass->GetWireState()->IsEnabled(), secondVisualPass->GetWireState()->IsEnabled()); 

}
