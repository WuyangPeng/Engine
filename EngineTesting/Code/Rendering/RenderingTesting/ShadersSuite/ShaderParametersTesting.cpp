// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.3 (2019/09/07 14:32)

#include "ShaderParametersTesting.h"
#include "Rendering/Shaders/ShaderParameters.h"
#include "Rendering/Shaders/VertexShader.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Renderers/RendererManager.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "System/Helper/PragmaWarning/LexicalCast.h"

using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, ShaderParametersTesting) 
#include SYSTEM_WARNING_DISABLE(26440) 
#include SYSTEM_WARNING_DISABLE(26414) 
#include SYSTEM_WARNING_DISABLE(26409) 
void Rendering::ShaderParametersTesting
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
 
void Rendering::ShaderParametersTesting
	::InitTest()
{
	ShaderBaseSharedPtr shader(new VertexShader("Shader", 1, 1, 5, 4));

	shader->SetConstant(0, "Constant0", 1);
	shader->SetConstant(1, "Constant1", 1);
	shader->SetConstant(2, "Constant2", 2);
	shader->SetConstant(3, "Constant3", 3);
	shader->SetConstant(4, "Constant4", 4);

	shader->SetSampler(0, "Texture0", ShaderFlags::SamplerType::Sampler1D);
	shader->SetSampler(1, "Texture1", ShaderFlags::SamplerType::Sampler1D);
	shader->SetSampler(2, "Texture2", ShaderFlags::SamplerType::Sampler1D);
	shader->SetSampler(3, "Texture3", ShaderFlags::SamplerType::Sampler1D);

// 	ShaderParametersSharedPtr shaderParameters(new ShaderParameters(shader.GetConstSharedPtr()));
// 
// 	ASSERT_EQUAL(shaderParameters->GetNumConstants(), 5);
// 	ASSERT_EQUAL(shaderParameters->GetNumTextures(), 4);
// 
// 	for (int i = 0; i < 5;++i)
// 	{
// 		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat(i + 1));
// 		ASSERT_EQUAL(shaderParameters->SetConstant("Constant" + boost::lexical_cast<string>(i), firstShaderFloat), i);
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(shaderParameters->GetConstants()[i]->GetNumRegisters(), i + 1);
// 		ASSERT_EQUAL(shaderParameters->GetConstant(i)->GetNumRegisters(), i + 1);
// 		ASSERT_EQUAL(shaderParameters->GetConstant("Constant" + boost::lexical_cast<string>(i))->GetNumRegisters(), i + 1);
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		TextureSharedPtr firstTexture(new Texture1D(TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i), 5, 0));
// 		ASSERT_EQUAL(shaderParameters->SetTexture("Texture" + boost::lexical_cast<string>(i), firstTexture), i);
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_ENUM_EQUAL(shaderParameters->GetTextures()[i]->GetFormat(), TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i));
// 		ASSERT_ENUM_EQUAL(shaderParameters->GetTexture(i)->GetFormat(), TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i));
// 		ASSERT_ENUM_EQUAL(shaderParameters->GetTexture("Texture" + boost::lexical_cast<string>(i))->GetFormat(), TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i));
// 	}
}

void Rendering::ShaderParametersTesting
	::CopyTest()
{
// 	VertexShaderSharedPtr firstShader(new VertexShader("Shader", 1, 1, 5, 4));
// 
// 	firstShader->SetConstant(0, "Constant0", 1);
// 	firstShader->SetConstant(1, "Constant1", 1);
// 	firstShader->SetConstant(2, "Constant2", 2);
// 	firstShader->SetConstant(3, "Constant3", 3);
// 	firstShader->SetConstant(4, "Constant4", 4);
// 
// 	firstShader->SetSampler(0, "Texture0", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(1, "Texture1", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(2, "Texture2", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(3, "Texture3", ShaderFlags::SamplerType::Sampler1D);
// 
// 	ShaderParametersSharedPtr firstShaderParameters(new ShaderParameters(firstShader.PolymorphicDowncastConstObjectSharedPtr<ConstShaderBaseSharedPtr>()));
// 
// 	for (int i = 0; i < 5;++i)
// 	{
// 		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat(i + 1));
// 		ASSERT_EQUAL(firstShaderParameters->SetConstant("Constant" + boost::lexical_cast<string>(i), firstShaderFloat), i);
// 	}
// 	
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		TextureSharedPtr firstTexture(new Texture1D(TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i), 5, 0));
// 		ASSERT_EQUAL(firstShaderParameters->SetTexture("Texture" + boost::lexical_cast<string>(i), firstTexture), i);
// 	}
// 
// 
// 	ShaderParametersSharedPtr secondShaderParameters(new ShaderParameters(*firstShaderParameters));
// 
// 	ASSERT_EQUAL(firstShaderParameters->GetNumConstants(), secondShaderParameters->GetNumConstants());
// 	ASSERT_EQUAL(firstShaderParameters->GetNumTextures(), secondShaderParameters->GetNumTextures());
// 	
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstShaderParameters->GetConstant(i)->GetNumRegisters(), secondShaderParameters->GetConstant(i)->GetNumRegisters());
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_ENUM_EQUAL(firstShaderParameters->GetTexture(i)->GetFormat(), secondShaderParameters->GetTexture(i)->GetFormat());
// 	}
// 
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_UNEQUAL(firstShaderParameters->GetConstant(i), secondShaderParameters->GetConstant(i));
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_UNEQUAL(firstShaderParameters->GetTexture(i), secondShaderParameters->GetTexture(i));
// 	}
}

