/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/13 21:17)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H
#define CORE_TOOLS_HELPER_SUITE_NAME_MACRO_IMPL_H

#include "CoreTools/Helper/NameMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

/// ����NameMacroTesting����
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