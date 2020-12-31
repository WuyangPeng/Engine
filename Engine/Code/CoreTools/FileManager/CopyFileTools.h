//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:24)

#ifndef CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
#define CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(CopyFileToolsImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CopyFileTools final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(CopyFileTools);
        using String = System::String;

    public:
        CopyFileTools(const String& inFileName, const String& outFileName);

        CLASS_INVARIANT_DECLARE;

    private:
        IMPL_TYPE_DECLARE(CopyFileTools);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_COPY_FILE_TOOLS_H
