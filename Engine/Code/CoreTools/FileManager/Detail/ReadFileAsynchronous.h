///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.3 (2021/09/04 10:05)

#ifndef CORE_TOOLS_FILE_MANAGER_READ_FILE_ASYNCHRONOUS_H
#define CORE_TOOLS_FILE_MANAGER_READ_FILE_ASYNCHRONOUS_H

#include "CoreTools/CoreToolsDll.h"

#include "FileAsynchronousImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReadFileAsynchronous : public FileAsynchronousImpl
    {
    public:
        using ClassType = ReadFileAsynchronous;
        using ParentType = FileAsynchronousImpl;

    public:
        explicit ReadFileAsynchronous() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void AsynchronousExecution(const FileAsynchronousParameter& fileAsynchronousParameter) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_READ_FILE_ASYNCHRONOUS_H
