///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:21)

#include "CoreTools/CoreToolsExport.h"

#include "CellRangeImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::CellRangeImpl::CellRangeImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& dataNode, const CellReference& topLeft, const CellReference& bottomRight, const SharedStringsSharedPtr& sharedStrings)
    : document{ document },
      dataNode{ dataNode },
      topLeft{ topLeft },
      bottomRight{ bottomRight },
      sharedStrings{ sharedStrings }
{
    if (bottomRight < topLeft)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("cell 范围无效。"s));
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellRangeImpl);

int CoreTools::SimpleCSV::CellRangeImpl::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return bottomRight.GetRow() + 1 - topLeft.GetRow();
}

int CoreTools::SimpleCSV::CellRangeImpl::GetNumColumns() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return bottomRight.GetColumn() + 1 - topLeft.GetColumn();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::CellRangeImpl::GetDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto documentSharedPtr = document.lock();

    if (!documentSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return documentSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellRangeImpl::GetDataNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return dataNode;
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellRangeImpl::GetTopLeft() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return topLeft;
}

CoreTools::SimpleCSV::CellReference CoreTools::SimpleCSV::CellRangeImpl::GetBottomRight() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return bottomRight;
}

CoreTools::SimpleCSV::CellRangeImpl::SharedStringsSharedPtr CoreTools::SimpleCSV::CellRangeImpl::GetSharedStrings()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto sharedStringsSharedPtr = sharedStrings.lock();

    if (!sharedStringsSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("sharedStrings已被释放。"s));
    }

    return sharedStringsSharedPtr;
}
