///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/29 23:03)

#include "CoreTools/CoreToolsExport.h"

#include "QueryXmlDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;

CoreTools::SimpleCSV::QueryXmlDataImpl::QueryXmlDataImpl(const string& xmlPath)
    : xmlPath{ xmlPath }, m_XmlData{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QueryXmlDataImpl::QueryXmlDataImpl(const string& xmlPath, const XmlDataSharedPtr& xmlData)
    : xmlPath{ xmlPath }, m_XmlData{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QueryXmlDataImpl)

string CoreTools::SimpleCSV::QueryXmlDataImpl::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return xmlPath;
}

CoreTools::SimpleCSV::QueryXmlDataImpl::XmlDataSharedPtr CoreTools::SimpleCSV::QueryXmlDataImpl::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlData = m_XmlData.lock();
    if (!xmlData)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("指针已释放！"s));
    }
    else
    {
        return xmlData;
    }
}

void CoreTools::SimpleCSV::QueryXmlDataImpl::SetXmlData(const XmlDataSharedPtr& xmlData) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_XmlData = xmlData;
}
