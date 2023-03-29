///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/09 18:09)

#include "CoreTools/CoreToolsExport.h"

#include "JsonTotalGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
#include "CoreTools/TextParsing/Json/JsonNode.h"
#include "CoreTools/TextParsing/Json/JsonNodeContainer.h"

#include <map>
#include <set>

using namespace std::literals;

CoreTools::JsonTotalGenerateImpl::JsonTotalGenerateImpl(String nameSpace, JsonHeadContainer jsonHeadContainer) noexcept
    : nameSpace{ std::move(nameSpace) }, jsonHeadContainer{ std::move(jsonHeadContainer) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonTotalGenerateImpl)

void CoreTools::JsonTotalGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto fileName = directory + TextParsing::gForwardSlash + nameSpace + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent();

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::JsonTotalGenerateImpl::GetOldContent(const String& fileName)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        IFStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const Error&)
    {
        // 文件不存在是正常的。
        return String{};
    }
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateCopyright()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("/// Copyright (c) 2010-\n"s);

    content += SYSTEM_TEXT("/// Threading Core Render Engine\n"s);
    content += TextParsing::gAnnotation;
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("/// 作者：彭武阳，彭晔恩，彭晔泽\n"s);
    content += SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n"s);
    content += TextParsing::gAnnotation;
    content += TextParsing::gNewlineCharacter;

    content += SYSTEM_TEXT("/// 标准：std:c++20\n"s);
    content += SYSTEM_TEXT("/// 自动生成\n"s);

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return TextParsing::gNewline.data();
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + nameSpace + GetFileSuffix());

    String content{ TextParsing::gIfndef };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gDefine;
    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringUtility::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::gEndif };

    content += headerGuard;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    DataType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName(), value);
    }

    auto content = GenerateDataHead(dataType);

    content += TextParsing::gIncludePrefix;
    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateEnumHead(const EnumType& enumType)
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::gIncludePrefix;
        content += TextParsing::gFlags;
        content += TextParsing::gForwardSlash;
        content += value;
        content += TextParsing::gHeadFileSuffix;
    }

    if (!enumType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateDataHead(const DataType& dataType)
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value.first;
        content += TextParsing::gHeadDetailFileSuffix;
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateFwdHead()
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gTextParsingFwd };

    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gCoreToolsHeadFile };

    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIncludePrefix;
    content += nameSpace;
    content += TextParsing::gFwd;
    content += TextParsing::gHeadFileSuffix;

    content += TextParsing::gUnicodeUsing;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gMemory;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIncludePrefix };

    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gHeadFileSuffix;
    content += TextParsing::gNewlineCharacter;

    std::set<String> dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIncludePrefix;
        content += value;
        content += TextParsing::gHeadFileSuffix;
    }

    content += SYSTEM_TEXT("#include \"CoreTools/CharacterString/StringConversion.h\"\n");
    content += TextParsing::gUserClassInvariantMacro;
    content += TextParsing::gExceptionMacro;
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonRow.h\"\n");
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonHead.h\"\n");
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gFilesystem;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gUsingNamespaceLiterals;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gNamespace };

    content += nameSpace;
    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateEnumFwd(const EnumType& enumType)
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gEnumClass;
        content += value;
        content += TextParsing::gSemicolonNewline;
    }

    if (!enumType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateInnerNameSpaceBegin(const JsonHead& jsonHead) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::gIndentation };

    content += SYSTEM_TEXT("namespace "s);

    content += jsonHead.GetJsonClassName();
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateInnerNameSpaceEnd() const
{
    String content{ TextParsing::gIndentation };

    content += TextParsing::gFunctionEndBrackets;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateDataFwd(const DataType& dataType) const
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gClass;
        content += value.first;
        content += TextParsing::gContainer;
        content += TextParsing::gSemicolonNewline;

        if (value.second.HasNested())
        {
            content += TextParsing::gNewlineCharacter;

            content += GenerateInnerNameSpaceBegin(value.second);

            ClassNameType classNameType{};

            for (const auto& innerValue : value.second)
            {
                if (innerValue->GetJsonDataType() == JsonDataType::Nested || innerValue->GetJsonDataType() == JsonDataType::NestedArray)
                {
                    const auto className = GetClassNameType(*innerValue);
                    classNameType.insert(className.begin(), className.end());
                }
            }

            for (const auto& name : classNameType)
            {
                if (name.empty())
                    continue;

                content += TextParsing::gIndentation;
                content += TextParsing::gIndentation;
                content += TextParsing::gClass;
                content += name;
                content += TextParsing::gSemicolonNewline;
            }

            content += GenerateInnerNameSpaceEnd();
        }

        content += TextParsing::gNewlineCharacter;
    }

    if (!dataType.empty())
    {
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

CoreTools::JsonTotalGenerateImpl::ClassNameType CoreTools::JsonTotalGenerateImpl::GetClassNameType(const JsonNode& jsonNode)
{
    ClassNameType result{};

    result.insert(StringUtility::ToFirstLetterUpper(jsonNode.GetTypeName()));

    for (const auto& value : jsonNode.GetJsonNodeContainer())
    {
        if (value->GetJsonDataType() == JsonDataType::Nested || value->GetJsonDataType() == JsonDataType::NestedArray)
        {
            const auto className = GetClassNameType(*value);
            result.insert(className.begin(), className.end());
        }
    }

    return result;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateFwd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    DataType dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName(), value);
    }

    content += GenerateDataFwd(dataType);

    content += TextParsing::gIndentation;
    content += TextParsing::gClass;
    content += nameSpace;
    content += TextParsing::gContainer;
    content += TextParsing::gSemicolonNewline;

    content += TextParsing::gFunctionEndBrackets;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };

    content += TextParsing::gClass;
    content += className;
    content += TextParsing::gFinal;
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gFunctionBeginBrackets;

    content += TextParsing::gIndentation;
    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gClassType;
    content += className;
    content += TextParsing::gSemicolonNewline;
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };

    content += TextParsing::gPublic;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const System::String& directory);\n"s);
    content += TextParsing::gNewlineCharacter;

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("CLASS_INVARIANT_DECLARE;\n"s);
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    std::set<String> dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("NODISCARD std::shared_ptr<const "s);
        content += value;
        content += SYSTEM_TEXT("Container> Get");
        content += value;
        content += SYSTEM_TEXT("Container() const noexcept;\n");
    }

    content += TextParsing::gNewlineCharacter;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("private:\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("void Parsing(const System::String& directory);\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("void Verify() const;\n"s);
    content += TextParsing::gNewlineCharacter;

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{};

    std::set<String> dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    for (const auto& value : dataType)
    {
        content += SYSTEM_TEXT("std::shared_ptr<const ");
        content += nameSpace;
        content += SYSTEM_TEXT("::");
        content += value;
        content += SYSTEM_TEXT("Container> ");

        content += nameSpace;
        content += SYSTEM_TEXT("::");
        content += className;
        content += SYSTEM_TEXT("::Get");
        content += value;
        content += SYSTEM_TEXT("Container() const noexcept\n");

        content += SYSTEM_TEXT("{\n");

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_1;\n");
        content += TextParsing::gNewlineCharacter;

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("return ");
        content += StringUtility::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container;\n");

        content += SYSTEM_TEXT("}\n");
        content += TextParsing::gNewlineCharacter;
    }

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    auto content = nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("(const System::String& directory)\n"s);

    content += SYSTEM_TEXT("    : "s);

    std::set<String> dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    auto index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += SYSTEM_TEXT("      "s);
        }

        content += StringUtility::ToFirstLetterLower(value) + SYSTEM_TEXT("Container{}");

        if (index != boost::numeric_cast<int>(dataType.size()) - 1)
        {
            content += SYSTEM_TEXT(","s);
        }

        content += SYSTEM_TEXT("\n"s);

        ++index;
    }

    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("Parsing(directory);\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("Verify();\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_1;\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s);
    content += nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::Parsing(const System::String& directory)\n"s);

    content += SYSTEM_TEXT("{\n"s);
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("const std::filesystem::path path{ directory };\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("for (const auto& inputPath : std::filesystem::directory_iterator(path))\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("auto fileName = inputPath.path().native();\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("if (fileName.find(SYSTEM_TEXT(\".json\"s)) != (fileName.size() - 5))\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("continue;\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("CoreTools::JsonRow::BasicTree basicTree{ fileName };\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("read_json(CoreTools::StringConversion::StandardConversionMultiByte(fileName), basicTree);\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("CoreTools::JsonRow jsonRow{ basicTree };\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("CoreTools::JsonHead jsonHead{ fileName };\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("const auto className = jsonHead.GetJsonClassName();\n"s);
    content += SYSTEM_TEXT("\n"s);

    auto firstData = true;
    for (const auto& value : dataType)
    {
        if (firstData)
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
        }
        else
        {
            content += TextParsing::gIndentation;
            content += TextParsing::gIndentation;
            content += SYSTEM_TEXT("else "s);
        }
        content += SYSTEM_TEXT("if (className == SYSTEM_TEXT(\"");
        content += value;
        content += SYSTEM_TEXT("\"s))\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("{\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += StringUtility::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container = std::make_shared<"s);
        content += value;
        content += SYSTEM_TEXT("Container>(jsonRow);\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("}\n"s);

        firstData = false;
    }

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s);
    content += nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::Verify() const\n"s);
    content += SYSTEM_TEXT("{\n"s);

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("if (!");
        content += StringUtility::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container)\n"s);

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("{\n"s);

        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringUtility::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("表不存在。\"s))\n"s);

        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("}\n"s);

        content += SYSTEM_TEXT("\n"s);
    }

    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("#ifdef OPEN_CLASS_INVARIANT\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("bool "s);
    content += nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::IsValid() const noexcept\n"s);
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("if ("s);

    index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += SYSTEM_TEXT("        "s);
        }

        content += StringUtility::ToFirstLetterLower(value);
        content += TextParsing::gContainer;

        if (index == boost::numeric_cast<int>(dataType.size()) - 1)
        {
            content += SYSTEM_TEXT(")\n"s);
        }
        else
        {
            content += SYSTEM_TEXT(" &&\n"s);
        }

        ++index;
    }

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("return true;\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("}\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("else\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::gIndentation;
    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("return false;\n"s);

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("}\n"s);

    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("#endif  // OPEN_CLASS_INVARIANT\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::JsonTotalGenerateImpl::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::gContainer.data();

    String content{ TextParsing::gIndentation };
    content += SYSTEM_TEXT("private:\n"s);

    std::set<String> dataType{};

    for (const auto& value : jsonHeadContainer)
    {
        dataType.emplace(value.GetJsonClassName());
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::gIndentation;
        content += TextParsing::gIndentation;
        content += SYSTEM_TEXT("std::shared_ptr<const "s);
        content += value;
        content += SYSTEM_TEXT("Container> ");
        content += StringUtility::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container;\n");
    }

    content += TextParsing::gIndentation;
    content += SYSTEM_TEXT("};\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}
