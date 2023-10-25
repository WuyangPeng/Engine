///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:34)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/FileManager/FileAsynchronousParameter.h"
#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

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

    private:
        NODISCARD FileAsynchronousParameter ExtractNextReadFile() noexcept;

        void WaitThread();
        void Execution();

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
