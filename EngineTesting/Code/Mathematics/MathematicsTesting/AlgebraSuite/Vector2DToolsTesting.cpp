// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 11:36)

#include "Vector2DToolsTesting.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2DDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  

using std::vector;
using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class Vector2DTools<float>;
	template class Vector2DTools<double>;	
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector2DToolsTesting) 

void Mathematics::Vector2DToolsTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DistanceTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProductTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(PerpTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);	
}

void Mathematics::Vector2DToolsTesting
	::DistanceTest()
{
	FloatVector2D firstVector(3.0f,4.0f);

	ASSERT_APPROXIMATE(FloatVector2DTools::VectorMagnitude(firstVector),5.0f,1e-8f);
	ASSERT_APPROXIMATE(FloatVector2DTools::VectorMagnitudeSquared(firstVector),  25.0f,1e-8f);

	FloatVector2D secondVector(6.0f,8.0f);

	ASSERT_APPROXIMATE(FloatVector2DTools::Distance(firstVector,secondVector),  5.0f,1e-8f);
	ASSERT_APPROXIMATE(FloatVector2DTools::DistanceSquared(firstVector,secondVector), 25.0f,1e-8f);
}

void Mathematics::Vector2DToolsTesting
	::ProductTest()
{
	DoubleVector2D firstVector(-4.0,3.0);
	DoubleVector2D secondVector(8.0,6.0);

	ASSERT_APPROXIMATE(DoubleVector2DTools::DotProduct(firstVector,secondVector), -14.0,1e-8f);
	ASSERT_APPROXIMATE(DoubleVector2DTools::PseudoCrossProduct(firstVector,secondVector), -48.0,1e-8f);
}

void Mathematics::Vector2DToolsTesting
	::ProjectionTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -10.0f,10.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop) 
	{
		DoubleVector2D firstVector(randomDistribution(generator),
			                  randomDistribution(generator));

		DoubleVector2D secondVector(randomDistribution(generator),
			                   randomDistribution(generator));
	
		double moduleSquare = DoubleVector2DTools::VectorMagnitudeSquared(secondVector);
		DoubleVector2D parallelVector =  secondVector * (DoubleVector2DTools::DotProduct(firstVector, secondVector) / moduleSquare);

		ASSERT_TRUE(DoubleVector2DTools::Approximate(DoubleVector2DTools::ParallelVectorLhsToRhs(firstVector,secondVector),parallelVector));

		DoubleVector2D apeakVector = firstVector - parallelVector;

		ASSERT_TRUE(DoubleVector2DTools::Approximate(DoubleVector2DTools::ApeakVectorLhsToRhs(firstVector,secondVector),apeakVector));

		double angle = DoubleMath::ACos(DoubleVector2DTools::DotProduct(firstVector,secondVector) / (DoubleVector2DTools::VectorMagnitude(firstVector) * DoubleVector2DTools::VectorMagnitude(secondVector)));

		ASSERT_APPROXIMATE(angle,DoubleVector2DTools::GetVectorIncludedAngle(firstVector,secondVector),1e-10);
	}
}

void Mathematics::Vector2DToolsTesting
	::PerpTest()
{
	FloatVector2D firstVector(3.0f,4.0f);
	FloatVector2D perpVector(4.0f,-3.0f);

	ASSERT_TRUE(FloatVector2DTools::Approximate(FloatVector2DTools::GetPerp(firstVector),perpVector));

	perpVector.Normalize();

	ASSERT_TRUE(FloatVector2DTools::Approximate(FloatVector2DTools::GetUnitPerp(firstVector),perpVector));

	float dotPerp = firstVector.GetX() * perpVector.GetY() - firstVector.GetY() * perpVector.GetX();

	ASSERT_APPROXIMATE(FloatVector2DTools::DotPerp(firstVector,perpVector), dotPerp,1e-8f);	
}

void Mathematics::Vector2DToolsTesting
	::CompareTest()
{
	FloatVector2D firstVector(6.0f,8.0f);
	FloatVector2D secondVector(7.0f,5.0f);

	ASSERT_TRUE(FloatVector2DTools::Approximate(firstVector,firstVector));
	ASSERT_TRUE(FloatVector2DTools::Approximate(secondVector,secondVector));
	ASSERT_FALSE(FloatVector2DTools::Approximate(firstVector,secondVector));

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

void Mathematics::Vector2DToolsTesting
	::OtherCalculateTest()
{
	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -10.0f,10.0f };

	const auto testLoopCount = GetTestLoopCount();	

	vector<DoubleVector2D> vectors;

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D eachVector(randomDistribution(generator),randomDistribution(generator));

		vectors.push_back(eachVector);
	}
	
	DoubleAxesAlignBoundingBox2D aabb = DoubleVector2DTools::ComputeExtremes(vectors);
	DoubleVector2D minVector = aabb.GetMinPoint();
	DoubleVector2D maxVector = aabb.GetMaxPoint();

	for(const auto& eachVector:vectors)
	{
		ASSERT_TRUE(minVector.GetX() <= eachVector.GetX());
		ASSERT_TRUE(minVector.GetY() <= eachVector.GetY());
		ASSERT_TRUE(eachVector.GetX() <= maxVector.GetX());
		ASSERT_TRUE(eachVector.GetY() <= maxVector.GetY());
	}	

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstVector(randomDistribution(generator), randomDistribution(generator));
		DoubleVector2D secondVector(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2DTools::Vector2DOrthonormalize orthonormalize =  DoubleVector2DTools::Orthonormalize(firstVector,secondVector);
		
		firstVector.Normalize();
		
		double dot = DoubleVector2DTools::DotProduct(firstVector,secondVector); 
		secondVector -= firstVector * dot;
		secondVector.Normalize();
		
		ASSERT_TRUE(DoubleVector2DTools::Approximate(firstVector,orthonormalize.GetUVector()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(secondVector, orthonormalize.GetVVector()));
		
		DoubleVector2D thirdVector(randomDistribution(generator), randomDistribution(generator));
		
		DoubleVector2DOrthonormalBasis orthonormalBasis =  DoubleVector2DTools::GenerateOrthonormalBasis(thirdVector);
		
		thirdVector.Normalize();
		
		ASSERT_TRUE(DoubleVector2DTools::Approximate(thirdVector,  orthonormalBasis.GetUVector()));
		ASSERT_TRUE(DoubleVector2DTools::Approximate(DoubleVector2DTools::GetPerp(thirdVector),  orthonormalBasis.GetVVector()));
	}
}

