///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/27 11:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_DETAIL_H

#include "PolynomialRootsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/PolynomialDivideDetail.h"

#include <gsl/gsl_util>

template <typename Real>
Mathematics::PolynomialRootsImpl<Real>::PolynomialRootsImpl(Real epsilon)
    : m_Count{ 0 },
      m_MaxRoot{ 4 },  // Ĭ��֧��ά�� <= 4
      m_Root(m_MaxRoot),
      m_Epsilon{ epsilon },
      m_MaxIterations{ 128 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Epsilon && 0 <= m_Count && m_Root.size() == gsl::narrow_cast<size_t>(m_MaxRoot) && 0 <= m_MaxIterations)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::SetMaxIterations(int maxIterations) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_MaxIterations = maxIterations;
}

template <typename Real>
int Mathematics::PolynomialRootsImpl<Real>::GetCount() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Count;
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetRoot(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Root.at(index);
}

template <typename Real>
typename const Mathematics::PolynomialRootsImpl<Real>::ContainerConstIter Mathematics::PolynomialRootsImpl<Real>::GetBegin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Root.begin();
}

template <typename Real>
typename const Mathematics::PolynomialRootsImpl<Real>::ContainerConstIter Mathematics::PolynomialRootsImpl<Real>::GetEnd() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Root.end();
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::SetRoot(int index, Real value)
{
    m_Root.at(index) = value;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindAlgebraic(Real constant, Real once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (m_Epsilon <= Math::FAbs(once))
    {
        SetRoot(0, -constant / once);
        m_Count = 1;

        return true;
    }
    else
    {
        m_Count = 0;
        return false;
    }
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetBound(Real constant, Real once)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(once) <= m_Epsilon)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʽ�Ǻ㶨�ģ�Լ������Ч��"s));
    }

    auto maxValue = Math::FAbs(constant) / once;

    return Math::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindAlgebraic(Real constant, Real once, Real secondary)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(secondary) <= m_Epsilon)
    {
        // ������һ�ε�
        return FindAlgebraic(constant, once);
    }

    auto discriminant = once * once - Math::GetValue(4) * constant * secondary;
    if (Math::FAbs(discriminant) <= m_Epsilon)
    {
        discriminant = Math::GetValue(0);
    }

    if (discriminant < Math::GetValue(0))
    {
        m_Count = 0;
        return false;
    }

    auto lhs = Math::GetRational(1, 2) / secondary;

    if (Math::GetValue(0) < discriminant)
    {
        discriminant = Math::Sqrt(discriminant);

        SetRoot(0, lhs * (-once - discriminant));
        SetRoot(1, lhs * (-once + discriminant));
        m_Count = 2;
    }
    else
    {
        SetRoot(0, -lhs * once);
        m_Count = 1;
    }

    return true;
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetBound(Real constant, Real once, Real secondary)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(secondary) <= m_Epsilon)
    {
        // ������һ�ε�
        if (FindAlgebraic(constant, once))
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            return m_Root[0];
#include STSTEM_WARNING_POP
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("Լ������Ч�ġ�"s));
        }
    }

    auto value0 = Math::FAbs(constant) / secondary;
    auto value1 = Math::FAbs(once) / secondary;
    auto maxValue = (value1 <= value0 ? value0 : value1);

    return Math::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(thrice) <= m_Epsilon)
    {
        // �����Ƕ��ε�
        return FindAlgebraic(constant, once, secondary);
    }

    // ȷ������ʽ��һ, x^3 + secondary * x^2 + once * x + constant = 0.
    constant /= thrice;
    once /= thrice;
    secondary /= thrice;

    // ת��Ϊy^3 + a * y + b = 0 ����x = y - c2 / 3��
    constexpr auto third = Math::GetRational(1, 3);
    constexpr auto twentySeventh = Math::GetRational(1, 27);
    auto offset = third * secondary;
    auto a = once - secondary * offset;
    auto b = constant + secondary * (Math::GetValue(2) * secondary * secondary - Math::GetValue(9) * once) * twentySeventh;

    auto halfB = (Math::GetRational(1, 2)) * b;

    auto discriminant = halfB * halfB + a * a * a * twentySeventh;

    if (Math::FAbs(discriminant) <= m_Epsilon)
    {
        discriminant = Math::GetValue(0);

        auto halfBPowThird = Math::CubeRoot(halfB);

        SetRoot(0, Math::GetValue(2) * halfBPowThird - offset);
        SetRoot(1, -halfBPowThird - offset);
        m_Count = 2;
    }
    else if (Math::GetValue(0) < discriminant)  // 1ʵ,2���
    {
        discriminant = Math::Sqrt(discriminant);
        auto discriminantMinusHalfB = -halfB + discriminant;
        auto root = Math::CubeRoot(discriminantMinusHalfB);

        auto negativeDiscriminantMinusHalfB = -halfB - discriminant;
        root += Math::CubeRoot(negativeDiscriminantMinusHalfB);
        root -= offset;
        SetRoot(0, root);
        m_Count = 1;
    }
    else  // if (discr <  Math::sm_Zero)
    {
        auto dist = Math::Sqrt(-third * a);
        auto angle = third * Math::ATan2(Math::Sqrt(-discriminant), -halfB);
        auto cosValue = Math::Cos(angle);
        auto sinValue = Math::Sin(angle);
        SetRoot(0, Math::GetValue(2) * dist * cosValue - offset);
        SetRoot(1, -dist * (cosValue + Math::GetSqrt3() * sinValue) - offset);
        SetRoot(2, -dist * (cosValue - Math::GetSqrt3() * sinValue) - offset);
        m_Count = 3;
    }

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, bool doBalancing, Real tolerance, bool isUseCompanion)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(thrice) <= m_Epsilon)
    {
        // �����Ƕ��ε�
        return FindAlgebraic(constant, once, secondary);
    }

    // ȷ������ʽ��һ, x^3 + secondary * x^2 + once * x + constant = 0
    constant /= thrice;
    once /= thrice;
    secondary /= thrice;

    // ����3��3Эͬ����
    VariableMatrix matrix{ 3, 3 };  // ��ʼ��Ϊ0��
    matrix(1, 0) = Math::GetValue(1);
    matrix(2, 1) = Math::GetValue(1);
    matrix(0, 2) = -constant;
    matrix(1, 2) = -once;
    matrix(2, 2) = -secondary;

    if (doBalancing)
    {
        if (isUseCompanion)
        {
            BalanceCompanion3(matrix, tolerance);
        }
        else
        {
            Balance3(matrix, tolerance);
        }
    }

    return QRIteration3(matrix);
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::BalanceCompanion3(VariableMatrix& matrix, Real tolerance)
{
    auto a10 = Math::FAbs(matrix(1, 0));
    auto a21 = Math::FAbs(matrix(2, 1));
    auto a02 = Math::FAbs(matrix(0, 2));
    auto a12 = Math::FAbs(matrix(1, 2));
    auto a22 = Math::FAbs(matrix(2, 2));

    for (auto i = 0; i < sm_BalanceCompanionIterationMax; ++i)
    {
        // ���� ��/�� 0
        auto rowNorm = a02;
        auto colomnNorm = a10;
        auto scale = Math::Sqrt(colomnNorm / rowNorm);
        a02 *= scale;
        a10 = a02;

        // ���� ��/�� 1
        rowNorm = (a12 <= a10 ? a10 : a12);
        colomnNorm = a21;
        scale = Math::Sqrt(colomnNorm / rowNorm);
        a10 *= scale;
        a12 *= scale;
        a21 /= scale;

        // ���� ��/�� 2
        rowNorm = (a22 <= a21 ? a21 : a22);
        colomnNorm = (a12 <= a02 ? a02 : a12);
        if (colomnNorm < a22)
        {
            colomnNorm = a22;
        }
        scale = Math::Sqrt(colomnNorm / rowNorm);

        a21 *= scale;
        a02 /= scale;
        a12 /= scale;

        if (IsBalancedCompanion3(a10, a21, a02, a12, a22, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(i != sm_BalanceCompanionIterationMax - 1, "������������\n");
    }

    matrix(1, 0) = (Math::GetValue(0) <= matrix(1, 0) ? a10 : -a10);
    matrix(2, 1) = (Math::GetValue(0) <= matrix(2, 1) ? a21 : -a21);
    matrix(0, 2) = (Math::GetValue(0) <= matrix(0, 2) ? a02 : -a02);
    matrix(1, 2) = (Math::GetValue(0) <= matrix(1, 2) ? a12 : -a12);
    matrix(2, 2) = (Math::GetValue(0) <= matrix(2, 2) ? a22 : -a22);
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::IsBalancedCompanion3(Real a10, Real a21, Real a02, Real a12, Real a22, Real tolerance) noexcept
{
    // ��/�� 0
    auto rowNorm = a02;
    auto colomnNorm = a10;
    auto test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // ��/�� 1
    rowNorm = (a12 <= a10 ? a10 : a12);
    colomnNorm = a21;
    test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // ��/�� 2
    rowNorm = (a22 <= a21 ? a21 : a22);
    colomnNorm = (a12 <= a02 ? a02 : a12);
    if (colomnNorm < a22)
    {
        colomnNorm = a22;
    }
    test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);

    return test <= tolerance;
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::QRIteration3(VariableMatrix& matrix)
{
    VariableLengthVector variableLengthVector{ 3 };

    for (auto i = 0; i < m_MaxIterations; ++i)
    {
        auto rhs = m_Epsilon * (Math::FAbs(matrix(0, 0)) + Math::FAbs(matrix(1, 1)));

        if (Math::FAbs(matrix(1, 0)) <= rhs)
        {
            // mat(0,0)��һ���������Ӿ���Ķ��η��̡�
            auto trace = matrix(1, 1) + matrix(2, 2);
            auto det = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);

            if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
            {
                return false;
            }
            SetRoot(m_Count, matrix(0, 0));
            ++m_Count;

            return true;
        }

        rhs = m_Epsilon * (Math::FAbs(matrix(1, 1)) + Math::FAbs(matrix(2, 2)));

        if (Math::FAbs(matrix(2, 1)) <= rhs)
        {
            // mat(2,2)��һ�����������Ӿ���Ķ��η��̡�
            auto trace = matrix(0, 0) + matrix(1, 1);
            auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
            if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
            {
                return false;
            }

            SetRoot(m_Count, matrix(2, 2));
            ++m_Count;

            return true;
        }

        FrancisQRStep(matrix, variableLengthVector);
    }

    // �������Ͻ������ζ���ʽ������һ��ʵ�����������������������������ô�죿
    // һЩʵ�������������ʽ������һ��˫�����㷨�������ٶ�����
    // Ҳ��һ������Ŷ���kick��ϵͳ�е�һ��λ���ܻ���Ч��

    MATHEMATICS_ASSERTION_4(false, "����������\n");

    // ���ڣ�������С�ĴζԽ���ȥ�������
    if (Math::FAbs(matrix(1, 0)) <= Math::FAbs(matrix(2, 1)))
    {
        // mat(0,0)��һ�����������Ӿ���Ķ��η��̡�
        auto trace = matrix(1, 1) + matrix(2, 2);
        auto det = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
        if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
        {
            return false;
        }

        SetRoot(m_Count, matrix(0, 0));
        ++m_Count;
    }
    else
    {
        // mat(2,2)��һ�����������Ӿ���Ķ��η��̡�
        auto trace = matrix(0, 0) + matrix(1, 1);
        auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
        if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
        {
            return false;
        }

        SetRoot(m_Count, matrix(2, 2));
        ++m_Count;
    }

    return true;
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::FrancisQRStep(VariableMatrix& hessenbergMatrix, VariableLengthVector& vector)
{
    // ����һ��n��nδ��ԭ����Hessenberg����H��β��2��2�������������ֵa1��a2��
    // ���� H��Z^T * H * Z����Z = P(1) * ... * P(n-2)��Householder�����
    // Z^T*(H-a1*I)*(H-a2*I)�������ǡ�
    // assert:  H��δ��ԭ����Hessenberg�� n >= 3

    // ����(H - a1 * I) * (H - a2 * I)�ĵ�һ�С�
    const auto rowsNumber = hessenbergMatrix.GetRowsNumber();
    auto trace = hessenbergMatrix(rowsNumber - 2, rowsNumber - 2) + hessenbergMatrix(rowsNumber - 1, rowsNumber - 1);
    auto det = hessenbergMatrix(rowsNumber - 2, rowsNumber - 2) * hessenbergMatrix(rowsNumber - 1, rowsNumber - 1) -
               hessenbergMatrix(rowsNumber - 2, rowsNumber - 1) * hessenbergMatrix(rowsNumber - 1, rowsNumber - 2);
    Vector3D uVector{ hessenbergMatrix(0, 0) * hessenbergMatrix(1, 1) + hessenbergMatrix(0, 1) * hessenbergMatrix(1, 0) - trace * hessenbergMatrix(0, 0) + det,
                      hessenbergMatrix(1, 0) * (hessenbergMatrix(0, 0) + hessenbergMatrix(1, 1) - trace),
                      hessenbergMatrix(1, 0) * hessenbergMatrix(2, 1) };

    // ����H ʹ�� P(0) * H * P(0)^T.
    auto vVector = GetHouseholderVector(3, uVector);
    PremultiplyHouseholder(hessenbergMatrix, vector, 0, 2, 0, rowsNumber - 1, 3, vVector);
    PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rowsNumber - 1, 0, 2, 3, vVector);

    for (auto i = 1; i <= rowsNumber - 3; ++i)
    {
        // ����H ʹ�� P(i) * H * P(i)^T.
        uVector[0] = hessenbergMatrix(i, i - 1);
        uVector[1] = hessenbergMatrix(i + 1, i - 1);
        uVector[2] = hessenbergMatrix(i + 2, i - 1);
        vVector = GetHouseholderVector(3, uVector);

        // �з�Χ����ҪΪ0 �� n - 1����Ϊ���ͼ�������ھ���H
        PremultiplyHouseholder(hessenbergMatrix, vector, i, i + 2, i - 1, rowsNumber - 1, 3, vVector);

        // �з�Χ����ҪΪ0 �� n - 1����Ϊ���ͼ�������ھ���H
        auto rMax = i + 3;
        if (rowsNumber <= rMax)
        {
            rMax = rowsNumber - 1;
        }
        PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rMax, i, i + 2, 3, vVector);
    }

    // ����H ʹ��P(n-2)*H*P(n-2)^T.
    uVector[0] = hessenbergMatrix(rowsNumber - 2, rowsNumber - 3);
    uVector[1] = hessenbergMatrix(rowsNumber - 1, rowsNumber - 3);
    vVector = GetHouseholderVector(2, uVector);

    // �з�Χ����ҪΪ0 �� n - 1����Ϊ���ͼ�������ھ���H
    PremultiplyHouseholder(hessenbergMatrix, vector, rowsNumber - 2, rowsNumber - 1, rowsNumber - 3, rowsNumber - 1, 2, vVector);
    PostmultiplyHouseholder(hessenbergMatrix, vector, 0, rowsNumber - 1, rowsNumber - 2, rowsNumber - 1, 2, vVector);
}

// private
template <typename Real>
typename const Mathematics::PolynomialRootsImpl<Real>::Vector3D Mathematics::PolynomialRootsImpl<Real>::GetHouseholderVector(int size, const Vector3D& uVector)
{
    Vector3D vVector{};

    // Householder����V��
    // ����һ��������U������ʸ��V������
    // ʹV[0] = 1 �� (I - 2 * V * V^T / |V|^2) * U �ǳ���һ��ֲ����ⶼ���㡣
    // ����P = I - 2 * V * V^T /| V|^2 ��һ��Householder�任��һ���������

    auto length = Math::GetValue(0);

    for (auto i = 0; i < size; ++i)
    {
        length += uVector[i] * uVector[i];
    }
    length = Math::Sqrt(length);

    if (m_Epsilon < length)
    {
        auto inv = Math::GetValue(1) / (uVector[0] + Math::Sign(uVector[0]) * length);
        vVector[0] = Math::GetValue(1);
        for (auto i = 1; i < size; ++i)
        {
            vVector[i] = inv * uVector[i];
        }
    }
    else
    {
        // uVector�����������κ�����������
        vVector[0] = Math::GetValue(1);
        for (int i = 1; i < size; ++i)
        {
            vVector[i] = Math::GetValue(0);
        }
    }

    return vVector;
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::PremultiplyHouseholder(VariableMatrix& matrix, VariableLengthVector& variableLengthVector, int rowMin, int rowMax, int colunmMin, int colunmMax, int vSize, const Vector3D& vVector)
{
    // HouseholderԤ�ˣ������ľ���A��m��1ʸ��V����V[0]= 1��
    // ��S��A���Ӿ���m�е�rmin <= r <= m + rmin - 1���е���cmin <= c <= cmax��
    // ��P * S����S���� P = I - 2 * V * V^T / |V|^2��

    const auto subRows = rowMax - rowMin + 1;
    const auto subColunms = colunmMax - colunmMin + 1;

    auto sqrLen = Math::GetValue(0);
    for (auto i = 0; i < vSize; ++i)
    {
        sqrLen += vVector[i] * vVector[i];
    }

    auto beta = Math::GetValue(-2) / sqrLen;
    for (auto colunm = 0; colunm < subColunms; ++colunm)
    {
        variableLengthVector[colunm] = Math::GetValue(0);
        for (auto row = 0; row < subRows; ++row)
        {
            variableLengthVector[colunm] += vVector[row] * matrix(rowMin + row, colunmMin + colunm);
        }
        variableLengthVector[colunm] *= beta;
    }

    for (auto row = 0; row < subRows; ++row)
    {
        for (auto colunm = 0; colunm < subColunms; ++colunm)
        {
            matrix(rowMin + row, colunmMin + colunm) += vVector[row] * variableLengthVector[colunm];
        }
    }
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::PostmultiplyHouseholder(VariableMatrix& matrix, VariableLengthVector& variableLengthVector, int rowMin, int rowMax,
                                                                     int colunmMin, int colunmMax, int vSize, const Vector3D& vVector)
{
    // HouseholderԤ�ˣ������ľ���A��m��1ʸ��V����V[0]= 1��
    // ��S��A���Ӿ���m�е�rmin <= r <= m + rmin - 1���е���cmin <= c <= cmax��
    // ��P * S����S���� P = I - 2 * V * V^T / |V|^2��

    const auto subRows = rowMax - rowMin + 1;
    const auto subColunms = colunmMax - colunmMin + 1;

    auto sqrLen = Math::GetValue(0);
    for (auto i = 0; i < vSize; ++i)
    {
        sqrLen += vVector[i] * vVector[i];
    }

    auto beta = Math::GetValue(-2) / sqrLen;
    for (auto row = 0; row < subRows; ++row)
    {
        variableLengthVector[row] = Math::GetValue(0);
        for (auto colunm = 0; colunm < subColunms; ++colunm)
        {
            variableLengthVector[row] += matrix(rowMin + row, colunmMin + colunm) * vVector[colunm];
        }
        variableLengthVector[row] *= beta;
    }

    for (auto row = 0; row < subRows; ++row)
    {
        for (auto colunm = 0; colunm < subColunms; ++colunm)
        {
            matrix(rowMin + row, colunmMin + colunm) += variableLengthVector[row] * vVector[colunm];
        }
    }
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(thrice) <= m_Epsilon)
    {
        // ����ʽ�Ƕ��Ρ�
        return GetBound(constant, once, secondary);
    }

    auto invThrice = Math::GetValue(1) / thrice;
    auto maxValue = Math::FAbs(constant) * invThrice;

    auto onceProduct = Math::FAbs(once) * invThrice;
    if (maxValue < onceProduct)
    {
        maxValue = onceProduct;
    }

    auto secondaryProduct = Math::FAbs(secondary) * invThrice;
    if (maxValue < secondaryProduct)
    {
        maxValue = secondaryProduct;
    }

    return Math::GetValue(1) + maxValue;
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::Balance3(VariableMatrix& matrix, Real tolerance)
{
    for (auto loop = 0; loop < sm_BalanceIterationMax; ++loop)
    {
        for (auto index = 0; index < 3; ++index)
        {
            auto rowNorm = GetRowNorm(index, matrix);
            auto colomnNorm = GetColomnNorm(index, matrix);
            auto scale = Math::Sqrt(colomnNorm / rowNorm);
            auto invScale = Math::GetValue(1) / scale;
            ScaleRow(index, scale, matrix);
            ScaleColomn(index, invScale, matrix);
        }

        if (IsBalanced3(matrix, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(loop != sm_BalanceIterationMax - 1, "����������\n");
    }
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::IsBalanced3(VariableMatrix& matrix, Real tolerance)
{
    for (auto i = 0; i < 3; ++i)
    {
        auto rowNorm = GetRowNorm(i, matrix);
        auto colomnNorm = GetColomnNorm(i, matrix);
        auto test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
        if (tolerance < test)
        {
            return false;
        }
    }
    return true;
}

// private
template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetRowNorm(int row, VariableMatrix& matrix)
{
    auto norm = Math::GetValue(0);
    for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
    {
        auto absValue = Math::FAbs(matrix(row, column));
        if (norm < absValue)
        {
            norm = absValue;
        }
    }
    return norm;
}

// private
template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetColomnNorm(int colomn, VariableMatrix& matrix)
{
    auto norm = Math::GetValue(0);
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        auto absValue = Math::FAbs(matrix(row, colomn));
        if (norm < absValue)
        {
            norm = absValue;
        }
    }
    return norm;
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::ScaleRow(int row, Real scale, VariableMatrix& matrix)
{
    for (auto column = 0; column < matrix.GetColumnsNumber(); ++column)
    {
        matrix(row, column) *= scale;
    }
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::ScaleColomn(int column, Real scale, VariableMatrix& matrix)
{
    for (auto row = 0; row < matrix.GetRowsNumber(); ++row)
    {
        matrix(row, column) *= scale;
    }
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::SpecialCubic(Real thrice, Real once, Real constant) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // �� thrice * r^3 + once * r = constant ������thrice > 0��once > 0��
    //
    // �� r = D * sinh(u) ���� D = sqrt(4 * once/(3 * thrice))
    // sinh(3 * u) = 4 * [sinh(u)]^3 + 3 * sinh(u) = E ���� E = 4 * C / (A * D^3).
    // sinh(3 * u) = E �н� u = (1 / 3)*log(E + sqrt(E^2 + 1))
    // �⵼�� sinh(u) = ((E + sqrt(E^2 + 1))^{1 / 3} - (E + sqrt(E^2 + 1))^{-1 / 3}) / 2.
    // ���,  r = D*((E + sqrt(E^2 + 1))^{1 / 3} - (E + sqrt(E^2 + 1))^{-1 / 3}) / 2

    auto sqrt = Math::Sqrt(Math::GetValue(4) * once / (Math::GetValue(3) * thrice));
    auto value = Math::GetValue(4) * constant / (thrice * sqrt * sqrt * sqrt);
    auto pow = Math::CubeRoot(value + Math::Sqrt(value * value + Math::GetValue(1)));
    auto root = (Math::GetRational(1, 2) * sqrt * (pow - (Math::GetValue(1) / pow)));

    return root;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindAlgebraic(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(quartic) <= m_Epsilon)
    {
        // ����ʽ�����ε�
        return FindAlgebraic(constant, once, secondary, thrice);
    }

    // ʹ����ʽ��һ, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant.
    constant /= quartic;
    once /= quartic;
    secondary /= quartic;
    thrice /= quartic;

    // ���������ζ���ʽ y^3 + newSecondary * y^2 + newOnce * y + newConstant = 0.
    auto newConstant = -thrice * thrice * constant + Math::GetValue(4) * secondary * constant - once * once;
    auto newOnce = thrice * once - Math::GetValue(4) * constant;
    auto newSecondary = -secondary;
    // �������ٲ���һ����
    if (!FindAlgebraic(newConstant, newOnce, newSecondary, Math::GetValue(1)))
    {
        return false;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    auto thriceRoot = m_Root[0];
#include STSTEM_WARNING_POP

    m_Count = 0;

    auto discriminant = Math::GetRational(1, 4) * thrice * thrice - secondary + thriceRoot;
    if (Math::FAbs(discriminant) <= m_Epsilon)
    {
        discriminant = Math::GetValue(0);
    }

    if (Math::GetValue(0) < discriminant)
    {
        auto discriminantSqrt = Math::Sqrt(discriminant);
        auto t1 = Math::GetRational(3, 4) * thrice * thrice - discriminantSqrt * discriminantSqrt - Math::GetValue(2) * secondary;
        auto t2 = (Math::GetValue(4) * thrice * secondary - Math::GetValue(8) * once -
                   thrice * thrice * thrice) /
                  (Math::GetValue(4) * discriminantSqrt);

        auto tPlus = t1 + t2;
        auto tMinus = t1 - t2;
        if (Math::FAbs(tPlus) <= m_Epsilon)
        {
            tPlus = Math::GetValue(0);
        }
        if (Math::FAbs(tMinus) <= m_Epsilon)
        {
            tMinus = Math::GetValue(0);
        }

        if (Math::GetValue(0) <= tPlus)
        {
            auto tPlusSqrt = Math::Sqrt(tPlus);
            SetRoot(m_Count, Math::GetRational(-1, 4) * thrice + (Math::GetRational(1, 2) * (discriminantSqrt + tPlusSqrt)));
            ++m_Count;
            SetRoot(m_Count, Math::GetRational(-1, 4) * thrice + (Math::GetRational(1, 2) * (discriminantSqrt - tPlusSqrt)));
            ++m_Count;
        }
        if (Math::GetValue(0) <= tMinus)
        {
            auto e = Math::Sqrt(tMinus);
            SetRoot(m_Count, Math::GetRational(-1, 4) * thrice + (Math::GetRational(1, 2) * (e - discriminantSqrt)));
            ++m_Count;
            SetRoot(m_Count, Math::GetRational(-1, 4) * thrice - (Math::GetRational(1, 2) * (e + discriminantSqrt)));
            ++m_Count;
        }
    }
    else if (discriminant < Math::GetValue(0))
    {
        m_Count = 0;
    }
    else
    {
        auto t2 = thriceRoot * thriceRoot - Math::GetValue(4) * constant;
        if (-m_Epsilon <= t2)
        {
            // ȡ��Ϊ��
            if (t2 < Math::GetValue(0))
            {
                t2 = Math::GetValue(0);
            }

            t2 = Math::GetValue(2) * Math::Sqrt(t2);
            auto t1 = Math::GetRational(3, 4) * thrice * thrice - Math::GetValue(2) * secondary;
            auto tPlus = t1 + t2;
            if (m_Epsilon <= tPlus)
            {
                auto tPlusSqrt = Math::Sqrt(tPlus);
                SetRoot(m_Count, Math::GetRational(-1, 4) * thrice + Math::GetRational(1, 2) * tPlusSqrt);
                ++m_Count;
                SetRoot(m_Count, Math::GetRational(-1, 4) * thrice - Math::GetRational(1, 2) * tPlusSqrt);
                ++m_Count;
            }
            auto tMinus = t1 - t2;
            if (m_Epsilon <= tMinus)
            {
                auto tMinusSqrt = Math::Sqrt(tMinus);
                SetRoot(m_Count, Math::GetRational(-1, 4) * thrice + Math::GetRational(1, 2) * tMinusSqrt);
                ++m_Count;
                SetRoot(m_Count, Math::GetRational(-1, 4) * thrice - Math::GetRational(1, 2) * tMinusSqrt);
                ++m_Count;
            }
        }
    }

    return 0 < m_Count;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindEigenvalues(Real constant, Real once, Real secondary, Real thrice, Real quartic, bool doBalancing, Real tolerance)
{
    if (Math::FAbs(quartic) <= m_Epsilon)
    {
        // ����ʽ�����Ρ�
        return FindAlgebraic(constant, once, secondary, thrice);
    }

    // ʹ����ʽ��һ, x^4 + thrice * x^3 + secondary * x^2 + once * x + constant.
    constant /= quartic;
    once /= quartic;
    secondary /= quartic;
    thrice /= quartic;

    // ����4��4��ͬ����󡣳�ʼ��Ϊ��
    VariableMatrix matrix{ 4, 4 };
    matrix(1, 0) = Math::GetValue(1);
    matrix(2, 1) = Math::GetValue(1);
    matrix(3, 2) = Math::GetValue(1);
    matrix(0, 3) = -constant;
    matrix(1, 3) = -once;
    matrix(2, 3) = -secondary;
    matrix(3, 3) = -thrice;

    if (doBalancing)
    {
        BalanceCompanion4(matrix, tolerance);
    }

    return QRIteration4(matrix);
}

// private
template <typename Real>
void Mathematics::PolynomialRootsImpl<Real>::BalanceCompanion4(VariableMatrix& matrix, Real tolerance)
{
    auto a10 = Math::FAbs(matrix(1, 0));
    auto a21 = Math::FAbs(matrix(2, 1));
    auto a32 = Math::FAbs(matrix(3, 2));
    auto a03 = Math::FAbs(matrix(0, 3));
    auto a13 = Math::FAbs(matrix(1, 3));
    auto a23 = Math::FAbs(matrix(2, 3));
    auto a33 = Math::FAbs(matrix(3, 3));

    for (auto i = 0; i < sm_BalanceCompanionIterationMax; ++i)
    {
        // ƽ�� ��/�� 0
        auto rowNorm = a03;
        auto colomnNorm = a10;
        auto scale = Math::Sqrt(colomnNorm / rowNorm);
        a03 *= scale;
        a10 = a03;

        // ƽ�� ��/�� 1
        rowNorm = (a13 <= a10 ? a10 : a13);
        colomnNorm = a21;
        scale = Math::Sqrt(colomnNorm / rowNorm);
        a10 *= scale;
        a13 *= scale;
        a21 /= scale;

        // ƽ�� ��/�� 2
        rowNorm = (a21 >= a23 ? a21 : a23);
        colomnNorm = a32;
        scale = Math::Sqrt(colomnNorm / rowNorm);
        a21 *= scale;
        a23 *= scale;
        a32 /= scale;

        // ƽ�� ��/�� 3
        rowNorm = (a33 <= a32 ? a32 : a33);
        colomnNorm = (a13 <= a03 ? a03 : a13);
        if (colomnNorm < a23)
        {
            colomnNorm = a23;
        }
        if (colomnNorm < a33)
        {
            colomnNorm = a33;
        }
        scale = Math::Sqrt(colomnNorm / rowNorm);
        a32 *= scale;
        a03 /= scale;
        a13 /= scale;
        a23 /= scale;

        if (IsBalancedCompanion4(a10, a21, a32, a03, a13, a23, a33, tolerance))
        {
            break;
        }

        MATHEMATICS_ASSERTION_1(i != sm_BalanceCompanionIterationMax - 1, "����������\n");
    }

    matrix(1, 0) = (Math::GetValue(0) <= matrix(1, 0) ? a10 : -a10);
    matrix(2, 1) = (Math::GetValue(0) <= matrix(2, 1) ? a21 : -a21);
    matrix(3, 2) = (Math::GetValue(0) <= matrix(3, 2) ? a32 : -a32);
    matrix(0, 3) = (Math::GetValue(0) <= matrix(0, 3) ? a03 : -a03);
    matrix(1, 3) = (Math::GetValue(0) <= matrix(1, 3) ? a13 : -a13);
    matrix(2, 3) = (Math::GetValue(0) <= matrix(2, 3) ? a23 : -a23);
    matrix(3, 3) = (Math::GetValue(0) <= matrix(3, 3) ? a33 : -a33);
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::IsBalancedCompanion4(Real a10, Real a21, Real a32, Real a03, Real a13, Real a23, Real a33, Real tolerance) noexcept
{
    // ��/�� 0
    auto rowNorm = a03;
    auto colomnNorm = a10;
    auto test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // ��/�� 1
    rowNorm = (a13 <= a10 ? a10 : a13);
    colomnNorm = a21;
    test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // ��/�� 2
    rowNorm = (a23 <= a21 ? a21 : a23);
    colomnNorm = a32;
    test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);
    if (tolerance < test)
    {
        return false;
    }

    // ��/�� 3
    rowNorm = (a33 <= a32 ? a32 : a33);
    colomnNorm = (a13 <= a03 ? a03 : a13);
    if (colomnNorm < a23)
    {
        colomnNorm = a23;
    }
    if (colomnNorm < a33)
    {
        colomnNorm = a33;
    }
    test = Math::FAbs(Math::GetValue(1) - colomnNorm / rowNorm);

    return test <= tolerance;
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::QRIteration4(VariableMatrix& matrix)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

    VariableLengthVector vector{ 4 };

    for (auto i = 0; i < m_MaxIterations; ++i)
    {
        auto rhs = m_Epsilon * (Math::FAbs(matrix(0, 0)) + Math::FAbs(matrix(1, 1)));

        if (Math::FAbs(matrix(1, 0)) <= rhs)
        {
            // matrix(0,0)��һ����������3��3�Ӿ���
            // ���⿽������ͨ����/��ƫ������FrancisQR������
            VariableMatrix matrixMS{ 3, 3 };

            matrixMS(0, 0) = matrix(1, 1);
            matrixMS(0, 1) = matrix(1, 2);
            matrixMS(0, 2) = matrix(1, 3);
            matrixMS(1, 0) = matrix(2, 1);
            matrixMS(1, 1) = matrix(2, 2);
            matrixMS(1, 2) = matrix(2, 3);
            matrixMS(2, 0) = matrix(3, 1);
            matrixMS(2, 1) = matrix(3, 2);
            matrixMS(2, 2) = matrix(3, 3);
            if (!QRIteration3(matrixMS))
            {
                return false;
            }
            m_Root[m_Count++] = matrix(0, 0);

            return true;
        }

        rhs = m_Epsilon * (Math::FAbs(matrix(1, 1)) + Math::FAbs(matrix(2, 2)));

        if (Math::FAbs(matrix(2, 1)) <= rhs)
        {
            // �þ��󱻷ֽ������2��2�顣����Щ��Ķ��η���ʽ��
            auto trace = matrix(0, 0) + matrix(1, 1);
            auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
            if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
            {
                return false;
            }
            const auto saveCount = m_Count;
            constexpr auto saveRootSize = 2;
            std::array<Real, saveRootSize> saveRoot{};
            for (auto j = 0; j < saveCount && j < saveRootSize; ++j)
            {
                saveRoot[j] = m_Root[j];
            }

            trace = matrix(2, 2) + matrix(3, 3);
            det = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
            if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
            {
                return false;
            }
            for (auto j = 0; j < saveCount && j < saveRootSize; ++j)
            {
                m_Root[m_Count++] = saveRoot[j];
            }

            return 0 < m_Count;
        }

        rhs = m_Epsilon * (Math::FAbs(matrix(2, 2)) + Math::FAbs(matrix(3, 3)));

        if (Math::FAbs(matrix(3, 2)) <= rhs)
        {
            // matrix(3,3)��һ����������3��3�Ӿ���
            // ���⿽������ͨ����/��ƫ������FrancisQR������
            VariableMatrix matrixMS{ 3, 3 };

            matrixMS(0, 0) = matrix(0, 0);
            matrixMS(0, 1) = matrix(0, 1);
            matrixMS(0, 2) = matrix(0, 2);
            matrixMS(1, 0) = matrix(1, 0);
            matrixMS(1, 1) = matrix(1, 1);
            matrixMS(1, 2) = matrix(1, 2);
            matrixMS(2, 0) = matrix(2, 0);
            matrixMS(2, 1) = matrix(2, 1);
            matrixMS(2, 2) = matrix(2, 2);

            if (!QRIteration3(matrixMS))
            {
                return false;
            }
            m_Root[m_Count++] = matrix(3, 3);

            return true;
        }

        FrancisQRStep(matrix, vector);
    }

    // ���������������������ô�죿
    // Ҳ��һ������Ŷ���kick��ϵͳ�е�һ��λ���ܻ���Ч��

    MATHEMATICS_ASSERTION_4(false, "����������\n");

    // ���ڣ�������С�ζԽ������
    auto i = 0;
    auto minValue = Math::FAbs(matrix(1, 0));
    auto absValue = Math::FAbs(matrix(2, 1));
    if (absValue < minValue)
    {
        minValue = absValue;
        i = 1;
    }
    absValue = Math::FAbs(matrix(3, 2));
    if (absValue < minValue)
    {
        minValue = absValue;
        i = 2;
    }

    if (i == 0)
    {
        // matrix(0,0)��һ����������3��3�Ӿ���
        // ���⿽������ͨ����/��ƫ������FrancisQR������
        VariableMatrix matrixMS{ 3, 3 };

        matrixMS(0, 0) = matrix(1, 1);
        matrixMS(0, 1) = matrix(1, 2);
        matrixMS(0, 2) = matrix(1, 3);
        matrixMS(1, 0) = matrix(2, 1);
        matrixMS(1, 1) = matrix(2, 2);
        matrixMS(1, 2) = matrix(2, 3);
        matrixMS(2, 0) = matrix(3, 1);
        matrixMS(2, 1) = matrix(3, 2);
        matrixMS(2, 2) = matrix(3, 3);
        if (!QRIteration3(matrixMS))
        {
            return false;
        }
        m_Root[m_Count++] = matrix(0, 0);
    }
    else if (i == 1)
    {
        // �þ��󱻷ֽ������2��2�顣����Щ��Ķ��η���ʽ��
        auto trace = matrix(0, 0) + matrix(1, 1);
        auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
        if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
        {
            return false;
        }
        const auto saveCount = m_Count;
        std::array<Real, 2> saveRoot{};
        for (auto j = 0; j < saveCount; ++j)
        {
            saveRoot[j] = m_Root[j];
        }

        trace = matrix(2, 2) + matrix(3, 3);
        det = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
        if (!FindAlgebraic(det, -trace, Math::GetValue(1)))
        {
            return false;
        }
        for (auto j = 0; j < saveCount; ++j)
        {
            m_Root[m_Count++] = saveRoot[j];
        }
    }
    else  // i == 2
    {
        // matrix(3,3)��һ����������3��3�Ӿ���
        // ���⿽������ͨ����/��ƫ������FrancisQR������
        VariableMatrix matrixMS{ 3, 3 };

        matrixMS(0, 0) = matrix(0, 0);
        matrixMS(0, 1) = matrix(0, 1);
        matrixMS(0, 2) = matrix(0, 2);
        matrixMS(1, 0) = matrix(1, 0);
        matrixMS(1, 1) = matrix(1, 1);
        matrixMS(1, 2) = matrix(1, 2);
        matrixMS(2, 0) = matrix(2, 0);
        matrixMS(2, 1) = matrix(2, 1);
        matrixMS(2, 2) = matrix(2, 2);
        if (!QRIteration3(matrixMS))
        {
            return false;
        }
        m_Root[m_Count++] = matrix(3, 3);
    }

    return 0 < m_Count;

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetBound(Real constant, Real once, Real secondary, Real thrice, Real quartic)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::FAbs(quartic) <= m_Epsilon)
    {
        // ����ʽ�����ε�
        return GetBound(constant, once, secondary, thrice);
    }

    auto maxValue = Math::FAbs(constant) / quartic;

    auto value = Math::FAbs(once) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    value = Math::FAbs(secondary) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    value = Math::FAbs(thrice) / quartic;
    if (maxValue < value)
    {
        maxValue = value;
    }

    return Math::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindBisection(const Polynomial& polynomial, int digits)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto bound = GetBound(polynomial);

    if (Math::GetValue(0) <= bound)
        return FindBisection(polynomial, -bound, bound, digits);
    else
        return false;
}

template <typename Real>
Real Mathematics::PolynomialRootsImpl<Real>::GetBound(const Polynomial& polynomial)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto copyPolynomial = polynomial;
    copyPolynomial.Compress(m_Epsilon);
    const auto degree = copyPolynomial.GetDegree();
    if (degree < 1)
    {
        // ����ʽ�ǳ�����������Ч�߽硣
        return Math::GetValue(-1);
    }

    auto invCopyDegree = Math::GetValue(1) / copyPolynomial[degree];
    auto maxValue = Math::GetValue(0);
    for (auto i = 0; i < degree; ++i)
    {
        auto value = Math::FAbs(copyPolynomial[i]) * invCopyDegree;
        if (maxValue < value)
        {
            maxValue = value;
        }
    }

    return Math::GetValue(1) + maxValue;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::FindBisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    // �����Ҫ���·������顣
    if (m_MaxRoot < polynomial.GetDegree())
    {
        m_MaxRoot = polynomial.GetDegree();
        m_Root.resize(m_MaxRoot);
    }

    auto root = Math::GetValue(0);
    if (polynomial.GetDegree() == 1)
    {
        if (Bisection(polynomial, xMin, xMax, digits, root))
        {
            m_Count = 1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            m_Root[0] = root;
#include STSTEM_WARNING_POP

            return true;
        }
        m_Count = 0;

        return false;
    }

    // ��ȡ��������ʽ�ĸ���
    auto derivative = polynomial.GetDerivative();
    if (!FindBisection(derivative, xMin, xMax, digits))
    {
        return false;
    }

    auto newCount = 0;
    const auto newRootCount = m_Count + 1;
    Container newRoot(newRootCount);

    if (0 < m_Count)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        // ���Ҹ���[xmin,root[0]].
        if (Bisection(polynomial, xMin, m_Root[0], digits, root))
        {
            newRoot[newCount++] = root;
        }

        // ���Ҹ���[root[i],root[i + 1]] �� 0 <= i <= count - 2.
        for (auto i = 0; i <= m_Count - 2; ++i)
        {
            const auto nextRootIndex = i + 1;
            if (Bisection(polynomial, m_Root[i], m_Root[nextRootIndex], digits, root))
            {
                newRoot[newCount++] = root;
            }
        }

        // ���Ҹ��� [root[count - 1],xmax].
        const auto rootIndex = m_Count - 1;
        if (Bisection(polynomial, m_Root[rootIndex], xMax, digits, root))
        {
            newRoot[newCount++] = root;
        }

#include STSTEM_WARNING_POP
    }
    else
    {
        // ����ʽ����[xmin,xmax]�����������һ������
        if (Bisection(polynomial, xMin, xMax, digits, root))
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            newRoot[newCount++] = root;
#include STSTEM_WARNING_POP
        }
    }

    // ���Ƶ��ɻ�������
    if (0 < newCount)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        m_Count = 1;
        m_Root[0] = newRoot[0];
        for (auto i = 1; i < newCount; ++i)
        {
            const auto beforeRootIndex = i - 1;
            auto rootDifference = newRoot[i] - newRoot[beforeRootIndex];
            if (m_Epsilon < Math::FAbs(rootDifference))
            {
                m_Root[m_Count++] = newRoot[i];
            }
        }

#include STSTEM_WARNING_POP
    }
    else
    {
        m_Count = 0;
    }

    return 0 < m_Count;
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::Bisection(const Polynomial& polynomial, Real xMin, Real xMax, int digits, Real& root)
{
    auto xMinPolynomial = polynomial(xMin);
    if (Math::FAbs(xMinPolynomial) <= Math::GetZeroTolerance())
    {
        root = xMin;
        return true;
    }

    auto xMaxPolynomial = polynomial(xMax);
    if (Math::FAbs(xMaxPolynomial) <= Math::GetZeroTolerance())
    {
        root = xMax;
        return true;
    }

    if (Math::GetValue(0) < xMinPolynomial * xMaxPolynomial)
    {
        return false;
    }

    // ȷ���������������'digits'��׼ȷ��..
    auto differenceLog = Math::Log(xMax - xMin);
    auto digitsProductLN10 = static_cast<Real>(digits) * Math::GetLN10();
    auto arg = (differenceLog + digitsProductLN10) / Math::GetLN2();
    const auto maxIter = static_cast<int>(arg + Math::GetRational(1, 2));

    for (auto i = 0; i < maxIter; ++i)
    {
        root = Math::GetRational(1, 2) * (xMin + xMax);
        auto rootPolynomial = polynomial(root);
        auto product = rootPolynomial * xMinPolynomial;
        if (product < Math::GetValue(0))
        {
            xMax = root;
            xMaxPolynomial = rootPolynomial;
        }
        else if (Math::GetValue(0) < product)
        {
            xMin = root;
            xMinPolynomial = rootPolynomial;
        }
        else
        {
            break;
        }
    }

    return true;
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::AllRealPartsNegative(const Polynomial& polynomial)
{
    // ʹ��ϵ����һ���������Ժ���ý��ı丱����
    const auto degree = polynomial.GetDegree();
    Container coeff{};
    for (auto i = 0; i < degree + 1; ++i)
    {
        coeff.emplace_back(polynomial[i]);
    }

// ʹ����ʽ��һ��
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    if (m_Epsilon < Math::FAbs(coeff[degree] - Math::GetValue(1)))
    {
        for (auto i = 0; i < degree; ++i)
        {
            coeff[i] /= coeff[degree];
        }

        coeff[degree] = Math::GetValue(1);
    }
#include STSTEM_WARNING_POP

    return AllRealPartsNegative(degree, coeff);
}

template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::AllRealPartsPositive(const Polynomial& polynomial)
{
    // ʹ��ϵ����һ���������Ժ���ý��ı丱����
    auto degree = polynomial.GetDegree();
    Container coeff{};
    for (auto i = 0; i < degree + 1; ++i)
    {
        coeff.emplace_back(polynomial[i]);
    }

    // ʹ����ʽ��һ��
    if (m_Epsilon < Math::FAbs(coeff[degree] - Math::GetValue(1)))
    {
        for (auto i = 0; i < degree; ++i)
        {
            coeff[i] /= coeff[degree];
        }

        coeff[degree] = Math::GetValue(1);
    }

    // ���� z -> -z.
    auto sign = -1;
    for (auto i = degree - 1; 0 <= i; --i)
    {
        coeff[i] *= sign;
        sign = -sign;
    }

    return AllRealPartsNegative(degree, coeff);
}

// private
template <typename Real>
bool Mathematics::PolynomialRootsImpl<Real>::AllRealPartsNegative(int degree, Container& coeff)
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    MATHEMATICS_ASSERTION_1(Math::FAbs(coeff[degree] - Math::GetValue(1)) <= m_Epsilon, "����ʽ��1\n");

    const auto degreeMinus1 = degree - 1;
    if (coeff[degreeMinus1] <= Math::GetValue(0))
    {
        return false;
    }

    if (degree == 1)
    {
        return true;
    }

    Container tmpCoeff(degree);

    tmpCoeff[0] = Math::GetValue(2) * coeff[0] * coeff[degreeMinus1];

    for (auto i = 1; i <= degree - 2; ++i)
    {
        tmpCoeff[i] = coeff[degreeMinus1] * coeff[i];
        if (((degree - i) % 2) == 0)
        {
            const auto next = i - 1;
            tmpCoeff[i] -= coeff[next];
        }
        tmpCoeff[i] *= Math::GetValue(2);
    }

    tmpCoeff[degreeMinus1] = Math::GetValue(2) * coeff[degreeMinus1] * coeff[degreeMinus1];

    auto nextDegree = 0;
    for (nextDegree = degree - 1; 0 <= nextDegree; --nextDegree)
    {
        if (m_Epsilon < Math::FAbs(tmpCoeff[nextDegree]))
        {
            break;
        }
    }
    for (auto i = 0; i <= nextDegree - 1; ++i)
    {
        coeff[i] = tmpCoeff[i] / tmpCoeff[nextDegree];
    }

    if (0 <= nextDegree)
    {
        coeff[nextDegree] = Math::GetValue(1);

        return AllRealPartsNegative(nextDegree, coeff);
    }
    else
    {
        return false;
    }

#include STSTEM_WARNING_POP
}

template <typename Real>
int Mathematics::PolynomialRootsImpl<Real>::GetRootCount(const Polynomial& polynomial, Real begin, Real end)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    const auto degree = polynomial.GetDegree();
    auto coeff = polynomial.GetValue();

    if (degree == 0)
    {
        // ����ʽ��������㶨��
        if (Math::FAbs(coeff[0]) <= m_Epsilon)
        {
            return 0;
        }
        else
        {
            // ��ʾ�������
            return -1;
        }
    }

    // ����Sturm���С�
    std::vector<Polynomial> sturm{ Polynomial{ polynomial }, polynomial.GetDerivative() };
    auto beginPolynomialIndex = 0;
    auto endPolynomialIndex = 1;
    auto currentIndex = sturm.size() - 1;

    while (0 < sturm[endPolynomialIndex].GetDegree())
    {
        auto divide = sturm[beginPolynomialIndex].Divide(sturm[endPolynomialIndex], m_Epsilon);
        auto quot = divide.GetQuotient();
        auto remainder = -divide.GetRemainder();

        sturm.emplace_back(remainder);

        currentIndex = sturm.size() - 1;
        beginPolynomialIndex = endPolynomialIndex;
        endPolynomialIndex = boost::numeric_cast<int>(currentIndex);
    }

    const auto numSturm = boost::numeric_cast<int>(sturm.size());

    // ������begin�ķ��Ÿı䡣
    auto signChanges0 = 0;
    if (Math::FAbs(begin + Math::sm_MaxReal) <= m_Epsilon)
    {
        auto lhsValue = Math::GetValue(0);

        if (sturm[0].GetDegree() & 1)
        {
            lhsValue = -sturm[0].GetEnd();
        }
        else
        {
            lhsValue = sturm[0].GetEnd();
        }

        if (Math::FAbs(lhsValue) < m_Epsilon)
        {
            lhsValue = Math::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto rhsValue = Math::GetValue(0);

            if (sturm[i].GetDegree() & 1)
            {
                rhsValue = -sturm[i].GetEnd();
            }
            else
            {
                rhsValue = sturm[i].GetEnd();
            }

            if (Math::FAbs(rhsValue) < m_Epsilon)
            {
                rhsValue = Math::GetValue(0);
            }

            if (lhsValue * rhsValue < Math::GetValue(0) || Math::FAbs(lhsValue) < m_Epsilon)
            {
                ++signChanges0;
            }

            lhsValue = rhsValue;
        }
    }
    else
    {
        auto lhsValue = Math::GetValue(0);

        lhsValue = sturm[0](begin);
        if (Math::FAbs(lhsValue) < m_Epsilon)
        {
            lhsValue = Math::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto rhsValue = Math::GetValue(0);

            rhsValue = sturm[i](begin);
            if (Math::FAbs(rhsValue) < m_Epsilon)
            {
                rhsValue = Math::GetValue(0);
            }

            if (lhsValue * rhsValue < Math::GetValue(0) || Math::FAbs(lhsValue) < m_Epsilon)
            {
                ++signChanges0;
            }

            lhsValue = rhsValue;
        }
    }

    // ������end�ķ��Ÿı䡣
    auto signChanges1 = 0;
    if (Math::FAbs(end - Math::sm_MaxReal) <= m_Epsilon)
    {
        Real lhsValue = sturm[0].GetEnd();
        if (Math::FAbs(lhsValue) < m_Epsilon)
        {
            lhsValue = Math::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto rhsValue = sturm[i].GetEnd();
            if (Math::FAbs(rhsValue) < m_Epsilon)
            {
                rhsValue = Math::GetValue(0);
            }

            if (lhsValue * rhsValue < Math::GetValue(0) || Math::FAbs(lhsValue) < m_Epsilon)
            {
                ++signChanges1;
            }

            lhsValue = rhsValue;
        }
    }
    else
    {
        auto lhsValue = sturm[0](end);
        if (Math::FAbs(lhsValue) < m_Epsilon)
        {
            lhsValue = Math::GetValue(0);
        }

        for (auto i = 1; i < numSturm; ++i)
        {
            auto rhsValue = sturm[i](end);
            if (Math::FAbs(rhsValue) < m_Epsilon)
            {
                rhsValue = Math::GetValue(0);
            }

            if (lhsValue * rhsValue < Math::GetValue(0) || Math::FAbs(lhsValue) < m_Epsilon)
            {
                ++signChanges1;
            }

            lhsValue = rhsValue;
        }
    }

    if (signChanges1 <= signChanges0)
    {
        return signChanges0 - signChanges1;
    }

    // ���������ǲ�Ӧ�õ������
    MATHEMATICS_ASSERTION_1(false, "��������\n");

#include STSTEM_WARNING_POP

    return 0;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_POLYNOMIAL_ROOTS_IMPL_DETAIL_H
