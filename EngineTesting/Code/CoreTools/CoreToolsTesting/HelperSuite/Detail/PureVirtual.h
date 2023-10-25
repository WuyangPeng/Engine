///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:35)

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