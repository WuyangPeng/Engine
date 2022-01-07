///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:37)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE RowRangeImpl final
        {
        public:
            using ClassType = RowRangeImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

        public:
            RowRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings) noexcept;

            CLASS_INVARIANT_DECLARE;

            NODISCARD ConstXMLDocumentSharedPtr GetDocument();
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_RANGE_IMPL_H
