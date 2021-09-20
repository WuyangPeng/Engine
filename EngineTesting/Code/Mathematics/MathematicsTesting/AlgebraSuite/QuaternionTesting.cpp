// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.0.2 (2019/08/22 10:00)

#include "QuaternionTesting.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <vector>
#include <random> 

using std::vector;
using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
	template class Quaternion<float>;
	template class Quaternion<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,QuaternionTesting) 

void Mathematics::QuaternionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClosestCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FactorCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ConstraintsClosestCalculateTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::QuaternionTesting
	::ConstructionTest()
{
	FloatQuaternion firstQuaternion;

	ASSERT_APPROXIMATE(firstQuaternion[0],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[1],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[2],0.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[3],0.0f,1e-8f);

	DoubleQuaternion secondQuaternion(3.0,5.0,6.0,7.0);

	ASSERT_APPROXIMATE(secondQuaternion[0],3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[1],5.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[2],6.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[3],7.0,1e-10);

	DoubleQuaternion thirdQuaternion(secondQuaternion);

	ASSERT_APPROXIMATE(thirdQuaternion[0],3.0,1e-10);
	ASSERT_APPROXIMATE(thirdQuaternion[1],5.0,1e-10);
	ASSERT_APPROXIMATE(thirdQuaternion[2],6.0,1e-10);
	ASSERT_APPROXIMATE(thirdQuaternion[3],7.0,1e-10);

	thirdQuaternion[0] = 5.0;
	thirdQuaternion[1] = 15.0;
	thirdQuaternion[2] = 25.0;
	thirdQuaternion[3] = 35.0;

	ASSERT_APPROXIMATE(secondQuaternion[0],3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[1],5.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[2],6.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[3],7.0,1e-10);

	secondQuaternion = thirdQuaternion;

	ASSERT_APPROXIMATE(secondQuaternion[0],5.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[1],15.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[2],25.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[3],35.0,1e-10);

	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };
	uniform_real<float> secondRandomDistribution{ 0.0f,FloatMath::GetTwoPI() }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatVector3D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		firstVector.Normalize();

		float firstFloat(secondRandomDistribution(generator));

		FloatMatrix3 firstMatrix(firstVector,firstFloat);

		FloatQuaternion fourthQuaternion(firstMatrix);

		FloatMatrix3 secondMatrix = fourthQuaternion.ToRotationMatrix();

		ASSERT_TRUE(Approximate(firstMatrix,secondMatrix,1e-6f));

		FloatQuaternion fifthQuaternion(firstVector,firstFloat);

		FloatVector3D secondVector = fifthQuaternion.ToAxis();
		float secondFloat = fifthQuaternion.ToAngle();

		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector,secondVector));
		ASSERT_APPROXIMATE(firstFloat,secondFloat,1e-5f);

		vector<FloatVector3D> firstVector3DfVector;

		firstVector3DfVector.push_back(FloatVector3D(firstMatrix(0,0),firstMatrix(1,0),firstMatrix(2,0)));
		firstVector3DfVector.push_back(FloatVector3D(firstMatrix(0,1),firstMatrix(1,1), firstMatrix(2,1)));
		firstVector3DfVector.push_back(FloatVector3D(firstMatrix(0,2),firstMatrix(1,2),firstMatrix(2,2)));

		FloatQuaternion sixQuaternion(firstVector3DfVector);

		vector<FloatVector3D> secondVector3DfVector = sixQuaternion.ToRotationColumnVector3D();

		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[0],secondVector3DfVector[0]));
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[1],secondVector3DfVector[1]));
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[2],secondVector3DfVector[2]));

		fourthQuaternion.FromRotationMatrix(firstMatrix);

		secondMatrix = fourthQuaternion.ToRotationMatrix();

		ASSERT_TRUE(Approximate(firstMatrix,secondMatrix,1e-6f)); 	

		fourthQuaternion.FromRotationColumnVector3D(firstVector3DfVector);

		secondVector3DfVector = sixQuaternion.ToRotationColumnVector3D();

		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[0],secondVector3DfVector[0]));
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[1],secondVector3DfVector[1]));
		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector3DfVector[2],secondVector3DfVector[2]));

		fourthQuaternion.FromAxisAngle(firstVector,firstFloat);

		FloatMatrix3Extract extract = fifthQuaternion.ToAngleAxis();

		secondVector = extract.GetAxis();
		secondFloat = extract.GetAngle();

		ASSERT_TRUE(FloatVector3DTools::Approximate(firstVector,secondVector));
		ASSERT_APPROXIMATE(firstFloat,secondFloat,1e-5f);
	}
}

void Mathematics::QuaternionTesting
	::AccessTest()
{
	const FloatQuaternion firstQuaternion(3.0f,5.0f,6.0f,7.0f);

	ASSERT_APPROXIMATE(firstQuaternion[0],3.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[1],5.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[2],6.0f,1e-8f);
	ASSERT_APPROXIMATE(firstQuaternion[3],7.0f,1e-8f);

	DoubleQuaternion secondQuaternion(23.0,25.0,62.0,27.0);

	ASSERT_APPROXIMATE(secondQuaternion[0],23.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[1],25.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[2],62.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion[3],27.0,1e-10);

	ASSERT_APPROXIMATE(secondQuaternion.GetW(),23.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetX(),25.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetY(),62.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetZ(),27.0,1e-10);

	secondQuaternion.SetW(3.0);

	ASSERT_APPROXIMATE(secondQuaternion.GetW(),3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetX(),25.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetY(),62.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetZ(),27.0,1e-10);

	secondQuaternion.SetX(4.5);

	ASSERT_APPROXIMATE(secondQuaternion.GetW(),3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetX(),4.5,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetY(),62.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetZ(),27.0,1e-10);

	secondQuaternion.SetY(14.5);

	ASSERT_APPROXIMATE(secondQuaternion.GetW(),3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetX(),4.5,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetY(),14.5,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetZ(),27.0,1e-10);

	secondQuaternion.SetZ(7.77);

	ASSERT_APPROXIMATE(secondQuaternion.GetW(),3.0,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetX(),4.5,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetY(),14.5,1e-10);
	ASSERT_APPROXIMATE(secondQuaternion.GetZ(),7.77,1e-10);

}

