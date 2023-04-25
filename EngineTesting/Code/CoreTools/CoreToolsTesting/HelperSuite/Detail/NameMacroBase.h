///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:53)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_BASE_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_BASE_H

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