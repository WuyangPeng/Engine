// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:14)

#include "Vector3DTesting.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/BarycentricCoordinates.h"
#include "Mathematics/Algebra/Vector3DTools.h"

using std::uniform_real;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class Vector3D<float>;
	template class Vector3D<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3DTesting) 

void Mathematics::Vector3DTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BarycentricsTest);
}

void Mathematics::Vector3DTesting
	::ConstructionTest()
{
// 	FloatVector3D firstVector;
// 
// 	ASSERT_APPROXIMATE(firstVector[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[2],0.0f,1e-8f);
// 
// 	FloatVector3D::Tuple3 tuple(1.0f,3.0f,13.0f); 
// 
// 	FloatVector3D secondVector(tuple);
// 
// 	ASSERT_APPROXIMATE(secondVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[1],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[2],13.0f,1e-8f);
// 
// 	DoubleVector3D thirdVector(6.0,9.0,34.0);
// 
// 	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[1],9.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[2],34.0,1e-10);
// 
// 	FloatVector3D fourthVector(thirdVector);
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],6.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],9.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[2],34.0f,1e-8f);
// 
// 	fourthVector = tuple;
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[2],13.0f,1e-8f);
// 
// 	FloatVector2D fifthVector(3.0f,8.0f);
// 	DoubleVector3D sixthVector(fifthVector);
// 
// 	ASSERT_APPROXIMATE(sixthVector[0],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(sixthVector[1],8.0f,1e-8f);
// 	ASSERT_APPROXIMATE(sixthVector[2],0.0f,1e-8f);
// 
// 	FloatVector4D seventhVector(3.0f,8.0f,60.0f,1.0f);
// 	DoubleVector3D eighthVector(seventhVector);
// 
// 	ASSERT_APPROXIMATE(eighthVector[0],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(eighthVector[1],8.0f,1e-8f);
// 	ASSERT_APPROXIMATE(eighthVector[2],60.0f,1e-8f);
// 
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_One[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_One[1],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_One[2],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_Zero[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_Zero[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::sm_Zero[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnit()[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnit()[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnit()[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitY()[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitY()[1],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitY()[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitZ()[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitZ()[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector3D::GetUnitZ()[2],1.0f,1e-8f);
}

void Mathematics::Vector3DTesting
	::AccessTest()
{
	DoubleVector3D firstVector(6.0,9.0,4.0);

	ASSERT_APPROXIMATE(firstVector.GetX(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),9.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),4.0,1e-10);
	ASSERT_FALSE(firstVector.IsZero());

	DoubleVector3D secondVector;
	ASSERT_TRUE(secondVector.IsZero());

	firstVector.ZeroOut();
	ASSERT_TRUE(firstVector.IsZero());

	firstVector.SetCoordinate(9.0,6.0,8.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),9.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),8.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(7.0);
	firstVector.SetZ(17.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),3.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),7.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),17.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(4.0);
	firstVector.SetZ(0.0);

	ASSERT_FALSE(firstVector.IsNormalize());

	firstVector.Normalize();

	ASSERT_TRUE(firstVector.IsNormalize());

	ASSERT_APPROXIMATE(firstVector.GetX(),0.6,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),0.8,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),0.0,1e-10);
}

void Mathematics::Vector3DTesting
	::CalculateTest()
{
	FloatVector3D firstVector(26.0f,91.0f,8.0f);

	FloatVector3D secondVector = -firstVector;
	ASSERT_APPROXIMATE(secondVector.GetX(),-26.0,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),-91.0,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetZ(),-8.0,1e-8f);

	secondVector[0] = 3.0f;
	secondVector[1] = 7.0f;
	secondVector[2] = 17.0f;

	ASSERT_APPROXIMATE(secondVector.GetX(),3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),7.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetZ(),17.0f,1e-8f);

	const DoubleVector3D thirdVector(6.0,5.0,15.0);

	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[2],15.0,1e-10);

	DoubleVector3D fourthVector(9.0,3.0,3.0);
	fourthVector += thirdVector;
	ASSERT_APPROXIMATE(fourthVector[0],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],8.0,0.1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],18.0,1e-10);

	DoubleVector3D fifthVector = thirdVector + fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],21.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],13.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],33.0,1e-10);

	fifthVector -= fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],15.0,1e-10);

	fourthVector = fifthVector - thirdVector;

	ASSERT_APPROXIMATE(fourthVector[0],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],0.0,1e-10);

	fifthVector *= 6.0;

	ASSERT_APPROXIMATE(fifthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],90.0,1e-10);

	fourthVector = 0.5 * fifthVector;

	ASSERT_APPROXIMATE(fourthVector[0],18.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],45.0,1e-10);

	fourthVector = fifthVector * 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],72.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],60.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],180.0,1e-10);

	fourthVector /= 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],90.0,1e-10);

	fifthVector = fourthVector / 3.0;

	ASSERT_APPROXIMATE(fifthVector[0],12.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],10.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],30.0,1e-10);
}

