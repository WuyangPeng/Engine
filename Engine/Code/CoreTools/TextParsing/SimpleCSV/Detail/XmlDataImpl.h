/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 17:46)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools::SimpleCSV
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
                    std::string xmlId,
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
        NODISCARD std::string GetXmlId() const;
        NODISCARD ContentType GetXmlType() const noexcept;

        NODISCARD XMLDocumentSharedPtr GetXmlDocument() noexcept;
        NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const noexcept;

    private:
        static constexpr auto loadFlags = pugi::parse_default | pugi::parse_ws_pcdata;

    private:
        /// 指向父Document对象的指针。
        DocumentWeakPtr parentDocument;

        /// .xlsx zip 存档中XML数据的路径。
        std::string xmlPath;

        /// XML数据的关系ID。
        std::string xmlId;

        /// XML数据表示的类型。
        ContentType xmlType;

        /// 底层 XMLDocument 对象
        XMLDocumentSharedPtr xmlDocument;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_DATA_IMPL_H
