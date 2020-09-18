//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/07 15:58)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_IMPL_DETAIL_H
#define RENDERING_DATA_TYPES_TRANSFORM_IMPL_DETAIL_H

#include "TransformImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Mathematics/Algebra/MatrixDetail.h"

template <typename Real>
Rendering::TransformImpl<Real>::TransformImpl() noexcept
    : m_TransformMatrix{}, m_RotationOrGeneralMatrix{ Mathematics::MatrixInitType::Identity },
      m_Translate{}, m_Scale{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) },
      m_InverseMatrix{ Mathematics::MatrixInitType::Identity }, m_InverseNeedsUpdate{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Rendering::TransformImpl<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Rendering::TransformImpl<Real>::MakeIdentity() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_RotationOrGeneralMatrix.MakeIdentity();

    m_Translate = APoint{};
    m_Scale = APoint{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };

    m_TransformMatrix.MakeIdentity();

    m_InverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::TransformImpl<Real>::MakeUnitScale() noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    m_Scale = APoint{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) };

    m_TransformMatrix.MakeUnitScale(m_RotationOrGeneralMatrix);

    m_InverseNeedsUpdate = true;
}

template <typename Real>
bool Rendering::TransformImpl<Real>::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.IsIdentity();
}

template <typename Real>
bool Rendering::TransformImpl<Real>::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.IsRotationOrScaleMatrix();
}

template <typename Real>
bool Rendering::TransformImpl<Real>::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.IsUniformScale();
}

template <typename Real>
void Rendering::TransformImpl<Real>::SetRotate(const Matrix& rotate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_RotationOrGeneralMatrix = rotate;

    m_TransformMatrix.SetRotate(m_RotationOrGeneralMatrix, m_Scale);

    m_InverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::TransformImpl<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_RotationOrGeneralMatrix = matrix;

    m_TransformMatrix.SetMatrix(m_RotationOrGeneralMatrix);

    m_InverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::TransformImpl<Real>::SetTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_Translate = translate;

    m_TransformMatrix.SetTranslate(m_Translate);

    m_InverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::TransformImpl<Real>::SetScale(const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(Approximate(scale, APoint{}, Math::GetZeroTolerance()), "scale不能为零。\n");

    m_Scale = scale;

    m_TransformMatrix.SetScale(m_RotationOrGeneralMatrix, m_Scale);

    m_InverseNeedsUpdate = true;
}

template <typename Real>
void Rendering::TransformImpl<Real>::SetUniformScale(Real scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    m_Scale = APoint{ scale, scale, scale };

    m_TransformMatrix.SetUniformScale(m_RotationOrGeneralMatrix, m_Scale.GetX());

    m_InverseNeedsUpdate = true;
}

template <typename Real>
typename const Rendering::TransformImpl<Real>::Matrix Rendering::TransformImpl<Real>::GetRotate() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_2(m_TransformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");

    return m_RotationOrGeneralMatrix;
}

template <typename Real>
const typename Rendering::TransformImpl<Real>::Matrix Rendering::TransformImpl<Real>::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_RotationOrGeneralMatrix;
}

template <typename Real>
const typename Rendering::TransformImpl<Real>::APoint Rendering::TransformImpl<Real>::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Translate;
}

template <typename Real>
const typename Rendering::TransformImpl<Real>::APoint Rendering::TransformImpl<Real>::GetScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_TransformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");

    return m_Scale;
}

template <typename Real>
Real Rendering::TransformImpl<Real>::GetUniformScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(m_TransformMatrix.IsRotationOrScaleMatrix(), "Matrix不是旋转矩阵\n");
    RENDERING_ASSERTION_1(m_TransformMatrix.IsUniformScale(), "Matrix不是单位缩放\n");

    return m_Scale.GetX();
}

template <typename Real>
Real Rendering::TransformImpl<Real>::GetNorm() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (m_TransformMatrix.IsRotationOrScaleMatrix())
    {
        return m_Scale.GetNorm();
    }

    // 一般的矩阵。使用最大行和矩阵规范。光谱标准（特征值的最大绝对值）小于或等于该标准。
    // 因此，此函数返回最大比例的近似值。
    return m_RotationOrGeneralMatrix.GetNorm();
}

template <typename Real>
typename Rendering::TransformImpl<Real>::APoint Rendering::TransformImpl<Real>::operator*(const APoint& point) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.GetMatrix() * point;
}

template <typename Real>
typename Rendering::TransformImpl<Real>::AVector Rendering::TransformImpl<Real>::operator*(const AVector& vector) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.GetMatrix() * vector;
}

