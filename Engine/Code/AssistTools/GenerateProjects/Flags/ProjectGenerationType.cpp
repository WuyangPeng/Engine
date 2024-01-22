/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:57)

#include "AssistTools/AssistToolsExport.h"

#include "GameParameterType.h"
#include "ProjectGenerationType.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

System::StringView AssistTools::ToString(GameParameterType gameParameterType)
{
    static std::map<GameParameterType, System::StringView> result{ { GameParameterType::CoreName, SYSTEM_TEXT("CoreName") },
                                                                   { GameParameterType::CoreCapital, SYSTEM_TEXT("CoreCapital") },
                                                                   { GameParameterType::ProjectChineseName, SYSTEM_TEXT("ProjectChineseName") },
                                                                   { GameParameterType::ProjectDescribeName, SYSTEM_TEXT("ProjectDescribeName") },
                                                                   { GameParameterType::ProjectName, SYSTEM_TEXT("ProjectName") },
                                                                   { GameParameterType::ProjectCapital, SYSTEM_TEXT("ProjectCapital") },
                                                                   { GameParameterType::ProjectAbbreviation, SYSTEM_TEXT("ProjectAbbreviation") },
                                                                   { GameParameterType::EndYear, SYSTEM_TEXT("EndYear") },
                                                                   { GameParameterType::Version, SYSTEM_TEXT("Version") },
                                                                   { GameParameterType::VersionNum, SYSTEM_TEXT("VersionNum") },
                                                                   { GameParameterType::TestingName, SYSTEM_TEXT("TestingName") } };

    if (const auto iter = result.find(gameParameterType);
        iter != result.cend())
    {
        return iter->second;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("未知的枚举类型，gameParameterType = ") + System::ToString(gameParameterType))
}

std::string AssistTools::ToMultiByteString(GameParameterType gameParameterType)
{
    return CoreTools::StringConversion::StandardConversionMultiByte(ToString(gameParameterType).data());
}
