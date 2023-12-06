///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 16:24)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_REPLACE_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_REPLACE_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"
#include "AssistTools/GenerateProjects/GenerateProjectsInternalFwd.h"

#include <gsl/pointers>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE ProjectGenerationReplace
    {
    public:
        using ClassType = ProjectGenerationReplace;

        using String = System::String;
        using StringView = System::StringView;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;
        using ReplaceContainer = std::vector<Replace>;

    public:
        ProjectGenerationReplace(String templateContent, GameParameterAnalysis gameParameterAnalysis, CodeMappingAnalysis codeMappingAnalysis) noexcept;

        CLASS_INVARIANT_DECLARE;

        void ReplaceCodeMapping(const StringView& codeKey);
        void ReplaceModuleCount();
        void ReplaceModuleDescribe();
        void ReplaceModuleJson();
        void ReplaceModuleTestingJson();
        void ReplaceGameParameter(GameParameterType gameParameterType);
        void ReplaceCallRunBat(ProjectServiceType projectServiceType);
        void ReplaceCallRunTestingBat();
        void ReplaceTime();
        void ReplaceCopyright();
        void ReplaceCodeAnalysis();
        void ReplaceTestingCodeAnalysis();
        void ReplaceMiddleLayerInclude();
        void ReplaceMiddleLayerFwdInclude();
        void ReplaceToolDirectory();
        void ReplaceToolProject();
        void ReplaceToolNestedProjects();
        void ReplaceTestingToolProject();

        NODISCARD static String GetIdentifier(const String& original);

        NODISCARD String GetReplaceResult() const;

        NODISCARD static String ReplaceParameter(const String& content, const StringView& codeKey, const String& parameter);
        NODISCARD static String ReplaceParameter(const String& content, const ReplaceContainer& replace);

        NODISCARD bool IsEmpty() const noexcept;

    private:
        using ReplaceParameterFunction = String (ClassType::*)(const String&, int, const GameModule&) const;
        using NotNullReplaceParameterFunction = gsl::not_null<ReplaceParameterFunction>;

    private:
        void ReplaceParameter(const StringView& codeKey, const String& parameter);

        NODISCARD String ReplaceModuleDescribe(const String& moduleDescribe, int serial, const GameModule& gameModule) const;
        NODISCARD String ReplaceJson(const String& json, int serial, const GameModule& gameModule) const;
        NODISCARD static String ReplaceCallRunBat(const String& callRunBat, ProjectServiceType projectServiceType, const GameModule& gameModule);
        NODISCARD static String ReplaceModuleName(const String& module, const String& moduleName);
        NODISCARD static String ReplaceMiddleLayerName(const String& middleLayer, const MiddleLayerModule& middleLayerModule);
        NODISCARD static String ReplaceToolProject(const String& toolProject, const GameModule& gameModule);
        NODISCARD static String ReplaceToolNestedProjects(const String& toolNestedProjects, const GameModule& gameModule);
        NODISCARD String GetModuleDescribe() const;
        NODISCARD String GetModuleJson() const;
        NODISCARD String GetModuleTestingJson() const;
        NODISCARD String GetCallRunBat(ProjectServiceType projectServiceType) const;
        NODISCARD String GetCallRunTestingBat() const;
        NODISCARD String GetCodeAnalysis() const;
        NODISCARD String GetTestingCodeAnalysis() const;
        NODISCARD String GetMiddleLayer(const StringView& codeKey) const;
        NODISCARD String GetToolProject() const;
        NODISCARD String GetToolNestedProjects() const;
        NODISCARD String GetTestToolProject() const;

        NODISCARD String GetDescribe(const StringView& codeKey, NotNullReplaceParameterFunction replaceParameterType) const;
        NODISCARD String GetProjectName(const String& templateContent) const;
        NODISCARD String GetModuleName(const String& templateContent) const;

    private:
        String replaceResult;
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_REPLACE_H