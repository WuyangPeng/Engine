/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:46)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/Row.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE RowIteratorImpl final
    {
    public:
        using ClassType = RowIteratorImpl;

        using ValueType = Row;
        using DifferenceType = int64_t;
        using PointerType = Row*;
        using ReferenceType = Row&;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const RowRange& rowRange, IteratorLocation location);

        CLASS_INVARIANT_DECLARE;

        RowIteratorImpl& operator++();
        RowIteratorImpl operator++(int);
        NODISCARD ReferenceType operator*() noexcept;
        NODISCARD PointerType operator->() noexcept;

        NODISCARD bool IsSame(const RowIteratorImpl& rhs) const;

    private:
        using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;
        using RowSharedPtr = std::shared_ptr<Row>;

    private:
        ConstXMLDocumentWeakPtr document;
        SharedStringsWeakPtr sharedStrings;
        XMLNode dataNode;
        int firstRow{ 1 };
        int lastRow{ 1 };
        RowSharedPtr currentRow;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_ITERATOR_IMPL_H
