///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/09 16:40)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateProjectsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

#include <map>

ASSIST_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(ProjectGenerationImpl);

namespace AssistTools
{
    class ASSIST_TOOLS_DEFAULT_DECLARE ProjectGeneration
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(ProjectGeneration);

        using String = System::String;
        using ReplaceContainer = std::vector<Replace>;
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;

    public:
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, ProjectServiceType projectServiceType);
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceContainer& replace);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H