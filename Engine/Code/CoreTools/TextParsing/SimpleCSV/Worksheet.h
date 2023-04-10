///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:18)

#ifndef CORE_TOOLS_TEXT_PARSING_WORKSHEET_H
#define CORE_TOOLS_TEXT_PARSING_WORKSHEET_H

#include "CoreTools/CoreToolsDll.h"

#include "Cell.h"
#include "CellRange.h"
#include "Column.h"
#include "Row.h"
#include "SheetBase.h"

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Worksheet final : public SheetBase
    {
    public:
        using ClassType = Worksheet;
        using ParentType = SheetBase;
        using CellSharedPtr = std::shared_ptr<Cell>;
        using RowSharedPtr = std::shared_ptr<Row>;

    public:
        explicit Worksheet(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD CellSharedPtr GetCell(const std::string& ref) const;
        NODISCARD CellSharedPtr GetCell(const CellReference& ref) const;
        NODISCARD CellSharedPtr GetCell(int rowNumber, int columnNumber) const;
        NODISCARD CellRange GetRange() const;
        NODISCARD CellRange GetRange(const CellReference& topLeft, const CellReference& bottomRight) const;
        NODISCARD RowRange GetRows() const;
        NODISCARD RowRange GetRows(int rowCount) const;
        NODISCARD RowRange GetRows(int firstRow, int lastRow) const;
        NODISCARD RowSharedPtr GetRow(int rowNumber) const;
        NODISCARD Column GetColumn(int columnNumber) const;
        NODISCARD CellReference GetLastCell() const;
        NODISCARD int GetColumnCount() const;
        NODISCARD int GetRowCount() const;
        NODISCARD bool IsSelected() const override;
        void SetSelected(bool selected) override;
        void SetColor(const Color& color) override;
        NODISCARD Color GetColor() const override;

    private:
        void Init();

        void Init(XMLNode colsNode);

        static void SetTabColor(const XMLDocument& xmlDocument, const Color& color);
        NODISCARD static Color GetTabColor(const XMLDocument& xmlDocument);
        NODISCARD static XMLNode CreateTabColor(const XMLDocument& xmlDocument);
        static void SetTabSelected(const XMLDocument& xmlDocument, bool selected);
        NODISCARD static bool TabIsSelected(const XMLDocument& xmlDocument);

        NODISCARD XMLNode GetCellNode(int rowNumber, int columnNumber) const;
        NODISCARD XMLNode GetCellNodeInColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const;
        NODISCARD XMLNode GetCellNodeInTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const;
        NODISCARD XMLNode GetCellNodeGreaterTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode) const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_WORKSHEET_H
