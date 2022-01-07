///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:32)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE CellIteratorImpl final
        {
        public:
            using ClassType = CellIteratorImpl;
            using ValueType = Cell;
            using DifferenceType = int64_t;
            using PointerType = Cell*;
            using ReferenceType = Cell&;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using CellSharedPtr = std::shared_ptr<Cell>;

        public:
            CellIteratorImpl(const ConstXMLDocumentSharedPtr& document, const SharedStringsSharedPtr& sharedStrings, const CellRange& cellRange, IteratorLocation location);

            CLASS_INVARIANT_DECLARE;

            CellIteratorImpl& operator++();
            CellIteratorImpl operator++(int);

            NODISCARD ReferenceType operator*() noexcept;
            NODISCARD PointerType operator->() noexcept;

            NODISCARD bool IsSame(const CellIteratorImpl& rhs) const;
            NODISCARD int Distance(const CellIteratorImpl& last) const;

        private:
            using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

        private:
            NODISCARD static CellSharedPtr GetCurrentCell(const ConstXMLDocumentSharedPtr& document,
                                                          const SharedStringsSharedPtr& sharedStrings,
                                                          const XMLNode& dataNode,
                                                          const CellReference& topLeft,
                                                          IteratorLocation location);

            NODISCARD CellReference GetNextCellReference() const;
            void AddCurrentCell(const CellReference& nextCellReference);
            void AddSameRowCurrentCell(const CellReference& nextCellReference);
            void AddNextRowCurrentCell(const CellReference& nextCellReference);

            void CheckDocument();
            void SetCurrentCell(const XMLNode& dataNode);

        private:
            ConstXMLDocumentWeakPtr document;
            CellReference topLeft;
            CellReference bottomRight;
            CellSharedPtr currentCell;
            SharedStringsWeakPtr sharedStrings;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_ITERATOR_IMPL_H
