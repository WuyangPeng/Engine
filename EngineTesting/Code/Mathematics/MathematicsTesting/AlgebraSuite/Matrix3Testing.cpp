// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/21 16:05)

#include "Matrix3Testing.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::vector;
using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Matrix3<float>;
	template class Matrix3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix3Testing) 

void Mathematics::Matrix3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(EulerTest);
}

void Mathematics::Matrix3Testing
	::ConstructionTest()
{
    FloatMatrix3 firstMatrix(MatrixInitType::Zero);

	ASSERT_APPROXIMATE(firstMatrix(0,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,2),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,2),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,2),0.0f,1e-8f);

	FloatMatrix3 secondMatrix(MatrixInitType::Identity);

	ASSERT_APPROXIMATE(secondMatrix(0,0),1.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,2),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,1),1.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,2),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,0),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,1),0.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,2),1.0f,1e-8f);

	DoubleMatrix3 thirdMatrix(3.0,6.0,1.0,6.2,5.2,1.01,3.1,2.0,6.06);

	ASSERT_APPROXIMATE(thirdMatrix(0,0),3.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),6.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(0,2),1.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),6.2,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),5.2,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(1,2),1.01,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(2,0),3.1,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(2,1),2.0,1e-10);
	ASSERT_APPROXIMATE(thirdMatrix(2,2),6.06,1e-10);
	
	vector<double> doubleVector{ 6.0,6.2,9.0,2.0,9.5,3.1,4.2,2.0,6.1 };

	DoubleMatrix3 fourthMatrix(doubleVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(fourthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(0,1),6.2,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(0,2),9.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(1,0),2.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(1,1),9.5,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(1,2),3.1,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(2,0),4.2,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(2,1),2.0,1e-10);
	ASSERT_APPROXIMATE(fourthMatrix(2,2),6.1,1e-10);

	DoubleMatrix3 fifthMatrix(doubleVector,MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(fifthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(0,1),2.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(0,2),4.2,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(1,0),6.2,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(1,1),9.5,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(1,2),2.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(2,0),9.0,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(2,1),3.1,1e-10);
	ASSERT_APPROXIMATE(fifthMatrix(2,2),6.1,1e-10);
	
	FloatVector3D firstVector(6.0f,3.0f,5.0f);
	FloatVector3D secondVector(8.0f,3.1f,9.0f);
	FloatVector3D thirdVector(18.0f,13.1f,19.0f);

	FloatMatrix3 sixthMatrix(firstVector,secondVector,thirdVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(sixthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(0,1),3.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(0,2),5.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(1,0),8.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(1,1),3.1f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(1,2),9.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(2,0),18.0f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(2,1),13.1f,1e-8f);
	ASSERT_APPROXIMATE(sixthMatrix(2,2),19.0f,1e-8f);

	FloatMatrix3 seventhMatrix(firstVector,secondVector,thirdVector, MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(seventhMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(0,1),8.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(0,2),18.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(1,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(1,1),3.1f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(1,2),13.1f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(2,0),5.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(2,1),9.0f,1e-8f);
	ASSERT_APPROXIMATE(seventhMatrix(2,2),19.0f,1e-8f);

	vector<FloatVector3D> vector3DVector{ firstVector,secondVector,thirdVector };

	FloatMatrix3 eighthMatrix(vector3DVector,MatrixMajorFlags::Row);

	ASSERT_APPROXIMATE(eighthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(0,1),3.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(0,2),5.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(1,0),8.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(1,1),3.1f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(1,2),9.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(2,0),18.0f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(2,1),13.1f,1e-8f);
	ASSERT_APPROXIMATE(eighthMatrix(2,2),19.0f,1e-8f);

	FloatMatrix3 ninthMatrix(vector3DVector,MatrixMajorFlags::Column);

	ASSERT_APPROXIMATE(ninthMatrix(0,0),6.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(0,1),8.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(0,2),18.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(1,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(1,1),3.1f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(1,2),13.1f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(2,0),5.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(2,1),9.0f,1e-8f);
	ASSERT_APPROXIMATE(ninthMatrix(2,2),19.0f,1e-8f);

	DoubleMatrix3 tenthMatrix(6.0,89.0,6.0);

	ASSERT_APPROXIMATE(tenthMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(1,1),89.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(tenthMatrix(2,2),6.0,1e-10);
	
	DoubleMatrix3 eleventhMatrix(MatrixRotationAxis::X,DoubleMath::GetHalfPI() / 3.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),1.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),cos(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),-sin(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),sin(DoubleMath::GetHalfPI() / 3.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),cos(DoubleMath::GetHalfPI() / 3.0),1e-10);

	eleventhMatrix.MakeRotation(MatrixRotationAxis::Y,DoubleMath::GetHalfPI() / 4.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),cos(DoubleMath::GetHalfPI() / 4.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),sin(DoubleMath::GetHalfPI() / 4.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),1.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),-sin(DoubleMath::GetHalfPI() / 4.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),cos(DoubleMath::GetHalfPI() / 4.0),1e-10);

	eleventhMatrix.MakeRotation(MatrixRotationAxis::Z,DoubleMath::GetHalfPI() / 5.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),cos(DoubleMath::GetHalfPI() / 5.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),-sin(DoubleMath::GetHalfPI() / 5.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),sin(DoubleMath::GetHalfPI() / 5.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),cos(DoubleMath::GetHalfPI() / 5.0),1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),1.0,1e-10);

	firstVector.Normalize();
	eleventhMatrix.MakeRotation(firstVector,DoubleMath::GetHalfPI() / 3.0);

	double cosValue = DoubleMath::Cos(DoubleMath::GetHalfPI() / 3.0);
	double sinValue = DoubleMath::Sin(DoubleMath::GetHalfPI() / 3.0);
	double oneMinusCos = 1.0 - cosValue;

 	ASSERT_APPROXIMATE(eleventhMatrix(0,0),static_cast<double>(firstVector[0]) * firstVector[0] * oneMinusCos + cosValue,1e-8);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1), static_cast<double>(firstVector[0]) * firstVector[1] * oneMinusCos - firstVector[2] * sinValue,1e-8);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2), static_cast<double>(firstVector[0]) * firstVector[2] * oneMinusCos + firstVector[1] * sinValue,1e-8);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0), static_cast<double>(firstVector[0]) * firstVector[1] * oneMinusCos + firstVector[2] * sinValue,1e-8);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1), static_cast<double>(firstVector[1]) * firstVector[1] * oneMinusCos + cosValue,1e-9);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2), static_cast<double>(firstVector[1]) * firstVector[2] * oneMinusCos - firstVector[0] * sinValue,1e-9);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0), static_cast<double>(firstVector[0]) * firstVector[2] * oneMinusCos - firstVector[1] * sinValue,1e-8);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1), static_cast<double>(firstVector[1]) * firstVector[2] * oneMinusCos + firstVector[0] * sinValue,1e-9);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2), static_cast<double>(firstVector[2]) * firstVector[2] * oneMinusCos + cosValue,1e-8);
	
	FloatMatrix3 twelfthMatrix(firstVector,secondVector);

	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(),twelfthMatrix(0,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(),twelfthMatrix(0,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetZ(),twelfthMatrix(0,2),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(),twelfthMatrix(1,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(),twelfthMatrix(1,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetZ(),twelfthMatrix(1,2),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetX(),twelfthMatrix(2,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetY(),twelfthMatrix(2,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetZ(),twelfthMatrix(2,2),1e-10f);
	
	eleventhMatrix.MakeZero();

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),0.0,1e-10);

	eleventhMatrix.MakeIdentity();

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),1.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),1.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),1.0,1e-10);

	eleventhMatrix.MakeDiagonal(6.0,9.0,4.0);

	ASSERT_APPROXIMATE(eleventhMatrix(0,0),6.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(0,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,1),9.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(1,2),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,0),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,1),0.0,1e-10);
	ASSERT_APPROXIMATE(eleventhMatrix(2,2),4.0,1e-10);

	secondVector.Normalize();

	DoubleMatrix3 thirteenthMatrix(secondVector,DoubleMath::GetHalfPI() / 6.0);

	cosValue = DoubleMath::Cos(DoubleMath::GetHalfPI() / 6.0);
	sinValue = DoubleMath::Sin(DoubleMath::GetHalfPI() / 6.0);
	oneMinusCos = 1.0 - cosValue;

	ASSERT_APPROXIMATE(thirteenthMatrix(0,0), static_cast<double>(secondVector[0]) * secondVector[0] * oneMinusCos + cosValue,1e-9);
	ASSERT_APPROXIMATE(thirteenthMatrix(0,1), static_cast<double>(secondVector[0]) * secondVector[1] * oneMinusCos -  secondVector[2] * sinValue,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(0,2), static_cast<double>(secondVector[0]) * secondVector[2] * oneMinusCos + secondVector[1] * sinValue,1e-9);
	ASSERT_APPROXIMATE(thirteenthMatrix(1,0), static_cast<double>(secondVector[0]) * secondVector[1] * oneMinusCos + secondVector[2] * sinValue,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(1,1), static_cast<double>(secondVector[1]) * secondVector[1] * oneMinusCos + cosValue,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(1,2), static_cast<double>(secondVector[1]) * secondVector[2] * oneMinusCos - secondVector[0] * sinValue,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(2,0), static_cast<double>(secondVector[0]) * secondVector[2] * oneMinusCos - secondVector[1] * sinValue,1e-9);
	ASSERT_APPROXIMATE(thirteenthMatrix(2,1), static_cast<double>(secondVector[1]) * secondVector[2] * oneMinusCos + secondVector[0] * sinValue,1e-10);
	ASSERT_APPROXIMATE(thirteenthMatrix(2,2), static_cast<double>(secondVector[2]) * secondVector[2] * oneMinusCos + cosValue,1e-8f);

	ninthMatrix.MakeTensorProduct(firstVector,secondVector);

	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetX(),ninthMatrix(0,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetY(),ninthMatrix(0,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetX() * secondVector.GetZ(),ninthMatrix(0,2),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetX(),ninthMatrix(1,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetY(),ninthMatrix(1,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetY() * secondVector.GetZ(),ninthMatrix(1,2),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetX(),ninthMatrix(2,0),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetY(),ninthMatrix(2,1),1e-10f);
	ASSERT_APPROXIMATE(firstVector.GetZ() * secondVector.GetZ(),ninthMatrix(2,2),1e-10f);

	eleventhMatrix = tenthMatrix;

	ASSERT_TRUE(Approximate(eleventhMatrix,tenthMatrix,1e-10));
	
	DoubleMatrix3 fourteenthMatrix(eleventhMatrix);

	ASSERT_TRUE(Approximate(eleventhMatrix,fourteenthMatrix,1e-10));
}

void Mathematics::Matrix3Testing
	::AccessTest()
{
	const FloatMatrix3 firstMatrix(3.0f,4.0f,8.1f, 3.2f,9.0f,1.0f,6.4f,5.8f,9.6f);

	ASSERT_APPROXIMATE(firstMatrix(0,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,1),4.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(0,2),8.1f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,0),3.2f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,1),9.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(1,2),1.0f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,0),6.4f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,1),5.8f,1e-8f);
	ASSERT_APPROXIMATE(firstMatrix(2,2),9.6f,1e-8f);

	DoubleMatrix3 secondMatrix(9.2,1.0,4.2,5.2,6.0,7.0,3.5,8.7,4.5);

	ASSERT_APPROXIMATE(secondMatrix(0,0),9.2,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(0,1),1.0,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(0,2),4.2,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(1,0),5.2,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(1,1),6.0,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(1,2),7.0,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(2,0),3.5,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(2,1),8.7,1e-10);
	ASSERT_APPROXIMATE(secondMatrix(2,2),4.5,1e-10);
}

