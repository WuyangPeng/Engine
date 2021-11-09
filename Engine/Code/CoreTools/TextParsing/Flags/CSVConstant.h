///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.5 (2021/11/01 11:08)

#ifndef CORE_TOOLS_TEXT_PARSING_CSV_CONSTANT_H
#define CORE_TOOLS_TEXT_PARSING_CSV_CONSTANT_H

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
    namespace TextParsing
    {
        constexpr auto g_BackSlash = SYSTEM_TEXT('\\');
        constexpr auto g_ForwardSlash = SYSTEM_TEXT('/');
        constexpr auto g_Dot = SYSTEM_TEXT('.');
        constexpr auto g_NewlineCharacter = SYSTEM_TEXT('\n');
        constexpr auto g_Space = SYSTEM_TEXT(' ');
        constexpr auto g_Colon = SYSTEM_TEXT(':');
        constexpr auto g_equalSign = SYSTEM_TEXT('=');

        constexpr System::StringView g_XlsxExtension{ SYSTEM_TEXT(".xlsx") };
        constexpr System::StringView g_CsvExtension{ SYSTEM_TEXT(".csv") };

        constexpr System::StringView g_EnumIDDescribe{ SYSTEM_TEXT("id") };
        constexpr System::StringView g_EnumNameDescribe{ SYSTEM_TEXT("name") };
        constexpr System::StringView g_EnumDescribe{ SYSTEM_TEXT("describe") };
        constexpr System::StringView g_IOStream{ SYSTEM_TEXT("iostream") };

        constexpr System::StringView g_Newline{ SYSTEM_TEXT("\r\n") };
        constexpr System::StringView g_ClassEndBrackets{ SYSTEM_TEXT("    };\n") };
        constexpr System::StringView g_FunctionBeginBrackets{ SYSTEM_TEXT("{\n") };
        constexpr System::StringView g_FunctionEndBrackets{ SYSTEM_TEXT("}\n") };
        constexpr System::StringView g_Comma{ SYSTEM_TEXT(",") };
        constexpr System::StringView g_Or{ SYSTEM_TEXT("|") };
        constexpr System::StringView g_QuotationMarks{ SYSTEM_TEXT("\"") };
        constexpr System::StringView g_Indentation{ SYSTEM_TEXT("    ") };
        constexpr System::StringView g_MemberIndentation{ SYSTEM_TEXT("      ") };
        constexpr System::StringView g_DoubleColon{ SYSTEM_TEXT("::") };
        constexpr System::StringView g_SemicolonNewline{ SYSTEM_TEXT(";\n") };
        constexpr System::StringView g_RightBracket{ SYSTEM_TEXT(")\n") };
        constexpr System::StringView g_KeySplit{ SYSTEM_TEXT("+-*/&|^=<> ") };
        constexpr System::StringView g_FileSplit{ SYSTEM_TEXT("/\\") };

        constexpr System::StringView g_HeadFileExtensionName{ SYSTEM_TEXT(".h") };
        constexpr System::StringView g_SourceFileExtensionName{ SYSTEM_TEXT(".cpp") };
        constexpr System::StringView g_DetailHeadFileExtensionName{ SYSTEM_TEXT("Detail.h") };

        constexpr System::StringView g_False{ SYSTEM_TEXT("false") };
        constexpr System::StringView g_EnumFilePrefix{ SYSTEM_TEXT("/Flags/") };
        constexpr System::StringView g_Container{ SYSTEM_TEXT("Container") };
        constexpr System::StringView g_CoreToolsHeadFile{ SYSTEM_TEXT("#include \"CoreTools/CoreToolsDll.h\"\n") };
        constexpr System::StringView g_IncludePrefix{ SYSTEM_TEXT("#include \"") };
        constexpr System::StringView g_HeadFileSuffix{ SYSTEM_TEXT(".h\"\n") };
        constexpr System::StringView g_UnicodeUsing{ SYSTEM_TEXT("#include \"System/Helper/UnicodeUsing.h\"\n") };
        constexpr System::StringView g_Deque{ SYSTEM_TEXT("#include <deque>\n") };
        constexpr System::StringView g_Memory{ SYSTEM_TEXT("#include <memory>\n") };
        constexpr System::StringView g_Vector{ SYSTEM_TEXT("#include <vector>\n") };
        constexpr System::StringView g_Map{ SYSTEM_TEXT("#include <map>\n") };
        constexpr System::StringView g_UnorderedMap{ SYSTEM_TEXT("#include <unordered_map>\n") };
        constexpr System::StringView g_UserClassInvariantMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h\"\n") };
        constexpr System::StringView g_ExceptionMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/ExceptionMacro.h\"\n") };
        constexpr System::StringView g_Public{ SYSTEM_TEXT("public:\n") };
        constexpr System::StringView g_Private{ SYSTEM_TEXT("private:\n") };
        constexpr System::StringView g_Class{ SYSTEM_TEXT("class ") };
        constexpr System::StringView g_ClassType{ SYSTEM_TEXT("using ClassType = ") };
        constexpr System::StringView g_ClassInvariantVirtualDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_VIRTUAL_DECLARE;\n") };
        constexpr System::StringView g_ClassInvariantFinalDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_FINAL_DECLARE;\n") };
        constexpr System::StringView g_ClassInvariantDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_DECLARE;\n") };
        constexpr System::StringView g_UserSelfClassIsValid9{ SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_9;\n") };
        constexpr System::StringView g_UserSelfClassIsValid1{ SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_1;\n") };
        constexpr System::StringView g_UserClassIsValidConst9{ SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_9;\n") };
        constexpr System::StringView g_UserClassIsValidConst1{ SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_1;\n") };

        constexpr std::string_view g_DefaultCellAddress{ "A1" };
        constexpr std::string_view g_SheetData{ "sheetData" };
        constexpr std::string_view g_Columns{ "cols" };
        constexpr std::string_view g_Column{ "col" };
        constexpr std::string_view g_Min{ "min" };
        constexpr std::string_view g_Max{ "max" };
        constexpr std::string_view g_Width{ "width" };
        constexpr std::string_view g_CustomWidth{ "customWidth" };
        constexpr std::string_view g_SheetPr{ "sheetPr" };
        constexpr std::string_view g_TabColor{ "tabColor" };
        constexpr std::string_view g_SheetViews{ "sheetViews" };
        constexpr std::string_view g_TabSelected{ "tabSelected" };
        constexpr std::string_view g_RGB{ "rgb" };
        constexpr std::string_view g_Dimension{ "dimension" };
        constexpr std::string_view g_Ref{ "ref" };
        constexpr std::string_view g_AttributeR{ "r" };
        constexpr std::string_view g_ChildC{ "c" };
        constexpr std::string_view g_Sheets{ "sheets" };
        constexpr std::string_view g_Name{ "name" };
        constexpr std::string_view g_RID{ "r:id" };
        constexpr std::string_view g_X1{ "xl/" };
        constexpr std::string_view g_Worksheets{ "/xl/worksheets/sheet" };
        constexpr std::string_view g_XML{ ".xml" };
        constexpr std::string_view g_SheetID{ "sheetId" };
        constexpr std::string_view g_Sheet{ "sheet" };
        constexpr std::string_view g_State{ "state" };
        constexpr std::string_view g_DefinedNames{ "definedNames" };
        constexpr std::string_view g_LocalSheetID{ "localSheetId" };
        constexpr std::string_view g_ID{ "Id" };
        constexpr std::string_view g_Target{ "Target" };
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_CSV_CONSTANT_H