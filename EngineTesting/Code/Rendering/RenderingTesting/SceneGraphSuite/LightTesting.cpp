// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/05 10:49)

#include "LightTesting.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/SceneGraph/Light.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"

#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/InitTerm.h"




#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Rendering, LightTesting) 

void Rendering::LightTesting
	::MainTest()
{
	CoreTools::InitTerm::ExecuteInitializers();

	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CopyTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(StreamTest); 

	CoreTools::InitTerm::ExecuteTerminators();
}
 
void Rendering::LightTesting
	::BaseTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  

	std::uniform_real<float> secondFloatRandomDistribution(0.0f, 1.0f);

	Light firstLight(LightType::Ambient);

	ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Ambient);

	firstLight.SetType(LightType::Directional);

	ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Directional);

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
		float exponent = secondFloatRandomDistribution(generator);

		firstLight.SetExponent(exponent);

		ASSERT_APPROXIMATE(exponent, firstLight.GetExponent(), 1e-8f);

		Colour<float> ambient(firstFloatRandomDistribution(generator),
                              firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator));
		Colour<float> diffuse(firstFloatRandomDistribution(generator),
                              firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator));
		Colour<float> specular(firstFloatRandomDistribution(generator),
                               firstFloatRandomDistribution(generator),
							   firstFloatRandomDistribution(generator),
							   firstFloatRandomDistribution(generator));

		firstLight.SetAmbient(ambient);
		firstLight.SetDiffuse(diffuse);
		firstLight.SetSpecular(specular);

		ASSERT_TRUE(Approximate(firstLight.GetAmbient(), ambient, 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetDiffuse(), diffuse, 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetSpecular(), specular, 1e-8f));

 
		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));


		firstLight.SetPosition(firstPosition);

		ASSERT_TRUE(Approximate(firstPosition, firstLight.GetPosition(), 1e-8f));

		float constant = secondFloatRandomDistribution(generator); 
		float linear = secondFloatRandomDistribution(generator); 
		float quadratic = secondFloatRandomDistribution(generator); 
		float intensity = secondFloatRandomDistribution(generator);

		firstLight.SetAttenuation(constant, linear, quadratic, intensity);

		ASSERT_APPROXIMATE(firstLight.GetConstant(), constant, 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetLinear(), linear, 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetQuadratic(), quadratic, 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetIntensity(), intensity, 1e-8f);
	}	
}

void Rendering::LightTesting
	::CalculateTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  
	std::uniform_real<float> secondFloatRandomDistribution(0.0f, Mathematics::FloatMath::GetPI());

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
		Light firstLight(LightType::Ambient, 1e-5f);

		float angle(Mathematics::FloatMath::FAbs(secondFloatRandomDistribution(generator)));

		firstLight.SetAngle(angle);

		ASSERT_APPROXIMATE(angle, firstLight.GetAngle(), 1e-8f);
		ASSERT_APPROXIMATE(Mathematics::FloatMath::Cos(angle), firstLight.GetCosAngle(), 1e-8f);
		ASSERT_APPROXIMATE(Mathematics::FloatMath::Sin(angle), firstLight.GetSinAngle(), 1e-8f);
		 
		Light::AVector firstVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        firstVector.Normalize();

		Light::AVector secondVector(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

        secondVector.Normalize();

		Light::AVector thirdVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        thirdVector.Normalize();

// 		Mathematics::AVectorOrthonormalBasisf orthonormalize = GenerateOrthonormalBasis(thirdVector, 1e-5f);
// 
// 		firstLight.SetVector(orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector());
// 
// 		ASSERT_TRUE(Approximate(firstLight.GetUpVector(), orthonormalize.GetUVector(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight.GetRightVector(), orthonormalize.GetVVector(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight.GetDirectionVector(), orthonormalize.GetWVector(), 1e-8f));
// 
// 		firstLight.SetDirection(thirdVector);
// 
// 		ASSERT_TRUE(Approximate(firstLight.GetUpVector(), orthonormalize.GetUVector(), 1e-5f));
// 		ASSERT_TRUE(Approximate(firstLight.GetRightVector(), orthonormalize.GetVVector(), 1e-5f));
// 		ASSERT_TRUE(Approximate(firstLight.GetDirectionVector(), orthonormalize.GetWVector(), 1e-5f));
	}	
}

