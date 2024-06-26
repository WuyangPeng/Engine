/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/29 22:36)

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
