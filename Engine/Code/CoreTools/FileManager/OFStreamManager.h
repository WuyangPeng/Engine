//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(OFStreamManagerImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE OFStreamManager final  
    {
    public:
        NON_COPY_TYPE_DECLARE(OFStreamManager);
        using String = System::String;
        using PosType = System::PosType;

    public:
        OFStreamManager(const String& fileName, bool addition);
        ~OFStreamManager() noexcept = default;
        OFStreamManager(const OFStreamManager& rhs) noexcept = delete;
        OFStreamManager& operator=(const OFStreamManager& rhs) noexcept = delete;
        OFStreamManager(OFStreamManager&& rhs) noexcept = delete;
        OFStreamManager& operator=(OFStreamManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] PosType GetOFStreamSize() const;

        OFStreamManager& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
