// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.1 (2020/01/21 15:47)

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
    // �����ָ�������������ԡ�
    //m_ObjectRegister.RegisterRoot(ConstObjectInterfaceSharedPtr());

    // ����Ψһ���󼯺��ڶ���ͼ�С�
    // ʹ���ǿ��Դ�������д�뻺������������������ֽ�����ȷ�д�С��
    for (const auto& object : m_TopLevel)
    {
        object->Register(m_ObjectRegister);
    }
}

// private
int CoreTools::BufferOutStreamImpl ::GetBufferSize()
{
    auto bufferSize = 0;

    // ��1��ʼ����

    for (const auto& value : *m_ObjectRegister)
    {
        bufferSize += value.m_Object->GetStreamingSize();
    }

    // ������������С���ǵ��ˡ�Top Level���ַ�����
    auto topLevelBytesNumber = Stream::GetStreamingSize(TopLevel::GetTopLevelDescription());
    bufferSize += topLevelBytesNumber * m_TopLevel.GetTopLevelSize();

    return bufferSize;
}

// private
void CoreTools::BufferOutStreamImpl ::ResetBufferSize(int bufferSize)
{
    CORE_TOOLS_ASSERTION_0(0 < bufferSize, "��������СС�ڻ����0��");

    // ��������Ҫ��д��Ļ�������
    m_BufferPtr = make_shared<FileBuffer>(bufferSize);
    m_TargetPtr = make_shared<BufferTarget>(bufferSize, m_ObjectRegister);
}

void CoreTools::BufferOutStreamImpl ::SaveToBuffer()
{
    // �������Ŀ�껺������
    // ��1��ʼ����

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