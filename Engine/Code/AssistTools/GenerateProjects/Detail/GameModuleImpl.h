///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 10:47)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GameModuleImpl
    {
    public:
        using ClassType = GameModuleImpl;

        using String = System::String;

    public:
        GameModuleImpl(String moduleName, String chineseName, bool isClient, String uppercaseName) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetModuleName() const;
        NODISCARD String GetChineseName() const;
        NODISCARD bool IsClient() const noexcept;
        NODISCARD String GetUppercaseName() const;

    private:
        String moduleName;
        String chineseName;
        bool isClient;
        String uppercaseName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_MODULE_IMPL_H