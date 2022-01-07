///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "RowRangeImpl.h"
#include "Utilities.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellRange.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/IteratorFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::RowRangeImpl::RowRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, int first, int last, const SharedStringsSharedPtr& sharedStrings) noexcept
    : document{ document },
      dataNode{ dataNode },
      firstRow{ first },
      lastRow{ last },
      sharedStrings{ sharedStrings }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RowRangeImpl);

int CoreTools::SimpleCSV::RowRangeImpl::GetRowCount() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lastRow - firstRow + 1;
}

int CoreTools::SimpleCSV::RowRangeImpl::GetFirstRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return firstRow;
}

int CoreTools::SimpleCSV::RowRangeImpl::GetLastRow() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return lastRow;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowRangeImpl::GetDataNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return dataNode;
}

CoreTools::SimpleCSV::RowRangeImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::RowRangeImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings已被释放。"s));
    }

    return sharedStringsSharedPtr;
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::RowRangeImpl::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return documentSharedPtr;
}
