///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/28 18:18)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateSolutionImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateSolutionImpl;
        using ParentType = GenerateTemplateImpl;

    public:
        GenerateTemplateSolutionImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& coreName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName) const;

    private:
        static const System::String extension;

        System::String solutionName;
        System::String coreName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_SOLUTION_IMPL_H
