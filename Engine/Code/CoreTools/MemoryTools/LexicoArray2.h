/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/22 15:12)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    /// 一个模板类，用于提供符合行主序（RowMajor = true）或列主序（RowMajor = false）的二维数组访问。
    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2
    {
    };

    // 数组维度只有在运行时才知道。
    template <typename Real>
    class LexicoArray2<true, Real>
    {
    public:
        using ClassType = LexicoArray2<true, Real>;

        using Container = std::vector<Real>;

    public:
        LexicoArray2(int numRows, int numColumns, Container& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

    private:
        int numRows;
        int numColumns;
        Container& matrix;
    };

    template <typename Real>
    class LexicoArray2<false, Real>
    {
    public:
        using ClassType = LexicoArray2<false, Real>;

        using Container = std::vector<Real>;

    public:
        LexicoArray2(int numRows, int numColumns, Container& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

    private:
        int numRows;
        int numColumns;
        Container& matrix;
    };

    // 数组维度在编译时是已知的。
    template <typename Real, int NumRows, int NumColumns>
    class LexicoArray2<true, Real, NumRows, NumColumns>
    {
    public:
        using ClassType = LexicoArray2<true, Real, NumRows, NumColumns>;

        using Container = std::vector<Real>;

    public:
        explicit LexicoArray2(Container& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumColumns() noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

    private:
        Container& matrix;
    };

    template <typename Real, int NumRows, int NumColumns>
    class LexicoArray2<false, Real, NumRows, NumColumns>
    {
    public:
        using ClassType = LexicoArray2<false, Real, NumRows, NumColumns>;

        using Container = std::vector<Real>;

    public:
        explicit LexicoArray2(Container& matrix) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumColumns() noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

    private:
        Container& matrix;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
