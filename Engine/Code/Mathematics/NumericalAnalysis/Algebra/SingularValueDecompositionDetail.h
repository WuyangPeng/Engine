/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H

#include "GivensRotationDetail.h"
#include "SingularInfoDetail.h"
#include "SingularValueDecomposition.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::Algebra::SingularValueDecomposition<Real>::SingularValueDecomposition(int numRows, int numCols, int maxIterations)
    : numRows{ numRows },
      numCols{ numCols },
      maxIterations{ maxIterations },
      matrix(System::GetProduct(numRows, numCols)),
      uMatrix(System::GetProduct(numRows, numRows)),
      vMatrix(System::GetProduct(numCols, numCols)),
      sMatrix(System::GetProduct(numRows, numCols)),
      diagonal(numCols),
      superDiagonal(System::GetMinus(numCols, 1)),
      lHouseholder(numCols, DiagonalType(numRows)),
      rHouseholder(System::GetMinus(numCols, 2), DiagonalType(numCols)),
      lGivens(System::GetProduct(maxIterations, (numCols - 1))),
      rGivens(System::GetProduct(maxIterations, (numCols - 1)))
{
    if (numCols < 2 || numRows < numCols || maxIterations <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ч���롣"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::SingularValueDecomposition<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::Algebra::SingularValueDecomposition<Real>::Solve(const MatrixType& input, Real multiplier)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (multiplier <= Real{} || input.size() != matrix.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ����������Ч��"))
    }

    /// �����븴�Ƶ�matrix�����������ڲ��޸ĺ�һ������
    matrix = input;

    /// ��matrix��ԭΪ˫�Խ�����ʽ��
    /// ���Խ���matrix(d,d)�ͳ��Խ���matrix(d,d+1)�ֱ�洢��diagonal��superDiagonal�С�
    Bidiagonalize();

    /// ��ֵ����ȷ��˫�ԽǾ���B�ĶԽ�����Ŀ�Ƿ��㹻С���Ա���Ϊ�㡣
    /// �������¹�ʽ���壺
    ///   threshold = multiplier * unitRoundOff * |B|,����
    /// ����������std::numeric_limits<Real>::epsilon()��|B|�Ǿ���ķ�����
    /// ������һ��С�� [��Golub��Van Loan���㷨8.3.2��SVD�㷨��֮ǰ�����]��
    /// B��L-infinity�������ڼ��㡣
    Real epsilon{};
    Real threshold{};
    ComputeCutoffs(multiplier, epsilon, threshold);

    constexpr auto invalid = std::numeric_limits<int>::max();
    rGivens.clear();
    lGivens.clear();
    for (auto iteration = 0; iteration < maxIterations; ++iteration)
    {
        /// ������Խ�����Ŀ�����ڵĶԽ�����Ŀ���ʵ����Ϊ�㣬��������Ϊ�㡣
        auto numZero = 0;
        for (auto i = 0; i <= numCols - 2; ++i)
        {
            const auto nextIndex = i + 1;
            const auto absSuper = Math::FAbs(superDiagonal.at(i));
            const auto absDiagonal0 = Math::FAbs(diagonal.at(i));
            const auto absDiagonal1 = Math::FAbs(diagonal.at(nextIndex));
            if (absSuper <= epsilon * (absDiagonal0 + absDiagonal1))
            {
                superDiagonal.at(i) = Real{};
                ++numZero;
            }
        }

        if (numZero == numCols - 1)
        {
            /// ���Խ�����ʵ���϶�Ϊ�㣬����㷨�Ѿ�����������U��V��S��
            ComputeOrthogonalMatrices();
            return iteration;
        }

        /// �ҵ��������{iMin,...,iMax}�����ڸ����У����Խ�����Ŀ����ȫ����ЧΪ�㡣
        /// ��·�˽ӣ� iMax != invalid����Ϊ������г��Խ����Ϊ�㣬
        /// ��ǰ���if���"if (numZero == numCols - 1)"��ȷ���˳��ú���
        auto iMax = numCols - 2;
        for (; iMax != 0; --iMax)
        {
            if (!Math::Approximate(superDiagonal.at(iMax), Real{}))
            {
                break;
            }
        }
        ++iMax;

        auto iMin = iMax - 1;
        for (; iMin != invalid; --iMin)
        {
            if (!Math::Approximate(superDiagonal.at(iMin), Real{}))
            {
                break;
            }
        }
        ++iMin;

        /// ��Ӧ�� {iMin,...,iMax} ���ӿ�����г��Խ�����Ŀʵ���϶������㡣
        /// ȷ�����ӿ��Ƿ����ʵ����Ϊ��ĶԽ�����Ŀ��
        /// ����ǣ���ʹ��Givens��ת����������Ŀ���й��㡣
        if (DiagonalEntriesNonzero(iMin, iMax, threshold))
        {
            DoGolubKahanStep(iMin, iMax);
        }
    }
    return invalid;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::MatrixType Mathematics::Algebra::SingularValueDecomposition<Real>::GetU() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return uMatrix;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::MatrixType Mathematics::Algebra::SingularValueDecomposition<Real>::GetV() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vMatrix;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::MatrixType Mathematics::Algebra::SingularValueDecomposition<Real>::GetS() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sMatrix;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::Algebra::SingularValueDecomposition<Real>::GetSingularValue(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (numCols <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ֵ��������Ч��"))
    }

    const auto matrixIndex = index + numCols * index;

    return sMatrix.at(matrixIndex);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::DiagonalType Mathematics::Algebra::SingularValueDecomposition<Real>::GetUColumn(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (numRows <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("U�е�������Ч��"))
    }

    DiagonalType column{};

    for (auto row = 0; row < numRows; ++row)
    {
        const auto matrixIndex = index + numRows * row;

        column.emplace_back(uMatrix.at(matrixIndex));
    }

    return column;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::DiagonalType Mathematics::Algebra::SingularValueDecomposition<Real>::GetVColumn(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (numCols <= index)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("V�е�������Ч��"))
    }

    DiagonalType column{};

    for (auto row = 0; row < numCols; ++row)
    {
        const auto matrixIndex = index + numCols * row;

        column.emplace_back(vMatrix.at(matrixIndex));
    }

    return column;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::Algebra::SingularValueDecomposition<Real>::DiagonalType Mathematics::Algebra::SingularValueDecomposition<Real>::GetSingularValues() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    DiagonalType singularValues{};

    for (auto index = 0; index < numCols; ++index)
    {
        const auto matrixIndex = index + numCols * index;

        singularValues.emplace_back(sMatrix.at(matrixIndex));
    }

    return singularValues;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeHouseholderU(int numRows, int numCols, const MatrixType& a, int selectCol, DiagonalType& v)
{
    /// ��ȡ������v[]������v[row] = A(row, selectCol)��
    /// Ԫ��v[row] = 0��ʾ0 <= row < selectCol���Ա��������δ��ʼ�����ڴ棻
    /// ���÷���Ӧ������ЩԪ�ء�
    auto row = 0;
    for (; row < selectCol; ++row)
    {
        v.at(row) = Real{};
    }

    Real mu{};
    for (; row < numRows; ++row)
    {
        const auto index = selectCol + numCols * row;
        const auto element = a.at(index);
        mu += element * element;
        v.at(row) = element;
    }
    mu = Math::Sqrt(mu);

    if (Math::Approximate(mu, Real{}))
    {
        const auto beta = v.at(selectCol) + (Real{} <= v.at(selectCol) ? mu : -mu);
        for (row = selectCol + 1; row < numRows; ++row)
        {
            v.at(row) /= beta;
        }
    }

    v.at(selectCol) = Math::GetValue(1);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeHouseholderV(int numRows, int numCols, const MatrixType& a, int selectRow, DiagonalType& v)
{
    /// ��ȡ������v[]������v[col] = A(selectRow, col)��
    /// Ԫ��v[col] = 0��ʾ0 <= col <= selectRow��
    /// �Ա��������δ��ʼ�����ڴ棻���÷���Ӧ������ЩԪ�ء�

    System::UnusedFunction(numRows);

    const auto selectRowP1 = selectRow + 1;
    auto col = 0;
    for (; col < selectRowP1; ++col)
    {
        v.at(col) = Real{};
    }

    Real mu{};
    for (; col < numCols; ++col)
    {
        const auto index = col + numCols * selectRow;
        const auto element = a.at(index);
        mu += element * element;
        v.at(col) = element;
    }
    mu = Math::Sqrt(mu);

    if (Math::Approximate(mu, Real{}))
    {
        const auto beta = v.at(selectRowP1) + (Real{} <= v.at(selectRowP1) ? mu : -mu);
        for (col = selectRowP1 + 1; col < numCols; ++col)
        {
            v.at(col) /= beta;
        }
    }

    v.at(selectRowP1) = Math::GetValue(1);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::DoHouseholderPreMultiply(int numRows, int numCols, const DiagonalType& v, int selectCol, MatrixType& a)
{
    Real vSqrLength{};
    for (auto row = selectCol; row < numRows; ++row)
    {
        vSqrLength += v.at(row) * v.at(row);
    }
    const auto beta = Math::GetValue(-2) / vSqrLength;

    DiagonalType w(numCols);
    for (auto col = selectCol; col < numCols; ++col)
    {
        w.at(col) = Real{};
        for (auto row = selectCol; row < numRows; ++row)
        {
            const auto index = col + numCols * row;
            w.at(col) += v.at(row) * a.at(index);
        }
        w.at(col) *= beta;
    }

    for (auto row = selectCol; row < numRows; ++row)
    {
        for (auto col = selectCol; col < numCols; ++col)
        {
            const auto index = col + numCols * row;
            a.at(index) += v.at(row) * w.at(col);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::DoHouseholderPostMultiply(int numRows, int numCols, const DiagonalType& v, int selectRow, MatrixType& a)
{
    Real vSqrLength{};
    for (auto col = selectRow; col < numCols; ++col)
    {
        vSqrLength += v.at(col) * v.at(col);
    }
    const auto beta = Math::GetValue(-2) / vSqrLength;

    DiagonalType w(numRows);
    for (auto row = selectRow; row < numRows; ++row)
    {
        w.at(row) = Real{};
        for (auto col = selectRow; col < numCols; ++col)
        {
            const auto index = col + numCols * row;
            w.at(row) += a.at(index) * v.at(col);
        }
        w.at(row) *= beta;
    }

    for (auto row = selectRow; row < numRows; ++row)
    {
        for (auto col = selectRow; col < numCols; ++col)
        {
            const auto index = col + numCols * row;
            a.at(index) += w.at(row) * v.at(col);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::Bidiagonalize()
{
    DiagonalType uVector(numRows);
    DiagonalType vVector(numCols);
    for (auto i = 0; i < numCols; ++i)
    {
        /// ����u-Householder������
        ComputeHouseholderU(numRows, numCols, matrix, i, lHouseholder.at(i));

        /// ���� A = (I - 2*u*u^T/u^T*u) * A.
        DoHouseholderPreMultiply(numRows, numCols, lHouseholder.at(i), i, matrix);

        if (i < boost::numeric_cast<int>(rHouseholder.size()))
        {
            /// ����v-Householder������
            ComputeHouseholderV(numRows, numCols, matrix, i, rHouseholder.at(i));

            // ���� A = A * (I - 2*v*v^T/v^T*v).
            DoHouseholderPostMultiply(numRows, numCols, rHouseholder.at(i), i, matrix);
        }
    }

    /// ��Golub-Kahan�����и��ƶԽ��ߺʹζԽ����Ի�û���һ���ԡ�
    for (auto d = 0; d < numCols; ++d)
    {
        const auto index = d + numCols * d;
        diagonal.at(d) = matrix.at(index);
    }

    for (auto s = 0; s < numCols - 1; ++s)
    {
        const auto index = (s + 1) + numCols * s;
        superDiagonal.at(s) = matrix.at(index);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeCutoffs(Real multiplier, Real& epsilon, Real& threshold) const
{
    Real norm{};
    for (auto i = 0; i < numCols; ++i)
    {
        const auto abs = Math::FAbs(diagonal.at(i));
        if (norm < abs)
        {
            norm = abs;
        }
    }

    for (auto i = 0; i < numCols - 1; ++i)
    {
        const auto abs = Math::FAbs(superDiagonal.at(i));
        if (norm < abs)
        {
            norm = abs;
        }
    }

    epsilon = multiplier * unitRoundOff;
    threshold = epsilon * norm;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::GetSinCos(Real x, Real y, Real& cs, Real& sn) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (Math::Approximate(y, Real{}))
    {
        if (std::fabs(x) < std::fabs(y))
        {
            const auto tau = -x / y;
            sn = Math::GetValue(1) / Math::Sqrt(Math::GetValue(1) + tau * tau);
            cs = sn * tau;
        }
        else
        {
            const auto tau = -y / x;
            cs = Math::GetValue(1) / Math::Sqrt(Math::GetValue(1) + tau * tau);
            sn = cs * tau;
        }
    }
    else
    {
        cs = Math::GetValue(1);
        sn = Real{};
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::SingularValueDecomposition<Real>::DiagonalEntriesNonzero(int iMin, int iMax, Real threshold)
{
    for (auto i = iMin; i < iMax; ++i)
    {
        if (Math::FAbs(diagonal.at(i)) <= threshold)
        {
            /// ʹ��ƽ����ת�����Խ�����Ŀ�Ӿ�����������Ӷ�����һ���㡣
            Real cs{};
            Real sn{};
            auto y = superDiagonal.at(i);
            superDiagonal.at(i) = Real{};
            for (auto j = i + 1; j <= iMax; ++j)
            {
                auto x = diagonal.at(j);
                GetSinCos(x, y, cs, sn);

                /// ע��Givens����Ϊ(cs,-sn)�����Ų��Ǳ������
                lGivens.emplace_back(i, j, cs, -sn);
                diagonal.at(j) = cs * x - sn * y;
                if (j < iMax)
                {
                    auto z = superDiagonal.at(j);
                    superDiagonal.at(j) = cs * z;
                    y = sn * z;
                }
            }
            return false;
        }
    }
    return true;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::DoGolubKahanStep(int iMin, int iMax)
{
    /// ��ʽ��ת�䡣
    /// ��A = {{a00,a01},{a01,a11}}��B^T*B������2x2�顣
    /// ����A������ֵu������ӽ�a11������a00��

    Real f0{};
    Real f1{};
    Real d1{};
    Real d2{};
    if (1 < iMax)
    {
        f0 = superDiagonal.at(System::GetMinus(iMax, 2));
        f1 = superDiagonal.at(System::GetMinus(iMax, 1));
        d1 = diagonal.at(System::GetMinus(iMax, 1));
        d2 = diagonal.at(iMax);
    }
    else
    {
        f0 = Real{};
        f1 = superDiagonal.at(0);
        d1 = diagonal.at(0);
        d2 = diagonal.at(1);
    }

    /// ����B^T*B������2x2�顣
    const auto a00 = d1 * d1 + f0 * f0;
    const auto a01 = d1 * f1;
    auto a11 = d2 * d2 + f1 * f1;

    /// ����ֵΪ((a00+a11) +/- sqrt((a00-a11)^2+a01^2))/2��
    /// ��(a00+a11)/2�Ⱦࡣ
    /// ���a11 >= a00������������ֵʹ��(+)sqrt�
    /// ���a11 <= a00������������ֵʹ��(-)sqrt�
    const auto sum = a00 + a11;
    const auto dif = a00 - a11;
    const auto root = Math::Sqrt(dif * dif + a01 * a01);
    const auto lambda = Math::GetRational(1, 2) * (a00 <= a11 ? sum + root : sum - root);
    auto x = diagonal.at(iMin) * diagonal.at(iMin) - lambda;
    auto y = diagonal.at(iMin) * superDiagonal.at(iMin);

    Real a02{};
    Real cs{};
    Real sn{};
    for (auto i0 = iMin - 1, i1 = iMin, i2 = iMin + 1; i1 <= iMax - 1; ++i0, ++i1, ++i2)
    {
        /// ����Givens��תG�������䱣�������ڼ���U^T*A*V = S�е�V��
        GetSinCos(x, y, cs, sn);
        rGivens.emplace_back(i1, i2, cs, sn);

        // ���� B0 = B*G.
        if (iMin < i1)
        {
            superDiagonal.at(i0) = cs * superDiagonal.at(i0) - sn * a02;
        }

        a11 = diagonal.at(i1);
        auto a12 = superDiagonal.at(i1);
        auto a22 = diagonal.at(i2);
        diagonal.at(i1) = cs * a11 - sn * a12;
        superDiagonal.at(i1) = sn * a11 + cs * a12;
        diagonal.at(i2) = cs * a22;
        auto a21 = -sn * a22;

        /// ������һ��Givens��ת�Ĳ���
        x = diagonal.at(i1);
        y = a21;

        /// ����Givens��תG�������䱣����������U^T*A*V = S�м���U��
        GetSinCos(x, y, cs, sn);
        lGivens.emplace_back(i1, i2, cs, sn);

        // ���� B1 = G^T*B0.
        a11 = diagonal.at(i1);
        a12 = superDiagonal.at(i1);
        a22 = diagonal.at(i2);
        diagonal.at(i1) = cs * a11 - sn * a21;
        superDiagonal.at(i1) = cs * a12 - sn * a22;
        diagonal.at(i2) = sn * a12 + cs * a22;

        if (i1 < iMax - 1)
        {
            auto a23 = superDiagonal.at(i2);
            a02 = -sn * a23;
            superDiagonal.at(i2) = cs * a23;

            /// ������һ��Givens��ת�Ĳ�����
            x = superDiagonal.at(i1);
            y = a02;
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeOrthogonalMatrices()
{
    /// ������ǰ�з�������ֵ������U��V��
    ComputeUOrthogonal();
    ComputeVOrthogonal();

    /// ȷ������ֵ�ǷǸ��ġ�
    /// ���ŵı仯��U�������գ�
    /// �Ǹ�ֵ���洢��S�����С�
    EnsureNonnegativeSingularValues();

    /// �����������ֵ��������
    /// �������б�U�����V�������ա�
    SortSingularValues();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeUOrthogonal()
{
    /// ��U�ĵ�λ����ʼ��
    std::fill(uMatrix.begin(), uMatrix.end(), Real{});
    for (auto d = 0; d < numRows; ++d)
    {
        const auto index = d + numRows * d;
        uMatrix.at(index) = Math::GetValue(1);
    }

    /// ʹ������ۼӳ���Householder���䡣
    /// ������DoHouseholderԤ�ˡ�
    /// ʹ��DoHouseholderPostMultiply�������ۼӲ������ã�
    /// ��ΪDoHouseHolderPostMultiple��������DoHousehouserPreMultiply���������в�ͬ��
    for (auto k = 0, col = numCols - 1; k <= numCols - 1; ++k, --col)
    {
        DoHouseholderPreMultiply(numRows, numRows, lHouseholder.at(col), col, uMatrix);
    }

    /// ʹ�������ۼӳ���Givens��ת��
    for (const auto& givens : lGivens)
    {
        auto j0 = givens.GetIndex0();
        auto j1 = givens.GetIndex1();
        for (auto row = 0; row < numRows; ++row, j0 += numRows, j1 += numRows)
        {
            auto& q0 = uMatrix.at(j0);
            auto& q1 = uMatrix.at(j1);
            const auto prd0 = givens.GetCs() * q0 - givens.GetSn() * q1;
            const auto prd1 = givens.GetSn() * q0 + givens.GetCs() * q1;
            q0 = prd0;
            q1 = prd1;
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::ComputeVOrthogonal()
{
    /// ��V�ĵ�λ����ʼ��
    std::fill(vMatrix.begin(), vMatrix.end(), Real{});
    for (auto d = 0; d < numCols; ++d)
    {
        const auto index = d + numCols * d;
        vMatrix.at(index) = Math::GetValue(1);
    }

    /// ʹ������ۼӳ���Householder���䡣
    /// ������DoHouseholderԤ�ˡ�
    /// ʹ��DoHouseholderPostMultiply�������ۼӲ������ã�
    /// ��ΪDoHouseHolderPostMultiple��������DoHousehouserPreMultiply���������в�ͬ��
    for (auto k = 0, col = numCols - 3; k <= numCols - 3; ++k, --col)
    {
        DoHouseholderPreMultiply(numCols, numCols, rHouseholder.at(col), col, vMatrix);
    }

    /// ʹ�������ۼӳ���Givens��ת��
    for (const auto& givens : rGivens)
    {
        auto j0 = givens.GetIndex0();
        auto j1 = givens.GetIndex1();
        for (auto col = 0; col < numCols; ++col, j0 += numCols, j1 += numCols)
        {
            auto& q0 = vMatrix.at(j0);
            auto& q1 = vMatrix.at(j1);
            const auto prd0 = givens.GetCs() * q0 - givens.GetSn() * q1;
            const auto prd1 = givens.GetSn() * q0 + givens.GetCs() * q1;
            q0 = prd0;
            q1 = prd1;
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::EnsureNonnegativeSingularValues()
{
    std::fill(sMatrix.begin(), sMatrix.end(), Real{});
    for (auto i = 0; i < numCols; ++i)
    {
        if (Real{} <= diagonal.at(i))
        {
            const auto index = i + numCols * i;
            sMatrix.at(index) = diagonal.at(i);
        }
        else
        {
            const auto index = i + numCols * i;
            sMatrix.at(index) = -diagonal.at(i);
            for (auto row = 0; row < numRows; ++row)
            {
                const auto elementIndex = i + numRows * row;
                auto& element = uMatrix.at(elementIndex);
                element = -element;
            }
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::Algebra::SingularValueDecomposition<Real>::SortSingularValues()
{
    /// �ԷǸ�����ֵ��������
    SingularInfoContainer sorted(numCols);
    for (auto i = 0; i < numCols; ++i)
    {
        const auto index = i + numCols * i;
        sorted.at(i).SetSingular(sMatrix.at(index));
        sorted.at(i).SetInversePermute(i);
    }
    std::sort(sorted.begin(), sorted.end(), std::greater<SingularInfo>());
    for (auto i = 0; i < numCols; ++i)
    {
        const auto index = i + numCols * i;
        sMatrix.at(index) = sorted.at(i).GetSingular();
    }

    // ��������������С�
    std::vector<int> permute(numCols);
    for (auto i = 0; i < numCols; ++i)
    {
        permute.at(sorted.at(i).GetInversePermute()) = i;
    }

    /// ��U������н���Permute����ʹ�������������ֵһ�¡�
    const auto sortedUMatrixCount = numRows * numRows;
    MatrixType sortedUMatrix(sortedUMatrixCount);
    auto col = 0;
    for (; col < numCols; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            const auto index = col + numRows * row;
            const auto& source = uMatrix.at(index);
            const auto sortedUMatrixIndex = permute.at(col) + numRows * row;
            auto& target = sortedUMatrix.at(sortedUMatrixIndex);
            target = source;
        }
    }
    for (; col < numRows; ++col)
    {
        for (auto row = 0; row < numRows; ++row)
        {
            const auto index = col + numRows * row;
            const auto& source = uMatrix.at(index);
            auto& target = sortedUMatrix.at(index);
            target = source;
        }
    }
    uMatrix = std::move(sortedUMatrix);

    /// ��V������н���Permute����ʹ�������������ֵһ�¡�
    const auto sortedVMatrixCount = numCols * numCols;
    MatrixType sortedVMatrix(sortedVMatrixCount);
    for (col = 0; col < numCols; ++col)
    {
        for (auto row = 0; row < numCols; ++row)
        {
            const auto index = col + numCols * row;
            const auto& source = vMatrix.at(index);
            const auto sortedVMatrixIndex = permute.at(col) + numCols * row;
            auto& target = sortedVMatrix.at(sortedVMatrixIndex);
            target = source;
        }
    }
    vMatrix = std::move(sortedVMatrix);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_SINGULAR_VALUE_DECOMPOSITION_DETAIL_H
