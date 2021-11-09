///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/10/15 14:18)

#ifndef CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "ExcelConversionCSVImpl.h"
#include "OpenXLSXDocument.h"
#include "System/Helper/PragmaWarning/OpenXLSX.h"
#include "System/Helper/UnicodeUsing.h"

#include <set>
#include <string>

#ifdef CORE_TOOLS_USE_OPENXLSX

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

    public:
        OpenXLSXConversion(const std::string& xlsxFileName, const String& csvFileName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void Conversion();

        void ObtainRelated(const OpenXLSX::XLWorksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, const OpenXLSX::XLWorksheet& xlWorksheet);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, const OpenXLSX::XLRow& xlRow);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const OpenXLSX::XLCellValue& xlCellValue);
        NODISCARD std::string GetContent(bool isFirstPage, int rowIndex, int columnIndex, const std::string& column);
        NODISCARD bool IsIgnore(const OpenXLSX::XLWorksheet& xlWorksheet);

        void SaveIntoFile(const std::string& content);

    private:
        using IndexContainer = std::set<int>;

    private:
        OpenXLSXDocument document;
        String csvFileName;
        IndexContainer exclude;
        IndexContainer stringField;
        IndexContainer bitField;
        IndexContainer bitArrayField;
    };
}

#endif CORE_TOOLS_USE_OPENXLSX

#endif  // CORE_TOOLS_TEXT_PARSING_OPENXLSX_CONVERSION_H