///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:04)

#include "TestingObjectSize.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, TestingObjectSize);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, TestingObjectSize);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, TestingObjectSize);

CoreTools::TestingObjectSize::TestingObjectSize(int value)
    : ParentType{ "TestingObjectSize" }, testValue{ value }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TestingObjectSize);

int CoreTools::TestingObjectSize::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::GetStreamingSize() + GetStreamSize(GetTestValue());
}

CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(CoreTools, TestingObjectSize)

void CoreTools::TestingObjectSize::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void CoreTools::TestingObjectSize::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void CoreTools::TestingObjectSize::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(testValue);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::TestingObjectSize::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(testValue);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::TestingObjectSize::TestingObjectSize(LoadConstructor value)
    : ParentType{ value }, testValue{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

int CoreTools::TestingObjectSize::GetTestValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return testValue;
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::TestingObjectSize::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::TestingObjectSize::ObjectSharedPtr CoreTools::TestingObjectSize::Create(int value)
{
    return std::make_shared<ClassType>(value);
}