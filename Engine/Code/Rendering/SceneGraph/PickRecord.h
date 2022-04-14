///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/02 16:20)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_H

#include "Spatial.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(PickRecord, PickRecordImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRecord : private boost::totally_ordered<PickRecord>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PickRecord);

    public:
        NODISCARD static PickRecord Create();

        // ������֧��const static PickRecord��Picker���졣
        explicit PickRecord(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSpatialSharedPtr GetIntersected() const noexcept;
        NODISCARD float GetParameter() const noexcept;
        NODISCARD int GetTriangle() const noexcept;
        NODISCARD float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSharedPtr& intersected);
        void SetParameter(float parameter);
        void SetTriangle(int triangle);
        void SetBary(float firstBary, float secondBary);

        NODISCARD bool operator==(const PickRecord& rhs) const noexcept;
        NODISCARD bool operator<(const PickRecord& rhs) const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_H
