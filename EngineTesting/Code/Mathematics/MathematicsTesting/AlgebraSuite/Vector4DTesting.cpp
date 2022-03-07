// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:27)

#include "Vector4DTesting.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
	template class Vector4<float>;
	template class Vector4<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector4Testing) 

void Mathematics::Vector4Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
	ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
void Mathematics::Vector4Testing
	::ConstructionTest()
{
// 	FloatVector4 firstVector;
// 
// 	ASSERT_APPROXIMATE(firstVector[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(firstVector[3],0.0f,1e-8f);
// 
// 	FloatVector4::Tuple4 tuple(1.0f,3.0f,13.0f,23.0f);
// 
// 	FloatVector4 secondVector(tuple);
// 
// 	ASSERT_APPROXIMATE(secondVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[1],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[2],13.0f,1e-8f);
// 	ASSERT_APPROXIMATE(secondVector[3],23.0f,1e-8f);
// 
// 	DoubleVector4 thirdVector(6.0,9.0,34.0,8.0);
// 
// 	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[1],9.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[2],34.0,1e-10);
// 	ASSERT_APPROXIMATE(thirdVector[3],8.0,1e-10);
// 
// 	FloatVector4 fourthVector(thirdVector);
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],6.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],9.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[2],34.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[3],8.0f,1e-8f);
// 
// 	fourthVector = tuple;
// 
// 	ASSERT_APPROXIMATE(fourthVector[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[1],3.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[2],13.0f,1e-8f);
// 	ASSERT_APPROXIMATE(fourthVector[3],23.0f,1e-8f);
// 
// 	FloatVector2 fifthVector(3.0f,8.0f);
// 	DoubleVector4 sixthVector(fifthVector);
// 
// 	ASSERT_APPROXIMATE(sixthVector[0],3.0f,1e-10);
// 	ASSERT_APPROXIMATE(sixthVector[1],8.0f,1e-10);
// 	ASSERT_APPROXIMATE(sixthVector[2],0.0f,1e-10);
// 	ASSERT_APPROXIMATE(sixthVector[3],0.0f,1e-10);
// 
// 	FloatVector3 seventhVector(3.0f,8.0f,60.0f);
// 	DoubleVector4 eighthVector(seventhVector);
// 
// 	ASSERT_APPROXIMATE(eighthVector[0],3.0f,1e-10);
// 	ASSERT_APPROXIMATE(eighthVector[1],8.0f,1e-10);
// 	ASSERT_APPROXIMATE(eighthVector[2],60.0f,1e-10);
// 	ASSERT_APPROXIMATE(eighthVector[3],0.0f,1e-10);
// 
// 	ASSERT_APPROXIMATE(FloatVector4::sm_One[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_One[1],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_One[2],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_One[3],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_Zero[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_Zero[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_Zero[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_Zero[3],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnit()[0],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnit()[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnit()[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnit()[3],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitY()[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitY()[1],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitY()[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitY()[3],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitZ()[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitZ()[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitZ()[2],1.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::GetUnitZ()[3],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_UnitW[0],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_UnitW[1],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_UnitW[2],0.0f,1e-8f);
// 	ASSERT_APPROXIMATE(FloatVector4::sm_UnitW[3],1.0f,1e-8f);
}

void Mathematics::Vector4Testing
	::AccessTest()
{
	Vector4D firstVector(6.0,9.0,4.0,89.0);

	ASSERT_APPROXIMATE(firstVector.GetX(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),9.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),4.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetW(),89.0,1e-10);
	ASSERT_FALSE(firstVector.IsZero());

	Vector3D secondVector;
	ASSERT_TRUE(secondVector.IsZero());

	firstVector.ZeroOut();
	ASSERT_TRUE(firstVector.IsZero());

	firstVector.SetCoordinate(9.0,6.0,8.0,1.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),9.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),8.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetW(),1.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(7.0);
	firstVector.SetZ(17.0);
	firstVector.SetW(8.0);
	ASSERT_APPROXIMATE(firstVector.GetX(),3.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),7.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),17.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetW(),8.0,1e-10);

	firstVector.SetX(6.0);
	firstVector.SetY(9.0);
	firstVector.SetZ(18.0);
	firstVector.SetW(3.0);
	firstVector.ProjectionNormalization();

	ASSERT_APPROXIMATE(firstVector.GetX(),2.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),3.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),6.0,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetW(),1.0,1e-10);

	firstVector.SetX(3.0);
	firstVector.SetY(4.0);
	firstVector.SetZ(1.0);
	firstVector.SetW(2.0);
	firstVector.Normalize();

	double magnitude = MathD::Sqrt(30.0);

	ASSERT_APPROXIMATE(firstVector.GetX(),3.0 / magnitude,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetY(),4.0 / magnitude,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetZ(),1.0 / magnitude,1e-10);
	ASSERT_APPROXIMATE(firstVector.GetW(),2.0 / magnitude,1e-10);
}

void Mathematics::Vector4Testing
	::CalculateTest()
{
	Vector4F firstVector(26.0f,91.0f,8.0f,-5.0f);

	Vector4F secondVector = -firstVector;
	ASSERT_APPROXIMATE(secondVector.GetX(),-26.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),-91.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetZ(),-8.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetW(),5.0f,1e-8f);

	secondVector[0] = 3.0f;
	secondVector[1] = 7.0f;
	secondVector[2] = 17.0f;
	secondVector[3] = -187.0f;

	ASSERT_APPROXIMATE(secondVector.GetX(),3.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetY(),7.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetZ(),17.0f,1e-8f);
	ASSERT_APPROXIMATE(secondVector.GetW(),-187.0f,1e-8f);

	const Vector4D thirdVector(6.0,5.0,15.0,-8.0);

	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[2],15.0,1e-10);
	ASSERT_APPROXIMATE(thirdVector[3],-8.0,1e-10);

	Vector4D fourthVector(9.0,3.0,3.0,-7.0);
	fourthVector += thirdVector;
	ASSERT_APPROXIMATE(fourthVector[0],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],8.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],18.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[3],-15.0,1e-10);

	Vector4D fifthVector = thirdVector + fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],21.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],13.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],33.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[3],-23.0,1e-10);

	fifthVector -= fourthVector;

	ASSERT_APPROXIMATE(fifthVector[0],6.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],5.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],15.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[3],-8.0,1e-10);

	fourthVector = fifthVector - thirdVector;

	ASSERT_APPROXIMATE(fourthVector[0],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],0.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[3],0.0,1e-10);

	fifthVector *= 6.0;

	ASSERT_APPROXIMATE(fifthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],90.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[3],-48.0,1e-10);

	fourthVector = 0.5 * fifthVector;

	ASSERT_APPROXIMATE(fourthVector[0],18.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],15.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],45.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[3],-24.0,1e-10);

	fourthVector = fifthVector * 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],72.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],60.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],180.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[3],-96.0,1e-10);

	fourthVector /= 2.0;

	ASSERT_APPROXIMATE(fourthVector[0],36.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[1],30.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[2],90.0,1e-10);
	ASSERT_APPROXIMATE(fourthVector[3],-48.0,1e-10);

	fifthVector = fourthVector / 3.0;

	ASSERT_APPROXIMATE(fifthVector[0],12.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[1],10.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[2],30.0,1e-10);
	ASSERT_APPROXIMATE(fifthVector[3],-16.0,1e-10);
}

