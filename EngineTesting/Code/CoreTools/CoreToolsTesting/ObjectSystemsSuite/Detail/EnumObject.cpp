/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:49)

#include "EnumObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, EnumObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, EnumObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, EnumObject);

CoreTools::EnumObject::EnumObject(DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }, enumValue{ EnumObjectEnum::Five }, enumArray0{}, enumArray1{}
{
    AllocationArray0(EnumObjectEnum::Ten);
    AllocationArray1(EnumObjectEnum::Five);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

bool CoreTools::EnumObject::IsLoadValidity() const
{
    if (enumValue == EnumObjectEnum::Ten || enumArray0.empty() || enumArray1.empty())
        return false;

    for (auto i = 0; i < bufferSize; ++i)
    {
        if (enumArray0.at(i) == EnumObjectEnum::Five || enumArray1.at(i) == EnumObjectEnum::Ten)
            return false;
    }

    return true;
}

CoreTools::EnumObject::EnumObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, enumValue{ EnumObjectEnum::Ten }, enumArray0{}, enumArray1{}
{
    AllocationArray1(EnumObjectEnum::Ten);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::EnumObject::AllocationArray0(EnumObjectEnum value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        enumArray0.emplace_back(value);
    }
}

void CoreTools::EnumObject::AllocationArray1(EnumObjectEnum value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        enumArray1.emplace_back(value);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::EnumObject::IsValid() const noexcept
{
    return ParentType::IsValid() && !enumArray1.empty();
}

#endif  // OPEN_CLASS_INVARIANT

int CoreTools::EnumObject::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    /// WriteEnum
    size += CoreTools::GetStreamSize(enumValue);

    /// WriteEnumWithNumber
    size += sizeof(int32_t);
    size += bufferSize * CoreTools::GetStreamSize(enumValue);

    /// WriteEnumWithoutNumber
    size += bufferSize * CoreTools::GetStreamSize(enumValue);

    return size;
}

int64_t CoreTools::EnumObject::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::EnumObject::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteEnum(enumValue);
    target.WriteEnumContainerWithNumber(enumArray0);
    target.WriteEnumContainerWithoutNumber(enumArray1);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::EnumObject::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::EnumObject::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::EnumObject::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadEnum(enumValue);

    if (const auto size = source.Read<int32_t>();
        0 < size)
    {
        source.ReadEnumContainer(size, enumArray0);
        source.ReadEnumContainer(size, enumArray1);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::EnumObject::CloneObject() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
