///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:02)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNode.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonNodeImpl.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, JsonNode)

CoreTools::JsonNode::JsonNode(const String& typeName, JsonDataType jsonDataType)
    : impl{ typeName, jsonDataType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNode)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonNode, AddJsonNode, JsonNodeContainer, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonNode, GetTypeName, System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNode, GetJsonDataType, CoreTools::JsonDataType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, JsonNode, SetNewJsonDataType, JsonDataType, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonNode, SetNewJsonNodeContainer, JsonNodeContainer, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNode, GetJsonNodeContainer, CoreTools::JsonNodeContainer)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNode, HasArray, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNode, HasBoolArray, bool)
