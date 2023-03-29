///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:26)

#ifndef CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_H
#define CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/FileManager/FileEventInterface.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"

CORE_TOOLS_PERFORMANCE_UNSHARED_EXPORT_IMPL(FileAsynchronousParameterImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE FileAsynchronousParameter final
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(FileAsynchronousParameter);
        using String = System::String;

    public:
        FileAsynchronousParameter(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event);
        FileAsynchronousParameter(const String& fileName, bool binaryFile, const ConstFileBufferSharedPtr& FileBuffer, bool append);
        FileAsynchronousParameter(const String& fileName, bool binaryFile, const FileEventInterfaceSharedPtr& event, const ConstFileBufferSharedPtr& FileBuffer, bool append);

        CLASS_INVARIANT_DECLARE;

        NODISCARD String GetFileName() const;
        NODISCARD bool IsBinaryFile() const noexcept;
        NODISCARD FileEventInterfaceWeakPtr GetEvent() const noexcept;
        NODISCARD ConstFileBufferSharedPtr GetFileBuffer() const;
        NODISCARD bool IsAppend() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_FILE_ASYNCHRONOUS_PARAMETER_H
