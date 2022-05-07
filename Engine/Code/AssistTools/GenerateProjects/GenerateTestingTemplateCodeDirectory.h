///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:49)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "AssistTools/GenerateProjects/GenerateProjectsFwd.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingTemplateCodeDirectoryImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateCodeDirectory
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingTemplateCodeDirectory);

    public:
        GenerateTestingTemplateCodeDirectory(const System::String& directory, const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& exportDirectory, const System::String& newSolutionName, const CopyrightData& copyrightData, const System::String& projectCapital, const System::String& newCoreName, const System::String& CoreNameCapital) const;

    private:
        PackageType impl;
    };
}
#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_CODE_DIRECTORY_H
