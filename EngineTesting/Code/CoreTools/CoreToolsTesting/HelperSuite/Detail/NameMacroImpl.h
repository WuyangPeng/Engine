///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/13 23:04)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H

#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

// 测试NameMacroTesting所需
namespace CoreTools
{
    class NameMacroImpl final
    {
    public:
        using ClassType = NameMacroImpl;

    public:
        NameMacroImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H