///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:15)

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