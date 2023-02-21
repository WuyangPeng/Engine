///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 11:00)

#ifndef RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H
#define RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H

#include "Rendering/RenderingDll.h"

#include "CollapseRecord.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"

#include <vector>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(CollapseRecordArray, CollapseRecordArrayImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CollapseRecordArray : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(CollapseRecordArray);
        using ParentType = Object;

    public:
        explicit CollapseRecordArray(const std::vector<CollapseRecord>& collapseRecord);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CollapseRecordArray);

        NODISCARD int GetNumRecords() const;
        NODISCARD std::vector<CollapseRecord> GetRecords() const;
        NODISCARD CollapseRecord GetRecord(int index) const;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(CollapseRecordArray);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(CollapseRecordArray);
}

#endif  // RENDERING_DETAIL_COLLAPSE_RECORD_ARRAY_H
