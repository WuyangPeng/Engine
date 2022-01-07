///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/19 15:56)

#include "StreamObject.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::make_shared;
using std::string;

CORE_TOOLS_RTTI_DEFINE(CoreTools, StreamObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, StreamObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, StreamObject);

CoreTools::StreamObject::StreamObject(const string& name)
    : ParentType{ name }, boolValue{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::StreamObject::StreamObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, boolValue{ true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StreamObject)

int CoreTools::StreamObject::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CORE_TOOLS_STREAM_SIZE(boolValue);

    return size;
}

uint64_t CoreTools::StreamObject::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::StreamObject::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(boolValue);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::StreamObject::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::StreamObject::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::StreamObject::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    boolValue = source.ReadBool();

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::StreamObject::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

bool CoreTools::StreamObject::GetBoolValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boolValue;
}

CoreTools::StreamObject::StreamObjectSharedPtr CoreTools::StreamObject::Create(const string& name)
{
    return make_shared<ClassType>(name);
}
