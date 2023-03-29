///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/10 14:16)

#include "CoreTools/CoreToolsExport.h"

#include "JsonNode.h"
#include "JsonNodeContainer.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Detail/Json/JsonNodeContainerImpl.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, JsonNodeContainer)

CoreTools::JsonNodeContainer CoreTools::JsonNodeContainer::Create()
{
    return JsonNodeContainer{ DisableNotThrow::Disable };
}

CoreTools::JsonNodeContainer::JsonNodeContainer(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, JsonNodeContainer)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonNodeContainer, AddJsonNode, JsonNodeContainer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonNodeContainer, AddJsonNode, JsonNodeSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, JsonNodeContainer, GetJsonDataType, String, CoreTools::JsonDataType)

void CoreTools::JsonNodeContainer::SetNewJsonDataType(const String& key, JsonDataType jsonDataType)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetNewJsonDataType(key, jsonDataType);
}

void CoreTools::JsonNodeContainer::SetNewJsonNodeContainer(const String& key, const JsonNodeContainer& jsonNodeContainer)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetNewJsonNodeContainer(key, jsonNodeContainer);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, begin, CoreTools::JsonNodeContainer::ContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, begin, CoreTools::JsonNodeContainer::ContainerIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, end, CoreTools::JsonNodeContainer::ContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, end, CoreTools::JsonNodeContainer::ContainerIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, IsEmpty, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, GetJsonDataType, CoreTools::JsonDataType)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, JsonNodeContainer, SetJsonDataType, JsonDataType, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, HasNested, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, HasArray, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, JsonNodeContainer, HasBoolArray, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, JsonNodeContainer, GetSize, int)