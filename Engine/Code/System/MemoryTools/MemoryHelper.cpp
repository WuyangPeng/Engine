///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/16 19:26)

#include "System/SystemExport.h"

#include "MemoryHelper.h"
#include "Using/VirtualToolsUsing.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/WindowsMacro.h"

#include <cstdlib>

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)

    return ::malloc(size);

#include STSTEM_WARNING_POP
}

void System::FreeMemory(void* memory) noexcept
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26408)

    ::free(memory);

#include STSTEM_WARNING_POP
}
