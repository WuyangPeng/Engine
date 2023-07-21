///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/02 18:25)

#ifndef DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_H
#define DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_H

#include "Database/DatabaseDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

DATABASE_DELAY_COPY_UNSHARED_EXPORT_IMPL(CodeMapping, CodeMappingImpl);

namespace Database
{
    class DATABASE_DEFAULT_DECLARE CodeMapping final
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
        explicit CodeMapping(CoreTools::DisableNotThrow disableNotThrow);

    private:
        PackageType impl;
    };
}

#endif  // DATABASE_DATABASE_ENTITY_CODE_GENERATION_CODE_MAPPING_H
