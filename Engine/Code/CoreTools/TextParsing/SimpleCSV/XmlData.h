///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 15:01)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_DATA_H
#define CORE_TOOLS_TEXT_PARSING_XML_DATA_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "Flags/ContentFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::XmlDataImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::NonCopyImpl<CoreTools::SimpleCSV::XmlDataImpl>;

namespace CoreTools::SimpleCSV
{
    /// XmlData类将.xml文件的属性和行为封装在.xlsx 文件zip包中。
    /// XmlData类型的对象旨在集中存储在Document对象中，其他封装Excel元素行为的对象（例如 Workbook 和 Worksheet）可以从中检索它们。
    class CORE_TOOLS_DEFAULT_DECLARE XmlData final
    {
    public:
        NON_COPY_TYPE_DECLARE(XmlData);

        using DocumentSharedPtr = std::shared_ptr<Document>;
        using DocumentWeakPtr = std::weak_ptr<Document>;

    public:
        /// 此构造函数创建具有给定参数的对象。 xmlId 和 xmlType 参数具有默认值。
        /// 这些仅对关系 (.rels)文件和位于zip包根目录中的[Content_Types].xml文件有用。
        XmlData(const DocumentSharedPtr& parentDocument,
                const std::string& xmlPath,
                const std::string& xmlId = std::string{},
                ContentType xmlType = ContentType::Unknown);

        CLASS_INVARIANT_DECLARE;

        /// 设置底层XML文档的原始数据。在使用XML文件模板创建新文件时，能够直接设置XML数据非常有用。
        /// 例如，在创建新工作表时，可以使用此函数添加最小行Worksheet对象的XML代码。
        void SetRawData(const std::string& data);

        /// 获取底层XML文档的原始数据。此函数将从底层XMLDocument对象中检索原始XML文本数据。
        /// 这将主要用于使用Document类中的Save函数将数据保存到.xlsx 包时。
        NODISCARD std::string GetRawData() const;

        /// 检索.xlsx zip存档中XML数据的路径。
        NODISCARD std::string GetXmlPath() const;

        /// 检索XML文件的关系ID。
        NODISCARD std::string GetXmlId() const;

        /// 检索XML数据表示的类型。
        NODISCARD ContentType GetXmlType() const noexcept;

        /// 访问基础XMLDocument对象。
        NODISCARD XMLDocumentSharedPtr GetXmlDocument() noexcept;
        NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const noexcept;

        NODISCARD DocumentWeakPtr GetParentDocument() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_DATA_H
