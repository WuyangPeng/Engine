///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 22:29)

#include "CoreTools/CoreToolsExport.h"

#include "BufferInStreamImpl.h"
#include "TopLevel.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

using std::string;

CoreTools::BufferInStreamImpl::BufferInStreamImpl(const ConstFileBufferSharedPtr& fileBuffer, int startPoint)
    : startPoint{ startPoint },
      topLevel{ InTopLevel::Create() },
      source{ std::make_shared<BufferSource>(fileBuffer) },
      objectLink{ ObjectLink::Create() }
{
    AnalysisBuffer();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::BufferInStreamImpl::AnalysisBuffer()
{
    IncrementBytesProcessed();

    // ���ؼ����е�Ψһ����
    while (source->GetBytesRead() < source->GetBytesTotal())
    {
        ReadObject();
    }

    objectLink->Sort();

    Link();
    PostLink();
}

// private
void CoreTools::BufferInStreamImpl::IncrementBytesProcessed()
{
    if (0 < startPoint)
    {
        source->IncrementBytesProcessed(startPoint);
    }
}

// private
void CoreTools::BufferInStreamImpl::ReadObject()
{
    // ��ȡ"Top Level"����RTTI����
    auto name = source->ReadString();
    const auto isTopLevel = (name == TopLevel::GetTopLevelDescription());
    if (isTopLevel)
    {
        // ��ȡRTTI����
        name = source->ReadString();
    }

    CreateObject(isTopLevel, name);
}

// private
void CoreTools::BufferInStreamImpl::CreateObject(bool isTopLevel, const string& name)
{
    // �õ���Ҫ����ȡ�����͵Ĺ����������������Object::Find(name)ʧ�ܣ���ȷ��������ʹ���������֮ǰ
    // ��'main' �� 'WinMain'�е���InitTerm::ExecuteInitializers() ,��ʼ������乤��map�ͶԹ�������������䡣
    try
    {
        DoCreateObject(isTopLevel, name);
    }
    catch (const Error& error)
    {
        // ��ȷ�����Ѿ����CORE_TOOLS_REGISTER_STREAM(someclass)��ÿһ��'someclass'��ͷ�ļ��С��������ÿ����ע�Ṥ��������
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, CoreTools)
            << error 
            << SYSTEM_TEXT("��")
            << name
            << SYSTEM_TEXT("��")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void CoreTools::BufferInStreamImpl::DoCreateObject(bool isTopLevel, const string& name)
{
    const auto factory = OBJECT_MANAGER_SINGLETON.Find(name);

    if (factory != nullptr)
    {
        // ��Դ���������ظö���
        auto object = (*factory)(*source);
        objectLink->Insert(object->GetUniqueID(), object);

        // ��������Ӧ�ó���ʹ�õĶ������
        if (isTopLevel)
        {
            topLevel.Insert(object);
        }
    }
}

// private
void CoreTools::BufferInStreamImpl::Link()
{
    // ���Ӷ�����������ȡ���洢������Object*�����ݳ�Ա�ľɵ�ַ��
    // �µ�ַ���ڵ�ǰ���ó�������ʱ������

    for (auto& value : *objectLink)
    {
        value->Link(*objectLink);
    }
}

// private
void CoreTools::BufferInStreamImpl::PostLink()
{
    // �������ִ�����Ӻ�����塣�ڶ�ȡ�������ӵ�ģʽ�У�
    // Ĭ�Ϲ��캯�����ڴ���һ���������е������ټ��ء����������Ӵ����Ķ���
    // �����Ӻ�����Ӧ�ó�������ʱ��������ʱ������һЩ��Ĭ�Ϲ��캯�������Ĺ�����

    for (auto& value : *objectLink)
    {
        value->PostLink();
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::BufferInStreamImpl::IsValid() const noexcept
{
    if (0 <= startPoint)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

const CoreTools::InTopLevel CoreTools::BufferInStreamImpl::GetTopLevel() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return topLevel;
}
