// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/06 15:21)

#include "LightAmbientConstantTesting.h"
#include "Rendering/SceneGraph/CameraManager.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/LoadVisual.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/ShaderFloats/LightAmbientConstant.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h" 


#include <random>

using std::vector;
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26496)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, LightAmbientConstantTesting) 

void Rendering::LightAmbientConstantTesting
	::MainTest()
{ 
	CameraManager::Create();
	RendererManager::Create();

	CoreTools::InitTerm::ExecuteInitializers(); 

	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest);
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(UpdateTest);

	CoreTools::InitTerm::ExecuteTerminators();

	RendererManager::Destroy();
	CameraManager::Destroy();
}
 
void Rendering::LightAmbientConstantTesting
	::InitTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		LightSharedPtr firstLight(new Light(LightType::Ambient));

		float exponent = secondFloatRandomDistribution(generator);
		firstLight->SetExponent(exponent);

		Colour<float> ambient(secondFloatRandomDistribution(generator),
			                  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator));
		Colour<float> diffuse(secondFloatRandomDistribution(generator),
			                  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator));
		Colour<float> specular(secondFloatRandomDistribution(generator),
			                   secondFloatRandomDistribution(generator),
							   secondFloatRandomDistribution(generator),
							   secondFloatRandomDistribution(generator));

		firstLight->SetAmbient(ambient);
		firstLight->SetDiffuse(diffuse);
		firstLight->SetSpecular(specular);
		 
		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
			                        firstFloatRandomDistribution(generator),
									firstFloatRandomDistribution(generator));

		firstLight->SetPosition(firstPosition);
		
		float constant = secondFloatRandomDistribution(generator);
		float linear = secondFloatRandomDistribution(generator);
		float quadratic = secondFloatRandomDistribution(generator);
		float intensity = secondFloatRandomDistribution(generator);

		firstLight->SetAttenuation(constant, linear, quadratic, intensity);

		constexpr int numRegisters = 1;
		LightAmbientConstant firstShaderFloat(firstLight);
		ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);
		
		firstShaderFloat.SetNumRegisters(numRegisters);
		ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), numRegisters);

		ASSERT_UNEQUAL_NULL_PTR(firstShaderFloat.GetData());
	
		ASSERT_TRUE(firstShaderFloat.AllowUpdater());
		firstShaderFloat.DisableUpdater();
		ASSERT_FALSE(firstShaderFloat.AllowUpdater());
		firstShaderFloat.EnableUpdater();
		ASSERT_TRUE(firstShaderFloat.AllowUpdater());

		vector<float> firstData(4, 1);
		firstShaderFloat.SetRegisters(firstData);

		for (int i = 0; i < 4; ++i)
		{
			ASSERT_APPROXIMATE(firstData[i], firstShaderFloat.GetRegisters()[i], 1e-8f);
		}

		const LightAmbientConstant secondShaderFloat(firstLight);
		ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), numRegisters);
		ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat.GetData());
		ASSERT_TRUE(secondShaderFloat.AllowUpdater());

		LightAmbientConstant thirdShaderFloat(firstLight);
		ASSERT_EQUAL(thirdShaderFloat.GetNumRegisters(), numRegisters);

		ASSERT_UNEQUAL_NULL_PTR(thirdShaderFloat.GetData());

		ASSERT_TRUE(thirdShaderFloat.AllowUpdater());
		thirdShaderFloat.DisableUpdater();
		ASSERT_FALSE(thirdShaderFloat.AllowUpdater());
		thirdShaderFloat.EnableUpdater();
		ASSERT_TRUE(thirdShaderFloat.AllowUpdater());

		vector<float> secondData;
		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			secondData.push_back(static_cast<float>(registerIndex));
		}

		thirdShaderFloat.SetRegister(0, secondData);

		ASSERT_EQUAL(secondData, thirdShaderFloat.GetRegister(0));

		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], registerIndex, 1e-8f);
		}

		ASSERT_EQUAL(firstShaderFloat.GetLight(), firstLight);
		ASSERT_EQUAL(secondShaderFloat.GetLight(), firstLight);
		ASSERT_EQUAL(thirdShaderFloat.GetLight(), firstLight);
	}
}

