///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/09 15:54)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_H
#define CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellIteratorImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::CellIterator, CoreTools::SimpleCSV::CellIteratorImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CellIterator final
        {
        public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(CellIterator);
            using ValueType = Cell;
            using DifferenceType = int64_t;
            using PointerType = Cell*;
            using ReferenceType = Cell&;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using CellSharedPtr = std::shared_ptr<Cell>;

        public:
            CellIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const CellRange& cellRange, IteratorLocation location);

            CLASS_INVARIANT_DECLARE;

            CellIterator& operator++();
            CellIterator operator++(int);
            NODISCARD ReferenceType operator*();
            NODISCARD PointerType operator->();

            NODISCARD bool IsSame(const CellIterator& rhs) const;
            NODISCARD int Distance(const CellIterator& last) const;

        private:
            PackageType impl;
        };

        NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator==(const CellIterator& lhs, const CellIterator& rhs);
        NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator!=(const CellIterator& lhs, const CellIterator& rhs);
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_H
