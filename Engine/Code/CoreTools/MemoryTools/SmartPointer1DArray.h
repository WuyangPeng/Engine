//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/19 16:47)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
    template <typename T>
    class SmartPointer1DArray final : private boost::equality_comparable<SmartPointer1DArray<T>, boost::equality_comparable<SmartPointer1DArray<T>, T*>>
    {
    public:
        using ClassType = SmartPointer1DArray<T>;
        using PointerType = T*;
        using ReferenceType = T&;
        using ConstPointerType = const T*;
        using ConstReferenceType = const T&;

    public:
        // ����T*��SmartPointer1DArray����ʽת�������Ҫ��ֹ����ͬʱɾ��SmartPointer1DArray& operator= (T* data);
        SmartPointer1DArray(PointerType data = nullptr);
        ~SmartPointer1DArray() noexcept;

        SmartPointer1DArray(const SmartPointer1DArray& rhs);
        SmartPointer1DArray& operator=(PointerType data);
        SmartPointer1DArray& operator=(const SmartPointer1DArray& rhs);

        SmartPointer1DArray(SmartPointer1DArray&& rhs) noexcept;
        SmartPointer1DArray& operator=(SmartPointer1DArray&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConstPointerType GetData() const noexcept;
        [[nodiscard]] operator ConstPointerType() const noexcept;
        [[nodiscard]] ConstReferenceType operator*() const noexcept;
        [[nodiscard]] ConstPointerType operator->() const noexcept;

        [[nodiscard]] PointerType GetData() noexcept;
        [[nodiscard]] operator PointerType() noexcept;
        [[nodiscard]] ReferenceType operator*() noexcept;
        [[nodiscard]] PointerType operator->() noexcept;

    private:
        void Swap(SmartPointer1DArray& rhs) noexcept;

    private:
        PointerType m_Data;
    };

    template <typename T>
    bool operator==(const SmartPointer1DArray<T>& lhs, T* data) noexcept;

    template <typename T>
    bool operator==(const SmartPointer1DArray<T>& lhs, const SmartPointer1DArray<T>& rhs) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_1D_ARRAY_H
