///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/14 15:28)

#ifndef CORE_TOOLS_TEXT_PARSING_WORKBOOK_H
#define CORE_TOOLS_TEXT_PARSING_WORKBOOK_H

#include "CoreTools/CoreToolsDll.h"

#include "ContentTypes.h"
#include "Relationships.h"
#include "SimpleCSVException.h"
#include "XmlFile.h"

#include <vector>

namespace CoreTools
{
    namespace SimpleCSV
    {
        class CORE_TOOLS_DEFAULT_DECLARE Workbook final : public XmlFile
        {
        public:
            using ClassType = Workbook;
            using ParentType = XmlFile;
            using SharedStringsSharedPtr = std::shared_ptr<SharedStrings>;
            using SheetNamesType = std::vector<std::string>;

        public:
            explicit Workbook(const XmlDataSharedPtr& xmlData);

            CLASS_INVARIANT_FINAL_DECLARE;

            NODISCARD Worksheet GetSheet(int index);
            NODISCARD Worksheet GetSheet(const std::string& sheetName);
            NODISCARD Worksheet GetWorksheet(const std::string& sheetName);
            NODISCARD Worksheet GetChartsheet(const std::string& sheetName);

            void DeleteSheet(const std::string& sheetName);
            void AddWorksheet(const std::string& sheetName);
            void CloneSheet(const std::string& existingName, const std::string& newName);

            void SetSheetIndex(const std::string& sheetName, int index);
            NODISCARD int GetIndexOfSheet(const std::string& sheetName) const;

            NODISCARD SheetType GetTypeOfSheet(const std::string& sheetName) const;
            NODISCARD SheetType GetTypeOfSheet(int index) const;

            NODISCARD int GetSheetCount() const;
            NODISCARD int GetWorksheetCount() const;
            NODISCARD int GetChartsheetCount() const;

            NODISCARD SheetNamesType GetSheetNames() const;
            NODISCARD SheetNamesType GetWorksheetNames() const;
            NODISCARD SheetNamesType GetChartsheetNames() const;

            NODISCARD bool IsSheetExists(const std::string& sheetName) const;
            NODISCARD bool IsWorksheetExists(const std::string& sheetName) const;
            NODISCARD bool IsChartsheetExists(const std::string& sheetName) const;

            NODISCARD SharedStringsSharedPtr GetSharedStrings();
            NODISCARD bool HasSharedStrings() const;

            void SetSheetName(const std::string& sheetRID, const std::string& newName);
            NODISCARD std::string GetSheetVisibility(const std::string& sheetID) const;
            NODISCARD std::string GetSheetName(const std::string& sheetID) const;
            NODISCARD std::string GetSheetID(const std::string& sheetName);
            NODISCARD int CreateInternalSheetID();
            void PrepareSheetMetadata(const std::string& sheetName, int internalID);

        private:
            void SetSheetVisibility(const std::string& sheetRID, const std::string& state);
            NODISCARD XMLNode GetSheetsNode() const;

            void UpdateSheetReferences(std::string oldName, std::string newName);
        };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_WORKBOOK_H
