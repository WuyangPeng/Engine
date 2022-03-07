///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 23:36)

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
