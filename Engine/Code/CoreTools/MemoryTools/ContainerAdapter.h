///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:32)

#ifndef CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H
#define CORE_TOOLS_MEMORY_TOOLS_CONTAINER_ADAPTER_H

#include "CoreTools/CoreToolsDll.h"

#include "RawIterators.h"

/// ContainerAdapter����һ������һά���ݵ����������ơ�
/// ���ṩ��std::array��std::vector������ĳ�Ա����������ʹ�û��ڷ�Χ�ĵ�����
/// �����ṩ���캯������װ������һ������ԭʼָ�롣

namespace CoreTools
{
    /// ��������Ҫģ�����std::vector�Ĵ󲿷ֽӿڣ���Դ������һ��ԭʼָ�롣
    /// ��֧�ֵĺ������Խ���std::array<T,N>���͵Ĳ��������߶���N��0������ʱ��֪��С��������ContainerAdapter<T,N>���͵��Ա�����
    /// ��֧�ֿ��Խ���std::vector<T>���ͻ�ContainerAdapter<T>����С��������ʱ��֪�����͵Ĳ����ĺ�����
    template <typename T, int...>
    class ContainerAdapter;

    template <typename T, int N>
    requires(N > 0)
    class ContainerAdapter<T, N>
    {
    public:
        using ClassType = ContainerAdapter<T, N>;

        using value_type = T;
        using size_type = int;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using iterator = RawIterator<T>;
        using const_iterator = RawConstIterator<T>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    public:
        /// ������ָ������Ԫ������ķǿ�ָ�롣���÷�����ȷ��Ԫ��������ΪN��
        /// ���һ��Ĭ�ϲ���numElements������������������ʵ�ַ��ͣ����캯������������
        explicit ContainerAdapter(T* elements, int numElements = N);

        /// ������������ԭʼ����һ����֪����˲��������κ����ݡ�
        /// �����������Ӧ�ó���������ط���̬����ģ�����÷����������䡣
        /// ���÷�����֤ContainerAdapterʹ��ʱ�ڴ����Ч�ԡ�
        ~ContainerAdapter() noexcept = default;

        /// ���ƹ��캯�������ã��Ա����ڶ���֮�乲��ԭʼָ�룬����������ϵͳ�ļ���ơ�
        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static int constexpr size() noexcept
        {
            return N;
        }

        NODISCARD T* GetData() noexcept;
        NODISCARD const T* GetData() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        NODISCARD iterator begin() noexcept;
        NODISCARD const_iterator begin() const noexcept;

        NODISCARD iterator end() noexcept;
        NODISCARD const_iterator end() const noexcept;

        NODISCARD reverse_iterator rbegin() noexcept;
        NODISCARD const_reverse_iterator rbegin() const noexcept;

        NODISCARD reverse_iterator rend() noexcept;
        NODISCARD const_reverse_iterator rend() const noexcept;

        NODISCARD const_iterator cbegin() const noexcept;
        NODISCARD const_iterator cend() const noexcept;

        NODISCARD const_reverse_iterator crbegin() const noexcept;
        NODISCARD const_reverse_iterator crend() const noexcept;

        /// ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value);

    private:
        T* elements;
    };

    template <typename T>
    class ContainerAdapter<T>
    {
    public:
        using ClassType = ContainerAdapter<T>;

        using value_type = T;
        using size_type = int;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using iterator = RawIterator<T>;
        using const_iterator = RawConstIterator<T>;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    public:
        /// ������ָ������Ԫ������ķǿ�ָ�롣���÷�����ȷ��Ԫ��������ΪnumElements��
        explicit ContainerAdapter(T* elements, int numElements = 0);

        /// ������������ԭʼ����һ����֪����˲��������κ����ݡ�
        /// �����������Ӧ�ó���������ط���̬����ģ�����÷����������䡣
        /// ���÷�����֤ContainerAdapterʹ��ʱ�ڴ����Ч�ԡ�
        ~ContainerAdapter() noexcept = default;

        /// ���ƹ��캯�������ã��Ա����ڶ���֮�乲��ԭʼָ�룬����������ϵͳ�ļ���ơ�
        ContainerAdapter(const ContainerAdapter& rhs) = delete;
        ContainerAdapter& operator=(const ContainerAdapter& rhs) = delete;

        ContainerAdapter(ContainerAdapter&& rhs) noexcept = delete;
        ContainerAdapter& operator=(ContainerAdapter&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int size() const noexcept;

        NODISCARD T* GetData() noexcept;
        NODISCARD const T* GetData() const noexcept;

        NODISCARD const T& operator[](int index) const;
        NODISCARD T& operator[](int index);

        NODISCARD iterator begin() noexcept;
        NODISCARD const_iterator begin() const noexcept;

        NODISCARD iterator end() noexcept;
        NODISCARD const_iterator end() const noexcept;

        NODISCARD reverse_iterator rbegin() noexcept;
        NODISCARD const_reverse_iterator rbegin() const noexcept;

        NODISCARD reverse_iterator rend() noexcept;
        NODISCARD const_reverse_iterator rend() const noexcept;

        NODISCARD const_iterator cbegin() const noexcept;
        NODISCARD const_iterator cend() const noexcept;

        NODISCARD const_reverse_iterator crbegin() const noexcept;
        NODISCARD const_reverse_iterator crend() const noexcept;

        /// ������Ԫ������Ϊָ��ֵ��
        void Fill(const T& value);

    private:
        int numElements;
        T* elements;
    };
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_ATOMIC_MIN_MAX_H