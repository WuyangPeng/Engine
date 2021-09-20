///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/30 11:43)

#include "CaseInsensitiveStringTesting.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CaseInsensitiveStringTesting::CaseInsensitiveStringTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CaseInsensitiveStringTesting)

void CoreTools::CaseInsensitiveStringTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CaseInsensitiveStringTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TStringTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DynamicLinkStringTest); 
}

void CoreTools::CaseInsensitiveStringTesting::StringTest()
{
    CaseInsensitiveString string0{ "stRinG" };
    CaseInsensitiveString string1{ "STRiNG" };
    CaseInsensitiveString string2{ "testSTRING" };

    ASSERT_EQUAL(string0, string1);
    ASSERT_FALSE(string0 != string1);
    ASSERT_FALSE(string0 < string1);
    ASSERT_FALSE(string0 > string1);
    ASSERT_TRUE(string0 <= string1);
    ASSERT_TRUE(string0 >= string1);
    ASSERT_EQUAL(string2.find(string0), 4u);
    ASSERT_EQUAL(string2.find(string1), 4u);
}

void CoreTools::CaseInsensitiveStringTesting::WStringTest()
{
    CaseInsensitiveWString string0{ L"strIng" };
    CaseInsensitiveWString string1{ L"STRiNG" };
    CaseInsensitiveWString string2{ L"testString" };

    ASSERT_EQUAL(string0, string1);
    ASSERT_FALSE(string0 != string1);
    ASSERT_FALSE(string0 < string1);
    ASSERT_FALSE(string0 > string1);
    ASSERT_TRUE(string0 <= string1);
    ASSERT_TRUE(string0 >= string1);
    ASSERT_EQUAL(string2.find(string0), 4u);
    ASSERT_EQUAL(string2.find(string1), 4u);
}

void CoreTools::CaseInsensitiveStringTesting::TStringTest()
{
    CaseInsensitiveTString string0{ SYSTEM_TEXT("StriNg") };
    CaseInsensitiveTString string1{ SYSTEM_TEXT("sTrING") };
    CaseInsensitiveTString string2{ SYSTEM_TEXT("TEstString") };

    ASSERT_EQUAL(string0, string1);
    ASSERT_FALSE(string0 != string1);
    ASSERT_FALSE(string0 < string1);
    ASSERT_FALSE(string0 > string1);
    ASSERT_TRUE(string0 <= string1);
    ASSERT_TRUE(string0 >= string1);
    ASSERT_EQUAL(string2.find(string0), 4u);
    ASSERT_EQUAL(string2.find(string1), 4u);
}

void CoreTools::CaseInsensitiveStringTesting::DynamicLinkStringTest()
{
    CaseInsensitiveDynamicLinkString string0{ DYNAMIC_LINK_TEXT("StriNg") };
    CaseInsensitiveDynamicLinkString string1{ DYNAMIC_LINK_TEXT("sTrING") };
    CaseInsensitiveDynamicLinkString string2{ DYNAMIC_LINK_TEXT("TEstString") };

    ASSERT_EQUAL(string0, string1);
    ASSERT_FALSE(string0 != string1);
    ASSERT_FALSE(string0 < string1);
    ASSERT_FALSE(string0 > string1);
    ASSERT_TRUE(string0 <= string1);
    ASSERT_TRUE(string0 >= string1);
    ASSERT_EQUAL(string2.find(string0), 4u);
    ASSERT_EQUAL(string2.find(string1), 4u);
}
