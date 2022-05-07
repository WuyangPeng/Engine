///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:08)

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