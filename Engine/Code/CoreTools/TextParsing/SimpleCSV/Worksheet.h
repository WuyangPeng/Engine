/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 15:22)

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
        using CountType = std::vector<int>;

    private:
        void Init();
        void SetDimensionNode();

        static void Init(XMLNode colsNode);
        static void Init(XMLNode colsNode, XMLNode currentNode);
        static void Init(XMLNode colsNode, XMLNode currentNode, int index);

        static void SetTabColor(const XMLDocument& xmlDocument, const Color& color);
        NODISCARD static Color GetTabColor(const XMLDocument& xmlDocument);
        NODISCARD static XMLNode CreateTabColor(const XMLDocument& xmlDocument);
        static void SetTabSelected(const XMLDocument& xmlDocument, bool selected);
        NODISCARD static bool TabIsSelected(const XMLDocument& xmlDocument);

        NODISCARD XMLNode GetCellNode(int rowNumber, int columnNumber) const;
        NODISCARD static XMLNode GetCellNodeInColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode);
        NODISCARD static XMLNode GetCellNodeInTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode);
        NODISCARD static XMLNode GetCellNodeGreaterTwoColumnNumber(int rowNumber, int columnNumber, XMLNode rowNode);

        NODISCARD static XMLNode GetFirstChildPreviousSibling(int columnNumber, const XMLNode& rowNode);
        NODISCARD static XMLNode GetLastChildPreviousSibling(int columnNumber, const XMLNode& rowNode);

        NODISCARD XMLNode GetFirstChildColumnsByInsertChildBefore() const;
        static void AppendAttribute(int columnNumber, int attributeMin, XMLNode firstChildColumns, XMLNode& columnNode);

        NODISCARD CountType GetCellCount() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_WORKSHEET_H
