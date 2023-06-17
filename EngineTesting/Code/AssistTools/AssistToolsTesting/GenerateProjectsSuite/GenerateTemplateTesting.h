///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:52)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H

#include "CoreTools/EngineConfiguration/StringReplacing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
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
        NODISCARD int GetContentFindCount(const System::String& templateFileName, const System::String& findContent);
        void ContentCountTest(const System::String& templateFileName, const System::String& findContent, int testCount, const std::string& functionName, int index);

        NODISCARD System::String GetManagerChineseName() const;
        NODISCARD CopyrightData GetCopyrightData() const;

        NODISCARD static System::String GetResourceDirectory();
        NODISCARD static System::String GetSolutionName();
        NODISCARD static System::String GetForwardSlash();
        NODISCARD static System::String GetProjectCapital();
        NODISCARD static System::String GetPercent();

        NODISCARD static System::String GetSpecialCodeEngineDirectory();
        NODISCARD static System::String GetCodeEngineDirectory();
        NODISCARD static System::String GetInputManagerName();
        NODISCARD static System::String GetEventManagerName();
        NODISCARD static System::String GetMiddleLayerName();
        NODISCARD static System::String GetEngineDirectory();
        NODISCARD static System::String GetEventManagerCapitalName();
        NODISCARD static System::String GetEventManagerInterface();
        NODISCARD static System::String GetInputManagerCapitalName();
        NODISCARD static System::String GetInputManagerInterface();
        NODISCARD static System::String GetUpdateName();
        NODISCARD static System::String GetExportDirectory();
        NODISCARD static System::String GetTesting();
        NODISCARD static Replace GetSpecialReplace();

        NODISCARD static System::String GetSpecialEndYear();
        NODISCARD static System::String GetSpecialProjectChineseName();
        NODISCARD static System::String GetSpecialVersions();
        NODISCARD static System::String GetSpecialDate();
        NODISCARD static System::String GetSpecialHour();
        NODISCARD static System::String GetSpecialMinute();
        NODISCARD static System::String GetSpecialProjectCapital();
        NODISCARD static System::String GetSpecialSolutionName();
        NODISCARD static System::String GetSpecialProjectName();
        NODISCARD static System::String GetSpecialManagerCapital();
        NODISCARD static System::String GetSpecialManagerName();
        NODISCARD static System::String GetSpecialManagerChineseName();
        NODISCARD static System::String GetSpecialInterfaceName();

        NODISCARD static System::String GetDefaultEndYear();
        NODISCARD static System::String GetDefaultProjectChineseName();
        NODISCARD static System::String GetDefaultVersions();
        NODISCARD static System::String GetDefaultDate();
        NODISCARD static System::String GetDefaultHour();
        NODISCARD static System::String GetDefaultMinute();
        NODISCARD static System::String GetDefaultProjectCapital();
        NODISCARD static System::String GetDefaultSolutionName();
        NODISCARD static System::String GetDefaultProjectName();
        NODISCARD static System::String GetDefaultManagerChineseName();
        NODISCARD static System::String GetDefaultManagerName();
        NODISCARD static System::String GetDefaultManagerCapital();
        NODISCARD static System::String GetDefaultInterfaceName();

    private:
        NODISCARD static int GetEndYear() noexcept;
        NODISCARD static System::String GetVersions();
        NODISCARD System::String GetProjectChineseName() const;

    private:
        CoreTools::StringReplacing generateTemplateTesting;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_TESTING_H