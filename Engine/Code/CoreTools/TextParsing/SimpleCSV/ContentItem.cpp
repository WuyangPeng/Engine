/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:27)

#include "CoreTools/CoreToolsExport.h"

#include "ContentItem.h"
#include "Detail/ContentItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::ContentItem::ContentItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode)
    : impl{ document, columnNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, ContentItem)

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItem::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

std::string CoreTools::SimpleCSV::ContentItem::GetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetPath();
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItem::GetTypeFromString(const std::string& typeString)
{
    return ImplType::GetTypeFromString(typeString);
}

std::string CoreTools::SimpleCSV::ContentItem::GetStringFromType(ContentType type)
{
    return ImplType::GetStringFromType(type);
}
