///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 22:35)

#include "CoreTools/CoreToolsExport.h"

#include "JsonRow.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonRowImpl.h"

CoreTools::JsonRow::JsonRow(const BasicTree& basicTree)
    : impl{ basicTree }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonRow)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonRow, GetCount, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetString, String, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetBool, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetInt, String, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetInt64, String, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetDouble, String, double)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetBoolArray, String, CoreTools::JsonRow::BoolContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetIntArray, String, CoreTools::JsonRow::IntContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetInt64Array, String, CoreTools::JsonRow::Int64Container)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonRow, GetDoubleArray, String, CoreTools::JsonRow::DoubleContainer)
