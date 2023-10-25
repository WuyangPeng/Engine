///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/24 15:35)

#ifndef CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_FINAL_H
#define CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_FINAL_H

#include "PureVirtual.h"

namespace CoreTools
{
    class PureVirtualFinal final : public PureVirtual
    {
    public:
        using ClassType = PureVirtualFinal;
        using ParentType = PureVirtual;

    public:
        PureVirtualFinal() noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_FINAL_H