/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 21:39)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_IMPL_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/FileEventInterface.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE FileAsynchronousParameterImpl final
    {
    public:
        using ClassType = FileAsynchronousParameterImpl;

        using String = System::String;

    public:
        FileAsynchronousParameterImpl(String fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event) noexcept;
        FileAsynchronousParameterImpl(String fileName, bool binaryFile, ConstFileBufferSharedPtr fileBuffer, bool append) noexcept;
        FileAsynchronousParameterImpl(String fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, ConstFileBufferSharedPtr fileBuffer, bool append) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileName() const;
        NODISCARD bool IsBinaryFile() const noexcept;
        NODISCARD FileEventInterfaceWeakPtr GetEvent() const noexcept;
        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const;
        NODISCARD bool IsAppend() const noexcept;

    private:
        String fileName;
        bool binaryFile;
        FileEventInterfaceWeakPtr event;
        ConstFileBufferSharedPtr fileBuffer;
        bool append;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_IMPL_H
