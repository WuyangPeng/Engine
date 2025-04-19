///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 11:17)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H

#include "Vector3Detail.h"
#include "Vector3Orthonormalize.h"
#include "Vector3Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Orthonormalize<Real, Robust>::Vector3Orthonormalize(const Vector3Type& uVector, const Vector3Type& vVector, const Vector3Type& wVector, const Real epsilon)
    : uVector{ uVector }, vVector{ vVector }, wVector{ wVector }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3Orthonormalize<Real, Robust>::Vector3Orthonormalize(const ContainerType& vectors, const Real epsilon)
    : uVector{ vectors.at(Vector3Type::xIndex) }, vVector{ vectors.at(Vector3Type::yIndex) }, wVector{ vectors.at(Vector3Type::zIndex) }, epsilon{ epsilon }
{
    Generate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
void Mathematics::Vector3Orthonormalize<Real, Robust>::Generate()
{
    /// �����������v0��v1��v2����Gram-Schmidt������������ʸ��u0��u1��u2���£�
    ///   u0 = v0 / |v0|
    ///   u1 = (v1 - (u0 * v1)u0) / |v1 - (u0 * v1)u0|
    ///   u2 = (v2 - (u0 * v2)u0 - (u1 * v2)u1) / |v2 - (u0 * v2)u0 - (u1 * v2)u1|
    ///
    /// ����|A|��ʾ����A�ĳ��Ⱥ�A * B��ʾ����A��B�ĵ��

    // ���� u0
    if constexpr (Robust)
    {
        uVector.RobustNormalize(epsilon);
    }
    else
    {
        uVector.Normalize(epsilon);
    }

    // ���� u1
    const auto dotUV = Vector3ToolsType::DotProduct(uVector, vVector);

    MATHEMATICS_ASSERTION_1(epsilon < MathType::FAbs(dotUV), "�������������������޹صģ�");

    vVector -= dotUV * uVector;
    if constexpr (Robust)
    {
        vVector.RobustNormalize(epsilon);
    }
    else
    {
        vVector.Normalize(epsilon);
    }

    // ���� u2
    const auto dotVW = Vector3ToolsType::DotProduct(vVector, wVector);
    const auto dotUW = Vector3ToolsType::DotProduct(uVector, wVector);

    wVector -= dotUW * uVector + dotVW * vVector;
    if constexpr (Robust)
    {
        wVector.RobustNormalize(epsilon);
    }
    else
    {
        wVector.Normalize(epsilon);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real> bool Mathematics::Vector3Orthonormalize<Real, Robust>::IsValid() const noexcept
{
    try
    {
        if (MathType::FAbs(Vector3ToolsType::DotProduct(uVector, vVector)) <= epsilon &&
            MathType::FAbs(Vector3ToolsType::DotProduct(uVector, wVector)) <= epsilon &&
            MathType::FAbs(Vector3ToolsType::DotProduct(vVector, wVector)) <= epsilon &&
            uVector.IsNormalize(epsilon) &&
            vVector.IsNormalize(epsilon) &&
            wVector.IsNormalize(epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetUVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uVector;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetVVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vVector;
}

template <typename Real, bool Robust>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::Vector3Orthonormalize<Real, Robust>::GetWVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return wVector;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_ORTHONORMALIZE_ACHIEVE_H