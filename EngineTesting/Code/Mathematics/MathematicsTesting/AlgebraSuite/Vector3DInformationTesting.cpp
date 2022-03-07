// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:42)

#include "Vector3DInformationTesting.h"
#include "Mathematics/Algebra/Vector3InformationDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3Tools.h"

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3Information<float>;
	template class Vector3Information<double>;	
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3InformationTesting) 

void Mathematics::Vector3InformationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DimensionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AxesAlignBoundingBoxTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DirectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ExtremeTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector3InformationTesting
	::DimensionTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ 0.0001,0.0002 };
	uniform_real<double> secondRandomDistribution{ -10.0,10.0 }; 

	vector<Vector3D> firstVector;
	vector<Vector3D> secondVector;
	vector<Vector3D> thirdVector;
	vector<Vector3D> fourthVector;
	double slope = secondRandomDistribution(generator);
	double yCoordinate = secondRandomDistribution(generator);
	
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D firstEachVector(firstRandomDistribution(generator),
			                      firstRandomDistribution(generator),
								  firstRandomDistribution(generator));
		
		firstVector.push_back(firstEachVector);

		double randomValue = firstRandomDistribution(generator) * secondRandomDistribution(generator);

		Vector3D secondEachVector(randomValue, yCoordinate, randomValue * slope);

		secondVector.push_back(secondEachVector);

		Vector3D thirdEachVector(secondRandomDistribution(generator),
			                      secondRandomDistribution(generator),	
								  firstRandomDistribution(generator));

		thirdVector.push_back(thirdEachVector);

		Vector3D fourthEachVector(secondRandomDistribution(generator),
			                       secondRandomDistribution(generator),	
								   secondRandomDistribution(generator));

		fourthVector.push_back(fourthEachVector);
	}

	thirdVector.push_back(Vector3D(20.0,80.7,firstRandomDistribution(generator)));
	thirdVector.push_back(Vector3D(120.0,180.7,firstRandomDistribution(generator)));
	fourthVector.push_back(Vector3D(20.0,80.7,20.0));
	fourthVector.push_back(Vector3D(120.0,180.7,-80.0));

	DoubleVector3Information firstInformation(firstVector,0.0001);

	ASSERT_EQUAL(firstInformation.GetDimension(),0);

	DoubleVector3Information secondInformation(secondVector,0.0001);

	ASSERT_EQUAL(secondInformation.GetDimension(),1);

	DoubleVector3Information thirdInformation(thirdVector,0.0001);

	ASSERT_EQUAL(thirdInformation.GetDimension(),2);

	DoubleVector3Information fourthInformation(fourthVector,0.0001);

	ASSERT_EQUAL(fourthInformation.GetDimension(),3);
}

void Mathematics::Vector3InformationTesting
	::AxesAlignBoundingBoxTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f }; 

	vector<Vector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
			                 randomDistribution(generator));

		vectors.push_back(eachVector);
	}
	
	auto aabb = Vector3ToolsD::ComputeExtremes(vectors);
	DoubleVector3Information secondInformation(vectors);

	ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMinPoint(), secondInformation.GetAABB().GetMinPoint()));

	ASSERT_TRUE(Vector3ToolsD::Approximate(aabb.GetMaxPoint(),secondInformation.GetAABB().GetMaxPoint()));

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

