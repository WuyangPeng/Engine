///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/04 16:00)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateGetFunction.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/CSVTypeConversion.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using std::vector;
using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateGetFunction::CSVGenerateGetFunction(const CSVHead& csvHead, const String& keyTypeDescribe)
    : csvHead{ csvHead }, keyTypeDescribe{ keyTypeDescribe }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateGetFunction)

System::String CoreTools::CSVGenerateGetFunction::GenerateBaseGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD virtual "s);
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" GetKey() const noexcept;\n"s);

    content += g_NewlineCharacter;

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateBaseGetFunction(index);
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateBaseGetFunction(int index) const
{
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    const auto dataType = csvHead.GetDataType(index);

    auto actualType = csvHead.GetActualType(index);

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD virtual "s);
    content += actualType;
    content += g_Space;
    content += functionVariableName;
    content += SYSTEM_TEXT("() const");

    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += SYSTEM_TEXT(" noexcept");
    }

    content += g_SemicolonNewline;

    if (CSVDataType::BoolArray <= dataType)
    {
        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD virtual int "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Count() const;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD virtual bool "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("(MAYBE_UNUSED int index) const;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD virtual "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Begin() const;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD virtual "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("End() const;\n"s);
    }

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        auto upperVariableName = csvHead.GetUpperVariableName(index);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD virtual std::shared_ptr<const "s);
        content += StringConversion::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("> Get"s);
        content += upperVariableName;
        content += SYSTEM_TEXT("(MAYBE_UNUSED const "s);
        content += csvHead.GetNameSpace();
        content += SYSTEM_TEXT("Container& csvContainer) const;\n "s);
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateChildGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD "s);
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" GetKey() const noexcept override;\n"s);

    content += g_NewlineCharacter;

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateChildGetFunction(index);
    }

    if (csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += GenerateGetKeyFunction();
    }

    if (csvHead.HasScope())
    {
        content += g_Indentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("void Checking();\n"s);
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateGetKeyFunction() const
{
    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD constexpr static "s);
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" GenerateKey(");

    const auto result = csvHead.GetKeyName();

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += SYSTEM_TEXT(", "s);
        }
    }

    content += SYSTEM_TEXT(") noexcept\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionBeginBrackets;

    content += g_Indentation;
    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("return ");

    content += csvHead.GetKey();
    content += g_SemicolonNewline;

    content += g_Indentation;
    content += g_Indentation;
    content += g_FunctionEndBrackets;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateChildGetFunction(int index) const
{
    auto actualType = csvHead.GetActualType(index);
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD "s);
    content += actualType;
    content += SYSTEM_TEXT(" ");
    content += functionVariableName;
    content += SYSTEM_TEXT("() const ");

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += SYSTEM_TEXT("noexcept ");
    }

    content += SYSTEM_TEXT("override;\n"s);

    if (CSVDataType::BoolArray <= dataType)
    {
        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD int "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Count() const override;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD bool "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("(int index) const override;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Begin() const noexcept override;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("End() const noexcept override;\n"s);
    }

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        auto upperVariableName = csvHead.GetUpperVariableName(index);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD std::shared_ptr<const "s);
        content += StringConversion::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("> Get"s);
        content += upperVariableName;
        content += SYSTEM_TEXT("(const ");
        content += csvHead.GetNameSpace();
        content += SYSTEM_TEXT("Container& csvContainer) const override;\n "s);
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateGetFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD "s);
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" GetKey() const noexcept;\n"s);

    content += g_NewlineCharacter;

    const auto count = csvHead.GetCount();
    for (auto index = 0; index < count; ++index)
    {
        content += GenerateGetFunction(index);
    }

    if (csvHead.GetCSVFormatType() == CSVFormatType::Key)
    {
        content += GenerateGetKeyFunction();
    }

    if (csvHead.HasScope())
    {
        content += g_Indentation;
        content += SYSTEM_TEXT("private:\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("void Checking();\n"s);
        content += g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateGetFunction(int index) const
{
    auto actualType = csvHead.GetActualType(index);
    auto functionVariableName = csvHead.GetFunctionVariableName(index);

    String content{ g_Indentation };
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD "s);
    content += actualType;
    content += g_Space;
    content += functionVariableName;
    content += SYSTEM_TEXT("() const");

    const auto dataType = csvHead.GetDataType(index);
    if (CSVDataType::Bool <= dataType && dataType <= CSVDataType::IntVector4)
    {
        content += SYSTEM_TEXT(" noexcept");
    }

    content += g_SemicolonNewline;

    if (CSVDataType::BoolArray <= dataType)
    {
        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD int "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Count() const;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD bool "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("(int index) const;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("Begin() const noexcept;\n"s);

        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD "s);
        content += actualType;
        content += SYSTEM_TEXT("::const_iterator "s);
        content += functionVariableName;
        content += SYSTEM_TEXT("End() const noexcept;\n"s);
    }

    const auto mapping = csvHead.GetMapping(index);
    if (!mapping.empty())
    {
        auto upperVariableName = csvHead.GetUpperVariableName(index);
        content += g_Indentation;
        content += g_Indentation;
        content += SYSTEM_TEXT("NODISCARD std::shared_ptr<const "s);
        content += StringConversion::ToFirstLetterUpper(mapping);
        content += SYSTEM_TEXT("> Get"s);
        content += upperVariableName;
        content += SYSTEM_TEXT("(const CSVContainer& csvContainer) const;\n"s);
    }

    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    const auto csvFormatType = csvHead.GetCSVFormatType();

    switch (csvFormatType)
    {
        case CSVFormatType::Default:
        {
            content += GenerateDefaultContainerFunction();
        }
        break;
        case CSVFormatType::Vector:
        {
            content += GenerateVectorContainerFunction();
        }
        break;
        case CSVFormatType::TreeMap:
            FALLTHROUGH;
        case CSVFormatType::HashMap:
        {
            content += GenerateMapContainerFunction();
        }
        break;
        case CSVFormatType::Key:
        {
            content += GenerateKeyContainerFunction();
        }
        break;
        case CSVFormatType::Unique:
        {
            content += GenerateUniqueContainerFunction();
        }
        break;
        default:
            break;
    }

    content += g_Indentation;
    content += SYSTEM_TEXT("private:\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("void Parsing(const CoreTools::CSVContent& csvContent);\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateDefaultContainerFunction() const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container GetContainer() const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateVectorContainerFunction() const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container GetContainer() const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateMapContainerFunction() const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD MappingContainer GetContainer() const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateKeyContainerFunction() const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("("s);

    auto result = csvHead.GetKeyName();

    auto index = 0u;
    for (const auto& value : result)
    {
        content += CSVTypeConversion::GetActualType(csvHead.GetDataType(value));
        content += g_Space;
        content += value;

        ++index;
        if (index != result.size())
        {
            content += SYSTEM_TEXT(", "s);
        }
    }

    content += SYSTEM_TEXT(") const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(");
    content += keyTypeDescribe;
    content += SYSTEM_TEXT(" key) const;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container GetContainer() const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("BaseSharedPtr GetFirst"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("template <typename Function>\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Container Get"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("(Function function) const;\n"s);
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateGetFunction::GenerateUniqueContainerFunction() const
{
    String content{ g_Indentation };

    content += g_Indentation;
    content += SYSTEM_TEXT("NODISCARD Const"s);
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("SharedPtr Get");
    content += csvHead.GetCSVClassName();
    content += SYSTEM_TEXT("() const noexcept;\n "s);
    content += g_NewlineCharacter;

    return content;
}