void Mathematics::QuaternionTesting
	::OperatorCalculateTest()
{
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0f,100.0f };
	uniform_real<double> secondRandomDistribution{ 0.0f,FloatMath::GetTwoPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)	 
	{
		DoubleVector3D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		firstVector.Normalize();

		double firstDouble(secondRandomDistribution(generator));

		DoubleQuaternion firstQuaternion(firstVector,firstDouble);

		DoubleVector3D secondVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		secondVector.Normalize();

		double secondDouble(secondRandomDistribution(generator));

		DoubleQuaternion secondQuaternion(secondVector,secondDouble);

		DoubleQuaternion thirdQuaternion = firstQuaternion * secondQuaternion;

		DoubleQuaternion fourthQuaternion(DoubleMatrix3(firstVector,firstDouble) *  DoubleMatrix3(secondVector,secondDouble));

		ASSERT_TRUE(Approximate(thirdQuaternion, fourthQuaternion,1e-10) || Approximate(thirdQuaternion, -fourthQuaternion,1e-10) );  

		DoubleMatrix3 firstMatrix = thirdQuaternion.ToRotationMatrix();
		DoubleMatrix3 secondMatrix = fourthQuaternion.ToRotationMatrix();

		ASSERT_TRUE(Approximate(firstMatrix,secondMatrix,1e-10)); 

		DoubleQuaternion fifthQuaternion(firstQuaternion);

		fifthQuaternion *= secondQuaternion;

		DoubleMatrix3 thirdMatrix = fifthQuaternion.ToRotationMatrix();
		DoubleMatrix3 fourthMatrix = fourthQuaternion.ToRotationMatrix();

		ASSERT_TRUE(Approximate(thirdMatrix, fourthMatrix,1e-10));  	

		DoubleQuaternion sixthQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		DoubleQuaternion seventhQuaternion = -sixthQuaternion;

		ASSERT_APPROXIMATE(sixthQuaternion[0],-seventhQuaternion[0],1e-10);
		ASSERT_APPROXIMATE(sixthQuaternion[1],-seventhQuaternion[1],1e-10);
		ASSERT_APPROXIMATE(sixthQuaternion[2],-seventhQuaternion[2],1e-10);
		ASSERT_APPROXIMATE(sixthQuaternion[3],-seventhQuaternion[3],1e-10);
	}

	DoubleQuaternion eighthQuaternion(3.0,5.1,6.7,8.71);
	DoubleQuaternion ninthQuaternion(13.1,15.0,16.71,18.7);

	DoubleQuaternion tenthQuaternion = eighthQuaternion + ninthQuaternion;

	ASSERT_APPROXIMATE(tenthQuaternion[0],16.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],20.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],23.41,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],27.41,1e-10);

	tenthQuaternion = eighthQuaternion - ninthQuaternion;

	ASSERT_APPROXIMATE(tenthQuaternion[0],-10.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],-9.9,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],-10.01,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],-9.99,1e-10);

	tenthQuaternion = eighthQuaternion * 4.0;

	ASSERT_APPROXIMATE(tenthQuaternion[0],12.0,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],20.4,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],26.8,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],34.84,1e-10);

	tenthQuaternion = 20.0 * eighthQuaternion;
	
	ASSERT_APPROXIMATE(tenthQuaternion[0],60.0,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],102.0,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],134.0,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],174.2,1e-10);

	tenthQuaternion = eighthQuaternion / 2.0;

	ASSERT_APPROXIMATE(tenthQuaternion[0],1.5,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],2.55,1e-101);
	ASSERT_APPROXIMATE(tenthQuaternion[2],3.35,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],4.355,1e-10);

	tenthQuaternion = eighthQuaternion;

	tenthQuaternion += ninthQuaternion;

	ASSERT_APPROXIMATE(tenthQuaternion[0],16.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],20.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],23.41,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],27.41,1e-10);

	tenthQuaternion = eighthQuaternion;

	tenthQuaternion -= ninthQuaternion;

	ASSERT_APPROXIMATE(tenthQuaternion[0],-10.1,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],-9.9,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],-10.01,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],-9.99,1e-10);

	tenthQuaternion = eighthQuaternion;

	tenthQuaternion *= 4.0;

	ASSERT_APPROXIMATE(tenthQuaternion[0],12.0,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],20.4,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],26.8,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],34.84,1e-10);	

	tenthQuaternion = eighthQuaternion;

	tenthQuaternion /= 2.0;

	ASSERT_APPROXIMATE(tenthQuaternion[0],1.5,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[1],2.55,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[2],3.35,1e-10);
	ASSERT_APPROXIMATE(tenthQuaternion[3],4.355,1e-10);
}

