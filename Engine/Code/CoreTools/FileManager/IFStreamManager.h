//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:28)

#ifndef CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(IFStreamManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE IFStreamManager final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(IFStreamManager);
        using String = System::String;

    public:
        explicit IFStreamManager(const String& fileName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetFileContent() const;
        [[nodiscard]] String BackupFile() const;

        void SetSimplifiedChinese();

    private:
        IMPL_TYPE_DECLARE(IFStreamManager);
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_IFSTREAM_MANAGER_H
