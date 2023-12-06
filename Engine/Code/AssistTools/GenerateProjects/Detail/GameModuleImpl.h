///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/08 15:30)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <array>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GameModuleImpl
    {
    public:
        using ClassType = GameModuleImpl;

        using String = System::String;
        static constexpr auto guidCount = 4;
        using GuidContainer = std::array<String, guidCount>;

    public:
        GameModuleImpl(String moduleName, String chineseName, ProjectServiceType projectServiceType, String uppercaseName, const GuidContainer& guid) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetModuleName() const;
        NODISCARD String GetChineseName() const;
        NODISCARD ProjectServiceType GetProjectServiceType() const noexcept;
        NODISCARD String GetUppercaseName() const;
        NODISCARD String GetGuid(int index) const;

    private:
        String moduleName;
        String chineseName;
        ProjectServiceType projectServiceType;
        String uppercaseName;
        GuidContainer guid;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H