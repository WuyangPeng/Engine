/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:49)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_H
#define CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_H

#include "CoreTools/CoreToolsDll.h"

#include "Row.h"
#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::RowIteratorImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::RowIterator, CoreTools::SimpleCSV::RowIteratorImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE RowIterator final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RowIterator);

        using ValueType = Row;
        using DifferenceType = int64_t;
        using PointerType = Row*;
        using ReferenceType = Row&;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowIterator(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowRange& rowRange, IteratorLocation location);

        CLASS_INVARIANT_DECLARE;

        RowIterator& operator++();
        RowIterator operator++(int);
        NODISCARD ReferenceType operator*() noexcept;
        NODISCARD PointerType operator->() noexcept;

        NODISCARD bool IsSame(const RowIterator& rhs) const;

    private:
        PackageType impl;
    };

    NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator==(const RowIterator& lhs, const RowIterator& rhs);
    NODISCARD CORE_TOOLS_DEFAULT_DECLARE bool operator!=(const RowIterator& lhs, const RowIterator& rhs);
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_H
