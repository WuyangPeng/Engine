//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:26)

#ifndef CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
#define CORE_TOOLS_FILE_MANAGER_DIRECTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_EXPORT_SHARED_PTR(DirectoryImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Directory final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(Directory);

    public:
        explicit Directory(const System::String& directoryName);

        CLASS_INVARIANT_DECLARE;

    private:
        IMPL_TYPE_DECLARE(FileBuffer);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_DIRECTORY_H
