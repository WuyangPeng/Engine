/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 19:14)

#include "CameraTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferOutStream.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/PickLine.h"

Rendering::CameraTesting::CameraTesting(const OStreamShared& stream)
    : ParentType{ stream },
      viewVolumeTool{ GetEngineRandomSeed() },
      aPointApproximateFunction{ Mathematics::Approximate<float> },
      aVectorApproximateFunction{ Mathematics::Approximate<float> },
      matrixApproximateFunction{ Mathematics::Approximate<float> }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, CameraTesting)

void Rendering::CameraTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::CameraTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(DefaultMatrixTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(DefaultProjectionViewMatrixTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ProjectionViewMatrixTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetProjectionMatrixTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetPickLineTest);
}

bool Rendering::CameraTesting::DefaultMatrixTest()
{
    constexpr auto epsilon = 1e-4f;
    constexpr auto identityMatrix = Matrix::GetIdentityMatrix();
    const auto camera = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

    ASSERT_TRUE(camera->PreViewIsIdentity());
    ASSERT_TRUE(camera->PostProjectionIsIdentity());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPreViewMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPostProjectionMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());

    const auto matrix0 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPreViewMatrix(matrix0);

    ASSERT_FALSE(camera->PreViewIsIdentity());
    ASSERT_TRUE(camera->PostProjectionIsIdentity());

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPreViewMatrix(), matrix0, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPostProjectionMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());

    const auto matrix1 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPostProjectionMatrix(matrix1);

    ASSERT_FALSE(camera->PreViewIsIdentity());
    ASSERT_FALSE(camera->PostProjectionIsIdentity());

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPreViewMatrix(), matrix0, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPostProjectionMatrix(), matrix1, Mathematics::MathF::GetZeroTolerance());

    camera->SetPreViewMatrix(identityMatrix);

    ASSERT_TRUE(camera->PreViewIsIdentity());
    ASSERT_FALSE(camera->PostProjectionIsIdentity());

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPreViewMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPostProjectionMatrix(), matrix1, Mathematics::MathF::GetZeroTolerance());

    camera->SetPostProjectionMatrix(identityMatrix);

    ASSERT_TRUE(camera->PreViewIsIdentity());
    ASSERT_TRUE(camera->PostProjectionIsIdentity());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPreViewMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetPostProjectionMatrix(), identityMatrix, Mathematics::MathF::GetZeroTolerance());

    return true;
}

bool Rendering::CameraTesting::DefaultProjectionViewMatrixTest()
{
    constexpr auto epsilon = 1e-4f;
    constexpr auto identityMatrix = Matrix::GetIdentityMatrix();
    const auto camera = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    const auto matrix0 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPreViewMatrix(matrix0);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    const auto matrix1 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPostProjectionMatrix(matrix1);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    camera->SetPreViewMatrix(identityMatrix);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    camera->SetPostProjectionMatrix(identityMatrix);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return true;
}

bool Rendering::CameraTesting::ProjectionViewMatrixTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto camera = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto upFieldOfViewDegrees = 90.0f * viewVolumeTool.GetRandomProportion();
    const auto aspectRatio = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMin = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMax = 10000.0f * viewVolumeTool.GetRandomProportion();

    camera->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    const auto position = viewVolumeTool.ComputePosition();

    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetDirectionVector();
    const auto vector1 = viewVolumeTool.GetUpVector();
    const auto vector2 = viewVolumeTool.GetRightVector();

    camera->SetFrame(position, vector0, vector1, vector2);

    const auto matrix0 = viewVolumeTool.ComputeMatrix(epsilon);
    const auto matrix1 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPreViewMatrix(matrix0);
    camera->SetPostProjectionMatrix(matrix1);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return true;
}

bool Rendering::CameraTesting::SetProjectionMatrixTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto camera = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto matrix0 = viewVolumeTool.ComputeMatrix(epsilon);
    const auto matrix1 = viewVolumeTool.ComputeMatrix(epsilon);

    camera->SetPreViewMatrix(matrix0);
    camera->SetPostProjectionMatrix(matrix1);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * (camera->GetProjectionMatrix() * camera->GetViewMatrix()) * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * (camera->GetViewMatrix() * camera->GetProjectionMatrix()) * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    const auto point0 = viewVolumeTool.ComputePosition();
    const auto point1 = viewVolumeTool.ComputePosition();
    const auto point2 = viewVolumeTool.ComputePosition();
    const auto point3 = viewVolumeTool.ComputePosition();
    const auto nearExtrude = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto farExtrude = 10000.0f * viewVolumeTool.GetRandomProportion();

    camera->SetProjectionMatrix(point0, point1, point2, point3, nearExtrude, farExtrude);

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPostProjectionMatrix() * camera->GetProjectionMatrix() * camera->GetViewMatrix() * camera->GetPreViewMatrix(), epsilon);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera->GetProjectionViewMatrix(), camera->GetPreViewMatrix() * camera->GetViewMatrix() * camera->GetProjectionMatrix() * camera->GetPostProjectionMatrix(), epsilon);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return true;
}

