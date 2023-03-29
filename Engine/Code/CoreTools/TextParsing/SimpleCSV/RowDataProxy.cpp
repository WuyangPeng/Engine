///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/08 13:54)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataProxyDetail.h"
#include "Detail/RowDataProxyImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataProxy, GetValues, CoreTools::SimpleCSV::RowDataProxy::CellValueContainer)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataProxy, GetSharedStrings, CoreTools::SimpleCSV::RowDataProxy::SharedStringsSharedPtr)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, RowDataProxy, DeleteCellValues, int, void)

void CoreTools::SimpleCSV::RowDataProxy::PrependCellValue(const CellValue& value, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->PrependCellValue(value, column);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataProxy, GetRowNode, CoreTools::SimpleCSV::XMLNode)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataProxy, Clear, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RowDataProxy, GetDocument, CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr)

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
