///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 13:49)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::FileAsynchronousImpl::FileAsynchronousImpl() noexcept
    : fileContainer{}, thread{}, mutex{}, conditionVariable{}, isStop{ false }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileAsynchronousImpl)

void CoreTools::FileAsynchronousImpl::Registered(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& fileBuffer, bool append)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    fileContainer.emplace_back(fileName, binaryFile, event, fileBuffer, append);

    conditionVariable.notify_one();
}

void CoreTools::FileAsynchronousImpl::Registered(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& fileBuffer, bool append)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    fileContainer.emplace_back(fileName, binaryFile, fileBuffer, append);

    conditionVariable.notify_one();
}

void CoreTools::FileAsynchronousImpl::Registered(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    fileContainer.emplace_back(fileName, binaryFile, event);

    conditionVariable.notify_one();
}

CoreTools::FileAsynchronousParameter CoreTools::FileAsynchronousImpl::ExtractNextReadFile() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto fileParameter = fileContainer.front();

    fileContainer.pop_front();

    return fileParameter;
}

void CoreTools::FileAsynchronousImpl::SetThread()
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    isStop = false;

    thread = std::thread{ &ClassType::WaitThread, this };
}

void CoreTools::FileAsynchronousImpl::Stop()
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    isStop = true;

    conditionVariable.notify_one();
}

void CoreTools::FileAsynchronousImpl::Join()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (thread.joinable())
    {
        thread.join();
    }
}

void CoreTools::FileAsynchronousImpl::WaitThread()
{
    do
    {
        std::unique_lock uniqueLock{ mutex };
        conditionVariable.wait(uniqueLock, [this] {
            return isStop || !fileContainer.empty();
        });

        Execution();

    } while (!isStop || !fileContainer.empty());
}

void CoreTools::FileAsynchronousImpl::Execution()
{
    if (!fileContainer.empty())
    {
        EXCEPTION_TRY
        {
            const auto fileAsynchronousParameter = ExtractNextReadFile();

            AsynchronousExecution(fileAsynchronousParameter);
        }
        EXCEPTION_ALL_CATCH(CoreTools)
    }
}
