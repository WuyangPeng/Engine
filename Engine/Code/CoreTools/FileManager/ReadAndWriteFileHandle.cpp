// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/19 17:15)

#include "CoreTools/CoreToolsExport.h"

#include "ReadAndWriteFileHandle.h"
#include "Detail/ReadAndWriteFileHandleImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::ReadAndWriteFileHandle
	::ReadAndWriteFileHandle(const String& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ReadAndWriteFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ReadAndWriteFileHandle, GetFileLength, uint64_t);

void CoreTools::ReadAndWriteFileHandle
	::Read(size_t itemSize, void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Read(itemSize, data);
}

void CoreTools::ReadAndWriteFileHandle
	::Read(size_t itemSize, size_t itemsNumber, void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Read(itemSize, itemsNumber, data);
}

void CoreTools::ReadAndWriteFileHandle
	::Write(size_t itemSize, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, data);
}

void CoreTools::ReadAndWriteFileHandle
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, itemsNumber, data);
}
