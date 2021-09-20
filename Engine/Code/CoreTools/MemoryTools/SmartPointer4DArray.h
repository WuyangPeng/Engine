//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/19 16:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
    template <typename T>
    class SmartPointer4DArray final : private boost::equality_comparable<SmartPointer4DArray<T>, boost::equality_comparable<SmartPointer4DArray<T>, T****>>
    {
    public:
        using ClassType = SmartPointer4DArray<T>;
        using PointerType = T****;
        using ReferenceType = T***&;
        using ConstPointerType = T**** const;
        using ConstReferenceType = T*** const&;

    public:
        // 允许T****到SmartPointer4DArray的隐式转换。如果要禁止，请同时删除SmartPointer4DArray& operator= (T**** data);
        SmartPointer4DArray(PointerType data = nullptr);
        ~SmartPointer4DArray() noexcept;

        SmartPointer4DArray(const SmartPointer4DArray& rhs);
        SmartPointer4DArray& operator=(PointerType data);
        SmartPointer4DArray& operator=(const SmartPointer4DArray& rhs);

        SmartPointer4DArray(SmartPointer4DArray&& rhs) noexcept;
        SmartPointer4DArray& operator=(SmartPointer4DArray&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ConstPointerType GetData() const noexcept;
        [[nodiscard]] operator ConstPointerType() const noexcept;
        [[nodiscard]] ConstReferenceType operator*() const noexcept;

        [[nodiscard]] PointerType GetData() noexcept;
        [[nodiscard]] operator PointerType() noexcept;
        [[nodiscard]] ReferenceType operator*() noexcept;

    private:
        void Swap(SmartPointer4DArray& rhs) noexcept;

    private:
        PointerType m_Data;
    };

    template <typename T>
    bool operator==(const SmartPointer4DArray<T>& lhs, T**** data) noexcept;

    template <typename T>
    bool operator==(const SmartPointer4DArray<T>& lhs, const SmartPointer4DArray<T>& rhs) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_4D_ARRAY_H
