///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "Row.h"
#include "Detail/RowImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::SimpleCSV::Row::RowSharedPtr CoreTools::SimpleCSV::Row::CreateRow(const ConstXMLDocumentSharedPtr& document)
{
    return make_shared<Row>(document, RowCreate::Init);
}

CoreTools::SimpleCSV::Row::RowSharedPtr CoreTools::SimpleCSV::Row::CreateRow(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, SharedStringsSharedPtr sharedStrings)
{
    auto row = CreateRow(document);
    row->impl->Init(row, rowNode, sharedStrings);

    return row;
}

CoreTools::SimpleCSV::Row::Row(const ConstXMLDocumentSharedPtr& document, MAYBE_UNUSED RowCreate cellCreate)
    : impl{ document }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, Row)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetHeight, double)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Row, SetHeight, double, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetDescent, double)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Row, SetDescent, double, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, IsHidden, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Row, SetHidden, bool, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetRowNumber, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetCellCount, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, Row, GetValues, CoreTools::SimpleCSV::RowDataProxy&)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, Row, GetValues, const CoreTools::SimpleCSV::RowDataProxy&)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetCells, CoreTools::SimpleCSV::RowDataRange)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, Row, GetCells, int, CoreTools::SimpleCSV::RowDataRange)

CoreTools::SimpleCSV::RowDataRange CoreTools::SimpleCSV::Row::GetCells(int firstCell, int lastCell) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetCells(firstCell, lastCell);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetRowNode, CoreTools::SimpleCSV::XMLNode)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, Row, GetSharedStrings, CoreTools::SimpleCSV::Row::SharedStringsSharedPtr)

bool CoreTools::SimpleCSV::Row::IsSame(const Row& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsSame(*rhs.impl);
}

bool CoreTools::SimpleCSV::Row::IsLess(const Row& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsLess(*rhs.impl);
}

bool CoreTools::SimpleCSV::operator==(const Row& lhs, const Row& rhs)
{
    return lhs.IsSame(rhs);
}

bool CoreTools::SimpleCSV::operator<(const Row& lhs, const Row& rhs)
{
    return lhs.IsLess(rhs);
}
