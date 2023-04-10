///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 09:25)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE RowRangeImpl final
    {
    public:
        using ClassType = RowRangeImpl;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        RowRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstXMLDocumentSharedPtr GetDocument() const;
        NODISCARD int GetRowCount() const noexcept;
        NODISCARD int GetFirstRow() const noexcept;
        NODISCARD int GetLastRow() const noexcept;
        NODISCARD XMLNode GetDataNode() const;
        NODISCARD SharedStringsSharedPtr GetSharedStrings();

    private:
        using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

    private:
        ConstXMLDocumentWeakPtr document;
        XMLNode dataNode;
        int firstRow;
        int lastRow;
        SharedStringsWeakPtr sharedStrings;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H
