/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:17)

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

    /// 转换成非const引用不可用
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
        const T& value;
    };

    /// 转换成非const指针不可用
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
