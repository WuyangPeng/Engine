///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/08 23:31)

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