///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:09)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QueryXmlDataImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QueryXmlDataImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE QueryXmlData final
        {
        public:
            PERFORMANCE_UNSHARED_TYPE_DECLARE(QueryXmlData);
            using XmlDataSharedPtr = std::shared_ptr<XmlData>;

        public:
            explicit QueryXmlData(const std::string& xmlPath);
            QueryXmlData(const std::string& xmlPath, const XmlDataSharedPtr& xmlData);

            CLASS_INVARIANT_DECLARE;

            NODISCARD std::string GetXmlPath() const;
            NODISCARD XmlDataSharedPtr GetXmlData() const;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H
