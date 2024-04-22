/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 17:46)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_HIDDEN_DECLARE XmlFileImpl final
    {
    public:
        using ClassType = XmlFileImpl;

        using XmlDataSharedPtr = std::shared_ptr<XmlData>;
        using ConstXmlDataSharedPtr = std::shared_ptr<const XmlData>;
        using XmlDataWeakPtr = std::weak_ptr<XmlData>;
        using DocumentSharedPtr = std::shared_ptr<Document>;
        using ConstDocumentSharedPtr = std::shared_ptr<const Document>;

    public:
        XmlFileImpl() noexcept = delete;
        explicit XmlFileImpl(const XmlDataSharedPtr& xmlData) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetXmlData() const;
        void SetXmlData(const std::string& data);
        NODISCARD std::string GetRelationshipId() const;

        NODISCARD DocumentSharedPtr GetParentDocument();
        NODISCARD ConstDocumentSharedPtr GetParentDocument() const;
        NODISCARD XMLDocumentSharedPtr GetXmlDocument();
        NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const;

        NODISCARD XMLNode GetSheetData() const;
        NODISCARD XMLNode GetFirstChildColumns() const;

    private:
        using DocumentWeakPtr = std::weak_ptr<Document>;

    private:
        NODISCARD XmlDataSharedPtr GetXmlDataSharedPtr();
        NODISCARD ConstXmlDataSharedPtr GetXmlDataSharedPtr() const;

    private:
        /// �ײ�XML���ݶ���
        XmlDataWeakPtr xmlData;
        DocumentWeakPtr document;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H
