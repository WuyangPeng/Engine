///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:17)

#ifndef CORE_TOOLS_TEXT_PARSING_DOCUMENT_H
#define CORE_TOOLS_TEXT_PARSING_DOCUMENT_H

#include "CoreTools/CoreToolsDll.h"

#include "AppProperties.h"
#include "CommandQuery/QuerySharedStrings.h"
#include "CommandQuery/QuerySheetId.h"
#include "CommandQuery/QuerySheetName.h"
#include "CommandQuery/QuerySheetRelsId.h"
#include "CommandQuery/QuerySheetRelsTarget.h"
#include "CommandQuery/QuerySheetType.h"
#include "CommandQuery/QuerySheetVisibility.h"
#include "CommandQuery/QueryXmlData.h"
#include "SimpleCSVException.h"
#include "Workbook.h"
#include "XmlData.h"
#include "Flags/CSVExceptionFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVInternalFwd.h"
#include "CoreTools/TextParsing/SimpleZip/ZipArchive.h"

#include <memory>
#include <string>

template class CORE_TOOLS_DEFAULT_DECLARE std::shared_ptr<CoreTools::SimpleCSV::DocumentImpl>;
template class CORE_TOOLS_DEFAULT_DECLARE CoreTools::NonCopyImpl<CoreTools::SimpleCSV::DocumentImpl>;

namespace CoreTools::SimpleCSV
{
    class CORE_TOOLS_DEFAULT_DECLARE Document final
    {
    public:
        NON_COPY_TYPE_DECLARE(Document);
        using DocumentSharedPtr = std::shared_ptr<Document>;

    public:
        NODISCARD static DocumentSharedPtr Create(const std::string& docPath);
        NODISCARD static DocumentSharedPtr Open(const std::string& docPath);

    private:
        enum class DocumentCreate
        {
            Init,
        };

    public:
        explicit Document(DocumentCreate documentCreate, const std::string& docPath);

        CLASS_INVARIANT_DECLARE;

        void Save();
        void SaveAs(const std::string& fileName);
        NODISCARD std::string GetName() const;
        NODISCARD Workbook GetWorkbook() const;

        NODISCARD std::string GetProperty(Property prop) const;
        void SetProperty(Property prop, const std::string& value);
        void DeleteProperty(Property theProperty);

        NODISCARD std::string ExtractXmlFromArchive(const std::string& path);

        void ExecuteCommand(const CommandSetSheetName& command);
        void ExecuteCommand(const CommandSetSheetIndex& command);
        void ExecuteCommand(const CommandResetCalcChain& command);
        void ExecuteCommand(const CommandAddSharedStrings& command);
        void ExecuteCommand(const CommandAddWorksheet& command);
        void ExecuteCommand(const CommandDeleteSheet& command);
        void ExecuteCommand(const CommandCloneSheet& command);

        NODISCARD QuerySheetName ExecuteQuery(const QuerySheetName& query) const;
        NODISCARD QuerySheetVisibility ExecuteQuery(const QuerySheetVisibility& query) const;
        NODISCARD QuerySheetType ExecuteQuery(const QuerySheetType& query) const;
        NODISCARD QuerySheetId ExecuteQuery(const QuerySheetId& query) const;
        NODISCARD QuerySheetRelsId ExecuteQuery(const QuerySheetRelsId& query) const;
        NODISCARD QuerySheetRelsTarget ExecuteQuery(const QuerySheetRelsTarget& query) const;
        NODISCARD QuerySharedStrings ExecuteQuery(MAYBE_UNUSED const QuerySharedStrings& query) const;
        NODISCARD QueryXmlData ExecuteQuery(const QueryXmlData& query) const;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DOCUMENT_H
