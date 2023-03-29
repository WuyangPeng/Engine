///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:37)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousFactory.h"
#include "ReadFileAsynchronous.h"
#include "WriteFileAsynchronous.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::FileAsynchronousFactory::FileAsynchronousSharedPtr CoreTools::FileAsynchronousFactory::Create(BufferIO bufferIO)
{
    switch (bufferIO)
    {
        case BufferIO::Read:
            return std::make_shared<ReadFileAsynchronous>();
        case BufferIO::Write:
            return std::make_shared<WriteFileAsynchronous>();
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ���ļ����͡�"s))
}
