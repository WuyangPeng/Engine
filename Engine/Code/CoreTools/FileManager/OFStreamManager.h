///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.3 (2021/09/03 15:00)
//	����汾��0.5.1.1 (2020/10/13 20:29)

#ifndef CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
#define CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"
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

        CLASS_INVARIANT_DECLARE;

        NODISCARD PosType GetOFStreamSize() const;

        OFStreamManager& operator<<(const String& message);
        void SetSimplifiedChinese();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_FILE_MANAGER_OFSTREAM_MANAGER_H
