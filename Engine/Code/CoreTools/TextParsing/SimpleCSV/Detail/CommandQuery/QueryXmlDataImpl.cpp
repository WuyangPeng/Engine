///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/06 16:34)

#include "CoreTools/CoreToolsExport.h"

#include "QueryXmlDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::QueryXmlDataImpl::QueryXmlDataImpl(std::string xmlPath) noexcept
    : xmlPath{ xmlPath }, xmlData{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::QueryXmlDataImpl::QueryXmlDataImpl(std::string xmlPath, const XmlDataSharedPtr& xmlData) noexcept
    : xmlPath{ xmlPath }, xmlData{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QueryXmlDataImpl)

std::string CoreTools::SimpleCSV::QueryXmlDataImpl::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return xmlPath;
}

CoreTools::SimpleCSV::QueryXmlDataImpl::XmlDataSharedPtr CoreTools::SimpleCSV::QueryXmlDataImpl::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (auto xmlDataSharedPtr = xmlData.lock(); xmlDataSharedPtr != nullptr)
    {
        return xmlDataSharedPtr;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("ָ�����ͷţ�"s))
    }
}

void CoreTools::SimpleCSV::QueryXmlDataImpl::SetXmlData(const XmlDataSharedPtr& aXmlData) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    xmlData = aXmlData;
}
