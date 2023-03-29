///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/07 13:55)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE RowDataIteratorImpl final
    {
    public:
        using ClassType = RowDataIteratorImpl;
        using ValueType = Cell;
        using DifferenceType = int64_t;
        using PointerType = Cell*;
        using ReferenceType = Cell&;
        using CellSharedPtr = std::shared_ptr<Cell>;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowDataIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowDataRange& rowDataRange, IteratorLocation location);

        CLASS_INVARIANT_DECLARE;

        RowDataIteratorImpl& operator++();
        RowDataIteratorImpl operator++(int);
        NODISCARD ReferenceType operator*() noexcept;
        NODISCARD PointerType operator->() noexcept;

        NODISCARD bool IsSame(const RowDataIteratorImpl& rhs) const;

    private:
        ConstXMLDocumentWeakPtr document;
        RowDataRange dataRange;
        XMLNode cellNode;
        CellSharedPtr currentCell;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_IMPL_H