void Mathematics::Vector3InformationTesting
	::DirectionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f };

	vector<Vector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator));

		vectors.push_back(eachVector);
	}	
	
	DoubleVector3Information information(vectors);

	auto ptr = information.GetAABB();

	Vector3D minVector = ptr.GetMinPoint();
	Vector3D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() - minVector.GetX();

	double yRange = maxVector.GetY() -  minVector.GetY();	

	double zRange = maxVector.GetZ() - minVector.GetZ();	

	if(xRange < yRange && zRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetY() -  minVector.GetY()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetY() - maxVector.GetY()) <= 1e-10)
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
			if(MathD::FAbs(eachVector.GetX() -   minVector.GetX()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetX() -  maxVector.GetX()) <= 1e-10)
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
			if(MathD::FAbs(eachVector.GetZ() -  minVector.GetZ()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if (MathD::FAbs(eachVector.GetZ() - maxVector.GetZ()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	Vector3D directionX = maxVector - minVector;
	directionX.Normalize();

	Vector3D directionY = information.GetPerpendicularExtreme() -  information.GetOrigin();
	double dot = Vector3ToolsD::DotProduct(directionX,directionY);
	directionY -= dot * directionX;
	directionY.Normalize();

	Vector3D directionZ = Vector3ToolsD::CrossProduct(directionX,directionY);

	ASSERT_TRUE(Vector3ToolsD::Approximate(minVector,  information.GetOrigin()));
	ASSERT_TRUE(Vector3ToolsD::Approximate(directionX,  information.GetDirectionX()));
	ASSERT_TRUE(Vector3ToolsD::Approximate(directionY,  information.GetDirectionY()));
	ASSERT_TRUE(Vector3ToolsD::Approximate(directionZ, information.GetDirectionZ()));
}

void Mathematics::Vector3InformationTesting
	::ExtremeTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0f,100.0f };

	vector<Vector3D> vectors;

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D eachVector(randomDistribution(generator),
			                 randomDistribution(generator),
			                 randomDistribution(generator));

		vectors.push_back(eachVector);
	}	
	
	DoubleVector3Information information(vectors);

	auto ptr = information.GetAABB();

	Vector3D minVector = ptr.GetMinPoint();
	Vector3D maxVector = ptr.GetMaxPoint();

	double xRange = maxVector.GetX() -  minVector.GetX();

	double yRange = maxVector.GetY() - minVector.GetY();	

	double zRange = maxVector.GetZ() - minVector.GetZ();	

	if(xRange < yRange && zRange < yRange)
	{
		for(const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetY() -  minVector.GetY()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetY() -  maxVector.GetY()) <= 1e-10)
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
			if(MathD::FAbs(eachVector.GetX() -  minVector.GetX()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetX() -  maxVector.GetX()) <= 1e-10)
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
			if(MathD::FAbs(eachVector.GetZ() -   minVector.GetZ()) <= 1e-10)
			{
				minVector = eachVector;
				break;
			}
		}

		for (const auto& eachVector:vectors)
		{
			if(MathD::FAbs(eachVector.GetZ() -  maxVector.GetZ()) <= 1e-10)
			{
				maxVector = eachVector;
				break;
			}
		}
	}

	ASSERT_TRUE(Vector3ToolsD::Approximate(minVector,  information.GetMinExtreme()));
	ASSERT_TRUE(Vector3ToolsD::Approximate(maxVector,  information.GetMaxExtreme()));

	double maxDistance = 0.0;
	Vector3D perpendicularExtreme;
	for (const auto& eachVector:vectors)
	{
		Vector3D diff = eachVector - information.GetOrigin();
		double dot = Vector3ToolsD::DotProduct(information.GetDirectionX(),diff);
		Vector3D proj = diff - dot * information.GetDirectionX();
		double distance = Vector3ToolsD::GetLength(proj);

		if (maxDistance < distance)
		{
			maxDistance = distance;
			perpendicularExtreme = eachVector;
		}
	}

	ASSERT_TRUE(Vector3ToolsD::Approximate(perpendicularExtreme,  information.GetPerpendicularExtreme()));
	
	maxDistance = 0.0;
	NumericalValueSymbol maxSign = NumericalValueSymbol::Zero;
	Vector3D tetrahedronExtreme;
	for (const auto& eachVector : vectors)
	{
		Vector3D diff = eachVector -  information.GetOrigin();
		double distance = Vector3ToolsD::DotProduct(information.GetDirectionZ(),diff);
		NumericalValueSymbol sign = MathD::Sign(distance);
		distance = MathD::FAbs(distance);
		if (maxDistance < distance)
		{
			maxDistance = distance;
			maxSign = sign;
			tetrahedronExtreme = eachVector;
		}
	}

	ASSERT_TRUE(Vector3ToolsD::Approximate(tetrahedronExtreme, information.GetTetrahedronExtreme()));
											
}

