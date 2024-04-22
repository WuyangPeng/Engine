/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 13:21)

#ifndef CORE_TOOLS_TEXT_PARSING_TEXT_PARSING_CONSTANT_H
#define CORE_TOOLS_TEXT_PARSING_TEXT_PARSING_CONSTANT_H

#include "System/Helper/UnicodeUsing.h"

namespace CoreTools::TextParsing
{
    constexpr auto gDot = SYSTEM_TEXT('.');
    constexpr auto gColon = SYSTEM_TEXT(':');
    constexpr auto gSpace = SYSTEM_TEXT(' ');
    constexpr auto gLeftBrace = SYSTEM_TEXT('{');
    constexpr auto gRightBrace = SYSTEM_TEXT('}');
    constexpr auto gBackSlash = SYSTEM_TEXT('\\');
    constexpr auto gForwardSlash = SYSTEM_TEXT('/');
    constexpr auto gLeftBrackets = SYSTEM_TEXT('(');
    constexpr auto gRightBrackets = SYSTEM_TEXT(')');
    constexpr auto gLeftAngleBracket = SYSTEM_TEXT('<');
    constexpr auto gRightAngleBracket = SYSTEM_TEXT('>');
    constexpr auto gNewlineCharacter = SYSTEM_TEXT('\n');
    constexpr auto gLeftSquareBrackets = SYSTEM_TEXT('[');
    constexpr auto gRightSquareBrackets = SYSTEM_TEXT(']');

    constexpr System::StringView gCsvExtension{ SYSTEM_TEXT(".csv") };
    constexpr System::StringView gXlsxExtension{ SYSTEM_TEXT(".xlsx") };

    constexpr System::StringView gIs{ SYSTEM_TEXT("Is") };
    constexpr System::StringView gIdSmall{ SYSTEM_TEXT("id") };
    constexpr System::StringView gIdCapital{ SYSTEM_TEXT("Id") };
    constexpr System::StringView gEnumName{ SYSTEM_TEXT("name") };
    constexpr System::StringView gEnumDescribe{ SYSTEM_TEXT("describe") };

    constexpr System::StringView gOr{ SYSTEM_TEXT("|") };
    constexpr System::StringView gAnd{ SYSTEM_TEXT("&") };
    constexpr System::StringView gComma{ SYSTEM_TEXT(",") };
    constexpr System::StringView gLess{ SYSTEM_TEXT(" < ") };
    constexpr System::StringView gEqualSign{ SYSTEM_TEXT("=") };
    constexpr System::StringView gGreater{ SYSTEM_TEXT(" > ") };
    constexpr System::StringView gNewline{ SYSTEM_TEXT("\r\n") };
    constexpr System::StringView gFileSplit{ SYSTEM_TEXT("/\\") };
    constexpr System::StringView gDoubleColon{ SYSTEM_TEXT("::") };
    constexpr System::StringView gLessEqual{ SYSTEM_TEXT(" <= ") };
    constexpr System::StringView gStringComma{ SYSTEM_TEXT("\\,") };
    constexpr System::StringView gGreaterEqual{ SYSTEM_TEXT(" >= ") };
    constexpr System::StringView gQuotationMarks{ SYSTEM_TEXT("\"") };
    constexpr System::StringView gExpressionAnd{ SYSTEM_TEXT(") && (") };
    constexpr System::StringView gKeySplit{ SYSTEM_TEXT("+-*/&|^=<> ") };
    constexpr System::StringView gFunctionBeginBrackets{ SYSTEM_TEXT("{\n") };
    constexpr System::StringView gScopeExpressionSplit{ SYSTEM_TEXT("()[]<>=-  ") };

    constexpr System::StringView gHeadFileExtensionName{ SYSTEM_TEXT(".h") };
    constexpr System::StringView gSourceFileExtensionName{ SYSTEM_TEXT(".cpp") };
    constexpr System::StringView gFwdHeadFileExtensionName{ SYSTEM_TEXT("Fwd.h") };
    constexpr System::StringView gDetailHeadFileExtensionName{ SYSTEM_TEXT("Detail.h") };
    constexpr System::StringView gContainerHeadFileExtensionName{ SYSTEM_TEXT("Container.h") };
    constexpr System::StringView gContainerSourceFileExtensionName{ SYSTEM_TEXT("Container.cpp") };

