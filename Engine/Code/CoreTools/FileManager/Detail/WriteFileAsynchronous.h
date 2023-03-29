///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:24)

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
