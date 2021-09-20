///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 16:06)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H

#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

// 测试NameMacroTesting所需
namespace CoreTools
{
    class NameMacroImpl final
    {
    public:
        using ClassType = NameMacroImpl;

    public:
        explicit NameMacroImpl(int count) noexcept;

        CLASS_INVARIANT_DECLARE;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

    private:
        int count;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H