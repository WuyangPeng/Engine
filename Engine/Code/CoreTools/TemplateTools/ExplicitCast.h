///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:05)

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

    // ת���ɷ�const���ò�����
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

    // ת���ɷ�constָ�벻����
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
