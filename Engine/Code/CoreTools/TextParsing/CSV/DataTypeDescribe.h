///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/26 13:45)

#ifndef CORE_TOOLS_TEXT_PARSING_DATA_TYPE_DESCRIBE_H
#define CORE_TOOLS_TEXT_PARSING_DATA_TYPE_DESCRIBE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    class DataTypeDescribe final
    {
    public:
        using ClassType = DataTypeDescribe;

        using StringView = System::StringView;

    public:
        constexpr DataTypeDescribe(CSVDataType csvDataType,
                                   StringView describe,
                                   StringView actualType,
                                   StringView functionName,
                                   StringView valueType,
                                   StringView baseReturnDescribe,
                                   StringView abbreviation)
            : csvDataType{ csvDataType },
              describe{ describe },
              actualType{ actualType },
              functionName{ functionName },
              valueType{ valueType },
              baseReturnDescribe{ baseReturnDescribe },
              abbreviation{ abbreviation }
        {
        }

        NODISCARD constexpr CSVDataType GetCsvDataType() const noexcept
        {
            return csvDataType;
        }

        NODISCARD constexpr StringView GetDescribe() const noexcept
        {
            return describe;
        }

        NODISCARD constexpr StringView GetActualType() const noexcept
        {
            return actualType;
        }

        NODISCARD constexpr StringView GetFunctionName() const noexcept
        {
            return functionName;
        }

        NODISCARD constexpr StringView GetValueType() const noexcept
        {
            return valueType;
        }

        NODISCARD constexpr StringView GetBaseReturnDescribe() const noexcept
        {
            return baseReturnDescribe;
        }

        NODISCARD constexpr StringView GetAbbreviation() const noexcept
        {
            return abbreviation;
        }

    private:
        CSVDataType csvDataType;
        StringView describe;
        StringView actualType;
        StringView functionName;
        StringView valueType;
        StringView baseReturnDescribe;
        StringView abbreviation;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DATA_TYPE_DESCRIBE_H