void Rendering::CameraTesting::GetPickLineTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto camera = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto pickLine0 = camera->GetPickLine(0, 0, 1024, 768, 500, 500);

    ASSERT_TRUE(pickLine0.IsContain());

    const auto pickLine1 = camera->GetPickLine(0, 0, 1024, 768, 1500, 500);

    ASSERT_FALSE(pickLine1.IsContain());
}

bool Rendering::CameraTesting::StreamTest()
{
    constexpr auto epsilon = 1e-4f;
    const auto camera0 = Camera::Create(false, DepthType::MinusOneToOne, epsilon);

    const auto position = viewVolumeTool.ComputePosition();
    viewVolumeTool.ComputeAxes(epsilon);

    const auto vector0 = viewVolumeTool.GetDirectionVector();
    const auto vector1 = viewVolumeTool.GetUpVector();
    const auto vector2 = viewVolumeTool.GetRightVector();

    camera0->SetFrame(position, vector0, vector1, vector2);

    const auto upFieldOfViewDegrees = 90.0f * viewVolumeTool.GetRandomProportion();
    const auto aspectRatio = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMin = 1.0f * viewVolumeTool.GetRandomProportion();
    const auto directionMax = 10000.0f * viewVolumeTool.GetRandomProportion();

    camera0->SetFrustum(upFieldOfViewDegrees, aspectRatio, directionMin, directionMax);

    const auto matrix0 = viewVolumeTool.ComputeMatrix(epsilon);
    const auto matrix1 = viewVolumeTool.ComputeMatrix(epsilon);

    camera0->SetPreViewMatrix(matrix0);
    camera0->SetPostProjectionMatrix(matrix1);

    auto outTopLevel = CoreTools::OutTopLevel::Create();
    outTopLevel.Insert(camera0);

    const CoreTools::BufferOutStream bufferOutStream{ outTopLevel };
    const auto buffer = bufferOutStream.GetBufferOutStreamInformation();

    const CoreTools::BufferInStream bufferInStream{ buffer };

    const auto inTopLevel = bufferInStream.GetTopLevel();

    ASSERT_EQUAL_FAILURE_THROW(inTopLevel.GetTopLevelSize(), 1, "流读取失败。");

    const auto camera1 = boost::polymorphic_pointer_cast<Camera>(*inTopLevel.begin());

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointApproximateFunction, camera0->GetPosition(), camera1->GetPosition(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, camera0->GetDirectionVector(), camera1->GetDirectionVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, camera0->GetUpVector(), camera1->GetUpVector(), epsilon);
    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorApproximateFunction, camera0->GetRightVector(), camera1->GetRightVector(), epsilon);

    ASSERT_APPROXIMATE(camera0->GetDirectionMin(), camera1->GetDirectionMin(), epsilon);
    ASSERT_APPROXIMATE(camera0->GetDirectionMax(), camera1->GetDirectionMax(), epsilon);
    ASSERT_APPROXIMATE(camera0->GetUpMin(), camera1->GetUpMin(), epsilon);
    ASSERT_APPROXIMATE(camera0->GetUpMax(), camera1->GetUpMax(), epsilon);
    ASSERT_APPROXIMATE(camera0->GetRightMin(), camera1->GetRightMin(), epsilon);
    ASSERT_APPROXIMATE(camera0->GetRightMax(), camera1->GetRightMax(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera0->GetProjectionMatrix(), camera1->GetProjectionMatrix(), epsilon);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera0->GetPreViewMatrix(), camera1->GetPreViewMatrix(), Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixApproximateFunction, camera0->GetPostProjectionMatrix(), camera1->GetPostProjectionMatrix(), Mathematics::MathF::GetZeroTolerance());
    ASSERT_EQUAL(camera0->PreViewIsIdentity(), camera1->PreViewIsIdentity());
    ASSERT_EQUAL(camera0->PostProjectionIsIdentity(), camera1->PostProjectionIsIdentity());

    return true;
}
