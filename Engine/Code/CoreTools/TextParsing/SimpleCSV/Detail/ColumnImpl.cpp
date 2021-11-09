///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/09 16:39)

#include "CoreTools/CoreToolsExport.h"

#include "ColumnImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::ColumnImpl::ColumnImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& columnNode) noexcept
    : document{ document }, columnNode{ columnNode }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, ColumnImpl);

float CoreTools::SimpleCSV::ColumnImpl::GetWidth() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetColumnNode().attribute("width").as_float();
}

void CoreTools::SimpleCSV::ColumnImpl::SetWidth(float width)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetColumnNode();

    auto widthAtt = node.attribute("width");
    if (!widthAtt)
    {
        widthAtt = node.append_attribute("width");
    }

    widthAtt.set_value(width);

    auto customAtt = node.attribute("customWidth");
    if (!customAtt)
    {
        customAtt = node.append_attribute("customWidth");
    }

    customAtt.set_value("1");
}

bool CoreTools::SimpleCSV::ColumnImpl::IsHidden() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetColumnNode().attribute("hidden").as_bool();
}

void CoreTools::SimpleCSV::ColumnImpl::SetHidden(bool state)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto node = GetColumnNode();

    auto hiddenAtt = node.attribute("hidden");
    if (!hiddenAtt)
    {
        hiddenAtt = node.append_attribute("hidden");
    }

    if (state)
    {
        hiddenAtt.set_value("1");
    }
    else
    {
        hiddenAtt.set_value("0");
    }
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::ColumnImpl::GetColumnNode() const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return columnNode;
}
