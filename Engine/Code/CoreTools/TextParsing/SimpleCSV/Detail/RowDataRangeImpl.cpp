///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataRangeImpl.h"
#include "Utilities.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowDataRangeImpl::RowDataRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& rowNode, int firstColumn, int lastColumn, const SharedStringsSharedPtr& sharedStrings)
    : document{ document },
      rowNode{ rowNode },
      firstColumn{ firstColumn },
      lastColumn{ lastColumn },
      sharedStrings{ sharedStrings }
{
    if (lastColumn < firstColumn)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, "lastColumnС��firstColumn��"s);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowDataRangeImpl);

CoreTools::SimpleCSV::RowDataRangeImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::RowDataRangeImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings�ѱ��ͷš�"s));
    }

    return sharedStringsSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowDataRangeImpl::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document�ѱ��ͷš�"s));
    }

    return rowNode;
}

int CoreTools::SimpleCSV::RowDataRangeImpl::GetFirstColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return firstColumn;
}

int CoreTools::SimpleCSV::RowDataRangeImpl::GetLastColumn() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lastColumn;
}

int CoreTools::SimpleCSV::RowDataRangeImpl::GetSize() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lastColumn - firstColumn + 1;
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::RowDataRangeImpl::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document�ѱ��ͷš�"s));
    }

    return documentSharedPtr;
}