/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:03)

#include "CoreTools/CoreToolsExport.h"

#include "CellValueProxyImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Cell.h"
#include "CoreTools/TextParsing/SimpleCSV/CellValue.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ValueTypeFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

CoreTools::SimpleCSV::CellValueProxyImpl::CellValueProxyImpl() noexcept
    : cell{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::SimpleCSV::CellValueProxyImpl::CellValueProxyImpl(const CellSharedPtr& cell) noexcept
    : cell{ cell }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, CellValueProxyImpl)

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellValueProxyImpl::GetXMLNode() const
{
    const auto cellSharedPtr = cell.lock();

    if (!cellSharedPtr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("cell已被释放。"s))
    }

    const auto cellNode = cellSharedPtr->GetXMLNode();

    if (cellNode.empty())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("cellNode无效！"s))
    }

    return cellNode;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellValueProxyImpl::AppendAttributeT()
{
    auto cellNode = GetXMLNode();

    if (!cellNode.attribute("t"))
    {
        cellNode.append_attribute("t");
    }

    return cellNode;
}

void CoreTools::SimpleCSV::CellValueProxyImpl::Clear()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto cellNode = GetXMLNode();

    cellNode.remove_attribute("t");
    cellNode.remove_attribute(" xml:space");
    cellNode.remove_child("v");
}

void CoreTools::SimpleCSV::CellValueProxyImpl::SetError()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto cellNode = AppendAttributeT();

    cellNode.attribute("t").set_value("e");
    cellNode.remove_attribute(" xml:space");
    cellNode.remove_child("v");
}

std::string CoreTools::SimpleCSV::CellValueProxyImpl::GetAttributeValue() const
{
    const auto cellNode = GetXMLNode();

    const auto attribute = cellNode.attribute("t");

    if (const auto attributeValue = attribute.value();
        attributeValue != nullptr)
    {
        return attributeValue;
    }
    else
    {
        return std::string{};
    }
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueProxyImpl::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto cellNode = GetXMLNode();
    const auto node = cellNode.child("v");

    if (const auto attributeValue = GetAttributeValue();
        attributeValue.empty() && !node)
    {
        return ValueType::Empty;
    }
    else if (attributeValue.empty() || (attributeValue == "n" && node))
    {
        return GetNumberType(node);
    }
    else if (!attributeValue.empty())
    {
        return GetStringType(attributeValue);
    }

    return ValueType::Error;
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueProxyImpl::GetStringType(const std::string& attributeValue) noexcept
{
    if (attributeValue == "s")
    {
        return ValueType::String;
    }
    else if (attributeValue == "inlineStr")
    {
        return ValueType::String;
    }
    else if (attributeValue == "str")
    {
        return ValueType::String;
    }
    else if (attributeValue == "b")
    {
        return ValueType::Boolean;
    }
    else
    {
        return ValueType::Error;
    }
}

CoreTools::SimpleCSV::ValueType CoreTools::SimpleCSV::CellValueProxyImpl::GetNumberType(const XMLNode& node)
{
    if (const std::string numberString{ node.text().get() };
        numberString.find('.') != std::string::npos ||
        numberString.find("E-") != std::string::npos ||
        numberString.find("e-") != std::string::npos)
    {
        return ValueType::Float;
    }
    else
    {
        return ValueType::Integer;
    }
}

std::string CoreTools::SimpleCSV::CellValueProxyImpl::GetTypeAsString() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    switch (GetType())
    {
        case ValueType::Empty:
            return "empty";
        case ValueType::Boolean:
            return "boolean";
        case ValueType::Integer:
            return "integer";
        case ValueType::Float:
            return "float";
        case ValueType::String:
            return "string";
        default:
            return "error";
    }
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::CellValueProxyImpl::AppendChildV()
{
    auto cellNode = GetXMLNode();

    if (!cellNode.child("v"))
    {
        cellNode.append_child("v");
    }

    return cellNode;
}

void CoreTools::SimpleCSV::CellValueProxyImpl::SetInteger(int64_t numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto cellNode = AppendChildV();

    cellNode.remove_attribute("t");
    auto child = cellNode.child("v");
    child.text().set(numberValue);
    child.remove_attribute(child.attribute("xml:space"));
}

void CoreTools::SimpleCSV::CellValueProxyImpl::SetBoolean(bool numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto cellNode = AppendAttributeT();
    cellNode = AppendChildV();
    auto child = cellNode.child("v");

    cellNode.attribute("t").set_value("b");
    child.text().set(numberValue ? 1 : 0);
    child.remove_attribute(child.attribute("xml:space"));
}

void CoreTools::SimpleCSV::CellValueProxyImpl::SetFloat(double numberValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto cellNode = AppendChildV();
    auto child = cellNode.child("v");

    cellNode.remove_attribute("t");
    child.text().set(numberValue);
    child.remove_attribute(child.attribute("xml:space"));
}

void CoreTools::SimpleCSV::CellValueProxyImpl::SetString(const std::string& stringValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    std::ignore = AppendAttributeT();
    const auto cellNode = AppendChildV();

    cellNode.attribute("t").set_value("s");

    const auto cellSharedPtr = cell.lock();

    if (cellSharedPtr == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("cell已被释放。"s))
    }

    const auto sharedStrings = cellSharedPtr->GetSharedStrings();

    const auto index = (sharedStrings->IsStringExists(stringValue) ? sharedStrings->GetStringIndex(stringValue) : sharedStrings->AppendString(stringValue));

    cellNode.child("v").text().set(index);
}

CoreTools::SimpleCSV::CellValue CoreTools::SimpleCSV::CellValueProxyImpl::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto cellNode = GetXMLNode();

    switch (GetType())
    {
        case ValueType::Empty:
        {
            return CellValue::CreateDefault();
        }
        case ValueType::Float:
        {
            return CellValue{ cellNode.child("v").text().as_double() };
        }
        case ValueType::Integer:
        {
#ifdef TCRE_USE_GCC
            return CellValue{ static_cast<int64_t>(cellNode.child("v").text().as_llong()) };
#else  // !TCRE_USE_GCC
            return CellValue{ cellNode.child("v").text().as_llong() };
#endif  // TCRE_USE_GCC
        }
        case ValueType::String:
        {
            const auto cellSharedPtr = cell.lock();

            if (!cellSharedPtr)
            {
                THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("cell已被释放。"s))
            }

            if (const auto attributeValue = GetAttributeValue(); attributeValue == "s")
            {
                const auto sharedStrings = cellSharedPtr->GetSharedStrings();

                return CellValue{ sharedStrings->GetString(cellNode.child("v").text().as_int()) };
            }
            else if (attributeValue == "str")
            {
                return CellValue{ cellNode.child("v").text().get() };
            }
            else
            {
                THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, "未知的字符串类型。"s)
            }
        }
        case ValueType::Boolean:
        {
            return CellValue{ cellNode.child("v").text().as_bool() };
        }
        default:
        {
            return CellValue::CreateError();
        }
    }
}
