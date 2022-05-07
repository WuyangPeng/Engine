///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:27)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateDirectoryImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingTemplateEngineDirectoryImpl : public GenerateTemplateDirectoryImpl
    {
    public:
        using ClassType = GenerateTestingTemplateEngineDirectoryImpl;
        using ParentType = GenerateTemplateDirectoryImpl;

    public:
        GenerateTestingTemplateEngineDirectoryImpl(const System::String& directory, const std::string& configurationFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newSolutionName,
                        const System::String& newCoreName,
                        const System::String& newIncludeName,
                        const System::String& newTestingIncludeName,
                        const System::String& newDebugLibName,
                        const System::String& newReleaseLibName) const;

    private:
        void GenerateToSolution(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const;
        void GenerateToModule(const System::String& resourceDirectory,
                              const System::String& newSolutionName,
                              const System::String& newIncludeName,
                              const System::String& newTestingIncludeName,
                              const System::String& newDebugLibName,
                              const System::String& newReleaseLibName,
                              const System::String& aModuleName) const;
        void GenerateToModuleVcxproj(const System::String& resourceDirectory,
                                     const System::String& newSolutionName,
                                     const System::String& newIncludeName,
                                     const System::String& newTestingIncludeName,
                                     const System::String& newDebugLibName,
                                     const System::String& newReleaseLibName,
                                     const System::String& aModuleName) const;
        void GenerateToModuleVcxprojFilters(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const;
        void GenerateToUpdate(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const;
        void GenerateToLogJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const;
        void GenerateToTestingJson(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const;
        void GenerateToEnvironmentVariable(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& aModuleName) const;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_IMPL_H
