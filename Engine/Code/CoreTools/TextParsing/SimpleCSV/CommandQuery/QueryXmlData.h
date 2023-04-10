///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:15)

#ifndef CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H
#define CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<const CoreTools::SimpleCSV::QueryXmlDataImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<CoreTools::SimpleCSV::QueryXmlDataImpl>;

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_QUERY_XML_DATA_H
