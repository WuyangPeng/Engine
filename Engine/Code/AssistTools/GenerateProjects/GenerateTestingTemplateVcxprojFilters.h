///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:50)

#ifndef ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_H
#define ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingTemplateVcxprojFiltersImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateVcxprojFilters
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingTemplateVcxprojFilters);

    public:
        GenerateTestingTemplateVcxprojFilters(const System::String& templateFileName, const System::String& projectName, const System::String& moduleName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newProjectName, const System::String& newModuleName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECT_SGENERATE_TESTING_TEMPLATE_VCXPROJ_FILTERS_IMPL_H
