//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/06 10:47)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_ACHIEVE_H
#define RENDERING_DATA_TYPES_TRANSFORM_ACHIEVE_H

#include "Transform.h"
#include "Detail/TransformImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Mathematics/Algebra/MatrixDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)  // 导出类允许默认构造函数抛出异常。
template <typename Real>
Rendering::Transform<Real>::Transform()
    : m_Impl{ std::make_shared<ImplType>() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

template <typename Real>
void Rendering::Transform<Real>::Copy()
{
    static_assert(std::is_same_v<ClassShareType::NonConstCopyMember, CoreTools::TrueType>, "It is not allowed to define the Copy function used for copy delayed.");
    RENDERING_CLASS_IS_VALID_1;

    if (1 < m_Impl.use_count())
    {
        m_Impl = std::make_shared<ImplType>(*m_Impl);
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Rendering::Transform<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Rendering::Transform<Real>::MakeIdentity()
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->MakeIdentity();
}

template <typename Real>
void Rendering::Transform<Real>::MakeUnitScale()
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->MakeUnitScale();
}

template <typename Real>
bool Rendering::Transform<Real>::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsIdentity();
}

template <typename Real>
bool Rendering::Transform<Real>::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsRotationOrScaleMatrix();
}

template <typename Real>
bool Rendering::Transform<Real>::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsUniformScale();
}

template <typename Real>
void Rendering::Transform<Real>::SetRotate(const Matrix& rotate)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetRotate(rotate);
}

template <typename Real>
void Rendering::Transform<Real>::SetMatrix(const Matrix& matrix)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetMatrix(matrix);
}

template <typename Real>
void Rendering::Transform<Real>::SetTranslate(const APoint& translate)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetTranslate(translate);
}

template <typename Real>
void Rendering::Transform<Real>::SetScale(const APoint& scale)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetScale(scale);
}

template <typename Real>
void Rendering::Transform<Real>::SetUniformScale(Real scale)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetUniformScale(scale);
}

template <typename Real>
const typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetRotate() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRotate();
}

template <typename Real>
const typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrix();
}

template <typename Real>
const typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTranslate();
}

template <typename Real>
const typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::GetScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetScale();
}

template <typename Real>
Real Rendering::Transform<Real>::GetUniformScale() const noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetUniformScale();
}

template <typename Real>
Real Rendering::Transform<Real>::GetNorm() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNorm();
}

template <typename Real>
typename Rendering::Transform<Real>::APoint Rendering::Transform<Real>::operator*(const APoint& point) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return (*m_Impl) * point;
}

template <typename Real>
typename Rendering::Transform<Real>::AVector Rendering::Transform<Real>::operator*(const AVector& vector) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return (*m_Impl) * vector;
}

template <typename Real>
Rendering::Transform<Real>& Rendering::Transform<Real>::operator*=(const Transform& transform)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    *m_Impl *= (*transform.m_Impl);

    return *this;
}

template <typename Real>
const typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetHomogeneousMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetHomogeneousMatrix();
}

template <typename Real>
const typename Rendering::Transform<Real>::Matrix Rendering::Transform<Real>::GetInverseMatrix(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetInverseMatrix(epsilon);
}

template <typename Real>
const Rendering::Transform<Real> Rendering::Transform<Real>::GetInverseTransform(float epsilon) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    Transform<Real> transform{};

    *transform.m_Impl = m_Impl->GetInverseTransform(epsilon);

    return transform;
}

template <typename Real>
int Rendering::Transform<Real>::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetStreamingSize();
}

template <typename Real>
void Rendering::Transform<Real>::ReadAggregate(CoreTools::BufferSource& source)
{
    IMPL_NON_CONST_COPY_MEMBER_FUNCTION_STATIC_ASSERT;

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
            auto scale = Math::GetValue(0);
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

#endif  // RENDERING_DATA_TYPES_TRANSFORM_ACHIEVE_H
