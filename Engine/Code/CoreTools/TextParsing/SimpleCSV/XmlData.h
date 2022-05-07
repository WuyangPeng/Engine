///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:54)

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

namespace CoreTools
{
    namespace SimpleCSV
    {
        /// XmlData�ཫ.xml�ļ������Ժ���Ϊ��װ��.xlsx �ļ�zip���С�
        /// XmlData���͵Ķ���ּ�ڼ��д洢��Document�����У�������װExcelԪ����Ϊ�Ķ������� Workbook �� Worksheet�����Դ��м������ǡ�
        class CORE_TOOLS_DEFAULT_DECLARE XmlData final
        {
        public:
            NON_COPY_TYPE_DECLARE(XmlData);
            using DocumentSharedPtr = std::shared_ptr<Document>;
            using DocumentWeakPtr = std::weak_ptr<Document>;

        public:
            /// �˹��캯���������и��������Ķ��� xmlID �� xmlType ��������Ĭ��ֵ��
            /// ��Щ���Թ�ϵ (.rels)�ļ���λ��zip����Ŀ¼�е�[Content_Types].xml�ļ����á�
            XmlData(const DocumentSharedPtr& parentDocument,
                    const std::string& xmlPath,
                    const std::string& xmlID = std::string{},
                    ContentType xmlType = ContentType::Unknown);

            CLASS_INVARIANT_DECLARE;

            /// ���õײ�XML�ĵ���ԭʼ���ݡ���ʹ��XML�ļ�ģ�崴�����ļ�ʱ���ܹ�ֱ������XML���ݷǳ����á�
            /// ���磬�ڴ����¹�����ʱ������ʹ�ô˺���������С��Worksheet�����XML���롣
            void SetRawData(const std::string& data);

            /// ��ȡ�ײ�XML�ĵ���ԭʼ���ݡ��˺������ӵײ�XMLDocument�����м���ԭʼXML�ı����ݡ�
            /// �⽫��Ҫ����ʹ��Document���е�Save���������ݱ��浽.xlsx ��ʱ��
            NODISCARD std::string GetRawData() const;

            /// ����.xlsx zip�浵��XML���ݵ�·����
            NODISCARD std::string GetXmlPath() const;

            /// ����XML�ļ��Ĺ�ϵID��
            NODISCARD std::string GetXmlID() const;

            /// ����XML���ݱ�ʾ�����͡�
            NODISCARD ContentType GetXmlType() const noexcept;

            /// ���ʻ���XMLDocument����
            NODISCARD XMLDocumentSharedPtr GetXmlDocument() noexcept;
            NODISCARD ConstXMLDocumentSharedPtr GetXmlDocument() const noexcept;

            NODISCARD DocumentWeakPtr GetParentDocument() noexcept;

        private:
            PackageType impl;
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_DATA_H