void Rendering::LightAmbientConstantTesting
	::CopyTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		LightSharedPtr firstLight(new Light(LightType::Ambient));

		float exponent = secondFloatRandomDistribution(generator);
		firstLight->SetExponent(exponent);

		Colour<float> ambient(secondFloatRandomDistribution(generator),
			                  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator));
		Colour<float> diffuse(secondFloatRandomDistribution(generator),
			                  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator),
							  secondFloatRandomDistribution(generator));
		Colour<float> specular(secondFloatRandomDistribution(generator),
			                   secondFloatRandomDistribution(generator),
							   secondFloatRandomDistribution(generator),
							   secondFloatRandomDistribution(generator));

		firstLight->SetAmbient(ambient);
		firstLight->SetDiffuse(diffuse);
		firstLight->SetSpecular(specular);

		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
			                        firstFloatRandomDistribution(generator),
			                        firstFloatRandomDistribution(generator));

		firstLight->SetPosition(firstPosition);

		float constant = secondFloatRandomDistribution(generator);
		float linear = secondFloatRandomDistribution(generator);
		float quadratic = secondFloatRandomDistribution(generator);
		float intensity = secondFloatRandomDistribution(generator);

		firstLight->SetAttenuation(constant, linear, quadratic, intensity);

		LightAmbientConstant firstShaderFloat(firstLight);
		ASSERT_EQUAL(firstShaderFloat.GetNumRegisters(), 1);

		LightAmbientConstant secondShaderFloat(firstShaderFloat);
		ASSERT_EQUAL(secondShaderFloat.GetNumRegisters(), 1);

		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			firstShaderFloat[registerIndex] = static_cast<float>(registerIndex);
		}

		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
			ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
		}

		LightAmbientConstant thirdShaderFloat(firstLight);
		thirdShaderFloat = firstShaderFloat;
		firstShaderFloat = secondShaderFloat;

		for (int registerIndex = 0; registerIndex < 4; ++registerIndex)
		{
			ASSERT_APPROXIMATE(firstShaderFloat[registerIndex], 0.0f, 1e-8f);
			ASSERT_APPROXIMATE(secondShaderFloat[registerIndex], 0.0f, 1e-8f);
			ASSERT_APPROXIMATE(thirdShaderFloat[registerIndex], static_cast<float>(registerIndex), 1e-8f);
		}

		ASSERT_EQUAL(firstShaderFloat.GetLight(), firstLight);
		ASSERT_EQUAL(secondShaderFloat.GetLight(), firstLight);
		ASSERT_EQUAL(thirdShaderFloat.GetLight(), firstLight);
	}
}

void Rendering::LightAmbientConstantTesting
	::StreamTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f, 100.0f);
// 	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);
// 
// 	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
// 	{
// 		LightSharedPtr firstLight(new Light(LightType::Ambient));
// 
// 		float exponent = secondFloatRandomDistribution(generator);
// 		firstLight->SetExponent(exponent);
// 
// 		Colour<float> ambient(secondFloatRandomDistribution(generator),
// 			                  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator));
// 		Colour<float> diffuse(secondFloatRandomDistribution(generator),
// 			                  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator));
// 		Colour<float> specular(secondFloatRandomDistribution(generator),
// 			                   secondFloatRandomDistribution(generator),
// 							   secondFloatRandomDistribution(generator),
// 							   secondFloatRandomDistribution(generator));
// 
// 		firstLight->SetAmbient(ambient);
// 		firstLight->SetDiffuse(diffuse);
// 		firstLight->SetSpecular(specular);
// 
// 		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
// 			                        firstFloatRandomDistribution(generator),
// 			                        firstFloatRandomDistribution(generator));
// 
// 		firstLight->SetPosition(firstPosition);
// 
// 		float constant = secondFloatRandomDistribution(generator);
// 		float linear = secondFloatRandomDistribution(generator);
// 		float quadratic = secondFloatRandomDistribution(generator);
// 		float intensity = secondFloatRandomDistribution(generator);
// 
// 		firstLight->SetAttenuation(constant, linear, quadratic, intensity);
// 
// 		CoreTools::OutTopLevel outTopLevel;
// 		LightAmbientConstantSharedPtr firstShaderFloat(new LightAmbientConstant(firstLight));
// 		
// 		for (int i = 0; i < 4;++i)
// 		{	 
// 			(*firstShaderFloat)[i] = static_cast<float>(i);
// 		}
// 		
// 		outTopLevel.Insert(firstShaderFloat);	 
// 		
// 		CoreTools::BufferOutStream outStream(outTopLevel);
// 		
// 		CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 			outStream.GetBufferOutStreamInformation();
//         
// 		CoreTools::BufferInStream inStream(fileBufferPtr);
//         
// 		CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
// 		
// 		ASSERT_EQUAL(inTopLevel.GetTopLevelSize(),1);
// 		
// 		LightAmbientConstantSharedPtr secondShaderFloat =
// 			inTopLevel[0].PolymorphicDowncastObjectSharedPtr<LightAmbientConstantSharedPtr>();
// 		
// 		ASSERT_UNEQUAL_NULL_PTR(secondShaderFloat);
// 		
// 		ASSERT_EQUAL(firstShaderFloat->GetRegisters().size(),
// 		             secondShaderFloat->GetRegisters().size());
// 		
// 		for (unsigned registerIndex = 0; registerIndex < firstShaderFloat->GetRegisters().size(); ++registerIndex)
// 		{
// 			ASSERT_APPROXIMATE(firstShaderFloat->GetRegisters()[registerIndex], 
// 			                   secondShaderFloat->GetRegisters()[registerIndex], 1e-8f);
// 		}
// 
// 		ConstLightSharedPtr secondLight = secondShaderFloat->GetLight(); 
// 
// 		ASSERT_ENUM_EQUAL(secondLight->GetType(), firstLight->GetType());
// 		ASSERT_APPROXIMATE(secondLight->GetExponent(), firstLight->GetExponent(), 1e-8f);
// 		ASSERT_TRUE(Approximate(firstLight->GetAmbient(), secondLight->GetAmbient(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetDiffuse(), secondLight->GetDiffuse(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetSpecular(), secondLight->GetSpecular(), 1e-8f));
// 		ASSERT_TRUE(Approximate(secondLight->GetPosition(), firstLight->GetPosition(), 1e-8f));
// 		ASSERT_APPROXIMATE(firstLight->GetConstant(), secondLight->GetConstant(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetLinear(), secondLight->GetLinear(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetQuadratic(), secondLight->GetQuadratic(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetIntensity(), secondLight->GetIntensity(), 1e-8f);
// 
// 	}
}

