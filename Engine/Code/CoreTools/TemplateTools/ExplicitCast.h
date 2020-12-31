//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 15:13)

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
        ExplicitCast(T value);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator ValueType() const;

    private:
        ValueType m_Value;
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
    class ExplicitCast<T const&> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<T const&>;

    public:
        ExplicitCast(T const& value);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator T const &() const;

        ExplicitCast& operator=(const ExplicitCast&) = delete;

    private:
        T const& m_Value;
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
    class ExplicitCast<T const*> final
    {
    public:
        using ValueType = T;
        using ClassType = ExplicitCast<T const*>;

    public:
        ExplicitCast(T const* value);

        CLASS_INVARIANT_DECLARE;

    public:
        [[nodiscard]] operator T const *() const;

    private:
        T const* m_Value;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_H
