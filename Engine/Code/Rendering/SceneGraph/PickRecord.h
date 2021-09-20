// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 11:32)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_H

#include "Spatial.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(PickRecord,PickRecordImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickRecord : private boost::totally_ordered<PickRecord>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(PickRecord);

    public:
        // ������֧��const static PickRecord��Picker���졣
        PickRecord();

        CLASS_INVARIANT_DECLARE;

        ConstSpatialSharedPtr GetIntersected() const;
        float GetParameter() const;
        int GetTriangle() const;
        float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSharedPtr& intersected);
        void SetParameter(float parameter);
        void SetTriangle(int triangle);
        void SetBary(float firstBary, float secondBary);

        bool operator==(const PickRecord& rhs) const;
        bool operator<(const PickRecord& rhs) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_H
