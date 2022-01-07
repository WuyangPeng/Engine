///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:26)

#include "CoreTools/CoreToolsExport.h"

#include "ContentItem.h"
#include "Detail/ContentItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::SimpleCSV::ContentItem::ContentItem(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode)
    : impl{ document, columnNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, ContentItem)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, ContentItem, GetType, CoreTools::SimpleCSV::ContentType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools::SimpleCSV, ContentItem, GetPath, string)

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItem::GetTypeFromString(const string& typeString)
{
    return ImplType::GetTypeFromString(typeString);
}

string CoreTools::SimpleCSV::ContentItem::GetStringFromType(ContentType type)
{
    return ImplType::GetStringFromType(type);
}
