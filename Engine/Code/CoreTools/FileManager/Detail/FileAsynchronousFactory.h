/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:32)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileManagerInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileAsynchronousFactory final
    {
    public:
        using ClassType = FileAsynchronousFactory;

        using FileAsynchronousSharedPtr = std::shared_ptr<FileAsynchronousImpl>;

    public:
        NODISCARD static FileAsynchronousSharedPtr Create(BufferIO bufferIO);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_FACTORY_H
