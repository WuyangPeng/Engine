///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:08)

#include "CoreTools/CoreToolsExport.h"

#include "CellValue.h"
#include "CellValueProxyDetail.h"
#include "Detail/CellValueProxyImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::CellValueProxy CoreTools::SimpleCSV::CellValueProxy::CreateEmpty()
{
    return CellValueProxy{ CellValueProxyCreate::Init };
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellValueProxy)

CoreTools::SimpleCSV::CellValueProxy::CellValueProxy(CellValueProxyCreate cellValueProxyCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(cellValueProxyCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueProxy::CellValueProxy(const CellSharedPtr& cell)
    : impl{ cell }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellValueProxy)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, Clear, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, SetError, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, GetType, CoreTools::SimpleCSV::ValueType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, GetTypeAsString, std::string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetInteger, int64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetBoolean, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetFloat, double, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, CellValueProxy, SetString, std::string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, GetValue, CoreTools::SimpleCSV::CellValue)

void CoreTools::SimpleCSV::CellValueProxy::SetCellValue(const CellValue& cellValue)
{
    switch (cellValue.GetType())
    {
        case ValueType::Boolean:
        {
            SetBoolean(cellValue.template Get<bool>());
            break;
        }
        case ValueType::Integer:
        {
            SetInteger(cellValue.template Get<int64_t>());
            break;
        }
        case ValueType::Float:
        {
            SetFloat(cellValue.template Get<double>());
            break;
        }
        case ValueType::String:
        {
            SetString(cellValue.template Get<std::string>());
            break;
        }
        default:
        {
            break;
        }
    }
}
