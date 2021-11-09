///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/11 11:34)

#ifndef CORE_TOOLS_TEXT_PARSING_ROW_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_ROW_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/RowDataRange.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE RowImpl final
        {
        public:
            using ClassType = RowImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using RowSharedPtr = std::shared_ptr<Row>;

        public:
            explicit RowImpl(const ConstXMLDocumentSharedPtr& document);
            RowImpl(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings);

            CLASS_INVARIANT_DECLARE;

            void Init(const RowSharedPtr& row, const XMLNode& rowNode, const SharedStringsSharedPtr& sharedStrings);

            NODISCARD double GetHeight() const;
            void SetHeight(double height);
            NODISCARD double GetDescent() const;
            void SetDescent(double descent);
            NODISCARD bool IsHidden() const;
            void SetHidden(bool state);
            NODISCARD int GetRowNumber() const;
            NODISCARD int GetCellCount() const;
            NODISCARD RowDataProxy& GetValues() noexcept;
            NODISCARD const RowDataProxy& GetValues() const noexcept;
            NODISCARD RowDataRange GetCells() const;
            NODISCARD RowDataRange GetCells(int cellCount) const;
            NODISCARD RowDataRange GetCells(int firstCell, int lastCell) const;
            NODISCARD XMLNode GetRowNode() const;
            NODISCARD SharedStringsSharedPtr GetSharedStrings();
            NODISCARD bool IsSame(const RowImpl& rhs) const;
            NODISCARD bool IsLess(const RowImpl& rhs) const;

        private:
            using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

        private:
            ConstXMLDocumentWeakPtr m_Document;
            XMLNode m_RowNode;
            SharedStringsWeakPtr m_SharedStrings;
            RowDataProxy m_RowDataProxy;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_ROW_IMPL_H
