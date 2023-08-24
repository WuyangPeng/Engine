///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/15 10:24)

#ifndef CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_H
#define CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeMappingAnalysisImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CodeMappingAnalysis final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CodeMappingAnalysis);

        using String = System::String;

    public:
        explicit CodeMappingAnalysis(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetElement(const String& codeKey) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_ANALYSIS_H
