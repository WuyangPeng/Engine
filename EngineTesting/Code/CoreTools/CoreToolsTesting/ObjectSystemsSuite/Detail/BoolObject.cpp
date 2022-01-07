// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 14:04)

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

using std::swap;

CORE_TOOLS_RTTI_DEFINE(CoreTools, BoolObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, BoolObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, BoolObject);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::BoolObject ::BoolObject()
    : ParentType{}, m_BoolValue{ false }, m_BoolArray1{   }, m_BoolArray2{   }
{
    AllocationFirstArray(true);
    AllocationSecondArray(false);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}
#include STSTEM_WARNING_POP

CoreTools::BoolObject ::BoolObject(LoadConstructor value)
    : ParentType{ value }, m_BoolValue{ true }, m_BoolArray1{ nullptr }, m_BoolArray2{   }
{
    AllocationSecondArray(true);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
// private
void CoreTools::BoolObject ::AllocationFirstArray(bool value) noexcept
{
    for (auto i = 0; i < sm_BufferSize; ++i)
    {
        m_BoolArray1[i] = value;
    }
}

// private
void CoreTools::BoolObject ::AllocationSecondArray(bool value)
{
    for (auto i = 0; i < sm_BufferSize; ++i)
    {
        m_BoolArray2[i] = value;
    }
}

CoreTools::BoolObject ::BoolObject(const BoolObject& rhs)
    : ParentType{}, m_BoolValue{ rhs.m_BoolValue }, m_BoolArray1{  }, m_BoolArray2{   }
{
  

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

// private
bool CoreTools::BoolObject ::IsLoadValidity() const
{
    if (m_BoolValue == true || m_BoolArray1 == nullptr || m_BoolArray2 == nullptr)
        return false;

    for (int i = 0; i < sm_BufferSize; ++i)
    {
        if (m_BoolArray1[i] == false || m_BoolArray2[i] == true)
            return false;
    }

    return true;
}

CoreTools::BoolObject& CoreTools::BoolObject ::operator=(const BoolObject& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    BoolObject temp{ rhs };
    Swap(temp);

    return *this;
}

// private
void CoreTools::BoolObject ::Swap(BoolObject& rhs)
{
    swap(m_BoolValue, rhs.m_BoolValue);
    swap(m_BoolArray1, rhs.m_BoolArray1);
    swap(m_BoolArray2, rhs.m_BoolArray2);
}

CoreTools::BoolObject ::~BoolObject()
{
    SELF_CLASS_IS_VALID_1;

    
   // Release();
}

void CoreTools::BoolObject ::Release()
{
    
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BoolObject ::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_BoolArray2 != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::BoolObject ::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    // WriteBool
    size += CORE_TOOLS_STREAM_SIZE(m_BoolValue);

    // WriteBoolWithNumber
    size += sizeof(int);
    size += sm_BufferSize * CORE_TOOLS_STREAM_SIZE(m_BoolValue);

    // WriteBoolWithoutNumber
    size += sm_BufferSize * CORE_TOOLS_STREAM_SIZE(m_BoolValue);

    return size;
}

uint64_t CoreTools::BoolObject ::Register( ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::BoolObject ::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    //  target.WriteBool(m_BoolValue);
    //  target.WriteBoolWithNumber(sm_BufferSize, m_BoolArray1);
    //  target.WriteBoolWithoutNumber(sm_BufferSize, m_BoolArray2);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::BoolObject ::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::BoolObject ::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::BoolObject ::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    m_BoolValue = source.ReadBool();
    auto size = 0;
    source.Read(size);
    if (0 < size)
    {
        

        //  source.ReadBool(sm_BufferSize, m_BoolArray1);
        // source.ReadBool(sm_BufferSize, m_BoolArray2);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::BoolObject::CloneObject() const
{
    return nullptr;
}
#include STSTEM_WARNING_POP