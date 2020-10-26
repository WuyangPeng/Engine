//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/19 16:49)

#ifndef CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H
#define CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H

#include "System/Helper/PragmaWarning/Operators.h"

namespace CoreTools
{
    template <typename T>
    class SmartPointerSingle final : private boost::equality_comparable<SmartPointerSingle<T>, boost::equality_comparable<SmartPointerSingle<T>, T*>>
    {
    public:
        using ClassType = SmartPointerSingle<T>;
        using PointerType = T*;
        using ReferenceType = T&;
        using ConstPointerType = const T*;
        using ConstReferenceType = const T&;

    public:
        // 允许T*到PointerSingle的隐式转换。如果要禁止，请同时删除PointerSingle& operator= (T* data);
        SmartPointerSingle(PointerType data = nullptr);
        ~SmartPointerSingle() noexcept;

        SmartPointerSingle(const SmartPointerSingle& rhs);
        SmartPointerSingle& operator=(PointerType data);
        SmartPointerSingle& operator=(const SmartPointerSingle& rhs);

        SmartPointerSingle(SmartPointerSingle&& rhs) noexcept;
        SmartPointerSingle& operator=(SmartPointerSingle&& rhs) noexcept;

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
        void Swap(SmartPointerSingle& rhs) noexcept;

    private:
        PointerType m_Data;
    };

    template <typename T>
    bool operator==(const SmartPointerSingle<T>& lhs, T* data) noexcept;

    template <typename T>
    bool operator==(const SmartPointerSingle<T>& lhs, const SmartPointerSingle<T>& rhs) noexcept;
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_SMART_POINTER_SINGLE_H
