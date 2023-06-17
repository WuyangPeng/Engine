///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:55)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H
#define RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H

#include "Transform.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"

template <typename Real>
Rendering::Transform<Real>::Transform() noexcept
    : transformMatrix{},
      rotationOrGeneralMatrix{ Mathematics::MatrixInitType::Identity },
      translate{},
      scale{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) },
      inverseMatrix{ Mathematics::MatrixInitType::Identity },
      inverseNeedsUpdate{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Rendering::Transform<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Rendering::Transform<Real>::MakeIdentity() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rotationOrGeneralMatrix.MakeIdentity();

    translate = APoint{};
    scale = APoint{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };

    transformMatrix.MakeIdentity();

    inverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::Transform<Real>::MakeUnitScale() noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    scale = APoint{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };

    transformMatrix.MakeUnitScale(rotationOrGeneralMatrix);

    inverseNeedsUpdate = true;
}

template <typename Real>
bool Rendering::Transform<Real>::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsIdentity();
}

template <typename Real>
bool Rendering::Transform<Real>::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsRotationOrScaleMatrix();
}

template <typename Real>
bool Rendering::Transform<Real>::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.IsUniformScale();
}

template <typename Real>
void Rendering::Transform<Real>::SetRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rotationOrGeneralMatrix = rotate;

    transformMatrix.SetRotate(rotationOrGeneralMatrix, scale);

    inverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::Transform<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rotationOrGeneralMatrix = matrix;

    transformMatrix.SetMatrix(rotationOrGeneralMatrix);

    inverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::Transform<Real>::SetTranslate(const APoint& aTranslate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    translate = aTranslate;

    transformMatrix.SetTranslate(translate);

    inverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::Transform<Real>::SetScale(const APoint& aScale) noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(Approximate(aScale, APoint{}, Math::GetZeroTolerance()), "scale����Ϊ�㡣\n");

    scale = aScale;

    transformMatrix.SetScale(rotationOrGeneralMatrix, scale);

    inverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::Transform<Real>::SetUniformScale(Real aScale) noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    scale = APoint{ aScale, aScale, aScale };

    transformMatrix.SetUniformScale(rotationOrGeneralMatrix, scale.GetX());

    inverseNeedsUpdate = true;
}

template <typename Real>
typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetRotate() const noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_2(transformMatrix.IsRotationOrScaleMatrix(), "Matrix������ת����\n");

    return rotationOrGeneralMatrix;
}

template <typename Real>
typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rotationOrGeneralMatrix;
}

template <typename Real>
typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return translate;
}

template <typename Real>
typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::GetScale() const noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(transformMatrix.IsRotationOrScaleMatrix(), "Matrix������ת����\n");

    return scale;
}

template <typename Real>
Real Rendering::Transform<Real>::GetUniformScale() const noexcept(gAssert < 2 || gRenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(transformMatrix.IsRotationOrScaleMatrix(), "Matrix������ת����\n");
    RENDERING_ASSERTION_1(transformMatrix.IsUniformScale(), "Matrix���ǵ�λ����\n");

    return scale.GetX();
}

template <typename Real>
Real Rendering::Transform<Real>::GetNorm() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (transformMatrix.IsRotationOrScaleMatrix())
    {
        return scale.GetNorm();
    }

    // һ��ľ���ʹ������к;���淶�����ױ�׼������ֵ��������ֵ��С�ڻ���ڸñ�׼��
    // ��ˣ��˺��������������Ľ���ֵ��
    return rotationOrGeneralMatrix.GetNorm();
}

template <typename Real>
typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::operator*(const APoint& point) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix() * point;
}

template <typename Real>
typename Rendering::Transform<Real>::AVector Rendering::Transform<Real>::operator*(const AVector& vector) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix() * vector;
}

template <typename Real>
Rendering::Transform<Real>& Rendering::Transform<Real>::operator*=(const Transform& transform)
{
    RENDERING_CLASS_IS_VALID_9;

    *this = *this * transform;

    return *this;
}

template <typename Real>
typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetHomogeneousMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix.GetMatrix();
}

