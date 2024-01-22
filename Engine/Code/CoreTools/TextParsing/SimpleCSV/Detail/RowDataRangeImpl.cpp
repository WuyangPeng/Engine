/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:04)

#include "CoreTools/CoreToolsExport.h"

#include "RowDataRangeImpl.h"
#include "Utilities.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
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
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Overflow, "lastColumn小于firstColumn。"s)
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
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings已被释放。"s))
    }

    return sharedStringsSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::RowDataRangeImpl::GetRowNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
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
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
    }

    return documentSharedPtr;
}
