/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/01 10:49)

#include "CoreTools/CoreToolsExport.h"

#include "CWriteFileManager.h"
#include "Detail/CWriteFileManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::CWriteFileManager::CWriteFileManager(const String& fileName, bool addition)
    : impl{ fileName, addition }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CWriteFileManager)

uint32_t CoreTools::CWriteFileManager::GetFileByteSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileByteSize();
}

bool CoreTools::CWriteFileManager::PutCharacter(int character)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->PutCharacter(character);
}

bool CoreTools::CWriteFileManager::PutString(const std::string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->PutString(str);
}

bool CoreTools::CWriteFileManager::IsEof() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->IsEof();
}

bool CoreTools::CWriteFileManager::Flush() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Flush();
}

CoreTools::CWriteFileManager::PosType CoreTools::CWriteFileManager::GetPosition()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetPosition();
}

bool CoreTools::CWriteFileManager::SetPosition(PosType position) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetPosition(position);
}

long CoreTools::CWriteFileManager::Tell() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Tell();
}

void CoreTools::CWriteFileManager::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::CWriteFileManager::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}

bool CoreTools::CWriteFileManager::Seek(long offset, FileSeek whence) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Seek(offset, whence);
}

bool CoreTools::CWriteFileManager::SetVBuffer(FileSetVBuffer type, size_t size) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetVBuffer(type, size);
}
