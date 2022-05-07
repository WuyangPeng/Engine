///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:14)

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
