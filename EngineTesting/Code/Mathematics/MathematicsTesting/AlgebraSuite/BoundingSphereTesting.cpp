/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/06 09:31)

#include "BoundingSphereTesting.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

Mathematics::BoundingSphereTesting::BoundingSphereTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared },
      transformTool{ GetEngineRandomSeed() },

      aPointFApproximateFunction{ Mathematics::Approximate<float> },
      boundingSphereFApproximateFunction{ Mathematics::Approximate<float> },

      aPointDApproximateFunction{ Mathematics::Approximate<double> },
      boundingSphereDApproximateFunction{ Mathematics::Approximate<double> }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, BoundingSphereTesting)

void Mathematics::BoundingSphereTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::BoundingSphereTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ModifyTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(InsideTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(NegativeSideTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(PositiveSideTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(GrowToContainTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(TransformByTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ComputeFromAPointTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ComputeFromVector3Test);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ComputeFromDataTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(LineIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(LineNonIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RayIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RayNonIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SegmentIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SegmentNonIntersectionTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(BoundingSphereStaticTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(BoundingSphereVelocityTest);
}

void Mathematics::BoundingSphereTesting::DefaultTest()
{
    constexpr auto epsilon0 = 1e-4f;
    constexpr BoundingSphereF boundingSphere0{};

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, boundingSphere0.GetCenter(), APointF::GetOrigin(), epsilon0);
    ASSERT_APPROXIMATE(boundingSphere0.GetRadius(), 0.0f, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    constexpr BoundingSphereD boundingSphere1{};

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, boundingSphere1.GetCenter(), APointD::GetOrigin(), epsilon1);
    ASSERT_APPROXIMATE(boundingSphere1.GetRadius(), 0.0, epsilon1);
}

bool Mathematics::BoundingSphereTesting::ModifyTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center01 = transformTool.ComputePositionF();
    const auto radius01 = transformTool.GetRadiusF();
    BoundingSphereF boundingSphere0{ center01, radius01 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, boundingSphere0.GetCenter(), center01, epsilon0);
    ASSERT_APPROXIMATE(boundingSphere0.GetRadius(), radius01, epsilon0);

    const auto center02 = transformTool.ComputePositionF();
    boundingSphere0.SetCenter(center02);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, boundingSphere0.GetCenter(), center02, epsilon0);
    ASSERT_APPROXIMATE(boundingSphere0.GetRadius(), radius01, epsilon0);

    const auto radius02 = transformTool.GetRadiusF();
    boundingSphere0.SetRadius(radius02);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, boundingSphere0.GetCenter(), center02, epsilon0);
    ASSERT_APPROXIMATE(boundingSphere0.GetRadius(), radius02, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto center11 = transformTool.ComputePositionD();
    const auto radius11 = transformTool.GetRadiusD();
    BoundingSphereD boundingSphere1{ center11, radius11 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, boundingSphere1.GetCenter(), center11, epsilon1);
    ASSERT_APPROXIMATE(boundingSphere1.GetRadius(), radius11, epsilon1);

    const auto center12 = transformTool.ComputePositionD();
    boundingSphere1.SetCenter(center12);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, boundingSphere1.GetCenter(), center12, epsilon1);
    ASSERT_APPROXIMATE(boundingSphere1.GetRadius(), radius11, epsilon1);

    const auto radius12 = transformTool.GetRadiusD();
    boundingSphere1.SetRadius(radius12);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, boundingSphere1.GetCenter(), center12, epsilon1);
    ASSERT_APPROXIMATE(boundingSphere1.GetRadius(), radius12, epsilon1);

    return true;
}

bool Mathematics::BoundingSphereTesting::InsideTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center0 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center0, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const PlaneF plane00{ normal0, center0 };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane00, epsilon0), NumericalValueSymbol::Zero);

    const PlaneF plane01{ normal0, center0 + normal0 * radius0 };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane01, epsilon0), NumericalValueSymbol::Zero);

    const PlaneF plane02{ normal0, center0 + normal0 * transformTool.GetRandom(radius0) };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane02, epsilon0), NumericalValueSymbol::Zero);

    const PlaneF plane03{ normal0, center0 - normal0 * radius0 };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane03, epsilon0), NumericalValueSymbol::Zero);

    const PlaneF plane04{ normal0, center0 - normal0 * transformTool.GetRandom(radius0) };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane04, epsilon0), NumericalValueSymbol::Zero);

    constexpr auto epsilon1 = 1e-6;
    const auto center1 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center1, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const PlaneD plane10{ normal1, center1 };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane10, epsilon1), NumericalValueSymbol::Zero);

    const PlaneD plane11{ normal1, center1 + normal1 * radius1 };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane11, epsilon1), NumericalValueSymbol::Zero);

    const PlaneD plane12{ normal1, center1 + normal1 * transformTool.GetRandom(radius1) };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane12, epsilon1), NumericalValueSymbol::Zero);

    const PlaneD plane13{ normal1, center1 - normal1 * radius1 };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane13, epsilon1), NumericalValueSymbol::Zero);

    const PlaneD plane14{ normal1, center1 - normal1 * transformTool.GetRandom(radius1) };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane14, epsilon1), NumericalValueSymbol::Zero);

    return true;
}

