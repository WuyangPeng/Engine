///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/10/23 22:12)

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

#include <map>
#include <set>

using namespace std::literals;
using std::map;
using std::set;
using std::vector;

CoreTools::CSVTotalGenerateImpl::CSVTotalGenerateImpl(const String& nameSpace, const CSVHeadContainer& csvHeadContainer)
    : nameSpace{ nameSpace }, csvHeadContainer{ csvHeadContainer }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVTotalGenerateImpl)

System::String CoreTools::CSVTotalGenerateImpl::GenerateCopyright() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return String{ SYSTEM_TEXT(
        "/// Copyright (c) 2010-\n"
        "/// Threading Core Render Engine\n"
        "///\n"
        "/// 作者：彭武阳，彭晔恩，彭晔泽\n"
        "/// 联系作者：94458936@qq.com\n"
        "///\n"
        "/// 标准：std:c++17\n"
        "/// 自动生成\n") };
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNewLine() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT("\n"s);
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + GetFileSuffix());

    return SYSTEM_TEXT("#ifndef "s) + headerGuard + SYSTEM_TEXT("\n"s) +
           SYSTEM_TEXT("#define "s) + headerGuard + SYSTEM_TEXT("\n"s) +
           SYSTEM_TEXT("\n"s);
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHeaderGuard() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + nameSpace + GetFileSuffix());

    return SYSTEM_TEXT("#ifndef "s) + headerGuard + SYSTEM_TEXT("\n"s) +
           SYSTEM_TEXT("#define "s) + headerGuard + SYSTEM_TEXT("\n"s) +
           SYSTEM_TEXT("\n"s);
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHeaderGuardEndif() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto headerGuard = StringConversion::ToUpperMacro(nameSpace + GetFileSuffix());

    return SYSTEM_TEXT("#endif  // "s) + headerGuard + SYSTEM_TEXT("\n"s);
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    vector<String> enumType{};
    map<String, CSVHead> dataType{};

    for (const auto& value : csvHeadContainer)
    {
        if (value.GetCSVFormatType() == CSVFormatType::Enum)
        {
            enumType.emplace_back(value.GetCSVClassName());
        }
        else
        {
            dataType.emplace(value.GetCSVClassName(), value);
        }
    }

    for (const auto& value : enumType)
    {
        content += SYSTEM_TEXT("#include \"Flags/"s) + value + SYSTEM_TEXT(".h\"\n"s);
    }

    if (!enumType.empty())
    {
        content += SYSTEM_TEXT("\n"s);
    }

    for (const auto& value : dataType)
    {
        content += SYSTEM_TEXT("#include \""s) + value.first + SYSTEM_TEXT(".h\"\n"s);

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += SYSTEM_TEXT("#include \""s) + value.first + SYSTEM_TEXT("Base.h\"\n"s);
        }

        if (value.second.GetCSVFormatType() == CSVFormatType::Unique)
        {
            content += SYSTEM_TEXT("#include \""s) + value.first + SYSTEM_TEXT("Container.h\"\n"s);
        }
        else
        {
            content += SYSTEM_TEXT("#include \""s) + value.first + SYSTEM_TEXT("ContainerDetail.h\"\n"s);
        }
    }

    if (!dataType.empty())
    {
        content += SYSTEM_TEXT("\n"s);
    }

    content += SYSTEM_TEXT("#include \""s) + nameSpace + SYSTEM_TEXT("Container.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwdHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("#include \"CoreTools/TextParsing/TextParsingFwd.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("#include \"CoreTools/CoreToolsDll.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("#include \"") + nameSpace + SYSTEM_TEXT("Fwd.h\"\n"s);
    content += SYSTEM_TEXT("#include \"System/Helper/UnicodeUsing.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("#include <memory>\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerSourceHead() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto content = SYSTEM_TEXT("#include \""s) + nameSpace + SYSTEM_TEXT("Container.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

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
        content += SYSTEM_TEXT("#include \""s) + value + SYSTEM_TEXT("Container.h\"\n");
    }

    content += SYSTEM_TEXT("#include \"CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/Helper/ExceptionMacro.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVContent.h\"\n"s);
    content += SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSVHead.h\"\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("#include <filesystem>\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("using std::make_shared;\n"s);
    content += SYSTEM_TEXT("using std::shared_ptr;\n"s);
    content += SYSTEM_TEXT("using namespace std::literals;\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateNameSpace() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return SYSTEM_TEXT("namespace "s) + nameSpace + SYSTEM_TEXT("\n") + SYSTEM_TEXT("{\n");
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateFwd() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    String content{};

    set<String> enumType{};
    map<String, CSVHead> dataType{};

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

    for (const auto& value : enumType)
    {
        content += SYSTEM_TEXT("    enum class "s) + value + SYSTEM_TEXT(";\n"s);
    }

    if (!enumType.empty())
    {
        content += SYSTEM_TEXT("\n"s);
    }

    for (const auto& value : dataType)
    {
        content += SYSTEM_TEXT("    class "s) + value.first + SYSTEM_TEXT(";\n"s);

        if (value.second.GetCSVFormatType() == CSVFormatType::Default ||
            value.second.GetCSVFormatType() == CSVFormatType::Vector ||
            value.second.GetCSVFormatType() == CSVFormatType::Key)
        {
            content += SYSTEM_TEXT("    class "s) + value.first + SYSTEM_TEXT("Base;\n"s);
        }

        content += SYSTEM_TEXT("    class "s) + value.first + SYSTEM_TEXT("Container;\n"s);
    }

    if (!dataType.empty())
    {
        content += SYSTEM_TEXT("\n"s);
    }

    content += SYSTEM_TEXT("    class "s) + nameSpace + SYSTEM_TEXT("Container;\n"s);

    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerClassName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    auto content = SYSTEM_TEXT("    class "s) + className + SYSTEM_TEXT(" final\n"s);
    content += SYSTEM_TEXT("    {\n"s);
    content += SYSTEM_TEXT("    public:\n"s);
    content += SYSTEM_TEXT("        using ClassType = "s) + className + SYSTEM_TEXT(";\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    auto content = SYSTEM_TEXT("    public:\n"s);
    content += SYSTEM_TEXT("        explicit "s) + className + SYSTEM_TEXT("(const System::String& directory);\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("        CLASS_INVARIANT_DECLARE;\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerFunction() const
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
        content += SYSTEM_TEXT("        NODISCARD std::shared_ptr<const "s) + value + SYSTEM_TEXT("Container> Get");
        content += value + SYSTEM_TEXT("Container() const noexcept;\n");
    }

    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("    private:\n"s);
    content += SYSTEM_TEXT("        void Parsing(const System::String& directory);\n"s);
    content += SYSTEM_TEXT("        void Verify();\n"s);
    content += SYSTEM_TEXT("\n"s);

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
        content += SYSTEM_TEXT("shared_ptr<const ") + nameSpace + SYSTEM_TEXT("::") + value + SYSTEM_TEXT("Container> ");
        content += nameSpace + SYSTEM_TEXT("::") + className + SYSTEM_TEXT("::Get") + value + SYSTEM_TEXT("Container() const noexcept\n");
        content += SYSTEM_TEXT("{\n");
        content += SYSTEM_TEXT("    USER_CLASS_IS_VALID_CONST_1;\n");
        content += SYSTEM_TEXT("\n");
        content += SYSTEM_TEXT("    return ") + StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container;\n");
        content += SYSTEM_TEXT("}\n");
        content += SYSTEM_TEXT("\n");
    }

    return content;
}

System::String CoreTools::CSVTotalGenerateImpl::GenerateContainerDefaultFunctionDefinition() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = nameSpace + SYSTEM_TEXT("Container"s);

    auto content = nameSpace + SYSTEM_TEXT("::"s) + className + SYSTEM_TEXT("::"s) + className + SYSTEM_TEXT("(const System::String& directory)\n"s);

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
    content += SYSTEM_TEXT("    Parsing(directory);\n"s);
    content += SYSTEM_TEXT("    Verify();\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("    USER_SELF_CLASS_IS_VALID_1;\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s) + nameSpace + SYSTEM_TEXT("::"s) + className + SYSTEM_TEXT("::Parsing(const System::String& directory)\n"s);
    content += SYSTEM_TEXT("{\n"s);
    content += SYSTEM_TEXT("    std::filesystem::path path{ directory };\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("    for (const auto& inputPath : std::filesystem::directory_iterator(path))\n"s);
    content += SYSTEM_TEXT("    {\n"s);
    content += SYSTEM_TEXT("        auto fileName = inputPath.path().native();\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("        if (fileName.find(SYSTEM_TEXT(\".csv\"s)) != (fileName.size() - 4))\n"s);
    content += SYSTEM_TEXT("        {\n"s);
    content += SYSTEM_TEXT("            continue;\n"s);
    content += SYSTEM_TEXT("        }\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("        CoreTools::CSVContent csvContent{ fileName };\n"s);
    content += SYSTEM_TEXT("\n"s);
    content += SYSTEM_TEXT("        auto csvClassName = csvContent.GetCSVClassName();\n"s);
    content += SYSTEM_TEXT("\n"s);

    auto firstData = true;
    for (const auto& value : dataType)
    {
        if (firstData)
        {
            content += SYSTEM_TEXT("        "s);
        }
        else
        {
            content += SYSTEM_TEXT("        else "s);
        }
        content += SYSTEM_TEXT("if (csvClassName == SYSTEM_TEXT(\"") + value + SYSTEM_TEXT("\"s))\n"s);
        content += SYSTEM_TEXT("        {\n"s);
        content += SYSTEM_TEXT("            "s) + StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container = make_shared<"s) + value + SYSTEM_TEXT("Container>(csvContent);\n"s);
        content += SYSTEM_TEXT("        }\n"s);

        firstData = false;
    }

    content += SYSTEM_TEXT("    }\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("void "s) + nameSpace + SYSTEM_TEXT("::"s) + className + SYSTEM_TEXT("::Verify()\n"s);
    content += SYSTEM_TEXT("{\n"s);

    for (const auto& value : dataType)
    {
        content += SYSTEM_TEXT("    if (!") + StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container)\n"s);
        content += SYSTEM_TEXT("    {\n"s);
        content += SYSTEM_TEXT("        THROW_EXCEPTION(SYSTEM_TEXT(\""s) + StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("表不存在\"s));\n"s);
        content += SYSTEM_TEXT("    }\n"s);

        content += SYSTEM_TEXT("\n"s);
    }

    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("#ifdef OPEN_CLASS_INVARIANT\n"s);
    content += SYSTEM_TEXT("\n"s);

    content += SYSTEM_TEXT("bool "s) + nameSpace + SYSTEM_TEXT("::"s) + className + SYSTEM_TEXT("::IsValid() const noexcept\n"s);
    content += SYSTEM_TEXT("{\n"s);

    content += SYSTEM_TEXT("    if ("s);

    index = 0;
    for (const auto& value : dataType)
    {
        if (index != 0)
        {
            content += SYSTEM_TEXT("        "s);
        }

        content += StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container"s);

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

    content += SYSTEM_TEXT("    {\n"s);
    content += SYSTEM_TEXT("        return true;\n"s);
    content += SYSTEM_TEXT("    }\n"s);

    content += SYSTEM_TEXT("    else\n"s);
    content += SYSTEM_TEXT("    {\n"s);
    content += SYSTEM_TEXT("        return false;\n"s);
    content += SYSTEM_TEXT("    }\n"s);

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

    auto content = SYSTEM_TEXT("    private:\n"s);

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
        content += SYSTEM_TEXT("        std::shared_ptr<const "s) + value + SYSTEM_TEXT("Container> ");
        content += StringConversion::ToFirstLetterLower(value) + SYSTEM_TEXT("Container;\n");
    }

    content += SYSTEM_TEXT("    };\n"s);
    content += SYSTEM_TEXT("}\n"s);
    content += SYSTEM_TEXT("\n"s);

    return content;
}

void CoreTools::CSVTotalGenerateImpl::GenerateFile(const String& directory) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto fileName = directory + SYSTEM_TEXT("/"s) + nameSpace + GetFileSuffix();

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
