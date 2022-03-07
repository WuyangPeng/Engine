// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:14)

#include "Vector3DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"

#include "Mathematics/Algebra/BarycentricCoordinates.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Vector3<float>;
    template class Vector3<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26481)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector3Testing)

void Mathematics::Vector3Testing ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BarycentricsTest);
}

void Mathematics::Vector3Testing ::ConstructionTest()
{
    // 	FloatVector3 firstVector;
    //
    // 	ASSERT_APPROXIMATE(firstVector[0],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(firstVector[1],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(firstVector[2],0.0f,1e-8f);
    //
    // 	FloatVector3::Tuple3 tuple(1.0f,3.0f,13.0f);
    //
    // 	FloatVector3 secondVector(tuple);
    //
    // 	ASSERT_APPROXIMATE(secondVector[0],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(secondVector[1],3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(secondVector[2],13.0f,1e-8f);
    //
    // 	DoubleVector3 thirdVector(6.0,9.0,34.0);
    //
    // 	ASSERT_APPROXIMATE(thirdVector[0],6.0,1e-10);
    // 	ASSERT_APPROXIMATE(thirdVector[1],9.0,1e-10);
    // 	ASSERT_APPROXIMATE(thirdVector[2],34.0,1e-10);
    //
    // 	FloatVector3 fourthVector(thirdVector);
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
    // 	FloatVector2 fifthVector(3.0f,8.0f);
    // 	DoubleVector3 sixthVector(fifthVector);
    //
    // 	ASSERT_APPROXIMATE(sixthVector[0],3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(sixthVector[1],8.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(sixthVector[2],0.0f,1e-8f);
    //
    // 	FloatVector4 seventhVector(3.0f,8.0f,60.0f,1.0f);
    // 	DoubleVector3 eighthVector(seventhVector);
    //
    // 	ASSERT_APPROXIMATE(eighthVector[0],3.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(eighthVector[1],8.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(eighthVector[2],60.0f,1e-8f);
    //
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_One[0],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_One[1],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_One[2],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_Zero[0],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_Zero[1],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::sm_Zero[2],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnit()[0],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnit()[1],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnit()[2],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitY()[0],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitY()[1],1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitY()[2],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitZ()[0],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitZ()[1],0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(FloatVector3::GetUnitZ()[2],1.0f,1e-8f);
}

