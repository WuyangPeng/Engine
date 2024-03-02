/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/12/01 13:42)

#include "ScaleTransformTesting.h"
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

Mathematics::ScaleTransformTesting::ScaleTransformTesting(const OStreamShared& streamShared)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, ScaleTransformTesting)

void Mathematics::ScaleTransformTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::ScaleTransformTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PromptTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(RotateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(NormTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MultiplicationTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(InverseTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(StreamTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MakeScaleTest);
}

void Mathematics::ScaleTransformTesting::PromptTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0) };

    ASSERT_FALSE(transform0.IsIdentity());
    ASSERT_TRUE(transform0.IsRotationOrScaleMatrix());
    ASSERT_FALSE(transform0.IsUniformScale());

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{ transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1) };

    ASSERT_FALSE(transform1.IsIdentity());
    ASSERT_TRUE(transform1.IsRotationOrScaleMatrix());
    ASSERT_FALSE(transform1.IsUniformScale());
}

bool Mathematics::ScaleTransformTesting::RotateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale00 = transformTool.GetScaleF(epsilon0);
    const auto scale01 = transformTool.GetScaleF(epsilon0);
    const auto scale02 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale00, scale01, scale02 };
    const APointF point0{ scale00, scale01, scale02 };
    const Vector4F vector0{ scale00, scale01, scale02, 1.0f };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetRotate(), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetMatrix(), MatrixF::GetIdentityMatrix(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetTranslate(), APointF::GetOrigin(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW0(), Vector4F::GetZero(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW1(), Vector4F::GetUnitW(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point0, epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetScaleW1(), vector0, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale10 = transformTool.GetScaleD(epsilon1);
    const auto scale11 = transformTool.GetScaleD(epsilon1);
    const auto scale12 = transformTool.GetScaleD(epsilon1);
    const TransformD transform1{ scale10, scale11, scale12 };
    const APointD point1{ scale10, scale11, scale12 };
    const Vector4D vector1{ scale10, scale11, scale12, 1.0f };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetRotate(), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetMatrix(), MatrixD::GetIdentityMatrix(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetTranslate(), APointD::GetOrigin(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW0(), Vector4D::GetZero(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW1(), Vector4D::GetUnitW(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point1, epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetScaleW1(), vector1, epsilon1);

    return true;
}

void Mathematics::ScaleTransformTesting::ConvertTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3FApproximateFunction, transform0.GetRotationMatrix3(), Matrix3F::GetIdentity(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(aQuaternionFApproximateFunction, transform0.GetRotationAQuaternion(), AQuaternionF::GetIdentity(), epsilon0);

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
    const TransformD transform1{ transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrix3DApproximateFunction, transform1.GetRotationMatrix3(), Matrix3D::GetIdentity(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(aQuaternionDApproximateFunction, transform1.GetRotationAQuaternion(), AQuaternionD::GetIdentity(), epsilon1);

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

bool Mathematics::ScaleTransformTesting::NormTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale00 = transformTool.GetScaleF(epsilon0);
    const auto scale01 = transformTool.GetScaleF(epsilon0);
    const auto scale02 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale00, scale01, scale02 };

    ASSERT_APPROXIMATE(transform0.GetNorm(), CoreTools::MaxElement({ MathF::FAbs(scale00), MathF::FAbs(scale01), MathF::FAbs(scale02) }), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale10 = transformTool.GetScaleD(epsilon1);
    const auto scale11 = transformTool.GetScaleD(epsilon1);
    const auto scale12 = transformTool.GetScaleD(epsilon1);
    const TransformD transform1{ scale10, scale11, scale12 };

    ASSERT_APPROXIMATE(transform1.GetNorm(), CoreTools::MaxElement({ MathD::FAbs(scale10), MathD::FAbs(scale11), MathD::FAbs(scale12) }), epsilon1);

    return true;
}

bool Mathematics::ScaleTransformTesting::MultiplicationTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const auto scale00 = transformTool.GetScaleF(epsilon0);
    const auto scale01 = transformTool.GetScaleF(epsilon0);
    const auto scale02 = transformTool.GetScaleF(epsilon0);
    const TransformF transform0{ scale00, scale01, scale02 };

    const auto position0 = transformTool.ComputePositionF();
    const auto position1 = transform0 * position0;

    ASSERT_APPROXIMATE(position0.GetX() * scale00, position1.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position0.GetY() * scale01, position1.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position0.GetZ() * scale02, position1.GetZ(), epsilon0);

    const auto vector0 = transformTool.ComputeVectorF();
    const auto vector1 = transform0 * vector0;

    ASSERT_APPROXIMATE(vector0.GetX() * scale00, vector1.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector0.GetY() * scale01, vector1.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector0.GetZ() * scale02, vector1.GetZ(), epsilon0);

    const auto transform1 = transformTool.ComputeTransformF(epsilon0);
    auto transform2 = transform1 * transform0;

    transform2 *= transform0.GetInverseTransform(epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const auto scale10 = transformTool.GetScaleD(epsilon1);
    const auto scale11 = transformTool.GetScaleD(epsilon1);
    const auto scale12 = transformTool.GetScaleD(epsilon1);
    const TransformD transform3{ scale10, scale11, scale12 };

    const auto position2 = transformTool.ComputePositionD();
    const auto position3 = transform3 * position2;

    ASSERT_APPROXIMATE(position2.GetX() * scale10, position3.GetX(), epsilon0);
    ASSERT_APPROXIMATE(position2.GetY() * scale11, position3.GetY(), epsilon0);
    ASSERT_APPROXIMATE(position2.GetZ() * scale12, position3.GetZ(), epsilon0);

    const auto vector2 = transformTool.ComputeVectorD();
    const auto vector3 = transform3 * vector2;

    ASSERT_APPROXIMATE(vector2.GetX() * scale10, vector3.GetX(), epsilon0);
    ASSERT_APPROXIMATE(vector2.GetY() * scale11, vector3.GetY(), epsilon0);
    ASSERT_APPROXIMATE(vector2.GetZ() * scale12, vector3.GetZ(), epsilon0);

    const auto transform4 = transformTool.ComputeTransformD(epsilon1);
    auto transform5 = transform4 * transform3;

    transform5 *= transform3.GetInverseTransform(epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon1);

    return true;
}

NODISCARD bool Mathematics::ScaleTransformTesting::InverseTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetHomogeneousMatrix() * transform0.GetInverseMatrix(epsilon0), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0 * transform0.GetInverseTransform(epsilon0), TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{ transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1) };

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetHomogeneousMatrix() * transform1.GetInverseMatrix(epsilon1), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1 * transform1.GetInverseTransform(epsilon1), TransformD::GetIdentityTransform(), epsilon1);

    return true;
}

bool Mathematics::ScaleTransformTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{ transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0), transformTool.GetScaleF(epsilon0) };

    const auto bufferSize0 = transform0.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    transform0.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    TransformF transform1{};
    transform1.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, transform1, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform2{ transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1), transformTool.GetScaleD(epsilon1) };

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

bool Mathematics::ScaleTransformTesting::MakeScaleTest()
{
    constexpr auto epsilon0 = 1e-4f;
    auto transform0 = transformTool.ComputeRotationTransformF(epsilon0);

    const auto scale00 = transformTool.GetScaleF(epsilon0);
    const auto scale01 = transformTool.GetScaleF(epsilon0);
    const auto scale02 = transformTool.GetScaleF(epsilon0);
    transform0.SetScale(scale00, scale01, scale02);
    const APointF point00{ scale00, scale01, scale02 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point00, epsilon0);

    const APointF point01{ scale01, scale00, scale02 };
    transform0.SetScale(point01);
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point01, epsilon0);

    const APointF point02{ scale02, scale00, scale01 };
    transform0.SetScale(point02.GetVector3());
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point02, epsilon0);

    const APointF point03{ scale02, scale00, scale01 };
    transform0.SetScale(Vector4F{ point03.GetVector3() });
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), point03, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    auto transform1 = transformTool.ComputeRotationTransformD(epsilon0);

    const auto scale10 = transformTool.GetScaleD(epsilon1);
    const auto scale11 = transformTool.GetScaleD(epsilon1);
    const auto scale12 = transformTool.GetScaleD(epsilon1);
    transform1.SetScale(scale10, scale11, scale12);
    const APointD point10{ scale10, scale11, scale12 };

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point10, epsilon1);

    const APointD point11{ scale11, scale10, scale12 };
    transform1.SetScale(point11);
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point11, epsilon1);

    const APointD point12{ scale12, scale10, scale11 };
    transform1.SetScale(point12.GetVector3());
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point12, epsilon1);

    const APointD point13{ scale12, scale10, scale11 };
    transform1.SetScale(Vector4D{ point13.GetVector3() });
    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), point13, epsilon1);

    return true;
}
