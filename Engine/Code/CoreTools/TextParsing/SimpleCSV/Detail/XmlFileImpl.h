///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:39)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    namespace SimpleCSV
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
            NODISCARD std::string GetRelationshipID() const;

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
            // 底层XML数据对象
            XmlDataWeakPtr xmlData;
            DocumentWeakPtr document;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_FILE_IMPL_H
