///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:15)

#ifndef CORE_TOOLS_HELPER_SUITE_NAME_FINAL_MACRO_H
#define CORE_TOOLS_HELPER_SUITE_NAME_FINAL_MACRO_H

#include "NameMacro.h"

namespace CoreTools
{
    class NameFinalMacro final : public NameMacro
    {
    public:
        using ClassType = NameFinalMacro;
        using ParentType = NameMacro;

    public:
        explicit NameFinalMacro(const std::string& name);

        NODISCARD static NameMacroSharedPtr Create(const std::string& name);

        CLASS_INVARIANT_FINAL_DECLARE;

        CORE_TOOLS_NAMES_FINAL_DECLARE;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const final;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_NAME_FINAL_MACRO_H