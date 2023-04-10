///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:16)

#ifndef CORE_TOOLS_TEXT_PARSING_CELL_H
#define CORE_TOOLS_TEXT_PARSING_CELL_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::CellImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::NonCopyImpl<CoreTools::SimpleCSV::CellImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Cell final
    {
    public:
        NON_COPY_TYPE_DECLARE(Cell);
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
        using CellSharedPtr = std::shared_ptr<Cell>;

    public:
        NODISCARD static CellSharedPtr CreateCell();
        NODISCARD static CellSharedPtr CreateCell(const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings);

        CLASS_INVARIANT_DECLARE;

        NODISCARD explicit operator bool() const;

        NODISCARD CellValueProxy& GetValue() noexcept;
        NODISCARD const CellValueProxy& GetValue() const noexcept;
        NODISCARD CellReference GetCellReference() const;

        NODISCARD bool HasFormula() const;
        NODISCARD std::string GetFormula() const;
        void SetFormula(const std::string& formula);

        NODISCARD bool IsSame(const Cell& rhs) const;
        NODISCARD SharedStringsSharedPtr GetSharedStrings() const;
        NODISCARD XMLNode GetXMLNode() const;

    private:
        enum class CellCreate
        {
            Init,
        };

    public:
        explicit Cell(CellCreate cellCreate);
        explicit Cell(CellCreate cellCreate, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings);

    private:
        PackageType impl;
    };

    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator==(const Cell& lhs, const Cell& rhs);
    CORE_TOOLS_DEFAULT_DECLARE NODISCARD bool operator!=(const Cell& lhs, const Cell& rhs);
}

#endif  // CORE_TOOLS_TEXT_PARSING_CELL_H