bool Mathematics::BoundingSphereTesting::NegativeSideTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center0 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center0, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const PlaneF plane02{ normal0, center0 + normal0 * (radius0 + transformTool.GetRandom(radius0)) };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane02, epsilon0), NumericalValueSymbol::Negative);

    constexpr auto epsilon1 = 1e-6;
    const auto center1 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center1, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const PlaneD plane12{ normal1, center1 + normal1 * (radius1 + transformTool.GetRandom(radius1)) };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane12, epsilon1), NumericalValueSymbol::Negative);

    return true;
}

bool Mathematics::BoundingSphereTesting::PositiveSideTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center0 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center0, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const PlaneF plane02{ normal0, center0 - normal0 * (radius0 + transformTool.GetRandom(radius0)) };

    ASSERT_EQUAL(boundingSphere0.WhichSide(plane02, epsilon0), NumericalValueSymbol::Positive);

    constexpr auto epsilon1 = 1e-6;
    const auto center1 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center1, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const PlaneD plane12{ normal1, center1 - normal1 * (radius1 + transformTool.GetRandom(radius1)) };

    ASSERT_EQUAL(boundingSphere1.WhichSide(plane12, epsilon1), NumericalValueSymbol::Positive);

    return true;
}

bool Mathematics::BoundingSphereTesting::GrowToContainTest()
{
    const auto center01 = transformTool.ComputePositionF();
    const auto radius01 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere01{ center01, radius01 };

    const auto center02 = transformTool.ComputePositionF();
    const auto radius02 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere02{ center02, radius02 };

    auto boundingSphere03 = boundingSphere01;
    boundingSphere03.GrowToContain(boundingSphere02);

    ASSERT_TRUE(TestIntersection(boundingSphere03, boundingSphere01));
    ASSERT_TRUE(TestIntersection(boundingSphere03, boundingSphere02));

    const auto center11 = transformTool.ComputePositionD();
    const auto radius11 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere11{ center11, radius11 };

    const auto center12 = transformTool.ComputePositionD();
    const auto radius12 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere12{ center12, radius12 };

    auto boundingSphere13 = boundingSphere11;
    boundingSphere13.GrowToContain(boundingSphere12);

    ASSERT_TRUE(TestIntersection(boundingSphere13, boundingSphere11));
    ASSERT_TRUE(TestIntersection(boundingSphere13, boundingSphere12));

    return true;
}

bool Mathematics::BoundingSphereTesting::TransformByTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center01 = transformTool.ComputePositionF();
    const auto radius01 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere01{ center01, radius01 };

    const auto transform0 = transformTool.ComputeTransformF(epsilon0);

    const auto boundingSphere02 = boundingSphere01.TransformBy(transform0);
    const auto center02 = transform0 * center01;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, boundingSphere02.GetCenter(), center02, epsilon0);
    ASSERT_APPROXIMATE(boundingSphere02.GetRadius(), radius01 * transform0.GetNorm(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto center11 = transformTool.ComputePositionD();
    const auto radius11 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere11{ center11, radius11 };

    const auto transform1 = transformTool.ComputeTransformD(epsilon1);

    const auto boundingSphere12 = boundingSphere11.TransformBy(transform1);
    const auto center12 = transform1 * center11;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, boundingSphere12.GetCenter(), center12, epsilon1);
    ASSERT_APPROXIMATE(boundingSphere12.GetRadius(), radius11 * transform1.GetNorm(), epsilon1);

    return true;
}