void Mathematics::QuaternionTesting
	::ArithmeticCalculateTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };
	uniform_real<float> secondRandomDistribution{ 0.0f,FloatMath::GetTwoPI() };
	uniform_real<float> thirdRandomDistribution{ 0.0f,1.0f }; 
	uniform_int<> fourthRandomDistribution(0,20);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		float length = firstQuaternion[0] * firstQuaternion[0] +
			           firstQuaternion[1] * firstQuaternion[1] +
					   firstQuaternion[2] * firstQuaternion[2] +
					   firstQuaternion[3] * firstQuaternion[3];

		ASSERT_APPROXIMATE(length,firstQuaternion.SquaredLength(),1e-8f);

		length = FloatMath::Sqrt(length);

		ASSERT_APPROXIMATE(length,firstQuaternion.Length(),1e-8f);

		FloatQuaternion secondQuaternion(firstQuaternion);

		secondQuaternion.Normalize();

		ASSERT_APPROXIMATE(firstQuaternion[0],secondQuaternion[0] * length,1e-5f);
		ASSERT_APPROXIMATE(firstQuaternion[1],secondQuaternion[1] * length,1e-5f);
		ASSERT_APPROXIMATE(firstQuaternion[2],secondQuaternion[2] * length,1e-5f);
		ASSERT_APPROXIMATE(firstQuaternion[3],secondQuaternion[3] * length,1e-5f);

		secondQuaternion = firstQuaternion.Inverse();

		FloatQuaternion thirdQuaternion = secondQuaternion * firstQuaternion;

		ASSERT_APPROXIMATE(thirdQuaternion[0],1.0f,1e-6f);
		ASSERT_APPROXIMATE(thirdQuaternion[1],0.0f,1e-7f);
		ASSERT_APPROXIMATE(thirdQuaternion[2],0.0f,1e-7f);
		ASSERT_APPROXIMATE(thirdQuaternion[3],0.0f,1e-7f);

		thirdQuaternion = firstQuaternion * secondQuaternion;

		ASSERT_APPROXIMATE(thirdQuaternion[0],1.0f,1e-6f);
		ASSERT_APPROXIMATE(thirdQuaternion[1],0.0f,1e-7f);
		ASSERT_APPROXIMATE(thirdQuaternion[2],0.0f,1e-7f);
		ASSERT_APPROXIMATE(thirdQuaternion[3],0.0f,1e-7f);

		thirdQuaternion = firstQuaternion.Conjugate();

		ASSERT_APPROXIMATE(thirdQuaternion[0],firstQuaternion[0],1e-8f);
		ASSERT_APPROXIMATE(thirdQuaternion[1],-firstQuaternion[1],1e-8f);
		ASSERT_APPROXIMATE(thirdQuaternion[2],-firstQuaternion[2],1e-8f);
		ASSERT_APPROXIMATE(thirdQuaternion[3],-firstQuaternion[3],1e-8f);

		firstQuaternion[0] = 0.0f;
		secondQuaternion = firstQuaternion.Exp();
		thirdQuaternion = secondQuaternion.Log();

		firstQuaternion.Normalize();
		thirdQuaternion.Normalize();

		ASSERT_TRUE(Approximate(thirdQuaternion, firstQuaternion,1e-6f) || Approximate(thirdQuaternion, -firstQuaternion,1e-6f) );  

		firstQuaternion = secondQuaternion;
		secondQuaternion = firstQuaternion.Log();
		thirdQuaternion = secondQuaternion.Exp();

		ASSERT_TRUE(Approximate(thirdQuaternion, firstQuaternion,1e-3f));

		FloatVector3D firstVector(firstRandomDistribution(generator),firstRandomDistribution(generator),firstRandomDistribution(generator));

		FloatVector3D secondVector = firstQuaternion.Rotate(firstVector);
		FloatVector3D thirdVector = firstQuaternion.ToRotationMatrix() * firstVector;

		ASSERT_TRUE(FloatVector3DTools::Approximate(secondVector,thirdVector));

		DoubleVector3D fourthVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
							   firstRandomDistribution(generator));

		fourthVector.Normalize();

		double firstDouble(secondRandomDistribution(generator));

		DoubleQuaternion fourthQuaternion(fourthVector,firstDouble);

		DoubleVector3D fifthVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
							  firstRandomDistribution(generator));

		fifthVector.Normalize();

		double secondDouble(secondRandomDistribution(generator));

		DoubleQuaternion fifthQuaternion(fifthVector,secondDouble);

		DoubleQuaternion sixthQuaternion;

		sixthQuaternion.Slerp(0.0,fourthQuaternion,fifthQuaternion);

		ASSERT_TRUE(Approximate(fourthQuaternion, sixthQuaternion,1e-10));

		sixthQuaternion.Slerp(1.0,fourthQuaternion,fifthQuaternion);

		ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion,1e-10));

		double firstT = thirdRandomDistribution(generator);

		sixthQuaternion.Slerp(firstT,fourthQuaternion,fifthQuaternion);		

		double cosValue = Dot(fourthQuaternion,fifthQuaternion);
		double angle = DoubleMath::ACos(cosValue);

		double passAngle = DoubleMath::ACos(Dot(fourthQuaternion,sixthQuaternion));
		double remainAngle = DoubleMath::ACos(Dot(sixthQuaternion,fifthQuaternion));

		ASSERT_APPROXIMATE(passAngle + remainAngle,angle,1e-10);
		ASSERT_APPROXIMATE(passAngle / angle,firstT,1e-10);
		ASSERT_APPROXIMATE(remainAngle / angle, 1.0 - firstT,1e-10);

		int extraSpins = fourthRandomDistribution(generator);

		sixthQuaternion.SlerpExtraSpins(0.0,fourthQuaternion,fifthQuaternion,extraSpins);

		ASSERT_TRUE(Approximate(fourthQuaternion, sixthQuaternion,1e-10));

		sixthQuaternion.SlerpExtraSpins(1.0,fourthQuaternion,fifthQuaternion,extraSpins);

		ASSERT_TRUE(Approximate(fifthQuaternion, sixthQuaternion,1e-10) || Approximate(fifthQuaternion, -sixthQuaternion,1e-10) );

		sixthQuaternion.SlerpExtraSpins(firstT,fourthQuaternion,fifthQuaternion,extraSpins);		

		cosValue = Dot(fourthQuaternion,fifthQuaternion);
		angle = DoubleMath::ACos(cosValue);

		double phase = DoubleMath::GetPI() * extraSpins * firstT;

		double coeff0 = DoubleMath::Sin((1 - firstT) * angle - phase) / DoubleMath::Sin(angle);
		double coeff1 = DoubleMath::Sin( firstT * angle + phase) / DoubleMath::Sin(angle);

		DoubleQuaternion seventhQuaternion = coeff0 * fourthQuaternion + coeff1 * fifthQuaternion;

		ASSERT_TRUE(Approximate(sixthQuaternion, seventhQuaternion,1e-10)); 

		DoubleQuaternion eighthQuaternion(firstRandomDistribution(generator),
			                         firstRandomDistribution(generator),
									 firstRandomDistribution(generator),
									 firstRandomDistribution(generator));

		eighthQuaternion.Normalize();

		DoubleQuaternion ninthQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		ninthQuaternion.Normalize();

		DoubleQuaternion tenthQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		tenthQuaternion.Normalize();

		// 使用另一种算法进行测试。
		seventhQuaternion = eighthQuaternion.Inverse();
		sixthQuaternion = ninthQuaternion.Inverse();
		fifthQuaternion = seventhQuaternion * ninthQuaternion;
		fourthQuaternion = sixthQuaternion * tenthQuaternion;
		seventhQuaternion = 0.25 * (fifthQuaternion.Log() - fourthQuaternion.Log());

		sixthQuaternion = ninthQuaternion * seventhQuaternion.Exp();

		sixthQuaternion.Normalize();

		fifthQuaternion.Intermediate(eighthQuaternion,
			                         ninthQuaternion,
									 tenthQuaternion);

		fifthQuaternion.Normalize();

		ASSERT_TRUE(Approximate(sixthQuaternion, fifthQuaternion,1e-10)); 

		DoubleQuaternion eleventhQuaternion(firstRandomDistribution(generator),
			                           firstRandomDistribution(generator),
									   firstRandomDistribution(generator),
									   firstRandomDistribution(generator));

		eleventhQuaternion.Normalize();

		double slerpT = 2.0 * firstT * (1.0 - firstT);
	
		seventhQuaternion.Slerp(firstT, eighthQuaternion, eleventhQuaternion);
		sixthQuaternion.Slerp(firstT, ninthQuaternion, tenthQuaternion);
		fifthQuaternion.Slerp(slerpT, seventhQuaternion, sixthQuaternion);

		seventhQuaternion.Squad(firstT, eighthQuaternion,ninthQuaternion, tenthQuaternion,eleventhQuaternion);

		ASSERT_TRUE(Approximate(seventhQuaternion, fifthQuaternion,1e-10)); 

		fourthVector.Normalize();
		firstVector.Normalize();

		fifthVector = DoubleVector3DTools::CrossProduct(fourthVector,firstVector);

		fifthVector.Normalize();

		angle = DoubleVector3DTools::GetVectorIncludedAngle(fourthVector,firstVector);

		seventhQuaternion.FromAxisAngle(fifthVector,angle);
		fifthQuaternion.Align(fourthVector,firstVector,1e-7);

		ASSERT_TRUE(Approximate(seventhQuaternion, fifthQuaternion,1e-6)); 
 
		DoubleQuaternion::QuaternionSwingTwist quaternionSwingTwist = eighthQuaternion.DecomposeTwistTimesSwing(firstVector,1e-7);

		seventhQuaternion = quaternionSwingTwist.GetTwist() * quaternionSwingTwist.GetSwing();

		ASSERT_TRUE(Approximate(seventhQuaternion, eighthQuaternion,1e-6));  
		ASSERT_APPROXIMATE(seventhQuaternion[3],eighthQuaternion[3],1e-6);

		fifthVector = eighthQuaternion.Rotate(firstVector);
		fifthQuaternion.Align(firstVector, fifthVector,1e-7);
		seventhQuaternion = eighthQuaternion * fifthQuaternion.Conjugate();

		ASSERT_TRUE(Approximate(seventhQuaternion, quaternionSwingTwist.GetTwist(),1e-10)); 

		ASSERT_TRUE(Approximate(fifthQuaternion, quaternionSwingTwist.GetSwing(),1e-10));  

		quaternionSwingTwist =eighthQuaternion.DecomposeSwingTimesTwist(firstVector,1e-7);

		seventhQuaternion = quaternionSwingTwist.GetSwing() * quaternionSwingTwist.GetTwist();

		ASSERT_TRUE(Approximate(seventhQuaternion, eighthQuaternion,1e-6));

		fifthVector = eighthQuaternion.Rotate(firstVector);
		fifthQuaternion.Align(firstVector, fifthVector,1e-7);
		seventhQuaternion = fifthQuaternion.Conjugate() * eighthQuaternion;

		ASSERT_TRUE(Approximate(fifthQuaternion, quaternionSwingTwist.GetSwing(),1e-10)); 

		ASSERT_TRUE(Approximate(seventhQuaternion, quaternionSwingTwist.GetTwist(),1e-10));   

		double dot = eighthQuaternion[0] * ninthQuaternion[0] +
			         eighthQuaternion[1] * ninthQuaternion[1] +
					 eighthQuaternion[2] * ninthQuaternion[2] +
					 eighthQuaternion[3] * ninthQuaternion[3];

		ASSERT_APPROXIMATE(dot,Dot(eighthQuaternion,ninthQuaternion),1e-10);		
	} 
}

