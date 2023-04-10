///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:18)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_FILE_H
#define CORE_TOOLS_TEXT_PARSING_XML_FILE_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::XmlFileImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::CopyUnsharedImpl<CoreTools::SimpleCSV::XmlFile, CoreTools::SimpleCSV::XmlFileImpl>;

namespace CoreTools::SimpleCSV
{
    /// XmlFile类提供了一个供派生类使用的接口。
    /// 它充当所有类的基类，这些类由.xlsx 包中的.xml 文件表示。
    class CORE_TOOLS_DEFAULT_DECLARE XmlFile
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(XmlFile);
        using XmlDataSharedPtr = std::shared_ptr<XmlData>;
        using DocumentSharedPtr = std::shared_ptr<Document>;
        using ConstDocumentSharedPtr = std::shared_ptr<const Document>;

    public:
        XmlFile() noexcept = delete;
        explicit XmlFile(const XmlDataSharedPtr& xmlData);
        virtual ~XmlFile() noexcept = default;
        XmlFile(const XmlFile& rhs) = default;
        XmlFile& operator=(const XmlFile& rhs) = default;
        XmlFile(XmlFile&& rhs) noexcept = default;
        XmlFile& operator=(XmlFile&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        // 获取对象所表示的XML数据的方法。
        NODISCARD std::string GetXmlData() const;

        // 提供对象表示的XML数据。
        void SetXmlData(const std::string& data);

        // 此函数返回对象的关系ID（Relationships对象中使用的ID）。
        NODISCARD std::string GetRelationshipId() const;

        NODISCARD DocumentSharedPtr GetParentDocument();
        NODISCARD ConstDocumentSharedPtr GetParentDocument() const;
        NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const;
        NODISCARD XMLDocumentSharedPtr GetXmlDocument();

        NODISCARD XMLNode GetSheetData() const;
        NODISCARD XMLNode GetFirstChildColumns() const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_FILE_H
