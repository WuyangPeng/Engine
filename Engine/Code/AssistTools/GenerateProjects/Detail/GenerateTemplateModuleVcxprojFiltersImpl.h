///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/28 18:14)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateModuleVcxprojFiltersImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateModuleVcxprojFiltersImpl;
        using ParentType = GenerateTemplateImpl;

    public:
        GenerateTemplateModuleVcxprojFiltersImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName) const;

    private:
        static const System::String extension;

    private:
        System::String solutionName;
        System::String moduleName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_FILTERS_IMPL_H
