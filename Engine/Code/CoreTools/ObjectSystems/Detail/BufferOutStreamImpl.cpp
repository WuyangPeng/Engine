///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 22:42)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/Stream.h"

using std::make_shared;
using std::string;

CoreTools::BufferOutStreamImpl::BufferOutStreamImpl(const OutTopLevel& topLevel)
    : topLevel{ topLevel }, objectRegister{ ObjectRegister::Create() }, buffer{}, target{}
{
    GenerateBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BufferOutStreamImpl::GenerateBuffer()
{
    Register();

    const auto bufferSize = GetBufferSize();

    if (0 < bufferSize)
    {
        ResetBufferSize(bufferSize);
        SaveToBuffer();
    }
}

// private
void CoreTools::BufferOutStreamImpl::Register()
{
    // 创建唯一对象集合在对象图中。
    // 使我们可以创建用于写入缓冲区所需的数据流的字节数的确切大小。
    for (const auto& object : topLevel)
    {
        const auto uniqueID = object->Register(*objectRegister);
        if (uniqueID == 0)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("uniqueID == 0"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

// private
int CoreTools::BufferOutStreamImpl::GetBufferSize()
{
    auto bufferSize = 0;

    for (const auto& value : *objectRegister)
    {
        bufferSize += value.object->GetStreamingSize();
    }

    // 调整缓冲区大小考虑到了“Top Level”字符串。
    const auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * topLevel.GetTopLevelSize();

    return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "缓冲区大小小于或等于0！");

    // 创建对象将要被写入的缓冲区。
    buffer = make_shared<FileBuffer>(bufferSize);
    target = make_shared<BufferTarget>(bufferSize, objectRegister);
}

void CoreTools::BufferOutStreamImpl::SaveToBuffer()
{
    // 保存对象到目标缓冲区。

    for (const auto& value : *objectRegister)
    {
        if (topLevel.IsTopLevel(value.object))
        {
            target->Write(TopLevel::GetTopLevelDescription().data());
        }
        value.object->Save(*target);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferOutStreamImpl::IsValid() const noexcept
{
    if (buffer != nullptr && target != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::FileBufferSharedPtr CoreTools::BufferOutStreamImpl::GetBufferOutStreamInformation() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return buffer;
}