void Mathematics::Vector3Testing ::AccessTest()
{
    Vector3D firstVector(6.0, 9.0, 4.0);

    ASSERT_APPROXIMATE(firstVector.GetX(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 4.0, 1e-10);
    ASSERT_FALSE(firstVector.IsZero());

    Vector3D secondVector;
    ASSERT_TRUE(secondVector.IsZero());

    firstVector.ZeroOut();
    ASSERT_TRUE(firstVector.IsZero());

    firstVector.SetCoordinate(9.0, 6.0, 8.0);
    ASSERT_APPROXIMATE(firstVector.GetX(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 8.0, 1e-10);

    firstVector.SetX(3.0);
    firstVector.SetY(7.0);
    firstVector.SetZ(17.0);
    ASSERT_APPROXIMATE(firstVector.GetX(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 17.0, 1e-10);

    firstVector.SetX(3.0);
    firstVector.SetY(4.0);
    firstVector.SetZ(0.0);

    ASSERT_FALSE(firstVector.IsNormalize());

    firstVector.Normalize();

    ASSERT_TRUE(firstVector.IsNormalize());

    ASSERT_APPROXIMATE(firstVector.GetX(), 0.6, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 0.8, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 0.0, 1e-10);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::Vector3Testing ::CalculateTest()
{
    Vector3F firstVector(26.0f, 91.0f, 8.0f);

    Vector3F secondVector = -firstVector;
    ASSERT_APPROXIMATE(secondVector.GetX(), -26.0, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetY(), -91.0, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetZ(), -8.0, 1e-8f);

    secondVector[0] = 3.0f;
    secondVector[1] = 7.0f;
    secondVector[2] = 17.0f;

    ASSERT_APPROXIMATE(secondVector.GetX(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetY(), 7.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetZ(), 17.0f, 1e-8f);

    const Vector3D thirdVector(6.0, 5.0, 15.0);

    ASSERT_APPROXIMATE(thirdVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[2], 15.0, 1e-10);

    Vector3D fourthVector(9.0, 3.0, 3.0);
    fourthVector += thirdVector;
    ASSERT_APPROXIMATE(fourthVector[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 8.0, 0.1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 18.0, 1e-10);

    Vector3D fifthVector = thirdVector + fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 13.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 33.0, 1e-10);

    fifthVector -= fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 15.0, 1e-10);

    fourthVector = fifthVector - thirdVector;

    ASSERT_APPROXIMATE(fourthVector[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 0.0, 1e-10);

    fifthVector *= 6.0;

    ASSERT_APPROXIMATE(fifthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 90.0, 1e-10);

    fourthVector = 0.5 * fifthVector;

    ASSERT_APPROXIMATE(fourthVector[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 45.0, 1e-10);

    fourthVector = fifthVector * 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 60.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 180.0, 1e-10);

    fourthVector /= 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 90.0, 1e-10);

    fifthVector = fourthVector / 3.0;

    ASSERT_APPROXIMATE(fifthVector[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 10.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 30.0, 1e-10);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector3Testing ::BarycentricsTest()
{
    Vector3D firstVector(1.0, 0.0, 0.0);
    Vector3D secondVector(0.0, 1.0, 0.0);
    Vector3D thirdVector(0.0, 0.0, 1.0);
    Vector3D fourthVector(0.0, 0.0, 0.0);

    Vector3D::BarycentricCoordinates firstCoordinates = firstVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

    ASSERT_TRUE(firstCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(firstCoordinates[0], 1.0, 1e-10);
    ASSERT_APPROXIMATE(firstCoordinates[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(firstCoordinates[2], 0.0, 1e-10);
    ASSERT_APPROXIMATE(firstCoordinates[3], 0.0, 1e-10);

    Vector3D::BarycentricCoordinates secondCoordinates = secondVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

    ASSERT_TRUE(secondCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(secondCoordinates[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(secondCoordinates[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondCoordinates[2], 0.0, 1e-10);
    ASSERT_APPROXIMATE(secondCoordinates[3], 0.0, 1e-10);

    Vector3D::BarycentricCoordinates thirdCoordinates = thirdVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

    ASSERT_TRUE(thirdCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(thirdCoordinates[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirdCoordinates[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirdCoordinates[2], 1.0, 1e-10);
    ASSERT_APPROXIMATE(thirdCoordinates[3], 0.0, 1e-10);

    Vector3D::BarycentricCoordinates fourthCoordinates = fourthVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

    ASSERT_TRUE(fourthCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(fourthCoordinates[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthCoordinates[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthCoordinates[2], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthCoordinates[3], 1.0, 1e-10);

    Vector3D fifthVector(0.1, 0.1, 0.1);

    Vector3D::BarycentricCoordinates fifthCoordinates = fifthVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

    ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(fifthCoordinates[0] + fifthCoordinates[1] + fifthCoordinates[2] + fifthCoordinates[3], 1.0, 1e-10);

    default_random_engine generator{};

    uniform_real<double> randomDistribution{ -10.0, 10.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Vector3D sixthVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        Vector3D::BarycentricCoordinates sixthCoordinates = sixthVector.GetBarycentrics(firstVector, secondVector, thirdVector, fourthVector);

        ASSERT_TRUE(sixthCoordinates.IsBarycentricCoordinatesValid());

        Vector3D difference[4]{ firstVector - fourthVector, secondVector - fourthVector, thirdVector - fourthVector, sixthVector - fourthVector };

        double det = Vector3ToolsD::ScalarTripleProduct(difference[1], difference[2], difference[0]);

        Vector3D e1CrossE2 = Vector3ToolsD::CrossProduct(difference[1], difference[2]);
        Vector3D e2CrossE0 = Vector3ToolsD::CrossProduct(difference[2], difference[0]);
        Vector3D e0CrossE1 = Vector3ToolsD::CrossProduct(difference[0], difference[1]);

        double bary0 = Vector3ToolsD::DotProduct(difference[3], e1CrossE2) / det;
        double bary1 = Vector3ToolsD::DotProduct(difference[3], e2CrossE0) / det;
        double bary2 = Vector3ToolsD::DotProduct(difference[3], e0CrossE1) / det;
        double bary3 = 1.0 - bary0 - bary1 - bary2;

        ASSERT_TRUE(sixthCoordinates.IsBarycentricCoordinatesValid());
        ASSERT_APPROXIMATE(sixthCoordinates[0], bary0, 1e-10);
        ASSERT_APPROXIMATE(sixthCoordinates[1], bary1, 1e-10);
        ASSERT_APPROXIMATE(sixthCoordinates[2], bary2, 1e-10);
        ASSERT_APPROXIMATE(sixthCoordinates[3], bary3, 1e-10);
    }
}
