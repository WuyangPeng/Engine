///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 10:25)

#ifndef CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_H
#define CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(CodeMapping, CodeMappingImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE CodeMapping final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(CodeMapping);

        using String = System::String;

    public:
        NODISCARD static CodeMapping Create();

        CLASS_INVARIANT_DECLARE;

        void Insert(const String& codeKey, const String& element);
        NODISCARD String GetElement(const String& codeKey) const;

    private:
        explicit CodeMapping(DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_CODE_MAPPING_H
