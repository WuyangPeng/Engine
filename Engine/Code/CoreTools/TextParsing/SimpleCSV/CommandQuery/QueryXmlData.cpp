///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:17)

#include "CoreTools/CoreToolsExport.h"

#include "QueryXmlData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QueryXmlDataImpl.h"

using std::string;

CoreTools::SimpleCSV::QueryXmlData::QueryXmlData(const string& xmlPath)
    : impl{ xmlPath }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QueryXmlData::QueryXmlData(const std::string& xmlPath, const XmlDataSharedPtr& xmlData)
    : impl{ xmlPath, xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QueryXmlData)

string CoreTools::SimpleCSV::QueryXmlData::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlPath();
}

CoreTools::SimpleCSV::QueryXmlData::XmlDataSharedPtr CoreTools::SimpleCSV::QueryXmlData::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlData();
}
