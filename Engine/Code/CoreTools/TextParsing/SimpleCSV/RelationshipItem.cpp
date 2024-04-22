/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 11:27)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItem.h"
#include "Detail/RelationshipItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SimpleCSV::RelationshipItem::RelationshipItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& node)
    : impl{ document, node }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RelationshipItem)

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItem::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

std::string CoreTools::SimpleCSV::RelationshipItem::GetTarget() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetTarget();
}

std::string CoreTools::SimpleCSV::RelationshipItem::GetId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetId();
}

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItem::GetTypeFromString(const std::string& typeString)
{
    return ImplType::GetTypeFromString(typeString);
}

std::string CoreTools::SimpleCSV::RelationshipItem::GetStringFromType(RelationshipType type)
{
    return ImplType::GetStringFromType(type);
}
