// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/27 16:20)

#include "PolynomialRootsRationalTesting.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsRationalDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_int;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class PolynomialRootsRational<float>;
	template class PolynomialRootsRational<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialRootsRationalTesting) 

void Mathematics::PolynomialRootsRationalTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);	
	ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
}

void Mathematics::PolynomialRootsRationalTesting
	::BaseTest()
{
	DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

	ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
}

void Mathematics::PolynomialRootsRationalTesting
	::OnceTest() 
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e10, 1.0e10); 
	uniform_int<> secondRandomDistribution(0,100000000);
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

		double constant = firstRandomDistribution(generator);
		double once = firstRandomDistribution(generator);

		if (DoubleMath::FAbs(once) < 1e-10)
		{
			once = 1.0;
		}

		ASSERT_TRUE(firstPolynomialRootsRational.Linear(constant, once));
 
		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

		for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);

			ASSERT_APPROXIMATE(root * once + constant,0.0,1e-5);
			ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
		}

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRational(constant);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRational(once);

		ASSERT_TRUE(firstPolynomialRootsRational.Linear(constantPolynomialRational, oncePolynomialRational));

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

		for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);

			ASSERT_APPROXIMATE(root * oncePolynomialRational.ConvertTo<double>() + constantPolynomialRational.ConvertTo<double>(), 0.0, 1e-5);

			ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
		}

		int constantDenominator = secondRandomDistribution(generator);
		int onceDenominator = secondRandomDistribution(generator);

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);

		ASSERT_TRUE(firstPolynomialRootsRational.Linear(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator));

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

		for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);

			ASSERT_APPROXIMATE(root * oncePolynomialRationalDenominator.ConvertTo<double>() + constantPolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-2);

			ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
		}

		once = 0.0;
		ASSERT_FALSE(firstPolynomialRootsRational.Linear(constant, once));
		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
		
		ASSERT_FALSE(firstPolynomialRootsRational.Linear(constantPolynomialRational, DoublePolynomialRootsRational::PolynomialRational()));
		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
	}
}

void Mathematics::PolynomialRootsRationalTesting
	::SecondaryTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e8, 1.0e8); 
	uniform_int<> secondRandomDistribution(0, 1000000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

		double constant = firstRandomDistribution(generator);
		double once = firstRandomDistribution(generator);
		double secondary = firstRandomDistribution(generator);

		bool result = firstPolynomialRootsRational.Quadratic(constant, once, secondary);

		if(result)
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2);

			for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
			{
				double root = firstPolynomialRootsRational.GetRoot(k);
				
				ASSERT_APPROXIMATE(root * root * secondary + root * once + constant,0.0,1e-6);

				if (firstPolynomialRootsRational.GetQuantity() == 2)
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
				else
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
			}		
			 
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
		}	

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRational(constant);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRational(once);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRational(secondary);

		result = firstPolynomialRootsRational.Quadratic(constantPolynomialRational, oncePolynomialRational, secondaryPolynomialRational);

		if(result)
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2);

			for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
			{
				double root = firstPolynomialRootsRational.GetRoot(k);
				
				ASSERT_APPROXIMATE(root * root * secondaryPolynomialRational.ConvertTo<double>() + root * oncePolynomialRational.ConvertTo<double>() + constantPolynomialRational.ConvertTo<double>(), 0.0, 1e-6);

				if (firstPolynomialRootsRational.GetQuantity() == 2)
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
				else
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
			}		
			 
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
		}

		int constantDenominator = secondRandomDistribution(generator);
		int onceDenominator = secondRandomDistribution(generator);
		int secondaryDenominator = secondRandomDistribution(generator);

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);

		result = firstPolynomialRootsRational.Quadratic(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator, secondaryPolynomialRationalDenominator);

		if(result)
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 ||  firstPolynomialRootsRational.GetQuantity() == 2);

			for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
			{
				double root = firstPolynomialRootsRational.GetRoot(k);
				
				ASSERT_APPROXIMATE(root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() + root * oncePolynomialRationalDenominator.ConvertTo<double>() + constantPolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-6);

				if (firstPolynomialRootsRational.GetQuantity() == 2)
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
				else
					ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
			}		
			 
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
		}
	}
}

