///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/07 20:07)

#include "CoreTools/CoreToolsExport.h"

#include "CellValue.h"
#include "CellValueProxyDetail.h"
#include "Detail/CellValueProxyImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::SimpleCSV::CellValueProxy CoreTools::SimpleCSV::CellValueProxy::CreateEmpty()
{
    return CellValueProxy{ CellValueProxyCreate::Init };
}

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, CellValueProxy)

CoreTools::SimpleCSV::CellValueProxy::CellValueProxy(MAYBE_UNUSED CellValueProxyCreate cellValueProxyCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
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
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, GetTypeAsString, string)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetInteger, int64_t, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetBoolean, bool, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, CellValueProxy, SetFloat, double, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, CellValueProxy, SetString, string, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, CellValueProxy, GetValue, CoreTools::SimpleCSV::CellValue)
