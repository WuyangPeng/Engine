// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/06 14:07)

#include "EnumObject.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferInStream.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::swap;

CORE_TOOLS_RTTI_DEFINE(CoreTools, EnumObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(CoreTools, EnumObject);
CORE_TOOLS_FACTORY_DEFINE(CoreTools, EnumObject);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26432)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26455)
CoreTools::EnumObject
	::EnumObject()
	:ParentType{}, m_EnumValue{ EnumObjectEnum::Five }, m_EnumArray1{ NEW1<EnumObjectEnum>(sm_BufferSize) }, m_EnumArray2{ NEW1<EnumObjectEnum>(sm_BufferSize) }
{
	AllocationFirstArray(EnumObjectEnum::Ten);
	AllocationSecondArray(EnumObjectEnum::Five);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

// private
bool CoreTools::EnumObject
	::IsLoadValidity() const
{
	if (m_EnumValue == EnumObjectEnum::Ten || m_EnumArray1 == nullptr || m_EnumArray2 == nullptr)
		return false;

	for (auto i = 0; i < sm_BufferSize; ++i)
	{
		if (m_EnumArray1[i] == EnumObjectEnum::Five || m_EnumArray2[i] == EnumObjectEnum::Ten)
			return false;
	}

	return true;
}

CoreTools::EnumObject
	::EnumObject(LoadConstructor value)
	:ParentType{ value }, m_EnumValue{ EnumObjectEnum::Ten }, m_EnumArray1{ nullptr }, m_EnumArray2{ NEW1<EnumObjectEnum>(sm_BufferSize) }
{
	AllocationSecondArray(EnumObjectEnum::Ten);

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::EnumObject
	::AllocationFirstArray(EnumObjectEnum value)
{
	for (auto i = 0; i < sm_BufferSize; ++i)
	{
		m_EnumArray1[i] = value;
	}
}

// private
void CoreTools::EnumObject
	::AllocationSecondArray(EnumObjectEnum value)
{
	for (auto i = 0; i < sm_BufferSize; ++i)
	{
		m_EnumArray2[i] = value;
	}
}

CoreTools::EnumObject
	::EnumObject(const EnumObject& rhs)
	:ParentType{}, m_EnumValue{ rhs.m_EnumValue }, m_EnumArray1{ NEW1<EnumObjectEnum>(sm_BufferSize) }, m_EnumArray2{ NEW1<EnumObjectEnum>(sm_BufferSize) }
{
	for (auto i = 0; i < sm_BufferSize; ++i)
	{
		m_EnumArray1[i] = rhs.m_EnumArray1[i];
		m_EnumArray2[i] = rhs.m_EnumArray2[i];
	}

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

	CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::EnumObject& CoreTools::EnumObject
	::operator=(const EnumObject& rhs)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	EnumObject temp{ rhs };
	Swap(temp);

	return *this;
}

// private
void CoreTools::EnumObject
	::Swap(EnumObject& rhs)
{
	swap(m_EnumValue, rhs.m_EnumValue);
	swap(m_EnumArray1, rhs.m_EnumArray1);
	swap(m_EnumArray2, rhs.m_EnumArray2);
}

CoreTools::EnumObject
	::~EnumObject()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;

//	Release();
}

void CoreTools::EnumObject
	::Release()
{
	DELETE1<EnumObjectEnum>(m_EnumArray1);
	DELETE1<EnumObjectEnum>(m_EnumArray2);
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::EnumObject
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_EnumArray2 != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

int CoreTools::EnumObject
	::GetStreamingSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto size = ParentType::GetStreamingSize();

	// WriteEnum
	size += CORE_TOOLS_STREAM_SIZE(m_EnumValue);

	// WriteEnumWithNumber
	size += sizeof(int);
	size += sm_BufferSize * CORE_TOOLS_STREAM_SIZE(m_EnumValue);

	// WriteEnumWithoutNumber
	size += sm_BufferSize * CORE_TOOLS_STREAM_SIZE(m_EnumValue);

	return size;
}

uint64_t CoreTools::EnumObject
	::Register(const ObjectRegisterSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return ParentType::Register(target);
}

void CoreTools::EnumObject ::Save(const BufferTargetSharedPtr& target) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

	ParentType::Save(target);

	target->WriteEnum(m_EnumValue);
   //     target->WriteEnumWithNumber(sm_BufferSize, m_EnumArray1);
    //    target->WriteEnumWithoutNumber(sm_BufferSize, m_EnumArray2);

	CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void CoreTools::EnumObject ::Link(const ObjectLinkSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return ParentType::Link(source);
}

void CoreTools::EnumObject
	::PostLink()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return ParentType::PostLink();
}

void CoreTools::EnumObject ::Load(const BufferSourceSharedPtr& source)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

	ParentType::Load(source);

	source->ReadEnum(m_EnumValue);
	auto size = 0;
        source->Read(size);
	if (0 < size)
	{
		m_EnumArray1 = NEW1<EnumObjectEnum>(size);

		//source->ReadEnum(sm_BufferSize, m_EnumArray1);
          //      source->ReadEnum(sm_BufferSize, m_EnumArray2);
	}

	CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);

	CORE_TOOLS_ASSERTION_1(IsLoadValidity(), "载入的数据出现错误！");
}

CoreTools::ObjectInterfaceSharedPtr CoreTools::EnumObject::CloneObject() const
{
    return nullptr;
    
}





#include STSTEM_WARNING_POP