///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 21:18)

#include "CoreTools/CoreToolsExport.h"

#include "QuerySharedStringsImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;

CoreTools::SimpleCSV::QuerySharedStringsImpl::QuerySharedStringsImpl(const SharedStringsSharedPtr& sharedStrings) noexcept
    : m_SharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, QuerySharedStringsImpl)

CoreTools::SimpleCSV::QuerySharedStringsImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::QuerySharedStringsImpl::GetSharedStrings() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto sharedStringsSharedPtr = m_SharedStrings.lock();
    if (sharedStringsSharedPtr)
    {
        return sharedStringsSharedPtr;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("ָ�����ͷţ�"s));
    }
}

void CoreTools::SimpleCSV::QuerySharedStringsImpl::SetSharedStrings(const SharedStringsSharedPtr& sharedStrings) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_SharedStrings = sharedStrings;
}
