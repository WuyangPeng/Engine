///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/18 16:58)

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