///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/10 1:12)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_IMPL_H

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
        class CORE_TOOLS_HIDDEN_DECLARE RowDataRangeImpl final
        {
        public:
            using ClassType = RowDataRangeImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

        public:
            RowDataRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, int firstColumn, int lastColumn, const SharedStringsSharedPtr& sharedStrings);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetSize() const noexcept;

            NODISCARD ConstXMLDocumentSharedPtr GetDocument();
            NODISCARD SharedStringsSharedPtr GetSharedStrings();
            NODISCARD XMLNode GetRowNode() const;
            NODISCARD int GetFirstColumn() const noexcept;
            NODISCARD int GetLastColumn() const noexcept;

        private:
            using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

        private:
            ConstXMLDocumentWeakPtr document;
            XMLNode rowNode;
            int firstColumn{ 1 };
            int lastColumn{ 1 };
            SharedStringsWeakPtr sharedStrings;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_RANGE_IMPL_H
