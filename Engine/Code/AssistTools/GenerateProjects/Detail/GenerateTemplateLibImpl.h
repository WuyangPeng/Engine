///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:07)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateLibImpl : public GenerateTemplateBaseImpl
    {
    public:
        using ClassType = GenerateTemplateLibImpl;
        using ParentType = GenerateTemplateBaseImpl;

    public:
        GenerateTemplateLibImpl(const System::String& templateFileName, const Replace& replace);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newProjectName,
                        const CopyrightData& copyrightData,
                        const System::String& solutionName) const;

    private:
        static const System::String extension;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LIB_IMPL_H
