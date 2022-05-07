///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:47)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MESSAGE_HEADER_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MESSAGE_HEADER_H

#include "AssistTools/AssistToolsDll.h"

#include "Flags/GenerateTemplateReplaceFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <map>
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateMessageImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateMessage
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateMessage);
        using Replace = std::map<GenerateTemplateReplace, System::String>;

    public:
        GenerateTemplateMessage(const System::String& templateFileName, const System::String& extension, const Replace& replace);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& solutionName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_MESSAGE_HEADER_H
