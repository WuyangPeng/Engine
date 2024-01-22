/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:43)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySharedStringsImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySharedStringsImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE QuerySharedStrings final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(QuerySharedStrings);

        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        NODISCARD static QuerySharedStrings Create();
        explicit QuerySharedStrings(const SharedStringsSharedPtr& sharedStrings);

        CLASS_INVARIANT_DECLARE;

        NODISCARD SharedStringsSharedPtr GetSharedStrings() const;

    private:
        explicit QuerySharedStrings(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H
