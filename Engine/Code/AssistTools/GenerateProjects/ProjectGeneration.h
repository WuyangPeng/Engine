///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/16 14:20)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H

#include "AssistTools/AssistToolsDll.h"

#include "GenerateProjectsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/CharacterString/CharacterStringFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
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
        using CodeMappingAnalysis = CoreTools::CodeMappingAnalysis;
        using ReplaceType = std::map<String, String>;

    public:
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis);
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, bool isClient);
        ProjectGeneration(ProjectGenerationType projectGenerationType, const String& fileName, const GameParameterAnalysis& gameParameterAnalysis, const CodeMappingAnalysis& codeMappingAnalysis, const ReplaceType& replace);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetContent() const;

    private:
        PackageType impl;
    };
}

#endif  // ASSIST_TOOLS_GENERATE_PROJECTS_PROJECT_GENERATION_H