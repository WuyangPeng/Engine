// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 15:34)

#include "HomogeneousPointTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class HomogeneousPoint<float>;
    template class HomogeneousPoint<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, HomogeneousPointTesting)

void Mathematics::HomogeneousPointTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::HomogeneousPointTesting ::ConstructionTest()
{
    HomogeneousPointF firstPoint;

    ASSERT_APPROXIMATE(firstPoint[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[3], 0.0f, 1e-8f);

    firstPoint.SetX(1.0f);
    firstPoint.SetY(2.0f);
    firstPoint.SetW(4.0f);

    HomogeneousPointF secondPoint(firstPoint);

    ASSERT_APPROXIMATE(secondPoint[0], 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondPoint[1], 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondPoint[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondPoint[3], 4.0f, 1e-8f);

    ASSERT_TRUE(Approximate(firstPoint, secondPoint, 1e-8f));

    HomogeneousPointD thirdPoint(3.0, 5.0, 6.0, 7.0);

    ASSERT_APPROXIMATE(thirdPoint[0], 3.0, 1e-10);
    ASSERT_APPROXIMATE(thirdPoint[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(thirdPoint[2], 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdPoint[3], 7.0, 1e-10);

    secondPoint.SetX(11.0f);
    secondPoint.SetY(12.0f);
    secondPoint.SetZ(14.0f);

    ASSERT_FALSE(Approximate(firstPoint, secondPoint, 1e-8f));

    firstPoint = secondPoint;

    ASSERT_APPROXIMATE(firstPoint[0], 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], 14.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[3], 4.0f, 1e-8f);

    ASSERT_TRUE(Approximate(firstPoint, secondPoint, 1e-8f));
}

void Mathematics::HomogeneousPointTesting ::AccessTest()
{
    HomogeneousPointF firstPoint(1.0f, 2.0f, 0.0f, 4.0f);

    ASSERT_APPROXIMATE(firstPoint[0], 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[1], 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[2], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint[3], 4.0f, 1e-8f);

    // 	ASSERT_APPROXIMATE(*firstPoint.GetCoordinate(),1.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(*(firstPoint.GetCoordinate() + 1),2.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(*(firstPoint.GetCoordinate() + 2),0.0f,1e-8f);
    // 	ASSERT_APPROXIMATE(*(firstPoint.GetCoordinate() + 3),4.0f,1e-8f);

    ASSERT_APPROXIMATE(firstPoint.GetX(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetY(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetZ(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetW(), 4.0f, 1e-8f);

    firstPoint.SetX(6.0f);
    firstPoint.SetY(8.0f);
    firstPoint.SetZ(2.0f);
    firstPoint.SetW(9.0f);

    ASSERT_APPROXIMATE(firstPoint.GetX(), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetY(), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetZ(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstPoint.GetW(), 9.0f, 1e-8f);

    const HomogeneousPointD secondPoint(5.0, 1.0, 3.0, 2.0);

    ASSERT_APPROXIMATE(secondPoint[0], 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint[2], 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint[3], 2.0, 1e-10);

    // 	ASSERT_APPROXIMATE(*secondPoint.GetCoordinate(),5.0,1e-10);
    // 	ASSERT_APPROXIMATE(*(secondPoint.GetCoordinate() + 1),1.0,1e-10);
    // 	ASSERT_APPROXIMATE(*(secondPoint.GetCoordinate() + 2),3.0,1e-10);
    // 	ASSERT_APPROXIMATE(*(secondPoint.GetCoordinate() + 3),2.0,1e-10);

    ASSERT_APPROXIMATE(secondPoint.GetX(), 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint.GetY(), 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint.GetZ(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(secondPoint.GetW(), 2.0, 1e-10);
}

void Mathematics::HomogeneousPointTesting ::CompareTest()
{
    const HomogeneousPointF firstPoint(1.0f, 2.0f, 0.0f, 4.0f);
    const HomogeneousPointF secondPoint;

    ASSERT_FALSE(firstPoint == secondPoint);
    ASSERT_TRUE(firstPoint != secondPoint);

    ASSERT_FALSE(firstPoint < secondPoint);
    ASSERT_TRUE(firstPoint > secondPoint);
    ASSERT_FALSE(firstPoint <= secondPoint);
    ASSERT_TRUE(firstPoint >= secondPoint);

    ASSERT_TRUE(Approximate(firstPoint, firstPoint, 1e-8f));
    ASSERT_TRUE(Approximate(secondPoint, secondPoint, 1e-8f));
    ASSERT_FALSE(Approximate(firstPoint, secondPoint, 1e-8f));
}
