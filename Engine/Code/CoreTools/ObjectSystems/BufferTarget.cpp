///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:07)

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
    : impl{ bufferSize, objectRegister }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, BufferTarget)

void CoreTools::BufferTarget::Write(const bool datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const uint32_t value{ datum ? 0xFFFFFFFFu : 0u };
    Write(CORE_TOOLS_STREAM_SIZE(value), &value);
}

void CoreTools::BufferTarget::Write(const char* datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Write(string{ datum });
}

void CoreTools::BufferTarget::Write(const string& datum)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto length = boost::numeric_cast<int32_t>(datum.length());
    Write(length);

    if (0 < length)
    {
        Write(sizeof(char), length, datum.c_str());

        // �ַ�����д��Ϊ4�ֽڵı�����
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
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, data);
}

void CoreTools::BufferTarget::Write(size_t itemSize, size_t itemsNumber, const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(itemSize, itemsNumber, data);
}

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferTarget::GetFileBuffer() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFileBuffer();
}
