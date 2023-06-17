///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/28 18:15)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateModuleVcxprojImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateModuleVcxprojImpl;
        using ParentType = GenerateTemplateImpl;

    public:
        GenerateTemplateModuleVcxprojImpl(const System::String& templateFileName, const System::String& solutionName, const System::String& moduleName, const System::String& includeName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newModuleName, const System::String& newIncludeName) const;

    private:
        static const System::String extension;

    private:
        System::String solutionName;
        System::String moduleName;
        System::String includeName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MODULE_VCXPROJ_IMPL_H
