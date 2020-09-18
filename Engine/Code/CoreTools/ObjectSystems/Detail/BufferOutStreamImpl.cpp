// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.1 (2020/01/21 15:47)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/Stream.h"

using std::make_pair;
using std::make_shared;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26486)

CoreTools::BufferOutStreamImpl ::BufferOutStreamImpl(const OutTopLevel& topLevel)
    : m_TopLevel{ topLevel }, m_ObjectRegister{ make_shared<ObjectRegister>() }, m_BufferPtr{}, m_TargetPtr{}
{
    GenerateBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BufferOutStreamImpl ::GenerateBuffer()
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
void CoreTools::BufferOutStreamImpl ::Register()
{
    // 插入空指针和零索引的配对。
    //m_ObjectRegister.RegisterRoot(ConstObjectInterfaceSharedPtr());

    // 创建唯一对象集合在对象图中。
    // 使我们可以创建用于写入缓冲区所需的数据流的字节数的确切大小。
    for (const auto& object : m_TopLevel)
    {
        object->Register(m_ObjectRegister);
    }
}

// private
int CoreTools::BufferOutStreamImpl ::GetBufferSize()
{
    auto bufferSize = 0;

    // 从1开始计数

    for (const auto& value : *m_ObjectRegister)
    {
        bufferSize += value.m_Object->GetStreamingSize();
    }

    // 调整缓冲区大小考虑到了“Top Level”字符串。
    auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * m_TopLevel.GetTopLevelSize();

    return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl ::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "缓冲区大小小于或等于0！");

    // 创建对象将要被写入的缓冲区。
    m_BufferPtr = make_shared<FileBuffer>(bufferSize);
    m_TargetPtr = make_shared<BufferTarget>(bufferSize, m_ObjectRegister);
}

void CoreTools::BufferOutStreamImpl ::SaveToBuffer()
{
    // 保存对象到目标缓冲区。
    // 从1开始计数

    for (const auto& value : *m_ObjectRegister)
    {
        if (m_TopLevel.IsTopLevel(value.m_Object))
        {
            m_TargetPtr->Write(TopLevel::GetTopLevelDescription());
        }
        value.m_Object->Save(m_TargetPtr);
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferOutStreamImpl ::IsValid() const noexcept
{
    if (m_BufferPtr != nullptr && m_TargetPtr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::BufferOutStreamImpl::FileBufferPtr CoreTools::BufferOutStreamImpl ::GetBufferOutStreamInformation() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_BufferPtr;
}

#include STSTEM_WARNING_POP