///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 18:10)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGenerationReplace.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/Flags/GameParameterType.h"
#include "AssistTools/GenerateProjects/Flags/ProjectServiceType.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"
#include "AssistTools/GenerateProjects/Replace.h"
#include "AssistTools/GenerateProjects/Using/ProjectGenerationUsing.h"

AssistTools::ProjectGenerationReplace::ProjectGenerationReplace(String templateContent, GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : replaceResult{ std::move(templateContent) }, gameParameterAnalysis{ std::move(gameParameterAnalysis) }, codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ProjectGenerationReplace)

System::String AssistTools::ProjectGenerationReplace::GetReplaceResult() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return replaceResult;
}

System::String AssistTools::ProjectGenerationReplace::GetIdentifier(const String& original)
{
    return dollar.data() + original + dollar.data();
}

void AssistTools::ProjectGenerationReplace::ReplaceCodeMapping(const StringView& codeKey)
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(codeKey, codeMappingAnalysis.GetElement(codeKey.data()));
}

void AssistTools::ProjectGenerationReplace::ReplaceParameter(const StringView& codeKey, const String& parameter)
{
#ifdef ASSIST_TOOLS_USE_CUSTOM_REPLACE

    const auto search = GetIdentifier(codeKey.data());
    size_t pos{};
    while ((pos = replaceResult.find(search, pos)) != String::npos)
    {
        replaceResult.replace(pos, search.length(), parameter);
        pos += parameter.length();
    }

#else  // !ASSIST_TOOLS_USE_CUSTOM_REPLACE

    boost::replace_all(replaceResult, GetIdentifier(codeKey.data()), parameter);

#endif  // ASSIST_TOOLS_USE_CUSTOM_REPLACE
}

System::String AssistTools::ProjectGenerationReplace::ReplaceParameter(const String& content, const StringView& codeKey, const String& parameter)
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

#ifdef ASSIST_TOOLS_USE_CUSTOM_REPLACE

    auto result = content;

    const auto search = GetIdentifier(codeKey.data());
    size_t pos{};
    while ((pos = result.find(search, pos)) != String::npos)
    {
        result.replace(pos, search.length(), parameter);
        pos += parameter.length();
    }

    return result;

#else  // !ASSIST_TOOLS_USE_CUSTOM_REPLACE

    return boost::replace_all_copy(content, GetIdentifier(codeKey.data()), parameter);

#endif  // ASSIST_TOOLS_USE_CUSTOM_REPLACE
}

System::String AssistTools::ProjectGenerationReplace::ReplaceParameter(const String& content, const ReplaceContainer& replace)
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

#ifdef ASSIST_TOOLS_USE_CUSTOM_ARRAY_REPLACE

    auto result = content;

    size_t pos{};
    while ((pos = result.find(dollar, pos)) != String::npos)
    {
        auto find = false;
        for (const auto& element : replace)
        {
            const auto codeKey = element.GetKeyCode();
            const auto parameter = element.GetParameter();

            if (pos + codeKey.size() + 1 < result.size() &&
                result.at(pos + codeKey.size() + 1) == dollar.at(0) &&
                result.compare(pos + 1, codeKey.size(), codeKey) == 0)
            {
                result.replace(pos, codeKey.length() + 2, parameter);
                pos += parameter.length();
                find = true;

                break;
            }
        }

        if (!find)
        {
            ++pos;
        }
    }

    return result;

#else  // !ASSIST_TOOLS_USE_CUSTOM_ARRAY_REPLACE

    auto result = content;

    for (const auto& element : replace)
    {
        result = ReplaceParameter(result, element.GetKeyCode(), element.GetParameter());
    }

    return result;

#endif  // ASSIST_TOOLS_USE_CUSTOM_ARRAY_REPLACE
}

bool AssistTools::ProjectGenerationReplace::IsEmpty() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return replaceResult.empty();
}

void AssistTools::ProjectGenerationReplace::ReplaceModuleCount()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(moduleCountKey, System::ToString(gameParameterAnalysis.GetModuleCount()));
}

void AssistTools::ProjectGenerationReplace::ReplaceModuleDescribe()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(moduleDescribeKey, GetModuleDescribe());
}

