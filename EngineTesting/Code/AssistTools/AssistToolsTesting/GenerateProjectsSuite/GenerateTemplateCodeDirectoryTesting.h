///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 10:50)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H

#include "GenerateTemplateTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace AssistTools
{
    class GenerateTemplateCodeDirectoryTesting : public GenerateTemplateTesting
    {
    public:
        using ClassType = GenerateTemplateCodeDirectoryTesting;
        using ParentType = GenerateTemplateTesting;

    public:
        explicit GenerateTemplateCodeDirectoryTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();

        void GenerateToTest();
        void HeaderExistTest();
        void HelperExistToTest(const System::String& extension);
        void MessageExistToTest(const System::String& extension);
        void LibExistTest();
        void MainExistTest();
        void ManagerExistTest(const System::String& managerName);
        void ManagerHeaderExistTest(const System::String& managerName, const System::String& resultSuffix);
        void ManagerLibExistTest(const System::String& managerName);
        void DllMainExistTest(const System::String& managerName);
        void DllLibExistTest(const System::String& managerName);
        void MacroExistTest(const System::String& managerName, const System::String& resultSuffix);
        void ManagerEngineExistTest(const System::String& managerName);
        void InputManagerEngineExistTest();
        void CoreEngineExistTest();
        void EngineExistTest(const System::String& managerName, const System::String& resultSuffix);
        void MiddleLayerEngineExistTest(const System::String& managerName, const System::String& resultSuffix);

        void DoRunUnitTest() override;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_GENERATE_TEMPLATE_CODE_DIRECTORY_TESTING_H