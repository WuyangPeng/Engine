///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:14)

#include "IntObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, IntObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, IntObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, IntObject);

CoreTools::IntObject::IntObject(DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, intValue{ 5 }, intArray0{}, intArray1{}
{
    AllocationArray0(4);
    AllocationArray1(5);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::IntObject::IntObject(LoadConstructor value)
    : ParentType{ value }, intValue{ 0 }, intArray0{}, intArray1{}
{
    AllocationArray1(4);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::IntObject::AllocationArray0(int value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        intArray0.emplace_back(value);
    }
}

void CoreTools::IntObject::AllocationArray1(int value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        intArray1.emplace_back(value);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::IntObject::IsValid() const noexcept
{
    if (ParentType::IsValid() && !intArray1.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool CoreTools::IntObject::IsLoadValidity() const
{
    if (intValue != 5 || intArray0.empty() || intArray1.empty())
        return false;

    for (auto i = 0; i < bufferSize; ++i)
    {
        if (intArray0.at(i) != 4 || intArray1.at(i) != 5)
            return false;
    }

    return true;
}

int CoreTools::IntObject::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    // WriteInt
    size += sizeof(intValue);

    // WriteIntWithNumber
    size += sizeof(int32_t);
    size += bufferSize * sizeof(intValue);

    // WriteIntWithoutNumber
    size += bufferSize * sizeof(intValue);

    return size;
}

int64_t CoreTools::IntObject::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::IntObject::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(intValue);
    target.WriteContainerWithNumber(intArray0);
    target.WriteContainerWithoutNumber(intArray1);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::IntObject::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::IntObject::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::IntObject::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(intValue);

    if (const auto size = source.Read<int32_t>();
        0 < size)
    {
        source.ReadContainer(bufferSize, intArray0);
        source.ReadContainer(bufferSize, intArray1);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::IntObject::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
