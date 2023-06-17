///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:24)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateDirectoryImpl.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateCodeDirectoryImpl : public GenerateTemplateDirectoryImpl
    {
    public:
        using ClassType = GenerateTestingTemplateCodeDirectoryImpl;
        using ParentType = GenerateTemplateDirectoryImpl;

    public:
        GenerateTestingTemplateCodeDirectoryImpl(const System::String& directory, const std::string& configurationFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const;

    private:
        void GenerateToManager(const System::String& exportDirectory,
                               const System::String& newSolutionName,
                               const CopyrightData& copyrightData,
                               const System::String& aManagerName,
                               const System::String& projectCapital,
                               const System::String& managerCapital) const;
        void GenerateToManager(const System::String& exportDirectory,
                               const System::String& newSolutionName,
                               const CopyrightData& copyrightData,
                               const System::String& aManagerName,
                               const System::String& projectCapital,
                               const System::String& managerCapital,
                               const System::String& extension,
                               const System::String& fileName,
                               const System::String& resultName) const;
    };
}
#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_IMPL_H