void Mathematics::Vector3DTesting
	::BarycentricsTest()
{
	DoubleVector3D firstVector(1.0,0.0,0.0);
	DoubleVector3D secondVector(0.0,1.0,0.0);
	DoubleVector3D thirdVector(0.0,0.0,1.0);
	DoubleVector3D fourthVector(0.0,0.0,0.0);

	DoubleVector3D::BarycentricCoordinates firstCoordinates = firstVector.GetBarycentrics(firstVector,secondVector, thirdVector,fourthVector);

	ASSERT_TRUE(firstCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(firstCoordinates[0],1.0,1e-10);
	ASSERT_APPROXIMATE(firstCoordinates[1],0.0,1e-10);
	ASSERT_APPROXIMATE(firstCoordinates[2],0.0,1e-10);
	ASSERT_APPROXIMATE(firstCoordinates[3],0.0,1e-10);

	DoubleVector3D::BarycentricCoordinates secondCoordinates = secondVector.GetBarycentrics(firstVector,secondVector,thirdVector,fourthVector);

	ASSERT_TRUE(secondCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(secondCoordinates[0],0.0,1e-10);
	ASSERT_APPROXIMATE(secondCoordinates[1],1.0,1e-10);
	ASSERT_APPROXIMATE(secondCoordinates[2],0.0,1e-10);
	ASSERT_APPROXIMATE(secondCoordinates[3],0.0,1e-10);

	DoubleVector3D::BarycentricCoordinates thirdCoordinates = thirdVector.GetBarycentrics(firstVector,secondVector,thirdVector,fourthVector);

	ASSERT_TRUE(thirdCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(thirdCoordinates[0],0.0,1e-10);
	ASSERT_APPROXIMATE(thirdCoordinates[1],0.0,1e-10);
	ASSERT_APPROXIMATE(thirdCoordinates[2],1.0,1e-10);
	ASSERT_APPROXIMATE(thirdCoordinates[3],0.0,1e-10);

	DoubleVector3D::BarycentricCoordinates fourthCoordinates = fourthVector.GetBarycentrics(firstVector,secondVector,thirdVector,fourthVector);

	ASSERT_TRUE(fourthCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(fourthCoordinates[0],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthCoordinates[1],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthCoordinates[2],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthCoordinates[3],1.0,1e-10);

	DoubleVector3D fifthVector(0.1,0.1,0.1);

	DoubleVector3D::BarycentricCoordinates fifthCoordinates = fifthVector.GetBarycentrics(firstVector,secondVector,thirdVector,fourthVector);

	ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());
	ASSERT_APPROXIMATE(fifthCoordinates[0] + fifthCoordinates[1] + fifthCoordinates[2] + fifthCoordinates[3],1.0,1e-10);

	default_random_engine generator{};

	uniform_real<double> randomDistribution{ -10.0,10.0 };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D sixthVector(randomDistribution(generator),
			                  randomDistribution(generator),
							  randomDistribution(generator));

		DoubleVector3D::BarycentricCoordinates sixthCoordinates = sixthVector.GetBarycentrics(firstVector,secondVector,thirdVector,fourthVector);

		ASSERT_TRUE(sixthCoordinates.IsBarycentricCoordinatesValid());

		DoubleVector3D difference[4] { firstVector - fourthVector,secondVector - fourthVector, thirdVector - fourthVector, sixthVector - fourthVector };

		double det = DoubleVector3DTools::ScalarTripleProduct(difference[1], difference[2], difference[0]);

		DoubleVector3D e1CrossE2 = DoubleVector3DTools::CrossProduct(difference[1], difference[2]);
		DoubleVector3D e2CrossE0 = DoubleVector3DTools::CrossProduct(difference[2], difference[0]);
		DoubleVector3D e0CrossE1 = DoubleVector3DTools::CrossProduct(difference[0], difference[1]);			
		
		double bary0 = DoubleVector3DTools::DotProduct(difference[3],e1CrossE2) / det;
		double bary1 = DoubleVector3DTools::DotProduct(difference[3],e2CrossE0) / det;
		double bary2 = DoubleVector3DTools::DotProduct(difference[3],e0CrossE1) / det;
		double bary3 = 1.0 - bary0 - bary1 - bary2;		

		ASSERT_TRUE(sixthCoordinates.IsBarycentricCoordinatesValid());
		ASSERT_APPROXIMATE(sixthCoordinates[0],bary0,1e-10);
		ASSERT_APPROXIMATE(sixthCoordinates[1],bary1,1e-10);
		ASSERT_APPROXIMATE(sixthCoordinates[2],bary2,1e-10);
		ASSERT_APPROXIMATE(sixthCoordinates[3],bary3,1e-10);
	}
}


