///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 10:30)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_RANGE_H
#define CORE_TOOLS_TEXT_PARSING_ROW_RANGE_H

#include "CoreTools/CoreToolsDll.h"

#include "RowIterator.h"
#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowRangeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowRange, CoreTools::SimpleCSV::RowRangeImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RowRange final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RowRange);
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowRange(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetRowCount() const noexcept;
        NODISCARD int GetFirstRow() const noexcept;
        NODISCARD int GetLastRow() const noexcept;
        NODISCARD XMLNode GetDataNode() const;
        NODISCARD SharedStringsSharedPtr GetSharedStrings();

        NODISCARD RowIterator begin();
        NODISCARD RowIterator end();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_RANGE_H
