///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:44)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_H

#include "AssistTools/AssistToolsDll.h"

#include "Flags/GenerateTemplateReplaceFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <map>
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateHeaderImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateHeader
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateHeader);
        using Replace = std::map<GenerateTemplateReplace, System::String>;

    public:
        GenerateTemplateHeader(const System::String& templateFileName, const Replace& replace);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_HEADER_H
