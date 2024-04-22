/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:25)

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

    /// 加载集合中的唯一对象。
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
    /// 读取"Top Level"名或RTTI名。
    auto name = source->ReadString();
    const auto isTopLevel = (name == TopLevel::GetTopLevelDescription());
    if (isTopLevel)
    {
        /// 读取RTTI名。
        name = source->ReadString();
    }

    CreateObject(isTopLevel, name);
}

void CoreTools::BufferInStreamImpl::CreateObject(bool isTopLevel, const std::string& name)
{
    /// 得到将要被读取的类型的工厂函数。如果断言Object::Find(name)失败，请确保您有在使用引擎代码之前
    /// 在'main' 或 'WinMain'中调用InitTerm::ExecuteInitializer() ,初始化会分配工厂map和对工厂函数进行填充。
    try
    {
        DoCreateObject(isTopLevel, name);
    }
    catch (const Error& error)
    {
        /// 请确定您已经添加CORE_TOOLS_REGISTER_STREAM(someClass)到每一个'someClass'的头文件中。这个宏会对每个类注册工厂函数。
        LOG_SINGLETON_ENGINE_APPENDER(Fatal, CoreTools, error, SYSTEM_TEXT("（"), name, SYSTEM_TEXT("）"), LogAppenderIOManageSign::TriggerAssert);
    }
}

void CoreTools::BufferInStreamImpl::DoCreateObject(bool isTopLevel, const std::string& name)
{
    if (const auto factory = OBJECT_MANAGER_SINGLETON.Find(name); factory != nullptr)
    {
        /// 从源缓冲器加载该对象。
        const auto object = (*factory)(*source);
        objectLink->Insert(object->GetUniqueId(), object);

        /// 跟踪所有应用程序使用的顶层对象
        if (isTopLevel)
        {
            topLevel.Insert(object);
        }
    }
}

void CoreTools::BufferInStreamImpl::Link()
{
    /// 链接对象。这个程序会取代存储的任意Object*的数据成员的旧地址，
    /// 新地址会在当前运用程序运行时创建。

    for (const auto& element : *objectLink)
    {
        element->Link(*objectLink);
    }
}

void CoreTools::BufferInStreamImpl::PostLink()
{
    /// 允许对象执行链接后的语义。在读取——链接的模式中，
    /// 默认构造函数用于创建一个对象，其中的数据再加载。链接器连接创建的对象。
    /// 后链接函数在应用程序运行时创建对象时可以做一些非默认构造函数所做的工作。

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