System::String AssistTools::ProjectGenerationReplace::GetModuleDescribe() const
{
    return GetDescribe(moduleDescribeKey, &ClassType::ReplaceModuleDescribe);
}

System::String AssistTools::ProjectGenerationReplace::GetDescribe(const StringView& codeKey, NotNullReplaceParameterFunction replaceParameterType) const
{
    const auto templateContent = codeMappingAnalysis.GetElement(codeKey.data());

    String content{};

    auto serial = 1;
    for (auto iter = gameParameterAnalysis.GetModuleBegin();
         iter != gameParameterAnalysis.GetModuleEnd();
         ++iter)
    {
        content += (this->*replaceParameterType)(templateContent, serial, *iter);

        ++serial;
    }

    return content;
}

System::String AssistTools::ProjectGenerationReplace::ReplaceModuleDescribe(const String& moduleDescribe, int serial, const GameModule& gameModule) const
{
    auto content = ReplaceParameter(moduleDescribe, serialKey, System::ToString(serial));

    content = ReplaceParameter(content, moduleNameKey, gameModule.GetModuleName());
    content = ReplaceParameter(content, moduleChineseNameKey, gameModule.GetChineseName());

    if (serial != gameParameterAnalysis.GetModuleCount())
    {
        content += SYSTEM_TEXT("\n");
    }

    return content;
}

void AssistTools::ProjectGenerationReplace::ReplaceModuleJson()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(moduleJsonKey, GetModuleJson());
}

System::String AssistTools::ProjectGenerationReplace::GetModuleJson() const
{
    return GetDescribe(moduleJsonKey, &ClassType::ReplaceJson);
}

System::String AssistTools::ProjectGenerationReplace::ReplaceJson(const String& json, int serial, const GameModule& gameModule) const
{
    auto content = ReplaceParameter(json, moduleNameKey, gameModule.GetModuleName());

    if (serial != gameParameterAnalysis.GetModuleCount())
    {
        content = ReplaceParameter(content, moduleNameIsEndKey, SYSTEM_TEXT(","));
        content += SYSTEM_TEXT("\n");
    }
    else
    {
        content = ReplaceParameter(content, moduleNameIsEndKey, SYSTEM_TEXT(""));
    }

    return content;
}

void AssistTools::ProjectGenerationReplace::ReplaceModuleTestingJson()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(moduleTestingJsonKey, GetModuleTestingJson());
}

System::String AssistTools::ProjectGenerationReplace::GetModuleTestingJson() const
{
    return GetDescribe(moduleTestingJsonKey, &ClassType::ReplaceJson);
}

void AssistTools::ProjectGenerationReplace::ReplaceGameParameter(GameParameterType gameParameterType)
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(ToString(gameParameterType), gameParameterAnalysis.GetGameParameter(gameParameterType));
}

void AssistTools::ProjectGenerationReplace::ReplaceCallRunBat(ProjectServiceType projectServiceType)
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(callRunBatKey, GetCallRunBat(projectServiceType));
}

System::String AssistTools::ProjectGenerationReplace::GetCallRunBat(ProjectServiceType projectServiceType) const
{
    const auto callRunBat = codeMappingAnalysis.GetElement(callRunBatKey.data());

    String content{};

    std::for_each(gameParameterAnalysis.GetModuleBegin(), gameParameterAnalysis.GetModuleEnd(), [&content, callRunBat, projectServiceType](const auto& element) {
        content += ReplaceCallRunBat(callRunBat, projectServiceType, element);
    });

    return content;
}

System::String AssistTools::ProjectGenerationReplace::ReplaceCallRunBat(const String& callRunBat, ProjectServiceType projectServiceType, const GameModule& gameModule)
{
    String content{};

    if (gameModule.GetProjectServiceType() == projectServiceType)
    {
        content += ReplaceModuleName(callRunBat, gameModule.GetModuleName());
    }

    return content;
}

void AssistTools::ProjectGenerationReplace::ReplaceCallRunTestingBat()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(callRunTestingBatKey, GetCallRunTestingBat());
}

System::String AssistTools::ProjectGenerationReplace::GetCallRunTestingBat() const
{
    const auto element = codeMappingAnalysis.GetElement(callRunTestingBatKey.data());

    return GetModuleName(element);
}

