//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 14:48)

#include "CoreTools/CoreToolsExport.h"

#include "BufferOutStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/Stream.h"

using std::make_pair;
using std::make_shared;
using std::string;

CoreTools::BufferOutStreamImpl::BufferOutStreamImpl(const OutTopLevel& topLevel)
    : m_TopLevel{ topLevel }, m_ObjectRegister{ make_shared<ObjectRegister>(DisableNotThrow::Disable) }, m_Buffer{}, m_Target{}
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
    // ����Ψһ���󼯺��ڶ���ͼ�С�
    // ʹ���ǿ��Դ�������д�뻺������������������ֽ�����ȷ�д�С��
    for (const auto& object : m_TopLevel)
    {
        const auto uniqueID = object->Register(m_ObjectRegister);
        if (uniqueID == 0)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
                << SYSTEM_TEXT("uniqueID == 0")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
}

// private
int CoreTools::BufferOutStreamImpl::GetBufferSize()
{
    auto bufferSize = 0;

    for (const auto& value : *m_ObjectRegister)
    {
        bufferSize += value.m_Object->GetStreamingSize();
    }

    // ������������С���ǵ��ˡ�Top Level���ַ�����
    const auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * m_TopLevel.GetTopLevelSize();

    return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "��������СС�ڻ����0��");

    // ��������Ҫ��д��Ļ�������
    m_Buffer = make_shared<FileBuffer>(bufferSize);
    m_Target = make_shared<BufferTarget>(bufferSize, m_ObjectRegister);
}

void CoreTools::BufferOutStreamImpl::SaveToBuffer()
{
    // �������Ŀ�껺������

    for (const auto& value : *m_ObjectRegister)
    {
        if (m_TopLevel.IsTopLevel(value.m_Object))
        {
            m_Target->Write(TopLevel::GetTopLevelDescription());
        }
        value.m_Object->Save(m_Target);
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::BufferOutStreamImpl::IsValid() const noexcept
{
    if (m_Buffer != nullptr && m_Target != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

CoreTools::FileBufferSharedPtr CoreTools::BufferOutStreamImpl::GetBufferOutStreamInformation() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Buffer;
}
