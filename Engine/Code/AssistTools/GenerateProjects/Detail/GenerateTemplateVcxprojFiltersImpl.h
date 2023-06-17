///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/28 18:21)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateVcxprojFiltersImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateVcxprojFiltersImpl;
        using ParentType = GenerateTemplateImpl;

    public:
        GenerateTemplateVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName) const;

    private:
        static const System::String extension;

    private:
        System::String projectName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
