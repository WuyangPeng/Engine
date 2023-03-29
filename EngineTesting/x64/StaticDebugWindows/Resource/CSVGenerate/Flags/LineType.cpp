/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "LineType.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

using namespace std::literals;

CSVConfigure::LineType CSVConfigure::StringCastLineType(const System::String& describe)
{
    static std::map<System::String, LineType> typeDescribe{ { SYSTEM_TEXT("Two"s), LineType::Two },
                                                            { SYSTEM_TEXT("Three"s), LineType::Three },
                                                            { SYSTEM_TEXT("Four"s), LineType::Four } };

    const auto iter = typeDescribe.find(describe);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

System::String CSVConfigure::EnumCastString(LineType type)
{
    static std::map<LineType, System::String> typeDescribe{ { LineType::Two, SYSTEM_TEXT("Two"s) },
                                                            { LineType::Three, SYSTEM_TEXT("Three"s) },
                                                            { LineType::Four, SYSTEM_TEXT("Four"s) } };

    const auto iter = typeDescribe.find(type);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

System::String CSVConfigure::GetEnumDescribe(LineType type)
{
    static std::map<LineType, System::String> typeDescribe{ { LineType::Two, SYSTEM_TEXT("二维"s) },
                                                            { LineType::Three, SYSTEM_TEXT("三维"s) },
                                                            { LineType::Four, SYSTEM_TEXT("四维"s) } };

    const auto iter = typeDescribe.find(type);

    if (iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

template <>
CSVConfigure::LineType CoreTools::CSVRow::StringCastEnum<CSVConfigure::LineType>(const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return CSVConfigure::StringCastLineType(describe);
}