void Mathematics::PolynomialRootsRationalTesting
	::ThriceTest() 
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e7, 1.0e7); 
	uniform_int<> secondRandomDistribution(0, 1000000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{ 
		DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

		double constant = firstRandomDistribution(generator);
		double once = firstRandomDistribution(generator);
		double secondary = firstRandomDistribution(generator);
		double thrice = firstRandomDistribution(generator);
		
		ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constant,once,secondary,thrice));

		ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2 || firstPolynomialRootsRational.GetQuantity() == 3);
		
		for (int k = 0;k < firstPolynomialRootsRational.GetQuantity();++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);
			
			ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
		}
			
		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRational(constant);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRational(once);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRational(secondary);
		DoublePolynomialRootsRational::PolynomialRational thricePolynomialRational(thrice);

		ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constantPolynomialRational,oncePolynomialRational,secondaryPolynomialRational,thricePolynomialRational));

		ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2 || firstPolynomialRootsRational.GetQuantity() == 3);
		
		for (int k = 0;k < firstPolynomialRootsRational.GetQuantity();++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);
			
			ASSERT_APPROXIMATE(constantPolynomialRational.ConvertTo<double>() + 
				               root * oncePolynomialRational.ConvertTo<double>() +
				               root * root * secondaryPolynomialRational.ConvertTo<double>() + 
							   root * root * root * thricePolynomialRational.ConvertTo<double>(), 0.0, 1e-3);
		}

		int constantDenominator = secondRandomDistribution(generator);
		int onceDenominator = secondRandomDistribution(generator);
		int secondaryDenominator = secondRandomDistribution(generator);
		int thriceDenominator = secondRandomDistribution(generator);

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);
		DoublePolynomialRootsRational::PolynomialRational thricePolynomialRationalDenominator(static_cast<int>(thrice), thriceDenominator);

		ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constantPolynomialRationalDenominator,oncePolynomialRationalDenominator,secondaryPolynomialRationalDenominator,thricePolynomialRationalDenominator));

		ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 ||
				    firstPolynomialRootsRational.GetQuantity() == 2 ||
				    firstPolynomialRootsRational.GetQuantity() == 3);
		
		for (int k = 0;k < firstPolynomialRootsRational.GetQuantity();++k)
		{
			double root = firstPolynomialRootsRational.GetRoot(k);
			
			ASSERT_APPROXIMATE(constantPolynomialRationalDenominator.ConvertTo<double>() + 
				               root * oncePolynomialRationalDenominator.ConvertTo<double>() +
				               root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() + 
							   root * root * root * thricePolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-3);
		}
	}

	// ππ‘Ï≈–± ΩŒ™¡„
	double constant = 1.0;
	double once = 3.0;
	double secondary = 3.0001;
	double thrice = 1.0; 

	DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

	ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constant,once,secondary,thrice));

	for (int i = 0; i < firstPolynomialRootsRational.GetQuantity(); ++i)
	{
		double root = firstPolynomialRootsRational.GetRoot(i);

		ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
	}	 
}

void Mathematics::PolynomialRootsRationalTesting
	::QuarticTest() 
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6); 
	uniform_int<> secondRandomDistribution(0, 1000000);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoublePolynomialRootsRational firstPolynomialRootsRational(1e-10);

		ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

		double constant = firstRandomDistribution(generator);
		double once = firstRandomDistribution(generator);
		double secondary = firstRandomDistribution(generator);
		double thrice = firstRandomDistribution(generator);
		double quartic = firstRandomDistribution(generator);

		if (firstPolynomialRootsRational.Quartic(constant, once, secondary, thrice, quartic))
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
				        firstPolynomialRootsRational.GetQuantity() == 4);
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(),0);
		}
			
		for (int m = 0;m < firstPolynomialRootsRational.GetQuantity();++m)
		{
			double root = firstPolynomialRootsRational.GetRoot(m);
			
			ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-2);
		}
			
		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRational(constant);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRational(once);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRational(secondary);
		DoublePolynomialRootsRational::PolynomialRational thricePolynomialRational(thrice);
		DoublePolynomialRootsRational::PolynomialRational quarticPolynomialRational(quartic);

		if (firstPolynomialRootsRational.Quartic(constantPolynomialRational,oncePolynomialRational,secondaryPolynomialRational,thricePolynomialRational,quarticPolynomialRational))
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
				        firstPolynomialRootsRational.GetQuantity() == 4);
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(),0);
		}

		for (int m = 0;m < firstPolynomialRootsRational.GetQuantity();++m)
		{
			double root = firstPolynomialRootsRational.GetRoot(m);

			ASSERT_APPROXIMATE(constantPolynomialRational.ConvertTo<double>() + 
				               root * oncePolynomialRational.ConvertTo<double>() +
				               root * root * secondaryPolynomialRational.ConvertTo<double>() + 
							   root * root * root * thricePolynomialRational.ConvertTo<double>() +
							   root * root * root * root * quarticPolynomialRational.ConvertTo<double>(), 0.0, 1e-3);;
		}

		int constantDenominator = secondRandomDistribution(generator);
		int onceDenominator = secondRandomDistribution(generator);
		int secondaryDenominator = secondRandomDistribution(generator);
		int thriceDenominator = secondRandomDistribution(generator);
		int quarticDenominator = secondRandomDistribution(generator);

		DoublePolynomialRootsRational::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
		DoublePolynomialRootsRational::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
		DoublePolynomialRootsRational::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);
		DoublePolynomialRootsRational::PolynomialRational thricePolynomialRationalDenominator(static_cast<int>(thrice), thriceDenominator);
		DoublePolynomialRootsRational::PolynomialRational quarticPolynomialRationalDenominator(static_cast<int>(thrice), quarticDenominator);

		if (firstPolynomialRootsRational.Quartic(constantPolynomialRationalDenominator,oncePolynomialRationalDenominator,secondaryPolynomialRationalDenominator,thricePolynomialRationalDenominator,quarticPolynomialRationalDenominator))
		{
			ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
				        firstPolynomialRootsRational.GetQuantity() == 4);
		}
		else
		{
			ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(),0);
		}

		for (int m = 0;m < firstPolynomialRootsRational.GetQuantity();++m)
		{
			double root = firstPolynomialRootsRational.GetRoot(m);

			ASSERT_APPROXIMATE(constantPolynomialRationalDenominator.ConvertTo<double>() + 
				               root * oncePolynomialRationalDenominator.ConvertTo<double>() +
				               root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() + 
							   root * root * root * thricePolynomialRationalDenominator.ConvertTo<double>() +
							   root * root * root * root * quarticPolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-3);;
		}
	}
}