bool Mathematics::BoundingSphereTesting::ComputeFromAPointTest()
{
    BoundingSphereF boundingSphere0{};

    BoundingSphereF::APointContainer point0{};

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        point0.emplace_back(transformTool.ComputePositionF());
    }

    boundingSphere0.ComputeFromData(point0);

    for (const auto& element : point0)
    {
        constexpr auto epsilon0 = 1e-4f;

        const auto difference = boundingSphere0.GetCenter() - element;

        ASSERT_TRUE(difference.Length() <= boundingSphere0.GetRadius() + epsilon0);
    }

    BoundingSphereD boundingSphere1{};

    BoundingSphereD::APointContainer point1{};

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        point1.emplace_back(transformTool.ComputePositionD());
    }

    boundingSphere1.ComputeFromData(point1);

    for (const auto& element : point1)
    {
        constexpr auto epsilon1 = 1e-6;

        const auto difference = boundingSphere1.GetCenter() - element;

        ASSERT_TRUE(difference.Length() <= boundingSphere1.GetRadius() + epsilon1);
    }

    return true;
}

bool Mathematics::BoundingSphereTesting::ComputeFromVector3Test()
{
    BoundingSphereF boundingSphere0{};

    BoundingSphereF::Vector3Container point0{};

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        point0.emplace_back(transformTool.ComputePositionF().GetVector3());
    }

    boundingSphere0.ComputeFromData(point0);

    for (const auto& element : point0)
    {
        constexpr auto epsilon0 = 1e-4f;

        const auto difference = boundingSphere0.GetCenter().GetVector3() - element;

        ASSERT_TRUE(Vector3ToolsF::GetLength(difference) <= boundingSphere0.GetRadius() + epsilon0);
    }

    BoundingSphereD boundingSphere1{};

    BoundingSphereD::Vector3Container point1{};

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        point1.emplace_back(transformTool.ComputePositionD().GetVector3());
    }

    boundingSphere1.ComputeFromData(point1);

    for (const auto& element : point1)
    {
        constexpr auto epsilon1 = 1e-6;

        const auto difference = boundingSphere1.GetCenter().GetVector3() - element;

        ASSERT_TRUE(Vector3ToolsD::GetLength(difference) <= boundingSphere1.GetRadius() + epsilon1);
    }

    return true;
}

bool Mathematics::BoundingSphereTesting::ComputeFromDataTest()
{
    const auto count = GetTestLoopCount();

    BoundingSphereF boundingSphere0{};

    BoundingSphereF::PixelType pixel0{};
    BoundingSphereF::APointContainer point0{};

    for (auto i = 0; i < count; ++i)
    {
        const auto position = transformTool.ComputePositionF();
        point0.emplace_back(position);

        for (auto positionIndex = 0; positionIndex < APointF::pointSize; ++positionIndex)
        {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

            const auto* ptr = reinterpret_cast<const char*>(&position[positionIndex]);

            for (auto ptrIndex = 0; ptrIndex < CoreTools::GetStreamSize<float>(); ++ptrIndex)
            {
                pixel0.emplace_back(ptr[ptrIndex]);
            }

#include SYSTEM_WARNING_POP
        }
    }

    const BoundingSphereF::SpanConstIterator spanConstIterator0{ pixel0.begin(), pixel0.end() };

    boundingSphere0.ComputeFromData(count, CoreTools::GetStreamSize<float>() * APointF::pointSize, spanConstIterator0);

    for (const auto& element : point0)
    {
        constexpr auto epsilon0 = 1e-4f;

        const auto difference = boundingSphere0.GetCenter() - element;

        ASSERT_TRUE(difference.Length() <= boundingSphere0.GetRadius() + epsilon0);
    }

    BoundingSphereD boundingSphere1{};

    BoundingSphereD::PixelType pixel1{};
    BoundingSphereD::APointContainer point1{};

    for (auto i = 0; i < count; ++i)
    {
        const auto position = transformTool.ComputePositionD();
        point1.emplace_back(position);

        for (auto positionIndex = 0; positionIndex < APointD::pointSize; ++positionIndex)
        {
#include SYSTEM_WARNING_PUSH

#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

            const auto* ptr = reinterpret_cast<const char*>(&position[positionIndex]);

            for (auto ptrIndex = 0; ptrIndex < CoreTools::GetStreamSize<double>(); ++ptrIndex)
            {
                pixel1.emplace_back(ptr[ptrIndex]);
            }

#include SYSTEM_WARNING_POP
        }
    }

    const BoundingSphereD::SpanConstIterator spanConstIterator1{ pixel1.begin(), pixel1.end() };

    boundingSphere1.ComputeFromData(count, CoreTools::GetStreamSize<double>() * APointF::pointSize, spanConstIterator1);

    for (const auto& element : point1)
    {
        constexpr auto epsilon1 = 1e-4f;

        const auto difference = boundingSphere1.GetCenter() - element;

        ASSERT_TRUE(difference.Length() <= boundingSphere1.GetRadius() + epsilon1);
    }

    return true;
}

