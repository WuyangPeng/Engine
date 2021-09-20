// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:42)

#include "Vector3DInformationTesting.h"
#include "Mathematics/Algebra/Vector3DInformationDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3DTools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3DInformation<float>;
	template class Vector3DInformation<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3DInformationTesting) 

void Mathematics::Vector3DInformationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}

void Mathematics::Vector3DInformationTesting
	::DimensionTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ 0.0001,0.0002 };
	uniform_real<double> secondRandomDistribution{ -10.0,10.0 }; 

	vector<DoubleVector3D> firstVector;
	vector<DoubleVector3D> secondVector;
	vector<DoubleVector3D> thirdVector;
	vector<DoubleVector3D> fourthVector;
	double slope = secondRandomDistribution(generator);
	double yCoordinate = secondRandomDistribution(generator);
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstEachVector(firstRandomDistribution(generator),
			                      firstRandomDistribution(generator),
								  firstRandomDistribution(generator));
		
		firstVector.push_back(firstEachVector);

		double randomValue = firstRandomDistribution(generator) * secondRandomDistribution(generator);

		DoubleVector3D secondEachVector(randomValue, yCoordinate, randomValue * slope);

		secondVector.push_back(secondEachVector);

		DoubleVector3D thirdEachVector(secondRandomDistribution(generator),
			                      secondRandomDistribution(generator),	
								  firstRandomDistribution(generator));

		thirdVector.push_back(thirdEachVector);

		DoubleVector3D fourthEachVector(secondRandomDistribution(generator),
			                       secondRandomDistribution(generator),	
								   secondRandomDistribution(generator));

		fourthVector.push_back(fourthEachVector);
	}

	thirdVector.push_back(DoubleVector3D(20.0,80.7,firstRandomDistribution(generator)));
	thirdVector.push_back(DoubleVector3D(120.0,180.7,firstRandomDistribution(generator)));
	fourthVector.push_back(DoubleVector3D(20.0,80.7,20.0));
	fourthVector.push_back(DoubleVector3D(120.0,180.7,-80.0));

	DoubleVector3DInformation firstInformation(firstVector,0.0001);

	ASSERT_EQUAL(firstInformation.GetDimension(),0);

	DoubleVector3DInformation secondInformation(secondVector,0.0001);

	ASSERT_EQUAL(secondInformation.GetDimension(),1);

	DoubleVector3DInformation thirdInformation(thirdVector,0.0001);

	ASSERT_EQUAL(thirdInformation.GetDimension(),2);

	DoubleVector3DInformation fourthInformation(fourthVector,0.0001);

	ASSERT_EQUAL(fourthInformation.GetDimension(),3);
}

void Mathematics::Vector3DInformationTesting
	::AxesAlignBoundingBoxTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f }; 

	vector<DoubleVector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
			                 randomDistribution(generator));

		vectors.push_back(eachVector);
	}
	
	auto aabb = DoubleVector3DTools::ComputeExtremes(vectors);
	DoubleVector3DInformation secondInformation(vectors);

	ASSERT_TRUE(DoubleVector3DTools::Approximate(aabb.GetMinPoint(), secondInformation.GetAABB().GetMinPoint()));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(aabb.GetMaxPoint(),secondInformation.GetAABB().GetMaxPoint()));

	double xRange = aabb.GetMaxPoint().GetX() - aabb.GetMinPoint().GetX();

	double yRange = aabb.GetMaxPoint().GetY() - aabb.GetMinPoint().GetY();

	double zRange = aabb.GetMaxPoint().GetZ() - aabb.GetMinPoint().GetZ();

	if(xRange < yRange && zRange < yRange)
	{
		ASSERT_APPROXIMATE(yRange,secondInformation.GetMaxRange(),1e-10);
	}
	else if(zRange < xRange)
	{
		ASSERT_APPROXIMATE(xRange,secondInformation.GetMaxRange(),1e-10);
	}
	else
	{
		ASSERT_APPROXIMATE(zRange,secondInformation.GetMaxRange(),1e-10);
	}
}

