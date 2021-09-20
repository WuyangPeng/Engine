// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/21 15:17)
    
#include "EulerTesting.h"
#include "Mathematics/Algebra/EulerDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
    
#include <random> 

using std::uniform_real;
using std::default_random_engine;
    
#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Euler<float>;
    template class Euler<double>;
}

#endif // BUILDING_MATHEMATICS_STATIC

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,EulerTesting) 

void Mathematics::EulerTesting
	::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXYZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZYXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXYXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZYZTest);
}
    
void Mathematics::EulerTesting
	::EulerXYZTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() }; 
    
	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = firstAngleDistribution(generator);
        double yAngle = secondAngleDistribution(generator);
        double zAngle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerXYZ(xAngle, yAngle, zAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerXYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
        ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYZ);
        
        firstMatrix.MakeEulerXYZ(xAngle - zAngle, DoubleMath::GetHalfPI(), zAngle);
        
        firstEuler = firstMatrix.ExtractEulerXYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYZ);
        
        firstMatrix.MakeEulerXYZ(xAngle + zAngle, -DoubleMath::GetHalfPI(), zAngle);
        
        firstEuler = firstMatrix.ExtractEulerXYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), -DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYZ);
    }
}

void Mathematics::EulerTesting
    ::EulerXZYTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = firstAngleDistribution(generator);
        double yAngle = firstAngleDistribution(generator);
        double zAngle = secondAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerXZY(xAngle, zAngle,yAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerXZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZY);
        
        firstMatrix.MakeEulerXZY(xAngle + yAngle, DoubleMath::GetHalfPI(), yAngle);
        
        firstEuler = firstMatrix.ExtractEulerXZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), DoubleMath::GetHalfPI(),1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZY);
        
        firstMatrix.MakeEulerXZY(xAngle - yAngle, -DoubleMath::GetHalfPI(), yAngle);
        
        firstEuler = firstMatrix.ExtractEulerXZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), -DoubleMath::GetHalfPI(),1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZY);
    }
}

void Mathematics::EulerTesting
    ::EulerYXZTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = secondAngleDistribution(generator);
        double yAngle = firstAngleDistribution(generator);
        double zAngle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerYXZ(yAngle,xAngle,zAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerYXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXZ);
        
        firstMatrix.MakeEulerYXZ(yAngle + zAngle, DoubleMath::GetHalfPI(), zAngle);
        
        firstEuler = firstMatrix.ExtractEulerYXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXZ);
        
        firstMatrix.MakeEulerYXZ(yAngle - zAngle, -DoubleMath::GetHalfPI(), zAngle);
        
        firstEuler = firstMatrix.ExtractEulerYXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), -DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXZ);
    }
}

void Mathematics::EulerTesting
    ::EulerYZXTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = firstAngleDistribution(generator);
        double yAngle = firstAngleDistribution(generator);
        double zAngle = secondAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerYZX(yAngle, zAngle, xAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerYZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZX);
        
        firstMatrix.MakeEulerYZX(yAngle + xAngle, -DoubleMath::GetHalfPI(), xAngle);
        
        firstEuler = firstMatrix.ExtractEulerYZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), -DoubleMath::GetHalfPI(),1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZX);
        
        firstMatrix.MakeEulerYZX(yAngle - xAngle, DoubleMath::GetHalfPI(), xAngle);
        
        firstEuler = firstMatrix.ExtractEulerYZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), DoubleMath::GetHalfPI(),1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZX);
    }
}
void Mathematics::EulerTesting
    ::EulerZXYTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = secondAngleDistribution(generator);
        double yAngle = firstAngleDistribution(generator);
        double zAngle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerZXY(zAngle, xAngle, yAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerZXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXY);
        
        firstMatrix.MakeEulerZXY(zAngle + yAngle, -DoubleMath::GetHalfPI(), yAngle);
        
        firstEuler = firstMatrix.ExtractEulerZXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), -DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXY);
        
        firstMatrix.MakeEulerZXY(zAngle - yAngle, DoubleMath::GetHalfPI(), yAngle);
        
        firstEuler = firstMatrix.ExtractEulerZXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXY);
    }
}

void Mathematics::EulerTesting
    ::EulerZYXTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ -DoubleMath::GetHalfPI(),DoubleMath::GetHalfPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double xAngle = firstAngleDistribution(generator);
        double yAngle = secondAngleDistribution(generator);
        double zAngle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerZYX(zAngle, yAngle, xAngle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerZYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYX);
        
        firstMatrix.MakeEulerZYX(zAngle + xAngle, DoubleMath::GetHalfPI(), xAngle);
        
        firstEuler = firstMatrix.ExtractEulerZYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYX);
        
        firstMatrix.MakeEulerZYX(zAngle - xAngle, -DoubleMath::GetHalfPI(), xAngle);
        
        firstEuler = firstMatrix.ExtractEulerZYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), -DoubleMath::GetHalfPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYX);
    }
}

