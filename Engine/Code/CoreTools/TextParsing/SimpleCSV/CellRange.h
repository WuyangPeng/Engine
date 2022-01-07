///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:47)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_RANGE_H
#define CORE_TOOLS_TEXT_PARSING_CELL_RANGE_H

#include "CoreTools/CoreToolsDll.h"

#include "CellIterator.h"
#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellRangeImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::CellRange, CoreTools::SimpleCSV::CellRangeImpl>;

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE CellRange final
        {
        public:
            COPY_UNSHARED_TYPE_DECLARE(CellRange);
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

        public:
            explicit CellRange(const ConstXMLDocumentSharedPtr& document,
                               const XMLNode& dataNode,
                               const CellReference& topLeft,
                               const CellReference& bottomRight,
                               const SharedStringsSharedPtr& sharedStrings);

            CLASS_INVARIANT_DECLARE;

            NODISCARD int GetNumRows() const noexcept;
            NODISCARD int GetNumColumns() const noexcept;

            NODISCARD ConstXMLDocumentSharedPtr GetDocument();
            NODISCARD XMLNode GetDataNode() const;
            NODISCARD CellReference GetTopLeft() const noexcept;
            NODISCARD CellReference GetBottomRight() const noexcept;
            NODISCARD SharedStringsSharedPtr GetSharedStrings();

            NODISCARD CellIterator begin();
            NODISCARD CellIterator end();

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_RANGE_H