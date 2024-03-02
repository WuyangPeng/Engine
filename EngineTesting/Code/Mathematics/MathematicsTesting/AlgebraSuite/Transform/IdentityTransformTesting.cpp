/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/30 19:54)

#include "IdentityTransformTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AQuaternionDetail.h"
#include "Mathematics/Algebra/Flags/EulerResultType.h"
#include "Mathematics/Algebra/TransformDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

Mathematics::IdentityTransformTesting::IdentityTransformTesting(const OStreamShared& streamShared)
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

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IdentityTransformTesting)

void Mathematics::IdentityTransformTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IdentityTransformTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PromptTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RotateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NormTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(MultiplicationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InverseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MakeIdentityTest);
}

void Mathematics::IdentityTransformTesting::PromptTest()
{
    const TransformF transform0{};

    ASSERT_TRUE(transform0.IsIdentity());
    ASSERT_TRUE(transform0.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform0.IsUniformScale());

    const TransformD transform1{};

    ASSERT_TRUE(transform1.IsIdentity());
    ASSERT_TRUE(transform1.IsRotationOrScaleMatrix());
    ASSERT_TRUE(transform1.IsUniformScale());
}

void Mathematics::IdentityTransformTesting::RotateTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetRotate(), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetMatrix(), MatrixF::GetIdentityMatrix(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetTranslate(), APointF::GetOrigin(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW0(), Vector4F::GetZero(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetTranslationW1(), Vector4F::GetUnitW(), epsilon0);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, transform0.GetScale(), APointF::GetUnit(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsF::Approximate, transform0.GetScaleW1(), Vector4F::GetOne(), epsilon0);
    ASSERT_APPROXIMATE(transform0.GetUniformScale(), MathF::GetValue(1), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{};

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetRotate(), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetMatrix(), MatrixD::GetIdentityMatrix(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetTranslate(), APointD::GetOrigin(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW0(), Vector4D::GetZero(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetTranslationW1(), Vector4D::GetUnitW(), epsilon1);

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, transform1.GetScale(), APointD::GetUnit(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector4ToolsD::Approximate, transform1.GetScaleW1(), Vector4D::GetOne(), epsilon1);
    ASSERT_APPROXIMATE(transform0.GetUniformScale(), MathD::GetValue(1), epsilon1);
}

void Mathematics::IdentityTransformTesting::ConvertTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

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
    const TransformD transform1{};

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

void Mathematics::IdentityTransformTesting::NormTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

    ASSERT_APPROXIMATE(transform0.GetNorm(), 1.0f, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{};

    ASSERT_APPROXIMATE(transform1.GetNorm(), 1.0, epsilon1);
}

bool Mathematics::IdentityTransformTesting::MultiplicationTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

    const auto position0 = transformTool.ComputePositionF();
    const auto position1 = transform0 * position0;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointFApproximateFunction, position0, position1, epsilon0);

    const auto vector0 = transformTool.ComputeVectorF();
    const auto vector1 = transform0 * vector0;

    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorFApproximateFunction, vector0, vector1, epsilon0);

    const auto transform1 = transformTool.ComputeTransformF(epsilon0);
    auto transform2 = transform0 * transform1;

    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    transform2 *= transform0;
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform1, transform2, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform3{};

    const auto position2 = transformTool.ComputePositionD();
    const auto position3 = transform3 * position2;

    ASSERT_APPROXIMATE_USE_FUNCTION(aPointDApproximateFunction, position2, position3, epsilon1);

    const auto vector2 = transformTool.ComputeVectorD();
    const auto vector3 = transform3 * vector2;

    ASSERT_APPROXIMATE_USE_FUNCTION(aVectorDApproximateFunction, vector2, vector3, epsilon1);

    const auto transform4 = transformTool.ComputeTransformD(epsilon0);
    auto transform5 = transform3 * transform4;

    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon0);

    transform5 *= transform3;
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform4, transform5, epsilon0);

    return true;
}

void Mathematics::IdentityTransformTesting::InverseTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixFApproximateFunction, transform0.GetHomogeneousMatrix() * transform0.GetInverseMatrix(epsilon0), MatrixF::GetIdentityMatrix(), epsilon0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0 * transform0.GetInverseTransform(epsilon0), TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform1{};

    ASSERT_APPROXIMATE_USE_FUNCTION(matrixDApproximateFunction, transform1.GetHomogeneousMatrix() * transform1.GetInverseMatrix(epsilon1), MatrixD::GetIdentityMatrix(), epsilon1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1 * transform1.GetInverseTransform(epsilon1), TransformD::GetIdentityTransform(), epsilon1);
}

void Mathematics::IdentityTransformTesting::StreamTest()
{
    constexpr auto epsilon0 = 1e-4f;
    const TransformF transform0{};

    const auto bufferSize0 = transform0.GetStreamingSize();

    const auto objectRegister0 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget0{ bufferSize0, objectRegister0 };

    transform0.WriteAggregate(bufferTarget0);

    CoreTools::BufferSource bufferSource0{ bufferTarget0.GetFileBuffer() };

    TransformF transform1{};
    transform1.ReadAggregate(bufferSource0);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, transform1, epsilon0);

    constexpr auto epsilon1 = 1e-6;
    const TransformD transform2{};

    const auto bufferSize1 = transform2.GetStreamingSize();

    const auto objectRegister1 = CoreTools::ObjectRegister::Create();
    CoreTools::BufferTarget bufferTarget1{ bufferSize1, objectRegister1 };

    transform2.WriteAggregate(bufferTarget1);

    CoreTools::BufferSource bufferSource1{ bufferTarget1.GetFileBuffer() };

    TransformD transform3{};
    transform3.ReadAggregate(bufferSource1);
    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform2, transform3, epsilon1);
}

void Mathematics::IdentityTransformTesting::MakeIdentityTest()
{
    constexpr auto epsilon0 = 1e-4f;
    TransformF transform0 = transformTool.ComputeTransformF(epsilon0);
    transform0.MakeIdentity();

    ASSERT_APPROXIMATE_USE_FUNCTION(transformFApproximateFunction, transform0, TransformF::GetIdentityTransform(), epsilon0);

    constexpr auto epsilon1 = 1e-6;
    TransformD transform1 = transformTool.ComputeTransformD(epsilon0);
    transform1.MakeIdentity();

    ASSERT_APPROXIMATE_USE_FUNCTION(transformDApproximateFunction, transform1, TransformD::GetIdentityTransform(), epsilon1);
}
