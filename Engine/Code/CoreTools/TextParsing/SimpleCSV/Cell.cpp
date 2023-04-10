///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:09)

#include "CoreTools/CoreToolsExport.h"

#include "Cell.h"
#include "Detail/CellImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, Cell, GetValue, CoreTools::SimpleCSV::CellValueProxy&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, Cell, GetValue, const CoreTools::SimpleCSV::CellValueProxy&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Cell, GetCellReference, CoreTools::SimpleCSV::CellReference)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Cell, HasFormula, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Cell, GetFormula, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, Cell, SetFormula, std::string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Cell, GetSharedStrings, CoreTools::SimpleCSV::Cell::SharedStringsSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Cell, GetXMLNode, CoreTools::SimpleCSV::XMLNode)

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
