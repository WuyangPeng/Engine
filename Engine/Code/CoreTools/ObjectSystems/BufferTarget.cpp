///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 17:09)

#include "CoreTools/CoreToolsExport.h"

#include "BufferTargetDetail.h"
#include "ObjectRegister.h"
#include "StreamSize.h"
#include "Detail/BufferTargetImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
    Write(CoreTools::GetStreamSize(value), &value);
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

        // �ַ�����д��Ϊ4�ֽڵı�����
        constexpr std::array<char, gDefaultSize> zero{};

        if (auto padding = length % gDefaultSize; 0 < padding)
        {
            padding = gDefaultSize - padding;
            Write(CoreTools::GetStreamSize<char>(), padding, zero.data());
        }
    }
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, BufferTarget, WriteUniqueId, ConstObjectInterfaceSharedPtr, void)
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