void Mathematics::Matrix3Testing
	::OperatorCalculateTest()
{
	FloatMatrix3 firstMatrix(3.0f,4.0f,8.1f,3.2f,-8.0f,6.2f,1.0f,-0.1f,7.0f);

	FloatMatrix3 secondMatrix = -firstMatrix;

	ASSERT_APPROXIMATE(secondMatrix(0,0),-3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,1),-4.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(0,2),-8.1f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,0),-3.2f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,1),8.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(1,2),-6.2f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,0),-1.0f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,1),0.1f,1e-8f);
	ASSERT_APPROXIMATE(secondMatrix(2,2),-7.0f,1e-8f);

	FloatMatrix3 thirdMatrix(9.2f,3.0f,2.0f,9.0f,47.0f,3.1f,6.9f,5.5f,100.0f);

	thirdMatrix += secondMatrix;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),6.2f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-1.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,2),-6.1f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),5.8f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),55.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,2),-3.1f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(2,0),5.9f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(2,1),5.6f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(2,2),93.0f,1e-8f);

	thirdMatrix -= firstMatrix;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),3.2f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-5.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,2),-14.2f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),2.6f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),63.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,2),-9.3f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(2,0),4.9f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(2,1),5.7f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(2,2),86.0f,1e-8f);

	thirdMatrix *= 6.0f;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),19.2f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-30.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,2),-85.2f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),15.6f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),378.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,2),-55.8f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(2,0),29.4f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(2,1),34.2f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(2,2),516.0f,1e-6f);

	thirdMatrix /= 2.0f;

	ASSERT_APPROXIMATE(thirdMatrix(0,0),9.6f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(0,1),-15.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(0,2),-42.6f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(1,0),7.8f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,1),189.0f,1e-8f);
	ASSERT_APPROXIMATE(thirdMatrix(1,2),-27.9f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(2,0),14.7f,1e-6f);
	ASSERT_APPROXIMATE(thirdMatrix(2,1),17.1f,1e-5f);
	ASSERT_APPROXIMATE(thirdMatrix(2,2),258.0f,1e-8f);

	FloatMatrix3 fourthMatrix2 = firstMatrix + thirdMatrix;

	ASSERT_APPROXIMATE(fourthMatrix2(0,0),12.6f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,1),-11.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,2),-34.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,0),11.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,1),181.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,2),-21.7f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,0),15.7f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,1),17.0f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,2),265.0f,1e-8f);
	
	fourthMatrix2 = firstMatrix - thirdMatrix;

	ASSERT_APPROXIMATE(fourthMatrix2(0,0),-6.6f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,1),19.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,2),50.7f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,0),-4.6f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,1),-197.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,2),34.1f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,0),-13.7f,1e-6f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,1),-17.2f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,2),-251.0f,1e-8f);	

	fourthMatrix2 = firstMatrix * 5.0f;

	ASSERT_APPROXIMATE(fourthMatrix2(0,0),15.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,1),20.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,2),40.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,0),16.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,1),-40.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,2),31.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,0),5.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,1),-0.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,2),35.0f,1e-8f);

	fourthMatrix2 = 3.0f * firstMatrix;

	ASSERT_APPROXIMATE(fourthMatrix2(0,0),9.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,1),12.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,2),24.3f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,0),9.6f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,1),-24.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,2),18.6f,1e-5f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,0),3.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,1),-0.3f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,2),21.0f,1e-8f);

	fourthMatrix2 =  firstMatrix / (-2.0f);

	ASSERT_APPROXIMATE(fourthMatrix2(0,0),-1.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,1),-2.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(0,2),-4.05f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,0),-1.6f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,1),4.0f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(1,2),-3.1f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,0),-0.5f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,1),0.05f,1e-8f);
	ASSERT_APPROXIMATE(fourthMatrix2(2,2),-3.5f,1e-8f);
	
	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -100.0f,100.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatMatrix3 fifthMatrix(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator));

		FloatMatrix3 sixthMatrix(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator));

		FloatMatrix3 seventhMatrix(sixthMatrix);

		seventhMatrix *= fifthMatrix;

		FloatMatrix3 fourthMatrix(sixthMatrix(0,0) * fifthMatrix(0,0) +
			                  sixthMatrix(0,1) * fifthMatrix(1,0) +
							  sixthMatrix(0,2) * fifthMatrix(2,0),
							  sixthMatrix(0,0) * fifthMatrix(0,1) +
							  sixthMatrix(0,1) * fifthMatrix(1,1) +
							  sixthMatrix(0,2) * fifthMatrix(2,1),
							  sixthMatrix(0,0) * fifthMatrix(0,2) +
							  sixthMatrix(0,1) * fifthMatrix(1,2) +
							  sixthMatrix(0,2) * fifthMatrix(2,2),
							  sixthMatrix(1,0) * fifthMatrix(0,0) +
							  sixthMatrix(1,1) * fifthMatrix(1,0) +
							  sixthMatrix(1,2) * fifthMatrix(2,0),
							  sixthMatrix(1,0) * fifthMatrix(0,1) +
							  sixthMatrix(1,1) * fifthMatrix(1,1) +
							  sixthMatrix(1,2) * fifthMatrix(2,1),
							  sixthMatrix(1,0) * fifthMatrix(0,2) +
							  sixthMatrix(1,1) * fifthMatrix(1,2) +
							  sixthMatrix(1,2) * fifthMatrix(2,2),
							  sixthMatrix(2,0) * fifthMatrix(0,0) +
							  sixthMatrix(2,1) * fifthMatrix(1,0) +
							  sixthMatrix(2,2) * fifthMatrix(2,0),
							  sixthMatrix(2,0) * fifthMatrix(0,1) +
							  sixthMatrix(2,1) * fifthMatrix(1,1) +
							  sixthMatrix(2,2) * fifthMatrix(2,1),
							  sixthMatrix(2,0) * fifthMatrix(0,2) +
							  sixthMatrix(2,1) * fifthMatrix(1,2) +
							  sixthMatrix(2,2) * fifthMatrix(2,2));

		ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix,1e-8f)); 

		seventhMatrix = sixthMatrix * fifthMatrix;

		ASSERT_TRUE(Approximate(fourthMatrix, seventhMatrix,1e-8f)); 
		
		FloatMatrix3::Vector3D firstVector(randomDistribution(generator),
			                           randomDistribution(generator),
			                           randomDistribution(generator));

		FloatMatrix3::Vector3D secondVector = seventhMatrix * firstVector;
		FloatMatrix3::Vector3D thirdVector = firstVector * seventhMatrix;

		FloatMatrix3::Vector3D fourthVector(seventhMatrix(0,0) * firstVector[0] + 
			                            seventhMatrix(0,1) * firstVector[1] +
										seventhMatrix(0,2) * firstVector[2],
										seventhMatrix(1,0) * firstVector[0] + 
										seventhMatrix(1,1) * firstVector[1] +
										seventhMatrix(1,2) * firstVector[2],
										seventhMatrix(2,0) * firstVector[0] + 
										seventhMatrix(2,1) * firstVector[1] +
										seventhMatrix(2,2) * firstVector[2]);

		ASSERT_TRUE(FloatVector3DTools::Approximate(secondVector,fourthVector,1e-8f)); 

		fourthVector[0] = seventhMatrix(0,0) * firstVector[0] + 
			              seventhMatrix(1,0) * firstVector[1] +
						  seventhMatrix(2,0) * firstVector[2];

		fourthVector[1] = seventhMatrix(0,1) * firstVector[0] + 
			              seventhMatrix(1,1) * firstVector[1] +
						  seventhMatrix(2,1) * firstVector[2];

		fourthVector[2] = seventhMatrix(0,2) * firstVector[0] + 
			              seventhMatrix(1,2) * firstVector[1] +
						  seventhMatrix(2,2) * firstVector[2];

		ASSERT_TRUE(FloatVector3DTools::Approximate(thirdVector,fourthVector,1e-8f));  
		
		FloatMatrix3 eighthMatrix = TransposeTimes(fifthMatrix,sixthMatrix);
		FloatMatrix3 ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f)); 

		eighthMatrix = TimesTranspose(fifthMatrix,sixthMatrix);
		ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f));  

		eighthMatrix = TransposeTimesTranspose(fifthMatrix,sixthMatrix);
		ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

		ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix,1e-8f));
	}
}

