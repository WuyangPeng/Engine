/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/02 17:32)

#include "TranslateTransformTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/Flags/ExtractEulerResultType.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class Transform<float>;
    template class Transform<double>;
}

Mathematics::TranslateTransformTesting::TranslateTransformTesting(const OStreamShared& streamShared)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, TranslateTransformTesting)

void Mathematics::TranslateTransformTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::TranslateTransformTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PromptTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RotateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NormTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MultiplicationTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(InverseTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetTranslateTest);
}

void Mathematics::TranslateTransformTesting::PromptTest()
{
    const auto transform0 = transformTool.ComputeTranslateTransformF();

    ASSERT_FALSE(transform0.IsIdentity());
    ASSERT_TRUE(transform0.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform0.IsUniformScale());

    const auto transform1 = transformTool.ComputeTranslateTransformD();

    ASSERT_FALSE(transform1.IsIdentity());
    ASSERT_TRUE(transform1.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform1.IsUniformScale());
}

bool Mathematics::TranslateTransformTesting::RotateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto point0 = transformTool.ComputePositionF();
    TransformF transform0{};
    transform0.SetTranslate(point0);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetRotate(), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetMatrix(), MatrixF::GetIdentityMatrix(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetTranslate(), point0, epsilon0);
    const Vector4F translation00{ point0.GetX(), point0.GetY(), point0.GetZ(), 0.0f };
    const Vector4F translation01{ point0.GetX(), point0.GetY(), point0.GetZ(), 1.0f };
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW0(), translation00, epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW1(), translation01, epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), APointF::GetUnit(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetScaleW1(), Vector4F::GetOne(), epsilon0);
    ASSERT_APPROXIMATE(transform0.GetUniformScale(), MathF::GetValue(1), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto point1 = transformTool.ComputePositionD();
    TransformD transform1{};
    transform1.SetTranslate(point1);

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetRotate(), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetMatrix(), MatrixD::GetIdentityMatrix(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetTranslate(), point1, epsilon1);
    const Vector4D translation10{ point1.GetX(), point1.GetY(), point1.GetZ(), 0.0 };
    const Vector4D translation11{ point1.GetX(), point1.GetY(), point1.GetZ(), 1.0 };
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW0(), translation10, epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW1(), translation11, epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), APointD::GetUnit(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetScaleW1(), Vector4D::GetOne(), epsilon1);
    ASSERT_APPROXIMATE(transform0.GetUniformScale(), MathD::GetValue(1), epsilon1);

    return true;
}

void Mathematics::TranslateTransformTesting::ConvertTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto transform0 = transformTool.ComputeTranslateTransformF();

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3FApproximateFunction, transform0.GetRotationMatrix3(), Matrix3F::GetIdentity(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(aQuaternionFApproximateFunction, transform0.GetRotationQuaternion(), AQuaternionF::GetIdentity(), epsilon0);

    const auto axisAngle0 = transform0.GetRotationAxisAngle();
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, axisAngle0.GetAxis(), Vector3F::GetUnitX(), epsilon0);
    ASSERT_APPROXIMATE(axisAngle0.GetAngle(), 0.0f, epsilon0);

    const auto euler0 = transform0.GetRotationEuler(ExtractEulerResultOrder::XYZ);
    ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0f, epsilon0);
    ASSERT_APPROXIMATE(euler0.GetX1Angle(), 0.0f, epsilon0);
    ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0f, epsilon0);
    ASSERT_APPROXIMATE(euler0.GetY1Angle(), 0.0f, epsilon0);
    ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0f, epsilon0);
    ASSERT_APPROXIMATE(euler0.GetZ1Angle(), 0.0f, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto transform1 = transformTool.ComputeTranslateTransformD();

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3DApproximateFunction, transform1.GetRotationMatrix3(), Matrix3D::GetIdentity(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(aQuaternionDApproximateFunction, transform1.GetRotationQuaternion(), AQuaternionD::GetIdentity(), epsilon1);

    const auto axisAngle1 = transform1.GetRotationAxisAngle();
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, axisAngle1.GetAxis(), Vector3D::GetUnitX(), epsilon1);
    ASSERT_APPROXIMATE(axisAngle1.GetAngle(), 0.0, epsilon1);

    const auto euler1 = transform1.GetRotationEuler(ExtractEulerResultOrder::XYZ);
    ASSERT_APPROXIMATE(euler1.GetX0Angle(), 0.0, epsilon1);
    ASSERT_APPROXIMATE(euler1.GetX1Angle(), 0.0, epsilon1);
    ASSERT_APPROXIMATE(euler1.GetY0Angle(), 0.0, epsilon1);
    ASSERT_APPROXIMATE(euler1.GetY1Angle(), 0.0, epsilon1);
    ASSERT_APPROXIMATE(euler1.GetZ0Angle(), 0.0, epsilon1);
    ASSERT_APPROXIMATE(euler1.GetZ1Angle(), 0.0, epsilon1);
}

