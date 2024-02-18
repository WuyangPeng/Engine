/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/30 15:40)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/LexicoArray2.h"

#include <vector>

namespace Mathematics
{
    /// 输入矩阵matrix必须是NxN。
    /// 元素查找的存储约定由MATHEMATICS_USE_ROW_MAJOR决定。
    /// 如果你想要matrix的逆，传递一个wantInverse为true；
    /// 返回的inverse也必须是NxN，并使用与M相同的存储约定。
    /// 如果不需要matrix的逆，请为wantInverse传递false。
    /// 如果要求解matrix * x = b 的 x，其中x和b是Nx1，则传递b。
    /// 如果要为求解matrix * y = c的 y，其中y和c是NxK，则传递c，并将K传递给numColumns。
    /// 在所有情况下，将N传递给numRows。
    template <typename Real>
    class GaussianElimination final
    {
    public:
        using ClassType = GaussianElimination<Real>;

        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, int numColumns, const Container& c, Real epsilon = Math::GetZeroTolerance());
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsInverse() const noexcept;
        NODISCARD Container GetInverse() const;
        NODISCARD Container GetX() const;
        NODISCARD Container GetY() const;
        NODISCARD Real GetDeterminant() const noexcept;

    private:
        using IndexContainer = std::vector<int>;

#ifdef MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = LexicoArray2<true, Real>;

#else  // !MATHEMATICS_USE_ROW_MAJOR

        using LexicoArray2 = LexicoArray2<false, Real>;

#endif  // MATHEMATICS_USE_ROW_MAJOR

    private:
        void Init();

    private:
        int numRows;
        Container matrix;
        bool wantInverse;
        Container b;
        int numColumns;
        Container c;
        Real epsilon;

        bool isInverse;
        LexicoArray2 inverseMatrix;
        Real determinant;
        Container x;
        LexicoArray2 y;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H