    constexpr System::StringView gMapInclude{ SYSTEM_TEXT("#include <map>\n") };
    constexpr System::StringView gMemoryInclude{ SYSTEM_TEXT("#include <memory>\n") };
    constexpr System::StringView gVectorInclude{ SYSTEM_TEXT("#include <vector>\n") };
    constexpr System::StringView gUnorderedMapInclude{ SYSTEM_TEXT("#include <unordered_map>\n") };

    constexpr System::StringView gGet{ SYSTEM_TEXT("Get") };
    constexpr System::StringView gBase{ SYSTEM_TEXT("Base") };
    constexpr System::StringView gTrue{ SYSTEM_TEXT("true") };
    constexpr System::StringView gFalse{ SYSTEM_TEXT("false") };
    constexpr System::StringView gDeque{ SYSTEM_TEXT("deque") };
    constexpr System::StringView gMemory{ SYSTEM_TEXT("memory") };
    constexpr System::StringView gVector{ SYSTEM_TEXT("vector") };
    constexpr System::StringView gGetEnum{ SYSTEM_TEXT("GetEnum") };
    constexpr System::StringView gStdName{ SYSTEM_TEXT("StdName") };
    constexpr System::StringView gStdType{ SYSTEM_TEXT("StdType") };
    constexpr System::StringView gContainer{ SYSTEM_TEXT("Container") };
    constexpr System::StringView gNamespace{ SYSTEM_TEXT("namespace") };
    constexpr System::StringView gVectorName{ SYSTEM_TEXT("VectorName") };
    constexpr System::StringView gMappingType{ SYSTEM_TEXT("MappingType") };
    constexpr System::StringView gElementType{ SYSTEM_TEXT("ElementType") };
    constexpr System::StringView gElementName{ SYSTEM_TEXT("ElementName") };
    constexpr System::StringView gCSVNameSpace{ SYSTEM_TEXT("CSVConfigure") };
    constexpr System::StringView gSmallElementType{ SYSTEM_TEXT("SmallElementType") };
    constexpr System::StringView gSmallElementName{ SYSTEM_TEXT("SmallElementName") };
    constexpr System::StringView gElementIsNoexcept{ SYSTEM_TEXT("ElementIsNoexcept") };
    constexpr System::StringView gElementDefaultValue{ SYSTEM_TEXT("ElementDefaultValue") };
    constexpr System::StringView gCheckingTypeCondition{ SYSTEM_TEXT("CheckingTypeCondition") };

    constexpr System::StringView gIfNdef{ SYSTEM_TEXT("#ifndef ") };
    constexpr System::StringView gDefine{ SYSTEM_TEXT("#define ") };
    constexpr System::StringView gEndif{ SYSTEM_TEXT("#endif  // ") };
    constexpr System::StringView gEnumFilePrefix{ SYSTEM_TEXT("/Flags/") };

    constexpr std::string_view gId{ "Id" };
    constexpr std::string_view gX1{ "xl/" };
    constexpr std::string_view gRef{ "ref" };
    constexpr std::string_view gRgb{ "rgb" };
    constexpr std::string_view gMin{ "min" };
    constexpr std::string_view gMax{ "max" };
    constexpr std::string_view gXML{ ".xml" };
    constexpr std::string_view gRId{ "r:id" };
    constexpr std::string_view gChildC{ "c" };
    constexpr std::string_view gName{ "name" };
    constexpr std::string_view gColumn{ "col" };
    constexpr std::string_view gSheet{ "sheet" };
    constexpr std::string_view gState{ "state" };
    constexpr std::string_view gWidth{ "width" };
    constexpr std::string_view gAttributeR{ "r" };
    constexpr std::string_view gColumns{ "cols" };
    constexpr std::string_view gSheets{ "sheets" };
    constexpr std::string_view gTarget{ "Target" };
    constexpr std::string_view gSheetPr{ "sheetPr" };
    constexpr std::string_view gSheetId{ "sheetId" };
    constexpr std::string_view gTabColor{ "tabColor" };
    constexpr std::string_view gSheetData{ "sheetData" };
    constexpr std::string_view gDimension{ "dimension" };
    constexpr std::string_view gDefaultCellAddress{ "A1" };
    constexpr std::string_view gSheetViews{ "sheetViews" };
    constexpr std::string_view gTabSelected{ "tabSelected" };
    constexpr std::string_view gCustomWidth{ "customWidth" };
    constexpr std::string_view gDefinedNames{ "definedNames" };
    constexpr std::string_view gLocalSheetId{ "localSheetId" };
    constexpr std::string_view gWorksheets{ "/xl/worksheets/sheet" };
}

#endif  // CORE_TOOLS_TEXT_PARSING_TEXT_PARSING_CONSTANT_H