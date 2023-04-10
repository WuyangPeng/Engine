///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/10 10:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H
#define CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H

#include "CoreTools/CoreToolsDll.h"

#include <iterator>

namespace CoreTools
{
    template <typename T>
    class RawConstIterator
    {
    public:
        using ClassType = RawConstIterator<T>;

        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

    public:
        RawConstIterator() noexcept;
        explicit RawConstIterator(pointer pointer, size_t offset = 0) noexcept;
        virtual ~RawConstIterator() noexcept = default;
        RawConstIterator(const RawConstIterator& rhs) = default;
        RawConstIterator& operator=(const RawConstIterator& rhs) = default;
        RawConstIterator(RawConstIterator&& rhs) noexcept = default;
        RawConstIterator& operator=(RawConstIterator&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD reference operator*() const;
        NODISCARD pointer operator->() const;
        NODISCARD reference operator[](ptrdiff_t offset) const;

        RawConstIterator& operator++();
        RawConstIterator operator++(int);
        RawConstIterator& operator--();
        RawConstIterator operator--(int);

        RawConstIterator& operator+=(ptrdiff_t offset);
        NODISCARD RawConstIterator operator+(ptrdiff_t offset) const;

        RawConstIterator& operator-=(ptrdiff_t offset);
        NODISCARD RawConstIterator operator-(ptrdiff_t offset) const;

        NODISCARD ptrdiff_t operator-(RawConstIterator const& rhs) const;

        NODISCARD std::strong_ordering operator<=>(RawConstIterator const& rhs) const;

    private:
        pointer master;
    };

    template <typename T>
    class RawIterator final : public RawConstIterator<T>
    {
    public:
        using ClassType = RawIterator<T>;
        using ParentType = RawConstIterator<T>;

        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

    public:
        RawIterator() noexcept;
        explicit RawIterator(pointer pointer, size_t offset = 0);

        CLASS_INVARIANT_DECLARE;

        NODISCARD reference operator*();
        NODISCARD pointer operator->();

        RawIterator operator++();
        RawIterator operator++(int32_t);

        RawIterator operator--();
        RawIterator operator--(int32_t);

        RawIterator& operator+=(ptrdiff_t offset);
        NODISCARD RawIterator operator+(ptrdiff_t offset) const;

        RawIterator& operator-=(ptrdiff_t offset);
        NODISCARD RawIterator operator-(ptrdiff_t offset) const;
    };

}

#endif  // CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H
