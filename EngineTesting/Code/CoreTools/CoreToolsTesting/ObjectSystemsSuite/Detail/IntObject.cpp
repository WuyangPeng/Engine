// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 14:11)

#include "IntObject.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::swap;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
CORE_TOOLS_RTTI_DEFINE(CoreTools, IntObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, IntObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, IntObject);

CoreTools::IntObject ::IntObject()
    : ParentType{}, m_IntValue{ 5 }, m_IntArray1{  }, m_IntArray2{   }
{
    AllocationFirstArray(4);
    AllocationSecondArray(5);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::IntObject ::IntObject(LoadConstructor value)
    : ParentType{ value }, m_IntValue{ 0 }, m_IntArray1{ nullptr }, m_IntArray2{   }
{
    AllocationSecondArray(4);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::IntObject ::AllocationFirstArray(int value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        m_IntArray1[i] = value;
    }
}

void CoreTools::IntObject ::AllocationSecondArray(int value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        m_IntArray2[i] = value;
    }
}

CoreTools::IntObject ::IntObject(const IntObject& rhs)
    : ParentType{}, m_IntValue{ rhs.m_IntValue }, m_IntArray1{  }, m_IntArray2{  }
{


    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::IntObject& CoreTools::IntObject ::operator=(const IntObject& rhs)
{
    CLASS_IS_VALID_1;

    IntObject temp{ rhs };
    Swap(temp);

    return *this;
}

// private
void CoreTools::IntObject ::Swap(IntObject& rhs)
{
    swap(m_IntValue, rhs.m_IntValue);
    swap(m_IntArray1, rhs.m_IntArray1);
    swap(m_IntArray2, rhs.m_IntArray2);
}

CoreTools::IntObject ::~IntObject()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    //	Release();
}

void CoreTools::IntObject ::Release()
{
 
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::IntObject ::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_IntArray2 != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

// private
bool CoreTools::IntObject ::IsLoadValidity() const
{
    if (m_IntValue != 5 || m_IntArray1 == nullptr || m_IntArray2 == nullptr)
        return false;

    for (int i = 0; i < bufferSize; ++i)
    {
        if (m_IntArray1[i] != 4 || m_IntArray2[i] != 5)
            return false;
    }

    return true;
}

int CoreTools::IntObject ::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    // WriteInt
    size += sizeof(m_IntValue);

    // WriteIntWithNumber
    size += sizeof(int);
    size += bufferSize * sizeof(m_IntValue);

    // WriteIntWithoutNumber
    size += bufferSize * sizeof(m_IntValue);

    return size;
}

uint64_t CoreTools::IntObject ::Register( ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::IntObject ::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    //target.Write(m_IntValue);
    //target.WriteWithNumber(bufferSize, m_IntArray1);
    //target.WriteWithoutNumber(bufferSize, m_IntArray2);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::IntObject ::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::IntObject ::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::IntObject ::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(m_IntValue);
    auto size = 0;
    source.Read(size);
    if (0 < size)
    {
       

        //source.Read(bufferSize, m_IntArray1);
        //source.Read(bufferSize, m_IntArray2);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::IntObject::CloneObject() const
{
    return nullptr;
}

#include STSTEM_WARNING_POP