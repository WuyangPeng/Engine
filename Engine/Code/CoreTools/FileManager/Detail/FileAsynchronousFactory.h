///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/23 15:22)

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
