///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 11:23)

#include "CoreTools/CoreToolsExport.h"

#include "CellReference.h"
#include "Detail/CellReferenceImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellReference)

CoreTools::SimpleCSV::CellReference::CellReference(const std::string& cellAddress)
    : impl{ cellAddress }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellReference::CellReference(int row, int column)
    : impl{ row, column }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellReference::CellReference(int row, const std::string& column)
    : impl{ row, column }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellReference)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellReference, GetRow, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellReference, SetRow, int, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools::SimpleCSV, CellReference, GetColumn, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellReference, SetColumn, int, void)

void CoreTools::SimpleCSV::CellReference::SetRowAndColumn(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetRowAndColumn(row, column);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellReference, GetAddress, std::string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, CellReference, SetAddress, std::string, void)

bool CoreTools::SimpleCSV::operator==(const CellReference& lhs, const CellReference& rhs) noexcept
{
    return lhs.GetRow() == rhs.GetRow() && lhs.GetColumn() == rhs.GetColumn();
}

bool CoreTools::SimpleCSV::operator<(const CellReference& lhs, const CellReference& rhs) noexcept
{
    if (lhs.GetRow() < rhs.GetRow())
        return true;
    else if (rhs.GetRow() < lhs.GetRow())
        return false;
    else
        return lhs.GetColumn() < rhs.GetColumn();
}

int CoreTools::SimpleCSV::CellReference::GetColumn(const std::string& cellAddress)
{
    const ImplType cellReference{ cellAddress };

    return cellReference.GetColumn();
}