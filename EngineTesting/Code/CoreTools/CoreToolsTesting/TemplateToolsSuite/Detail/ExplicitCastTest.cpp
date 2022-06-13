///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:50)

#include "ExplicitCastTest.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"

using std::string;

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExplicitCastTest)

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<int>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return integer;
}

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<const string&>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return stringValue;
}

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<const string*>() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return &stringValue;
}

CoreTools::ExplicitCastTest::ExplicitCastTest(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : integer{ 1 }, stringValue{ "ss" }, shortValue{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#if 0  // ����Ӧ�ò����������

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<short*>()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return &shortValue;
}

#endif  // 0

#if 0  // ����Ӧ�ò����������

CoreTools::ExplicitCastTest::operator CoreTools::ExplicitCast<short&>()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return shortValue;
}

#endif  // 0
