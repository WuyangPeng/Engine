///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:53)

#ifndef MATHEMATICS_BASE_LEXICO_ARRAY2_H
#define MATHEMATICS_BASE_LEXICO_ARRAY2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/BaseFwd.h"

#include <vector>

namespace Mathematics
{
    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2;

    template <typename Real>
    class LexicoArray2<true, Real>
    {
    public:
        using ClassType = LexicoArray2<true, Real>;

        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        LexicoArray2(int numRows, int numCols, const Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        NODISCARD Container GetContainer() const;

        void Clear();

    private:
        int numRows;
        int numCols;
        Container matrix;
    };

    template <typename Real>
    class LexicoArray2<false, Real>
    {
    public:
        using ClassType = LexicoArray2<false, Real>;

        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        LexicoArray2(int numRows, int numCols, const Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        NODISCARD Container GetContainer() const;

        void Clear();

    private:
        int numRows;
        int numCols;
        Container matrix;
    };

    template <typename Real, int NumRows, int NumCols>
    class LexicoArray2<true, Real, NumRows, NumCols>
    {
    public:
        using ClassType = LexicoArray2<true, Real, NumRows, NumCols>;

        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        explicit LexicoArray2(const Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        NODISCARD Container GetContainer() const;

        void Clear();

    private:
        Container matrix;
    };

    template <typename Real, int NumRows, int NumCols>
    class LexicoArray2<false, Real, NumRows, NumCols>
    {
    public:
        using ClassType = LexicoArray2<false, Real, NumRows, NumCols>;

        using Container = std::vector<Real>;
        using Math = Math<Real>;

    public:
        explicit LexicoArray2(const Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        NODISCARD Container GetContainer() const;

        void Clear();

    private:
        Container matrix;
    };
}

#endif  // MATHEMATICS_BASE_LEXICO_ARRAY2_H
