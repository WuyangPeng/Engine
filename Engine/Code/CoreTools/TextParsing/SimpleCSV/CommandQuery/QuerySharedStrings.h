///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:01)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QuerySharedStringsImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QuerySharedStringsImpl>;

namespace CoreTools
{
    namespace SimpleCSV
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
            explicit QuerySharedStrings(MAYBE_UNUSED DisableNotThrow disableNotThrow);

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_SHARED_STRINGS_H
