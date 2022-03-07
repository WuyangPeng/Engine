///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/09 1:39)

#include "CoreTools/CoreToolsExport.h"

#include "FileAsynchronousFactory.h"
#include "ReadFileAsynchronous.h"
#include "WriteFileAsynchronous.h"
#include "CoreTools/FileManager/Flags/BufferIOFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

// static
CoreTools::FileAsynchronousFactory::FileAsynchronousSharedPtr CoreTools::FileAsynchronousFactory::Create(BufferIO bufferIO)
{
    switch (bufferIO)
    {
        case BufferIO::Read:
            return make_shared<ReadFileAsynchronous>();
        case BufferIO::Write:
            return make_shared<WriteFileAsynchronous>();
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ���ļ����͡�"s));
}
