///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 16:52)

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

CoreTools::BufferOutStreamImpl::BufferOutStreamImpl(OutTopLevel topLevel)
    : topLevel{ std::move(topLevel) }, objectRegister{ ObjectRegister::Create() }, buffer{}, target{}
{
    GenerateBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::BufferOutStreamImpl::GenerateBuffer()
{
    Register();

    if (const auto bufferSize = GetBufferSize(); 0 < bufferSize)
    {
        ResetBufferSize(bufferSize);
        SaveToBuffer();
    }
}

void CoreTools::BufferOutStreamImpl::Register()
{
    // ����Ψһ���󼯺��ڶ���ͼ�С�
    // ʹ���ǿ��Դ�������д�뻺������������������ֽ�����ȷ�д�С��
    for (const auto& object : topLevel)
    {
        if (const auto uniqueID = object->Register(*objectRegister); uniqueID == 0)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools, SYSTEM_TEXT("uniqueId == 0"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

int CoreTools::BufferOutStreamImpl::GetBufferSize() const
{
    auto bufferSize = 0;

    for (const auto& value : *objectRegister)
    {
        bufferSize += value.object->GetStreamingSize();
    }

    // ������������С���ǵ��ˡ�Top Level���ַ�����
    const auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * topLevel.GetTopLevelSize();

    return bufferSize;
}

void CoreTools::BufferOutStreamImpl::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "��������СС�ڻ����0��");

    // ��������Ҫ��д��Ļ�������
    buffer = std::make_shared<FileBuffer>(bufferSize);
    target = make_shared<BufferTarget>(bufferSize, objectRegister);
}

void CoreTools::BufferOutStreamImpl::SaveToBuffer()
{
    // �������Ŀ�껺������
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
