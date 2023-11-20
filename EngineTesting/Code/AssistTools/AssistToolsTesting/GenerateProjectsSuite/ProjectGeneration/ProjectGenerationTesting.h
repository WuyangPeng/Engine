///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/10 14:13)

#ifndef ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_PROJECT_GENERATION_TESTING_H
#define ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_PROJECT_GENERATION_TESTING_H

#include "CoreTools/CharacterString/CodeMappingAnalysis.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "AssistTools/GenerateProjects/GameParameterAnalysis.h"

namespace AssistTools
{
    class ProjectGenerationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProjectGenerationTesting;
        using ParentType = UnitTest;

        using String = System::String;
        using StringView = System::StringView;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        explicit ProjectGenerationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD GameParameterAnalysis GetGameParameterAnalysis() const noexcept;
        NODISCARD CodeMappingAnalysis GetCodeMappingAnalysis() const noexcept;

        NODISCARD static String GetIdentifier(const StringView& original);

        NODISCARD String GetDirectory() const;

        void GetContentTest(ProjectGenerationType projectGenerationType);
        void CopyrightTest(ProjectGenerationType projectGenerationType);
        void ModuleTest(ProjectGenerationType projectGenerationType);
        void ModuleJsonTest(ProjectGenerationType projectGenerationType);
        void ModuleTestingJsonTest(ProjectGenerationType projectGenerationType);
        void CodeAnalysisTest(ProjectGenerationType projectGenerationType);
        void TestingCodeAnalysisTest(ProjectGenerationType projectGenerationType);
        void MiddleLayerTest(ProjectGenerationType projectGenerationType);
        void MiddleLayerFwdTest(ProjectGenerationType projectGenerationType);
        void CallRunTestingBat(ProjectGenerationType projectGenerationType);
        void GameParameterTest(ProjectGenerationType projectGenerationType);

    private:
        GameParameterAnalysis gameParameterAnalysis;
        CodeMappingAnalysis codeMappingAnalysis;
        String directory;
    };
}

#endif  // ASSIST_TOOLS_TESTING_GENERATE_PROJECTS_SUITE_PROJECT_GENERATION_TESTING_H