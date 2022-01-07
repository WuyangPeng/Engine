///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 22:29)

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

    // 加载集合中的唯一对象。
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
    // 读取"Top Level"名或RTTI名。
    auto name = source->ReadString();
    const auto isTopLevel = (name == TopLevel::GetTopLevelDescription());
    if (isTopLevel)
    {
        // 读取RTTI名。
        name = source->ReadString();
    }

    CreateObject(isTopLevel, name);
}

// private
void CoreTools::BufferInStreamImpl::CreateObject(bool isTopLevel, const string& name)
{
    // 得到将要被读取的类型的工厂函数。如果断言Object::Find(name)失败，请确保您有在使用引擎代码之前
    // 在'main' 或 'WinMain'中调用InitTerm::ExecuteInitializers() ,初始化会分配工厂map和对工厂函数进行填充。
    try
    {
        DoCreateObject(isTopLevel, name);
    }
    catch (const Error& error)
    {
        // 请确定您已经添加CORE_TOOLS_REGISTER_STREAM(someclass)到每一个'someclass'的头文件中。这个宏会对每个类注册工厂函数。
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, CoreTools)
            << error 
            << SYSTEM_TEXT("（")
            << name
            << SYSTEM_TEXT("）")
            << LOG_SINGLETON_TRIGGER_ASSERT;
    }
}

// private
void CoreTools::BufferInStreamImpl::DoCreateObject(bool isTopLevel, const string& name)
{
    const auto factory = OBJECT_MANAGER_SINGLETON.Find(name);

    if (factory != nullptr)
    {
        // 从源缓冲器加载该对象。
        auto object = (*factory)(*source);
        objectLink->Insert(object->GetUniqueID(), object);

        // 跟踪所有应用程序使用的顶层对象
        if (isTopLevel)
        {
            topLevel.Insert(object);
        }
    }
}

// private
void CoreTools::BufferInStreamImpl::Link()
{
    // 链接对象。这个程序会取代存储的任意Object*的数据成员的旧地址，
    // 新地址会在当前运用程序运行时创建。

    for (auto& value : *objectLink)
    {
        value->Link(*objectLink);
    }
}

// private
void CoreTools::BufferInStreamImpl::PostLink()
{
    // 允许对象执行链接后的语义。在读取——链接的模式中，
    // 默认构造函数用于创建一个对象，其中的数据再加载。链接器连接创建的对象。
    // 后链接函数在应用程序运行时创建对象时可以做一些非默认构造函数所做的工作。

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
