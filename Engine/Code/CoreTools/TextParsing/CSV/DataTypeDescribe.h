///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/18 21:31)

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
                                   StringView baseReturnDescribe)
            : csvDataType{ csvDataType },
              describe{ describe },
              actualType{ actualType },
              functionName{ functionName },
              valueType{ valueType },
              baseReturnDescribe{ baseReturnDescribe }
        {
        }

        constexpr CSVDataType GetCsvDataType() const noexcept
        {
            return csvDataType;
        }

        constexpr StringView GetDescribe() const noexcept
        {
            return describe;
        }

        constexpr StringView GetActualType() const noexcept
        {
            return actualType;
        }

        constexpr StringView GetFunctionName() const noexcept
        {
            return functionName;
        }

        constexpr StringView GetValueType() const noexcept
        {
            return valueType;
        }

        constexpr StringView GetBaseReturnDescribe() const noexcept
        {
            return baseReturnDescribe;
        }

    private:
        CSVDataType csvDataType;
        StringView describe;
        StringView actualType;
        StringView functionName;
        StringView valueType;
        StringView baseReturnDescribe;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_DATA_TYPE_DESCRIBE_H