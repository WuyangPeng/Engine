/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/23 09:54)

#include "ProjectionMatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTest.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

Rendering::ProjectionMatrixTesting::ProjectionMatrixTesting(const OStreamShared& stream)
    : ParentType{ stream },
      matrixApproximateFunction{ Mathematics::Approximate<float> },
      viewVolumeTool{ GetEngineRandomSeed() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ProjectionMatrixTesting)

void Rendering::ProjectionMatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ProjectionMatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(DepthTypeTest, DepthType::ZeroToOne);
    ASSERT_NOT_THROW_EXCEPTION_1(DepthTypeTest, DepthType::MinusOneToOne);

    ASSERT_NOT_THROW_EXCEPTION_2(DefaultTest, false, DepthType::ZeroToOne);
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultTest, true, DepthType::ZeroToOne);
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultTest, false, DepthType::MinusOneToOne);
    ASSERT_NOT_THROW_EXCEPTION_2(DefaultTest, true, DepthType::MinusOneToOne);

    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFrustumTest, false, DepthType::ZeroToOne, &ClassType::ZeroToOneNoPerspectiveFrustumTest);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFrustumTest, true, DepthType::ZeroToOne, &ClassType::ZeroToOnePerspectiveFrustumTest);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFrustumTest, false, DepthType::MinusOneToOne, &ClassType::MinusOneToOneNoPerspectiveFrustumTest);
    ASSERT_NOT_THROW_EXCEPTION_3(DefaultFrustumTest, true, DepthType::MinusOneToOne, &ClassType::MinusOneToOnePerspectiveFrustumTest);

    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ZeroToOnePerspectiveTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ZeroToOneNoPerspectiveTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MinusOneToOnePerspectiveTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MinusOneToOneNoPerspectiveTest);
}

void Rendering::ProjectionMatrixTesting::DepthTypeTest(DepthType depthType)
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, depthType, epsilon);

    ASSERT_EQUAL(viewVolume->GetDepthType(), depthType);
}

void Rendering::ProjectionMatrixTesting::DefaultTest(bool isPerspective, DepthType depthType)
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(isPerspective, depthType, epsilon);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, viewVolume->GetProjectionViewMatrix(), viewVolume->GetProjectionMatrix() * viewVolume->GetViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, viewVolume->GetProjectionViewMatrix(), viewVolume->GetViewMatrix() * viewVolume->GetProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

void Rendering::ProjectionMatrixTesting::DefaultFrustumTest(bool isPerspective, DepthType depthType, FrustumTestNotNullFunction frustumTestFunction)
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(isPerspective, depthType, epsilon);

    const auto projectionViewMatrix = viewVolume->GetProjectionMatrix();

    const auto frustum = GetFrustum(90.0f, 1.0f, 1.0f, 10000.0f);

    (this->*frustumTestFunction)(projectionViewMatrix, frustum, epsilon);
}

void Rendering::ProjectionMatrixTesting::SetFrustumTest(bool isPerspective, DepthType depthType, FrustumTestNotNullFunction frustumTestFunction)
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(isPerspective, depthType, epsilon);

    const auto upFieldOfViewDegrees = 90.0f * viewVolumeTool.GetRandomProportion();
    const auto aspectRatio = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMin = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMax = 10000.0f * viewVolumeTool.GetRandomProportion();

    viewVolume->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    const auto projectionViewMatrix = viewVolume->GetProjectionMatrix();

    const auto frustum = GetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    (this->*frustumTestFunction)(projectionViewMatrix, frustum, epsilon);
}

bool Rendering::ProjectionMatrixTesting::ZeroToOnePerspectiveTest()
{
    ASSERT_NOT_THROW_EXCEPTION_3(SetFrustumTest, true, DepthType::ZeroToOne, &ClassType::ZeroToOnePerspectiveFrustumTest);

    return true;
}

bool Rendering::ProjectionMatrixTesting::ZeroToOneNoPerspectiveTest()
{
    ASSERT_NOT_THROW_EXCEPTION_3(SetFrustumTest, false, DepthType::ZeroToOne, &ClassType::ZeroToOneNoPerspectiveFrustumTest);

    return true;
}

bool Rendering::ProjectionMatrixTesting::MinusOneToOnePerspectiveTest()
{
    ASSERT_NOT_THROW_EXCEPTION_3(SetFrustumTest, true, DepthType::MinusOneToOne, &ClassType::MinusOneToOnePerspectiveFrustumTest);

    return true;
}

bool Rendering::ProjectionMatrixTesting::MinusOneToOneNoPerspectiveTest()
{
    ASSERT_NOT_THROW_EXCEPTION_3(SetFrustumTest, false, DepthType::MinusOneToOne, &ClassType::MinusOneToOneNoPerspectiveFrustumTest);

    return true;
}

void Rendering::ProjectionMatrixTesting::ZeroToOnePerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon)
{
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(0) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(0) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), -frustum.at(0) * frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), 1.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 0.0f, epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(0) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(0) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), -frustum.at(0) * frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), 1.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 0.0f, epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

void Rendering::ProjectionMatrixTesting::ZeroToOneNoPerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon)
{
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), -frustum.at(0) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 1.0f, epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), -frustum.at(0) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 1.0f, epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

void Rendering::ProjectionMatrixTesting::MinusOneToOnePerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon)
{
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(0) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(0) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), (frustum.at(0) + frustum.at(1)) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), -2.0f * frustum.at(0) * frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), 1.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 0.0f, epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(0) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(0) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), (frustum.at(0) + frustum.at(1)) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), -2.0f * frustum.at(0) * frustum.at(1) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), 1.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 0.0f, epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

void Rendering::ProjectionMatrixTesting::MinusOneToOneNoPerspectiveFrustumTest(const Matrix& projectionViewMatrix, const Container& frustum, float epsilon)
{
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), 2.0f * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), -(frustum.at(0) + frustum.at(1)) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 1.0f, epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE(projectionViewMatrix(0, 0), 2.0f * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 0), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 0), -(frustum.at(4) + frustum.at(5)) * frustum.at(8), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 1), 2.0f * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 1), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 1), -(frustum.at(2) + frustum.at(3)) * frustum.at(7), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 2), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 2), 2.0f * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 2), -(frustum.at(0) + frustum.at(1)) * frustum.at(6), epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(0, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(1, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(2, 3), 0.0f, epsilon);
    ASSERT_APPROXIMATE(projectionViewMatrix(3, 3), 1.0f, epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}
