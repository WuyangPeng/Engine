/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/29 20:13)

#include "ExplicitCastTest.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"

#define EXPLICIT_CAST_COMPILE_ERROR

#undef EXPLICIT_CAST_COMPILE_ERROR

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExplicitCastTest)

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<int>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return integer;
}

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<const std::string&>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stringValue;
}

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<const std::string*>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &stringValue;
}

CoreTools::ExplicitCastTest::ExplicitCastTest(DisableNotThrow disableNotThrow)
    : integer{ 1 }, stringValue{ "ss" }, shortValue{ 0 }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef EXPLICIT_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<short*>()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return &shortValue;
}

#endif  // EXPLICIT_CAST_COMPILE_ERROR

#ifdef EXPLICIT_CAST_COMPILE_ERROR  // 这里应该产生编译错误。

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<short&>()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return shortValue;
}

#endif  // EXPLICIT_CAST_COMPILE_ERROR
