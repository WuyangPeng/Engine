///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:16)

#ifndef CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_FINAL_H
#define CORE_TOOLS_HELPER_SUITE_PURE_VIRTUAL_FINAL_H

#include "PureVirtual.h"

namespace CoreTools
{
    class PureVirtualFinal : public PureVirtual
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