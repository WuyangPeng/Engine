/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:59)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameter.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"

AssistTools::GameParameter::GameParameter(GameParameterType gameParameterType)
    : GameParameter{ gameParameterType, "" }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

AssistTools::GameParameter::GameParameter(GameParameterType gameParameterType, std::string defaultValue)
    : gameParameterType{ gameParameterType }, keyName{ ToMultiByteString(gameParameterType) }, defaultValue{ std::move(defaultValue) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, GameParameter)

AssistTools::GameParameterType AssistTools::GameParameter::GetGameParameterType() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterType;
}

std::string AssistTools::GameParameter::GetKeyName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return keyName;
}

std::string AssistTools::GameParameter::GetDefaultValue() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return defaultValue;
}
