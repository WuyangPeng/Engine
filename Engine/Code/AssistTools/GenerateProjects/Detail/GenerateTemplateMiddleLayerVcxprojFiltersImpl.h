///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:10)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateMiddleLayerVcxprojFiltersImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateMiddleLayerVcxprojFiltersImpl;
        using ParentType = GenerateTemplateImpl;

    public:
        GenerateTemplateMiddleLayerVcxprojFiltersImpl(const System::String& templateFileName, const System::String& projectName, const System::String& managerName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newManagerName) const;

    private:
        static const System::String extension;

    private:
        System::String projectName;
        System::String managerName;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MANAGER_VCXPROJ_FILTERS_IMPL_H
