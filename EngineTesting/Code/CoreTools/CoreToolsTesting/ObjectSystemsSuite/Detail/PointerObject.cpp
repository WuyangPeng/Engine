// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 14:13)

#include "BoolObject.h"
#include "EnumObject.h"
#include "IntObject.h"
#include "PointerObject.h"
#include "StringObject.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26418) 
CORE_TOOLS_RTTI_DEFINE(CoreTools, PointerObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, PointerObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, PointerObject);

CoreTools::PointerObject ::PointerObject()
    : ParentType{}
{
    Allocation();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

// private
void CoreTools::PointerObject ::Allocation()
{
    for (auto i = 0; i < bufferSize; ++i)
    {
    }
}

CoreTools::PointerObject ::PointerObject(LoadConstructor value)
    : ParentType{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::PointerObject ::~PointerObject()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    Release();
}

void CoreTools::PointerObject ::Release() noexcept
{
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::PointerObject ::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

// private
bool CoreTools::PointerObject ::IsLoadValidity() const
{
    return true;
}

int CoreTools::PointerObject ::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto size = ParentType::GetStreamingSize();

    return size;
}

uint64_t CoreTools::PointerObject ::Register(const ObjectRegisterSharedPtr& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

  const auto uniqueID = ParentType::Register(target);

    return uniqueID;
}

void CoreTools::PointerObject ::Save(const BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::PointerObject ::Link([[maybe_unused]] const ObjectLinkSharedPtr& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

void CoreTools::PointerObject ::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

void CoreTools::PointerObject ::Load(const BufferSourceSharedPtr& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

#include STSTEM_WARNING_POP