void Mathematics::Matrix3Testing
	::ArithmeticCalculateTest()
{
	default_random_engine generator{};
	uniform_real<float> randomDistribution{ -10.0f,10.0f };
	uniform_real<float> angleRandomDistribution{ 0.0f,FloatMath::GetPI() - 0.01f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatMatrix3::Vector3D firstVector(randomDistribution(generator),
			                           randomDistribution(generator),
			                           randomDistribution(generator));

		FloatMatrix3::Vector3D secondVector(randomDistribution(generator),
			                            randomDistribution(generator),
			                            randomDistribution(generator));

		FloatMatrix3 firstMatrix(randomDistribution(generator),
			                 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator),
							 randomDistribution(generator));

		float qForm = firstMatrix.QuadraticForm(firstVector,secondVector);

		float testQFormValue = FloatVector3DTools::DotProduct(firstVector,firstMatrix * secondVector);

		ASSERT_APPROXIMATE(qForm,testQFormValue,1e-8f);
		
		FloatMatrix3 secondMatrix = firstMatrix.Transpose();

		ASSERT_APPROXIMATE(firstMatrix(0,0),secondMatrix(0,0),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(0,1),secondMatrix(1,0),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(0,2),secondMatrix(2,0),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(1,0),secondMatrix(0,1),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(1,1),secondMatrix(1,1),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(1,2),secondMatrix(2,1),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(2,0),secondMatrix(0,2),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(2,1),secondMatrix(1,2),1e-8f);
		ASSERT_APPROXIMATE(firstMatrix(2,2),secondMatrix(2,2),1e-8f);

		secondMatrix = firstMatrix.TimesDiagonal(firstVector);

		FloatMatrix3 thirdMatrix = firstMatrix * FloatMatrix3(firstVector[0],firstVector[1],firstVector[2]);

		ASSERT_TRUE(Approximate(thirdMatrix, secondMatrix,1e-8f));

		secondMatrix = firstMatrix.DiagonalTimes(firstVector);

		thirdMatrix = FloatMatrix3(firstVector[0],firstVector[1],firstVector[2]) * firstMatrix;

		ASSERT_TRUE(Approximate(thirdMatrix, secondMatrix,1e-8f));

		float column00 = secondMatrix(0,2) * secondMatrix(2,1) - secondMatrix(0,1) * secondMatrix(2,2);
		float column10 = secondMatrix(0,0) * secondMatrix(2,2) - secondMatrix(0,2) * secondMatrix(2,0);
		float column20 = secondMatrix(0,1) * secondMatrix(2,0) - secondMatrix(0,0) * secondMatrix(2,1);
		
		float determinant = column00 * secondMatrix(1,0) + column10 * secondMatrix(1,1) + column20 * secondMatrix(1,2);

		ASSERT_APPROXIMATE(determinant,secondMatrix.Determinant(),1e-1f);
		
		if(FloatMath::GetZeroTolerance() < FloatMath::FAbs(determinant))
		{
			FloatMatrix3 fourthMatrix = secondMatrix.Inverse();

			FloatMatrix3 fifthMatrix = secondMatrix * fourthMatrix;

			ASSERT_TRUE(Approximate(fifthMatrix, FloatMatrix3::GetIdentity(),1e-3f));

			FloatMatrix3 sixthMatrix = secondMatrix.Adjoint();
			sixthMatrix /= determinant;

			fifthMatrix = sixthMatrix * secondMatrix;

			ASSERT_TRUE(Approximate(fifthMatrix, FloatMatrix3::GetIdentity(),1e-4f));
		}
		
		float angle = angleRandomDistribution(generator);
		firstVector.Normalize();

		FloatMatrix3 seventhMatrix(firstVector,angle);
		
  	    ASSERT_APPROXIMATE(angle,seventhMatrix.ExtractAngle(),
 				           1e-5f);
  	    ASSERT_TRUE(FloatVector3DTools::Approximate(seventhMatrix.ExtractAxis(),firstVector));

  	    FloatMatrix3Extract	extract	= seventhMatrix.ExtractAngleAxis();

  	    ASSERT_APPROXIMATE(angle, extract.GetAngle(),1e-5f);
  	    ASSERT_TRUE(FloatVector3DTools::Approximate(extract.GetAxis(),firstVector));		

		FloatMatrix3 eighthMatrix(seventhMatrix);
		
		seventhMatrix.Orthonormalize();

		FloatVector3D thirdVector(eighthMatrix(0,0),eighthMatrix(1,0),eighthMatrix(2,0));
		FloatVector3D fourthVector(seventhMatrix(0,0),seventhMatrix(1,0),seventhMatrix(2,0));

		thirdVector.Normalize();

		ASSERT_TRUE(FloatVector3DTools::Approximate(thirdVector,fourthVector,1e-7f));

		FloatVector3D fifthVector(eighthMatrix(0,1),eighthMatrix(1,1),eighthMatrix(2,1));;
		FloatVector3D sixthVector(seventhMatrix(0,1),seventhMatrix(1,1),seventhMatrix(2,1));

		fifthVector -= (FloatVector3DTools::DotProduct(fourthVector , fifthVector)) * fourthVector;

		fifthVector.Normalize();

		ASSERT_TRUE(FloatVector3DTools::Approximate(fifthVector,sixthVector,1e-7f));

		FloatVector3D seventhVector(eighthMatrix(0,2),eighthMatrix(1,2),eighthMatrix(2,2));
		FloatVector3D eighthVector(seventhMatrix(0,2),seventhMatrix(1,2),seventhMatrix(2,2));

		seventhVector -= (FloatVector3DTools::DotProduct(fourthVector,seventhVector)) * fourthVector;

		seventhVector -= (FloatVector3DTools::DotProduct(sixthVector,seventhVector)) * sixthVector;

		seventhVector.Normalize();

		ASSERT_TRUE(FloatVector3DTools::Approximate(seventhVector,eighthVector,1e-7f)); 

		float secondAngle = angleRandomDistribution(generator);
		float thirdAngle = angleRandomDistribution(generator);
		
		FloatMatrix3 ninthMatrix(randomDistribution(generator),angle,secondAngle,angle,randomDistribution(generator),thirdAngle,secondAngle,thirdAngle,randomDistribution(generator));
		
		FloatMatrix3::Matrix3EigenDecomposition eigenDecomposition = ninthMatrix.EigenDecomposition(1e-8f);

		FloatMatrix3 rotation = eigenDecomposition.GetRotation();
		FloatMatrix3 diagonal = eigenDecomposition.GetDiagonal();

		FloatMatrix3 tenthMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(ninthMatrix, tenthMatrix,1e-5f));	

		seventhMatrix.MakeRotation(firstVector,FloatMath::GetPI());

		ASSERT_APPROXIMATE(FloatMath::GetPI(),seventhMatrix.ExtractAngle(),1e-3f);

		// 由于旋转的角度是PI，所以旋转的方向可能是相反的。
		ASSERT_TRUE(FloatVector3DTools::Approximate(seventhMatrix.ExtractAxis(),firstVector) || FloatVector3DTools::Approximate(-seventhMatrix.ExtractAxis(),firstVector));

		FloatMatrix3 eleventhMatrix(firstVector,angle);
		FloatMatrix3 twelfthMatrix(secondVector,angle / 2.0f);

		seventhMatrix.Slerp(0.5,eleventhMatrix,tenthMatrix);

		FloatMatrix3 thirteenthMatrix = TransposeTimes(eleventhMatrix,tenthMatrix);

		FloatVector3D ninthVector = thirteenthMatrix.ExtractAxis();
		angle = thirteenthMatrix.ExtractAngle();	

		thirteenthMatrix.MakeRotation(ninthVector,angle * 0.5f);

		thirteenthMatrix = eleventhMatrix * thirteenthMatrix;
		 
		ASSERT_TRUE(Approximate(seventhMatrix, thirteenthMatrix,1e-8f));

		// 测试m_Matrix(0,2)为零的情况
		FloatMatrix3 fourteenthMatrix(randomDistribution(generator),angle,0.0f,angle,randomDistribution(generator),thirdAngle,0.0f,thirdAngle,randomDistribution(generator));

		eigenDecomposition = fourteenthMatrix.EigenDecomposition();

		rotation = eigenDecomposition.GetRotation();
		diagonal = eigenDecomposition.GetDiagonal();			

		FloatMatrix3 fifteenthMatrix = rotation * diagonal * rotation.Transpose();

		ASSERT_TRUE(Approximate(fifteenthMatrix, fourteenthMatrix,1e-5f));
	}	
}