void AssistTools::ProjectGenerationReplace::ReplaceTime()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto currentTime = boost::posix_time::second_clock::local_time();

    System::StringStream data{};
    data << std::setw(4) << std::setfill(SYSTEM_TEXT('0')) << currentTime.date().year() << SYSTEM_TEXT("/") << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << static_cast<int>(currentTime.date().month()) << SYSTEM_TEXT("/") << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.date().day();
    ReplaceParameter(dataKey, data.str());

    System::StringStream hour{};
    hour << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.time_of_day().hours();
    ReplaceParameter(hourKey, hour.str());

    System::StringStream minute{};
    minute << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.time_of_day().minutes();
    ReplaceParameter(minuteKey, minute.str());
}

void AssistTools::ProjectGenerationReplace::ReplaceCopyright()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceCodeMapping(copyrightKey);
}

void AssistTools::ProjectGenerationReplace::ReplaceCodeAnalysis()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(codeAnalysisKey, GetCodeAnalysis());
}

System::String AssistTools::ProjectGenerationReplace::GetCodeAnalysis() const
{
    const auto element = codeMappingAnalysis.GetElement(codeAnalysisKey.data());

    return GetModuleName(element) + GetProjectName(element);
}

System::String AssistTools::ProjectGenerationReplace::GetModuleName(const String& templateContent) const
{
    String content{};

    std::for_each(gameParameterAnalysis.GetModuleBegin(), gameParameterAnalysis.GetModuleEnd(), [&content, templateContent](const auto& element) {
        content += ReplaceModuleName(templateContent, element.GetModuleName());
    });

    return content;
}

System::String AssistTools::ProjectGenerationReplace::ReplaceModuleName(const String& module, const String& moduleName)
{
    return ReplaceParameter(module, moduleNameKey, moduleName) + SYSTEM_TEXT("\n");
}

void AssistTools::ProjectGenerationReplace::ReplaceTestingCodeAnalysis()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(testingCodeAnalysisKey, GetTestingCodeAnalysis());
}

System::String AssistTools::ProjectGenerationReplace::GetTestingCodeAnalysis() const
{
    const auto testingCodeAnalysis = codeMappingAnalysis.GetElement(testingCodeAnalysisKey.data());

    String content{};

    std::for_each(gameParameterAnalysis.GetModuleBegin(), gameParameterAnalysis.GetModuleEnd(), [&content, testingCodeAnalysis](const auto& element) {
        content += ReplaceModuleName(testingCodeAnalysis, element.GetModuleName() + SYSTEM_TEXT("Testing"));
    });

    content += GetProjectName(testingCodeAnalysis);

    return content;
}

AssistTools::ProjectGenerationReplace::String AssistTools::ProjectGenerationReplace::GetProjectName(const String& templateContent) const
{
    return ReplaceParameter(templateContent, moduleNameKey, gameParameterAnalysis.GetGameParameter(GameParameterType::ProjectName)) + SYSTEM_TEXT("\n");
}

void AssistTools::ProjectGenerationReplace::ReplaceMiddleLayerInclude()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(middleLayerIncludeKey, GetMiddleLayer(middleLayerIncludeKey));
}

System::String AssistTools::ProjectGenerationReplace::ReplaceMiddleLayerName(const String& middleLayer, const MiddleLayerModule& middleLayerModule)
{
    return ReplaceParameter(middleLayer, middleLayerNameKey, middleLayerModule.GetMiddleLayerName()) + SYSTEM_TEXT("\n");
}

void AssistTools::ProjectGenerationReplace::ReplaceMiddleLayerFwdInclude()
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    ReplaceParameter(middleLayerFwdIncludeKey, GetMiddleLayer(middleLayerFwdIncludeKey));
}

System::String AssistTools::ProjectGenerationReplace::GetMiddleLayer(const StringView& codeKey) const
{
    const auto middleLayer = codeMappingAnalysis.GetElement(codeKey.data());

    String content{};

    std::for_each(gameParameterAnalysis.GetMiddleLayerBegin(), gameParameterAnalysis.GetMiddleLayerEnd(), [&content, middleLayer](const auto& element) {
        content += ReplaceMiddleLayerName(middleLayer, element);
    });

    return content;
}
