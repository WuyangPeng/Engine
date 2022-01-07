// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 14:14)

#include "StringObject.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;
using std::swap;
using namespace std::literals;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26409)

#include SYSTEM_WARNING_DISABLE(26426)
namespace
{
    const string g_String1{ "FristString"s };
    const string g_String2{ "SecondString"s };
}

CORE_TOOLS_RTTI_DEFINE(CoreTools, StringObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, StringObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, StringObject);

CoreTools::StringObject ::StringObject()
    : ParentType{}, m_StringValue{   },
      m_StringArray1{   },
      m_StringArray2{   }
{
    AllocationArray1(g_String2);
    AllocationArray2(g_String1);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::StringObject ::StringObject(LoadConstructor value)
    : ParentType{ value }, m_StringValue{   },
      m_StringArray1{ nullptr },
      m_StringArray2{  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::StringObject ::AllocationArray1(const string& value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        m_StringArray1[i] = value;
    }
}

// private
void CoreTools::StringObject ::AllocationArray2(const string& value)
{
    for (auto i = 0; i < bufferSize; ++i)
    {
        m_StringArray2[i] = value;
    }
}

CoreTools::StringObject ::StringObject(const StringObject& rhs)
    : ParentType{}, m_StringValue{ rhs.m_StringValue },
      m_StringArray1{   },
      m_StringArray2{  }
{


    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::StringObject& CoreTools::StringObject ::operator=(const StringObject& rhs)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    StringObject temp{ rhs };
    Swap(temp);

    return *this;
}

// private
void CoreTools::StringObject ::Swap(StringObject& rhs)
{
    swap(m_StringValue, rhs.m_StringValue);
    swap(m_StringArray1, rhs.m_StringArray1);
    swap(m_StringArray2, rhs.m_StringArray2);
}

CoreTools::StringObject ::~StringObject()
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;

    //    Release();
}

void CoreTools::StringObject ::Release()
{
    
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::StringObject ::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_StringValue != nullptr && m_StringArray2 != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

// private
bool CoreTools::StringObject ::IsLoadValidity() const
{
    if (m_StringValue == nullptr || m_StringArray1 == nullptr || m_StringArray2 == nullptr || *m_StringValue != g_String1)
        return false;

    for (auto i = 0; i < bufferSize; ++i)
    {
        if (!(m_StringArray1[i] == g_String2 && m_StringArray2[i] == g_String1))
            return false;
    }

    return true;
}

int CoreTools::StringObject ::GetStreamingSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    // WriteString
    size += CORE_TOOLS_STREAM_SIZE(g_String1);

    // WriteStringWithNumber
    size += sizeof(int);
    for (auto i = 0; i < bufferSize; ++i)
    {
        size += CORE_TOOLS_STREAM_SIZE(g_String2);
    }

    // WriteStringWithoutNumber
    for (auto i = 0; i < bufferSize; ++i)
    {
        size += CORE_TOOLS_STREAM_SIZE(g_String1);
    }

    return size;
}

uint64_t CoreTools::StringObject ::Register(ObjectRegister& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void CoreTools::StringObject ::Save(BufferTarget& target) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::StringObject ::Link(ObjectLink& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::Link(source);
}

void CoreTools::StringObject ::PostLink()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return ParentType::PostLink();
}

void CoreTools::StringObject ::Load(BufferSource& source)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    *m_StringValue = source.ReadString();
    auto size = 0;
    source.Read(size);
    if (0 < size)
    {
      

        //         source.ReadString(bufferSize, m_StringArray1);
        //         source.ReadString(bufferSize, m_StringArray2);
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

    CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::StringObject::CloneObject() const
{
    return nullptr;
}
#include STSTEM_WARNING_POP