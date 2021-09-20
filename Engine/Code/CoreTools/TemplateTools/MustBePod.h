//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 15:26)

// Լ����������POD
#ifndef CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
#define CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H

#include "CoreTools/CoreToolsDll.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26496)
namespace CoreTools
{
    template <typename T>
    struct MustBePod
    {
        ~MustBePod()
        {
            [[maybe_unused]] void (*ptr)() = Constranints;
        }

    private:
        constexpr static void Constranints() noexcept
        {
            [[maybe_unused]] union
            {
                T TIsNotPODType;
            } unionType{};
        }
    };

    template <typename T>
    struct MustBePodOrVoid
    {
        ~MustBePodOrVoid()
        {
            [[maybe_unused]] void (*ptr)() = Constranints;
        }

    private:
        constexpr static void Constranints() noexcept
        {
            [[maybe_unused]] union
            {
                T TIsNotPODTypeOrVoid;
            } unionType{};
        }
    };

    template <>
    struct MustBePodOrVoid<void>
    {
    };
}
#include STSTEM_WARNING_POP
#endif  // CORE_TOOLS_TEMPLATE_TOOLS_MUST_BE_POD_H
