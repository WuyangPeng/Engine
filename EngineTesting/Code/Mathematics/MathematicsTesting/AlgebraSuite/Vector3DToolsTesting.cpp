// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 13:18)

#include "Vector3DToolsTesting.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  

using std::vector;
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class Vector3DTools<float>;
	template class Vector3DTools<double>;	
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3DToolsTesting) 

void Mathematics::Vector3DToolsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ConversionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);	
}

void Mathematics::Vector3DToolsTesting
	::DistanceTest()
{
	FloatVector3D firstVector(3.0f,4.0f,5.0f);

	ASSERT_APPROXIMATE(FloatVector3DTools::VectorMagnitude(firstVector), FloatMath::Sqrt(50.0f),1e-8f);
	ASSERT_APPROXIMATE(FloatVector3DTools::VectorMagnitudeSquared(firstVector),50.0f,1e-8f);

	FloatVector3D secondVector(6.0f,8.0f,5.0f);

	ASSERT_APPROXIMATE(FloatVector3DTools::Distance(firstVector,secondVector),5.0f,1e-8f);
	ASSERT_APPROXIMATE(FloatVector3DTools::DistanceSquared(firstVector,secondVector),25.0f,1e-8f);
}

void Mathematics::Vector3DToolsTesting
	::ProductTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
 		DoubleVector3D firstVector(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		DoubleVector3D secondVector(randomDistribution(generator),
			                   randomDistribution(generator),
							   randomDistribution(generator));

		double dotProduct = firstVector[0] * secondVector[0] +
			                firstVector[1] * secondVector[1] +
							firstVector[2] * secondVector[2];

		ASSERT_APPROXIMATE(DoubleVector3DTools::DotProduct(firstVector,secondVector),dotProduct,1e-10);

		DoubleVector3D crossProduct(firstVector.GetY() * secondVector.GetZ() - firstVector.GetZ() * secondVector.GetY(),
							   firstVector.GetZ() * secondVector.GetX() - firstVector.GetX() * secondVector.GetZ(),
							   firstVector.GetX() * secondVector.GetY() - firstVector.GetY() * secondVector.GetX());

		ASSERT_TRUE(DoubleVector3DTools::Approximate(DoubleVector3DTools::CrossProduct(firstVector,secondVector),crossProduct));
		
		ASSERT_TRUE(DoubleVector3DTools::Approximate(DoubleVector3DTools::CrossProductWithReduceMultiplication(firstVector,secondVector),crossProduct));

		crossProduct.Normalize();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(DoubleVector3DTools::UnitCrossProduct(firstVector,secondVector),crossProduct));

		DoubleVector3D thirdVector(randomDistribution(generator),randomDistribution(generator),randomDistribution(generator));

		ASSERT_APPROXIMATE(DoubleVector3DTools::ScalarTripleProduct(firstVector,secondVector,thirdVector),
						   DoubleVector3DTools::DotProduct(DoubleVector3DTools::CrossProduct(firstVector,secondVector),thirdVector),1e-10);
	}
}

void Mathematics::Vector3DToolsTesting
	::ProjectionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
 		DoubleVector3D firstVector(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		DoubleVector3D secondVector(randomDistribution(generator),
			                   randomDistribution(generator),
							   randomDistribution(generator));

		double moduleSquare = DoubleVector3DTools::VectorMagnitudeSquared(secondVector);
		DoubleVector3D parallelVector =  secondVector *  (DoubleVector3DTools::DotProduct(firstVector,  secondVector) / moduleSquare);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(parallelVector,DoubleVector3DTools::ParallelVectorLhsToRhs(firstVector,secondVector)));

		DoubleVector3D apeakVector = firstVector - parallelVector;

		ASSERT_TRUE(DoubleVector3DTools::Approximate(apeakVector,DoubleVector3DTools::ApeakVectorLhsToRhs(firstVector,secondVector)));

		double angle = DoubleMath::ACos(DoubleVector3DTools::DotProduct(firstVector,secondVector) / (DoubleVector3DTools::VectorMagnitude(firstVector) * DoubleVector3DTools::VectorMagnitude(secondVector)));

		ASSERT_APPROXIMATE(angle,DoubleVector3DTools::GetVectorIncludedAngle(firstVector,secondVector),1e-10);

		DoubleVector3D reflectionVector = 2 * DoubleVector3DTools::DotProduct(secondVector,firstVector) * secondVector - firstVector;

		ASSERT_TRUE(DoubleVector3DTools::Approximate(reflectionVector,DoubleVector3DTools::ReflectionVector(firstVector,secondVector)));

		double consistencyRatio(0.6);		

		double conphiSquare = DoubleVector3DTools::DotProduct(-secondVector,firstVector) * DoubleVector3DTools::DotProduct(-secondVector,firstVector);
		double consistencyRatioSquare = consistencyRatio * consistencyRatio;
		double costheta = 1 / consistencyRatioSquare * DoubleMath::Sqrt(1 - consistencyRatioSquare * (1 - conphiSquare));

		DoubleVector3D refractionVector = consistencyRatio * firstVector - (costheta + consistencyRatio * DoubleVector3DTools::DotProduct(-secondVector,firstVector)) * secondVector;

		ASSERT_TRUE(DoubleVector3DTools::Approximate(refractionVector,DoubleVector3DTools::RefractionVector(firstVector,secondVector,consistencyRatio)));
	}
}

