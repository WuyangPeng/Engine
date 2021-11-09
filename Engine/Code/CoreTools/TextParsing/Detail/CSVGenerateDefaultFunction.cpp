///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/03 16:08)

#include "CoreTools/CoreToolsExport.h"

#include "CSVGenerateDefaultFunction.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/Flags/CSVFlags.h"

using namespace std::literals;
using namespace CoreTools::TextParsing;

CoreTools::CSVGenerateDefaultFunction::CSVGenerateDefaultFunction(const CSVHead& csvHead, const String& suffix)
    : csvHead{ csvHead }, suffix{ suffix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CSVGenerateDefaultFunction)

System::String CoreTools::CSVGenerateDefaultFunction::GenerateBaseDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };

    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += className;
    content += SYSTEM_TEXT("() noexcept = default;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(int key) noexcept;\n"s);

    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("virtual ~"s);
    content += className;
    content += SYSTEM_TEXT("() noexcept = default;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += className;
    content += SYSTEM_TEXT("(const "s);
    content += className;
    content += SYSTEM_TEXT("& rhs) noexcept = default;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += className;
    content += SYSTEM_TEXT("& operator=(const "s);
    content += className;
    content += SYSTEM_TEXT("& rhs) noexcept = default;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += className;
    content += SYSTEM_TEXT("("s);
    content += className;
    content += SYSTEM_TEXT("&& rhs) noexcept = default;\n"s);

    content += g_Indentation;
    content += g_Indentation;
    content += className;
    content += SYSTEM_TEXT("& operator=("s);
    content += className;
    content += SYSTEM_TEXT("&& rhs) noexcept = default;\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassInvariantVirtualDeclare;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateChildDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };

    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVRow& csvRow);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassInvariantFinalDeclare;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };

    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVRow& csvRow);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassInvariantDeclare;
    content += g_NewlineCharacter;

    return content;
}

System::String CoreTools::CSVGenerateDefaultFunction::GenerateContainerDefaultFunction() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto className = csvHead.GetCSVClassName() + suffix;

    String content{ g_Indentation };

    content += g_Public;

    content += g_Indentation;
    content += g_Indentation;
    content += SYSTEM_TEXT("explicit "s);
    content += className;
    content += SYSTEM_TEXT("(const CoreTools::CSVContent& csvContent);\n"s);
    content += g_NewlineCharacter;

    content += g_Indentation;
    content += g_Indentation;
    content += g_ClassInvariantDeclare;
    content += g_NewlineCharacter;

    return content;
}
