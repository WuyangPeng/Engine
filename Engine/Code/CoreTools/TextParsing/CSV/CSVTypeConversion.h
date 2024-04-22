/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 13:19)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "DataTypeDescribe.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

#include <map>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CSVTypeConversion final
    {
    public:
        using ClassType = CSVTypeConversion;

        using String = System::String;

    public:
        NODISCARD static std::string GetTypeDescribe(CSVDataType csvDataType);
        NODISCARD static std::string GetTypeDescribe(CSVFormatType csvFormatType);
        NODISCARD static CSVFormatType GetFormatType(const String& describe);
        NODISCARD static CSVDataType GetDataType(const String& describe);

        NODISCARD static String GetActualType(CSVDataType csvDataType);
        NODISCARD static String GetAbbreviation(CSVDataType csvDataType);
        NODISCARD static String GetFunctionName(CSVDataType csvDataType);
        NODISCARD static String GetValueType(CSVDataType csvDataType);
        NODISCARD static String GetBaseReturnDescribe(CSVDataType csvDataType);

    private:
        using FormatTypeConversionDescribe = std::map<CSVFormatType, std::string>;
        using DescribeConversionFormatType = std::map<String, CSVFormatType>;
        using DataTypeDescribeContainer = std::vector<DataTypeDescribe>;
        using DataTypeConversionDescribe = std::map<CSVDataType, std::string>;
        using DescribeConversionDataType = std::map<String, CSVDataType>;
        using DataTypeConversionActualType = std::map<CSVDataType, String>;
        using DataTypeConversionFunctionName = std::map<CSVDataType, String>;
        using DataTypeConversionValueType = std::map<CSVDataType, String>;
        using DataTypeConversionBaseReturnDescribe = std::map<CSVDataType, String>;
        using DataTypeConversionAbbreviation = std::map<CSVDataType, String>;

    private:
        NODISCARD static FormatTypeConversionDescribe GetFormatTypeConversionDescribe();
        NODISCARD static DescribeConversionFormatType GetDescribeConversionFormatType();
        NODISCARD static DataTypeDescribeContainer GetDataTypeDescribeContainer();
        NODISCARD static DataTypeConversionDescribe GetDataTypeConversionDescribe();
        NODISCARD static DescribeConversionDataType GetDescribeConversionDataType();
        NODISCARD static DataTypeConversionActualType GetDataTypeConversionActualType();
        NODISCARD static DataTypeConversionFunctionName GetDataTypeConversionFunctionName();
        NODISCARD static DataTypeConversionValueType GetDataTypeConversionValueType();
        NODISCARD static DataTypeConversionBaseReturnDescribe GetDataTypeConversionBaseReturnDescribe();
        NODISCARD static DataTypeConversionAbbreviation GetDataTypeConversionAbbreviation();

        NODISCARD static CSVDataType GetEnumDataType(const String& describe);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H