template <typename Real>
typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetInverseMatrix(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (inverseNeedsUpdate)
    {
        if (transformMatrix.IsIdentity())
        {
            inverseMatrix.MakeIdentity();
        }
        else
        {
            if (transformMatrix.IsRotationOrScaleMatrix())
            {
                if (transformMatrix.IsUniformScale())
                {
                    inverseMatrix.SetValue<0>(rotationOrGeneralMatrix.GetValue<0>() / scale.GetX());
                    inverseMatrix.SetValue<1>(rotationOrGeneralMatrix.GetValue<4>() / scale.GetX());
                    inverseMatrix.SetValue<2>(rotationOrGeneralMatrix.GetValue<8>() / scale.GetX());

                    inverseMatrix.SetValue<4>(rotationOrGeneralMatrix.GetValue<1>() / scale.GetX());
                    inverseMatrix.SetValue<5>(rotationOrGeneralMatrix.GetValue<5>() / scale.GetX());
                    inverseMatrix.SetValue<6>(rotationOrGeneralMatrix.GetValue<9>() / scale.GetX());

                    inverseMatrix.SetValue<8>(rotationOrGeneralMatrix.GetValue<2>() / scale.GetX());
                    inverseMatrix.SetValue<9>(rotationOrGeneralMatrix.GetValue<6>() / scale.GetX());
                    inverseMatrix.SetValue<10>(rotationOrGeneralMatrix.GetValue<10>() / scale.GetX());
                }
                else
                {
                    // �滻3�������ֱ����6��1��������
                    const auto scale01 = scale.GetX() * scale.GetY();
                    const auto scale02 = scale.GetX() * scale.GetZ();
                    const auto scale12 = scale.GetY() * scale.GetZ();
                    const auto scale012 = (scale01 * scale.GetZ());
                    const auto inverseScale0 = scale12 / scale012;
                    const auto inverseScale1 = scale02 / scale012;
                    const auto inverseScale2 = scale01 / scale012;

                    inverseMatrix.SetValue<0>(inverseScale0 * rotationOrGeneralMatrix.GetValue<0>());
                    inverseMatrix.SetValue<1>(inverseScale0 * rotationOrGeneralMatrix.GetValue<4>());
                    inverseMatrix.SetValue<2>(inverseScale0 * rotationOrGeneralMatrix.GetValue<8>());

                    inverseMatrix.SetValue<4>(inverseScale1 * rotationOrGeneralMatrix.GetValue<1>());
                    inverseMatrix.SetValue<5>(inverseScale1 * rotationOrGeneralMatrix.GetValue<5>());
                    inverseMatrix.SetValue<6>(inverseScale1 * rotationOrGeneralMatrix.GetValue<9>());

                    inverseMatrix.SetValue<8>(inverseScale2 * rotationOrGeneralMatrix.GetValue<2>());
                    inverseMatrix.SetValue<9>(inverseScale2 * rotationOrGeneralMatrix.GetValue<6>());
                    inverseMatrix.SetValue<10>(inverseScale2 * rotationOrGeneralMatrix.GetValue<10>());
                }
            }
            else
            {
                inverseMatrix = rotationOrGeneralMatrix.Invert3x3(epsilon);
            }

            inverseMatrix.Plus<3>(-(inverseMatrix.GetValue<0>() * translate.GetX() + inverseMatrix.GetValue<1>() * translate.GetY() + inverseMatrix.GetValue<2>() * translate.GetZ()));

            inverseMatrix.Plus<7>(-(inverseMatrix.GetValue<4>() * translate.GetX() + inverseMatrix.GetValue<5>() * translate.GetY() + inverseMatrix.GetValue<6>() * translate.GetZ()));

            inverseMatrix.Plus<11>(-(inverseMatrix.GetValue<8>() * translate.GetX() + inverseMatrix.GetValue<9>() * translate.GetY() + inverseMatrix.GetValue<10>() * translate.GetZ()));

            // ����һ������任��m_Matrix�����һ������(0,0,0,1)�������ڹ��캯��������һ�Ρ�û�б�Ҫ���������á�
        }

        inverseNeedsUpdate = false;
    }

    return inverseMatrix;
}

template <typename Real>
Rendering::Transform<Real> Rendering::Transform<Real>::GetInverseTransform(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (transformMatrix.IsIdentity())
    {
        return Transform<Real>{};
    }

    Transform inverse{};
    APoint inverseTransform{};
    if (transformMatrix.IsRotationOrScaleMatrix())
    {
        const auto inverseRotation = rotationOrGeneralMatrix.Transpose();
        inverse.SetRotate(inverseRotation);
        if (transformMatrix.IsUniformScale())
        {
            const auto inverseScale = Math::GetValue(1) / scale.GetX();
            inverse.SetUniformScale(inverseScale);
            inverseTransform = -inverseScale * (inverseRotation * translate);
        }
        else
        {
            // Transform��Y = M * X + T��M = R * S���淽����X = S^{-1} * R^t * (Y - T)��
            // �޷���ʾΪX = (R * S) * Y + T��ֻ�ܱ�ʾΪX = (S * R) * Y + T��

            const APoint inverseScale{ Math::GetValue(1) / scale.GetX(), Math::GetValue(1) / scale.GetY(), Math::GetValue(1) / scale.GetZ() };
            inverse.SetScale(inverseScale);
            inverseTransform = inverseRotation * translate;
            inverseTransform[0] *= -inverseScale.GetX();
            inverseTransform[1] *= -inverseScale.GetY();
            inverseTransform[2] *= -inverseScale.GetZ();
        }
    }
    else
    {
        const auto result = rotationOrGeneralMatrix.Invert3x3(epsilon);

        inverse.SetMatrix(result);
        inverseTransform = -(result * translate);
    }

    inverse.SetTranslate(inverseTransform);

    return inverse;
}