void Mathematics::Vector3DToolsTesting
	::ConversionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
 		DoubleVector3D firstVector(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		double delta = Half(firstVector.GetZ());

		DoubleVector3D secondVector(firstVector.GetX() * delta,firstVector.GetY() * delta,firstVector.GetZ());

		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondVector,DoubleVector3DTools::FeatheringOutZAxes(firstVector,Half)));

		DoubleVector3D twistZAxesVector = DoubleVector3DTools::TwistZAxes(firstVector,Half);

		ASSERT_APPROXIMATE(twistZAxesVector.GetZ(),firstVector.GetZ(),1e-10);

		double testValue = (firstVector.GetX() - firstVector.GetY()) * (DoubleMath::Sin(delta) + DoubleMath::Cos(delta));

		ASSERT_APPROXIMATE(twistZAxesVector.GetX() + twistZAxesVector.GetY(),testValue,1e-10);

		double curvatureRadius = randomDistribution(generator);
		double bendCenter = randomDistribution(generator);
		double bendAreaMin = randomDistribution(generator);
		double bendAreaMax = bendAreaMin + 1000000.0;

		DoubleVector3D bendYAxesVector =	DoubleVector3DTools::BendYAxes(firstVector,curvatureRadius,bendCenter,bendAreaMin,bendAreaMax);

		ASSERT_APPROXIMATE(bendYAxesVector.GetX(),firstVector.GetX(),1e-10);

		double y = firstVector.GetY();

		if(firstVector.GetY() <= bendAreaMin)
			y = bendAreaMin;
		else if(firstVector.GetY() >= bendAreaMax)
			y = bendAreaMax;

		delta = 1 / curvatureRadius * (y - bendCenter);

		if(bendAreaMin <= firstVector.GetY() && firstVector.GetY() <= bendAreaMax)
		{
			ASSERT_APPROXIMATE(bendYAxesVector.GetY(),-DoubleMath::Sin(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter,1e-10);

			ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),-DoubleMath::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter,1e-10);		
		}
		else if(firstVector.GetY() < bendAreaMin)
		{
			ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
							   -DoubleMath::Sin(delta) *  (firstVector.GetZ() - curvatureRadius) +  bendCenter + DoubleMath::Cos(delta) *   (firstVector.GetY() - bendAreaMin),
						       1e-10);

			ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
				               -DoubleMath::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + bendCenter + DoubleMath::Sin(delta) * (firstVector.GetY() - bendAreaMin),
						       1e-10);			
		}
		else 
		{
			ASSERT_APPROXIMATE(bendYAxesVector.GetY(),
				              (-DoubleMath::Sin(delta) * (firstVector.GetZ() - curvatureRadius) + curvatureRadius + DoubleMath::Cos(delta)  * (firstVector.GetY() - bendAreaMax)),
						       1e-10);

			ASSERT_APPROXIMATE(bendYAxesVector.GetZ(),
				               (-DoubleMath::Cos(delta) * (firstVector.GetZ() - curvatureRadius) + curvatureRadius + DoubleMath::Sin(delta) * (firstVector.GetY() - bendAreaMax)),
						       1e-10);
		}
	}
}

void Mathematics::Vector3DToolsTesting
	::CompareTest()
{
	FloatVector3D firstVector(6.0f,8.0f,9.0f);
	FloatVector3D secondVector(7.0f,5.0f,19.0f);

	ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector,firstVector));
	ASSERT_TRUE(FloatVector3DTools::Approximate(secondVector,secondVector));
	ASSERT_FALSE(FloatVector3DTools::Approximate(firstVector,secondVector));

	ASSERT_TRUE(firstVector == firstVector);
	ASSERT_FALSE(firstVector == secondVector);
	ASSERT_TRUE(firstVector != secondVector);
	ASSERT_TRUE(firstVector < secondVector);
	ASSERT_TRUE(firstVector <= secondVector);
	ASSERT_FALSE(firstVector > secondVector);
	ASSERT_FALSE(firstVector >= secondVector);

	GetStream() << "以下是调试信息：\n";
	GetStream() << firstVector << '\n';
	GetStream() << secondVector << '\n';
}

