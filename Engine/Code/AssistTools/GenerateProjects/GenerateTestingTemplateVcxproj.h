///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/28 18:49)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingTemplateVcxprojImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateVcxproj
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingTemplateVcxproj);

    public:
        GenerateTestingTemplateVcxproj(const System::String& templateFileName,
                                       const System::String& projectName,
                                       const System::String& moduleName,
                                       const System::String& includeName,
                                       const System::String& testingIncludeName,
                                       const System::String& debugLibName,
                                       const System::String& releaseLibName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& solutionName,
                        const System::String& newModuleName,
                        const System::String& newIncludeName,
                        const System::String& newTestingIncludeName,
                        const System::String& newDebugLibName,
                        const System::String& newReleaseLibName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_VCXPROJ_H
