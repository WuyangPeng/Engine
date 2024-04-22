/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:32)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileAsynchronousImpl
    {
    public:
        using ClassType = FileAsynchronousImpl;

        using String = System::String;
        using FactoryType = FileAsynchronousFactory;

    public:
        explicit FileAsynchronousImpl() noexcept;
        virtual ~FileAsynchronousImpl() noexcept = default;
        FileAsynchronousImpl(const FileAsynchronousImpl& rhs) = delete;
        FileAsynchronousImpl& operator=(const FileAsynchronousImpl& rhs) = delete;
        FileAsynchronousImpl(FileAsynchronousImpl&& rhs) noexcept = delete;
        FileAsynchronousImpl& operator=(FileAsynchronousImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Registered(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event);
        void Registered(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& fileBuffer, bool append);
        void Registered(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& fileBuffer, bool append);

        void SetThread();
        void Stop();
        void Join();

    private:
        using FileContainer = std::deque<FileAsynchronousParameter>;
        using UniqueLock = std::unique_lock<std::mutex>;

    private:
        NODISCARD FileAsynchronousParameter ExtractNextReadFile() noexcept;

        void WaitThread();
        void Execution(UniqueLock& uniqueLock);

        virtual void AsynchronousExecution(const FileAsynchronousParameter& fileAsynchronousParameter) = 0;

    private:
        FileContainer fileContainer;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_IMPL_H
