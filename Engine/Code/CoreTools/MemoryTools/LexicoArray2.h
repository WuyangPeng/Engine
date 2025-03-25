/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 15:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Base/SpanIterator.h"

#include <vector>

namespace CoreTools
{
    /// һ��ģ���࣬�����ṩ����������RowMajor = true����������RowMajor = false���Ķ�ά������ʡ�
    template <bool RowMajor, typename Iter, int... Dimensions>
    class LexicoArray2
    {
    };

    /// ����ά��ֻ��������ʱ��֪����
    template <typename Iter>
    class LexicoArray2<true, Iter>
    {
    public:
        using ClassType = LexicoArray2<true, Iter>;

        using SpanIteratorType = SpanIterator<Iter>;
        using Real = typename SpanIteratorType::ValueType;

    public:
        LexicoArray2(int numRows, int numColumns, const SpanIteratorType& matrix) noexcept;
        LexicoArray2(int numRows, int numColumns, const Iter& begin, const Iter& end) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        template <typename Container>
        NODISCARD Container GetContainer() const;

        void FillZero();

    private:
        int numRows;
        int numColumns;
        SpanIteratorType matrix;
    };

    template <typename Iter>
    class LexicoArray2<false, Iter>
    {
    public:
        using ClassType = LexicoArray2<false, Iter>;

        using SpanIteratorType = SpanIterator<Iter>;
        using Real = typename SpanIteratorType::ValueType;

    public:
        LexicoArray2(int numRows, int numColumns, const SpanIteratorType& matrix) noexcept;
        LexicoArray2(int numRows, int numColumns, const Iter& begin, const Iter& end) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumRows() const noexcept;
        NODISCARD int GetNumColumns() const noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        template <typename Container>
        NODISCARD Container GetContainer() const;

        void FillZero();

    private:
        int numRows;
        int numColumns;
        SpanIteratorType matrix;
    };

    /// ����ά���ڱ���ʱ����֪�ġ�
    template <typename Iter, int NumRows, int NumColumns>
    class LexicoArray2<true, Iter, NumRows, NumColumns>
    {
    public:
        using ClassType = LexicoArray2<true, Iter, NumRows, NumColumns>;

        using SpanIteratorType = SpanIterator<Iter>;
        using Real = typename SpanIteratorType::ValueType;

    public:
        explicit LexicoArray2(const SpanIteratorType& matrix) noexcept;
        LexicoArray2(const Iter& begin, const Iter& end) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumColumns() noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        template <typename Container>
        NODISCARD Container GetContainer() const;

        void FillZero();

    private:
        SpanIteratorType matrix;
    };

    template <typename Iter, int NumRows, int NumColumns>
    class LexicoArray2<false, Iter, NumRows, NumColumns>
    {
    public:
        using ClassType = LexicoArray2<false, Iter, NumRows, NumColumns>;

        using SpanIteratorType = SpanIterator<Iter>;
        using Real = typename SpanIteratorType::ValueType;

    public:
        explicit LexicoArray2(const SpanIteratorType& matrix) noexcept;
        LexicoArray2(const Iter& begin, const Iter& end) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int GetNumRows() noexcept;
        NODISCARD static int GetNumColumns() noexcept;
        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        template <typename Container>
        NODISCARD Container GetContainer() const;

        void FillZero();

    private:
        SpanIteratorType matrix;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ARRAY2_H
