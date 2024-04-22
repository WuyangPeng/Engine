/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/11 22:25)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/ObjectLink.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CoreTools::BufferInStreamImpl::BufferInStreamImpl(const ConstFileBufferSharedPtr& fileBuffer, int startPoint)
    : startPoint{ startPoint },
      topLevel{ InTopLevel::Create() },
      source{ std::make_shared<BufferSource>(fileBuffer) },
      objectLink{ ObjectLink::Create() }
{
    AnalysisBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

void CoreTools::BufferInStreamImpl::AnalysisBuffer()
{
    IncrementBytesProcessed();

    /// ���ؼ����е�Ψһ����
    while (source->GetBytesRead() < source->GetBytesTotal())
    {
        ReadObject();
    }

    objectLink->Sort();

    Link();
    PostLink();
}

void CoreTools::BufferInStreamImpl::IncrementBytesProcessed()
{
    if (0 < startPoint)
    {
        source->IncrementBytesProcessed(startPoint);
    }
}

void CoreTools::BufferInStreamImpl::ReadObject()
{
    /// ��ȡ"Top Level"����RTTI����
    auto name = source->ReadString();
    const auto isTopLevel = (name == TopLevel::GetTopLevelDescription());
    if (isTopLevel)
    {
        /// ��ȡRTTI����
        name = source->ReadString();
    }

    CreateObject(isTopLevel, name);
}

void CoreTools::BufferInStreamImpl::CreateObject(bool isTopLevel, const std::string& name)
{
    /// �õ���Ҫ����ȡ�����͵Ĺ����������������Object::Find(name)ʧ�ܣ���ȷ��������ʹ���������֮ǰ
    /// ��'main' �� 'WinMain'�е���InitTerm::ExecuteInitializer() ,��ʼ������乤��map�ͶԹ�������������䡣
    try
    {
        DoCreateObject(isTopLevel, name);
    }
    catch (const Error& error)
    {
        /// ��ȷ�����Ѿ����CORE_TOOLS_REGISTER_STREAM(someClass)��ÿһ��'someClass'��ͷ�ļ��С��������ÿ����ע�Ṥ��������
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, CoreTools, error, SYSTEM_TEXT("��"), name, SYSTEM_TEXT("��"), LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::BufferInStreamImpl::DoCreateObject(bool isTopLevel, const std::string& name)
{
    if (const auto factory = OBJECT_MANAGER_SINGLETON.Find(name); factory != nullptr)
    {
        /// ��Դ���������ظö���
        const auto object = (*factory)(*source);
        objectLink->Insert(object->GetUniqueId(), object);

        /// ��������Ӧ�ó���ʹ�õĶ������
        if (isTopLevel)
        {
            topLevel.Insert(object);
        }
    }
}

void CoreTools::BufferInStreamImpl::Link()
{
    /// ���Ӷ�����������ȡ���洢������Object*�����ݳ�Ա�ľɵ�ַ��
    /// �µ�ַ���ڵ�ǰ���ó�������ʱ������

    for (const auto& element : *objectLink)
    {
        element->Link(*objectLink);
    }
}

void CoreTools::BufferInStreamImpl::PostLink()
{
    /// �������ִ�����Ӻ�����塣�ڶ�ȡ�������ӵ�ģʽ�У�
    /// Ĭ�Ϲ��캯�����ڴ���һ���������е������ټ��ء����������Ӵ����Ķ���
    /// �����Ӻ�����Ӧ�ó�������ʱ��������ʱ������һЩ��Ĭ�Ϲ��캯�������Ĺ�����

    for (const auto& element : *objectLink)
    {
        element->PostLink();
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferInStreamImpl::IsValid() const noexcept
{
    return 0 <= startPoint;
}

#endif  // OPEN_CLASS_INVARIANT

CoreTools::InTopLevel CoreTools::BufferInStreamImpl::GetTopLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return topLevel;
}
