///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2022/04/28 18:46)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LOG_JSON_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LOG_JSON_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateLogJsonImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateLogJson
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateLogJson);

    public:
        GenerateTemplateLogJson(const System::String& templateFileName, const System::String& projectName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& solutionName, const System::String& newFileName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_LOG_JSON_H
