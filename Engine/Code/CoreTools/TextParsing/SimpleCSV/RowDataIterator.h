///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/09 18:18)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowDataIteratorImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::DelayCopyUnsharedImpl<CoreTools::SimpleCSV::RowDataIterator, CoreTools::SimpleCSV::RowDataIteratorImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE RowDataIterator final
        {
        public:
            DELAY_COPY_UNSHARED_TYPE_DECLARE(RowDataIterator);
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
            NODISCARD ReferenceType operator*();
            NODISCARD PointerType operator->();

            NODISCARD bool IsSame(const RowDataIterator& rhs) const;

        private:
            PackageType impl;
        };

        NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator==(const RowDataIterator& lhs, const RowDataIterator& rhs);
        NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator!=(const RowDataIterator& lhs, const RowDataIterator& rhs);
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_ITERATOR_H
