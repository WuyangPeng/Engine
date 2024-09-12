/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/12 19:27)

#include "Base64Testing.h"
#include "CoreTools/CharacterString/Base64.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::Base64Testing::Base64Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Base64Testing)

void CoreTools::Base64Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::Base64Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EncodeTest);
}

void CoreTools::Base64Testing::EncodeTest()
{
    const auto input = "Hello world!!";
    const auto encode = Base64::Encode(input);

    ASSERT_EQUAL(Base64::Decode(encode), input);
}