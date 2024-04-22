/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 15:22)

#ifndef CORE_TOOLS_TEXT_PARSING_WORKBOOK_H
#define CORE_TOOLS_TEXT_PARSING_WORKBOOK_H

#include "CoreTools/CoreToolsDll.h"

#include "ContentTypes.h"
#include "Relationships.h"
#include "XmlFile.h"

#include <vector>

namespace CoreTools::SimpleCSV
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
        NODISCARD Worksheet GetChartSheet(const std::string& sheetName);

        void DeleteSheet(const std::string& sheetName);
        void AddWorksheet(const std::string& sheetName);
        void CloneSheet(const std::string& existingName, const std::string& newName);

        void SetSheetIndex(const std::string& sheetName, int index);
        NODISCARD int GetIndexOfSheet(const std::string& sheetName) const;

        NODISCARD SheetType GetTypeOfSheet(const std::string& sheetName) const;
        NODISCARD SheetType GetTypeOfSheet(int index) const;

        NODISCARD int GetSheetCount() const;
        NODISCARD int GetWorksheetCount() const;
        NODISCARD int GetChartSheetCount() const;

        NODISCARD SheetNamesType GetSheetNames() const;
        NODISCARD SheetNamesType GetWorksheetNames() const;
        NODISCARD SheetNamesType GetChartSheetNames() const;

        NODISCARD bool IsSheetExists(const std::string& sheetName) const;
        NODISCARD bool IsWorksheetExists(const std::string& sheetName) const;
        NODISCARD bool IsChartSheetExists(const std::string& sheetName) const;

        NODISCARD SharedStringsSharedPtr GetSharedStrings();
        NODISCARD bool HasSharedStrings() const;

        void SetSheetName(const std::string& sheetRId, const std::string& newName);
        NODISCARD std::string GetSheetVisibility(const std::string& sheetId) const;
        NODISCARD std::string GetSheetName(const std::string& sheetId) const;
        NODISCARD std::string GetSheetId(const std::string& sheetName);
        NODISCARD int CreateInternalSheetId();
        void PrepareSheetMetadata(const std::string& sheetName, int internalId);

    private:
        using XMLNodeContainer = std::vector<XMLNode>;

    private:
        void SetSheetVisibility(const std::string& sheetRId, const std::string& state);
        NODISCARD XMLNode GetSheetsNode() const;

        void UpdateSheetReferences(std::string oldName, std::string newName);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_WORKBOOK_H