bool Mathematics::BoundingSphereTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center01 = transformTool.ComputePositionF();
    const auto radius01 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere00{ center01, radius01 };

    const auto bufferSize0 = boundingSphere00.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    boundingSphere00.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    BoundingSphereF boundingSphere01{};
    boundingSphere01.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(boundingSphereFApproximateFunction, boundingSphere00, boundingSphere01, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto center11 = transformTool.ComputePositionD();
    const auto radius11 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere10{ center11, radius11 };

    const auto bufferSize1 = boundingSphere10.GetStreamingSize();

    const auto objectRegister1 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget1{ bufferSize1, objectRegister1 };

    boundingSphere10.WriteAggregate(bufferTarget1);

    CoreTools::BufferSource bufferSource1{ bufferTarget1.GetFileBuffer() };

    BoundingSphereD boundingSphere11{};
    boundingSphere11.ReadAggregate(bufferSource1);
    ASSERT_APPROXIMATE_USE_FUNCTION(boundingSphereDApproximateFunction, boundingSphere10, boundingSphere11, epsilon1);

    return true;
}

bool Mathematics::BoundingSphereTesting::LineIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * transformTool.GetRandom(radius0);
    const auto center01 = transformTool.ComputePositionF();

    const auto vector0 = center01 - point0;

    ASSERT_TRUE(boundingSphere0.TestIntersection(point0, vector0, -MathF::maxReal, MathF::maxReal));
    ASSERT_TRUE(boundingSphere0.TestIntersection(point0, -vector0, -MathF::maxReal, MathF::maxReal));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * transformTool.GetRandom(radius1);
    const auto center11 = transformTool.ComputePositionD();

    const auto vector1 = center11 - point1;

    ASSERT_TRUE(boundingSphere1.TestIntersection(point1, vector1, -MathD::maxReal, MathD::maxReal));
    ASSERT_TRUE(boundingSphere1.TestIntersection(point1, -vector1, -MathD::maxReal, MathD::maxReal));

    return true;
}

bool Mathematics::BoundingSphereTesting::LineNonIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * (radius0 + transformTool.GetRandom(radius0));
    const auto basis0 = GenerateOrthonormalBasis(normal0);

    ASSERT_FALSE(boundingSphere0.TestIntersection(point0, basis0.GetUVector(), -MathF::maxReal, MathF::maxReal));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * (radius1 + transformTool.GetRandom(radius1));
    const auto basis1 = GenerateOrthonormalBasis(normal1);

    ASSERT_FALSE(boundingSphere1.TestIntersection(point1, basis1.GetUVector(), -MathD::maxReal, MathD::maxReal));

    return true;
}

bool Mathematics::BoundingSphereTesting::RayIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * transformTool.GetRandom(radius0);
    const auto center01 = transformTool.ComputePositionF();

    const auto vector0 = center01 - point0;

    ASSERT_TRUE(boundingSphere0.TestIntersection(point0, vector0, 0.0f, MathF::maxReal));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * transformTool.GetRandom(radius1);
    const auto center11 = transformTool.ComputePositionD();

    const auto vector1 = center11 - point1;

    ASSERT_TRUE(boundingSphere1.TestIntersection(point1, vector1, 0.0, MathD::maxReal));

    return true;
}

bool Mathematics::BoundingSphereTesting::RayNonIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * (radius0 + transformTool.GetRandom(radius0));
    const auto basis0 = GenerateOrthonormalBasis(normal0);

    ASSERT_FALSE(boundingSphere0.TestIntersection(point0, basis0.GetUVector(), 0.0f, MathF::maxReal));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * (radius1 + transformTool.GetRandom(radius1));
    const auto basis1 = GenerateOrthonormalBasis(normal1);

    ASSERT_FALSE(boundingSphere1.TestIntersection(point1, basis1.GetUVector(), 0.0, MathD::maxReal));

    return true;
}

