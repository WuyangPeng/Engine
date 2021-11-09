///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/10 1:12)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataRangeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::RowDataRange, CoreTools::SimpleCSV::RowDataRangeImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE RowDataRange final
        {
        public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(RowDataRange);
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_H
