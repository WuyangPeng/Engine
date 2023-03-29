///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/08 11:45)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItem.h"
#include "Detail/RelationshipItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::RelationshipItem::RelationshipItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& node)
    : impl{ document, node }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RelationshipItem)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetType, CoreTools::SimpleCSV::RelationshipType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetTarget, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, RelationshipItem, GetId, std::string)

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItem::GetTypeFromString(const std::string& typeString)
{
    return ImplType::GetTypeFromString(typeString);
}

std::string CoreTools::SimpleCSV::RelationshipItem::GetStringFromType(RelationshipType type)
{
    return ImplType::GetStringFromType(type);
}
