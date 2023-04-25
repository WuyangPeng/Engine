///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 20:55)

#ifndef CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_H
#define CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_H

#include "CoreTools/Helper/UserMacro.h"

namespace CoreTools
{
    class PureVirtual
    {
    public:
        using ClassType = PureVirtual;

    public:
        PureVirtual() noexcept = default;
        virtual ~PureVirtual() = default;
        PureVirtual(const PureVirtual&) noexcept = default;
        PureVirtual& operator=(const PureVirtual&) noexcept = default;
        PureVirtual(PureVirtual&&) noexcept = default;
        PureVirtual& operator=(PureVirtual&&) noexcept = default;

        CLASS_INVARIANT_PURE_VIRTUAL_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_H