void Rendering::ShaderParametersTesting
	::StreamTest()
{
// 	CoreTools::OutTopLevel outTopLevel;
// 
// 	VertexShaderSharedPtr firstShader(new VertexShader("Shader", 1, 1, 5, 4));
// 
// 	firstShader->SetConstant(0, "Constant0", 1);
// 	firstShader->SetConstant(1, "Constant1", 1);
// 	firstShader->SetConstant(2, "Constant2", 2);
// 	firstShader->SetConstant(3, "Constant3", 3);
// 	firstShader->SetConstant(4, "Constant4", 4);
// 
// 	firstShader->SetSampler(0, "Texture0", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(1, "Texture1", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(2, "Texture2", ShaderFlags::SamplerType::Sampler1D);
// 	firstShader->SetSampler(3, "Texture3", ShaderFlags::SamplerType::Sampler1D);
// 
// 	ShaderParametersSharedPtr firstShaderParameters(new ShaderParameters(firstShader.PolymorphicDowncastConstObjectSharedPtr<ConstShaderBaseSharedPtr>()));
// 
// 	for (int i = 0; i < 5;++i)
// 	{
// 		ShaderFloatSharedPtr firstShaderFloat(new ShaderFloat(i + 1));
// 		ASSERT_EQUAL(firstShaderParameters->SetConstant("Constant" + boost::lexical_cast<string>(i), firstShaderFloat), i);
// 	}
// 	
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		TextureSharedPtr firstTexture(new Texture1D(TextureFormat(System::EnumCastUnderlying(TextureFormat::A8B8G8R8) + i), 5, 0));
// 		ASSERT_EQUAL(firstShaderParameters->SetTexture("Texture" + boost::lexical_cast<string>(i), firstTexture), i);
// 	}
// 	
// 	outTopLevel.Insert(firstShaderParameters);

/*	CoreTools::BufferOutStream outStream(outTopLevel);*/
// 
// 	CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr = outStream.GetBufferOutStreamInformation();
// 
// 	CoreTools::BufferInStream inStream(fileBufferPtr);
// 
// 	CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 	
// 	ShaderParametersSharedPtr secondShaderParameters = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<ShaderParametersSharedPtr>();
// 
// 	ASSERT_UNEQUAL_NULL_PTR(secondShaderParameters);
// 
// 	ASSERT_EQUAL(firstShaderParameters->GetNumConstants(), secondShaderParameters->GetNumConstants());
// 	ASSERT_EQUAL(firstShaderParameters->GetNumTextures(), secondShaderParameters->GetNumTextures());
// 	
// 	for (int i = 0; i < 5; ++i)
// 	{
// 		ASSERT_EQUAL(firstShaderParameters->GetConstant(i)->GetNumRegisters(), secondShaderParameters->GetConstant(i)->GetNumRegisters());
// 		ASSERT_EQUAL(firstShaderParameters->GetConstant("Constant" + boost::lexical_cast<string>(i))->GetNumRegisters(), secondShaderParameters->GetConstant("Constant" + boost::lexical_cast<string>(i))->GetNumRegisters());
// 	}
// 
// 	for (int i = 0; i < 4; ++i)
// 	{
// 		ASSERT_ENUM_EQUAL(firstShaderParameters->GetTexture(i)->GetFormat(), secondShaderParameters->GetTexture(i)->GetFormat());
// 		ASSERT_ENUM_EQUAL(firstShaderParameters->GetTexture("Texture" + boost::lexical_cast<string>(i))->GetFormat(),
// 			              secondShaderParameters->GetTexture("Texture" + boost::lexical_cast<string>(i))->GetFormat());
// 	}
}
