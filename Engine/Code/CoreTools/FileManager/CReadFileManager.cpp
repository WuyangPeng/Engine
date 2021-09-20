//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/14 14:19)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManager.h"
#include "Detail/CReadFileManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

CoreTools::CReadFileManager::CReadFileManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CReadFileManager)

void CoreTools::CReadFileManager::Read(size_t itemSize, void* data)
{
    return impl->Read(itemSize, data);
}

void CoreTools::CReadFileManager::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    return impl->Read(itemSize, itemsNumber, data);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetFileByteSize, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetCharacter, int);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, UnGetCharacter, int, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, GetString, int, string);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, IsEOF, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Flush, bool);

bool CoreTools::CReadFileManager::Seek(long offset, FileSeek whence) noexcept
{
    return impl->Seek(offset, whence);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetPosition, CoreTools::CReadFileManager::PosType);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, CReadFileManager, SetPosition, PosType, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Tell, long);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Rewind, void);

bool CoreTools::CReadFileManager::Setvbuf(FileSetvBuf type, size_t size) noexcept
{
    return impl->Setvbuf(type, size);
}
