///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/03 14:39)

#include "CoreTools/CoreToolsExport.h"

#include "CWriteFileManager.h"
#include "Detail/CWriteFileManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

CoreTools::CWriteFileManager::CWriteFileManager(const String& fileName, bool addition)
    : impl{ fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CWriteFileManager)

void CoreTools::CWriteFileManager::Write(size_t itemSize, const void* data)
{
    return impl->Write(itemSize, data);
}

void CoreTools::CWriteFileManager::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    return impl->Write(itemSize, itemsNumber, data);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CWriteFileManager, GetFileByteSize, uint32_t);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CWriteFileManager, PutCharacter, int, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, CWriteFileManager, PutString, string, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CWriteFileManager, IsEOF, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CWriteFileManager, Flush, bool);

bool CoreTools::CWriteFileManager::Seek(long offset, FileSeek whence) noexcept
{
    return impl->Seek(offset, whence);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CWriteFileManager, GetPosition, CoreTools::CWriteFileManager::PosType);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, CWriteFileManager, SetPosition, PosType, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CWriteFileManager, Tell, long);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CWriteFileManager, Rewind, void);

bool CoreTools::CWriteFileManager::Setvbuf(FileSetvBuf type, size_t size) noexcept
{
    return impl->Setvbuf(type, size);
}
