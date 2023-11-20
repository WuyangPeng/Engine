///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 09:19)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_H

#include "AssistTools/AssistToolsDll.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <string>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GameParameter
    {
    public:
        using ClassType = GameParameter;

    public:
        explicit GameParameter(GameParameterType gameParameterType);
        GameParameter(GameParameterType gameParameterType, std::string defaultValue);

        CLASS_INVARIANT_DECLARE;

        NODISCARD GameParameterType GetGameParameterType() const noexcept;
        NODISCARD std::string GetKeyName() const;
        NODISCARD std::string GetDefaultValue() const;

    private:
        GameParameterType gameParameterType;
        std::string keyName;
        std::string defaultValue;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GAME_PARAMETER_H
