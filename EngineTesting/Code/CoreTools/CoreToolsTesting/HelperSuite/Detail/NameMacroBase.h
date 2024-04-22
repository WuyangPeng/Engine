/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 21:15)

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