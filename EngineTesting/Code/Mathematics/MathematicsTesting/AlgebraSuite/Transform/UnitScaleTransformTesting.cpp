/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/01 13:42)

#include "UnitScaleTransformTesting.h"
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

Mathematics::UnitScaleTransformTesting::UnitScaleTransformTesting(const OStreamShared& streamShared)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, UnitScaleTransformTesting)

void Mathematics::UnitScaleTransformTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::UnitScaleTransformTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PromptTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RotateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(NormTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MultiplicationTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(InverseTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MakeUnitScaleTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(SetUniformScaleTest);
}

void Mathematics::UnitScaleTransformTesting::PromptTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0) };

    ASSERT_FALSE(transform0.IsIdentity());
    ASSERT_TRUE(transform0.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform0.IsUniformScale());

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{ transformTool.GetScaleD(epsilon1) };

    ASSERT_FALSE(transform1.IsIdentity());
    ASSERT_TRUE(transform1.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform1.IsUniformScale());
}

bool Mathematics::UnitScaleTransformTesting::RotateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale0 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale0 };
    const APointF point0{ scale0, scale0, scale0 };
    const Vector4F vector0{ scale0, scale0, scale0, 1.0f };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetRotate(), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetMatrix(), MatrixF::GetIdentityMatrix(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetTranslate(), APointF::GetOrigin(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW0(), Vector4F::GetZero(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW1(), Vector4F::GetUnitW(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point0, epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetScaleW1(), vector0, epsilon0);
    ASSERT_APPROXIMATE(transform0.GetUniformScale(), scale0, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale1 = transformTool.GetScaleD(epsilon1);
    const TransformD transform1{ scale1 };
    const APointD point1{ scale1, scale1, scale1 };
    const Vector4D vector1{ scale1, scale1, scale1, 1.0f };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetRotate(), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetMatrix(), MatrixD::GetIdentityMatrix(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetTranslate(), APointD::GetOrigin(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW0(), Vector4D::GetZero(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW1(), Vector4D::GetUnitW(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point1, epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetScaleW1(), vector1, epsilon1);
    ASSERT_APPROXIMATE(transform1.GetUniformScale(), scale1, epsilon1);

    return true;
}

void Mathematics::UnitScaleTransformTesting::ConvertTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0) };

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
    const TransformD transform1{ transformTool.GetScaleD(epsilon1) };

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

bool Mathematics::UnitScaleTransformTesting::NormTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale0 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale0 };

    ASSERT_APPROXIMATE(transform0.GetNorm(), MathF::FAbs(scale0), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale1 = transformTool.GetScaleD(epsilon1);
    const TransformD transform1{ scale1 };

    ASSERT_APPROXIMATE(transform1.GetNorm(), MathD::FAbs(scale1), epsilon1);

    return true;
}

bool Mathematics::UnitScaleTransformTesting::MultiplicationTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale0 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale0 };

    const auto position0 = transformTool.ComputePositionF();
    const auto position1 = transform0 * position0;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, position0 * scale0, position1, epsilon0);

    const auto vector0 = transformTool.ComputeVectorF();
    const auto vector1 = transform0 * vector0;

    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorFApproximateFunction, vector0 * scale0, vector1, epsilon0);

    const auto transform1 = transformTool.ComputeTransformF(epsilon0);
    auto transform2 = transform1 * transform0;

    transform2 *= transform0.GetInverseTransform(epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale1 = transformTool.GetScaleD(epsilon1);
    const TransformD transform3{ scale1 };

    const auto position2 = transformTool.ComputePositionD();
    const auto position3 = transform3 * position2;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, position2 * scale1, position3, epsilon1);

    const auto vector2 = transformTool.ComputeVectorD();
    const auto vector3 = transform3 * vector2;

    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorDApproximateFunction, vector2 * scale1, vector3, epsilon1);

    const auto transform4 = transformTool.ComputeTransformD(epsilon1);
    auto transform5 = transform4 * transform3;

    transform5 *= transform3.GetInverseTransform(epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon1);

    return true;
}

NODISCARD bool Mathematics::UnitScaleTransformTesting::InverseTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetHomogeneousMatrix() * transform0.GetInverseMatrix(epsilon0), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0 * transform0.GetInverseTransform(epsilon0), TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{ transformTool.GetScaleD(epsilon1) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetHomogeneousMatrix() * transform1.GetInverseMatrix(epsilon1), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1 * transform1.GetInverseTransform(epsilon1), TransformD::GetIdentityTransform(), epsilon1);

    return true;
}

bool Mathematics::UnitScaleTransformTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0) };

    const auto bufferSize0 = transform0.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    transform0.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    TransformF transform1{};
    transform1.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, transform1, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform2{ transformTool.GetScaleD(epsilon1) };

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

void Mathematics::UnitScaleTransformTesting::MakeUnitScaleTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0 = transformTool.ComputeRotationTransformF(epsilon0);

    transform0.MakeUnitScale();
    ASSERT_TRUE(transform0.IsUniformScale());

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3FApproximateFunction, transform0.GetHomogeneousMatrix().GetMatrix3(), Matrix3F::GetIdentity(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1 = transformTool.ComputeRotationTransformD(epsilon0);

    transform1.MakeUnitScale();
    ASSERT_TRUE(transform1.IsUniformScale());

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3DApproximateFunction, transform1.GetHomogeneousMatrix().GetMatrix3(), Matrix3D::GetIdentity(), epsilon1);
}

bool Mathematics::UnitScaleTransformTesting::SetUniformScaleTest()
{
    constexpr auto epsilon0 = 1e-4f;
    auto transform0 = transformTool.ComputeRotationTransformF(epsilon0);
    const auto scale0 = transformTool.GetScaleF(epsilon0);
    transform0.SetUniformScale(scale0);
    const APointF point0{ scale0, scale0, scale0 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point0, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    auto transform1 = transformTool.ComputeRotationTransformD(epsilon0);
    const auto scale1 = transformTool.GetScaleD(epsilon1);
    transform1.SetUniformScale(scale1);
    const APointD point1{ scale1, scale1, scale1 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point1, epsilon0);

    return true;
}