void Mathematics::EulerTesting
    ::EulerXYXTest()
{ 
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double x0Angle = firstAngleDistribution(generator);
        double yAngle = secondAngleDistribution(generator);
        double x1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerXYX(x0Angle, yAngle, x1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerXYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), x1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYX);
        
        firstMatrix.MakeEulerXYX(x0Angle - x1Angle, 0.0, x1Angle);
        
        firstEuler = firstMatrix.ExtractEulerXYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYX);
        
        firstMatrix.MakeEulerXYX(x0Angle + x1Angle, DoubleMath::GetPI(), x1Angle);
        
        firstEuler = firstMatrix.ExtractEulerXYX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XYX);
    }
}

void Mathematics::EulerTesting
    ::EulerXZXTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double x0Angle = firstAngleDistribution(generator);
        double zAngle = secondAngleDistribution(generator);
        double x1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerXZX(x0Angle, zAngle, x1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerXZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), x1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZX);
        
        firstMatrix.MakeEulerXZX(x0Angle + x1Angle, DoubleMath::GetPI(), x1Angle);
        
        firstEuler = firstMatrix.ExtractEulerXZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZX);
        
        firstMatrix.MakeEulerXZX(x0Angle - x1Angle, 0.0, x1Angle);
        
        firstEuler = firstMatrix.ExtractEulerXZX();
        
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), x0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::XZX);
    }
}

void Mathematics::EulerTesting
    ::EulerYXYTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double y0Angle = firstAngleDistribution(generator);
        double xAngle = secondAngleDistribution(generator);
        double y1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerYXY(y0Angle, xAngle, y1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerYXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), y1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXY);
        
        firstMatrix.MakeEulerYXY(y0Angle + y1Angle, DoubleMath::GetPI(), y1Angle);
        
        firstEuler = firstMatrix.ExtractEulerYXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXY);
        
        firstMatrix.MakeEulerYXY(y0Angle - y1Angle, 0.0, y1Angle);
        
        firstEuler = firstMatrix.ExtractEulerYXY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YXY);
    }
}

void Mathematics::EulerTesting
    ::EulerYZYTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double y0Angle = firstAngleDistribution(generator);
        double zAngle = secondAngleDistribution(generator);
        double y1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerYZY(y0Angle, zAngle, y1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerYZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), zAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), y1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZY);
        
        firstMatrix.MakeEulerYZY(y0Angle + y1Angle, DoubleMath::GetPI(), y1Angle);
        
        firstEuler = firstMatrix.ExtractEulerYZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZY);
        
        firstMatrix.MakeEulerYZY(y0Angle - y1Angle, 0.0, y1Angle);
        
        firstEuler = firstMatrix.ExtractEulerYZY();
        
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), y0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::YZY);
    }
}

void Mathematics::EulerTesting
    ::EulerZXZTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double z0Angle = firstAngleDistribution(generator);
        double xAngle = secondAngleDistribution(generator);
        double z1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerZXZ(z0Angle, xAngle, z1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerZXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), xAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), z1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXZ);
        
        firstMatrix.MakeEulerZXZ(z0Angle + z1Angle, DoubleMath::GetPI(), z1Angle);
        
        firstEuler = firstMatrix.ExtractEulerZXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXZ);
        
        firstMatrix.MakeEulerZXZ(z0Angle - z1Angle, 0.0, z1Angle);
        
        firstEuler = firstMatrix.ExtractEulerZXZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetX0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZXZ);
    }
}

void Mathematics::EulerTesting
    ::EulerZYZTest()
{
	default_random_engine generator{};
	uniform_real<double> firstAngleDistribution{ -DoubleMath::GetPI(),DoubleMath::GetPI() };
	uniform_real<double> secondAngleDistribution{ 0,DoubleMath::GetPI() };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        double z0Angle = firstAngleDistribution(generator);
        double yAngle = secondAngleDistribution(generator);
        double z1Angle = firstAngleDistribution(generator);
        
        DoubleMatrix3 firstMatrix;
        
        firstMatrix.MakeEulerZYZ(z0Angle, yAngle, z1Angle);
        
        DoubleEuler firstEuler = firstMatrix.ExtractEulerZYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), yAngle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), z1Angle,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Unique);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYZ);
        
        firstMatrix.MakeEulerZYZ(z0Angle + z1Angle, DoubleMath::GetPI(), z1Angle);
        
        firstEuler = firstMatrix.ExtractEulerZYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), DoubleMath::GetPI(),1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Difference);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYZ);
        
        firstMatrix.MakeEulerZYZ(z0Angle - z1Angle, 0.0, z1Angle);
        
        firstEuler = firstMatrix.ExtractEulerZYZ();
        
        ASSERT_APPROXIMATE(firstEuler.GetZ0Angle(), z0Angle,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetY0Angle(), 0.0,1e-10);
        ASSERT_APPROXIMATE(firstEuler.GetZ1Angle(), 0.0,1e-10);
		ASSERT_ENUM_EQUAL(firstEuler.GetType(),ExtractEulerResultType::Sum);
		ASSERT_ENUM_EQUAL(firstEuler.GetOrder(),ExtractEulerResultOrder::ZYZ);
    }
}