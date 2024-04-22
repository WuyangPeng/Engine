/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/02 22:52)

#ifndef CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "ExcelConversionCSVImpl.h"
#include "OpenXLSXDocument.h"
#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

#ifdef CORE_TOOLS_USE_OPEN_XLSX

namespace CoreTools
{
    /// Excelת��CSV��ʽ
    /// ��һ�У����ݴ洢��ʽ������ӳ�䡢����У������á�
    /// �ڶ��У���עÿ���ֶε�����/˵����
    /// �����У���ע�ֶ��������͡�
    /// �����У���ע�ֶα�������
    /// ����������,���ָ���
    /// ��������Ϊ��ʱ�����ݲ������������ַ������ͣ�����ʱͷβ����"��
    /// ����ʱ�����������Ƿ�Ϸ����ַ���������Ϊ��string����
    class CORE_TOOLS_HIDDEN_DECLARE OpenXLSXConversion final : public ExcelConversionCSVImpl
    {
    public:
        using ClassType = OpenXLSXConversion;
        using ParentType = ExcelConversionCSVImpl;

        using String = System::String;
        using Row = OpenXLSX::XLRow;
        using CellValue = OpenXLSX::XLCellValue;
        using Worksheet = OpenXLSX::XLWorksheet;

    public:
        OpenXLSXConversion(const std::string& xlsxFileName, String csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        using IndexContainer = std::set<int>;
        using Container = std::vector<std::string>;

    private:
        void Conversion();

        void ObtainRelated(const Worksheet& worksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const Worksheet& worksheet) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const Row& row) const;
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const CellValue& xlCellValue) const;

        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column) const;
        NODISCARD static bool IsIgnore(const Worksheet& worksheet);

        void SaveIntoFile(const std::string& content) const;

        void ObtainRelated(int excludeIndex, const CellValue& element);
        NODISCARD std::string GetFirstPageBitFieldContent(int columnIndex, const std::string& column) const;
        NODISCARD static std::string GetStringFieldContent(const std::string& column);

        NODISCARD static std::string GetBitArrayFieldContent(const std::string& column);
        NODISCARD static std::string GetBitFieldContent(const std::string& column);
        NODISCARD static std::string GetBitArrayFieldContent(bool isEnd, const std::string& element);

    private:
        OpenXLSXDocument document;
        String csvFileName;
        IndexContainer exclude;
        IndexContainer stringField;
        IndexContainer bitField;
        IndexContainer bitArrayField;
    };
}

#endif  // CORE_TOOLS_USE_OPEN_XLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPEN_XLSX_CONVERSION_H`