/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/02 16:38)

#include "MatrixTransformTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/Flags/EulerResultType.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class Transform<float>;
    template class Transform<double>;
}

Mathematics::MatrixTransformTesting::MatrixTransformTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared },
      transformTool{ GetEngineRandomSeed() },

      aPointFApproximateFunction{ Mathematics::Approximate<float> },
      aVectorFApproximateFunction{ Mathematics::Approximate<float> },
      matrixFApproximateFunction{ Mathematics::Approximate<float> },
      matrix3FApproximateFunction{ Mathematics::Approximate<float> },
      aQuaternionFApproximateFunction{ Mathematics::Approximate<float> },
      transformFApproximateFunction{ Mathematics::Approximate<float> },

      aPointDApproximateFunction{ Mathematics::Approximate<double> },
      aVectorDApproximateFunction{ Mathematics::Approximate<double> },
      matrixDApproximateFunction{ Mathematics::Approximate<double> },
      matrix3DApproximateFunction{ Mathematics::Approximate<double> },
      aQuaternionDApproximateFunction{ Mathematics::Approximate<double> },
      transformDApproximateFunction{ Mathematics::Approximate<double> }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MatrixTransformTesting)

void Mathematics::MatrixTransformTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MatrixTransformTesting::MainTest()
{
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(PromptTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RotateTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(NormTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MultiplicationTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(InverseTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
}

bool Mathematics::MatrixTransformTesting::PromptTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0{};
    transform0.SetMatrix(transformTool.ComputeMatrixF(epsilon0));

    ASSERT_FALSE(transform0.IsIdentity());
    ASSERT_FALSE(transform0.IsRotationOrScaleMatrix());
    ASSERT_FALSE(transform0.IsUniformScale());

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1{};
    transform1.SetMatrix(transformTool.ComputeMatrixD(epsilon1));

    ASSERT_FALSE(transform1.IsIdentity());
    ASSERT_FALSE(transform1.IsRotationOrScaleMatrix());
    ASSERT_FALSE(transform1.IsUniformScale());

    return true;
}

bool Mathematics::MatrixTransformTesting::RotateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0{};
    const auto rotate0 = transformTool.ComputeMatrixF(epsilon0);
    transform0.SetMatrix(rotate0);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetMatrix(), rotate0, epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetTranslate(), APointF::GetOrigin(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW0(), Vector4F::GetZero(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW1(), Vector4F::GetUnitW(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1{};
    const auto rotate1 = transformTool.ComputeMatrixD(epsilon0);
    transform1.SetMatrix(rotate1);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetMatrix(), rotate1, epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetTranslate(), APointD::GetOrigin(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW0(), Vector4D::GetZero(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW1(), Vector4D::GetUnitW(), epsilon1);

    return true;
}

bool Mathematics::MatrixTransformTesting::NormTest()
{
    constexpr auto epsilon0 = 1e-4f;

    TransformF transform0{};
    const auto rotate0 = transformTool.ComputeMatrixF(epsilon0);
    transform0.SetMatrix(rotate0);

    ASSERT_APPROXIMATE(transform0.GetNorm(), rotate0.GetNorm(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1{};
    const auto rotate1 = transformTool.ComputeMatrixD(epsilon1);
    transform1.SetMatrix(rotate1);

    ASSERT_APPROXIMATE(transform1.GetNorm(), rotate1.GetNorm(), epsilon1);

    return true;
}

bool Mathematics::MatrixTransformTesting::MultiplicationTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0{};
    const auto rotate0 = transformTool.ComputeMatrixF(epsilon0);
    transform0.SetMatrix(rotate0);

    const auto position00 = transformTool.ComputePositionF();
    const auto position01 = transform0 * position00;
    const auto position02 = rotate0 * position00;

    ASSERT_APPROXIMATE(position01.GetX(), position02.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position01.GetY(), position02.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position01.GetZ(), position02.GetZ(), epsilon0);

    const auto vector00 = transformTool.ComputeVectorF();
    const auto vector01 = transform0 * vector00;
    const auto vector02 = rotate0 * vector00;

    ASSERT_APPROXIMATE(vector01.GetX(), vector02.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector01.GetY(), vector02.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector01.GetZ(), vector02.GetZ(), epsilon0);

    const auto transform1 = transformTool.ComputeRotationTransformF(epsilon0);
    auto transform2 = transform1 * transform0;

    transform2 *= transform0.GetInverseTransform(epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform3{};
    const auto rotate1 = transformTool.ComputeMatrixD(epsilon0);
    transform3.SetMatrix(rotate1);

    const auto position10 = transformTool.ComputePositionD();
    const auto position11 = transform3 * position10;
    const auto position12 = rotate1 * position10;

    ASSERT_APPROXIMATE(position11.GetX(), position12.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position11.GetY(), position12.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position11.GetZ(), position12.GetZ(), epsilon0);

    const auto vector10 = transformTool.ComputeVectorD();
    const auto vector11 = transform3 * vector10;
    const auto vector12 = rotate1 * vector10;

    ASSERT_APPROXIMATE(vector11.GetX(), vector12.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector11.GetY(), vector12.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector11.GetZ(), vector12.GetZ(), epsilon0);

    const auto transform4 = transformTool.ComputeRotationTransformD(epsilon1);
    auto transform5 = transform4 * transform3;

    transform5 *= transform3.GetInverseTransform(epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon1);

    return true;
}

NODISCARD bool Mathematics::MatrixTransformTesting::InverseTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0{};
    const auto rotate0 = transformTool.ComputeMatrixF(epsilon0);
    transform0.SetMatrix(rotate0);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetHomogeneousMatrix() * transform0.GetInverseMatrix(epsilon0), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0 * transform0.GetInverseTransform(epsilon0), TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1{};
    const auto rotate1 = transformTool.ComputeMatrixD(epsilon0);
    transform1.SetMatrix(rotate1);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetHomogeneousMatrix() * transform1.GetInverseMatrix(epsilon1), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1 * transform1.GetInverseTransform(epsilon1), TransformD::GetIdentityTransform(), epsilon1);

    return true;
}

bool Mathematics::MatrixTransformTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0{};
    const auto rotate0 = transformTool.ComputeMatrixF(epsilon0);
    transform0.SetMatrix(rotate0);

    const auto bufferSize0 = transform0.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    transform0.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    TransformF transform1{};
    transform1.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, transform1, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform2{};
    const auto rotate1 = transformTool.ComputeMatrixD(epsilon0);
    transform2.SetMatrix(rotate1);

    const auto bufferSize1 = transform2.GetStreamingSize();

    const auto objectRegister1 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget1{ bufferSize1, objectRegister1 };

    transform2.WriteAggregate(bufferTarget1);

    CoreTools::BufferSource bufferSource1{ bufferTarget1.GetFileBuffer() };

    TransformD transform3{};
    transform3.ReadAggregate(bufferSource1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform2, transform3, epsilon1);

    return true;
}
