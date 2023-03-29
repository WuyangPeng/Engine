///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 10:18)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataIteratorImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowDataIterator, CoreTools::SimpleCSV::RowDataIteratorImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RowDataIterator final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RowDataIterator);
        using ValueType = Cell;
        using DifferenceType = int64_t;
        using PointerType = Cell*;
        using ReferenceType = Cell&;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
        using CellSharedPtr = std::shared_ptr<Cell>;

    public:
        RowDataIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowDataRange& rowDataRange, IteratorLocation location);

        CLASS_INVARIANT_DECLARE;

        RowDataIterator& operator++();
        RowDataIterator operator++(int);
        NODISCARD ReferenceType operator*() noexcept;
        NODISCARD PointerType operator->() noexcept;

        NODISCARD bool IsSame(const RowDataIterator& rhs) const;

    private:
        PackageType impl;
    };

    NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator==(const RowDataIterator& lhs, const RowDataIterator& rhs);
    NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator!=(const RowDataIterator& lhs, const RowDataIterator& rhs);
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H
