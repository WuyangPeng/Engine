///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 15:17)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateDirectory.h"
#include "GenerateEngineBase.h"
#include "System/Helper/UnicodeUsing.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTestingEngineImpl final : public GenerateEngineBase
    {
    public:
        using ClassType = GenerateTestingEngineImpl;
        using ParentType = GenerateEngineBase;

    public:
        GenerateTestingEngineImpl(const String& input, const String& output);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void GenerateRun() const override;
        void GenerateWindows() const override;

        void GenerateBinaryConfiguration(const String& staticDescribe, const GenerateDirectory& directory) const override;

        void GenerateRunBat(const GenerateDirectory& directory) const override;
        void GenerateRunBat(const String& moduleName, const GenerateDirectory& directory) const override;

        void GenerateCodeProject(const GenerateDirectory& directory) const override;
        void GenerateCodeVersion(const GenerateDirectory& directory) const;
        void GenerateCodeEngine(const GenerateDirectory& directory) const;

        void GenerateCodeModule(const GenerateDirectory& directory) const override;
        void GenerateWindowsProjectModule(const GenerateDirectory& directory) const;

        void GenerateWindowsProject(const GenerateDirectory& directory) const;
        void GenerateWindowsProjectVcxproj(const GenerateDirectory& directory) const;

        void GenerateWindowsProjectConfiguration(const GenerateDirectory& directory) const;

    private:
        String projectName;
        String testingName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_ENGINE_IMPL_H
