///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/03 13:59)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateClassName.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateClassName::CSVGenerateClassName(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateClassName)

System::String CoreTools::CSVGenerateClassName::GenerateParentClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };
    content += g_Class;
    content += className;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassType;
    content += className;
    content += g_SemicolonNewline;

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateChildClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };
    content += g_Class;
    content += className;
    content += SYSTEM_TEXT(" final : public "s);
    content += className;
    content += SYSTEM_TEXT("Base\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassType;
    content += className;
    content += g_SemicolonNewline;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("using ParentType = "s);
    content += className;
    content += SYSTEM_TEXT("Base;\n"s);

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };
    content += g_Class;
    content += className;
    content += SYSTEM_TEXT(" final\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassType;
    content += className;
    content += g_SemicolonNewline;

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateContainerClassName(const String& keyTypeDescribe) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };
    content += g_Class;
    content += className;
    content += SYSTEM_TEXT(" final\n"s);

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassType;
    content += className;
    content += g_SemicolonNewline;

    content += GenerateSharedPtrUsing(keyTypeDescribe);

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateSharedPtr(const String& prefix) const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("using Const"s) + csvHead.GetCSVClassName() + prefix + SYSTEM_TEXT("SharedPtr = std::shared_ptr<const "s) + csvHead.GetCSVClassName() + prefix + SYSTEM_TEXT(">;\n"s);

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateSharedPtrUsing(const String& keyTypeDescribe) const
{
    String content{};

    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Default:
            FALLTHROUGH;
        case CSVFormatType::Vector:
            FALLTHROUGH;
        case CSVFormatType::Key:
        {
            content += GenerateSharedPtr(SYSTEM_TEXT("Base"s));
            content += GenerateSharedPtrContainer(SYSTEM_TEXT("Base"s));
        }
        break;

        case CSVFormatType::TreeMap:
        {
            content += GenerateSharedPtr(String{});
            content += GenerateSharedPtrMappingContainer(keyTypeDescribe, SYSTEM_TEXT("map"s));
            content += GenerateSharedPtrContainer(String{});
        }
        break;
        case CSVFormatType::HashMap:
        {
            content += GenerateSharedPtr(String{});
            content += GenerateSharedPtrMappingContainer(keyTypeDescribe, SYSTEM_TEXT("unordered_map"s));
            content += GenerateSharedPtrContainer(String{});
        }
        break;
        case CSVFormatType::Unique:
        {
            content += GenerateSharedPtr(String{});
        }
        break;
        default:
            break;
    }

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateSharedPtrContainer(const String& prefix) const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("using Container = std::vector<Const"s) + csvHead.GetCSVClassName() + prefix + SYSTEM_TEXT("SharedPtr>;\n"s);

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateSharedPtrMappingContainer(const String& keyTypeDescribe, const String& mappingName) const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("using MappingContainer = std::"s) + mappingName + SYSTEM_TEXT("<"s) + keyTypeDescribe + SYSTEM_TEXT(", Const"s) + csvHead.GetCSVClassName() + SYSTEM_TEXT("SharedPtr>;\n"s);

    return content;
}

System::String CoreTools::CSVGenerateClassName::GenerateEnumClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };
    content += SYSTEM_TEXT("enum class "s);
    content += className;
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    return content;
}
