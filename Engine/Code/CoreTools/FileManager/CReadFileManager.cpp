/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:06)

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

int CoreTools::CReadFileManager::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileByteSize();
}

int CoreTools::CReadFileManager::GetCharacter()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetCharacter();
}

bool CoreTools::CReadFileManager::UnGetCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->UnGetCharacter(character);
}

std::string CoreTools::CReadFileManager::GetString(int count)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetString(count);
}

bool CoreTools::CReadFileManager::IsEof() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->IsEof();
}

bool CoreTools::CReadFileManager::Flush() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Flush();
}

CoreTools::CReadFileManager::PosType CoreTools::CReadFileManager::GetPosition()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetPosition();
}

bool CoreTools::CReadFileManager::SetPosition(PosType position) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->SetPosition(position);
}

long CoreTools::CReadFileManager::Tell() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Tell();
}

void CoreTools::CReadFileManager::Rewind() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Rewind();
}

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

bool CoreTools::CReadFileManager::Seek(long offset, FileSeek whence) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Seek(offset, whence);
}

bool CoreTools::CReadFileManager::SetVBuffer(FileSetVBuffer type, size_t size) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetVBuffer(type, size);
}
