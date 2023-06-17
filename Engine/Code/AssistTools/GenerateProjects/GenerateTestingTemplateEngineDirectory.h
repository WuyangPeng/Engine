///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2022/04/28 18:49)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTestingTemplateEngineDirectoryImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTestingTemplateEngineDirectory
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTestingTemplateEngineDirectory);

    public:
        GenerateTestingTemplateEngineDirectory(const System::String& directory, const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory,
                        const System::String& newSolutionName,
                        const System::String& newCoreName,
                        const System::String& newIncludeName,
                        const System::String& newTestingIncludeName,
                        const System::String& newDebugLibName,
                        const System::String& newReleaseLibName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TESTING_TEMPLATE_ENGINE_DIRECTORY_H
