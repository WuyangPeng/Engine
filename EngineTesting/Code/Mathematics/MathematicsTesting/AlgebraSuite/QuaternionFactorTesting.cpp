// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:43)

#include "QuaternionFactorTesting.h"
#include "Mathematics/Algebra/QuaternionFactorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Polynomial.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class QuaternionFactor<float>;
	template class QuaternionFactor<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,QuaternionFactorTesting) 

void Mathematics::QuaternionFactorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FactorXYZTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorXZYTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorYZXTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorYXZTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorZXYTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorZYXTest);
}

void Mathematics::QuaternionFactorTesting
	::FactorXYZTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		FloatQuaternionFactor firstQuaternionFactor(firstQuaternion,QuaternionFactorFlags::XYZ);

		FloatQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		FloatQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		FloatQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		FloatQuaternion fifthQuaternion = secondQuaternion * thirdQuaternion * fourthQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		//ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) );  	
	}
}

void Mathematics::QuaternionFactorTesting
	::FactorXZYTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		FloatQuaternionFactor firstQuaternionFactor(firstQuaternion,QuaternionFactorFlags::XZY);

		FloatQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		FloatQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		FloatQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		FloatQuaternion fifthQuaternion = secondQuaternion * fourthQuaternion * thirdQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		//ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 		
	}
}

void Mathematics::QuaternionFactorTesting
	::FactorYZXTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		DoubleQuaternionFactor firstQuaternionFactor(firstQuaternion,QuaternionFactorFlags::YZX);

		DoubleQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		DoubleQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		DoubleQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		DoubleQuaternion fifthQuaternion = thirdQuaternion * fourthQuaternion * secondQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		//ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) ); 	
	}
}

void Mathematics::QuaternionFactorTesting
	::FactorYXZTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleQuaternion firstQuaternion(firstRandomDistribution(generator),firstRandomDistribution(generator),firstRandomDistribution(generator),firstRandomDistribution(generator));

		DoubleQuaternionFactor firstQuaternionFactor(firstQuaternion,QuaternionFactorFlags::YXZ);

		DoubleQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		DoubleQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		DoubleQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		DoubleQuaternion fifthQuaternion = thirdQuaternion * secondQuaternion * fourthQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

	//	ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) );		
	}
}

void Mathematics::QuaternionFactorTesting
	::FactorZXYTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		FloatQuaternionFactor firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::ZXY);

		FloatQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		FloatQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		FloatQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		FloatQuaternion fifthQuaternion = fourthQuaternion * secondQuaternion * thirdQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		//ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 	
	}
}

void Mathematics::QuaternionFactorTesting
	::FactorZYXTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		DoubleQuaternionFactor firstQuaternionFactor(firstQuaternion,QuaternionFactorFlags::ZYX);

		DoubleQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		DoubleQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		DoubleQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		DoubleQuaternion fifthQuaternion = fourthQuaternion * thirdQuaternion * secondQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		//ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) ); 	
	}
}

