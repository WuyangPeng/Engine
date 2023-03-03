///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 10:57)

#include "CoreTools/CoreToolsExport.h"

#include "CReadFileManager.h"
#include "Detail/CReadFileManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::CReadFileManager::CReadFileManager(const String& fileName)
    : impl{ fileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CReadFileManager)

void CoreTools::CReadFileManager::Read(size_t itemSize, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, data);
}

void CoreTools::CReadFileManager::Read(size_t itemSize, size_t itemsNumber, void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Read(itemSize, itemsNumber, data);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetFileByteSize, int);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetCharacter, int);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, UnGetCharacter, int, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, CReadFileManager, GetString, int, std::string);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, IsEof, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Flush, bool);

bool CoreTools::CReadFileManager::Seek(long offset, FileSeek whence) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Seek(offset, whence);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, CReadFileManager, GetPosition, CoreTools::CReadFileManager::PosType);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(CoreTools, CReadFileManager, SetPosition, PosType, bool);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Tell, long);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, CReadFileManager, Rewind, void);

bool CoreTools::CReadFileManager::SetVBuffer(FileSetVBuffer type, size_t size) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetVBuffer(type, size);
}
