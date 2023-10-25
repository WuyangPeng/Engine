///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 18:04)

#include "CoreTools/CoreToolsExport.h"

#include "CellValue.h"
#include "CellValueProxyDetail.h"
#include "Detail/CellValueProxyImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

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

void CoreTools::SimpleCSV::CellValueProxy::Clear()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Clear();
}

void CoreTools::SimpleCSV::CellValueProxy::SetError()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetError();
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueProxy::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

std::string CoreTools::SimpleCSV::CellValueProxy::GetTypeAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetTypeAsString();
}

void CoreTools::SimpleCSV::CellValueProxy::SetInteger(int64_t numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetInteger(numberValue);
}

void CoreTools::SimpleCSV::CellValueProxy::SetBoolean(bool numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetBoolean(numberValue);
}

void CoreTools::SimpleCSV::CellValueProxy::SetFloat(double numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetFloat(numberValue);
}

void CoreTools::SimpleCSV::CellValueProxy::SetString(const std::string& stringValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetString(stringValue);
}

CoreTools::SimpleCSV::CellValue CoreTools::SimpleCSV::CellValueProxy::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetValue();
}

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
