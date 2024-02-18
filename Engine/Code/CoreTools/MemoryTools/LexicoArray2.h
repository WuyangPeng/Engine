/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/01/22 15:12)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include <vector>

namespace CoreTools
{
    /// һ��ģ���࣬�����ṩ����������RowMajor = true����������RowMajor = false���Ķ�ά������ʡ�
    template <bool RowMajor, typename Real, int... Dimensions>
    class LexicoArray2
    {
    };

    // ����ά��ֻ��������ʱ��֪����
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

    // ����ά���ڱ���ʱ����֪�ġ�
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
