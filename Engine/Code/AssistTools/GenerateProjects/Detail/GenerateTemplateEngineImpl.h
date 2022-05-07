///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:00)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateEngineImpl : public GenerateTemplateBaseImpl
    {
    public:
        using ClassType = GenerateTemplateEngineImpl;
        using ParentType = GenerateTemplateBaseImpl;

    public:
        GenerateTemplateEngineImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newProjectName,
                        const CopyrightData& copyrightData,
                        const System::String& solutionName,
                        const System::String& managerName,
                        const System::String& interfaceName,
                        const System::String& projectCapital,
                        const System::String& managerCapital) const;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_IMPL_H
