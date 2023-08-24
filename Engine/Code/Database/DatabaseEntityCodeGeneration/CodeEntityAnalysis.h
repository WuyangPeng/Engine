///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:51)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Database/DatabaseEntityCodeGeneration/DatabaseEntityCodeGenerationFwd.h"

DATABASE_PERFORMANCE_UNSHARED_EXPORT_IMPL(CodeEntityAnalysisImpl);

#include <vector>

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeEntityAnalysis final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(CodeEntityAnalysis);

        using String = System::String;
        using Container = std::vector<CodeEntityClass>;
        using ContainerConstIter = Container::const_iterator;

    public:
        explicit CodeEntityAnalysis(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetNamespaceName() const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_ENTITY_ANALYSIS_IMPL_H
