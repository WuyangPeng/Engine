///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/04 16:48)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileAsynchronousFactory final
    {
    public:
        using ClassType = FileAsynchronousFactory;
        using FileAsynchronousSharedPtr = std::shared_ptr<FileAsynchronousImpl>;
        using String = System::String;

    public:
        NODISCARD static FileAsynchronousSharedPtr Create(BufferIO bufferIO);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H