void Mathematics::TranslateTransformTesting::NormTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto transform0 = transformTool.ComputeTranslateTransformF();

    ASSERT_APPROXIMATE(transform0.GetNorm(), 1.0f, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto transform1 = transformTool.ComputeTranslateTransformD();

    ASSERT_APPROXIMATE(transform1.GetNorm(), 1.0, epsilon1);
}

bool Mathematics::TranslateTransformTesting::MultiplicationTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto point0 = transformTool.ComputePositionF();
    TransformF transform0{};
    transform0.SetTranslate(point0);

    const auto position00 = transformTool.ComputePositionF();
    const auto position01 = transform0 * position00;
    const auto position02 = point0 + position00;

    ASSERT_APPROXIMATE(position01.GetX(), position02.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position01.GetY(), position02.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position01.GetZ(), position02.GetZ(), epsilon0);

    const auto vector00 = transformTool.ComputeVectorF();
    const auto vector01 = transform0 * vector00;

    ASSERT_APPROXIMATE(vector01.GetX(), vector00.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector01.GetY(), vector00.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector01.GetZ(), vector00.GetZ(), epsilon0);

    const auto transform1 = transformTool.ComputeRotationTransformF(epsilon0);
    auto transform2 = transform1 * transform0;

    transform2 *= transform0.GetInverseTransform(epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto point1 = transformTool.ComputePositionD();
    TransformD transform3{};
    transform3.SetTranslate(point1);

    const auto position10 = transformTool.ComputePositionD();
    const auto position11 = transform3 * position10;
    const auto position12 = point1 + position10;

    ASSERT_APPROXIMATE(position11.GetX(), position12.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position11.GetY(), position12.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position11.GetZ(), position12.GetZ(), epsilon0);

    const auto vector10 = transformTool.ComputeVectorD();
    const auto vector11 = transform3 * vector10;

    ASSERT_APPROXIMATE(vector11.GetX(), vector11.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector11.GetY(), vector11.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector11.GetZ(), vector11.GetZ(), epsilon0);

    const auto transform4 = transformTool.ComputeRotationTransformD(epsilon1);
    auto transform5 = transform4 * transform3;

    transform5 *= transform3.GetInverseTransform(epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon1);

    return true;
}

bool Mathematics::TranslateTransformTesting::InverseTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto transform0 = transformTool.ComputeTranslateTransformF();

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetHomogeneousMatrix() * transform0.GetInverseMatrix(epsilon0), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0 * transform0.GetInverseTransform(epsilon0), TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto transform1 = transformTool.ComputeTranslateTransformD();

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetHomogeneousMatrix() * transform1.GetInverseMatrix(epsilon1), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1 * transform1.GetInverseTransform(epsilon1), TransformD::GetIdentityTransform(), epsilon1);

    return true;
}

bool Mathematics::TranslateTransformTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto transform0 = transformTool.ComputeTranslateTransformF();

    const auto bufferSize0 = transform0.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    transform0.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    TransformF transform1{};
    transform1.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, transform1, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto transform2 = transformTool.ComputeTranslateTransformD();

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

bool Mathematics::TranslateTransformTesting::SetTranslateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto point0 = transformTool.ComputePositionF();
    TransformF transform0{};
    transform0.SetTranslate(point0.GetX(), point0.GetY(), point0.GetZ());

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, point0, transform0.GetTranslate(), epsilon0);

    transform0.SetTranslate(Vector3F{ point0.GetX(), point0.GetY(), point0.GetZ() });

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, point0, transform0.GetTranslate(), epsilon0);

    transform0.SetTranslate(Vector4F{ point0.GetX(), point0.GetY(), point0.GetZ(), 0.0f });

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, point0, transform0.GetTranslate(), epsilon0);

    constexpr auto epsilon1 = 1e-4f;
    const auto point1 = transformTool.ComputePositionD();
    TransformD transform1{};
    transform1.SetTranslate(point1.GetX(), point1.GetY(), point1.GetZ());

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, point1, transform1.GetTranslate(), epsilon1);

    transform1.SetTranslate(Vector3D{ point1.GetX(), point1.GetY(), point1.GetZ() });

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, point1, transform1.GetTranslate(), epsilon1);

    transform1.SetTranslate(Vector4D{ point1.GetX(), point1.GetY(), point1.GetZ(), 0.0 });

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, point1, transform1.GetTranslate(), epsilon1);

    return true;
}
