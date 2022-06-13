///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:15)

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