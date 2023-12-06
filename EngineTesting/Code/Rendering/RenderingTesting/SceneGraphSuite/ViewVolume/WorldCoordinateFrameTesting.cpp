/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/23 09:18)

#include "WorldCoordinateFrameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTest.h"

Rendering::WorldCoordinateFrameTesting::WorldCoordinateFrameTesting(const OStreamShared& stream)
    : ParentType{ stream },
      aPointApproximateFunction{ Mathematics::Approximate<float> },
      aVectorApproximateFunction{ Mathematics::Approximate<float> },
      matrixApproximateFunction{ Mathematics::Approximate<float> },
      viewVolumeTool{ GetEngineRandomSeed() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, WorldCoordinateFrameTesting)

void Rendering::WorldCoordinateFrameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::WorldCoordinateFrameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(FetchTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetFrameTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MatrixTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(OrthonormalizeTest);
}

void Rendering::WorldCoordinateFrameTesting::DefaultTest()
{
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::ZeroToOne, Mathematics::MathF::GetZeroTolerance());

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, viewVolume->GetPosition(), APoint::GetOrigin(), Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetDirectionVector(), -AVector::GetUnitZ(), Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetUpVector(), AVector::GetUnitY(), Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetRightVector(), AVector::GetUnitX(), Mathematics::MathF::GetZeroTolerance());
}

bool Rendering::WorldCoordinateFrameTesting::FetchTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::ZeroToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();
    viewVolume->SetPosition(position);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, viewVolume->GetPosition(), position, epsilon);

    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetDirectionVector();
    const auto vector1 = viewVolumeTool.GetUpVector();
    const auto vector2 = viewVolumeTool.GetRightVector();

    viewVolume->SetAxes(vector0, vector1, vector2);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetDirectionVector(), vector0, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetUpVector(), vector1, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetRightVector(), vector2, epsilon);

    return true;
}

bool Rendering::WorldCoordinateFrameTesting::SetFrameTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::ZeroToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();

    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetDirectionVector();
    const auto vector1 = viewVolumeTool.GetUpVector();
    const auto vector2 = viewVolumeTool.GetRightVector();

    viewVolume->SetFrame(position, vector0, vector1, vector2);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, viewVolume->GetPosition(), position, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetDirectionVector(), vector0, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetUpVector(), vector1, epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, viewVolume->GetRightVector(), vector2, epsilon);

    return true;
}

bool Rendering::WorldCoordinateFrameTesting::MatrixTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::ZeroToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();

    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetVector();

    viewVolume->SetFrame(position, vector0.at(2), vector0.at(1), vector0.at(0));

    const auto viewMatrix = viewVolume->GetViewMatrix();
    const auto matrix = viewMatrix * viewVolume->GetInverseViewMatrix();

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, matrix, Matrix::GetIdentityMatrix(), epsilon);

    for (auto outerIndex = 0; outerIndex < AVector::vectorSize; ++outerIndex)
    {
#ifdef MATHEMATICS_USE_MATRIX_VECTOR

        const auto vector1 = viewMatrix.GetRow(outerIndex);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

        const auto vector1 = viewMatrix.GetColumn(outerIndex);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

        for (auto innerIndex = 0; innerIndex < AVector::vectorSize; ++innerIndex)
        {
            ASSERT_APPROXIMATE(vector1[innerIndex], vector0.at(outerIndex)[innerIndex], epsilon);
        }

        ASSERT_APPROXIMATE(vector1[AVector::vectorSize], -Dot(position, vector0.at(outerIndex)), epsilon);
    }

    return true;
}

bool Rendering::WorldCoordinateFrameTesting::OrthonormalizeTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto viewVolume = ViewVolumeTest::Create(false, DepthType::ZeroToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();

    const auto vector0 = viewVolumeTool.ComputeVector();
    const auto vector1 = viewVolumeTool.ComputeVector();
    const auto vector2 = viewVolumeTool.ComputeVector();

    viewVolume->SetFrame(position, vector0, vector1, vector2);

    const auto orthonormalize = Orthonormalize(vector0, vector1, vector2, epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, orthonormalize.GetUVector(), viewVolume->GetDirectionVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, orthonormalize.GetVVector(), viewVolume->GetUpVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, orthonormalize.GetWVector(), viewVolume->GetRightVector(), epsilon);

    return true;
}
