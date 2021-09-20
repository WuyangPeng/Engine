//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/22 15:04)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTargetDetail.h"
#include "ObjectRegister.h"
#include "StreamSize.h"
#include "Detail/BufferTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::array;
using std::make_shared;
using std::string;

CoreTools::BufferTarget::BufferTarget(int bufferSize, const ConstObjectRegisterSharedPtr& objectRegister)
    : impl{  bufferSize, objectRegister  }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTarget)

void CoreTools::BufferTarget::Write(const bool datum)
{
    

    const uint32_t value{ datum ? 0xFFFFFFFFu : 0u };
    Write(CORE_TOOLS_STREAM_SIZE(value), &value);
}

void CoreTools::BufferTarget::Write(const char* datum)
{
    

    Write(string{ datum });
}

void CoreTools::BufferTarget::Write(const string& datum)
{
    

    auto length = boost::numeric_cast<int32_t>(datum.length());
    Write(length);

    if (0 < length)
    {
        Write(sizeof(char), length, datum.c_str());

        // 字符串被写入为4字节的倍数。
        array<char, g_DefaultSize> zero{};
        auto padding = length % g_DefaultSize;
        if (0 < padding)
        {
            padding = g_DefaultSize - padding;
            Write(CoreTools::GetStreamSize<char>(), padding, zero.data());
        }
    }
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, BufferTarget, WriteUniqueID, ConstObjectInterfaceSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, BufferTarget, GetBytesWritten, int)

void CoreTools::BufferTarget::Write(size_t itemSize, const void* data)
{
    

    return impl->Write(itemSize, data);
}

void CoreTools::BufferTarget::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    

    return impl->Write(itemSize, itemsNumber, data);
}
