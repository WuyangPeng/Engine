///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/03/31 16:05)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class ExplicitCast final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<T>;

    public:
        ExplicitCast(T value) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator ValueType() const noexcept;

    private:
        ValueType value;
    };

    // 转换成非const引用不可用
    template <typename T>
    class ExplicitCast<T&> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<T&>;

    public:
        ExplicitCast(T&) = delete;

        CLASS_INVARIANT_DECLARE;

        operator T&() = delete;
    };

    template <typename T>
    class ExplicitCast<const T&> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<const T&>;

    public:
        ExplicitCast(const T& value) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator const T&() const noexcept;

        ~ExplicitCast() noexcept = default;
        ExplicitCast(const ExplicitCast& rhs) noexcept;
        ExplicitCast& operator=(const ExplicitCast&) = delete;
        ExplicitCast(ExplicitCast&& rhs) noexcept;
        ExplicitCast& operator=(ExplicitCast&&) noexcept = delete;

    private:
        T const& value;
    };

    // 转换成非const指针不可用
    template <typename T>
    class ExplicitCast<T*> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<T*>;

    public:
        ExplicitCast(T*) = delete;

        CLASS_INVARIANT_DECLARE;

        operator T*() = delete;
    };

    template <typename T>
    class ExplicitCast<const T*> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<const T*>;

    public:
        ExplicitCast(const T* value) noexcept;

        CLASS_INVARIANT_DECLARE;

    public:
        NODISCARD operator const T*() const noexcept;

    private:
        const T* value;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H
