///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:32)

#include "CoreTools/CoreToolsExport.h"

#include "XmlFileImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"

/// 构造函数以父XLDocument和文件路径作为输入创建一个新对象，
/// 可选输入是带有XML数据的std::string。
/// 如果 XML 数据由字符串提供，则在保存文档时将覆盖.zip 文件中具有相同路径的任何文件。
/// 如果未提供xmlData，则将使用给定路径从.zip 文件中读取数据。
CoreTools::SimpleCSV::XmlFileImpl::XmlFileImpl(const XmlDataSharedPtr& xmlData) noexcept
    : xmlData{ xmlData }, document{ xmlData->GetParentDocument() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlFileImpl)

/// 此方法使用std::string作为输入设置XML数据，底层XMLDocument读取数据。
/// 在PugiXML中调用load_string方法时，标志 'parse_ws_pcdata' 与默认标志一起传递。 这将启用空白字符的解析。
/// 如果不设置，只有空格的Excel单元格将作为空字符串返回，这不是我们想要的。
/// 缺点是输入xml文件中的\\n 和\\t等空白字符可能会扰乱解析。
void CoreTools::SimpleCSV::XmlFileImpl::SetXmlData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    GetXmlDataSharedPtr()->SetRawData(data);
}

// 此方法将底层XML数据作为std::string检索。
std::string CoreTools::SimpleCSV::XmlFileImpl::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDataSharedPtr()->GetRawData();
}

std::string CoreTools::SimpleCSV::XmlFileImpl::GetRelationshipId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDataSharedPtr()->GetXmlId();
}

CoreTools::SimpleCSV::XmlFileImpl::DocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetParentDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<Document>(static_cast<const ClassType*>(this)->GetParentDocument());

#include SYSTEM_WARNING_POP
}

CoreTools::SimpleCSV::XmlFileImpl::ConstDocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetParentDocument() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = document.lock();
    if (documentSharedPtr == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s))
    }

    return documentSharedPtr;
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetXmlDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDataSharedPtr()->GetXmlDocument();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetXmlDocument() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDataSharedPtr()->GetXmlDocument();
}

CoreTools::SimpleCSV::XmlFileImpl::XmlDataSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetXmlDataSharedPtr()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<XmlData>(static_cast<const ClassType*>(this)->GetXmlDataSharedPtr());

#include SYSTEM_WARNING_POP
}

CoreTools::SimpleCSV::XmlFileImpl::ConstXmlDataSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetXmlDataSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDataSharedPtr = xmlData.lock();
    if (xmlDataSharedPtr == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("xmlData已被释放。"s))
    }

    return xmlDataSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFileImpl::GetSheetData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->first_child().child(TextParsing::gSheetData.data());
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFileImpl::GetFirstChildColumns() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->first_child().child(TextParsing::gColumns.data());
}