void Mathematics::QuaternionTesting
	::ClosestCalculateTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -100.0f,100.0f };
	uniform_real<float> secondRandomDistribution{ 0.0f,FloatMath::GetTwoPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                        firstRandomDistribution(generator),
									firstRandomDistribution(generator),
									firstRandomDistribution(generator));

		FloatQuaternion secondQuaternion(firstQuaternion[0],
			                         firstQuaternion[1],
									 0.0f,
									 0.0f);

		secondQuaternion.Normalize();

		FloatQuaternion thirdQuaternion = firstQuaternion.GetClosestX();

		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-7f));

		secondQuaternion = firstQuaternion;
		secondQuaternion[1] = 0.0f;
		secondQuaternion[3] = 0.0f;

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestY();

		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-7f));  

		secondQuaternion = firstQuaternion;
		secondQuaternion[1] = 0.0f;
		secondQuaternion[2] = 0.0f;

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestZ();

		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-7f));

		firstQuaternion.Normalize();

		double det = static_cast<double>(firstQuaternion[0]) * firstQuaternion[3] - static_cast<double>(firstQuaternion[1]) * firstQuaternion[2];

		if(DoubleMath::FAbs(det) < 0.5 - DoubleMath::GetZeroTolerance())
		{
			double discr = 1.0 - 4.0 * det * det;
			discr = DoubleMath::Sqrt(DoubleMath::FAbs(discr));
			double a = static_cast<double>(firstQuaternion[0]) * firstQuaternion[1] + static_cast<double>(firstQuaternion[2]) * firstQuaternion[3];
			double b = static_cast<double>(firstQuaternion[0]) * firstQuaternion[0] - static_cast<double>(firstQuaternion[1]) * firstQuaternion[1] + static_cast<double>(firstQuaternion[2]) * firstQuaternion[2] - static_cast<double>(firstQuaternion[3]) * firstQuaternion[3];

			double c0 = 0.0;
			double s0 = 0.0;

			if (0.0 <= b)
			{
				c0 = 0.5 * (discr + b);
				s0 = a;
			}
			else
			{
				c0 = a;
				s0 = 0.5 * (discr - b);
			}
			double invLength = DoubleMath::InvSqrt(c0 * c0 + s0 * s0);
			c0 *= invLength;
			s0 *= invLength;

			double c1 = firstQuaternion[0] * c0 + firstQuaternion[1] * s0;
			double s1 = firstQuaternion[2] * c0 + firstQuaternion[3] * s0;
			invLength = DoubleMath::InvSqrt(c1 * c1 + s1 * s1);
			c1 *= invLength;
			s1 *= invLength;

			thirdQuaternion = firstQuaternion.GetClosestXY();

			ASSERT_APPROXIMATE(thirdQuaternion[0],c0 * c1,1e-6);
			ASSERT_APPROXIMATE(thirdQuaternion[1],s0 * c1,1e-6);
			ASSERT_APPROXIMATE(thirdQuaternion[2],c0 * s1,1e-6);
			ASSERT_APPROXIMATE(thirdQuaternion[3],s0 * s1,1e-6);		
		}
		else
		{
			double invLength = DoubleMath::InvSqrt(DoubleMath::FAbs(det));

			thirdQuaternion = firstQuaternion.GetClosestXY();

			ASSERT_APPROXIMATE(thirdQuaternion[0],firstQuaternion[0] * invLength,1e-8f);
			ASSERT_APPROXIMATE(thirdQuaternion[1],firstQuaternion[1] * invLength,1e-8f);
			ASSERT_APPROXIMATE(thirdQuaternion[2],0.0,1e-8f);
			ASSERT_APPROXIMATE(thirdQuaternion[3],0.0,1e-8f);				
		}

		secondQuaternion = firstQuaternion;
		secondQuaternion[3] = -firstQuaternion[3];

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestYX();
		FloatQuaternion fourthQuaternion = secondQuaternion.GetClosestXY();

		ASSERT_APPROXIMATE(fourthQuaternion[0],thirdQuaternion[0],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[1],thirdQuaternion[1],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[2],thirdQuaternion[2],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[3],-thirdQuaternion[3],1e-5f);


		secondQuaternion = firstQuaternion;
		secondQuaternion[3] = firstQuaternion[2];
		secondQuaternion[2] = firstQuaternion[3];

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestZX();
		fourthQuaternion = secondQuaternion.GetClosestXY();

		ASSERT_APPROXIMATE(fourthQuaternion[0],thirdQuaternion[0],1e-3f);
		ASSERT_APPROXIMATE(fourthQuaternion[1],thirdQuaternion[1],1e-4f);
		ASSERT_APPROXIMATE(fourthQuaternion[2],thirdQuaternion[3],1e-4f);
		ASSERT_APPROXIMATE(fourthQuaternion[3],thirdQuaternion[2],1e-3f);


		secondQuaternion = firstQuaternion;
		secondQuaternion[3] = firstQuaternion[2];
		secondQuaternion[2] = -firstQuaternion[3];

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestXZ();
		fourthQuaternion = secondQuaternion.GetClosestXY();

		ASSERT_APPROXIMATE(fourthQuaternion[0],thirdQuaternion[0],1e-4f);
		ASSERT_APPROXIMATE(fourthQuaternion[1],thirdQuaternion[1],1e-5f);
		ASSERT_APPROXIMATE(-fourthQuaternion[2],thirdQuaternion[3],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[3],thirdQuaternion[2],1e-4f);


		secondQuaternion = firstQuaternion;
		secondQuaternion[1] = firstQuaternion[2];
		secondQuaternion[2] = firstQuaternion[3];
		secondQuaternion[3] = firstQuaternion[1];

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestYZ();
		fourthQuaternion = secondQuaternion.GetClosestXY();

		ASSERT_APPROXIMATE(fourthQuaternion[0],thirdQuaternion[0],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[3],thirdQuaternion[1],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[2],thirdQuaternion[3],1e-6f);
		ASSERT_APPROXIMATE(fourthQuaternion[1],thirdQuaternion[2],1e-5f);


		secondQuaternion = firstQuaternion;
		secondQuaternion[1] = firstQuaternion[2];
		secondQuaternion[2] = firstQuaternion[3];
		secondQuaternion[3] = -firstQuaternion[1];

		secondQuaternion.Normalize();

		thirdQuaternion = firstQuaternion.GetClosestZY();
		fourthQuaternion = secondQuaternion.GetClosestXY();

		ASSERT_APPROXIMATE(fourthQuaternion[0],thirdQuaternion[0],1e-4f);
		ASSERT_APPROXIMATE(-fourthQuaternion[3],thirdQuaternion[1],1e-4f);
		ASSERT_APPROXIMATE(fourthQuaternion[2],thirdQuaternion[3],1e-5f);
		ASSERT_APPROXIMATE(fourthQuaternion[1],thirdQuaternion[2],1e-5f);
	}
}

