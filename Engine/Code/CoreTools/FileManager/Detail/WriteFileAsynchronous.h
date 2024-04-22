/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 22:50)

#ifndef CORE_TOOLS_FILE_MANAGER_WRITE_FILE_ASYNCHRONOUS_H
#define CORE_TOOLS_FILE_MANAGER_WRITE_FILE_ASYNCHRONOUS_H

#include "CoreTools/CoreToolsDll.h"

#include "FileAsynchronousImpl.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WriteFileAsynchronous final : public FileAsynchronousImpl
    {
    public:
        using ClassType = WriteFileAsynchronous;
        using ParentType = FileAsynchronousImpl;

    public:
        explicit WriteFileAsynchronous() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void AsynchronousExecution(const FileAsynchronousParameter& fileAsynchronousParameter) override;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_WRITE_FILE_ASYNCHRONOUS_H
