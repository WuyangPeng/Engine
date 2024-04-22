/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 10:59)

#include "CoreTools/CoreToolsExport.h"

#include "QueryXmlData.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Detail/CommandQuery/QueryXmlDataImpl.h"

CoreTools::SimpleCSV::QueryXmlData::QueryXmlData(const std::string& xmlPath)
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

std::string CoreTools::SimpleCSV::QueryXmlData::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlPath();
}

CoreTools::SimpleCSV::QueryXmlData::XmlDataSharedPtr CoreTools::SimpleCSV::QueryXmlData::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlData();
}
