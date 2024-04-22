/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 15:50)

#ifndef CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H
#define CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/Operators.h"

#include <iterator>

/// ContainerAdapter��������ԭʼָ��ĵ�������ʵ�֡�
/// ��RawConstIterator��RawIterator�ṩ����һ�㡣
namespace CoreTools
{
    template <typename T>
    class RawConstIterator : private boost::totally_ordered<RawConstIterator<T>>
    {
    public:
        using ClassType = RawConstIterator<T>;

        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

    public:
        explicit RawConstIterator(pointer pointer, int offset = 0) noexcept;
        virtual ~RawConstIterator() noexcept = default;
        RawConstIterator(const RawConstIterator& rhs) = default;
        RawConstIterator& operator=(const RawConstIterator& rhs) = default;
        RawConstIterator(RawConstIterator&& rhs) noexcept = default;
        RawConstIterator& operator=(RawConstIterator&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD reference operator*() const noexcept;
        NODISCARD pointer operator->() const;
        NODISCARD reference operator[](ptrdiff_t offset) const;

        RawConstIterator& operator++() noexcept;
        RawConstIterator operator++(int) noexcept;
        RawConstIterator& operator--() noexcept;
        RawConstIterator operator--(int) noexcept;

        RawConstIterator& operator+=(ptrdiff_t offset) noexcept;
        NODISCARD RawConstIterator operator+(ptrdiff_t offset) const noexcept;

        RawConstIterator& operator-=(ptrdiff_t offset) noexcept;
        NODISCARD RawConstIterator operator-(ptrdiff_t offset) const noexcept;

        NODISCARD virtual ptrdiff_t operator-(const RawConstIterator& rhs) const noexcept;

        NODISCARD bool operator==(const RawConstIterator& rhs) const noexcept;
        NODISCARD bool operator<(const RawConstIterator& rhs) const noexcept;

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
        explicit RawIterator(pointer pointer, int offset = 0) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD reference operator*() noexcept;
        NODISCARD pointer operator->();

        RawIterator operator++() noexcept;
        RawIterator operator++(int) noexcept;

        RawIterator operator--() noexcept;
        RawIterator operator--(int) noexcept;

        RawIterator& operator+=(ptrdiff_t offset) noexcept;
        NODISCARD RawIterator operator+(ptrdiff_t offset) const noexcept;

        RawIterator& operator-=(ptrdiff_t offset) noexcept;
        NODISCARD RawIterator operator-(ptrdiff_t offset) const noexcept;

        NODISCARD ptrdiff_t operator-(const ParentType& rhs) const noexcept;
    };

}

#endif  // CORE_TOOLS_MEMORY_TOOLS_RAW_ITERATORS_H
