///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 19:23)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2
    {
    };

    template <typename Real>
    class LexicoArray2<true, Real>
    {
    public:
        using ClassType = LexicoArray2<true, Real>;
        using Container = std::vector<Real>;

    public:
        LexicoArray2(int numRows, int numCols, Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;
        NODISCARD Real& operator()(int32_t row, int32_t col);
        NODISCARD const Real& operator()(int32_t row, int32_t col) const;

    private:
        int numRows;
        int numCols;
        Container& matrix;
    };

    template <typename Real>
    class LexicoArray2<false, Real>
    {
    public:
        using ClassType = LexicoArray2<false, Real>;
        using Container = std::vector<Real>;

    public:
        LexicoArray2(int numRows, int numCols, Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumCols() const noexcept;
        NODISCARD Real& operator()(int32_t row, int32_t col);
        NODISCARD const Real& operator()(int32_t row, int32_t col) const;

    private:
        int numRows;
        int numCols;
        Container& matrix;
    };

    template <typename Real, int NumRows, int NumCols>
    class LexicoArray2<true, Real, NumRows, NumCols>
    {
    public:
        using ClassType = LexicoArray2<true, Real, NumRows, NumCols>;
        using Container = std::vector<Real>;

    public:
        LexicoArray2(Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumCols() noexcept;
        NODISCARD Real& operator()(int32_t row, int32_t col);
        NODISCARD const Real& operator()(int32_t row, int32_t col) const;

    private:
        Container& matrix;
    };

    template <typename Real, int NumRows, int NumCols>
    class LexicoArray2<false, Real, NumRows, NumCols>
    {
    public:
        using ClassType = LexicoArray2<false, Real, NumRows, NumCols>;
        using Container = std::vector<Real>;

    public:
        LexicoArray2(Container& matrix);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumCols() noexcept;
        NODISCARD Real& operator()(int32_t row, int32_t col);
        NODISCARD const Real& operator()(int32_t row, int32_t col) const;

    private:
        Container& matrix;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
