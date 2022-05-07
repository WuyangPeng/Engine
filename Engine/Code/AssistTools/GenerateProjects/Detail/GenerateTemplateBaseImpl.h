///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 16:37)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateTemplateImpl.h"
#include "AssistTools/GenerateProjects/Flags/GenerateTemplateReplaceFlags.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <map>

namespace AssistTools
{
    class ASSIST_TOOLS_HIDDEN_DECLARE GenerateTemplateBaseImpl : public GenerateTemplateImpl
    {
    public:
        using ClassType = GenerateTemplateBaseImpl;
        using ParentType = GenerateTemplateImpl;
        using Replace = std::map<GenerateTemplateReplace, System::String>;

    public:
        GenerateTemplateBaseImpl(const System::String& templateFileName, const System::String& extension, const Replace& replace);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD System::String GetOriginal(GenerateTemplateReplace flag) const;

        NODISCARD VariableType GetCopyrightVariable(const CopyrightData& copyrightData) const;

    private:
        static const System::String defaultEndYear;
        static const System::String defaultProjectChineseName;
        static const System::String defaultManagerChineseName;
        static const System::String defaultVersions;
        static const System::String defaultDate;
        static const System::String defaultHour;
        static const System::String defaultMinute;
        static const System::String defaultProjectCapital;
        static const System::String defaultManagerCapital;
        static const System::String defaultSolutionName;
        static const System::String defaultProjectName;
        static const System::String defaultManagerName;
        static const System::String defaultInterfaceName;

        Replace replace;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_BASE_IMPL_H
