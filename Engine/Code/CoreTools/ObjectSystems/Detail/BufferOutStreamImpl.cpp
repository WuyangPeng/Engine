/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:24)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegister.h"
#include "CoreTools/ObjectSystems/Stream.h"

CoreTools::BufferOutStreamImpl::BufferOutStreamImpl(OutTopLevel topLevel)
    : topLevel{ std::move(topLevel) }, objectRegister{ ObjectRegister::Create() }, target{}
{
    GenerateBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::BufferOutStreamImpl::GenerateBuffer()
{
    Register();

    if (const auto bufferSize = GetBufferSize();
        0 < bufferSize)
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
        if (const auto uniqueId = object->Register(*objectRegister);
            uniqueId == 0)
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

    /// ������������С���ǵ��ˡ�Top Level���ַ�����
    const auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * topLevel.GetTopLevelSize();

    return bufferSize;
}

void CoreTools::BufferOutStreamImpl::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "��������СС�ڻ����0��");

    /// ��������Ҫ��д��Ļ�������
    target = make_shared<BufferTarget>(bufferSize, objectRegister);
}

void CoreTools::BufferOutStreamImpl::SaveToBuffer()
{
    /// �������Ŀ�껺������
    for (const auto& element : *objectRegister)
    {
        if (topLevel.IsTopLevel(element.object))
        {
            target->Write(TopLevel::GetTopLevelDescription().data());
        }
        element.object->Save(*target);
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferOutStreamImpl::IsValid() const noexcept
{
    return target != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::ConstFileBufferSharedPtr CoreTools::BufferOutStreamImpl::GetBufferOutStreamInformation() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return target->GetFileBuffer();
}
