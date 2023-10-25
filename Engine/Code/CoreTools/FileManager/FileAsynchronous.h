///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/22 11:40)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"

CORE_TOOLS_EXPORT_UNIQUE_PTR(FileAsynchronous);
CORE_TOOLS_NON_COPY_EXPORT_IMPL(FileAsynchronousImpl);

namespace CoreTools
{
    // 由于实现类本身使用了锁，单例不再使用锁。
    class CORE_TOOLS_DEFAULT_DECLARE FileAsynchronous final : public Singleton<FileAsynchronous, MutexCreate::UseNull>
    {
    public:
        NON_COPY_TYPE_DECLARE(FileAsynchronous);
        using ParentType = Singleton<FileAsynchronous>;

        using String = System::String;

    private:
        enum class FileAsynchronousCreate
        {
            Init,
        };

    public:
        explicit FileAsynchronous(FileAsynchronousCreate fileAsynchronousCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(FileAsynchronous)

        CLASS_INVARIANT_DECLARE;

        // 调用方需要保证事件回调的多线程安全问题。
        void RegisteredReadFile(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event);
        void RegisteredWriteFile(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& fileBuffer, bool append);
        void RegisteredWriteFile(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& fileBuffer, bool append);

        void Run();
        void Stop();

    private:
        using FileAsynchronousUniquePtr = std::unique_ptr<FileAsynchronous>;

    private:
        static FileAsynchronousUniquePtr fileAsynchronous;
        PackageType readImpl;
        PackageType writeImpl;
    };
}

#define FILE_ASYNCHRONOUS_SINGLETON CoreTools::FileAsynchronous::GetSingleton()

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_H
