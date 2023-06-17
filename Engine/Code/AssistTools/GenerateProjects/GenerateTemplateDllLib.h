///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:42)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DLL_LIB_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DLL_LIB_H

#include "AssistTools/AssistToolsDll.h"

#include "Flags/GenerateTemplateReplaceFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <map>
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateDllLibImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateDllLib
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateDllLib);
        using Replace = std::map<GenerateTemplateReplace, System::String>;

    public:
        GenerateTemplateDllLib(const System::String& templateFileName, const Replace& replace);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newProjectName,
                        const CopyrightData& copyrightData,
                        const System::String& solutionName,
                        const System::String& managerName,
                        const System::String& managerChineseName,
                        const System::String& projectCapital,
                        const System::String& managerCapital) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_DLL_LIB_H
