///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:30)

#ifndef CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "Lattice.h"

/// ��MultiArrayAdapterʵ������MultiArray������ͬ�Ľӿڣ�ֻ�Ǵ洢��ԭʼָ�������ⲿԴ�ṩ�ġ�
/// ��Ϊԭʼָ�����ⲿ�ģ������๲��ԭʼָ�룬���Ը��ƺ��ƶ����屻���á�
namespace CoreTools
{
    /// ����ʱ��֪��С�Ķ�ά������������ʵ�֡�
    template <typename T, bool OrderLToR, int... Sizes>
    class MultiArrayAdapter final : public Lattice<OrderLToR, Sizes...>, private boost::totally_ordered<MultiArrayAdapter<T, OrderLToR, Sizes...>>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR, Sizes...>;
        using ParentType = Lattice<OrderLToR, Sizes...>;

    public:
        explicit MultiArrayAdapter(T* container);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Reset(T* aContainer);

        // ��ȡָ��Ԫ�������ָ�롣
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // ����ָ����������Ԫ�ء�
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value) noexcept;

        // ��ȡ��������nά���������Ӧ��Ԫ�ء�
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const noexcept;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple) noexcept;

        // ��ȡ��nά�����Ӧ��Ԫ�ء�
        NODISCARD const T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate) const;
        NODISCARD T& operator()(const std::array<int, sizeof...(Sizes)>& coordinate);

        // ֧�ֶ�MultiArrayAdapter�����������ͱȽϡ�
        NODISCARD bool operator==(const MultiArrayAdapter& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArrayAdapter& rhs) const noexcept;

    private:
        // ָ�����ָ��洢Lattice<OrderLToR, Sizes...>::GetSize()���ڴ���T����
        T* container;
    };

    // ��������ʱ��֪�����С�Ķ�ά�����ʵ�֡�
    template <typename T, bool OrderLToR>
    class MultiArrayAdapter<T, OrderLToR> final : public Lattice<OrderLToR>
    {
    public:
        using ClassType = MultiArrayAdapter<T, OrderLToR>;
        using ParentType = Lattice<OrderLToR>;

        using SizeType = std::vector<int>;

    public:
        MultiArrayAdapter(const SizeType& sizes, T* container);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Reset(const SizeType& sizes, T* aContainer);

        ~MultiArrayAdapter() noexcept = default;

        MultiArrayAdapter(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter& operator=(const MultiArrayAdapter& rhs) = delete;
        MultiArrayAdapter(MultiArrayAdapter&& rhs) noexcept = delete;
        MultiArrayAdapter& operator=(MultiArrayAdapter&& rhs) noexcept = delete;

        // ��ȡָ��Ԫ�������ָ�롣
        NODISCARD const T* GetData() const noexcept;
        NODISCARD T* GetData() noexcept;

        // ����ָ����������Ԫ�ء�
        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        // ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value) noexcept;

        // ��ȡ��������nά���������Ӧ��Ԫ�ء�
        template <typename... IndexTypes>
        NODISCARD const T& operator()(IndexTypes... tuple) const;

        template <typename... IndexTypes>
        NODISCARD T& operator()(IndexTypes... tuple);

        // ��ȡ��nά�����Ӧ��Ԫ�ء�
        NODISCARD const T& operator()(const SizeType& coordinate) const;
        NODISCARD T& operator()(const SizeType& coordinate);

        // ֧�ֶ�MultiArrayAdapter�����������ͱȽϡ�
        NODISCARD bool operator==(const MultiArrayAdapter& rhs) const noexcept;
        NODISCARD bool operator<(const MultiArrayAdapter& rhs) const noexcept;

    private:
        // ָ�����ָ��洢Lattice<OrderLToR>::GetSize()���ڴ���T����
        T* container;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_MULTI_ARRAY_ADAPTER_H
