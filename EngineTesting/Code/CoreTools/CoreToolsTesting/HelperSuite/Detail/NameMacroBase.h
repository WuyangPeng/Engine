///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:15)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_BASE_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_BASE_H

#include "PureVirtual.h"
#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

namespace CoreTools
{
    class NameMacroBase
    {
    public:
        using ClassType = NameMacroBase;

    public:
        NameMacroBase() noexcept;
        virtual ~NameMacroBase() = default;
        NameMacroBase(const NameMacroBase&) noexcept = default;
        NameMacroBase& operator=(const NameMacroBase&) noexcept = default;
        NameMacroBase(NameMacroBase&&) noexcept = default;
        NameMacroBase& operator=(NameMacroBase&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        CORE_TOOLS_NAMES_DECLARE;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_MACRO_BASE_H