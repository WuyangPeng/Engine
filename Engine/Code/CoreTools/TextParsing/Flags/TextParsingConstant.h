///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/25 19:19)

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
    constexpr System::StringView gIoStream{ SYSTEM_TEXT("iostream") };
    constexpr System::StringView gEnumDescribe{ SYSTEM_TEXT("describe") };

    constexpr System::StringView gOr{ SYSTEM_TEXT("|") };
    constexpr System::StringView gAnd{ SYSTEM_TEXT("&") };
    constexpr System::StringView gComma{ SYSTEM_TEXT(",") };
    constexpr System::StringView gInit{ SYSTEM_TEXT("{}") };
    constexpr System::StringView gLess{ SYSTEM_TEXT(" < ") };
    constexpr System::StringView gLeft{ SYSTEM_TEXT("<< ") };
    constexpr System::StringView gEqualSign{ SYSTEM_TEXT("=") };
    constexpr System::StringView gGreater{ SYSTEM_TEXT(" > ") };
    constexpr System::StringView gBrackets{ SYSTEM_TEXT("() ") };
    constexpr System::StringView gNewline{ SYSTEM_TEXT("\r\n") };
    constexpr System::StringView gFileSplit{ SYSTEM_TEXT("/\\") };
    constexpr System::StringView gDoubleColon{ SYSTEM_TEXT("::") };
    constexpr System::StringView gLessEqual{ SYSTEM_TEXT(" <= ") };
    constexpr System::StringView gAnnotation{ SYSTEM_TEXT("///") };
    constexpr System::StringView gStringComma{ SYSTEM_TEXT("\\,") };
    constexpr System::StringView gLambdaEnd{ SYSTEM_TEXT("});\n") };
    constexpr System::StringView gNotEqualSign{ SYSTEM_TEXT("!=") };
    constexpr System::StringView gAndNewline{ SYSTEM_TEXT(" &&\n") };
    constexpr System::StringView gIndentation{ SYSTEM_TEXT("    ") };
    constexpr System::StringView gGreaterEqual{ SYSTEM_TEXT(" >= ") };
    constexpr System::StringView gQuotationMarks{ SYSTEM_TEXT("\"") };
    constexpr System::StringView gGetNestedEnd{ SYSTEM_TEXT("\"s))) ") };
    constexpr System::StringView gExpressionAnd{ SYSTEM_TEXT(") && (") };
    constexpr System::StringView gKeySplit{ SYSTEM_TEXT("+-*/&|^=<> ") };
    constexpr System::StringView gSemicolonNewline{ SYSTEM_TEXT(";\n") };
    constexpr System::StringView gDoubleForwardSlash{ SYSTEM_TEXT("//") };
    constexpr System::StringView gClassEndBrackets{ SYSTEM_TEXT("};\n") };
    constexpr System::StringView gFunctionEndBrackets{ SYSTEM_TEXT("}\n") };
    constexpr System::StringView gInitSystemTextEnd{ SYSTEM_TEXT("\"s), ") };
    constexpr System::StringView gMemberIndentation{ SYSTEM_TEXT("      ") };
    constexpr System::StringView gFunctionBeginBrackets{ SYSTEM_TEXT("{\n") };
    constexpr System::StringView gSemicolonAnnotation{ SYSTEM_TEXT(";  // ") };
    constexpr System::StringView gSystemTextEndNewline{ SYSTEM_TEXT("\"s))\n") };
    constexpr System::StringView gScopeExpressionSplit{ SYSTEM_TEXT("()[]<>=-  ") };
    constexpr System::StringView gGetJsonRowContainerEnd{ SYSTEM_TEXT("\"s));\n") };
    constexpr System::StringView gRightAngleBracketSemicolonNewline{ SYSTEM_TEXT(">;\n") };

    constexpr System::StringView gHeadFileExtensionName{ SYSTEM_TEXT(".h") };
    constexpr System::StringView gSourceFileExtensionName{ SYSTEM_TEXT(".cpp") };
    constexpr System::StringView gFwdHeadFileExtensionName{ SYSTEM_TEXT("Fwd.h") };
    constexpr System::StringView gDetailHeadFileExtensionName{ SYSTEM_TEXT("Detail.h") };
    constexpr System::StringView gContainerHeadFileExtensionName{ SYSTEM_TEXT("Container.h") };
    constexpr System::StringView gContainerSourceFileExtensionName{ SYSTEM_TEXT("Container.cpp") };

    constexpr System::StringView gMapInclude{ SYSTEM_TEXT("#include <map>\n") };
    constexpr System::StringView gDequeInclude{ SYSTEM_TEXT("#include <deque>\n") };
    constexpr System::StringView gMemoryInclude{ SYSTEM_TEXT("#include <memory>\n") };
    constexpr System::StringView gVectorInclude{ SYSTEM_TEXT("#include <vector>\n") };
    constexpr System::StringView gIoStreamInclude{ SYSTEM_TEXT("#include <iostream>\n") };
    constexpr System::StringView gAlgorithmInclude{ SYSTEM_TEXT("#include <algorithm>\n") };
    constexpr System::StringView gFilesystemInclude{ SYSTEM_TEXT("#include <filesystem>\n") };
    constexpr System::StringView gUnorderedMapInclude{ SYSTEM_TEXT("#include <unordered_map>\n") };

    constexpr System::StringView gLogMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/LogMacro.h\"\n") };
    constexpr System::StringView gEnumMacro{ SYSTEM_TEXT("#include \"System/Helper/EnumOperator.h\"\n") };
    constexpr System::StringView gUnicodeUsing{ SYSTEM_TEXT("#include \"System/Helper/UnicodeUsing.h\"\n") };
    constexpr System::StringView gCoreToolsHeadFile{ SYSTEM_TEXT("#include \"CoreTools/CoreToolsDll.h\"\n") };
    constexpr System::StringView gExceptionMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/ExceptionMacro.h\"\n") };
    constexpr System::StringView gIncludeCSVRow{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSV/CSVRow.h\"\n") };
    constexpr System::StringView gIncludeCSVHead{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSV/CSVHead.h\"\n") };
    constexpr System::StringView gIncludeJsonRow{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonRow.h\"\n") };
    constexpr System::StringView gIncludeVector2{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector2.h\"\n") };
    constexpr System::StringView gIncludeVector3{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector3.h\"\n") };
    constexpr System::StringView gIncludeVector4{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/Vector4.h\"\n") };
    constexpr System::StringView gIncludeJsonHead{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Json/JsonHead.h\"\n") };
    constexpr System::StringView gTextParsingFwd{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/TextParsingFwd.h\"\n") };
    constexpr System::StringView gNumericCast{ SYSTEM_TEXT("#include \"System/Helper/PragmaWarning/NumericCast.h\"\n") };
    constexpr System::StringView gCSVRowDetail{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSV/CSVRowDetail.h\"\n") };
    constexpr System::StringView gIncludeCSVContent{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/CSV/CSVContent.h\"\n") };
    constexpr System::StringView gIncludeIntVector2{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector2.h\"\n") };
    constexpr System::StringView gIncludeIntVector3{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector3.h\"\n") };
    constexpr System::StringView gIncludeIntVector4{ SYSTEM_TEXT("#include \"CoreTools/TextParsing/Data/IntVector4.h\"\n") };
    constexpr System::StringView gStringConversion{ SYSTEM_TEXT("#include \"CoreTools/CharacterString/StringConversion.h\"\n") };
    constexpr System::StringView gUserClassInvariantMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/ClassInvariant/UserClassInvariantMacro.h\"\n") };
    constexpr System::StringView gCoreToolsClassInvariantMacro{ SYSTEM_TEXT("#include \"CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h\"\n") };

    constexpr System::StringView gFwd{ SYSTEM_TEXT("Fwd") };
    constexpr System::StringView gGet{ SYSTEM_TEXT("Get") };
    constexpr System::StringView gMap{ SYSTEM_TEXT("map") };
    constexpr System::StringView gInt{ SYSTEM_TEXT("int") };
    constexpr System::StringView gRow{ SYSTEM_TEXT("Row") };
    constexpr System::StringView gEnd{ SYSTEM_TEXT("end") };
    constexpr System::StringView gKey{ SYSTEM_TEXT("key") };
    constexpr System::StringView gAuto{ SYSTEM_TEXT("auto") };
    constexpr System::StringView gBase{ SYSTEM_TEXT("Base") };
    constexpr System::StringView gType{ SYSTEM_TEXT("type") };
    constexpr System::StringView gTrue{ SYSTEM_TEXT("true") };
    constexpr System::StringView gVoid{ SYSTEM_TEXT("void") };
    constexpr System::StringView gBool{ SYSTEM_TEXT("bool") };
    constexpr System::StringView gElse{ SYSTEM_TEXT("else") };
    constexpr System::StringView gSize{ SYSTEM_TEXT("Size") };
    constexpr System::StringView gUsing{ SYSTEM_TEXT("using") };
    constexpr System::StringView gFlags{ SYSTEM_TEXT("Flags") };
    constexpr System::StringView gFalse{ SYSTEM_TEXT("false") };
    constexpr System::StringView gClass{ SYSTEM_TEXT("class") };
    constexpr System::StringView gFinal{ SYSTEM_TEXT("final") };
    constexpr System::StringView gBegin{ SYSTEM_TEXT("begin") };
    constexpr System::StringView gErase{ SYSTEM_TEXT("erase") };
    constexpr System::StringView gDouble{ SYSTEM_TEXT("double") };
    constexpr System::StringView gVerify{ SYSTEM_TEXT("Verify") };
    constexpr System::StringView gReturn{ SYSTEM_TEXT("return") };
    constexpr System::StringView gSmallIter{ SYSTEM_TEXT("iter") };
    constexpr System::StringView gParsing{ SYSTEM_TEXT("Parsing") };
    constexpr System::StringView gCapitalIter{ SYSTEM_TEXT("Iter") };
    constexpr System::StringView gSmallConst{ SYSTEM_TEXT("const") };
    constexpr System::StringView gContinue{ SYSTEM_TEXT("continue") };
    constexpr System::StringView gNoexcept{ SYSTEM_TEXT("noexcept") };
    constexpr System::StringView gExplicit{ SYSTEM_TEXT("explicit") };
    constexpr System::StringView gCapitalConst{ SYSTEM_TEXT("Const") };
    constexpr System::StringView gContainer{ SYSTEM_TEXT("Container") };
    constexpr System::StringView gSharedPtr{ SYSTEM_TEXT("SharedPtr") };
    constexpr System::StringView gNamespace{ SYSTEM_TEXT("namespace") };
    constexpr System::StringView gStringCast{ SYSTEM_TEXT("StringCast") };
    constexpr System::StringView gCsvContent{ SYSTEM_TEXT("csvContent") };
    constexpr System::StringView gUnorderedMap{ SYSTEM_TEXT("unordered_map") };
    constexpr System::StringView gMappingContainer{ SYSTEM_TEXT("MappingContainer") };

    constexpr System::StringView gIf{ SYSTEM_TEXT("if (") };
    constexpr System::StringView gIfNot{ SYSTEM_TEXT("if (!") };
    constexpr System::StringView gInt64{ SYSTEM_TEXT("int64_t") };
    constexpr System::StringView gTypeEnd{ SYSTEM_TEXT(" type)") };
    constexpr System::StringView gCEnd{ SYSTEM_TEXT(".cend())\n") };
    constexpr System::StringView gRhsCopy{ SYSTEM_TEXT("& rhs) ") };
    constexpr System::StringView gIfndef{ SYSTEM_TEXT("#ifndef ") };
    constexpr System::StringView gDefine{ SYSTEM_TEXT("#define ") };
    constexpr System::StringView gRhsMove{ SYSTEM_TEXT("&& rhs) ") };
    constexpr System::StringView gPublic{ SYSTEM_TEXT("public:\n") };
    constexpr System::StringView gEmpty{ SYSTEM_TEXT(".empty())\n") };
    constexpr System::StringView gEmplace{ SYSTEM_TEXT(".emplace(") };
    constexpr System::StringView gEndif{ SYSTEM_TEXT("#endif  // ") };
    constexpr System::StringView gCBegin{ SYSTEM_TEXT(".cbegin(), ") };
    constexpr System::StringView gPrivate{ SYSTEM_TEXT("private:\n") };
    constexpr System::StringView gFindCEnd{ SYSTEM_TEXT(".cend();\n") };
    constexpr System::StringView gChecking{ SYSTEM_TEXT("Checking()") };
    constexpr System::StringView gValue{ SYSTEM_TEXT(">(element));\n") };
    constexpr System::StringView gSystemTextEnd{ SYSTEM_TEXT("\"s)) ") };
    constexpr System::StringView gHeadFileSuffix{ SYSTEM_TEXT(".h\"\n") };
    constexpr System::StringView gOverride{ SYSTEM_TEXT(" override;\n") };
    constexpr System::StringView gArraySize{ SYSTEM_TEXT(".size());\n") };
    constexpr System::StringView gFunctionConst{ SYSTEM_TEXT("() const") };
    constexpr System::StringView gEnumFilePrefix{ SYSTEM_TEXT("/Flags/") };
    constexpr System::StringView gConstNewline{ SYSTEM_TEXT(") const\n") };
    constexpr System::StringView gFindCBegin{ SYSTEM_TEXT(".cbegin();\n") };
    constexpr System::StringView gCsvRowVariable{ SYSTEM_TEXT("{ csvRow.") };
    constexpr System::StringView gCSVRowCall{ SYSTEM_TEXT(">(csvRow));\n") };
    constexpr System::StringView gDoubleColonConst{ SYSTEM_TEXT("::Const") };
    constexpr System::StringView gSystemTextInitEnd{ SYSTEM_TEXT("\"s) }") };
    constexpr System::StringView gIncludePrefix{ SYSTEM_TEXT("#include \"") };
    constexpr System::StringView gVirtualDestructor{ SYSTEM_TEXT("virtual ~") };
    constexpr System::StringView gCSVRowParameter{ SYSTEM_TEXT(">(csvRow);\n") };
    constexpr System::StringView gConstSemicolonNewline{ SYSTEM_TEXT(") const;\n") };
    constexpr System::StringView gParentTypeMember{ SYSTEM_TEXT(": ParentType{},\n") };
    constexpr System::StringView gTemplateSpecialization{ SYSTEM_TEXT("template <>\n") };

    constexpr System::StringView gNodiscard{ SYSTEM_TEXT("NODISCARD ") };
    constexpr System::StringView gSystemText{ SYSTEM_TEXT("SYSTEM_TEXT(\"") };
    constexpr System::StringView gSystemTextBegin{ SYSTEM_TEXT("(SYSTEM_TEXT(\"") };
    constexpr System::StringView gSystemTextValue{ SYSTEM_TEXT(", SYSTEM_TEXT(\"") };
    constexpr System::StringView gLogSystemTextBegin{ SYSTEM_TEXT("<< SYSTEM_TEXT(\"") };
    constexpr System::StringView gInitSystemTextBegin{ SYSTEM_TEXT("{ SYSTEM_TEXT(\"") };
    constexpr System::StringView gThrowException{ SYSTEM_TEXT("THROW_EXCEPTION(SYSTEM_TEXT(\"") };
    constexpr System::StringView gClassInvariantDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_DECLARE;\n") };
    constexpr System::StringView gOpenClassInvariant{ SYSTEM_TEXT("#ifdef OPEN_CLASS_INVARIANT\n") };
    constexpr System::StringView gWarnLog{ SYSTEM_TEXT("LOG_SINGLETON_ENGINE_APPENDER(Warn, User, ") };
    constexpr System::StringView gUserSelfClassIsValid9{ SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_9;\n") };
    constexpr System::StringView gUserSelfClassIsValid1{ SYSTEM_TEXT("USER_SELF_CLASS_IS_VALID_1;\n") };
    constexpr System::StringView gUserClassIsValidConst9{ SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_9;\n") };
    constexpr System::StringView gUserClassIsValidConst1{ SYSTEM_TEXT("USER_CLASS_IS_VALID_CONST_1;\n") };
    constexpr System::StringView gClassInvariantStubDefine{ SYSTEM_TEXT("CLASS_INVARIANT_STUB_DEFINE(") };
    constexpr System::StringView gOpenClassInvariantEndif{ SYSTEM_TEXT("#endif  // OPEN_CLASS_INVARIANT\n") };
    constexpr System::StringView gClassInvariantFinalDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_FINAL_DECLARE;\n") };
    constexpr System::StringView gClassInvariantVirtualDeclare{ SYSTEM_TEXT("CLASS_INVARIANT_VIRTUAL_DECLARE;\n") };
    constexpr System::StringView gCoreToolsClassIsValidConst9{ SYSTEM_TEXT("CORE_TOOLS_CLASS_IS_VALID_CONST_9;\n") };

    constexpr System::StringView gDataSheet{ SYSTEM_TEXT("表") };
    constexpr System::StringView gNotUnique{ SYSTEM_TEXT("表不是唯一的\")") };
    constexpr System::StringView gContainerZero{ SYSTEM_TEXT("表为空。\"s))\n") };
    constexpr System::StringView gRepeatKey{ SYSTEM_TEXT("表存在重复主键。\")") };
    constexpr System::StringView gNotExistent{ SYSTEM_TEXT("表不存在。\"s))\n") };
    constexpr System::StringView gRepeatKeyHint{ SYSTEM_TEXT("表存在重复主键：\")") };
    constexpr System::StringView gRepeatFieldHint{ SYSTEM_TEXT("字段存在重复主键。\")") };
    constexpr System::StringView gTypeDescribeNotFind{ SYSTEM_TEXT("未找到对应的类型。\"s))\n") };
    constexpr System::StringView gBaseNotGetArray{ SYSTEM_TEXT("表基类不允许获取数组。\"s))\n") };
    constexpr System::StringView gDataVerificationFailed{ SYSTEM_TEXT(" 数据校验失败。\"s))\n") };
    constexpr System::StringView gBaseNotGetString{ SYSTEM_TEXT("表基类不允许获取字符串。\"s))\n") };
    constexpr System::StringView gBaseNotGetMapping{ SYSTEM_TEXT("表基类不允许获取映射值。\"s))\n") };
    constexpr System::StringView gConditionNotFind{ SYSTEM_TEXT("表未找到满足条件的配置信息。\"s))\n") };
    constexpr System::StringView gFieldConditionNotFind{ SYSTEM_TEXT("字段未找到满足条件的配置信息。\"s))\n") };
    constexpr System::StringView gKeyNotFind{ SYSTEM_TEXT("表未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s))\n") };
    constexpr System::StringView gFieldNotFind{ SYSTEM_TEXT("字段未找到key = \"s) + System::ToString(key) + SYSTEM_TEXT(\"的配置信息。\"s))\n") };

    constexpr System::StringView gJsonRow{ SYSTEM_TEXT("jsonRow") };
    constexpr System::StringView gGetEnum{ SYSTEM_TEXT("GetEnum") };
    constexpr System::StringView gAtZero{ SYSTEM_TEXT(".at(0);\n") };
    constexpr System::StringView gConstIter{ SYSTEM_TEXT("ConstIter") };
    constexpr System::StringView gIntKey{ SYSTEM_TEXT("int key{};\n") };
    constexpr System::StringView gGetFirst{ SYSTEM_TEXT("::GetFirst") };
    constexpr System::StringView gIfIter{ SYSTEM_TEXT("if (iter != ") };
    constexpr System::StringView gIterEnd{ SYSTEM_TEXT("iter.end())\n") };
    constexpr System::StringView gFindKey{ SYSTEM_TEXT(".find(key);\n") };
    constexpr System::StringView gAtIndex{ SYSTEM_TEXT(".at(index);\n") };
    constexpr System::StringView gEnumClass{ SYSTEM_TEXT("enum class ") };
    constexpr System::StringView gUsingConst{ SYSTEM_TEXT("using Const") };
    constexpr System::StringView gKeyConst{ SYSTEM_TEXT(" key) const;\n") };
    constexpr System::StringView gEraseIter{ SYSTEM_TEXT(".erase(iter, ") };
    constexpr System::StringView gReturnKey{ SYSTEM_TEXT("return key;\n") };
    constexpr System::StringView gSort{ SYSTEM_TEXT("std::ranges::sort(") };
    constexpr System::StringView gMappingType{ SYSTEM_TEXT("MappingType") };
    constexpr System::StringView gKeyMember{ SYSTEM_TEXT(": key{ key }\n") };
    constexpr System::StringView gCSVNameSpace{ SYSTEM_TEXT("CSVConfigure") };
    constexpr System::StringView gGenerateKey{ SYSTEM_TEXT(" GenerateKey(") };
    constexpr System::StringView gSizeZero{ SYSTEM_TEXT("if (size == 0)\n") };
    constexpr System::StringView gBaseGetKey{ SYSTEM_TEXT("Base->GetKey()") };
    constexpr System::StringView gReturnTrue{ SYSTEM_TEXT("return true;\n") };
    constexpr System::StringView gUsingMap{ SYSTEM_TEXT("using std::map;\n") };
    constexpr System::StringView gReturnIter{ SYSTEM_TEXT("return *iter;\n") };
    constexpr System::StringView gCountConst{ SYSTEM_TEXT("Count() const\n") };
    constexpr System::StringView gGetSharedPtr{ SYSTEM_TEXT("SharedPtr Get") };
    constexpr System::StringView gEndFunction{ SYSTEM_TEXT("End() const;\n") };
    constexpr System::StringView gBaseSecond{ SYSTEM_TEXT("Base).second)\n") };
    constexpr System::StringView gMakeShared{ SYSTEM_TEXT("std::make_shared") };
    constexpr System::StringView gReturnFalse{ SYSTEM_TEXT("return false;\n") };
    constexpr System::StringView gCopyAssignment{ SYSTEM_TEXT("& operator=(") };
    constexpr System::StringView gSystemString{ SYSTEM_TEXT("System::String") };
    constexpr System::StringView gFindFunction{ SYSTEM_TEXT(", function);\n") };
    constexpr System::StringView gClassType{ SYSTEM_TEXT("using ClassType = ") };
    constexpr System::StringView gReturnResult{ SYSTEM_TEXT("return result;\n") };
    constexpr System::StringView gContainerGet{ SYSTEM_TEXT("Container()->Get") };
    constexpr System::StringView gTypeDescribe{ SYSTEM_TEXT("> typeDescribe{ ") };
    constexpr System::StringView gFinalInherit{ SYSTEM_TEXT(" final : public ") };
    constexpr System::StringView gKeyNoexcept{ SYSTEM_TEXT("(int key) noexcept") };
    constexpr System::StringView gCheckingConst{ SYSTEM_TEXT("Checking() const") };
    constexpr System::StringView gNodiscardConst{ SYSTEM_TEXT("NODISCARD Const") };
    constexpr System::StringView gSizeGreaterOne{ SYSTEM_TEXT("if (1 < size)\n") };
    constexpr System::StringView gParentType{ SYSTEM_TEXT("using ParentType = ") };
    constexpr System::StringView gEnumCastString{ SYSTEM_TEXT("EnumCastString(") };
    constexpr System::StringView gCountFunction{ SYSTEM_TEXT("Count() const;\n") };
    constexpr System::StringView gBeginFunction{ SYSTEM_TEXT("Begin() const;\n") };
    constexpr System::StringView gEndFunctionConst{ SYSTEM_TEXT("End() const\n") };
    constexpr System::StringView gKeyConstFunction{ SYSTEM_TEXT(" key) const\n") };
    constexpr System::StringView gRangeFirst{ SYSTEM_TEXT("if (range.first != ") };
    constexpr System::StringView gConstIterator{ SYSTEM_TEXT("::const_iterator") };
    constexpr System::StringView gBeginSecond{ SYSTEM_TEXT(".begin()->second;\n") };
    constexpr System::StringView gStaticMapBegin{ SYSTEM_TEXT("static std::map<") };
    constexpr System::StringView gKeyFunction{ SYSTEM_TEXT(">(key), function);\n") };
    constexpr System::StringView gRangesUnique{ SYSTEM_TEXT("std::ranges::unique") };
    constexpr System::StringView gGetEnumDescribe{ SYSTEM_TEXT("GetEnumDescribe(") };
    constexpr System::StringView gConstAutoIter{ SYSTEM_TEXT("const auto iter = ") };
    constexpr System::StringView gIfIterBegin{ SYSTEM_TEXT("if (iter.begin() != ") };
    constexpr System::StringView gStdMakeShared{ SYSTEM_TEXT(", std::make_shared<") };
    constexpr System::StringView gHeadDetailFileSuffix{ SYSTEM_TEXT("Detail.h\"\n") };
    constexpr System::StringView gConstexprStatic{ SYSTEM_TEXT("constexpr static ") };
    constexpr System::StringView gConstNoexcept{ SYSTEM_TEXT("() const noexcept;\n") };
    constexpr System::StringView gIsValid{ SYSTEM_TEXT("IsValid() const noexcept\n") };
    constexpr System::StringView gBeginFunctionConst{ SYSTEM_TEXT("Begin() const\n") };
    constexpr System::StringView gVerifyConst{ SYSTEM_TEXT("void Verify() const;\n") };
    constexpr System::StringView gParsingJsonRow{ SYSTEM_TEXT("Parsing(jsonRow);\n") };
    constexpr System::StringView gIfFunction{ SYSTEM_TEXT("if (function(element))\n") };
    constexpr System::StringView gForLoop{ SYSTEM_TEXT("for (const auto& element : ") };
    constexpr System::StringView gNodiscardVirtual{ SYSTEM_TEXT("NODISCARD virtual ") };
    constexpr System::StringView gIndexParameter{ SYSTEM_TEXT("(int index) const;\n") };
    constexpr System::StringView gGetKeyConst{ SYSTEM_TEXT("GetKey() const noexcept") };
    constexpr System::StringView gGetContainer{ SYSTEM_TEXT("NODISCARD Container Get") };
    constexpr System::StringView gGetFirstSharedPtr{ SYSTEM_TEXT("SharedPtr GetFirst") };
    constexpr System::StringView gDoubleColonGenerateKey{ SYSTEM_TEXT("::GenerateKey") };
    constexpr System::StringView gEraseIterBegin{ SYSTEM_TEXT(".erase(iter.begin(), ") };
    constexpr System::StringView gContainerResult{ SYSTEM_TEXT("Container result{};\n") };
    constexpr System::StringView gMaybeUnusedConst{ SYSTEM_TEXT("(MAYBE_UNUSED const ") };
    constexpr System::StringView gSharedPtrConst{ SYSTEM_TEXT("std::shared_ptr<const ") };
    constexpr System::StringView gParsingContent{ SYSTEM_TEXT("Parsing(csvContent);\n") };
    constexpr System::StringView gNoexceptDefault{ SYSTEM_TEXT("noexcept = default;\n") };
    constexpr System::StringView gLoop{ SYSTEM_TEXT("for (auto i = 0; i < size; ++i)\n") };
    constexpr System::StringView gIntArrayInitial{ SYSTEM_TEXT(" = std::vector<int>;\n") };
    constexpr System::StringView gBoolArrayInitial{ SYSTEM_TEXT(" = std::deque<bool>;\n") };
    constexpr System::StringView gEndMakeShared{ SYSTEM_TEXT(".end(), std::make_shared<") };
    constexpr System::StringView gReturnIterSecond{ SYSTEM_TEXT("return iter->second;\n") };
    constexpr System::StringView gReturnRangeFirst{ SYSTEM_TEXT("return *range.first;\n") };
    constexpr System::StringView gIndexParameterConst{ SYSTEM_TEXT("(int index) const\n") };
    constexpr System::StringView gUsingSharedPtr{ SYSTEM_TEXT("using std::shared_ptr;\n") };
    constexpr System::StringView gBaseKeyFunction{ SYSTEM_TEXT("Base>(key), function);\n") };
    constexpr System::StringView gCSVRow{ SYSTEM_TEXT("(const CoreTools::CSVRow& csvRow)") };
    constexpr System::StringView gDescribe{ SYSTEM_TEXT("(const System::String& describe)") };
    constexpr System::StringView gUsingMakeShared{ SYSTEM_TEXT("using std::make_shared;\n") };
    constexpr System::StringView gDirectory{ SYSTEM_TEXT("const System::String& directory") };
    constexpr System::StringView gCSVContent{ SYSTEM_TEXT("(const CSVContent& csvContent)") };
    constexpr System::StringView gReturnValueSecond{ SYSTEM_TEXT("return element.second;\n") };
    constexpr System::StringView gParsingDirectoryCall{ SYSTEM_TEXT("Parsing(directory);\n") };
    constexpr System::StringView gEqualRange{ SYSTEM_TEXT("const auto range = equal_range(") };
    constexpr System::StringView gEndNoexceptFunction{ SYSTEM_TEXT("End() const noexcept;\n") };
    constexpr System::StringView gEmplaceBack{ SYSTEM_TEXT(".emplace_back(std::make_shared<") };
    constexpr System::StringView gInt64ArrayInitial{ SYSTEM_TEXT(" = std::vector<int64_t>;\n") };
    constexpr System::StringView gDoubleArrayInitial{ SYSTEM_TEXT(" = std::vector<double>;\n") };
    constexpr System::StringView gJsonRowGetInt{ SYSTEM_TEXT("{ jsonRow.GetInt(SYSTEM_TEXT(\"") };
    constexpr System::StringView gStringKeyMap{ SYSTEM_TEXT("static std::map<System::String, ") };
    constexpr System::StringView gGetContainerConstEnd{ SYSTEM_TEXT("::GetContainer() const\n") };
    constexpr System::StringView gReturnCsvContainerGet{ SYSTEM_TEXT("return csvContainer.Get") };
    constexpr System::StringView gUnique{ SYSTEM_TEXT("const auto iter = std::ranges::unique(") };
    constexpr System::StringView gFunctionParameter{ SYSTEM_TEXT("(Function function) const;\n") };
    constexpr System::StringView gGetJsonRow{ SYSTEM_TEXT(">(jsonRow.GetJsonRow(SYSTEM_TEXT(\"") };
    constexpr System::StringView gContainerEqualTo{ SYSTEM_TEXT("Container = std::vector<Const") };
    constexpr System::StringView gClassNameEqual{ SYSTEM_TEXT("if (className == SYSTEM_TEXT(\"") };
    constexpr System::StringView gJsonRowGetBool{ SYSTEM_TEXT("{ jsonRow.GetBool(SYSTEM_TEXT(\"") };
    constexpr System::StringView gEndFunctionConstNoexcept{ SYSTEM_TEXT("End() const noexcept\n") };
    constexpr System::StringView gKeyJudge{ SYSTEM_TEXT(".cend() && (*iter)->GetKey() == key)\n") };
    constexpr System::StringView gCountOverrideFunction{ SYSTEM_TEXT("Count() const override;\n") };
    constexpr System::StringView gDescribeConst{ SYSTEM_TEXT(">(const String& describe) const\n") };
    constexpr System::StringView gBeginNoexceptFunction{ SYSTEM_TEXT("Begin() const noexcept;\n") };
    constexpr System::StringView gFunctionTemplate{ SYSTEM_TEXT("template <typename Function>\n") };
    constexpr System::StringView gParentTypeIsValid{ SYSTEM_TEXT("if (ParentType::IsValid() &&\n") };
    constexpr System::StringView gResultEmplaceBack{ SYSTEM_TEXT("result.emplace_back(element);\n") };
    constexpr System::StringView gStringDirectory{ SYSTEM_TEXT("(const System::String& directory)") };
    constexpr System::StringView gContainerParameter{ SYSTEM_TEXT("Container& csvContainer) const") };
    constexpr System::StringView gJsonRowGetInt64{ SYSTEM_TEXT("{ jsonRow.GetInt64(SYSTEM_TEXT(\"") };
    constexpr System::StringView gKeyEqual{ SYSTEM_TEXT("if((*lhs).GetKey() == (*rhs).GetKey())\n") };
    constexpr System::StringView gCEndEqualKey{ SYSTEM_TEXT(".cend() && (*iter)->GetId() == key)\n") };
    constexpr System::StringView gIterFindIf{ SYSTEM_TEXT("const auto iter = std::ranges::find_if(") };
    constexpr System::StringView gReturnNumericCast{ SYSTEM_TEXT("return boost::numeric_cast<int>(") };
    constexpr System::StringView gFunctionParameterConst{ SYSTEM_TEXT("(Function function) const\n") };
    constexpr System::StringView gJsonRowGetDouble{ SYSTEM_TEXT("{ jsonRow.GetDouble(SYSTEM_TEXT(\"") };
    constexpr System::StringView gJsonRowGetString{ SYSTEM_TEXT("{ jsonRow.GetString(SYSTEM_TEXT(\"") };
    constexpr System::StringView gSharedPtrEqualTo{ SYSTEM_TEXT("SharedPtr = std::shared_ptr<const ") };
    constexpr System::StringView gBeginFunctionConstNoexcept{ SYSTEM_TEXT("Begin() const noexcept\n") };
    constexpr System::StringView gIterTypeDescribe{ SYSTEM_TEXT("if (iter != typeDescribe.cend())\n") };
    constexpr System::StringView gIndexParameterOverride{ SYSTEM_TEXT("(int index) const override;\n") };
    constexpr System::StringView gEndOverrideFunction{ SYSTEM_TEXT("End() const noexcept override;\n") };
    constexpr System::StringView gStringArrayInitial{ SYSTEM_TEXT(" = std::vector<System::String>;\n") };
    constexpr System::StringView gJsonRowParameter{ SYSTEM_TEXT("(const CoreTools::JsonRow& jsonRow)") };
    constexpr System::StringView gIfFunctionValueSecond{ SYSTEM_TEXT("if (function(element.second))\n") };
    constexpr System::StringView gFindTypeDescribe{ SYSTEM_TEXT("const auto iter = typeDescribe.find(") };
    constexpr System::StringView gMappingContainerEqualTo{ SYSTEM_TEXT("using MappingContainer = std::") };
    constexpr System::StringView gLowerBound{ SYSTEM_TEXT("const auto iter = std::ranges::lower_bound(") };
    constexpr System::StringView gContentSize{ SYSTEM_TEXT("const auto size = csvContent.GetCount();\n") };
    constexpr System::StringView gJsonRowGetIntArray{ SYSTEM_TEXT("{ jsonRow.GetIntArray(SYSTEM_TEXT(\"") };
    constexpr System::StringView gDirectoryParameter{ SYSTEM_TEXT("(const System::String& directory);\n") };
    constexpr System::StringView gUsingNamespaceLiterals{ SYSTEM_TEXT("using namespace std::literals;\n") };
    constexpr System::StringView gCsvClassNameEquation{ SYSTEM_TEXT("if (csvClassName == SYSTEM_TEXT(\"") };
    constexpr System::StringView gBeginOverrideFunction{ SYSTEM_TEXT("Begin() const noexcept override;\n") };
    constexpr System::StringView gGetKeyConstOverride{ SYSTEM_TEXT(" GetKey() const noexcept override;\n") };
    constexpr System::StringView gCSVRowStringCastEnum{ SYSTEM_TEXT(" CoreTools::CSVRow::StringCastEnum<") };
    constexpr System::StringView gReturnKeyLess{ SYSTEM_TEXT("return (*lhs).GetKey() < (*rhs).GetKey();\n") };
    constexpr System::StringView gJsonRowGetBoolArray{ SYSTEM_TEXT("{ jsonRow.GetBoolArray(SYSTEM_TEXT(\"") };
    constexpr System::StringView gGetIdLessReturn{ SYSTEM_TEXT("return (*lhs).GetId() < (*rhs).GetId();\n") };
    constexpr System::StringView gGetIdEqualReturn{ SYSTEM_TEXT("return (*lhs).GetId() == (*rhs).GetId();\n") };
    constexpr System::StringView gJsonRowGetInt64Array{ SYSTEM_TEXT("{ jsonRow.GetInt64Array(SYSTEM_TEXT(\"") };
    constexpr System::StringView gFunction{ SYSTEM_TEXT(", [](const auto& lhs, const auto& rhs) noexcept {\n") };
    constexpr System::StringView gParsingFunction{ SYSTEM_TEXT("void Parsing(const CSVContent& csvContent);\n") };
    constexpr System::StringView gGetContainerConst{ SYSTEM_TEXT("NODISCARD Container GetContainer() const;\n") };
    constexpr System::StringView gJsonRowGetDoubleArray{ SYSTEM_TEXT("{ jsonRow.GetDoubleArray(SYSTEM_TEXT(\"") };
    constexpr System::StringView gJsonRowGetStringArray{ SYSTEM_TEXT("{ jsonRow.GetStringArray(SYSTEM_TEXT(\"") };
    constexpr System::StringView gPathNative{ SYSTEM_TEXT("const auto fileName = inputPath.path().native();\n") };
    constexpr System::StringView gJsonRowConstruction{ SYSTEM_TEXT("CoreTools::JsonRow jsonRow{ basicTree };\n") };
    constexpr System::StringView gFilesystemPath{ SYSTEM_TEXT("const std::filesystem::path path{ directory };\n") };
    constexpr System::StringView gLogAssert{ SYSTEM_TEXT(", CoreTools::LogAppenderIOManageSign::TriggerAssert);\n") };
    constexpr System::StringView gResultEmplaceBackValueSecond{ SYSTEM_TEXT("result.emplace_back(element.second);\n") };
    constexpr System::StringView gGetJsonRowContainer{ SYSTEM_TEXT("Row = jsonRow.GetJsonRowContainer(SYSTEM_TEXT(\"") };
    constexpr System::StringView gReturnContainerRange{ SYSTEM_TEXT("return Container{ range.first, range.second };\n") };
    constexpr System::StringView gGetJsonClassName{ SYSTEM_TEXT("const auto className = jsonHead.GetJsonClassName();\n") };
    constexpr System::StringView gFileNameFind{ SYSTEM_TEXT("if (fileName.find(L\".csv\"s) != (fileName.size() - 4))\n") };
    constexpr System::StringView gJsonRowBasicTree{ SYSTEM_TEXT("CoreTools::JsonRow::BasicTree basicTree{ fileName };\n") };
    constexpr System::StringView gGetCSVClassName{ SYSTEM_TEXT("const auto csvClassName = csvContent.GetCSVClassName();\n") };
    constexpr System::StringView gGetMappingContainerConst{ SYSTEM_TEXT("NODISCARD MappingContainer GetContainer() const;\n") };
    constexpr System::StringView gCSVRowInit{ SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvHead, csvContent.GetContent(i) };\n") };
    constexpr System::StringView gLambdaFunctionInit{ SYSTEM_TEXT("const auto function = [](const auto& lhs, const auto& rhs) noexcept {\n") };
    constexpr System::StringView gDirectoryIterator{ SYSTEM_TEXT("for (const auto& inputPath : std::filesystem::directory_iterator(path))\n") };
    constexpr System::StringView gCSVRowZeroInit{ SYSTEM_TEXT("CoreTools::CSVRow csvRow{ csvContent.GetCSVHead(), csvContent.GetContent(0) };\n") };
    constexpr System::StringView gReadJson{ SYSTEM_TEXT("read_json(CoreTools::StringConversion::WideCharConversionMultiByte(fileName), basicTree);\n") };
    constexpr System::StringView gJsonHeadConstruction{ SYSTEM_TEXT("CoreTools::JsonHead jsonHead{ CoreTools::StringConversion::WideCharConversionStandard(fileName) };\n") };
    constexpr System::StringView gCSVContentInit{ SYSTEM_TEXT("const CoreTools::CSVContent csvContent{ CoreTools::StringConversion::WideCharConversionStandard(fileName) };\n") };

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

    constexpr System::StringView gCopyright{ SYSTEM_TEXT("/// Copyright (c) 2010-\n/// Threading Core Render Engine\n///\n/// 作者：彭武阳，彭晔恩，彭晔泽\n")
                                                 SYSTEM_TEXT("/// 联系作者：94458936@qq.com\n///\n/// 标准：std:c++20\n/// 自动生成\n") };
}

#endif  // CORE_TOOLS_TEXT_PARSING_TEXT_PARSING_CONSTANT_H