void Mathematics::Matrix3Testing
	::EulerTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleRandomDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleRandomDistribution{ -DoubleMath::GetHalfPI(), DoubleMath::GetHalfPI() };
	uniform_real<double> thirdAngleRandomDistribution{ 0.0, DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();	 

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		double firstAngle = firstAngleRandomDistribution(generator);
		double secondAngle = secondAngleRandomDistribution(generator);
		double thirdAngle = firstAngleRandomDistribution(generator);
		double fourthAngle = thirdAngleRandomDistribution(generator);

		DoubleMatrix3 firstMatrix;

		firstMatrix.MakeEulerXYZ(firstAngle,secondAngle,thirdAngle);

		DoubleMatrix3::Euler firstEuler = firstMatrix.ExtractEulerXYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),  ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerXZY(firstAngle,secondAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerXZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerYXZ(firstAngle,secondAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerYXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),  ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerYZX(firstAngle,secondAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerYZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerZXY(firstAngle,secondAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerZXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerZYX(firstAngle,secondAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerZYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(secondAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerXYX(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerXYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerXZX(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerXZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerYXY(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerYXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerYZY(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerYZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerZXZ(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerZXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		firstMatrix.MakeEulerZYZ(firstAngle,fourthAngle,thirdAngle);

		firstEuler = firstMatrix.ExtractEulerZYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(fourthAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(thirdAngle,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);

		// 测试特殊情况
		firstMatrix.MakeEulerXYZ(firstAngle + thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerXYZ(firstAngle - thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerXZY(firstAngle + thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerXZY(firstAngle - thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerYXZ(firstAngle + thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerYXZ(firstAngle - thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerYZX(firstAngle + thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerYZX(firstAngle - thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerZXY(firstAngle + thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerZXY(firstAngle - thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerZYX(firstAngle + thirdAngle,DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetHalfPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerZYX(firstAngle - thirdAngle,-DoubleMath::GetHalfPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(-DoubleMath::GetHalfPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerXYX(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerXYX(firstAngle - thirdAngle,0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXYX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerXZX(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerXZX(firstAngle - thirdAngle,0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerXZX();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerYXY(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerYXY(firstAngle - thirdAngle, 0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYXY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerYZY(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerYZY(firstAngle - thirdAngle,0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerYZY();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerZXZ(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerZXZ(firstAngle - thirdAngle,0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZXZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetX0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(), ExtractEulerResultType::Sum);

		firstMatrix.MakeEulerZYZ(firstAngle + thirdAngle,DoubleMath::GetPI(),thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(DoubleMath::GetPI(),firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);

		firstMatrix.MakeEulerZYZ(firstAngle - thirdAngle,0.0f,thirdAngle);
	
		firstEuler = firstMatrix.ExtractEulerZYZ();

		ASSERT_APPROXIMATE(firstAngle,firstEuler.GetZ0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetY0Angle(),1e-10);
		ASSERT_APPROXIMATE(0.0f,firstEuler.GetZ1Angle(),1e-10);

		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
	}	
}


