/// Copyright (c) 2010-
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 自动生成

#include "VectorType.h"
#include "CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

using namespace std::literals;

CSVConfigure::VectorType CSVConfigure::StringCastVectorType(const System::String& describe)
{
    static std::map<System::String, VectorType> typeDescribe{ { SYSTEM_TEXT("Two"s), VectorType::Two },
                                                              { SYSTEM_TEXT("Three"s), VectorType::Three },
                                                              { SYSTEM_TEXT("Four"s), VectorType::Four } };   

    if (const auto iter = typeDescribe.find(describe);
        iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

System::String CSVConfigure::EnumCastString(VectorType type)
{
    static std::map<VectorType, System::String> typeDescribe{ { VectorType::Two, SYSTEM_TEXT("Two"s) },
                                                              { VectorType::Three, SYSTEM_TEXT("Three"s) },
                                                              { VectorType::Four, SYSTEM_TEXT("Four"s) }
 };    

    if (const auto iter = typeDescribe.find(type);
        iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

System::String CSVConfigure::GetEnumDescribe(VectorType type)
{
    static std::map<VectorType, System::String> typeDescribe{ { VectorType::Two, SYSTEM_TEXT("二维"s) },
                                                              { VectorType::Three, SYSTEM_TEXT("三维"s) },
                                                              { VectorType::Four, SYSTEM_TEXT("四维"s) }
 };    

    if (const auto iter = typeDescribe.find(type);
        iter != typeDescribe.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到对应的类型。"s))
    }
}

template <>
CSVConfigure::VectorType CoreTools::CSVRow::StringCastEnum<CSVConfigure::VectorType>(const String& describe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return CSVConfigure::StringCastVectorType(describe);
}