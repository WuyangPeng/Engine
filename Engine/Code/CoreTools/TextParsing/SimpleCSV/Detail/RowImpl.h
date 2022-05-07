///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:36)

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