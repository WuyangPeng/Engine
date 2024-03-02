/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 09:15)

#ifndef MATHEMATICS_ALGEBRA_TRANSFORM_DETAIL_H
#define MATHEMATICS_ALGEBRA_TRANSFORM_DETAIL_H

#include "Angle/RotationDetail.h"
#include "Transform.h"
#include "Detail/AffineMatrixDetail.h"
#include "Detail/TransformMatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real>::Transform() noexcept
    : affineMatrix{},
      transformMatrix{},
      inverseMatrix{ MatrixInitType::Identity },
      inverseNeedsUpdate{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real>::Transform(Real scale) noexcept
    : affineMatrix{ scale },
      transformMatrix{ scale },
      inverseMatrix{ Math::GetValue(1) / scale, Math::GetValue(1) / scale, Math::GetValue(1) / scale },
      inverseNeedsUpdate{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real>::Transform(Real s0, Real s1, Real s2) noexcept
    : affineMatrix{ s0, s1, s2 },
      transformMatrix{ s0, s1, s2 },
      inverseMatrix{ Math::GetValue(1) / s0, Math::GetValue(1) / s1, Math::GetValue(1) / s2 },
      inverseNeedsUpdate{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_floating_point_v<Real>
bool Mathematics::Transform<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real>::operator Mathematics::Algebra::Matrix4x4<Real>() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetMatrix4x4();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    affineMatrix.MakeIdentity();
    transformMatrix.MakeIdentity();

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::MakeUnitScale()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    transformMatrix.MakeUnitScale();
    affineMatrix.MakeUnitScale();

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
bool Mathematics::Transform<Real>::IsIdentity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsIdentity();
}

template <typename Real>
requires std::is_floating_point_v<Real>
bool Mathematics::Transform<Real>::IsRotationOrScaleMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsRotationOrScaleMatrix();
}

template <typename Real>
requires std::is_floating_point_v<Real>
bool Mathematics::Transform<Real>::IsUniformScale() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsUniformScale();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotate(const Matrix& rotate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    affineMatrix.SetRotationOrGeneralMatrix(rotate);
    transformMatrix.SetRotate(affineMatrix.GetRotationOrGeneralMatrix(), affineMatrix.GetScale());

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotate(const Matrix4x4& rotate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix matrix{ MatrixInitType::Identity };

    for (auto row = 0; row < 4; ++row)
    {
        for (auto column = 0; column < 4; ++column)
        {
            matrix(row, column) = rotate(row, column);
        }
    }

    SetRotate(matrix);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetMatrix(const Matrix4x4& matrix)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix result{ MatrixInitType::Identity };

    for (auto row = 0; row < 4; ++row)
    {
        for (auto column = 0; column < 4; ++column)
        {
            result(row, column) = matrix(row, column);
        }
    }

    SetMatrix(result);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    affineMatrix.SetRotationOrGeneralMatrix(matrix);
    transformMatrix.SetMatrix(affineMatrix.GetRotationOrGeneralMatrix());

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(const APoint& translate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    affineMatrix.SetTranslate(translate);
    transformMatrix.SetTranslate(affineMatrix.GetTranslate());

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(Real x0, Real x1, Real x2) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetTranslate(APoint{ x0, x1, x2 });
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(const Vector3& translate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetTranslate(translate.GetX(), translate.GetY(), translate.GetZ());
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(const Vector4& translate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetTranslate(translate.GetX(), translate.GetY(), translate.GetZ());
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(const AlgebraVector3& translate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetTranslate(translate[0], translate[1], translate[2]);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetTranslate(const AlgebraVector4& translate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetTranslate(translate[0], translate[1], translate[2]);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(const APoint& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(!Approximate(scale, APoint::GetOrigin(), Math::GetZeroTolerance()), "scale不能为零。\n");

    affineMatrix.SetScale(scale);
    transformMatrix.SetScale(affineMatrix.GetRotationOrGeneralMatrix(), affineMatrix.GetScale());

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(Real s0, Real s1, Real s2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetScale(APoint{ s0, s1, s2 });
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(const Vector3& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetScale(scale.GetX(), scale.GetY(), scale.GetZ());
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(const Vector4& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetScale(scale.GetX(), scale.GetY(), scale.GetZ());
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(const AlgebraVector3& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetScale(scale[0], scale[1], scale[2]);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetScale(const AlgebraVector4& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetScale(scale[0], scale[1], scale[2]);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetUniformScale(Real scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(!Math::Approximate(scale, Real{}, Math::GetZeroTolerance()), "scale不能为零。\n");

    affineMatrix.SetScale(APoint{ scale, scale, scale });
    transformMatrix.SetUniformScale(affineMatrix.GetRotationOrGeneralMatrix(), affineMatrix.GetScale().GetX());

    inverseNeedsUpdate = true;
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix Mathematics::Transform<Real>::GetRotate() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(transformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");

    return affineMatrix.GetRotationOrGeneralMatrix();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix4x4 Mathematics::Transform<Real>::GetAlgebraRotate() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotate = GetRotate();

    return Matrix4x4{ rotate.GetData() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix Mathematics::Transform<Real>::GetMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return affineMatrix.GetRotationOrGeneralMatrix();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix4x4 Mathematics::Transform<Real>::GetAlgebraMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetMatrix();

    return Matrix4x4{ matrix.GetData() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::APoint Mathematics::Transform<Real>::GetTranslate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return affineMatrix.GetTranslate();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Vector4 Mathematics::Transform<Real>::GetTranslationW0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto translationMatrix = affineMatrix.GetTranslate();

    return Vector4{ translationMatrix.GetX(), translationMatrix.GetY(), translationMatrix.GetZ(), Math::GetValue(0) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Vector4 Mathematics::Transform<Real>::GetTranslationW1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto translationMatrix = affineMatrix.GetTranslate();

    return Vector4{ translationMatrix.GetX(), translationMatrix.GetY(), translationMatrix.GetZ(), Math::GetValue(1) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraVector3 Mathematics::Transform<Real>::GetAlgebraTranslate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto translationMatrix = affineMatrix.GetTranslate();

    return AlgebraVector3{ translationMatrix.GetX(), translationMatrix.GetY(), translationMatrix.GetZ() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraVector4 Mathematics::Transform<Real>::GetAlgebraTranslationW0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto translationMatrix = affineMatrix.GetTranslate();

    return AlgebraVector4{ translationMatrix.GetX(), translationMatrix.GetY(), translationMatrix.GetZ(), Math::GetValue(0) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraVector4 Mathematics::Transform<Real>::GetAlgebraTranslationW1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto translationMatrix = affineMatrix.GetTranslate();

    return AlgebraVector4{ translationMatrix.GetX(), translationMatrix.GetY(), translationMatrix.GetZ(), Math::GetValue(1) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::APoint Mathematics::Transform<Real>::GetScale() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(transformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");

    return affineMatrix.GetScale();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Vector4 Mathematics::Transform<Real>::GetScaleW1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto scaleMatrix = affineMatrix.GetScale();

    return Vector4{ scaleMatrix.GetX(), scaleMatrix.GetY(), scaleMatrix.GetZ(), Math::GetValue(1) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraVector3 Mathematics::Transform<Real>::GetAlgebraScale() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto scaleMatrix = GetScale();

    return AlgebraVector3{ scaleMatrix.GetX(), scaleMatrix.GetY(), scaleMatrix.GetZ() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraVector4 Mathematics::Transform<Real>::GetAlgebraScaleW1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto scaleMatrix = affineMatrix.GetScale();

    return AlgebraVector4{ scaleMatrix.GetX(), scaleMatrix.GetY(), scaleMatrix.GetZ(), Math::GetValue(1) };
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::Transform<Real>::GetUniformScale() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(transformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");
    MATHEMATICS_ASSERTION_0(transformMatrix.IsUniformScale(), "Matrix不是单位缩放\n");

    return GetScale().GetX();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const Matrix3& rotate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetRotate(Matrix{ rotate });
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix3 Mathematics::Transform<Real>::GetRotationMatrix3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetRotate().GetMatrix3();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const Matrix3x3& rotate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix matrix{ MatrixInitType::Identity };

    for (auto row = 0; row < 3; ++row)
    {
        for (auto column = 0; column < 3; ++column)
        {
            matrix(row, column) = rotate(row, column);
        }
    }

    SetRotate(matrix);
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix3x3 Mathematics::Transform<Real>::GetRotationMatrix3x3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix3x3 matrix{};

    const auto rotate = GetRotate();

    for (auto row = 0; row < 3; ++row)
    {
        for (auto column = 0; column < 3; ++column)
        {
            matrix(row, column) = rotate(row, column);
        }
    }
    return matrix;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const AQuaternion& quaternion) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetRotate(quaternion.ToRotationMatrix());
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AQuaternion Mathematics::Transform<Real>::GetRotationAQuaternion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    AQuaternion quaternion{};

    quaternion.FromRotationMatrix(GetRotate());

    return quaternion;
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const Quaternion& quaternion)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetRotate(static_cast<Matrix4x4>(Algebra::Rotation<4, Real>(quaternion)));
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Quaternion Mathematics::Transform<Real>::GetRotationQuaternion() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetAlgebraMatrix();

    return static_cast<Quaternion>(Algebra::Rotation<4, Real>(matrix));
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const AxisAngle& axisAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix matrix{};

    matrix.MakeRotation(AVector{ axisAngle.GetAxis() }, axisAngle.GetAngle());

    SetRotate(matrix);
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AxisAngle Mathematics::Transform<Real>::GetRotationAxisAngle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetRotate().GetMatrix3().ExtractAngleAxis();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const AlgebraAxisAngle3& axisAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const AlgebraAxisAngle4 axisAngle4{ HomogeneousLift(axisAngle.GetAxis(), Math::GetValue(1)), axisAngle.GetAngle() };

    SetRotate(static_cast<Matrix4x4>(Algebra::Rotation<4, Real>(axisAngle4)));
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraAxisAngle3 Mathematics::Transform<Real>::GetRotationAlgebraAxisAngle3() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetAlgebraMatrix();

    const auto algebraAxisAngle4 = static_cast<AlgebraAxisAngle4>(Algebra::Rotation<4, Real>(matrix));

    return AlgebraAxisAngle3{ HomogeneousProject(algebraAxisAngle4.GetAxis()), algebraAxisAngle4.GetAngle() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const AlgebraAxisAngle4& axisAngle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetRotate(static_cast<Matrix4x4>(Algebra::Rotation<4, Real>(axisAngle)));
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AlgebraAxisAngle4 Mathematics::Transform<Real>::GetRotationAlgebraAxisAngle4() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetAlgebraMatrix();

    return static_cast<AlgebraAxisAngle4>(Algebra::Rotation<4, Real>(matrix));
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const Euler& eulerAngles)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix3 rotate{};
    rotate.MakeEuler(eulerAngles);

    SetRotate(Matrix{ rotate });
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Euler Mathematics::Transform<Real>::GetRotationEuler(ExtractEulerResultOrder order) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetRotate().GetMatrix3();

    return matrix.ExtractEuler(order);
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::SetRotation(const EulerAngles& eulerAngles)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetRotate(static_cast<Matrix4x4>(Algebra::Rotation<4, Real>(eulerAngles)));
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::EulerAngles Mathematics::Transform<Real>::GetEulerAngles(int axis0, int axis1, int axis2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = GetAlgebraMatrix();

    return Algebra::Rotation<4, Real>(matrix)(axis0, axis1, axis2);
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::Transform<Real>::GetNorm() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (transformMatrix.IsRotationOrScaleMatrix())
    {
        // 使用RS矩阵（已定义MATHEMATICS_USE_MATRIX_VECTOR）或SR矩阵（未定义MATHEMATICS_USE_MATRIX_VECTOR）。
        return GetScale().GetNorm();
    }

    // 一般的矩阵。使用最大行和矩阵规范。光谱标准（特征值的最大绝对值）小于或等于该标准。
    // 因此，此函数返回最大比例的近似值。
    return affineMatrix.GetRotationOrGeneralMatrix().GetNorm();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::APoint Mathematics::Transform<Real>::operator*(const APoint& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix() * point;
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::AVector Mathematics::Transform<Real>::operator*(const AVector& vector) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix() * vector;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real>& Mathematics::Transform<Real>::operator*=(const Transform& transform)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = *this * transform;

    return *this;
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix Mathematics::Transform<Real>::GetHomogeneousMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix();
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix4x4 Mathematics::Transform<Real>::GetMatrix4x4() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto matrix = transformMatrix.GetMatrix();

    return Matrix4x4{ matrix.GetData() };
}

template <typename Real>
requires std::is_floating_point_v<Real>
typename Mathematics::Transform<Real>::Matrix Mathematics::Transform<Real>::GetInverseMatrix(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (inverseNeedsUpdate)
    {
        if (transformMatrix.IsIdentity())
        {
            inverseMatrix.MakeIdentity();
        }
        else
        {
            const auto rotationOrGeneralMatrix = affineMatrix.GetRotationOrGeneralMatrix();
            const auto scaleMatrix = affineMatrix.GetScale();
            const auto translateMatrix = affineMatrix.GetTranslate();

            if (transformMatrix.IsRotationOrScaleMatrix())
            {
                if (transformMatrix.IsUniformScale())
                {
                    const auto inverseScale = Math::GetValue(1) / scaleMatrix.GetX();

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

                    inverseMatrix.SetValue<0, 0>(inverseScale * rotationOrGeneralMatrix.template GetValue<0, 0>());
                    inverseMatrix.SetValue<0, 1>(inverseScale * rotationOrGeneralMatrix.template GetValue<1, 0>());
                    inverseMatrix.SetValue<0, 2>(inverseScale * rotationOrGeneralMatrix.template GetValue<2, 0>());

                    inverseMatrix.SetValue<1, 0>(inverseScale * rotationOrGeneralMatrix.template GetValue<0, 1>());
                    inverseMatrix.SetValue<1, 1>(inverseScale * rotationOrGeneralMatrix.template GetValue<1, 1>());
                    inverseMatrix.SetValue<1, 2>(inverseScale * rotationOrGeneralMatrix.template GetValue<2, 1>());

                    inverseMatrix.SetValue<2, 0>(inverseScale * rotationOrGeneralMatrix.template GetValue<0, 2>());
                    inverseMatrix.SetValue<2, 1>(inverseScale * rotationOrGeneralMatrix.template GetValue<1, 2>());
                    inverseMatrix.SetValue<2, 2>(inverseScale * rotationOrGeneralMatrix.template GetValue<2, 2>());

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

                    inverseMatrix.SetValue<0, 0>(rotationOrGeneralMatrix.template GetValue<0, 0>() * inverseScale);
                    inverseMatrix.SetValue<0, 1>(rotationOrGeneralMatrix.template GetValue<1, 0>() * inverseScale);
                    inverseMatrix.SetValue<0, 2>(rotationOrGeneralMatrix.template GetValue<2, 0>() * inverseScale);

                    inverseMatrix.SetValue<1, 0>(rotationOrGeneralMatrix.template GetValue<0, 1>() * inverseScale);
                    inverseMatrix.SetValue<1, 1>(rotationOrGeneralMatrix.template GetValue<1, 1>() * inverseScale);
                    inverseMatrix.SetValue<1, 2>(rotationOrGeneralMatrix.template GetValue<2, 1>() * inverseScale);

                    inverseMatrix.SetValue<2, 0>(rotationOrGeneralMatrix.template GetValue<0, 2>() * inverseScale);
                    inverseMatrix.SetValue<2, 1>(rotationOrGeneralMatrix.template GetValue<1, 2>() * inverseScale);
                    inverseMatrix.SetValue<2, 2>(rotationOrGeneralMatrix.template GetValue<2, 2>() * inverseScale);

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)
                }
                else
                {
                    // 替换3个倒数为6次乘法和1个倒数。
                    const auto scale01 = scaleMatrix.GetX() * scaleMatrix.GetY();
                    const auto scale02 = scaleMatrix.GetX() * scaleMatrix.GetZ();
                    const auto scale12 = scaleMatrix.GetY() * scaleMatrix.GetZ();
                    const auto inverseScale012 = Math::GetValue(1) / (scale01 * scaleMatrix.GetZ());
                    const auto inverseScale0 = scale12 * inverseScale012;
                    const auto inverseScale1 = scale02 * inverseScale012;
                    const auto inverseScale2 = scale01 * inverseScale012;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

                    inverseMatrix.SetValue<0, 0>(inverseScale0 * rotationOrGeneralMatrix.template GetValue<0, 0>());
                    inverseMatrix.SetValue<0, 1>(inverseScale0 * rotationOrGeneralMatrix.template GetValue<1, 0>());
                    inverseMatrix.SetValue<0, 2>(inverseScale0 * rotationOrGeneralMatrix.template GetValue<2, 0>());

                    inverseMatrix.SetValue<1, 0>(inverseScale1 * rotationOrGeneralMatrix.template GetValue<0, 1>());
                    inverseMatrix.SetValue<1, 1>(inverseScale1 * rotationOrGeneralMatrix.template GetValue<1, 1>());
                    inverseMatrix.SetValue<1, 2>(inverseScale1 * rotationOrGeneralMatrix.template GetValue<2, 1>());

                    inverseMatrix.SetValue<2, 0>(inverseScale2 * rotationOrGeneralMatrix.template GetValue<0, 2>());
                    inverseMatrix.SetValue<2, 1>(inverseScale2 * rotationOrGeneralMatrix.template GetValue<1, 2>());
                    inverseMatrix.SetValue<2, 2>(inverseScale2 * rotationOrGeneralMatrix.template GetValue<2, 2>());

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

                    inverseMatrix.SetValue<0, 0>(rotationOrGeneralMatrix.template GetValue<0, 0>() * inverseScale0);
                    inverseMatrix.SetValue<0, 1>(rotationOrGeneralMatrix.template GetValue<1, 0>() * inverseScale0);
                    inverseMatrix.SetValue<0, 2>(rotationOrGeneralMatrix.template GetValue<2, 0>() * inverseScale0);

                    inverseMatrix.SetValue<1, 0>(rotationOrGeneralMatrix.template GetValue<0, 1>() * inverseScale1);
                    inverseMatrix.SetValue<1, 1>(rotationOrGeneralMatrix.template GetValue<1, 1>() * inverseScale1);
                    inverseMatrix.SetValue<1, 2>(rotationOrGeneralMatrix.template GetValue<2, 1>() * inverseScale1);

                    inverseMatrix.SetValue<2, 0>(rotationOrGeneralMatrix.template GetValue<0, 2>() * inverseScale2);
                    inverseMatrix.SetValue<2, 1>(rotationOrGeneralMatrix.template GetValue<1, 2>() * inverseScale2);
                    inverseMatrix.SetValue<2, 2>(rotationOrGeneralMatrix.template GetValue<2, 2>() * inverseScale2);

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)
                }
            }
            else
            {
                inverseMatrix = GetHomogeneousMatrix().Invert3x3(epsilon);
            }

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

            inverseMatrix.SetValue<0, 3>(-(inverseMatrix.template GetValue<0, 0>() * translateMatrix.GetX() +
                                           inverseMatrix.template GetValue<0, 1>() * translateMatrix.GetY() +
                                           inverseMatrix.template GetValue<0, 2>() * translateMatrix.GetZ()));

            inverseMatrix.SetValue<1, 3>(-(inverseMatrix.template GetValue<1, 0>() * translateMatrix.GetX() +
                                           inverseMatrix.template GetValue<1, 1>() * translateMatrix.GetY() +
                                           inverseMatrix.template GetValue<1, 2>() * translateMatrix.GetZ()));

            inverseMatrix.SetValue<2, 3>(-(inverseMatrix.template GetValue<2, 0>() * translateMatrix.GetX() +
                                           inverseMatrix.template GetValue<2, 1>() * translateMatrix.GetY() +
                                           inverseMatrix.template GetValue<2, 2>() * translateMatrix.GetZ()));

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

            inverseMatrix.SetValue<3, 0>(-(inverseMatrix.template GetValue<0, 0>() * translate.GetX() +
                                           inverseMatrix.template GetValue<1, 0>() * translate.GetY() +
                                           inverseMatrix.template GetValue<2, 0>() * translate.GetZ()));

            inverseMatrix.SetValue<3, 1>(-(inverseMatrix.template GetValue<0, 1>() * translate.GetX() +
                                           inverseMatrix.template GetValue<1, 1>() * translate.GetY() +
                                           inverseMatrix.template GetValue<2, 1>() * translate.GetZ()));

            inverseMatrix.SetValue<3, 2>(-(inverseMatrix.template GetValue<0, 2>() * translate.GetX() +
                                           inverseMatrix.template GetValue<1, 2>() * translate.GetY() +
                                           inverseMatrix.template GetValue<2, 2>() * translate.GetZ()));

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)

            // 对于一个仿射变换，matrix的最后一行总是(0,0,0,1)。所以在构造函数中设置一次。没有必要在这里重置。
        }

        inverseNeedsUpdate = false;
    }

    return inverseMatrix;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Transform<Real> Mathematics::Transform<Real>::GetInverseTransform(Real epsilon) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Transform inverse{};  // = the identity

    if (!transformMatrix.IsIdentity())
    {
        if (transformMatrix.IsRotationOrScaleMatrix() && transformMatrix.IsUniformScale())
        {
            const auto rotationOrGeneralMatrix = affineMatrix.GetRotationOrGeneralMatrix();
            const auto scaleMatrix = affineMatrix.GetScale();
            const auto translateMatrix = affineMatrix.GetTranslate();

            const auto inverseRotation = rotationOrGeneralMatrix.Transpose();
            const auto inverseScale = Math::GetValue(1) / scaleMatrix.GetX();
            const auto inverseTransform = -inverseScale * (inverseRotation * GetTranslate());

            inverse.SetRotate(inverseRotation);
            inverse.SetUniformScale(inverseScale);
            inverse.SetTranslate(inverseTransform);
        }
        else
        {
            const auto rotationInverse = GetHomogeneousMatrix().Inverse(epsilon);
            const auto inverseTransform = rotationInverse.GetColumn(System::EnumCastUnderlying(HomogeneousPoint<Real>::PointIndex::W));

            inverse.SetMatrix(rotationInverse);
            inverse.SetTranslate(inverseTransform.GetX(), inverseTransform.GetY(), inverseTransform.GetZ());
        }
    }

    return inverse;
}

template <typename Real>
requires std::is_floating_point_v<Real>
int Mathematics::Transform<Real>::GetStreamingSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto rotationOrGeneralMatrix = affineMatrix.GetRotationOrGeneralMatrix();
    const auto scaleMatrix = affineMatrix.GetScale();
    const auto translateMatrix = affineMatrix.GetTranslate();

    const auto isIdentity = transformMatrix.IsIdentity();
    const auto isRotationOrScaleMatrix = transformMatrix.IsRotationOrScaleMatrix();
    const auto isUniformScale = transformMatrix.IsUniformScale();

    auto size = Mathematics::GetStreamSize(isIdentity) + Mathematics::GetStreamSize(isRotationOrScaleMatrix) + Mathematics::GetStreamSize(isUniformScale);

    if (isIdentity)
    {
        return size;
    }
    else if (isRotationOrScaleMatrix)
    {
        if (isUniformScale)
        {
            size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
            size += Mathematics::GetStreamSize(scaleMatrix.GetX());
            size += Mathematics::GetStreamSize(translateMatrix);

            return size;
        }
        else
        {
            size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
            size += Mathematics::GetStreamSize(scaleMatrix);
            size += Mathematics::GetStreamSize(translateMatrix);

            return size;
        }
    }
    else
    {
        size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
        size += Mathematics::GetStreamSize(translateMatrix);

        return size;
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::ReadAggregate(BufferSource& source)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto isIdentity = source.ReadBool();
    const auto isRotationOrScaleMatrix = source.ReadBool();
    const auto isUniformScale = source.ReadBool();

    if (isIdentity)
    {
        MakeIdentity();
    }
    else if (isRotationOrScaleMatrix)
    {
        if (isUniformScale)
        {
            Matrix rotate{};
            Real scale{};
            APoint translate{};

            source.ReadAggregate(rotate);
            source.Read(scale);
            source.ReadAggregate(translate);

            SetRotate(rotate);
            SetUniformScale(scale);
            SetTranslate(translate);
        }
        else
        {
            Matrix rotate{};
            APoint scale{};
            APoint translate{};

            source.ReadAggregate(rotate);
            source.ReadAggregate(scale);
            source.ReadAggregate(translate);

            SetRotate(rotate);
            SetScale(scale);
            SetTranslate(translate);
        }
    }
    else
    {
        Matrix matrix{};
        APoint translate{};

        source.ReadAggregate(matrix);
        source.ReadAggregate(translate);

        SetMatrix(matrix);
        SetTranslate(translate);
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::Transform<Real>::WriteAggregate(BufferTarget& target) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto isIdentity = IsIdentity();
    const auto isRotationOrScaleMatrix = IsRotationOrScaleMatrix();
    const auto isUniformScale = IsUniformScale();

    target.Write(isIdentity);
    target.Write(isRotationOrScaleMatrix);
    target.Write(isUniformScale);

    if (!isIdentity)
    {
        if (isRotationOrScaleMatrix)
        {
            if (isUniformScale)
            {
                target.WriteAggregate(GetRotate());
                target.Write(GetUniformScale());
                target.WriteAggregate(GetTranslate());
            }
            else
            {
                target.WriteAggregate(GetRotate());
                target.WriteAggregate(GetScale());
                target.WriteAggregate(GetTranslate());
            }
        }
        else
        {
            target.WriteAggregate(GetMatrix());
            target.WriteAggregate(GetTranslate());
        }
    }
}

template <typename Real>
Mathematics::Vector4<Real> Mathematics::operator*(const Transform<Real>& transform, const Vector4<Real>& vector)
{
    return transform.GetAlgebraMatrix() * vector;
}

template <typename Real>
Mathematics::Vector4<Real> Mathematics::operator*(const Vector4<Real>& vector, const Transform<Real>& transform)
{
    return vector * transform.GetAlgebraMatrix();
}

template <typename Real>
Mathematics::Transform<Real> Mathematics::operator*(const Transform<Real>& lhs, const Transform<Real>& rhs)
{
    if (lhs.IsIdentity())
    {
        return rhs;
    }

    if (rhs.IsIdentity())
    {
        return lhs;
    }

    Transform<Real> product{};

    if (lhs.IsRotationOrScaleMatrix() && rhs.IsRotationOrScaleMatrix())
    {
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

        if (lhs.IsUniformScale())
        {
            product.SetRotate(lhs.GetMatrix() * rhs.GetMatrix());

            product.SetTranslate(lhs.GetUniformScale() * (lhs.GetMatrix() * rhs.GetTranslate()) + lhs.GetTranslate());

            if (rhs.IsUniformScale())
            {
                product.SetUniformScale(lhs.GetUniformScale() * rhs.GetUniformScale());
            }
            else
            {
                product.SetScale(lhs.GetUniformScale() * rhs.GetScale());
            }

            return product;
        }

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

        if (lhs.IsUniformScale())
        {
            product.SetRotate(lhs.GetMatrix() * rhs.GetMatrix());

            product.SetTranslate(rhs.GetUniformScale() * (rhs.GetMatrix() * lhs.GetTranslate()) + rhs.GetTranslate());

            if (rhs.IsUniformScale())
            {
                product.SetUniformScale(lhs.GetUniformScale() * rhs.GetUniformScale());
            }
            else
            {
                product.SetScale(lhs.GetUniformScale() * rhs.GetScale());
            }

            return product;
        }

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)
    }

    /// 在所有剩余的情况下，矩阵不能写成R * S * X + T。

    const auto matrixA = (lhs.IsRotationOrScaleMatrix() ? lhs.GetMatrix().TimesDiagonal(lhs.GetScale()) : lhs.GetMatrix());
    const auto matrixB = (rhs.IsRotationOrScaleMatrix() ? rhs.GetMatrix().TimesDiagonal(rhs.GetScale()) : rhs.GetMatrix());

    product.SetMatrix(matrixA * matrixB);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    product.SetTranslate(matrixA * rhs.GetTranslate() + lhs.GetTranslate());

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    product.SetTranslate(lhs.GetTranslate() * matrixB + rhs.GetTranslate());

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return product;
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::operator*(const Algebra::Matrix4x4<Real>& matrix, const Transform<Real>& transform)
{
    return matrix * transform.GetAlgebraMatrix();
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::operator*(const Transform<Real>& transform, const Algebra::Matrix4x4<Real>& matrix)
{
    return transform.GetAlgebraMatrix() * matrix;
}

template <typename Real>
bool Mathematics::Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon)
{
    const auto lhsIsIdentity = lhs.IsIdentity();
    const auto lhsIsRotationOrScaleMatrix = lhs.IsRotationOrScaleMatrix();
    const auto lhsIsUniformScale = lhs.IsUniformScale();

    const auto rhsIsIdentity = rhs.IsIdentity();
    const auto rhsIsRotationOrScaleMatrix = rhs.IsRotationOrScaleMatrix();
    const auto rhsIsUniformScale = rhs.IsUniformScale();

    if (lhsIsIdentity && rhsIsIdentity)
    {
        return true;
    }
    else if (lhsIsRotationOrScaleMatrix && rhsIsRotationOrScaleMatrix)
    {
        if (lhsIsUniformScale && rhsIsUniformScale)
        {
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) &&
                Math<Real>::Approximate(lhs.GetUniformScale(), rhs.GetUniformScale(), epsilon) &&
                Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) &&
                Approximate(lhs.GetScale(), rhs.GetScale(), epsilon) &&
                Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
                return true;
            else
                return false;
        }
    }
    else
    {
        if (Approximate(lhs.GetHomogeneousMatrix(), rhs.GetHomogeneousMatrix(), epsilon))
            return true;
        else
            return false;
    }
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& stream, const Transform<Real>& transform)
{
    if (transform.IsRotationOrScaleMatrix())
    {
        stream << "Rotate:"
               << transform.GetRotate()
               << "　"
               << "Translate:"
               << transform.GetTranslate()
               << "　"
               << "Scale:"
               << transform.GetScale()
               << "　";
    }
    else
    {
        stream << "Rotate:"
               << transform.GetMatrix()
               << "　"
               << "Translate:"
               << transform.GetTranslate()
               << "　";
    }

    return stream;
}

#endif  // MATHEMATICS_ALGEBRA_TRANSFORM_DETAIL_H