void Rendering::LightTesting
	::CopyTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstFloatRandomDistribution(-100.0f,100.0f);  
	std::uniform_real<float> secondFloatRandomDistribution(0.0f, Mathematics::FloatMath::GetPI());
	std::uniform_real<float> thirdFloatRandomDistribution(0.0f, 1.0f);

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
		Light firstLight(LightType::Ambient);

		float exponent = secondFloatRandomDistribution(generator);

		firstLight.SetExponent(exponent);

		Colour<float> ambient(firstFloatRandomDistribution(generator),
                              firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator));
		Colour<float> diffuse(firstFloatRandomDistribution(generator),
                              firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator),
							  firstFloatRandomDistribution(generator));
		Colour<float> specular(firstFloatRandomDistribution(generator),
                               firstFloatRandomDistribution(generator),
							   firstFloatRandomDistribution(generator),
							   firstFloatRandomDistribution(generator));

		firstLight.SetAmbient(ambient);
		firstLight.SetDiffuse(diffuse);
		firstLight.SetSpecular(specular);

		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator),
                                    firstFloatRandomDistribution(generator));

		firstLight.SetPosition(firstPosition);

		float constant = thirdFloatRandomDistribution(generator);
		float linear = thirdFloatRandomDistribution(generator);
		float quadratic = thirdFloatRandomDistribution(generator);
		float intensity = thirdFloatRandomDistribution(generator);

		firstLight.SetAttenuation(constant, linear, quadratic, intensity);

		float angle(Mathematics::FloatMath::FAbs(secondFloatRandomDistribution(generator)));

		firstLight.SetAngle(angle);

		Light::AVector firstVector(firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator),
                                   firstFloatRandomDistribution(generator));

        firstVector.Normalize();

		firstLight.SetDirection(firstVector);

		Light secondLight(firstLight);

		ASSERT_ENUM_EQUAL(firstLight.GetType(), secondLight.GetType());
		ASSERT_APPROXIMATE(firstLight.GetAngle(), secondLight.GetAngle(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetCosAngle(), secondLight.GetCosAngle(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetSinAngle(), secondLight.GetSinAngle(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetExponent(), secondLight.GetExponent(), 1e-8f);
		ASSERT_TRUE(Approximate(firstLight.GetAmbient(), secondLight.GetAmbient(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetDiffuse(), secondLight.GetDiffuse(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetSpecular(), secondLight.GetSpecular(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetPosition(), secondLight.GetPosition(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetDirectionVector(), secondLight.GetDirectionVector(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetUpVector(), secondLight.GetUpVector(), 1e-8f));
		ASSERT_TRUE(Approximate(firstLight.GetRightVector(), secondLight.GetRightVector(), 1e-8f));
		ASSERT_APPROXIMATE(firstLight.GetConstant(), secondLight.GetConstant(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetLinear(), secondLight.GetLinear(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetQuadratic(), secondLight.GetQuadratic(), 1e-8f);
		ASSERT_APPROXIMATE(firstLight.GetIntensity(), secondLight.GetIntensity(), 1e-8f);

		Light thirdLight;
		thirdLight = secondLight;

		ASSERT_ENUM_EQUAL(thirdLight.GetType(), secondLight.GetType());
		ASSERT_APPROXIMATE(thirdLight.GetAngle(), secondLight.GetAngle(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetCosAngle(), secondLight.GetCosAngle(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetSinAngle(), secondLight.GetSinAngle(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetExponent(), secondLight.GetExponent(), 1e-8f);
		ASSERT_TRUE(Approximate(thirdLight.GetAmbient(), secondLight.GetAmbient(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetDiffuse(), secondLight.GetDiffuse(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetSpecular(), secondLight.GetSpecular(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetPosition(), secondLight.GetPosition(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetDirectionVector(), secondLight.GetDirectionVector(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetUpVector(), secondLight.GetUpVector(), 1e-8f));
		ASSERT_TRUE(Approximate(thirdLight.GetRightVector(), secondLight.GetRightVector(), 1e-8f));
		ASSERT_APPROXIMATE(thirdLight.GetConstant(), secondLight.GetConstant(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetLinear(), secondLight.GetLinear(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetQuadratic(), secondLight.GetQuadratic(), 1e-8f);
		ASSERT_APPROXIMATE(thirdLight.GetIntensity(), secondLight.GetIntensity(), 1e-8f);

		secondLight.SetType(LightType::Directional);

		ASSERT_ENUM_UNEQUAL(secondLight.GetType(), firstLight.GetType());
		ASSERT_ENUM_UNEQUAL(secondLight.GetType(), thirdLight.GetType());
		ASSERT_ENUM_EQUAL(firstLight.GetType(), thirdLight.GetType());
		ASSERT_ENUM_EQUAL(firstLight.GetType(), LightType::Ambient);
	}
} 

void Rendering::LightTesting
	::StreamTest()
{
	std::default_random_engine generator;
	std::uniform_real<float>  firstFloatRandomDistribution(-100.0f,100.0f); 
	std::uniform_real<float> secondFloatRandomDistribution(0.0f, Mathematics::FloatMath::GetPI());
	std::uniform_real<float> thirdFloatRandomDistribution(0.0f, 1.0f);  

	for(int loop = 0;loop < GetTestLoopCount();++loop)
	{
// 		CoreTools::OutTopLevel outTopLevel;
// 		CoreTools::ObjectInterfaceSharedPtr objectPtr(new Light(LightType::Ambient));
// 
// 		LightSharedPtr firstLight = objectPtr.PolymorphicDowncastObjectSharedPtr<LightSharedPtr>();
// 
// 		float exponent = secondFloatRandomDistribution(generator);
// 
// 		firstLight->SetExponent(exponent);
// 
// 		Colour<float> ambient(firstFloatRandomDistribution(generator),
//                               firstFloatRandomDistribution(generator),
// 							  firstFloatRandomDistribution(generator),
// 							  firstFloatRandomDistribution(generator));
// 		Colour<float> diffuse(firstFloatRandomDistribution(generator),
//                               firstFloatRandomDistribution(generator),
// 							  firstFloatRandomDistribution(generator),
// 							  firstFloatRandomDistribution(generator));
// 		Colour<float> specular(firstFloatRandomDistribution(generator),
//                                firstFloatRandomDistribution(generator),
// 							   firstFloatRandomDistribution(generator),
// 							   firstFloatRandomDistribution(generator));
// 
// 		firstLight->SetAmbient(ambient);
// 		firstLight->SetDiffuse(diffuse);
// 		firstLight->SetSpecular(specular);
// 
// 		Light::APoint firstPosition(firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator),
//                                     firstFloatRandomDistribution(generator));
// 
// 		firstLight->SetPosition(firstPosition);
// 
// 		float constant = thirdFloatRandomDistribution(generator);
// 		float linear = thirdFloatRandomDistribution(generator);
// 		float quadratic = thirdFloatRandomDistribution(generator);
// 		float intensity = thirdFloatRandomDistribution(generator);
// 
// 		firstLight->SetAttenuation(constant, linear, quadratic, intensity);
// 
// 		float angle(Mathematics::FloatMath::FAbs(secondFloatRandomDistribution(generator)));
// 
// 		firstLight->SetAngle(angle);
// 
// 		Light::AVector firstVector(firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator),
//                                    firstFloatRandomDistribution(generator));
// 
//         firstVector.Normalize();
// 
// 		firstLight->SetDirection(firstVector);
//         
//         outTopLevel.Insert(objectPtr);
//         
//         CoreTools::BufferOutStream outStream(outTopLevel);
//         
//         CoreTools::BufferOutStream::FileBufferPtr fileBufferPtr =
// 		    outStream.GetBufferOutStreamInformation();
//         
//         CoreTools::BufferInStream inStream(fileBufferPtr);
//         
//         CoreTools::InTopLevel inTopLevel = inStream.GetTopLevel();
//         
// 		LightSharedPtr secondLight = inTopLevel[0].PolymorphicDowncastObjectSharedPtr<LightSharedPtr>();
//         
// 		ASSERT_ENUM_EQUAL(firstLight->GetType(), secondLight->GetType());
// 		ASSERT_APPROXIMATE(firstLight->GetAngle(), secondLight->GetAngle(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetCosAngle(), secondLight->GetCosAngle(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetSinAngle(), secondLight->GetSinAngle(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetExponent(), secondLight->GetExponent(), 1e-8f);
// 		ASSERT_TRUE(Approximate(firstLight->GetAmbient(), secondLight->GetAmbient(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetDiffuse(), secondLight->GetDiffuse(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetSpecular(), secondLight->GetSpecular(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetPosition(), secondLight->GetPosition(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetDirectionVector(), secondLight->GetDirectionVector(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetUpVector(), secondLight->GetUpVector(), 1e-8f));
// 		ASSERT_TRUE(Approximate(firstLight->GetRightVector(), secondLight->GetRightVector(), 1e-8f));
// 		ASSERT_APPROXIMATE(firstLight->GetConstant(), secondLight->GetConstant(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetLinear(), secondLight->GetLinear(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetQuadratic(), secondLight->GetQuadratic(), 1e-8f);
// 		ASSERT_APPROXIMATE(firstLight->GetIntensity(), secondLight->GetIntensity(), 1e-8f);
	}
}