void Rendering::LightAmbientConstantTesting
	::UpdateTest()
{
// 	std::default_random_engine generator;
// 	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  
// 	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);
// 
// 	for(int loop = 0;loop < GetTestLoopCount();++loop)
// 	{
//         Camera::APoint firstPosition(firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator));
// 
//         Camera::AVector firstVector(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
// 
//         firstVector.Normalize();
// 
//         Camera::AVector secondVector(firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator),
//                                      firstFloatRandomDistribution(generator));
// 
//         secondVector.Normalize();
// 
//         Camera::AVector thirdVector(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
// 
//         thirdVector.Normalize();
// 
//         Mathematics::AVectorOrthonormalizef orthonormalize =
//               Orthonormalize(firstVector, secondVector, thirdVector,1e-5f);
//         
//         firstVector = orthonormalize.GetUVector();
//         secondVector = orthonormalize.GetVVector();
//         thirdVector = orthonormalize.GetWVector();       
// 
//         Camera firstCamera(true,1e-5f);
// 
//         firstCamera.SetFrame(firstPosition, firstVector,
//                              secondVector, thirdVector);
// 
// 		LightSharedPtr firstLight(new Light(LightType::Ambient));
// 
// 		float exponent = secondFloatRandomDistribution(generator);
// 		firstLight->SetExponent(exponent);
// 
// 		Colour<float> ambient(secondFloatRandomDistribution(generator),
// 			                  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator));
// 		Colour<float> diffuse(secondFloatRandomDistribution(generator),
// 			                  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator),
// 							  secondFloatRandomDistribution(generator));
// 		Colour<float> specular(secondFloatRandomDistribution(generator),
// 			                   secondFloatRandomDistribution(generator),
// 							   secondFloatRandomDistribution(generator),
// 							   secondFloatRandomDistribution(generator));
// 
// 		firstLight->SetAmbient(ambient);
// 		firstLight->SetDiffuse(diffuse);
// 		firstLight->SetSpecular(specular);
// 
// 		Light::APoint secondPosition(firstFloatRandomDistribution(generator),
// 			                         firstFloatRandomDistribution(generator),
// 									 firstFloatRandomDistribution(generator));
// 
// 		firstLight->SetPosition(secondPosition);
// 
// 		float constant = secondFloatRandomDistribution(generator);
// 		float linear = secondFloatRandomDistribution(generator);
// 		float quadratic = secondFloatRandomDistribution(generator);
// 		float intensity = secondFloatRandomDistribution(generator);
// 
// 		firstLight->SetAttenuation(constant, linear, quadratic, intensity);
// 
// 		LightAmbientConstant firstShaderFloat(firstLight);
// 
// 		VisualSharedPtr firstTrianglesMesh =
// 			LoadVisual::CreateFromFile(SYSTEM_TEXT("Resource/SceneGraphSuite/TrianglesMesh.trv"));
// 
// 		firstShaderFloat.Update(firstTrianglesMesh.GetData(), &firstCamera);
// 
// 		const Colour<float> colour = firstLight->GetAmbient();
// 		 
// 		ASSERT_APPROXIMATE(colour.GetRed(), firstShaderFloat[0], 1e-8f);
// 		ASSERT_APPROXIMATE(colour.GetGreen(), firstShaderFloat[1], 1e-8f);
// 		ASSERT_APPROXIMATE(colour.GetBlue(), firstShaderFloat[2], 1e-8f);
// 		ASSERT_APPROXIMATE(colour.GetAlpha(), firstShaderFloat[3], 1e-8f);
// 	}
}
