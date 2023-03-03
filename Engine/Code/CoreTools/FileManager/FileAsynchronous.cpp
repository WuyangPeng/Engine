///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/03/02 11:01)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronous.h"
#include "Flags/BufferIOFlags.h"
#include "Detail/FileAsynchronousFactory.h"
#include "Detail/FileAsynchronousImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, FileAsynchronous);

CoreTools::FileAsynchronous::FileAsynchronousUniquePtr CoreTools::FileAsynchronous::fileAsynchronous{};

void CoreTools::FileAsynchronous::Create()
{
    fileAsynchronous = std::make_unique<CoreTools::FileAsynchronous>(FileAsynchronousCreate::Init);
}

void CoreTools::FileAsynchronous::Destroy() noexcept
{
    fileAsynchronous.reset();
}

CoreTools::FileAsynchronous::FileAsynchronous(FileAsynchronousCreate fileAsynchronousCreate)
    : readImpl{ ImplCreateUseFactory::Default, BufferIO::Read }, writeImpl{ ImplCreateUseFactory::Default, BufferIO::Write }
{
    System::UnusedFunction(fileAsynchronousCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, FileAsynchronous)

void CoreTools::FileAsynchronous::RegisteredReadFile(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    readImpl->Registered(fileName, binaryFile, event);
}

void CoreTools::FileAsynchronous::RegisteredWriteFile(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& fileBuffer, bool append)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    writeImpl->Registered(fileName, binaryFile, fileBuffer, append);
}

void CoreTools::FileAsynchronous::RegisteredWriteFile(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& fileBuffer, bool append)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    writeImpl->Registered(fileName, binaryFile, event, fileBuffer, append);
}

void CoreTools::FileAsynchronous::Run()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    readImpl->SetThread();
    writeImpl->SetThread();
}

void CoreTools::FileAsynchronous::Stop()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    readImpl->Stop();
    writeImpl->Stop();

    readImpl->Join();
    writeImpl->Join();
}
