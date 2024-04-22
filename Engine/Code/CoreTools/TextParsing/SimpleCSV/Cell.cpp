/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:26)

#include "CoreTools/CoreToolsExport.h"

#include "Cell.h"
#include "Detail/CellImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::Cell::Cell(CellCreate cellCreate)
    : impl{ DisableNotThrow::Disable }
{
    System::UnusedFunction(cellCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Cell::Cell(CellCreate cellCreate, const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings)
    : impl{ document, cellNode, sharedStrings }
{
    System::UnusedFunction(cellCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::Cell::CellSharedPtr CoreTools::SimpleCSV::Cell::CreateCell()
{
    return std::make_shared<Cell>(CellCreate::Init);
}

CoreTools::SimpleCSV::Cell::CellSharedPtr CoreTools::SimpleCSV::Cell::CreateCell(const ConstXMLDocumentSharedPtr& document, const XMLNode& cellNode, const SharedStringsSharedPtr& sharedStrings)
{
    auto cell = make_shared<Cell>(CellCreate::Init, document, cellNode, sharedStrings);
    cell->impl->Init(cell);

    return cell;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Cell)

CoreTools::SimpleCSV::Cell::operator bool() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return static_cast<bool>(*impl);
}

CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::Cell::GetValue() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetValue();
}

const CoreTools::SimpleCSV::CellValueProxy& CoreTools::SimpleCSV::Cell::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValue();
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::Cell::GetCellReference() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCellReference();
}

bool CoreTools::SimpleCSV::Cell::HasFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->HasFormula();
}

std::string CoreTools::SimpleCSV::Cell::GetFormula() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFormula();
}

void CoreTools::SimpleCSV::Cell::SetFormula(const std::string& formula)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetFormula(formula);
}

CoreTools::SimpleCSV::Cell::SharedStringsSharedPtr CoreTools::SimpleCSV::Cell::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSharedStrings();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::Cell::GetXMLNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXMLNode();
}

bool CoreTools::SimpleCSV::Cell::IsSame(const Cell& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

bool CoreTools::SimpleCSV::operator==(const Cell& lhs, const Cell& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator!=(const Cell& lhs, const Cell& rhs)
{
    return !lhs.IsSame(rhs);
}
