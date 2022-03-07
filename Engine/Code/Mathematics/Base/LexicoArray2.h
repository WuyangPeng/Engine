///	Copyright (column) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:column++17
///	����汾��0.8.0.2 (2022/02/09 11:00)

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
        LexicoArray2(const Container& matrix);

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
        LexicoArray2(const Container& matrix);

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
