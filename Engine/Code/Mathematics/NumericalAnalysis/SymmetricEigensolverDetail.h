///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 15:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_DETAIL_H

#include "SymmetricEigensolver.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TemplateTools/RangeIteration.h"

#include <gsl/util>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::SymmetricEigensolver<Real>::SymmetricEigensolver(int size, int maxIterations)
    : size{ size },
      maxIterations{ maxIterations },
      matrix(System::GetProduct(size, size)),
      diagonal(size),
      superDiagonal(System::GetMinus(size, 1)),
      givens(System::GetProduct(maxIterations, size - 1)),
      permutation(size),
      visited(size),
      eigenvectorMatrixType{ -1 },
      pVector(size),
      vVector(size),
      wVector(size)
{
    if (size <= 1 && maxIterations <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效参数。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SymmetricEigensolver<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver<Real>::TriDiagonalize()
{
    for (auto i = 0, ip1 = 1; i < size - 2; ++i, ++ip1)
    {
        /// 计算Householder矢量。
        /// 从矩阵的行中读取初始矢量。
        Real length{};
        for (auto r = 0; r < ip1; ++r)
        {
            vVector.at(r) = Real{};
        }

        for (auto r = ip1; r < size; ++r)
        {
            const auto index = r + size * i;
            const auto vr = matrix.at(index);
            vVector.at(r) = vr;

            length += vr * vr;
        }
        auto vdv = MathType::GetValue(1);
        length = MathType::Sqrt(length);
        if (Real{} < length)
        {
            auto& v1 = vVector.at(ip1);
            auto sgn = (Real{} <= v1 ? MathType::GetValue(1) : MathType::GetValue(-1));
            auto invDenominator = MathType::GetValue(1) / (v1 + sgn * length);
            v1 = MathType::GetValue(1);
            for (auto r = ip1 + 1; r < size; ++r)
            {
                auto& vr = vVector.at(r);
                vr *= invDenominator;
                vdv += vr * vr;
            }
        }

        /// 计算秩1偏移量v*w^T和w*v^T。
        const auto invVdv = MathType::GetValue(1) / vdv;
        Real twoInvVdv = invVdv * MathType::GetValue(2);
        Real pdvtVdv{};
        for (auto r = i; r < size; ++r)
        {
            pVector.at(r) = Real{};
            auto c = i;
            for (; c < r; ++c)
            {
                pVector.at(r) += matrix.at(r + gsl::narrow_cast<size_t>(size) * c) * vVector.at(c);
            }
            for (; c < size; ++c)
            {
                pVector.at(r) = matrix.at(c + gsl::narrow_cast<size_t>(size) * r) * vVector.at(c);
            }
            pVector.at(r) *= twoInvVdv;
            pdvtVdv += pVector.at(r) * vVector.at(r);
        }

        pdvtVdv *= invVdv;
        for (auto r = i; r < size; ++r)
        {
            wVector.at(r) = pVector.at(r) - pdvtVdv * vVector.at(r);
        }

        /// 更新输入矩阵。
        for (auto r = i; r < size; ++r)
        {
            const auto vr = vVector.at(r);
            const auto wr = wVector.at(r);
            auto offset = vr * wr * MathType::GetValue(2);
            matrix.at(r + gsl::narrow_cast<size_t>(size) * r) -= offset;
            for (auto c = r + 1; c < size; ++c)
            {
                offset = vr * wVector.at(c) + wr * vVector.at(c);
                matrix.at(c + gsl::narrow_cast<size_t>(size) * r) -= offset;
            }
        }

        /// 将矢量复制到矩阵的第i列。
        /// 不存储索引0到i处的0值分量。
        /// 索引i+1处的1值分量也不被存储；
        /// 相反，存储量2/Dot(v,v)以用于特征向量构造。
        /// 该构造必须考虑到未存储的隐含组件。
        matrix.at(i + gsl::narrow_cast<size_t>(size) * ip1) = twoInvVdv;
        for (auto r = ip1 + 1; r < size; ++r)
        {
            matrix.at(i + gsl::narrow_cast<size_t>(size) * r) = vVector.at(r);
        }
    }

    // 在QR迭代中复制对角线和次对角线条目以获得缓存一致性。
    auto k = 0;
    const auto ksup = size - 1;
    auto index = 0;
    const auto delta = size + 1;
    for (; k < ksup; ++k, index += delta)
    {
        diagonal.at(k) = matrix.at(index);
        superDiagonal.at(k) = matrix.at(gsl::narrow_cast<size_t>(index) + 1);
    }
    diagonal.at(k) = matrix.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver<Real>::GetSinCos(Real x, Real y, Real& cs, Real& sn) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    /// 鲁棒地求解 sn*x + cs*y = 0
    if (!MathType::Approximate(y, Real{}))
    {
        if (MathType::FAbs(x) < MathType::FAbs(y))
        {
            const auto tau = -x / y;
            sn = MathType::GetValue(1) / MathType::Sqrt(MathType::GetValue(1) + tau * tau);
            cs = sn * tau;
        }
        else
        {
            const auto tau = -y / x;
            cs = MathType::GetValue(1) / MathType::Sqrt(MathType::GetValue(1) + tau * tau);
            sn = cs * tau;
        }
    }
    else
    {
        cs = MathType::GetValue(1);
        sn = Real{};
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver<Real>::DoQrImplicitShift(int iMin, int iMax)
{
    /// 隐含的转变。
    /// 计算更接近a11的右下2x2块的特征值u。
    const auto a00 = diagonal.at(iMax);
    const auto a01 = superDiagonal.at(iMax);
    auto a11 = diagonal.at(gsl::narrow_cast<size_t>(iMax) + 1);
    const auto dif = (a00 - a11) * MathType::GetRational(1, 2);
    const auto sgn = (Real{} <= dif ? MathType::GetValue(1) : MathType::GetValue(-1));
    const auto a01Sqr = a01 * a01;
    const auto u = a11 - a01Sqr / (dif + sgn * MathType::Sqrt(dif * dif + a01Sqr));
    auto x = diagonal.at(iMin) - u;
    auto y = superDiagonal.at(iMin);

    auto i0 = iMin - 1;
    auto i1 = iMin;
    auto i2 = iMin + 1;

    Real a02{};
    for (; i1 <= iMax; ++i0, ++i1, ++i2)
    {
        Real cs{};
        Real sn{};

        /// 计算Givens旋转并将其保存以用于计算特征向量。
        GetSinCos(x, y, cs, sn);
        givens.emplace_back(i1, cs, sn);

        /// 更新三对角矩阵。这相当于更新4x4子块，
        ///   b00 b01 b02 b03
        ///   b01 b11 b12 b13
        ///   b02 b12 b22 b23
        ///   b03 b13 b23 b33
        /// 四个角(b00, b03, b33)的值不变。
        /// 内部块 {{b11,b12},{b12,b22}}在每次传递时都会更新。
        /// 对于第一次传递，b0c值超出范围，因此只有值(b13, b23) 会更改。
        /// 对于最后一次传递，br3值超出范围，因此只有值(b01, b02)发生更改。
        /// 对于第一个和最后一个之间的过程，值(b01, b02, b13, b23)会发生变化。
        if (iMin < i1)
        {
            superDiagonal.at(i0) = cs * superDiagonal.at(i0) - sn * a02;
        }

        a11 = diagonal.at(i1);
        auto a12 = superDiagonal.at(i1);
        auto a22 = diagonal.at(i2);
        auto tmp11 = cs * a11 - sn * a12;
        auto tmp12 = cs * a12 - sn * a22;
        auto tmp21 = sn * a11 + cs * a12;
        auto tmp22 = sn * a12 + cs * a22;
        diagonal.at(i1) = cs * tmp11 - sn * tmp12;
        superDiagonal.at(i1) = sn * tmp11 + cs * tmp12;
        diagonal.at(i2) = sn * tmp21 + cs * tmp22;

        if (i1 < iMax)
        {
            auto a23 = superDiagonal.at(i2);
            a02 = -sn * a23;
            superDiagonal.at(i2) = cs * a23;

            /// 更新下一次Givens旋转的参数。
            x = superDiagonal.at(i1);
            y = a02;
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver<Real>::ComputePermutation(int32_t sortType)
{
    /// Householder反射的数量为H = size - 2。
    /// 如果H是偶数，则Householder反射的乘积是旋转；
    /// 否则，H是奇数，乘积是反射。
    /// Givens旋转的次数不会影响Householder反射的乘积类型。
    eigenvectorMatrixType = 1 - (size & 1);

    if (sortType == 0)
    {
        /// 为GetEigenvalues()和GetEigenvectors()设置一个标志，以知道未请求排序输出。
        permutation.at(0) = -1;

        return;
    }

    SortItemContainer items(size);

    for (auto i = 0; i < size; ++i)
    {
        items.at(i).SetEigenvalue(diagonal.at(i));
        items.at(i).SetIndex(i);
    }

    if (0 < sortType)
    {
        std::sort(items.begin(), items.end(),
                  [](const SortItemType& lhs, const SortItemType& rhs) noexcept {
                      return lhs.GetEigenvalue() < rhs.GetEigenvalue();
                  });
    }
    else
    {
        std::sort(items.begin(), items.end(),
                  [](const SortItemType& lhs, const SortItemType& rhs) noexcept {
                      return rhs.GetEigenvalue() < lhs.GetEigenvalue();
                  });
    }

    auto i = 0;
    for (auto const& item : items)
    {
        permutation.at(i++) = item.GetIndex();
    }

    /// GetEigenvectors()具有用于根据反射和旋转计算正交Q的非平凡代码。
    /// 为了避免在请求排序时使代码进一步复杂化，在未排序的情况下计算Q。
    /// 然后，我们需要交换Q的列，以与特征值的排序一致。
    /// 为了最大限度地减少由于列交换引起的复制，我们使用置换P。
    /// 从I获得P的最小转座次数是N减去P的循环次数。
    /// 每个循环都用最小的转座次数重新排序；
    /// 也就是说，本征项被循环交换，从而导致最小的复制量。
    /// 例如，如果有一个循环i0 -> i1 -> i2 -> i3，则复制为
    ///   save = eigenitem[i0];
    ///   eigenitem[i1] = eigenitem[i2];
    ///   eigenitem[i2] = eigenitem[i3];
    ///   eigenitem[i3] = save;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::SymmetricEigensolver<Real>::Solve(const MatrixType& input, int sortType)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    eigenvectorMatrixType = -1;

    if (0 < size)
    {
        matrix = input;

        TriDiagonalize();

        givens.clear();
        for (auto j = 0; j < maxIterations; ++j)
        {
            auto iMin = -1;
            auto iMax = -1;
            for (auto i = size - 2; i >= 0; --i)
            {
                /// 当a01比它的对角邻居小得多时，它实际上是零。
                const auto a00 = diagonal.at(i);
                const auto a01 = superDiagonal.at(i);
                const auto a11 = diagonal.at(gsl::narrow_cast<size_t>(i) + 1);
                const auto sum = MathType::FAbs(a00) + MathType::FAbs(a11);
                if (sum + MathType::FAbs(a01) != sum)
                {
                    if (iMax == -1)
                    {
                        iMax = i;
                    }
                    iMin = i;
                }
                else
                {
                    /// 与相邻的对角线项相比，超对角线项实际上为零。
                    if (0 <= iMin)
                    {
                        break;
                    }
                }
            }

            if (iMax == -1)
            {
                /// 算法已经收敛。
                ComputePermutation(sortType);
                return j;
            }

            /// 处理右下角最未还原的三对角块。
            DoQrImplicitShift(iMin, iMax);
        }
        return -1;
    }
    else
    {
        return 0;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::SymmetricEigensolver<Real>::DiagonalType Mathematics::SymmetricEigensolver<Real>::GetEigenvalues() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    DiagonalType eigenvalues{};

    if (0 < size)
    {
        if (0 <= permutation.at(0))
        {
            /// 已请求排序。
            for (auto i = 0; i < size; ++i)
            {
                const auto p = permutation.at(i);
                eigenvalues.at(i) = diagonal.at(p);
            }
        }
        else
        {
            /// 未请求排序。
            eigenvalues = diagonal;
        }
    }

    return eigenvalues;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::SymmetricEigensolver<Real>::MatrixType Mathematics::SymmetricEigensolver<Real>::GetEigenvectors() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MatrixType eigenvectors(gsl::narrow_cast<size_t>(size) * gsl::narrow_cast<size_t>(size));
    eigenvectorMatrixType = -1;

    if (0 < size)
    {
        /// 从单位矩阵开始。
        for (auto d = 0; d < size; ++d)
        {
            eigenvectors.at(d + gsl::narrow_cast<size_t>(size) * d) = MathType::GetValue(1);
        }

        /// 使用向后累加乘以Householder反射。
        for (auto i = size - 3, rMin = i + 1; i >= 0; --i, --rMin)
        {
            /// 从矩阵中复制v矢量和2/Dot(v,v)。
            const auto index = i + size * (i + 1);
            const auto twoInvVdv = matrix.at(index);
            auto r = 0;
            for (; r < i + 1; ++r)
            {
                vVector.at(r) = Real{};
            }
            vVector.at(r) = MathType::GetValue(1);
            for (++r; r < size; ++r)
            {
                vVector.at(r) = matrix.at(i + gsl::narrow_cast<size_t>(size) * r);
            }

            /// 计算w向量。
            for (r = 0; r < size; ++r)
            {
                wVector.at(r) = Real{};
                for (auto c = rMin; c < size; ++c)
                {
                    wVector.at(r) += vVector.at(c) * eigenvectors.at(r + gsl::narrow_cast<size_t>(size) * c);
                }
                wVector.at(r) *= twoInvVdv;
            }

            /// 更新矩阵，Q <- Q - v*w^T。
            for (r = rMin; r < size; ++r)
            {
                for (auto c = 0; c < size; ++c)
                {
                    eigenvectors.at(c + gsl::narrow_cast<size_t>(size) * r) -= vVector.at(r) * wVector.at(c);
                }
            }
        }

        /// 乘以Givens旋转。
        for (const auto& given : givens)
        {
            for (auto r = 0; r < size; ++r)
            {
                const auto j = given.GetIndex() + size * r;
                auto& q0 = eigenvectors.at(j);
                auto& q1 = eigenvectors.at(System::GetPlus(j, 1));
                auto prd0 = given.GetCs() * q0 - given.GetSn() * q1;
                auto prd1 = given.GetSn() * q0 + given.GetCs() * q1;
                q0 = prd0;
                q1 = prd1;
            }
        }

        /// Householder反射的数量为H = mSize - 2。
        /// 如果H是偶数，则Householder反射的乘积是旋转；
        /// 否则，H是奇数，乘积是反射。
        /// Givens旋转的次数不会影响Householder反射的乘积类型。
        eigenvectorMatrixType = 1 - (size & 1);

        if (0 <= permutation.at(0))
        {
            /// 已请求排序。
            std::ranges::fill(visited, 0);
            for (auto i = 0; i < size; ++i)
            {
                if (visited.at(i) == 0 && permutation.at(i) != i)
                {
                    /// 项目开始一个包含2个或多个元素的循环。
                    const auto start = i;
                    auto current = i;
                    for (auto j = 0; j < size; ++j)
                    {
                        pVector.at(j) = eigenvectors.at(i + gsl::narrow_cast<size_t>(size) * j);
                    }
                    auto next = permutation.at(current);
                    while (next != start)
                    {
                        eigenvectorMatrixType = 1 - eigenvectorMatrixType;
                        visited.at(current) = 1;
                        for (auto j = 0; j < size; ++j)
                        {
                            eigenvectors.at(current + gsl::narrow_cast<size_t>(size) * j) = eigenvectors.at(next + gsl::narrow_cast<size_t>(size) * j);
                        }
                        current = next;
                        next = permutation.at(current);
                    }
                    visited.at(current) = 1;
                    for (auto j = 0; j < size; ++j)
                    {
                        eigenvectors.at(current + gsl::narrow_cast<size_t>(size) * j) = pVector.at(j);
                    }
                }
            }
        }
    }

    return eigenvectors;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::SymmetricEigensolver<Real>::GetEigenvectorMatrixType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return eigenvectorMatrixType;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::SymmetricEigensolver<Real>::DiagonalType Mathematics::SymmetricEigensolver<Real>::GetEigenvector(int c) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    DiagonalType eigenvector(size);

    if (0 <= c && c < size)
    {
        /// y = H*x，则x和y被交换为下一个H
        auto& x = eigenvector;
        auto& y = pVector;

        /// 从欧几里得基向量开始。
        if (0 <= permutation.at(0))
        {
            /// 已请求排序。
            x.at(permutation.at(c)) = MathType::GetValue(1);
        }
        else
        {
            x.at(c) = MathType::GetValue(1);
        }

        /// 应用Givens旋转。
        for (const auto& given : CoreTools::Reverse(givens))
        {
            auto& xr = x.at(given.GetIndex());
            auto& xrp1 = x.at(System::GetPlus(given.GetIndex(), 1));
            const auto tmp0 = given.GetCs() * xr + given.GetSn() * xrp1;
            const auto tmp1 = -given.GetSn() * xr + given.GetCs() * xrp1;
            xr = tmp0;
            xrp1 = tmp1;
        }

        /// 应用Householder反射。
        for (auto i = size - 3; i >= 0; --i)
        {
            /// 获取Householder向量v。
            const auto index = i + size * (i + 1);
            auto twoInvVdv = matrix.at(index);
            auto r = 0;
            for (; r <= i; ++r)
            {
                y.at(r) = x.at(r);
            }

            /// 计算 s = Dot(x,v) * 2/v^T*v.
            ///
            /// 在代码的这一点上，r = i + 1。
            /// 在i-loop条目中，r = size-2。
            /// 在i-loop退出时，r = 1。
            /// 这将r保持在x[]的有效范围内。

            auto s = x.at(r);  // r = i+1, v[i+1] = 1

            /// 请注意，在i-loop条目中，r = size-2，
            /// 在这种情况下，r+1 = mSize-1。
            /// 这将索引j保持在x[]的有效范围内。
            for (auto j = r + 1; j < size; ++j)
            {
                s += x.at(j) * matrix.at(i + gsl::narrow_cast<size_t>(size) * j);
            }
            s *= twoInvVdv;

            y.at(r) = x.at(r) - s;  // v[i+1] = 1

            /// 计算y的剩余分量。
            for (++r; r < size; ++r)
            {
                y.at(r) = x.at(r) - s * matrix.at(i + gsl::narrow_cast<size_t>(size) * r);
            }

            std::swap(x, y);
        }

        /// 最终产品存储在x中。
        if (&x != &eigenvector)
        {
            eigenvector = x;
        }
    }

    return eigenvector;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real Mathematics::SymmetricEigensolver<Real>::GetEigenvalue(int c) const
{
    if (0 < size)
    {
        if (0 <= permutation.at(0))
        {
            /// 已请求排序。
            return diagonal.at(permutation.at(c));
        }
        else
        {
            /// 未请求排序。
            return diagonal.at(c);
        }
    }
    else
    {
        return std::numeric_limits<Real>::max();
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER_DETAIL_H