void Mathematics::Vector3DToolsTesting
	::OtherCalculateTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -100.0,100.0 };

	const auto testLoopCount = GetTestLoopCount();

	vector<DoubleVector3D> vectors;

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D eachVector(randomDistribution(generator),randomDistribution(generator),randomDistribution(generator));

		vectors.push_back(eachVector);
	}
	
	DoubleAxesAlignBoundingBox3D aabb = DoubleVector3DTools::ComputeExtremes(vectors);
	DoubleVector3D minVector = aabb.GetMinPoint();
	DoubleVector3D maxVector = aabb.GetMaxPoint();

	for(const auto& eachVector:vectors)
	{
		ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
		ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
		ASSERT_TRUE(minVector.GetZ() <= eachVector.GetZ());
		ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
		ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
		ASSERT_TRUE(eachVector.GetZ() <= maxVector.GetZ());
	}

	DoubleVector3D firstVector(randomDistribution(generator),
			              randomDistribution(generator),
						  randomDistribution(generator));
	DoubleVector3D secondVector(randomDistribution(generator),
			               randomDistribution(generator),
						   randomDistribution(generator));

	DoubleVector3D thirdVector(randomDistribution(generator),
			               randomDistribution(generator),
						   randomDistribution(generator));

	vectors.clear();
	vectors.push_back(firstVector);
	vectors.push_back(secondVector);
	vectors.push_back(thirdVector);

	DoubleVector3DTools::Vector3DOrthonormalize firstOrthonormalize = DoubleVector3DTools::Orthonormalize(firstVector,secondVector,thirdVector);

	DoubleVector3DTools::Vector3DOrthonormalize secondOrthonormaliz = DoubleVector3DTools::Orthonormalize(vectors);

	firstVector.Normalize();
	double dot0 = DoubleVector3DTools::DotProduct(firstVector,secondVector); 
	secondVector -= dot0 * firstVector;
	secondVector.Normalize();

	double dot1 = DoubleVector3DTools::DotProduct(secondVector,thirdVector);
	dot0 =  DoubleVector3DTools::DotProduct(firstVector,thirdVector);
	thirdVector -= dot0 * firstVector + dot1 * secondVector;
	thirdVector.Normalize();

	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstVector, firstOrthonormalize.GetUVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(secondVector,firstOrthonormalize.GetVVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(thirdVector,firstOrthonormalize.GetWVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstVector,secondOrthonormaliz.GetUVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(secondVector,secondOrthonormaliz.GetVVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(thirdVector,secondOrthonormaliz.GetWVector()));

	DoubleVector3D fourthVector(randomDistribution(generator),
		                   randomDistribution(generator),
						   randomDistribution(generator));


	DoubleVector3DOrthonormalBasis firstOrthonormalBasis = DoubleVector3DTools::GenerateOrthonormalBasis(fourthVector);

	fourthVector.Normalize();

	DoubleVector3DOrthonormalBasis secondOrthonormalBasis = DoubleVector3DTools::GenerateComplementBasis(fourthVector);

	ASSERT_TRUE(DoubleVector3DTools::Approximate(fourthVector,firstOrthonormalBasis.GetWVector()));
	ASSERT_TRUE(DoubleVector3DTools::Approximate(fourthVector, firstOrthonormalBasis.GetWVector()));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstOrthonormalBasis.GetUVector(),secondOrthonormalBasis.GetUVector()));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstOrthonormalBasis.GetVVector(), secondOrthonormalBasis.GetVVector()));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstOrthonormalBasis.GetWVector(),
		        DoubleVector3DTools::CrossProduct(secondOrthonormalBasis.GetUVector(),firstOrthonormalBasis.GetVVector())));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(firstOrthonormalBasis.GetUVector(),
		        DoubleVector3DTools::CrossProduct(firstOrthonormalBasis.GetVVector(),secondOrthonormalBasis.GetWVector())));

	ASSERT_TRUE(DoubleVector3DTools::Approximate(secondOrthonormalBasis.GetVVector(),
		        DoubleVector3DTools::CrossProduct(firstOrthonormalBasis.GetWVector(),firstOrthonormalBasis.GetUVector())));
					  
}

double Mathematics::Vector3DToolsTesting
	::Half( double value )
{
	return value * 0.5;
}

