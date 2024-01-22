/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 19:58)

#include "AssistTools/AssistToolsExport.h"

#include "ModuleGenerate.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/ProjectGeneration.h"
#include "AssistTools/GenerateProjects/Using/GenerateEngineUsing.h"

AssistTools::ModuleGenerate::ModuleGenerate(GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : gameParameterAnalysis{ std::move(gameParameterAnalysis) },
      codeMappingAnalysis{ std::move(codeMappingAnalysis) },
      content{}
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ModuleGenerate)

void AssistTools::ModuleGenerate::Generate()
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        GenerateModule(*iter);
    }
}

System::String AssistTools::ModuleGenerate::GetContent(const String& inputDirectory, const StringView& codeKey, ProjectGenerationType projectGenerationType)
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    const auto key = inputDirectory + slash.data() + codeKey.data();

    auto iter = content.find(key);

    if (iter == content.cend())
    {
        const ProjectGeneration projectGeneration{ projectGenerationType,
                                                   key + extension.data(),
                                                   gameParameterAnalysis,
                                                   codeMappingAnalysis };

        const auto result = projectGeneration.GetContent();

        iter = content.emplace(key, result).first;
    }

    if (iter != content.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应内容。"))
    }
}

System::String AssistTools::ModuleGenerate::GetOnlyContent(const String& inputDirectory, const StringView& codeKey, ProjectGenerationType projectGenerationType)
{
    ASSIST_TOOLS_CLASS_IS_VALID_9;

    auto iter = content.find(codeKey.data());

    if (iter == content.cend())
    {
        const ProjectGeneration projectGeneration{ projectGenerationType,
                                                   inputDirectory + slash.data() + codeKey.data() + extension.data(),
                                                   gameParameterAnalysis,
                                                   codeMappingAnalysis };

        const auto result = projectGeneration.GetContent();

        iter = content.emplace(codeKey.data(), result).first;
    }

    if (iter != content.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应内容。"))
    }
}

AssistTools::ModuleGenerate::MiddleLayerContainerConstIter AssistTools::ModuleGenerate::GetMiddleLayerBegin() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis.GetMiddleLayerBegin();
}

AssistTools::ModuleGenerate::MiddleLayerContainerConstIter AssistTools::ModuleGenerate::GetMiddleLayerEnd() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis.GetMiddleLayerEnd();
}

AssistTools::ModuleGenerate::String AssistTools::ModuleGenerate::GetProjectName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectName);
}
