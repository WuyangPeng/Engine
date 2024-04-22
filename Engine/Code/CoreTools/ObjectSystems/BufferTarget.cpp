/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:22)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTargetDetail.h"
#include "ObjectRegister.h"
#include "StreamSize.h"
#include "Detail/BufferTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::BufferTarget::BufferTarget(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister)
    : impl{ bufferSize, objectRegister }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTarget)

void CoreTools::BufferTarget::Write(bool datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const uint32_t value{ datum ? 0xFFFFFFFFu : 0u };
    Write(GetStreamSize(value), &value);
}

void CoreTools::BufferTarget::Write(const char* datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Write(std::string{ datum });
}

void CoreTools::BufferTarget::Write(const std::string& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto length = boost::numeric_cast<int32_t>(datum.length());
    Write(length);

    if (0 < length)
    {
        Write(sizeof(char), length, datum.c_str());

        /// 字符串被写入为4字节的倍数。
        constexpr std::array<char, gDefaultSize> zero{};

        if (auto padding = length % gDefaultSize; 0 < padding)
        {
            padding = gDefaultSize - padding;
            Write(CoreTools::GetStreamSize<char>(), padding, zero.data());
        }
    }
}

void CoreTools::BufferTarget::Write(size_t itemSize, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::BufferTarget::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}

int CoreTools::BufferTarget::GetBytesWritten() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetBytesWritten();
}

void CoreTools::BufferTarget::WriteUniqueId(const ConstObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->WriteUniqueId(object);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTarget::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileBuffer();
}
