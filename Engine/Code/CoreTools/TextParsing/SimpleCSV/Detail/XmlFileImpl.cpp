///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "XmlFileImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlData.h"

using std::string;

/// ���캯���Ը�XLDocument���ļ�·����Ϊ���봴��һ���¶���
/// ��ѡ�����Ǵ���XML���ݵ�std::string��
/// ��� XML �������ַ����ṩ�����ڱ����ĵ�ʱ������.zip �ļ��о�����ͬ·�����κ��ļ���
/// ���δ�ṩxmlData����ʹ�ø���·����.zip �ļ��ж�ȡ���ݡ�
CoreTools::SimpleCSV::XmlFileImpl::XmlFileImpl(const XmlDataSharedPtr& xmlData) noexcept
    : xmlData{ xmlData }, document{ xmlData->GetParentDocument() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlFileImpl)

/// �˷���ʹ��std::string��Ϊ��������XML���ݣ��ײ�XMLDocument��ȡ���ݡ�
/// ��PugiXML�е���load_string����ʱ����־ 'parse_ws_pcdata' ��Ĭ�ϱ�־һ�𴫵ݡ� �⽫���ÿհ��ַ��Ľ�����
/// ��������ã�ֻ�пո��Excel��Ԫ����Ϊ���ַ������أ��ⲻ��������Ҫ�ġ�
/// ȱ��������xml�ļ��е�\\n ��\\t�ȿհ��ַ����ܻ����ҽ�����
void CoreTools::SimpleCSV::XmlFileImpl::SetXmlData(const string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    GetXmlDataSharedPtr()->SetRawData(data);
}

// �˷������ײ�XML������Ϊstd::string������
string CoreTools::SimpleCSV::XmlFileImpl::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDataSharedPtr()->GetRawData();
}

string CoreTools::SimpleCSV::XmlFileImpl::GetRelationshipID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDataSharedPtr()->GetXmlID();
}

CoreTools::SimpleCSV::XmlFileImpl::DocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetParentDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<Document>(static_cast<const ClassType*>(this)->GetParentDocument());

#include STSTEM_WARNING_POP
}

CoreTools::SimpleCSV::XmlFileImpl::ConstDocumentSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetParentDocument() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto documentSharedPtr = document.lock();
    if (documentSharedPtr == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document�ѱ��ͷš�"s));
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<XmlData>(static_cast<const ClassType*>(this)->GetXmlDataSharedPtr());

#include STSTEM_WARNING_POP
}

CoreTools::SimpleCSV::XmlFileImpl::ConstXmlDataSharedPtr CoreTools::SimpleCSV::XmlFileImpl::GetXmlDataSharedPtr() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDataSharedPtr = xmlData.lock();
    if (xmlDataSharedPtr == nullptr)
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("xmlData�ѱ��ͷš�"s));
    }

    return xmlDataSharedPtr;
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFileImpl::GetSheetData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->first_child().child(TextParsing::g_SheetData.data());
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFileImpl::GetFirstChildColumns() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument()->first_child().child(TextParsing::g_Columns.data());
}