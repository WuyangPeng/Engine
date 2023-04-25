///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 16:02)

#include "BoolObject.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, BoolObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, BoolObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, BoolObject);

CoreTools::BoolObject::BoolObject(DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, boolValue{ false }, boolArray0{}, boolArray1{}
{
    AllocationArray0(true);
    AllocationArray1(false);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::BoolObject::BoolObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, boolValue{ true }, boolArray0{}, boolArray1{}
{
    AllocationArray1(true);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::BoolObject::AllocationArray0(bool value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        boolArray0.emplace_back(value);
    }
}

void CoreTools::BoolObject::AllocationArray1(bool value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        boolArray1.emplace_back(value);
    }
}

bool CoreTools::BoolObject::IsLoadValidity() const
{
    if (boolValue == true || boolArray0.empty() || boolArray1.empty())
        return false;

    for (auto i = 0; i < bufferSize; ++i)
    {
        if (boolArray0.at(i) == false || boolArray1.at(i) == true)
            return false;
    }

    return true;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BoolObject::IsValid() const noexcept
{
    if (ParentType::IsValid() && !boolArray1.empty())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::BoolObject::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    // WriteBool
    size += GetStreamSize(boolValue);

    // WriteBoolWithNumber
    size += sizeof(int32_t);
    size += bufferSize * GetStreamSize(boolValue);

    // WriteBoolWithoutNumber
    size += bufferSize * GetStreamSize(boolValue);

    return size;
}

int64_t CoreTools::BoolObject::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::BoolObject::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(boolValue);
    target.WriteBoolContainerWithNumber(boolArray0);
    target.WriteBoolContainerWithoutNumber(boolArray1);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::BoolObject::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::BoolObject::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::BoolObject::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    boolValue = source.ReadBool();

    if (const auto size = source.Read<int32_t>();
        0 < size)
    {
        source.ReadBoolContainer(size, boolArray0);
        source.ReadBoolContainer(size, boolArray1);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::BoolObject::CloneObject() const
{
    return std::make_shared<ClassType>(*this);
}