template <typename Real>
Rendering::TransformImpl<Real>& Rendering::TransformImpl<Real>::operator*=(const TransformImpl& transform)
{
    RENDERING_CLASS_IS_VALID_9;

    *this = *this * transform;

    return *this;
}

template <typename Real>
const typename Rendering::TransformImpl<Real>::Matrix Rendering::TransformImpl<Real>::GetHomogeneousMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_TransformMatrix.GetMatrix();
}

template <typename Real>
const typename Rendering::TransformImpl<Real>::Matrix Rendering::TransformImpl<Real>::GetInverseMatrix(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (m_InverseNeedsUpdate)
    {
        if (m_TransformMatrix.IsIdentity())
        {
            m_InverseMatrix.MakeIdentity();
        }
        else
        {
            if (m_TransformMatrix.IsRotationOrScaleMatrix())
            {
                if (m_TransformMatrix.IsUniformScale())
                {
                    m_InverseMatrix.SetValue<0>(m_RotationOrGeneralMatrix.GetValue<0>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<1>(m_RotationOrGeneralMatrix.GetValue<4>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<2>(m_RotationOrGeneralMatrix.GetValue<8>() / m_Scale.GetX());

                    m_InverseMatrix.SetValue<4>(m_RotationOrGeneralMatrix.GetValue<1>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<5>(m_RotationOrGeneralMatrix.GetValue<5>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<6>(m_RotationOrGeneralMatrix.GetValue<9>() / m_Scale.GetX());

                    m_InverseMatrix.SetValue<8>(m_RotationOrGeneralMatrix.GetValue<2>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<9>(m_RotationOrGeneralMatrix.GetValue<6>() / m_Scale.GetX());
                    m_InverseMatrix.SetValue<10>(m_RotationOrGeneralMatrix.GetValue<10>() / m_Scale.GetX());
                }
                else
                {
                    // 替换3个倒数分别乘以6和1个倒数。
                    auto scale01 = m_Scale.GetX() * m_Scale.GetY();
                    auto scale02 = m_Scale.GetX() * m_Scale.GetZ();
                    auto scale12 = m_Scale.GetY() * m_Scale.GetZ();
                    const auto scale012 = (scale01 * m_Scale.GetZ());
                    auto inverseScale0 = scale12 / scale012;
                    auto inverseScale1 = scale02 / scale012;
                    auto inverseScale2 = scale01 / scale012;

                    m_InverseMatrix.SetValue<0>(inverseScale0 * m_RotationOrGeneralMatrix.GetValue<0>());
                    m_InverseMatrix.SetValue<1>(inverseScale0 * m_RotationOrGeneralMatrix.GetValue<4>());
                    m_InverseMatrix.SetValue<2>(inverseScale0 * m_RotationOrGeneralMatrix.GetValue<8>());

                    m_InverseMatrix.SetValue<4>(inverseScale1 * m_RotationOrGeneralMatrix.GetValue<1>());
                    m_InverseMatrix.SetValue<5>(inverseScale1 * m_RotationOrGeneralMatrix.GetValue<5>());
                    m_InverseMatrix.SetValue<6>(inverseScale1 * m_RotationOrGeneralMatrix.GetValue<9>());

                    m_InverseMatrix.SetValue<8>(inverseScale2 * m_RotationOrGeneralMatrix.GetValue<2>());
                    m_InverseMatrix.SetValue<9>(inverseScale2 * m_RotationOrGeneralMatrix.GetValue<6>());
                    m_InverseMatrix.SetValue<10>(inverseScale2 * m_RotationOrGeneralMatrix.GetValue<10>());
                }
            }
            else
            {
                m_InverseMatrix = m_RotationOrGeneralMatrix.Invert3x3(epsilon);
            }

            m_InverseMatrix.Plus<3>(-(m_InverseMatrix.GetValue<0>() * m_Translate.GetX() + m_InverseMatrix.GetValue<1>() * m_Translate.GetY() + m_InverseMatrix.GetValue<2>() * m_Translate.GetZ()));

            m_InverseMatrix.Plus<7>(-(m_InverseMatrix.GetValue<4>() * m_Translate.GetX() + m_InverseMatrix.GetValue<5>() * m_Translate.GetY() + m_InverseMatrix.GetValue<6>() * m_Translate.GetZ()));

            m_InverseMatrix.Plus<11>(-(m_InverseMatrix.GetValue<8>() * m_Translate.GetX() + m_InverseMatrix.GetValue<9>() * m_Translate.GetY() + m_InverseMatrix.GetValue<10>() * m_Translate.GetZ()));

            // 对于一个仿射变换，m_Matrix的最后一行总是(0,0,0,1)。所以在构造函数中设置一次。没有必要在这里重置。
        }

        m_InverseNeedsUpdate = false;
    }

    return m_InverseMatrix;
}

template <typename Real>
const Rendering::TransformImpl<Real> Rendering::TransformImpl<Real>::GetInverseTransform(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (m_TransformMatrix.IsIdentity())
    {
        return TransformImpl<Real>{};
    }

    TransformImpl inverse{};
    APoint inverseTransform{};
    if (m_TransformMatrix.IsRotationOrScaleMatrix())
    {
        const auto inverseRotation = m_RotationOrGeneralMatrix.Transpose();
        inverse.SetRotate(inverseRotation);
        if (m_TransformMatrix.IsUniformScale())
        {
            const auto inverseScale = Math::GetValue(1) / m_Scale.GetX();
            inverse.SetUniformScale(inverseScale);
            inverseTransform = -inverseScale * (inverseRotation * m_Translate);
        }
        else
        {
            // Transform是Y = M * X + T，M = R * S，逆方向是X = S^{-1} * R^t * (Y - T)，
            // 无法表示为X = (R * S) * Y + T，只能表示为X = (S * R) * Y + T。

            const APoint inverseScale{ Math::GetValue(1) / m_Scale.GetX(), Math::GetValue(1) / m_Scale.GetY(), Math::GetValue(1) / m_Scale.GetZ() };
            inverse.SetScale(inverseScale);
            inverseTransform = inverseRotation * m_Translate;
            inverseTransform[0] *= -inverseScale.GetX();
            inverseTransform[1] *= -inverseScale.GetY();
            inverseTransform[2] *= -inverseScale.GetZ();
        }
    }
    else
    {
        const auto inverseMatrix = m_RotationOrGeneralMatrix.Invert3x3(epsilon);

        inverse.SetMatrix(inverseMatrix);
        inverseTransform = -(inverseMatrix * m_Translate);
    }

    inverse.SetTranslate(inverseTransform);

    return inverse;
}

template <typename Real>
int Rendering::TransformImpl<Real>::GetStreamingSize() const noexcept
{
    const auto isIdentity = m_TransformMatrix.IsIdentity();
    const auto isRotationOrScaleMatrix = m_TransformMatrix.IsRotationOrScaleMatrix();
    const auto isUniformScale = m_TransformMatrix.IsUniformScale();

    auto size = CORE_TOOLS_STREAM_SIZE(isIdentity) + CORE_TOOLS_STREAM_SIZE(isRotationOrScaleMatrix) + CORE_TOOLS_STREAM_SIZE(isUniformScale);

    if (isIdentity)
    {
        return size;
    }
    else if (isRotationOrScaleMatrix)
    {
        if (isUniformScale)
        {
            size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
            size += CORE_TOOLS_STREAM_SIZE(m_Scale.GetX());
            size += MATHEMATICS_STREAM_SIZE(m_Translate);

            return size;
        }
        else
        {
            size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
            size += MATHEMATICS_STREAM_SIZE(m_Scale);
            size += MATHEMATICS_STREAM_SIZE(m_Translate);

            return size;
        }
    }
    else
    {
        size += MATHEMATICS_STREAM_SIZE(m_RotationOrGeneralMatrix);
        size += MATHEMATICS_STREAM_SIZE(m_Translate);

        return size;
    }
}

template <typename Real>
const Rendering::TransformImpl<Real> Rendering::operator*(const TransformImpl<Real>& lhs, const TransformImpl<Real>& rhs)
{
    if (lhs.IsIdentity())
    {
        return rhs;
    }

    if (rhs.IsIdentity())
    {
        return lhs;
    }

    TransformImpl<Real> product{};

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

    // 在所有剩余的情况下，矩阵不能写成R * S * X + T。
    const auto matrixA = (lhs.IsRotationOrScaleMatrix() ? lhs.GetMatrix().TimesDiagonal(lhs.GetScale()) : lhs.GetMatrix());
    const auto matrixB = (rhs.IsRotationOrScaleMatrix() ? rhs.GetMatrix().TimesDiagonal(rhs.GetScale()) : rhs.GetMatrix());

    product.SetMatrix(matrixA * matrixB);
    product.SetTranslate(matrixA * rhs.GetTranslate() + lhs.GetTranslate());

    return product;
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_IMPL_DETAIL_H
