///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:45)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeMappingAnalysisImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeMappingAnalysis final
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

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_ANALYSIS_H
