// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 11:57)

#include "CoreTools/CoreToolsExport.h"

#include "BufferPoolImpl.h"
#include "CoreTools/MemoryTools/Buffer.h"
#include "CoreTools/MemoryTools/PoolDetail.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferPoolImpl
	::BufferPoolImpl() noexcept
	:ParentType{}, m_MinSize{ 0 }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, BufferPoolImpl)

CoreTools::Buffer* CoreTools::BufferPoolImpl
	::Get()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return GetBuffer(Buffer::GetMaxSize());
}

void CoreTools::BufferPoolImpl
	::Release(Buffer* ptr)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	if (ptr != nullptr)
	{
		ptr->ResetData();

		ParentType::Release(ptr);
	}	
}

CoreTools::Buffer* CoreTools::BufferPoolImpl
	::GetBuffer(int minSize)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	m_MinSize = minSize;

	return ParentType::Get();
}

CoreTools::Buffer* CoreTools::BufferPoolImpl
	::DoGet()
{
	// û���㹻��Ŀ��û�����������һ���µ�
	return CoreTools::New0<Buffer>(m_MinSize);
}

bool CoreTools::BufferPoolImpl
	::ConformCondition(Buffer* ptr) noexcept
{
	if (ptr != nullptr && m_MinSize <= ptr->GetSize())
		return true;
	else
		return false;
}