///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/28 18:44)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_H

#include "AssistTools/AssistToolsDll.h"

#include "Flags/GenerateTemplateReplaceFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <map>
#include <string>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(GenerateTemplateEngineDirectoryImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE GenerateTemplateEngineDirectory
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(GenerateTemplateEngineDirectory);

    public:
        GenerateTemplateEngineDirectory(const System::String& directory, const std::string& configurationFileName);

        CLASS_INVARIANT_DECLARE;

        void GenerateTo(const System::String& resourceDirectory, const System::String& newSolutionName, const System::String& newCoreName, const System::String& newIncludeName) const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_GENERATE_TEMPLATE_ENGINE_DIRECTORY_H
