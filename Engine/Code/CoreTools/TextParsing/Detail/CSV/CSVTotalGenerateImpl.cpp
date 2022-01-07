///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 21:05)

#include "CoreTools/CoreToolsExport.h"

#include "CSVTotalGenerateImpl.h"
#include "System/Helper/PragmaWarning/Algorithm.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/FileManager/FileManagerHelper.h"
#include "CoreTools/FileManager/IFStreamManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

#include <map>
#include <set>

using std::map;
using std::set;
using std::vector;
using namespace std::literals;

CoreTools::CSVTotalGenerateImpl::CSVTotalGenerateImpl(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : nameSpace{ nameSpace }, csvHeadContainer{ csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerateImpl)

void CoreTools::CSVTotalGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto fileName = directory + TextParsing::g_ForwardSlash + nameSpace + GetFileSuffix();

    const auto oldContent = GetOldContent(fileName);
    const auto newContent = GetContent();

    if (oldContent != newContent)
    {
        const auto result = StringConversion::StandardConversionMultiByte(newContent);

        FileManagerHelper::SaveIntoFile(fileName, true, boost::numeric_cast<int>(result.size()), result.c_str());
    }
}

System::String CoreTools::CSVTotalGenerateImpl::GetOldContent(const String& fileName) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    try
    {
        IFStreamManager iFStreamManager{ fileName };

        iFStreamManager.SetSimplifiedChinese();

        return iFStreamManager.GetFileContent();
    }
    catch (const CoreTools::Error&)
    {
        // 文件不存在是正常的。
        return String{};
    }
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateCopyright() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("/// Copyright (c) 2010-\n"s);

    content += SYSTEM_TEXT("/// Threading Core Render Engine\n"s);
    content += TextParsing::g_Annotation;
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("/// 作者：彭武阳，彭晔恩，彭晔泽\n"s);
    content += SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n"s);
    content += TextParsing::g_Annotation;
    content += TextParsing::g_NewlineCharacter;

    content += SYSTEM_TEXT("/// 标准：std:c++17\n"s);
    content += SYSTEM_TEXT("/// 自动生成\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNewLine() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return TextParsing::g_Newline.data();
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::g_Ifndef };

    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Define;
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + nameSpace + GetFileSuffix());

    String content{ TextParsing::g_Ifndef };

    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Define;
    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + GetFileSuffix());

    String content{ TextParsing::g_Endif };

    content += headerGuard;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    EnumType enumType{};
    DataType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace(value.GetCSVClassName());
        }
        else
        {
            dataType.emplace(value.GetCSVClassName(), value);
        }
    }

    auto content = GenerateEnumHead(enumType);
    content += GenerateDataHead(dataType);

    content += TextParsing::g_IncludePrefix;
    content += nameSpace;
    content += TextParsing::g_Container;
    content += TextParsing::g_HeadFileSuffix;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateEnumHead(const EnumType& enumType) const
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::g_IncludePrefix;
        content += TextParsing::g_Flags;
        content += TextParsing::g_ForwardSlash;
        content += value;
        content += TextParsing::g_HeadFileSuffix;
    }

    if (!enumType.empty())
    {
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateDataHead(const DataType& dataType) const
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::g_IncludePrefix;
        content += value.first;
        content += TextParsing::g_HeadFileSuffix;

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += TextParsing::g_IncludePrefix;
            content += value.first;
            content += TextParsing::g_Base;
            content += TextParsing::g_HeadFileSuffix;
        }

        if (value.second.GetCSVFormatType() == CSVFormatType::Unique)
        {
            content += TextParsing::g_IncludePrefix;
            content += value.first;
            content += TextParsing::g_Container;
            content += TextParsing::g_HeadFileSuffix;
        }
        else
        {
            content += TextParsing::g_IncludePrefix;
            content += value.first;
            content += TextParsing::g_Container;
            content += TextParsing::g_HeadDetailFileSuffix;
        }
    }

    if (!dataType.empty())
    {
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwdHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_TextParsingFwd };

    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_CoreToolsHeadFile };

    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_IncludePrefix;
    content += nameSpace;
    content += TextParsing::g_Fwd;
    content += TextParsing::g_HeadFileSuffix;

    content += TextParsing::g_UnicodeUsing;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Memory;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_IncludePrefix };

    content += nameSpace;
    content += TextParsing::g_Container;
    content += TextParsing::g_HeadFileSuffix;
    content += TextParsing::g_NewlineCharacter;

    set<String> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::g_IncludePrefix;
        content += value;
        content += TextParsing::g_Container;
        content += TextParsing::g_HeadFileSuffix;
    }

    content += TextParsing::g_UserClassInvariantMacro;
    content += TextParsing::g_ExceptionMacro;
    content += TextParsing::g_IncludeCSVContent;
    content += TextParsing::g_IncludeCSVHead;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Filesystem;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_UsingMakeShared;
    content += TextParsing::g_UsingSharedPtr;
    content += TextParsing::g_UsingNamespaceLiterals;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{ TextParsing::g_Namespace };

    content += nameSpace;
    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_FunctionBeginBrackets;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateEnumFwd(const EnumType& enumType) const
{
    String content{};

    for (const auto& value : enumType)
    {
        content += TextParsing::g_Indentation;
        content += TextParsing::g_EnumClass;
        content += value;
        content += TextParsing::g_SemicolonNewline;
    }

    if (!enumType.empty())
    {
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateDataFwd(const DataType& dataType) const
{
    String content{};

    for (const auto& value : dataType)
    {
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Class;
        content += value.first;
        content += TextParsing::g_SemicolonNewline;

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Class;
            content += value.first;
            content += TextParsing::g_Base;
            content += TextParsing::g_SemicolonNewline;
        }

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Class;
        content += value.first;
        content += TextParsing::g_Container;
        content += TextParsing::g_SemicolonNewline;
    }

    if (!dataType.empty())
    {
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    EnumType enumType{};
    DataType dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace(value.GetCSVClassName());
        }
        else
        {
            dataType.emplace(value.GetCSVClassName(), value);
        }
    }

    content += GenerateEnumFwd(enumType);
    content += GenerateDataFwd(dataType);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Class;
    content += nameSpace;
    content += TextParsing::g_Container;
    content += TextParsing::g_SemicolonNewline;

    content += TextParsing::g_FunctionEndBrackets;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::g_Container.data();

    String content{ TextParsing::g_Indentation };

    content += TextParsing::g_Class;
    content += className;
    content += TextParsing::g_Final;
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_FunctionBeginBrackets;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_ClassType;
    content += className;
    content += TextParsing::g_SemicolonNewline;
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::g_Container.data();

    String content{ TextParsing::g_Indentation };

    content += TextParsing::g_Public;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const System::String& directory);\n"s);
    content += TextParsing::g_NewlineCharacter;

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("CLASS_INVARIANT_DECLARE;\n"s);
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + TextParsing::g_Container.data();

    String content{};

    set<String> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("NODISCARD std::shared_ptr<const "s);
        content += value;
        content += SYSTEM_TEXT("Container> Get");
        content += value;
        content += SYSTEM_TEXT("Container() const noexcept;\n");
    }

    content += TextParsing::g_NewlineCharacter;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("private:\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("void Parsing(const System::String& directory);\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("void Verify();\n"s);
    content += TextParsing::g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    String content{};

    set<String> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += SYSTEM_TEXT("shared_ptr<const ");
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

        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_1;\n");
        content += TextParsing::g_NewlineCharacter;

        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("return ");
        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container;\n");

        content += SYSTEM_TEXT("}\n");
        content += TextParsing::g_NewlineCharacter;
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    auto content = nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("(const System::String& directory)\n"s);

    content += SYSTEM_TEXT("    : "s);

    set<String> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    auto index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += SYSTEM_TEXT("      "s);
        }

        content += StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container{}");

        if (index != boost::numeric_cast<int>(dataType.size()) - 1)
        {
            content += SYSTEM_TEXT(","s);
        }

        content += SYSTEM_TEXT("\n"s);

        ++index;
    }

    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("Parsing(directory);\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("Verify();\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_1;\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s);
    content += nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::Parsing(const System::String& directory)\n"s);

    content += SYSTEM_TEXT("{\n"s);
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("std::filesystem::path path{ directory };\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("for (const auto& inputPath : std::filesystem::directory_iterator(path))\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("auto fileName = inputPath.path().native();\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("if (fileName.find(SYSTEM_TEXT(\".csv\"s)) != (fileName.size() - 4))\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("continue;\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("CoreTools::CSVContent csvContent{ fileName };\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("auto csvClassName = csvContent.GetCSVClassName();\n"s);
    content += SYSTEM_TEXT("\n"s);

    auto firstData = true;
    for (const auto& value : dataType)
    {
        if (firstData)
        {
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
        }
        else
        {
            content += TextParsing::g_Indentation;
            content += TextParsing::g_Indentation;
            content += SYSTEM_TEXT("else "s);
        }
        content += SYSTEM_TEXT("if (csvClassName == SYSTEM_TEXT(\"");
        content += value;
        content += SYSTEM_TEXT("\"s))\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("{\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container = make_shared<"s);
        content += value;
        content += SYSTEM_TEXT("Container>(csvContent);\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("}\n"s);

        firstData = false;
    }

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s);
    content += nameSpace;
    content += SYSTEM_TEXT("::"s);
    content += className;
    content += SYSTEM_TEXT("::Verify()\n"s);
    content += SYSTEM_TEXT("{\n"s);

    for (const auto& value : dataType)
    {
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("if (!");
        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container)\n"s);

        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("{\n"s);

        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\""s);
        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("表不存在\"s));\n"s);

        content += TextParsing::g_Indentation;
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

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("if ("s);

    index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += SYSTEM_TEXT("        "s);
        }

        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container"s);

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

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("return true;\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("}\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("else\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("{\n"s);

    content += TextParsing::g_Indentation;
    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("return false;\n"s);

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("}\n"s);

    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("#endif  // OPEN_CLASS_INVARIANT\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerMember() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    String content{ TextParsing::g_Indentation };
    content += SYSTEM_TEXT("private:\n"s);

    set<String> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() != CSVFormatType::Enum)
        {
            dataType.emplace(value.GetCSVClassName());
        }
    }

    for (const auto& value : dataType)
    {
        content += TextParsing::g_Indentation;
        content += TextParsing::g_Indentation;
        content += SYSTEM_TEXT("std::shared_ptr<const "s);
        content += value;
        content += SYSTEM_TEXT("Container> ");
        content += StringConversion::ToFirstLetterLower(value);
        content += SYSTEM_TEXT("Container;\n");
    }

    content += TextParsing::g_Indentation;
    content += SYSTEM_TEXT("};\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}