void Mathematics::QuaternionTesting
	::FactorCalculateTest()
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

		FloatQuaternionFactor firstQuaternionFactor =  firstQuaternion.FactorXYZ();			                                  

		FloatQuaternion secondQuaternion(firstQuaternionFactor.GetCosX(),
			                         firstQuaternionFactor.GetSinX(),
									 0.0f,0.0f);
		
		FloatQuaternion thirdQuaternion(firstQuaternionFactor.GetCosY(),
			                        0.0f,
			                        firstQuaternionFactor.GetSinY(),
									0.0f);

		FloatQuaternion fourthQuaternion(firstQuaternionFactor.GetCosZ(),
			                         0.0f,0.0f,
			                         firstQuaternionFactor.GetSinZ());

		FloatQuaternion fifthQuaternion = secondQuaternion * thirdQuaternion * fourthQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		
		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 

		firstQuaternionFactor = firstQuaternion.FactorXZY();		

		secondQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosX(),   firstQuaternionFactor.GetSinX(), 0.0f,0.0f);
		
		thirdQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(),  0.0f);

		fourthQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosZ(),  0.0f,0.0f, firstQuaternionFactor.GetSinZ());

		fifthQuaternion = secondQuaternion * fourthQuaternion *  thirdQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) );  

		firstQuaternionFactor = firstQuaternion.FactorYZX();		

		secondQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		thirdQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		fourthQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		fifthQuaternion = thirdQuaternion * fourthQuaternion * secondQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 

		firstQuaternionFactor = firstQuaternion.FactorYXZ();		

		secondQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		thirdQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(), 0.0f);

		fourthQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f, firstQuaternionFactor.GetSinZ());

		fifthQuaternion = thirdQuaternion * secondQuaternion * fourthQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 

		firstQuaternionFactor = firstQuaternion.FactorZXY();		

		secondQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		thirdQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		fourthQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f, firstQuaternionFactor.GetSinZ());

		fifthQuaternion = fourthQuaternion * secondQuaternion * thirdQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 

		firstQuaternionFactor = firstQuaternion.FactorZYX();		

		secondQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosX(),firstQuaternionFactor.GetSinX(),0.0f,0.0f);
		
		thirdQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosY(),0.0f,firstQuaternionFactor.GetSinY(),0.0f);

		fourthQuaternion = FloatQuaternion(firstQuaternionFactor.GetCosZ(),0.0f,0.0f,firstQuaternionFactor.GetSinZ());

		fifthQuaternion = fourthQuaternion * thirdQuaternion * secondQuaternion;

		fifthQuaternion.Normalize();
		firstQuaternion.Normalize();

		ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) ); 

	}
}


