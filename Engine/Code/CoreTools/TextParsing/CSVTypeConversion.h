///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.5 (2021/10/16 20:24)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H
#define CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "TextParsingFwd.h"
#include "System/Helper/UnicodeUsing.h"

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
        NODISCARD static String GetFunctionName(CSVDataType csvDataType);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_TYPE_CONVERSION_H