///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:31)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H

#include "CoreTools/CoreToolsDll.h"

#include "Lattice.h"

#include <array>

/// Lattice�ฺ����������ڴ����ж�������
/// MultiArray�ฺ���ṩ�ڴ档���̳���Lattice��
namespace CoreTools
{
    // ����ʱ��֪��С�Ķ�ά�����ʵ�֡�
    template <typename T, bool OrderLToR, int... Sizes>
    class MultiArray final : public Lattice<OrderLToR, Sizes...>, private boost::totally_ordered<MultiArray<T, OrderLToR, Sizes...>>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��ȡָ��Ԫ�������ָ�롣
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // ����ָ����������Ԫ�ء�
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value);

        // ��ȡ��������nά���������Ӧ��Ԫ�ء�
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // ��ȡ��nά�����Ӧ��Ԫ�ء�
        NODISCARD const T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate);

        // ֧�ֶԶ�ά��������������ͱȽ�
        NODISCARD bool operator==(const MultiArray& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArray& rhs) const noexcept;

    private:
        static constexpr auto numElements = Lattice<OrderLToR, Sizes...>::numElements;
        using Container = std::array<T, numElements>;

    private:
        Container container;
    };

    // ��������ʱ��֪�����С�Ķ������ʵ�֡�
    template <typename T, bool OrderLToR>
    class MultiArray<T, OrderLToR> final : public Lattice<OrderLToR>, private boost::totally_ordered<MultiArray<T, OrderLToR>>
    {
    public:
        using ClassType = MultiArray<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;

        using SizeType = std::vector<int>;

    public:
        MultiArray() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ��ά�������ָ���Ĵ�С��
        explicit MultiArray(const SizeType& sizes);
        explicit MultiArray(const std::initializer_list<int>& sizes);

        /// ֧����Ĭ�Ϲ��캯��������ʼ��ά������ӳٹ��졣
        /// ���Ժ��ִ�й����У����Ը�����Ҫ���ö�ά����Ĵ�С��
        void Reset(const SizeType& sizes) override;
        void Reset(const std::initializer_list<int>& sizes) override;

        // ��ȡָ��Ԫ�������ָ�롣
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // ����ָ����������Ԫ�ء�
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value);

        // ��ȡ��������nά���������Ӧ��Ԫ�ء�
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // ��ȡ��nά�����Ӧ��Ԫ�ء�
        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

        // ֧�ֶԶ�ά��������������ͱȽ�
        NODISCARD bool operator==(const MultiArray& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArray& rhs) const noexcept;

    private:
        using Container = std::vector<T>;

    private:
        Container container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_H