void Mathematics::QuaternionTesting
	::ConstraintsClosestCalculateTest()
{
	default_random_engine generator{};
	uniform_real<float> firstRandomDistribution{ -FloatMath::GetHalfPI(), FloatMath::GetHalfPI() };
	uniform_real<float> thirdRandomDistribution{ -100.0f, 100.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		float firstAngle = firstRandomDistribution(generator);

		uniform_real<float> secondRandomDistribution(firstAngle,FloatMath::GetHalfPI());

		float secondAngle = secondRandomDistribution(generator);

		FloatQuaternionConstraints 
			firstQuaternionConstraints(firstAngle,secondAngle);

		FloatQuaternion firstQuaternion(thirdRandomDistribution(generator),
			                        thirdRandomDistribution(generator),
									thirdRandomDistribution(generator),
									thirdRandomDistribution(generator));

		FloatQuaternion secondQuaternion = firstQuaternion.GetClosestX();
		FloatQuaternion thirdQuaternion = firstQuaternion.GetClosestX(firstQuaternionConstraints);

		if(firstQuaternionConstraints.IsValid(secondQuaternion[0],secondQuaternion[1]))
		{
			// secondQuaternion和thirdQuaterniony应该是相等的
			ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f));
		}
		else
		{
			// thirdQuaternion的值同边界点有关
			float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
			float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
			float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
			float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

			float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[1];

			float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[1];

			if(dotMinAngle < 0.0)
			{
				cosValueMin = -cosValueMin;
				sinValueMin = -sinValueMin;
				dotMinAngle = -dotMinAngle;
			}

			if(dotMaxAngle < 0.0)
			{
				cosValueMax = -cosValueMax;
				sinValueMax = -sinValueMax;
				dotMaxAngle = -dotMaxAngle;
			}

			if(dotMaxAngle <= dotMinAngle)
			{
				ASSERT_APPROXIMATE(cosValueMin,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(sinValueMin,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[3],1e-8f);				
			}
			else
			{
				ASSERT_APPROXIMATE(cosValueMax,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(sinValueMax,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[3],1e-8f);
			}
		}


		secondQuaternion = firstQuaternion.GetClosestY();
		thirdQuaternion = firstQuaternion.GetClosestY(firstQuaternionConstraints);

		if(firstQuaternionConstraints.IsValid(secondQuaternion[0],secondQuaternion[2]))
		{
			// secondQuaternion和thirdQuaterniony应该是相等的
			ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f)); 
		}
		else
		{
			// thirdQuaternion的值同边界点有关
			float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
			float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
			float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
			float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

			float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[2];

			float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[2];

			if(dotMinAngle < 0.0)
			{
				cosValueMin = -cosValueMin;
				sinValueMin = -sinValueMin;
				dotMinAngle = -dotMinAngle;
			}

			if(dotMaxAngle < 0.0)
			{
				cosValueMax = -cosValueMax;
				sinValueMax = -sinValueMax;
				dotMaxAngle = -dotMaxAngle;
			}

			if(dotMaxAngle <= dotMinAngle)
			{
				ASSERT_APPROXIMATE(cosValueMin,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(sinValueMin,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[3],1e-8f);				
			}
			else
			{
				ASSERT_APPROXIMATE(cosValueMax,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(sinValueMax,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[3],1e-8f);
			}
		}


		secondQuaternion = firstQuaternion.GetClosestZ();
		thirdQuaternion = firstQuaternion.GetClosestZ(firstQuaternionConstraints);

		if(firstQuaternionConstraints.IsValid(secondQuaternion[0],secondQuaternion[3]))
		{
			// secondQuaternion和thirdQuaterniony应该是相等的
			ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f));  
		}
		else
		{
			// thirdQuaternion的值同边界点有关
			float cosValueMin = firstQuaternionConstraints.GetCosMinAngle();
			float sinValueMin = firstQuaternionConstraints.GetSinMinAngle();
			float cosValueMax = firstQuaternionConstraints.GetCosMaxAngle();
			float sinValueMax = firstQuaternionConstraints.GetSinMaxAngle();

			float dotMinAngle = cosValueMin * firstQuaternion[0] + sinValueMin * firstQuaternion[3];

			float dotMaxAngle = cosValueMax * firstQuaternion[0] + sinValueMax * firstQuaternion[3];

			if(dotMinAngle < 0.0)
			{
				cosValueMin = -cosValueMin;
				sinValueMin = -sinValueMin;
				dotMinAngle = -dotMinAngle;
			}

			if(dotMaxAngle < 0.0)
			{
				cosValueMax = -cosValueMax;
				sinValueMax = -sinValueMax;
				dotMaxAngle = -dotMaxAngle;
			}

			if(dotMaxAngle <= dotMinAngle)
			{
				ASSERT_APPROXIMATE(cosValueMin,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(sinValueMin,thirdQuaternion[3],1e-8f);				
			}
			else
			{
				ASSERT_APPROXIMATE(cosValueMax,thirdQuaternion[0],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[1],1e-8f);
				ASSERT_APPROXIMATE(0.0,thirdQuaternion[2],1e-8f);
				ASSERT_APPROXIMATE(sinValueMax,thirdQuaternion[3],1e-8f);
			}
		}

		firstQuaternion.Normalize();

		float thirdAngle = firstRandomDistribution(generator);

		uniform_real<float> fourthRandomDistribution(thirdAngle,FloatMath::GetHalfPI());

		float fourthAngle = fourthRandomDistribution(generator);

		FloatQuaternionConstraints secondQuaternionConstraints(thirdAngle,fourthAngle);

		secondQuaternion = firstQuaternion.GetClosestXY();
		thirdQuaternion = firstQuaternion.GetClosestXY(firstQuaternionConstraints,secondQuaternionConstraints);

		float det = firstQuaternion[0] * firstQuaternion[3] - firstQuaternion[1] * firstQuaternion[2];

		if (FloatMath::FAbs(det) < 0.5f - FloatMath::GetZeroTolerance())
		{
			float discr = FloatMath::Sqrt(FloatMath::FAbs(1.0f - 4.0f * det * det));

			float a = firstQuaternion[0] * firstQuaternion[1] + firstQuaternion[2] * firstQuaternion[3];
			float b = firstQuaternion[0] * firstQuaternion[0] - firstQuaternion[1] * firstQuaternion[1] +
					  firstQuaternion[2] * firstQuaternion[2] - firstQuaternion[3] * firstQuaternion[3];

			float c0 = 0.0f;
			float s0 = 0.0f;

			if (0.0f <= b)
			{
				c0 = 0.5f * (discr + b);
				s0 = a;
			}
			else
			{
				c0 = a;
				s0 = 0.5f * (discr - b);
			}
			float invLength = FloatMath::InvSqrt(c0 * c0 + s0 * s0);
			c0 *= invLength;
			s0 *= invLength;

			float c1 = firstQuaternion[0] * c0 + firstQuaternion[1] * s0;
			float s1 = firstQuaternion[2] * c0 + firstQuaternion[3] * s0;
			invLength = FloatMath::InvSqrt(c1 * c1 + s1 * s1);
			c1 *= invLength;
			s1 *= invLength;

			if (firstQuaternionConstraints.IsValid(c0, s0) && secondQuaternionConstraints.IsValid(c1, s1))
			{
				// secondQuaternion和thirdQuaterniony应该是相等的
			    ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f));  
			}
			else
			{
				// thirdQuaternion的值同边界点有关
				FloatQuaternion r(firstQuaternionConstraints.GetCosMinAngle(),firstQuaternionConstraints.GetSinMinAngle(),0.0f,0.0f);
				FloatQuaternion rInv = r.Conjugate();
				FloatQuaternion prod = rInv * firstQuaternion;
				FloatQuaternion tmp = prod.GetClosestY(secondQuaternionConstraints);
				float dotOptAngle = Dot(prod,tmp);
				FloatQuaternion q = r * tmp;

				r = FloatQuaternion(firstQuaternionConstraints.GetCosMaxAngle(), firstQuaternionConstraints.GetSinMaxAngle(),0.0f,0.0f);

				rInv = r.Conjugate();
				prod = rInv * firstQuaternion;
				tmp = prod.GetClosestY(secondQuaternionConstraints);
				float dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = r * tmp;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMinAngle(),0.0f,secondQuaternionConstraints.GetSinMinAngle(),0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestX(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMaxAngle(),0.0f,secondQuaternionConstraints.GetSinMaxAngle(),0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestX(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

			    ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f));  
			}
		}
		else
		{		
			float c0 = 0.0f;
			float s0 = 0.0f;
			float c1 = 0.0f;
			float s1 = 0.0f;

			if (0.0f < det)
			{
				float minAngle = firstQuaternionConstraints.GetMinAngle() - secondQuaternionConstraints.GetMaxAngle();
				float maxAngle = firstQuaternionConstraints.GetMaxAngle() - secondQuaternionConstraints.GetMinAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestX(con);

				float angle = FloatMath::ATan2(tmp[1], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[1] >=  0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());
				}

				if (angle <= firstQuaternionConstraints.GetMaxAngle() - secondQuaternionConstraints.GetMaxAngle())
				{
					c1 = secondQuaternionConstraints.GetCosMaxAngle();
					s1 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = secondQuaternionConstraints.GetMaxAngle() + angle;
					c0 = FloatMath::Cos(angle);
					s0 = FloatMath::Sin(angle);
				}
				else
				{
					c0 = firstQuaternionConstraints.GetCosMaxAngle();
					s0 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = firstQuaternionConstraints.GetMaxAngle() - angle;
					c1 = FloatMath::Cos(angle);
					s1 = FloatMath::Sin(angle);
				}
			}
			else
			{
				float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
				float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestX(con);

				float angle = FloatMath::ATan2(tmp[1], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[1] >= 0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());		
				}

				if (angle >= firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMaxAngle())
				{
					c1 = secondQuaternionConstraints.GetCosMaxAngle();
					s1 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = angle - secondQuaternionConstraints.GetMaxAngle();
					c0 = FloatMath::Cos(angle);
					s0 = FloatMath::Sin(angle);
				}
				else
				{
					c0 = firstQuaternionConstraints.GetCosMaxAngle();
					s0 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = angle - firstQuaternionConstraints.GetMaxAngle();
					c1 = FloatMath::Cos(angle);
					s1 = FloatMath::Sin(angle);
				}
			}

			FloatQuaternion q(c0 * c1,s0 * c1,c0 * s1,s0 * s1);

			if(Dot(firstQuaternion,q) < 0.0f)
			{
				q = -q;
			}

			ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f));  
		}


		secondQuaternion = firstQuaternion;
		secondQuaternion[3] = -secondQuaternion[3];
		secondQuaternion = secondQuaternion.GetClosestXY(secondQuaternionConstraints,firstQuaternionConstraints);

		secondQuaternion[3] = -secondQuaternion[3];

		thirdQuaternion = firstQuaternion.GetClosestYX(firstQuaternionConstraints,secondQuaternionConstraints);

		// secondQuaternion和thirdQuaterniony应该是相等的
		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f)); 

		secondQuaternion = firstQuaternion.GetClosestZX();
		thirdQuaternion = firstQuaternion.GetClosestZX(firstQuaternionConstraints,secondQuaternionConstraints);

		det = firstQuaternion[0] * firstQuaternion[2] - firstQuaternion[1] * firstQuaternion[3];

		if (FloatMath::FAbs(det) < 0.5f - FloatMath::GetZeroTolerance())
		{
			float discr = FloatMath::Sqrt(FloatMath::FAbs(1.0f - 4.0f * det * det));

			float a = firstQuaternion[0] * firstQuaternion[3] + 
				      firstQuaternion[1] * firstQuaternion[2];
			float b = firstQuaternion[0] * firstQuaternion[0] + 
				      firstQuaternion[1] * firstQuaternion[1] -
					  firstQuaternion[2] * firstQuaternion[2] - 
					  firstQuaternion[3] * firstQuaternion[3];

			float c2 = 0.0f;
			float s2 = 0.0f;

			if (0.0f <= b)
			{
				c2 = 0.5f * (discr + b);
				s2 = a;
			}
			else
			{
				c2 = a;
				s2 = 0.5f * (discr - b);
			}
			float invLength = FloatMath::InvSqrt(c2 * c2 + s2 * s2);
			c2 *= invLength;
			s2 *= invLength;

			float c0 = firstQuaternion[0] * c2 + firstQuaternion[3] * s2;
			float s0 = firstQuaternion[1] * c2 + firstQuaternion[2] * s2;
			invLength = FloatMath::InvSqrt(c0 * c0 + s0 * s0);
			c0 *= invLength;
			s0 *= invLength;

			if (firstQuaternionConstraints.IsValid(c2, s2) && secondQuaternionConstraints.IsValid(c0, s0))
			{
				// secondQuaternion和thirdQuaterniony应该是相等的
				ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-6f));
			}
			else
			{
				// thirdQuaternion的值同边界点有关
				FloatQuaternion r(firstQuaternionConstraints.GetCosMinAngle(),0.0f,0.0f,firstQuaternionConstraints.GetSinMinAngle());
				FloatQuaternion rInv = r.Conjugate();
				FloatQuaternion prod = rInv * firstQuaternion;
				FloatQuaternion tmp = prod.GetClosestX(secondQuaternionConstraints);
				float dotOptAngle = Dot(prod,tmp);
				FloatQuaternion q = r * tmp;

				r = FloatQuaternion(firstQuaternionConstraints.GetCosMaxAngle(),0.0f,0.0f,firstQuaternionConstraints.GetSinMaxAngle());

				rInv = r.Conjugate();
				prod = rInv * firstQuaternion;
				tmp = prod.GetClosestX(secondQuaternionConstraints);
				float dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = r * tmp;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMinAngle(),secondQuaternionConstraints.GetSinMinAngle(),0.0f,0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestZ(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMaxAngle(),secondQuaternionConstraints.GetSinMaxAngle(),0.0f,0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestZ(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

				ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f)); 
			}
		}
		else
		{		
			float c0 = 0.0f;
			float s0 = 0.0f;
			float c2 = 0.0f;
			float s2 = 0.0f;

			if (0.0f < det)
			{
				float minAngle = secondQuaternionConstraints.GetMinAngle() - firstQuaternionConstraints.GetMaxAngle();
				float maxAngle = secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMinAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestX(con);

				float angle = FloatMath::ATan2(tmp[1], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[1] >=  0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());
				}

				if (angle <= secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMaxAngle())
				{
					c2 = firstQuaternionConstraints.GetCosMaxAngle();
					s2 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = firstQuaternionConstraints.GetMaxAngle() + angle;
					c0 = FloatMath::Cos(angle);
					s0 = FloatMath::Sin(angle);
				}
				else
				{
					c0 = secondQuaternionConstraints.GetCosMaxAngle();
					s0 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = secondQuaternionConstraints.GetMaxAngle() - angle;
					c2 = FloatMath::Cos(angle);
					s2 = FloatMath::Sin(angle);
				}
			}
			else
			{
				float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
				float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestX(con);

				float angle = FloatMath::ATan2(tmp[1], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[1] >= 0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());		
				}

				if (angle >= secondQuaternionConstraints.GetMinAngle() + firstQuaternionConstraints.GetMaxAngle())
				{
					c2 = firstQuaternionConstraints.GetCosMaxAngle();
					s2 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = angle - firstQuaternionConstraints.GetMaxAngle();
					c0 = FloatMath::Cos(angle);
					s0 = FloatMath::Sin(angle);
				}
				else
				{
					c2 = secondQuaternionConstraints.GetCosMaxAngle();
					s2 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = angle - secondQuaternionConstraints.GetMaxAngle();
					c0 = FloatMath::Cos(angle);
					s0 = FloatMath::Sin(angle);
				}
			}

			FloatQuaternion q(c2 * c0,c2 * s0,s0 * s2,c0 * s2);

			if(Dot(firstQuaternion,q) < 0.0f)
			{
				q = -q;
			}

			ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f)); 		
		}


		secondQuaternion = firstQuaternion;
		secondQuaternion[2] = -secondQuaternion[2];
		secondQuaternion = secondQuaternion.GetClosestZX(secondQuaternionConstraints, firstQuaternionConstraints);

		secondQuaternion[2] = -secondQuaternion[2];

		thirdQuaternion = firstQuaternion.GetClosestXZ(firstQuaternionConstraints,secondQuaternionConstraints);

		// secondQuaternion和thirdQuaterniony应该是相等的
		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f)); 

		secondQuaternion = firstQuaternion.GetClosestZY();
		thirdQuaternion = firstQuaternion.GetClosestZY(firstQuaternionConstraints,secondQuaternionConstraints);

		det = firstQuaternion[0] * firstQuaternion[1] + firstQuaternion[2] * firstQuaternion[3];

		if (FloatMath::FAbs(det) < 0.5f - FloatMath::GetZeroTolerance())
		{
			float discr = FloatMath::Sqrt(FloatMath::FAbs(1.0f - 4.0f * det * det));

			float a = firstQuaternion[0] * firstQuaternion[3] - 
				      firstQuaternion[1] * firstQuaternion[2];
			float b = firstQuaternion[0] * firstQuaternion[0] - 
				      firstQuaternion[1] * firstQuaternion[1] +
					  firstQuaternion[2] * firstQuaternion[2] - 
					  firstQuaternion[3] * firstQuaternion[3];

			float c2 = 0.0f;
			float s2 = 0.0f;

			if (0.0f <= b)
			{
				c2 = 0.5f * (discr + b);
				s2 = a;
			}
			else
			{
				c2 = a;
				s2 = 0.5f * (discr - b);
			}
			float invLength = FloatMath::InvSqrt(c2 * c2 + s2 * s2);
			c2 *= invLength;
			s2 *= invLength;

			float c1 = firstQuaternion[0] * c2 + firstQuaternion[3] * s2;
			float s1 = firstQuaternion[2] * c2 - firstQuaternion[1] * s2;
			invLength = FloatMath::InvSqrt(c1 * c1 + s1 * s1);
			c1 *= invLength;
			s1 *= invLength;

			if (firstQuaternionConstraints.IsValid(c2, s2) && secondQuaternionConstraints.IsValid(c1, s1))
			{
				// secondQuaternion和thirdQuaterniony应该是相等的
				ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-6f)); 
			}
			else
			{
				// thirdQuaternion的值同边界点有关
				FloatQuaternion r(firstQuaternionConstraints.GetCosMinAngle(),0.0f,0.0f,firstQuaternionConstraints.GetSinMinAngle());
				FloatQuaternion rInv = r.Conjugate();
				FloatQuaternion prod = rInv * firstQuaternion;
				FloatQuaternion tmp = prod.GetClosestY(secondQuaternionConstraints);
				float dotOptAngle = Dot(prod,tmp);
				FloatQuaternion q = r * tmp;

				r = FloatQuaternion(firstQuaternionConstraints.GetCosMaxAngle(),0.0f,0.0f, firstQuaternionConstraints.GetSinMaxAngle());

				rInv = r.Conjugate();
				prod = rInv * firstQuaternion;
				tmp = prod.GetClosestY(secondQuaternionConstraints);
				float dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = r * tmp;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMinAngle(),0.0f,secondQuaternionConstraints.GetSinMinAngle(),0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestZ(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

				r = FloatQuaternion(secondQuaternionConstraints.GetCosMaxAngle(),0.0f,secondQuaternionConstraints.GetSinMaxAngle(),0.0f);
				rInv = r.Conjugate();
				prod = firstQuaternion * rInv;
				tmp = prod.GetClosestZ(firstQuaternionConstraints);
				dotAngle = Dot(prod,tmp);
				if (dotAngle > dotOptAngle)
				{
					q = tmp * r;
					dotOptAngle = dotAngle;
				}

				ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f)); 				
			}
		}
		else
		{		
			float c1 = 0.0f;
			float s1 = 0.0f;
			float c2 = 0.0f;
			float s2 = 0.0f;

			if (0.0f < det)
			{
				float minAngle = secondQuaternionConstraints.GetMinAngle() - firstQuaternionConstraints.GetMaxAngle();
				float maxAngle = secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMinAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestY(con);

				float angle = FloatMath::ATan2(tmp[2], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[2] >=  0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());
				}

				if (angle <= secondQuaternionConstraints.GetMaxAngle() - firstQuaternionConstraints.GetMaxAngle())
				{
					c2 = firstQuaternionConstraints.GetCosMaxAngle();
					s2 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = firstQuaternionConstraints.GetMaxAngle() + angle;
					c1 = FloatMath::Cos(angle);
					s1 = FloatMath::Sin(angle);
				}
				else
				{
					c1 = secondQuaternionConstraints.GetCosMaxAngle();
					s1 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = secondQuaternionConstraints.GetMaxAngle() - angle;
					c2 = FloatMath::Cos(angle);
					s2 = FloatMath::Sin(angle);
				}
			}
			else
			{
				float minAngle = firstQuaternionConstraints.GetMinAngle() + secondQuaternionConstraints.GetMinAngle();
				float maxAngle = firstQuaternionConstraints.GetMaxAngle() + secondQuaternionConstraints.GetMaxAngle();
				FloatQuaternionConstraints con(minAngle, maxAngle);

				FloatQuaternion tmp = firstQuaternion.GetClosestY(con);

				float angle = FloatMath::ATan2(tmp[2], tmp[0]);
				if (angle < minAngle || angle > maxAngle)
				{
					angle -= (tmp[2] >= 0.0f ? FloatMath::GetPI() : -FloatMath::GetPI());		
				}

				if (angle >= secondQuaternionConstraints.GetMinAngle() + firstQuaternionConstraints.GetMaxAngle())
				{
					c2 = firstQuaternionConstraints.GetCosMaxAngle();
					s2 = firstQuaternionConstraints.GetSinMaxAngle();
					angle = angle - firstQuaternionConstraints.GetMaxAngle();
					c1 = FloatMath::Cos(angle);
					s1 = FloatMath::Sin(angle);
				}
				else
				{
					c1 = secondQuaternionConstraints.GetCosMaxAngle();
					s1 = secondQuaternionConstraints.GetSinMaxAngle();
					angle = angle - secondQuaternionConstraints.GetMaxAngle();
					c2 = FloatMath::Cos(angle);
					s2 = FloatMath::Sin(angle);
				}
			}

			FloatQuaternion q(c2 * c1,-s1 * s2,s1 * c2,c1 * s2);

			if(Dot(firstQuaternion,q) < 0.0f)
			{
				q = -q;
			}

			ASSERT_TRUE(Approximate(q, thirdQuaternion,1e-8f)); 		
		}


		secondQuaternion = firstQuaternion;
		secondQuaternion[1] = -secondQuaternion[1];
		secondQuaternion = 	secondQuaternion.GetClosestZY(secondQuaternionConstraints,firstQuaternionConstraints);

		secondQuaternion[1] = -secondQuaternion[1];

		thirdQuaternion = firstQuaternion.GetClosestYZ(firstQuaternionConstraints,secondQuaternionConstraints);

		// secondQuaternion和thirdQuaterniony应该是相等的
		ASSERT_TRUE(Approximate(secondQuaternion, thirdQuaternion,1e-8f)); 
	}
}


