//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/19 16:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
    template <typename T>
    class SmartPointer3DArray final : private boost::equality_comparable<SmartPointer3DArray<T>, boost::equality_comparable<SmartPointer3DArray<T>, T***>>
    {
    public:
        using ClassType = SmartPointer3DArray<T>;
        using PointerType = T***;
        using ReferenceType = T**&;
        using ConstPointerType = T*** const;
        using ConstReferenceType = T** const&;

    public:
        // 允许T***到SmartPointer3DArray的隐式转换。如果要禁止，请同时删除SmartPointer3DArray& operator= (T*** data);
        SmartPointer3DArray(PointerType data = nullptr);
        ~SmartPointer3DArray() noexcept;

        SmartPointer3DArray(const SmartPointer3DArray& rhs);
        SmartPointer3DArray& operator=(PointerType data);
        SmartPointer3DArray& operator=(const SmartPointer3DArray& rhs);

        SmartPointer3DArray(SmartPointer3DArray&& rhs) noexcept;
        SmartPointer3DArray& operator=(SmartPointer3DArray&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConstPointerType GetData() const noexcept;
        [[nodiscard]] operator ConstPointerType() const noexcept;
        [[nodiscard]] ConstReferenceType operator*() const noexcept;

        [[nodiscard]] PointerType GetData() noexcept;
        [[nodiscard]] operator PointerType() noexcept;
        [[nodiscard]] ReferenceType operator*() noexcept;

    private:
        void Swap(SmartPointer3DArray& rhs) noexcept;

    private:
        PointerType m_Data;
    };

    template <typename T>
    bool operator==(const SmartPointer3DArray<T>& lhs, T*** data) noexcept;

    template <typename T>
    bool operator==(const SmartPointer3DArray<T>& lhs, const SmartPointer3DArray<T>& rhs) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_3D_ARRAY_H