bool Mathematics::BoundingSphereTesting::SegmentIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * transformTool.GetRandom(radius0);
    const auto center01 = transformTool.ComputePositionF();

    const auto vector0 = center01 - point0;

    ASSERT_TRUE(boundingSphere0.TestIntersection(point0, vector0, 0.0f, radius0));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * transformTool.GetRandom(radius1);
    const auto center11 = transformTool.ComputePositionD();

    const auto vector1 = center11 - point1;

    ASSERT_TRUE(boundingSphere1.TestIntersection(point1, vector1, 0.0, radius1));

    return true;
}

bool Mathematics::BoundingSphereTesting::SegmentNonIntersectionTest()
{
    const auto center00 = transformTool.ComputePositionF();
    const auto radius0 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere0{ center00, radius0 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto point0 = center00 + normal0 * (radius0 + transformTool.GetRandom(radius0));
    const auto basis0 = GenerateOrthonormalBasis(normal0);

    ASSERT_FALSE(boundingSphere0.TestIntersection(point0, basis0.GetUVector(), 0.0f, radius0));

    const auto center10 = transformTool.ComputePositionD();
    const auto radius1 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere1{ center10, radius1 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto point1 = center10 + normal1 * (radius1 + transformTool.GetRandom(radius1));
    const auto basis1 = GenerateOrthonormalBasis(normal1);

    ASSERT_FALSE(boundingSphere1.TestIntersection(point1, basis1.GetUVector(), 0.0, radius1));

    return true;
}

bool Mathematics::BoundingSphereTesting::BoundingSphereStaticTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center00 = transformTool.ComputePositionF();
    const auto radius00 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere00{ center00, radius00 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto radius01 = transformTool.GetRadiusF();
    const auto center01 = center00 + normal0 * (radius00 + radius01);

    const BoundingSphereF boundingSphere01{ center01, radius01 + epsilon0 };

    ASSERT_TRUE(TestIntersection(boundingSphere00, boundingSphere01, epsilon0));

    const BoundingSphereF boundingSphere02{ center01, radius01 - epsilon0 };

    ASSERT_FALSE(TestIntersection(boundingSphere00, boundingSphere02, epsilon0));

    constexpr auto epsilon1 = 1e-6;
    const auto center10 = transformTool.ComputePositionD();
    const auto radius10 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere10{ center10, radius10 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto radius11 = transformTool.GetRadiusD();
    const auto center11 = center10 + normal1 * (radius10 + radius11);

    const BoundingSphereD boundingSphere11{ center11, radius11 + epsilon1 };

    ASSERT_TRUE(TestIntersection(boundingSphere10, boundingSphere11, epsilon1));

    const BoundingSphereD boundingSphere12{ center11, radius11 - epsilon1 };

    ASSERT_FALSE(TestIntersection(boundingSphere10, boundingSphere12, epsilon1));

    return true;
}

bool Mathematics::BoundingSphereTesting::BoundingSphereVelocityTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto center00 = transformTool.ComputePositionF();
    const auto radius00 = transformTool.GetRadiusF();
    const BoundingSphereF boundingSphere00{ center00, radius00 };

    auto normal0 = transformTool.ComputeVectorF();
    normal0.Normalize();

    const auto radius01 = transformTool.GetRadiusF();
    const auto center01 = center00 + normal0 * (radius00 + radius01);

    const BoundingSphereF boundingSphere01{ center01, radius01 - epsilon0 };

    ASSERT_FALSE(TestIntersection(boundingSphere00, -normal0, boundingSphere01, normal0, radius00));
    ASSERT_TRUE(TestIntersection(boundingSphere00, normal0, boundingSphere01, -normal0, radius00));

    constexpr auto epsilon1 = 1e-6;
    const auto center10 = transformTool.ComputePositionD();
    const auto radius10 = transformTool.GetRadiusD();
    const BoundingSphereD boundingSphere10{ center10, radius10 };

    auto normal1 = transformTool.ComputeVectorD();
    normal1.Normalize();

    const auto radius11 = transformTool.GetRadiusD();
    const auto center11 = center10 + normal1 * (radius10 + radius11);

    const BoundingSphereD boundingSphere11{ center11, radius11 - epsilon1 };

    ASSERT_FALSE(TestIntersection(boundingSphere10, -normal1, boundingSphere11, normal1, epsilon1));
    ASSERT_TRUE(TestIntersection(boundingSphere10, normal1, boundingSphere11, -normal1, epsilon1));

    return true;
}