template <typename Real>
int Rendering::Transform<Real>::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto isIdentity = transformMatrix.IsIdentity();
    const auto isRotationOrScaleMatrix = transformMatrix.IsRotationOrScaleMatrix();
    const auto isUniformScale = transformMatrix.IsUniformScale();

    auto size = CoreTools::GetStreamSize(isIdentity) + CoreTools::GetStreamSize(isRotationOrScaleMatrix) + CoreTools::GetStreamSize(isUniformScale);

    if (isIdentity)
    {
        return size;
    }
    else if (isRotationOrScaleMatrix)
    {
        if (isUniformScale)
        {
            size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
            size += CoreTools::GetStreamSize(scale.GetX());
            size += Mathematics::GetStreamSize(translate);

            return size;
        }
        else
        {
            size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
            size += Mathematics::GetStreamSize(scale);
            size += Mathematics::GetStreamSize(translate);

            return size;
        }
    }
    else
    {
        size += Mathematics::GetStreamSize(rotationOrGeneralMatrix);
        size += Mathematics::GetStreamSize(translate);

        return size;
    }
}

template <typename Real>
void Rendering::Transform<Real>::ReadAggregate(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

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
            auto aScale = Math::GetValue(0);
            APoint aTranslate{};

            source.ReadAggregate(rotate);
            source.Read(aScale);
            source.ReadAggregate(aTranslate);

            SetRotate(rotate);
            SetUniformScale(aScale);
            SetTranslate(aTranslate);
        }
        else
        {
            Matrix rotate{};
            APoint aScale{};
            APoint aTranslate{};

            source.ReadAggregate(rotate);
            source.ReadAggregate(aScale);
            source.ReadAggregate(aTranslate);

            SetRotate(rotate);
            SetScale(aScale);
            SetTranslate(aTranslate);
        }
    }
    else
    {
        Matrix matrix{};
        APoint aTranslate{};

        source.ReadAggregate(matrix);
        source.ReadAggregate(aTranslate);

        SetMatrix(matrix);
        SetTranslate(aTranslate);
    }
}

template <typename Real>
void Rendering::Transform<Real>::WriteAggregate(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

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
Rendering::Transform<Real> Rendering::operator*(const Transform<Real>& lhs, const Transform<Real>& rhs)
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
    }

    // ������ʣ�������£�������д��R * S * X + T��
    const auto matrixA = (lhs.IsRotationOrScaleMatrix() ? lhs.GetMatrix().TimesDiagonal(lhs.GetScale()) : lhs.GetMatrix());
    const auto matrixB = (rhs.IsRotationOrScaleMatrix() ? rhs.GetMatrix().TimesDiagonal(rhs.GetScale()) : rhs.GetMatrix());

    product.SetMatrix(matrixA * matrixB);
    product.SetTranslate(matrixA * rhs.GetTranslate() + lhs.GetTranslate());

    return product;
}

template <typename Real>
bool Rendering::Approximate(const Transform<Real>& lhs, const Transform<Real>& rhs, const Real epsilon)
{
    const auto lhsIsIdentity = lhs.IsIdentity();
    const auto lhsIsRotationOrScaleMatrix = lhs.IsRotationOrScaleMatrix();
    const auto lhsIsUniformScale = lhs.IsUniformScale();

    const auto rhsIsIdentity = rhs.IsIdentity();
    const auto rhsIsRotationOrScaleMatrix = rhs.IsRotationOrScaleMatrix();
    const auto rhsIsUniformScale = rhs.IsUniformScale();

    if (lhsIsIdentity != rhsIsIdentity || lhsIsRotationOrScaleMatrix != rhsIsRotationOrScaleMatrix || lhsIsUniformScale != rhsIsUniformScale)
    {
        return false;
    }
    else if (lhsIsIdentity && rhsIsIdentity)
    {
        return true;
    }
    else if (lhsIsRotationOrScaleMatrix && rhsIsRotationOrScaleMatrix)
    {
        if (lhsIsUniformScale && rhsIsUniformScale)
        {
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) &&
                Mathematics::Math<Real>::Approximate(lhs.GetUniformScale(), rhs.GetUniformScale(), epsilon) &&
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
            if (Approximate(lhs.GetRotate(), rhs.GetRotate(), epsilon) && Approximate(lhs.GetScale(), rhs.GetScale(), epsilon) && Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
                return true;
            else
                return false;
        }
    }
    else
    {
        if (Approximate(lhs.GetMatrix(), rhs.GetMatrix(), epsilon) && Approximate(lhs.GetTranslate(), rhs.GetTranslate(), epsilon))
            return true;
        else
            return false;
    }
}

template <typename Real>
std::ostream& Rendering::operator<<(std::ostream& out, const Transform<Real>& transform)
{
    if (transform.IsRotationOrScaleMatrix())
    {
        out << "Rotate:" << transform.GetRotate() << "��";
        out << "Translate:" << transform.GetTranslate() << "��";
        out << "Scale:" << transform.GetScale() << "��";
    }
    else
    {
        out << "Rotate:" << transform.GetMatrix() << "��";
        out << "Translate:" << transform.GetTranslate() << "��";
    }

    return out;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_DETAIL_H
