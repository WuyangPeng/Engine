///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:36)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataIterator.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE RowDataProxyImpl final
        {
        public:
            using ClassType = RowDataProxyImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using CellValueContainer = std::vector<CellValue>;
            using BoolContainer = std::vector<bool>;
            using RowSharedPtr = std::shared_ptr<Row>;

        public:
            explicit RowDataProxyImpl(MAYBE_UNUSED DisableNotThrow disableNotThrow);
            RowDataProxyImpl(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode) noexcept;

            CLASS_INVARIANT_DECLARE;

            RowDataProxyImpl& operator=(const CellValueContainer& values);
            RowDataProxyImpl& operator=(const BoolContainer& values);

            NODISCARD CellValueContainer GetValues() const;
            NODISCARD SharedStringsSharedPtr GetSharedStrings();

            void DeleteCellValues(int count);
            void PrependCellValue(const CellValue& value, int column);

            NODISCARD XMLNode GetRowNode() const;

            void Clear();

            NODISCARD ConstXMLDocumentSharedPtr GetDocument();

        private:
            using RowWeakPtr = std::weak_ptr<Row>;

        private:
            ConstXMLDocumentWeakPtr document;
            RowWeakPtr row;
            XMLNode rowNode;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_DATA_PROXY_IMPL_H
