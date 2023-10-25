///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 14:59)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H

#include "CoreTools/CoreToolsDll.h"

#include "RowDataIterator.h"
#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataRangeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowDataRange, CoreTools::SimpleCSV::RowDataRangeImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RowDataRange final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RowDataRange);

        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowDataRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, int firstColumn, int lastColumn, const SharedStringsSharedPtr& sharedStrings);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSize() const noexcept;

        NODISCARD ConstXMLDocumentSharedPtr GetDocument();
        NODISCARD SharedStringsSharedPtr GetSharedStrings();
        NODISCARD XMLNode GetRowNode() const;
        NODISCARD int GetFirstColumn() const noexcept;
        NODISCARD int GetLastColumn() const noexcept;

        NODISCARD RowDataIterator begin();
        NODISCARD RowDataIterator end();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H
