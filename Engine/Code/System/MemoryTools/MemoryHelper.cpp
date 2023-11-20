///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 17:01)

#include "System/SystemExport.h"

#include "MemoryHelper.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdlib>
#include <cstring>

void System::MemorySet(void* bytes, int value, int byteSize) noexcept
{
    ::memset(bytes, value, byteSize);
}

void System::MemoryCopy(void* dst, const void* src, uint32_t count) noexcept
{
    ::memcpy(dst, src, count);
}

void* System::MallocMemory(size_t size) noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)

    return ::malloc(size);

#include SYSTEM_WARNING_POP
}

void System::FreeMemory(void* memory) noexcept
{
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)

    ::free(memory);

#include SYSTEM_WARNING_POP
}
