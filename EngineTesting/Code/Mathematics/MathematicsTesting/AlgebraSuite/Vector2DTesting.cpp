// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:30)

#include "Vector2DTesting.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
 
using std::uniform_real;
using std::default_random_engine;

 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector2DTesting) 

void Mathematics::Vector2DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BarycentricsTest);
}

void Mathematics::Vector2DTesting
	::ConstructionTest()
{
// 	FloatVector2D firstVector;
// 	
// 	ASSERT_APPROXIMATE(firstVector[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[1],0.0f,1e-8f);
// 
// 	FloatVector2D::Tuple2 tuple(1.0f,3.0f);
// 
// 	FloatVector2D secondVector(tuple);
// 
// 	ASSERT_APPROXIMATE(secondVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[1],3.0f,1e-8f);
// 
// 	DoubleVector2D thirdVector(6.0,9.0);
// 
// 	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[1],9.0,1e-10);
// 
// 	FloatVector2D fourthVector(thirdVector);
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],6.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],9.0f,1e-8f); 
// 
// 	fourthVector = tuple;
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],3.0f,1e-8f);
// 
// 	DoubleVector3D fifthVector(3.0,8.0,60.0);
// 	FloatVector2D sixthVector(fifthVector);
// 
// 	ASSERT_APPROXIMATE(sixthVector[0],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(sixthVector[1],8.0f,1e-8f);
// 
// 	FloatVector4D seventhVector(3.0f,8.0f,60.0f,1.0f);
// 	DoubleVector2D eighthVector(seventhVector);
// 
// 	ASSERT_APPROXIMATE(eighthVector[0],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(eighthVector[1],8.0f,1e-8f);
// 
// 	ASSERT_APPROXIMATE(FloatVector2D::sm_One[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::sm_One[1],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::sm_Zero[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::sm_Zero[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::GetUnit()[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::GetUnit()[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::GetUnitY()[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector2D::GetUnitY()[1],1.0f,1e-8f);
}

void Mathematics::Vector2DTesting
	::AccessTest()
{
	DoubleVector2D firstVector(6.0,9.0);

	ASSERT_APPROXIMATE(firstVector.GetX(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),9.0,1e-10);
	ASSERT_FALSE(firstVector.IsZero());

	DoubleVector2D secondVector;
	ASSERT_TRUE(secondVector.IsZero());

	firstVector.ZeroOut();
	ASSERT_TRUE(firstVector.IsZero());

	firstVector.SetCoordinate(9.0,6.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),9.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),6.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(7.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),3.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),7.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(4.0);

	ASSERT_FALSE(firstVector.IsNormalize());

	firstVector.Normalize();

	ASSERT_TRUE(firstVector.IsNormalize());

	ASSERT_APPROXIMATE(firstVector.GetX(),0.6,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),0.8,1e-10);
}

void Mathematics::Vector2DTesting
	::CalculateTest()
{
	FloatVector2D firstVector(26.0f,91.0f);

	FloatVector2D secondVector = -firstVector;
	ASSERT_APPROXIMATE(secondVector.GetX(),-26.0,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),-91.0,1e-8f);

	secondVector[0] = 3.0f;
	secondVector[1] = 7.0f;

	ASSERT_APPROXIMATE(secondVector.GetX(),3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),7.0f,1e-8f);

	const DoubleVector2D thirdVector(6.0,5.0);

	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[1],5.0,1e-10);

	DoubleVector2D fourthVector(9.0,3.0);
	fourthVector += thirdVector;
	ASSERT_APPROXIMATE(fourthVector[0],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],8.0,1e-10);

	DoubleVector2D fifthVector = thirdVector + fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],21.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],13.0,1e-10);

	fifthVector -= fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],5.0,1e-10);

	fourthVector = fifthVector - thirdVector;

	ASSERT_APPROXIMATE(fourthVector[0],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],0.0,1e-10);

	fifthVector *= 6.0;

	ASSERT_APPROXIMATE(fifthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],30.0,1e-10);

	fourthVector = 0.5 * fifthVector;

	ASSERT_APPROXIMATE(fourthVector[0],18.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],15.0,1e-10);

	fourthVector = fifthVector * 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],72.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],60.0,1e-10);

	fourthVector /= 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],30.0,1e-10);

	fifthVector = fourthVector / 3.0;

	ASSERT_APPROXIMATE(fifthVector[0],12.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],10.0,1e-10);
}

void Mathematics::Vector2DTesting
	::BarycentricsTest()
{
	DoubleVector2D firstVector(1.0,0.0);
	DoubleVector2D secondVector(0.0,0.0);
	DoubleVector2D thirdVector(0.0,1.0);

	DoubleVector2D::BarycentricCoordinates firstCoordinates = firstVector.GetBarycentrics(firstVector,secondVector,thirdVector);

	ASSERT_TRUE(firstCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(firstCoordinates[0],1.0,1e-10);
	ASSERT_APPROXIMATE(firstCoordinates[1],0.0,1e-10);
	ASSERT_APPROXIMATE(firstCoordinates[2],0.0,1e-10);

	DoubleVector2D::BarycentricCoordinates secondCoordinates = secondVector.GetBarycentrics(firstVector,secondVector,thirdVector);

	ASSERT_TRUE(secondCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(secondCoordinates[0],0.0,1e-10);
	ASSERT_APPROXIMATE(secondCoordinates[1],1.0,1e-10);
	ASSERT_APPROXIMATE(secondCoordinates[2],0.0,1e-10);

	DoubleVector2D::BarycentricCoordinates thirdCoordinates = thirdVector.GetBarycentrics(firstVector,secondVector,thirdVector);

	ASSERT_TRUE(thirdCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(thirdCoordinates[0],0.0,1e-10);
	ASSERT_APPROXIMATE(thirdCoordinates[1],0.0,1e-10);
	ASSERT_APPROXIMATE(thirdCoordinates[2],1.0,1e-10);

	DoubleVector2D fourthVector(0.1,0.1);

	DoubleVector2D::BarycentricCoordinates fourthCoordinates = fourthVector.GetBarycentrics(firstVector,secondVector,thirdVector);

	ASSERT_TRUE(fourthCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(fourthCoordinates[0] + fourthCoordinates[1] + fourthCoordinates[2] ,1.0,1e-10); 

	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -10.0f,10.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D fifthVector(randomDistribution(generator),randomDistribution(generator));

		DoubleVector2D::BarycentricCoordinates fifthCoordinates = fifthVector.GetBarycentrics(firstVector,secondVector,thirdVector);

		ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());

		DoubleVector2D difference[3] { firstVector - thirdVector, secondVector - thirdVector,fifthVector - thirdVector };

		double det = DoubleVector2DTools::DotPerp(difference[0], difference[1]);
		
		double bary0 = DoubleVector2DTools::DotPerp(difference[2],difference[1]) / det;
		double bary1 = DoubleVector2DTools::DotPerp(difference[0],difference[2]) / det;
		double bary2 = 1.0 - bary0 - bary1;		

		ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());
		ASSERT_APPROXIMATE(fifthCoordinates[0],bary0,1e-10);
		ASSERT_APPROXIMATE(fifthCoordinates[1],bary1,1e-10);
		ASSERT_APPROXIMATE(fifthCoordinates[2],bary2,1e-10);
	}
}



