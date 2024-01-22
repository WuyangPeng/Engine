/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:46)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_RANGE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_RANGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE CellRangeImpl final
    {
    public:
        using ClassType = CellRangeImpl;

        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;

    public:
        CellRangeImpl(const ConstXMLDocumentSharedPtr& document,
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

    private:
        using SharedStringsWeakPtr = std::weak_ptr<SharedStrings>;

    private:
        ConstXMLDocumentWeakPtr document;
        XMLNode dataNode;
        CellReference topLeft;
        CellReference bottomRight;
        SharedStringsWeakPtr sharedStrings;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_RANGE_IMPL_H