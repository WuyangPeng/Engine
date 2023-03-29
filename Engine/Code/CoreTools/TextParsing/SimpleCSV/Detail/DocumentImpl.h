///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/07 13:49)

#ifndef CORE_TOOLS_TEXT_PARSING_DOCUMENT_IMPL_H
#define CORE_TOOLS_TEXT_PARSING_DOCUMENT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySharedStrings.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetIndex.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsId.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetRelsTarget.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetType.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QuerySheetVisibility.h"
#include "CoreTools/TextParsing/SimpleCSV/CommandQuery/QueryXmlData.h"
#include "CoreTools/TextParsing/SimpleCSV/Workbook.h"
#include "CoreTools/TextParsing/SimpleZip/ZipArchive.h"

#include <memory>
#include <string>

namespace CoreTools::SimpleCSV
{
    class DocumentImpl final
    {
    public:
        using ClassType = DocumentImpl;
        using DocumentSharedPtr = std::shared_ptr<Document>;

    public:
        explicit DocumentImpl(std::string docPath);

        void Open(const DocumentSharedPtr& document);
        void Create(const DocumentSharedPtr& document);

        ~DocumentImpl() noexcept = default;
        DocumentImpl(const DocumentImpl& rhs) = delete;
        DocumentImpl& operator=(const DocumentImpl& rhs) = delete;
        DocumentImpl(DocumentImpl&& rhs) noexcept;
        DocumentImpl& operator=(DocumentImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Save();
        void SaveAs(const std::string& fileName);
        NODISCARD std::string GetName() const;
        NODISCARD Workbook GetWorkbook() const;
        void ResetCalcChain();
        NODISCARD std::string GetProperty(Property prop) const;
        void SetProperty(Property prop, const std::string& value);

        void DeleteProperty(Property aProperty);

        void ExecuteCommand(const CommandSetSheetName& command);
        void ExecuteCommand(const CommandSetSheetVisibility& command) noexcept;
        void ExecuteCommand(const CommandSetSheetColor& command) noexcept;
        void ExecuteCommand(const CommandSetSheetIndex& command);
        void ExecuteCommand(const CommandResetCalcChain& command);
        void ExecuteCommand(const CommandAddSharedStrings& command);
        void ExecuteCommand(const CommandAddWorksheet& command);
        void ExecuteCommand(const CommandAddChartSheet& command) noexcept;
        void ExecuteCommand(const CommandDeleteSheet& command);
        void ExecuteCommand(const CommandCloneSheet& command);

        NODISCARD QuerySheetName ExecuteQuery(const QuerySheetName& query) const;
        NODISCARD QuerySheetIndex ExecuteQuery(const QuerySheetIndex& query) const noexcept;
        NODISCARD QuerySheetVisibility ExecuteQuery(const QuerySheetVisibility& query) const;
        NODISCARD QuerySheetType ExecuteQuery(const QuerySheetType& query) const;
        NODISCARD QuerySheetId ExecuteQuery(const QuerySheetId& query) const;
        NODISCARD QuerySheetRelsId ExecuteQuery(const QuerySheetRelsId& query) const;
        NODISCARD QuerySheetRelsTarget ExecuteQuery(const QuerySheetRelsTarget& query) const;
        NODISCARD QuerySharedStrings ExecuteQuery(const QuerySharedStrings& query) const;
        NODISCARD QueryXmlData ExecuteQuery(const QueryXmlData& query) const;

        NODISCARD std::string ExtractXmlFromArchive(const std::string& path);

    private:
        using ConstXmlDataSharedPtr = std::shared_ptr<const XmlData>;
        using XmlDataSharedPtr = std::shared_ptr<XmlData>;
        using RelationshipsSharedPtr = std::shared_ptr<Relationships>;
        using ContentTypesSharedPtr = std::shared_ptr<ContentTypes>;
        using AppPropertiesSharedPtr = std::shared_ptr<AppProperties>;
        using PropertiesSharedPtr = std::shared_ptr<Properties>;
        using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
        using WorkbookSharedPtr = std::shared_ptr<Workbook>;
        using XmlDataContainer = std::vector<XmlDataSharedPtr>;

    private:
        using DocumentWeakPtr = std::weak_ptr<Document>;

    private:
        NODISCARD XmlDataSharedPtr GetXmlData(const std::string& path);
        NODISCARD ConstXmlDataSharedPtr GetXmlData(const std::string& path) const;
        void DoCreate();

        void SetAppVersionProperty(const std::string& value);

    private:
        DocumentWeakPtr documentWeakPtr;
        std::string filePath;
        XmlDataContainer data;
        RelationshipsSharedPtr docRelationships;
        RelationshipsSharedPtr wbkRelationships;
        ContentTypesSharedPtr contentTypes;
        AppPropertiesSharedPtr appProperties;
        PropertiesSharedPtr coreProperties;
        SharedStringsSharedPtr sharedStrings;
        WorkbookSharedPtr workbook;
        SimpleZip::ZipArchive archive;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DOCUMENT_IMPL_H
