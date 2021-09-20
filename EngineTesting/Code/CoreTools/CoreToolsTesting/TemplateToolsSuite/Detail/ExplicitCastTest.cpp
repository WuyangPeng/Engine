// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 15:37)

#include "ExplicitCastTest.h"
#include "CoreTools/TemplateTools/ExplicitCastDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h"
using std::string;

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ExplicitCastTest)

CoreTools::ExplicitCastTest
	::operator CoreTools::ExplicitCast<int>() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Integer;
}

CoreTools::ExplicitCastTest ::operator CoreTools::ExplicitCast<const string&>() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_StringValue;
}

CoreTools::ExplicitCastTest ::operator CoreTools::ExplicitCast<const string*>() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return &m_StringValue;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::ExplicitCastTest
	::ExplicitCastTest() 
	:m_Integer{ 1 }, m_StringValue{ "ss" }, m_ShortValue{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP
#if 0 // 这里应该产生编译错误。
CoreTools::ExplicitCastTest
	::operator CoreTools::ExplicitCast<short*>()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return &m_ShortValue;
}
#endif // 0

#if 0 // 这里应该产生编译错误。
CoreTools::ExplicitCastTest
	::operator CoreTools::ExplicitCast<short&>()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	return m_ShortValue;
}
#endif  // 0