void Mathematics::QuaternionTesting
	::CompareTest()
{
	default_random_engine generator{};
 
	uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f }; 

	FloatQuaternion firstQuaternion(firstRandomDistribution(generator),
			                    firstRandomDistribution(generator),
							    firstRandomDistribution(generator),
								firstRandomDistribution(generator));

	FloatQuaternion secondQuaternion(firstRandomDistribution(generator),
			                     firstRandomDistribution(generator),
							     firstRandomDistribution(generator),
								 firstRandomDistribution(generator));

	ASSERT_TRUE(firstQuaternion == firstQuaternion);
	ASSERT_FALSE(firstQuaternion == secondQuaternion);
	ASSERT_TRUE(firstQuaternion != secondQuaternion);

	if(!(firstQuaternion < secondQuaternion))
	{
		firstQuaternion[0] = 0.0f;
		secondQuaternion[0] = 1.0f;
	}

	ASSERT_TRUE(firstQuaternion < secondQuaternion);
	ASSERT_FALSE(firstQuaternion > secondQuaternion);
	ASSERT_TRUE(firstQuaternion <= secondQuaternion);
	ASSERT_FALSE(firstQuaternion >= secondQuaternion);

	ASSERT_TRUE(Approximate(firstQuaternion, firstQuaternion,1e-8f));
	ASSERT_TRUE(Approximate(secondQuaternion, secondQuaternion,1e-8f));
	ASSERT_FALSE(Approximate(firstQuaternion, secondQuaternion,1e-8f));

	GetStream() << "以下是调试信息：\n";
	GetStream() << firstQuaternion << '\n';
	GetStream() << secondQuaternion << '\n';
}

