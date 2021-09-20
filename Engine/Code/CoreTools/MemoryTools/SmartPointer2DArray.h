//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/19 16:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
    template <typename T>
    class SmartPointer2DArray final : private boost::equality_comparable<SmartPointer2DArray<T>, boost::equality_comparable<SmartPointer2DArray<T>, T**>>
    {
    public:
        using ClassType = SmartPointer2DArray<T>;
        using PointerType = T**;
        using ReferenceType = T*&;
        using ConstPointerType = T** const;
        using ConstReferenceType = T* const&;

    public:
        // 允许T**到SmartPointer2DArray的隐式转换。如果要禁止，请同时删除SmartPointer2DArray& operator= (T** data);
        SmartPointer2DArray(PointerType data = nullptr);
        ~SmartPointer2DArray() noexcept;

        SmartPointer2DArray(const SmartPointer2DArray& rhs);
        SmartPointer2DArray& operator=(PointerType data);
        SmartPointer2DArray& operator=(const SmartPointer2DArray& rhs);

        SmartPointer2DArray(SmartPointer2DArray&& rhs) noexcept;
        SmartPointer2DArray& operator=(SmartPointer2DArray&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConstPointerType const GetData() const noexcept;
        [[nodiscard]] operator ConstPointerType() const noexcept;
        [[nodiscard]] ConstReferenceType operator*() const noexcept;

        [[nodiscard]] PointerType GetData() noexcept;
        [[nodiscard]] operator PointerType() noexcept;
        [[nodiscard]] ReferenceType operator*() noexcept;

    private:
        void Swap(SmartPointer2DArray& rhs) noexcept;

    private:
        PointerType m_Data;
    };

    template <typename T>
    bool operator==(const SmartPointer2DArray<T>& lhs, T** data) noexcept;

    template <typename T>
    bool operator==(const SmartPointer2DArray<T>& lhs, const SmartPointer2DArray<T>& rhs) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_2D_ARRAY_H
