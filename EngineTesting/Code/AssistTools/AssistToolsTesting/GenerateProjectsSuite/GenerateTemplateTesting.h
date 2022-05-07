// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:11)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H

#include "CoreTools/EngineConfiguration/StringReplacing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "AssistTools/GenerateProjects/CopyrightData.h"
#include "AssistTools/GenerateProjects/Flags/GenerateTemplateReplaceFlags.h"

#include <map>

namespace AssistTools
{
    class GenerateTemplateTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = GenerateTemplateTesting;
        using ParentType = UnitTest;

    public:
        explicit GenerateTemplateTesting(const OStreamShared& stream);
        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using Replace = std::map<GenerateTemplateReplace, System::String>;

    protected:
        int GetContentFindCount(const System::String& templateFileName, const System::String& findContent);
        void ContentCountTest(const System::String& templateFileName, const System::String& findContent, int testCount, const std::string& functionName, int index);

        const System::String GetManagerChineseName() const;
        const CopyrightData GetCopyrightData() const;

        static const System::String GetResourceDirectory();
        static const System::String GetSolutionName();
        static const System::String GetForwardSlash();
        static const System::String GetProjectCapital();
        static const System::String GetPercent();

        static const System::String GetSpecialCodeEngineDirectory();
        static const System::String GetCodeEngineDirectory();
        static const System::String GetInputManagerName();
        static const System::String GetEventManagerName();
        static const System::String GetMiddleLayerName();
        static const System::String GetEngineDirectory();
        static const System::String GetEventManagerCapitalName();
        static const System::String GetEventManagerInterface();
        static const System::String GetInputManagerCapitalName();
        static const System::String GetInputManagerInterface();
        static const System::String GetUpdateName();
        static const System::String GetExportDirectory();
        static const System::String GetTesting();
        static const Replace GetSpecialReplace();

        static const System::String GetSpecialEndYear();
        static const System::String GetSpecialProjectChineseName();
        static const System::String GetSpecialVersions();
        static const System::String GetSpecialDate();
        static const System::String GetSpecialHour();
        static const System::String GetSpecialMinute();
        static const System::String GetSpecialProjectCapital();
        static const System::String GetSpecialSolutionName();
        static const System::String GetSpecialProjectName();
        static const System::String GetSpecialManagerCapital();
        static const System::String GetSpecialManagerName();
        static const System::String GetSpecialManagerChineseName();
        static const System::String GetSpecialInterfaceName();

        static const System::String GetDefaultEndYear();
        static const System::String GetDefaultProjectChineseName();
        static const System::String GetDefaultVersions();
        static const System::String GetDefaultDate();
        static const System::String GetDefaultHour();
        static const System::String GetDefaultMinute();
        static const System::String GetDefaultProjectCapital();
        static const System::String GetDefaultSolutionName();
        static const System::String GetDefaultProjectName();
        static const System::String GetDefaultManagerChineseName();
        static const System::String GetDefaultManagerName();
        static const System::String GetDefaultManagerCapital();
        static const System::String GetDefaultInterfaceName();

    private:
        static int GetEndYear() noexcept;
        static const System::String GetVersions();
        const System::String GetProjectChineseName() const;

    private:
        CoreTools::StringReplacing m_GenerateTemplateTesting;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H