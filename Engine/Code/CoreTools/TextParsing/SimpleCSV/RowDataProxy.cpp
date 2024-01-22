/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataProxyDetail.h"
#include "Detail/RowDataProxyImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, RowDataProxy)

CoreTools::SimpleCSV::RowDataProxy::RowDataProxy(const ConstXMLDocumentSharedPtr& document, const RowSharedPtr& row, const XMLNode& rowNode)
    : impl{ document, row, rowNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::RowDataProxy::RowDataProxy(DisableNotThrow disableNotThrow)
    : impl{ disableNotThrow }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataProxy)

CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowDataProxy::operator=(const CellValueContainer& values)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *impl = values;

    return *this;
}

CoreTools::SimpleCSV::RowDataProxy& CoreTools::SimpleCSV::RowDataProxy::operator=(const BoolContainer& values)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    *impl = values;

    return *this;
}

CoreTools::SimpleCSV::RowDataProxy::CellValueContainer CoreTools::SimpleCSV::RowDataProxy::GetValues() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValues();
}

CoreTools::SimpleCSV::RowDataProxy::SharedStringsSharedPtr CoreTools::SimpleCSV::RowDataProxy::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetSharedStrings();
}

void CoreTools::SimpleCSV::RowDataProxy::DeleteCellValues(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->DeleteCellValues(count);
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowDataProxy::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRowNode();
}

void CoreTools::SimpleCSV::RowDataProxy::Clear()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Clear();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::RowDataProxy::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetDocument();
}

void CoreTools::SimpleCSV::RowDataProxy::PrependCellValue(const CellValue& value, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->PrependCellValue(value, column);
}

CoreTools::SimpleCSV::RowDataProxy::operator CellValueContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetValues();
}

CoreTools::SimpleCSV::RowDataProxy::operator std::deque<CoreTools::SimpleCSV::CellValue>() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ConvertContainer<std::deque<CellValue>>();
}

CoreTools::SimpleCSV::RowDataProxy::operator std::list<CoreTools::SimpleCSV::CellValue>() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return ConvertContainer<std::list<CellValue>>();
}
