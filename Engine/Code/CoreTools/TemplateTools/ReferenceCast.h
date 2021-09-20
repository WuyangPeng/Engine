//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:28)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H
#define CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename T>
    class ReferenceCast
    {
    public:
        using ClassType = ReferenceCast<T>;

    public:
        explicit ReferenceCast(T& value) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator T&() const noexcept;

    private:
        T& m_Value;

        ReferenceCast& operator=(const ReferenceCast&) = delete;
    };

    template <>
    class ReferenceCast<int>
    {
    public:
        using ClassType = ReferenceCast<int>;

    public:
        explicit ReferenceCast(int value) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] operator int() const noexcept;

    private:
        int m_Value;
    };
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_REFERENCE_CAST_H