void Mathematics::Vector3DInformationTesting
	::DirectionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f };

	vector<DoubleVector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator));

		vectors.push_back(eachVector);
	}	
	
	DoubleVector3DInformation information(vectors);

	auto ptr = information.GetAABB();

	DoubleVector3D minVector = ptr.GetMinPoint();
	DoubleVector3D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() - minVector.GetX();

	double yRange = maxVector.GetY() -  minVector.GetY();	

	double zRange = maxVector.GetZ() - minVector.GetZ();	

	if(xRange < yRange && zRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() -  minVector.GetY()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() - maxVector.GetY()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}
	else if(zRange < xRange)
	{
		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetX() -   minVector.GetX()) <= 1e-10)
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
	else 
	{
		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetZ() -  minVector.GetZ()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if (DoubleMath::FAbs(eachVector.GetZ() - maxVector.GetZ()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	DoubleVector3D directionX = maxVector - minVector;
	directionX.Normalize();

	DoubleVector3D directionY = information.GetPerpendicularExtreme() -  information.GetOrigin();
	double dot = DoubleVector3DTools::DotProduct(directionX,directionY);
	directionY -= dot * directionX;
	directionY.Normalize();

	DoubleVector3D directionZ = DoubleVector3DTools::CrossProduct(directionX,directionY);

	ASSERT_TRUE(DoubleVector3DTools::Approximate(minVector,  information.GetOrigin()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(directionX,  information.GetDirectionX()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(directionY,  information.GetDirectionY()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(directionZ, information.GetDirectionZ()));
}

void Mathematics::Vector3DInformationTesting
	::ExtremeTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f };

	vector<DoubleVector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
			                 randomDistribution(generator));

		vectors.push_back(eachVector);
	}	
	
	DoubleVector3DInformation information(vectors);

	auto ptr = information.GetAABB();

	DoubleVector3D minVector = ptr.GetMinPoint();
	DoubleVector3D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() -  minVector.GetX();

	double yRange = maxVector.GetY() - minVector.GetY();	

	double zRange = maxVector.GetZ() - minVector.GetZ();	

	if(xRange < yRange && zRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetY() -  minVector.GetY()) <= 1e-10)
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
	else if(zRange < xRange)
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
	else 
	{
		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetZ() -   minVector.GetZ()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(DoubleMath::FAbs(eachVector.GetZ() -  maxVector.GetZ()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	ASSERT_TRUE(DoubleVector3DTools::Approximate(minVector,  information.GetMinExtreme()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(maxVector,  information.GetMaxExtreme()));

	double maxDistance = 0.0;
	DoubleVector3D perpendicularExtreme;
	for (const auto& eachVector:vectors)
	{
		DoubleVector3D diff = eachVector - information.GetOrigin();
		double dot = DoubleVector3DTools::DotProduct(information.GetDirectionX(),diff);
		DoubleVector3D proj = diff - dot * information.GetDirectionX();
		double distance = DoubleVector3DTools::VectorMagnitude(proj);

		if (maxDistance < distance)
		{
			maxDistance = distance;
			perpendicularExtreme = eachVector;
		}
	}

	ASSERT_TRUE(DoubleVector3DTools::Approximate(perpendicularExtreme,  information.GetPerpendicularExtreme()));
	
	maxDistance = 0.0;
	NumericalValueSymbol maxSign = NumericalValueSymbol::Zero;
	DoubleVector3D tetrahedronExtreme;
	for (const auto& eachVector : vectors)
	{
		DoubleVector3D diff = eachVector -  information.GetOrigin();
		double distance = DoubleVector3DTools::DotProduct(information.GetDirectionZ(),diff);
		NumericalValueSymbol sign = DoubleMath::Sign(distance);
		distance = DoubleMath::FAbs(distance);
		if (maxDistance < distance)
		{
			maxDistance = distance;
			maxSign = sign;
			tetrahedronExtreme = eachVector;
		}
	}

	ASSERT_TRUE(DoubleVector3DTools::Approximate(tetrahedronExtreme, information.GetTetrahedronExtreme()));
											
}

