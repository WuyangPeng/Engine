///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/1 11:3)

#include "StringUtilityTesting.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/StringUtility.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::StringUtilityTesting::StringUtilityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StringUtilityTesting)

void CoreTools::StringUtilityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StringUtilityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ToFirstLetterUpperTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToFirstLetterLowerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToUpperMacroTest);

    ASSERT_NOT_THROW_EXCEPTION_0(ConvertNarrowToWideTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertWideToNarrowTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToLowerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ToUpperTest);

    ASSERT_NOT_THROW_EXCEPTION_0(GetTextTokensTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetAdvancedTextTokensTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTokensTest);
}

void CoreTools::StringUtilityTesting::ToFirstLetterUpperTest()
{
    ASSERT_EQUAL(StringUtility::ToFirstLetterUpper(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("AuAu"s));
    ASSERT_EQUAL(StringUtility::ToFirstLetterUpper(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("AuAu"s));
    ASSERT_EQUAL(StringUtility::ToFirstLetterUpper(SYSTEM_TEXT(" auAu"s)), SYSTEM_TEXT(" auAu"s));
}

void CoreTools::StringUtilityTesting::ToFirstLetterLowerTest()
{
    ASSERT_EQUAL(StringUtility::ToFirstLetterLower(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("auAu"s));
    ASSERT_EQUAL(StringUtility::ToFirstLetterLower(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("auAu"s));
    ASSERT_EQUAL(StringUtility::ToFirstLetterLower(SYSTEM_TEXT(" AuAu"s)), SYSTEM_TEXT(" AuAu"s));
}

void CoreTools::StringUtilityTesting::ToUpperMacroTest()
{
    ASSERT_EQUAL(StringUtility::ToUpperMacro(SYSTEM_TEXT("AuAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringUtility::ToUpperMacro(SYSTEM_TEXT("auAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringUtility::ToUpperMacro(SYSTEM_TEXT(" AuAu"s)), SYSTEM_TEXT("AU_AU"s));
    ASSERT_EQUAL(StringUtility::ToUpperMacro(SYSTEM_TEXT(" Au_Au"s)), SYSTEM_TEXT("AU__AU"s));
    ASSERT_EQUAL(StringUtility::ToUpperMacro(SYSTEM_TEXT("Au_uu"s)), SYSTEM_TEXT("AU_UU"s));
}

void CoreTools::StringUtilityTesting::ConvertNarrowToWideTest()
{
    ASSERT_EQUAL(StringUtility::ConvertNarrowToWide("AuAu"s), L"AuAu"s);
    ASSERT_EQUAL(StringUtility::ConvertNarrowToWide("auAu"s), L"auAu"s);
    ASSERT_EQUAL(StringUtility::ConvertNarrowToWide(" auAu"s), L" auAu"s);
}

void CoreTools::StringUtilityTesting::ConvertWideToNarrowTest()
{
    ASSERT_EQUAL(StringUtility::ConvertWideToNarrow(L"AuAu"s), "AuAu"s);
    ASSERT_EQUAL(StringUtility::ConvertWideToNarrow(L"auAu"s), "auAu"s);
    ASSERT_EQUAL(StringUtility::ConvertWideToNarrow(L" AuAu"s), " AuAu"s);
}

void CoreTools::StringUtilityTesting::ToLowerTest()
{
    ASSERT_EQUAL(StringUtility::ToLower("AuAu"s), "auau"s);
    ASSERT_EQUAL(StringUtility::ToLower("auAu"s), "auau"s);
    ASSERT_EQUAL(StringUtility::ToLower(" AuAu"s), " auau"s);
    ASSERT_EQUAL(StringUtility::ToLower(" Au_Au"s), " au_au"s);
    ASSERT_EQUAL(StringUtility::ToLower("Au_uu"s), "au_uu"s);
}

void CoreTools::StringUtilityTesting::ToUpperTest()
{
    ASSERT_EQUAL(StringUtility::ToUpper("AuAu"s), "AUAU"s);
    ASSERT_EQUAL(StringUtility::ToUpper("auAu"s), "AUAU"s);
    ASSERT_EQUAL(StringUtility::ToUpper(" AuAu"s), " AUAU"s);
    ASSERT_EQUAL(StringUtility::ToUpper(" Au_Au"s), " AU_AU"s);
    ASSERT_EQUAL(StringUtility::ToUpper("Au_uu"s), "AU_UU"s);
}

void CoreTools::StringUtilityTesting::GetTextTokensTest()
{
    const auto text = StringUtility::GetTextTokens("GetText\r\nTokens"s);

    ASSERT_EQUAL_FAILURE_THROW(text.size(), 2u, "Tokens 大小测试失败。");
    ASSERT_EQUAL(text.at(0), "GetText");
    ASSERT_EQUAL(text.at(1), "Tokens");
}

void CoreTools::StringUtilityTesting::GetAdvancedTextTokensTest()
{
    const auto text = StringUtility::GetAdvancedTextTokens("GetText\x7FTokens"s);

    ASSERT_EQUAL_FAILURE_THROW(text.size(), 2u, "Tokens 大小测试失败。");
    ASSERT_EQUAL(text.at(0), "GetText");
    ASSERT_EQUAL(text.at(1), "Tokens");
}

void CoreTools::StringUtilityTesting::GetTokensTest()
{
    const auto text = StringUtility::GetTokens("GetTextTokens"s, "e");

    ASSERT_EQUAL_FAILURE_THROW(text.size(), 4u, "Tokens 大小测试失败。");
    ASSERT_EQUAL(text.at(0), "G");
    ASSERT_EQUAL(text.at(1), "tT");
    ASSERT_EQUAL(text.at(2), "xtTok");
    ASSERT_EQUAL(text.at(3), "ns");
}