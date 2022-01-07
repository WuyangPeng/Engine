///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:32)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValueProxy.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        // 封装电子表格单元格的属性和行为的实现类。
        class CORE_TOOLS_HIDDEN_DECLARE CellImpl final
        {
        public:
            using ClassType = CellImpl;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using CellSharedPtr = std::shared_ptr<Cell>;

        public:
            explicit CellImpl(MAYBE_UNUSED DisableNotThrow disableNotThrow);
            CellImpl(const CellSharedPtr& cell, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings);

            CLASS_INVARIANT_DECLARE;

            void Init(const CellSharedPtr& cell, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings);

            NODISCARD explicit operator bool() const;

            NODISCARD CellValueProxy& GetValue() noexcept;
            NODISCARD const CellValueProxy& GetValue() const noexcept;
            NODISCARD CellReference GetCellReference() const;

            NODISCARD bool HasFormula() const;
            NODISCARD std::string GetFormula() const;
            void SetFormula(const std::string& newFormula);

            NODISCARD bool IsSame(const CellImpl& rhs) const;

            NODISCARD SharedStringsSharedPtr GetSharedStrings() const;
            NODISCARD XMLNode GetXMLNode() const;

        private:
            using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

        private:
            void CheckDocument() const;
            NODISCARD XMLNode GetFormulaNode() const;
            NODISCARD XMLNode AppendFormulaChild();

        private:
            ConstXMLDocumentWeakPtr m_Document;
            XMLNode m_CellNode;
            SharedStringsWeakPtr m_SharedStrings;
            CellValueProxy m_ValueProxy;
            bool isNull;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_IMPL_H
