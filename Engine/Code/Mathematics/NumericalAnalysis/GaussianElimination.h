///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 10:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/BaseFwd.h"
#include "Mathematics/Base/LexicoArray2.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class GaussianElimination final
    {
    public:
        using ClassType = GaussianElimination<Real>;
        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, const Container& b, int numCols, const Container& c, Real epsilon = Math::GetZeroTolerance());
        GaussianElimination(int numRows, const Container& matrix, bool wantInverse, Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsInverse() const noexcept;
        NODISCARD Container GetInverse() const;
        NODISCARD Container GetX() const;
        NODISCARD Container GetY() const;
        NODISCARD Real GetDeterminant() const noexcept;

    private:
        using IndexContainer = std::vector<int>;

    private:
        void Init();

    private:
        int numRows;
        Container matrix;
        bool wantInverse;
        Container b;
        int numCols;
        Container c;
        Real epsilon;

        bool isInverse;
        LexicoArray2<true, Real> inverseMatrix;
        Real determinant;
        Container x;
        LexicoArray2<true, Real> y;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_H