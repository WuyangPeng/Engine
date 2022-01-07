///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItem.h"
#include "Detail/RelationshipItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::SimpleCSV::RelationshipItem::RelationshipItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& node)
    : impl{ document, node }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RelationshipItem)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetType, CoreTools::SimpleCSV::RelationshipType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetTarget, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetID, string)

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItem::GetTypeFromString(const string& typeString)
{
    return ImplType::GetTypeFromString(typeString);
}

string CoreTools::SimpleCSV::RelationshipItem::GetStringFromType(RelationshipType type)
{
    return ImplType::GetStringFromType(type);
}
