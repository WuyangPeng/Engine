// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.1 (2020/01/19 17:04)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManager.h"
#include "Detail/CReadFileManagerImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::CReadFileManager
	::CReadFileManager(const String& fileName)
	:m_Impl{ make_shared<ImplType>(fileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, CReadFileManager)

void CoreTools::CReadFileManager
	::Read(size_t itemSize, void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Read(itemSize, data);
}

void CoreTools::CReadFileManager
	::Read(size_t itemSize, size_t itemsNumber, void* data)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Read(itemSize, itemsNumber, data);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetFileByteSize, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetCharacter, int);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, UnGetCharacter, int, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, GetString, int, string);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, IsEOF, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Flush, bool);

bool CoreTools::CReadFileManager
	::Seek(long offset, FileSeek whence) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Seek(offset, whence);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetPosition, CoreTools::CReadFileManager::PosType);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, CReadFileManager, SetPosition, PosType, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Tell, long);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Rewind, void);

bool CoreTools::CReadFileManager
	::Setvbuf(FileSetvBuf type, size_t size) noexcept
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Setvbuf(type, size);
}

