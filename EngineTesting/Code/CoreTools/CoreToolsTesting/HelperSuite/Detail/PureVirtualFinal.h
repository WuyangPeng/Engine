///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:55)

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