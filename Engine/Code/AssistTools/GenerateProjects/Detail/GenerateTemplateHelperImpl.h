///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/28 18:02)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HELPER_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HELPER_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateBaseImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateHelperImpl : public GenerateTemplateBaseImpl
    {
    public:
        using ClassType = GenerateTemplateHelperImpl;
        using ParentType = GenerateTemplateBaseImpl;

    public:
        GenerateTemplateHelperImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newProjectName,
                        const CopyrightData& copyrightData,
                        const System::String& projectCapital,
                        const System::String& solutionName) const;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HELPER_IMPL_H
