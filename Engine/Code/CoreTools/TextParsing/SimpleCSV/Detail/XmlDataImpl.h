///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:38)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_HIDDEN_DECLARE XmlDataImpl final
        {
        public:
            using ClassType = XmlDataImpl;
            using DocumentSharedPtr = std::shared_ptr<Document>;
            using DocumentWeakPtr = std::weak_ptr<Document>;

        public:
            XmlDataImpl() = delete;

            XmlDataImpl(const DocumentSharedPtr& parentDocument,
                        const std::string& xmlPath,
                        const std::string& xmlID,
                        ContentType xmlType);

            ~XmlDataImpl() noexcept = default;
            XmlDataImpl(const XmlDataImpl& rhs) = delete;
            XmlDataImpl& operator=(const XmlDataImpl& rhs) = delete;
            XmlDataImpl(XmlDataImpl&& rhs) noexcept;
            XmlDataImpl& operator=(XmlDataImpl&& rhs) noexcept;

            CLASS_INVARIANT_DECLARE;

            void SetRawData(const std::string& data);
            NODISCARD std::string GetRawData() const;

            NODISCARD DocumentWeakPtr GetParentDocument() noexcept;

            NODISCARD std::string GetXmlPath() const;
            NODISCARD std::string GetXmlID() const;
            NODISCARD ContentType GetXmlType() const noexcept;

            NODISCARD XMLDocumentSharedPtr GetXmlDocument() noexcept;
            NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const noexcept;

        private:
            static constexpr auto loadFlags = pugi::parse_default | pugi::parse_ws_pcdata;

        private:
            DocumentWeakPtr parentDocument;  // ָ��Document�����ָ�롣
            std::string xmlPath;  // .xlsx zip �浵��XML���ݵ�·����
            std::string xmlID;  // XML���ݵĹ�ϵID��
            ContentType xmlType;  // XML���ݱ�ʾ�����͡�
            XMLDocumentSharedPtr xmlDocument;  // �ײ� XMLDocument ����
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H
