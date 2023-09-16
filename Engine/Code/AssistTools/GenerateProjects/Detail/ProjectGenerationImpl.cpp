///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/17 16:28)

#include "AssistTools/AssistToolsExport.h"

#include "ProjectGenerationImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/PosixTime.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"
#include "AssistTools/GenerateProjects/GameModule.h"
#include "AssistTools/GenerateProjects/MiddleLayerModule.h"

AssistTools::ProjectGenerationImpl::ProjectGenerationImpl(String fileName, GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept
    : fileName{ std::move(fileName) }, gameParameterAnalysis{ std::move(gameParameterAnalysis) }, codeMappingAnalysis{ std::move(codeMappingAnalysis) }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, ProjectGenerationImpl)

System::String AssistTools::ProjectGenerationImpl::GetTemplateContent() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    CoreTools::IFStreamManager streamManager{ fileName };
    streamManager.SetSimplifiedChinese();

    return streamManager.GetFileContent();
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCodeMapping(const String& templateContent, const String& codeKey) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto copyright = codeMappingAnalysis.GetElement(codeKey);
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$") + codeKey + SYSTEM_TEXT("$"), copyright);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceModuleCount(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ModuleCount"), System::ToString(gameParameterAnalysis.GetModuleCount()));
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceModuleDescribe(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto moduleDescribe = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ModuleDescribe"));

    String describe{};

    auto serial = 1;
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyModuleDescribe = moduleDescribe;
        boost::algorithm::replace_all(copyModuleDescribe, SYSTEM_TEXT("$Serial$"), System::ToString(serial));
        boost::algorithm::replace_all(copyModuleDescribe, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());
        boost::algorithm::replace_all(copyModuleDescribe, SYSTEM_TEXT("$ModuleChineseName$"), iter->GetChineseName());

        describe += copyModuleDescribe;

        if (serial != gameParameterAnalysis.GetModuleCount())
        {
            describe += SYSTEM_TEXT("\n");
        }

        ++serial;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ModuleDescribe$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceModuleJson(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto moduleJson = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ModuleJson"));

    String describe{};

    auto serial = 1;
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyModuleJson = moduleJson;
        boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());

        if (serial != gameParameterAnalysis.GetModuleCount())
        {
            boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleNameIsEnd$"), SYSTEM_TEXT(","));
        }
        else
        {
            boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleNameIsEnd$"), SYSTEM_TEXT(""));
        }

        describe += copyModuleJson;

        if (serial != gameParameterAnalysis.GetModuleCount())
        {
            describe += SYSTEM_TEXT("\n");
        }

        ++serial;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ModuleJson$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceModuleTestingJson(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto moduleJson = codeMappingAnalysis.GetElement(SYSTEM_TEXT("ModuleTestingJson"));

    String describe{};

    auto serial = 1;
    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyModuleJson = moduleJson;
        boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());

        if (serial != gameParameterAnalysis.GetModuleCount())
        {
            boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleNameIsEnd$"), SYSTEM_TEXT(","));
        }
        else
        {
            boost::algorithm::replace_all(copyModuleJson, SYSTEM_TEXT("$ModuleNameIsEnd$"), SYSTEM_TEXT(""));
        }

        describe += copyModuleJson;

        if (serial != gameParameterAnalysis.GetModuleCount())
        {
            describe += SYSTEM_TEXT("\n");
        }

        ++serial;
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$ModuleTestingJson$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceProjectChineseName(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ProjectChineseName"), gameParameterAnalysis.GetProjectChineseName());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceProjectDescribeName(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ProjectDescribeName"), gameParameterAnalysis.GetProjectDescribeName());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceProjectName(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ProjectName"), gameParameterAnalysis.GetProjectName());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceTestingName(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("TestingName"), gameParameterAnalysis.GetTestingName());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceVersion(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("Version"), gameParameterAnalysis.GetVersion());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceVersionNum(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("VersionNum"), gameParameterAnalysis.GetVersionNum());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceParameter(const String& templateContent, const String& codeKey, const String& parameter) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$") + codeKey + SYSTEM_TEXT("$"), parameter);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCallRunBat(const String& templateContent, bool isClient) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto callRunBat = codeMappingAnalysis.GetElement(SYSTEM_TEXT("CallRunBat"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        if (iter->IsClient() == isClient)
        {
            auto copyCallRunBat = callRunBat;
            boost::algorithm::replace_all(copyCallRunBat, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());

            describe += copyCallRunBat;

            describe += SYSTEM_TEXT("\n");
        }
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallRunBat$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::CallRunTestingBat(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto callRunBat = codeMappingAnalysis.GetElement(SYSTEM_TEXT("CallRunTestingBat"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyCallRunBat = callRunBat;
        boost::algorithm::replace_all(copyCallRunBat, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());

        describe += copyCallRunBat;

        describe += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CallRunTestingBat$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceProjectAbbreviation(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ProjectAbbreviation"), gameParameterAnalysis.GetProjectAbbreviation());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceEndYear(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("EndYear"), gameParameterAnalysis.GetEndYear());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceTime(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto currentTime = boost::posix_time::second_clock::local_time();

    System::StringStream data{};
    data << std::setw(4) << std::setfill(SYSTEM_TEXT('0')) << currentTime.date().year() << SYSTEM_TEXT("/") << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << static_cast<int>(currentTime.date().month()) << SYSTEM_TEXT("/") << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.date().day();
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Data$"), data.str());

    System::StringStream hour{};
    hour << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.time_of_day().hours();
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Hour$"), hour.str());

    System::StringStream minute{};
    minute << std::setw(2) << std::setfill(SYSTEM_TEXT('0')) << currentTime.time_of_day().minutes();
    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Minute$"), minute.str());

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCodeAnalysis(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto codeAnalysis = codeMappingAnalysis.GetElement(SYSTEM_TEXT("CodeAnalysis"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyCodeAnalysis = codeAnalysis;
        boost::algorithm::replace_all(copyCodeAnalysis, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName());

        describe += copyCodeAnalysis;

        describe += SYSTEM_TEXT("\n");
    }

    auto copyCodeAnalysis = codeAnalysis;
    boost::algorithm::replace_all(copyCodeAnalysis, SYSTEM_TEXT("$ModuleName$"), gameParameterAnalysis.GetProjectName());
    describe += copyCodeAnalysis;
    describe += SYSTEM_TEXT("\n");

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$CodeAnalysis$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceTestingCodeAnalysis(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto codeAnalysis = codeMappingAnalysis.GetElement(SYSTEM_TEXT("TestingCodeAnalysis"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetModuleBegin(); iter != gameParameterAnalysis.GetModuleEnd(); ++iter)
    {
        auto copyCodeAnalysis = codeAnalysis;
        boost::algorithm::replace_all(copyCodeAnalysis, SYSTEM_TEXT("$ModuleName$"), iter->GetModuleName() + SYSTEM_TEXT("Testing"));

        describe += copyCodeAnalysis;

        describe += SYSTEM_TEXT("\n");
    }

    auto copyCodeAnalysis = codeAnalysis;
    boost::algorithm::replace_all(copyCodeAnalysis, SYSTEM_TEXT("$ModuleName$"), gameParameterAnalysis.GetProjectName());
    describe += copyCodeAnalysis;
    describe += SYSTEM_TEXT("\n");

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$TestingCodeAnalysis$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceProjectCapital(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("ProjectCapital"), gameParameterAnalysis.GetProjectCapital());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCopyright(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto copyright = codeMappingAnalysis.GetElement(SYSTEM_TEXT("Copyright"));

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$Copyright$"), copyright);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCoreName(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("CoreName"), gameParameterAnalysis.GetCoreName());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceCoreCapital(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return ReplaceParameter(templateContent, SYSTEM_TEXT("CoreCapital"), gameParameterAnalysis.GetCoreCapital());
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceMiddleLayerInclude(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto middleLayerInclude = codeMappingAnalysis.GetElement(SYSTEM_TEXT("MiddleLayerInclude"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin(); iter != gameParameterAnalysis.GetMiddleLayerEnd(); ++iter)
    {
        auto copyMiddleLayerInclude = middleLayerInclude;
        boost::algorithm::replace_all(copyMiddleLayerInclude, SYSTEM_TEXT("$MiddleLayerName$"), iter->GetMiddleLayerName());

        describe += copyMiddleLayerInclude;

        describe += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$MiddleLayerInclude$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::ReplaceMiddleLayerFwdInclude(const String& templateContent) const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = templateContent;

    const auto middleLayerInclude = codeMappingAnalysis.GetElement(SYSTEM_TEXT("MiddleLayerFwdInclude"));

    String describe{};

    for (auto iter = gameParameterAnalysis.GetMiddleLayerBegin(); iter != gameParameterAnalysis.GetMiddleLayerEnd(); ++iter)
    {
        auto copyMiddleLayerInclude = middleLayerInclude;
        boost::algorithm::replace_all(copyMiddleLayerInclude, SYSTEM_TEXT("$MiddleLayerName$"), iter->GetMiddleLayerName());

        describe += copyMiddleLayerInclude;

        describe += SYSTEM_TEXT("\n");
    }

    boost::algorithm::replace_all(content, SYSTEM_TEXT("$MiddleLayerFwdInclude$"), describe);

    return content;
}

AssistTools::ProjectGenerationImpl::String AssistTools::ProjectGenerationImpl::GetFileName() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return fileName;
}
