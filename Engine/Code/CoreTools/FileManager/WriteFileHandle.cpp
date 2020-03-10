// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/19 17:16)

#include "CoreTools/CoreToolsExport.h"

#include "Detail/WriteFileHandleImpl.h"
#include "WriteFileHandle.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_shared;

CoreTools::WriteFileHandle
	::WriteFileHandle(const String& fileName, FileHandleCreationDisposition creation)
	:m_Impl{ make_shared<ImplType>(fileName,creation) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, WriteFileHandle)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, WriteFileHandle, GetFileByteSize, int)

void CoreTools::WriteFileHandle
	::Write(size_t itemSize, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, data);
}

void CoreTools::WriteFileHandle
	::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Write(itemSize, itemsNumber, data);
}





