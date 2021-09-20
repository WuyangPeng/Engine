// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 10:58)

#include "Vector2DInformationTesting.h"
#include "Mathematics/Algebra/Vector2DInformationDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector2DTools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector2DInformation<float>;
	template class Vector2DInformation<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector2DInformationTesting) 

void Mathematics::Vector2DInformationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}

void Mathematics::Vector2DInformationTesting
	::DimensionTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ 0.0001,0.0002 };
	uniform_real<double> secondRandomDistribution(-10.0, 10.0); 

	vector<DoubleVector2D> firstVector;
	vector<DoubleVector2D> secondVector;
	vector<DoubleVector2D> thirdVector;
	double slope = secondRandomDistribution(generator);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstEachVector(firstRandomDistribution(generator),firstRandomDistribution(generator));

		firstVector.push_back(firstEachVector);

		double randomValue = firstRandomDistribution(generator) * secondRandomDistribution(generator);

		DoubleVector2D secondEachVector(randomValue,randomValue * slope);

		secondVector.push_back(secondEachVector);

		DoubleVector2D thirdEachVector(secondRandomDistribution(generator),secondRandomDistribution(generator));

		thirdVector.push_back(thirdEachVector);
	}

	thirdVector.push_back(DoubleVector2D(20.0,80.7));
	thirdVector.push_back(DoubleVector2D(120.0,180.7));

	DoubleVector2DInformation firstInformation(firstVector,0.0001);

	ASSERT_EQUAL(firstInformation.GetDimension(),0);

	DoubleVector2DInformation secondInformation(secondVector,0.0001);

	ASSERT_EQUAL(secondInformation.GetDimension(),1);

	DoubleVector2DInformation thirdInformation(thirdVector,0.0001);

	ASSERT_EQUAL(thirdInformation.GetDimension(),2);
}

void Mathematics::Vector2DInformationTesting
	::AxesAlignBoundingBoxTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f }; 

	vector<DoubleVector2D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vectors.emplace_back(randomDistribution(generator), randomDistribution(generator));
	}
	
	auto aabb = DoubleVector2DTools::ComputeExtremes(vectors);
	DoubleVector2DInformation secondInformation(vectors);

	ASSERT_TRUE(DoubleVector2DTools::Approximate(aabb.GetMinPoint(),secondInformation.GetAABB().GetMinPoint()));

	ASSERT_TRUE(DoubleVector2DTools::Approximate(aabb.GetMaxPoint(), secondInformation.GetAABB().GetMaxPoint()));

	double xRange = aabb.GetMaxPoint().GetX() - aabb.GetMinPoint().GetX();

	double yRange = aabb.GetMaxPoint().GetY() - aabb.GetMinPoint().GetY();

	if(xRange < yRange)
	{
		ASSERT_APPROXIMATE(yRange,secondInformation.GetMaxRange(),1e-10);
	}
	else
	{
		ASSERT_APPROXIMATE(xRange,secondInformation.GetMaxRange(),1e-10);
	}
}

void Mathematics::Vector2DInformationTesting
	::DirectionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f };

	vector<DoubleVector2D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		vectors.emplace_back(randomDistribution(generator),randomDistribution(generator));
	}	
	
	DoubleVector2DInformation information(vectors);

	auto ptr = information.GetAABB();

	DoubleVector2D minVector = ptr.GetMinPoint();
	DoubleVector2D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() - minVector.GetX();

	double yRange = maxVector.GetY() - minVector.GetY();	

	if(xRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() - minVector.GetY()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() -  maxVector.GetY()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}
	else
	{
		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetX() - minVector.GetX()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetX() -  maxVector.GetX()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	DoubleVector2D directionX = maxVector - minVector;
	directionX.Normalize();
	DoubleVector2D directionY = -DoubleVector2DTools::GetPerp(directionX);

	ASSERT_TRUE(DoubleVector2DTools::Approximate(minVector,information.GetOrigin()));
	ASSERT_TRUE(DoubleVector2DTools::Approximate(directionX,information.GetDirectionX()));
	ASSERT_TRUE(DoubleVector2DTools::Approximate(directionY,information.GetDirectionY()));
}

void Mathematics::Vector2DInformationTesting
	::ExtremeTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f }; 

	vector<DoubleVector2D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D eachVector(randomDistribution(generator), randomDistribution(generator));

		vectors.push_back(eachVector);
	}	
	
	DoubleVector2DInformation information(vectors);

	auto ptr = information.GetAABB();

	DoubleVector2D minVector = ptr.GetMinPoint();
	DoubleVector2D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() - minVector.GetX();

	double yRange = maxVector.GetY() - minVector.GetY();	

	if(xRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() - 
				           minVector.GetY()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector : vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() -  maxVector.GetY()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}
	else
	{
		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetX() -  minVector.GetX()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetX() -  maxVector.GetX()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	ASSERT_TRUE(DoubleVector2DTools::Approximate(minVector,  information.GetMinExtreme()));
	ASSERT_TRUE(DoubleVector2DTools::Approximate(maxVector, information.GetMaxExtreme()));

	double maxDistance = 0.0;
	NumericalValueSymbol maxSign = NumericalValueSymbol::Zero;
	DoubleVector2D perpendicularExtreme;
	for (const auto& eachVector:vectors)
	{
		DoubleVector2D diff = eachVector - information.GetOrigin();
		double distance = DoubleVector2DTools::DotProduct(information.GetDirectionY(),  diff);
		NumericalValueSymbol sign = DoubleMath::Sign(distance);
		distance = DoubleMath::FAbs(distance);
		if (maxDistance < distance)
		{
			maxDistance = distance;
			maxSign = sign;
			perpendicularExtreme = eachVector;
		}
	}

	ASSERT_TRUE(DoubleVector2DTools::Approximate(perpendicularExtreme, information.GetPerpendicularExtreme()));
}

