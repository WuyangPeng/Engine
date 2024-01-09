/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/04 11:36)

#ifndef RENDERING_PICKING_PICKER_H
#define RENDERING_PICKING_PICKER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/SceneGraph/Spatial.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(Picker, PickerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Picker
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Picker);
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;

    public:
        explicit Picker(int numThreads);

        CLASS_INVARIANT_DECLARE;

        void SetMaxDistance(float maxDistance);
        NODISCARD float GetMaxDistance() const noexcept;

        void operator()(Spatial& scene,
                        const APoint& origin,
                        const AVector& direction,
                        float tMin,
                        float tMax);

        NODISCARD bool IsRecordsExist() const noexcept;

        // ��������������������Լ���ļ�¼��
        // ����Ӧ����0 < records.GetSize()ʱ���á�

        // ��λ��¼����С����ֵ��Tֵ��
        NODISCARD PickRecord GetClosestToZero() const;

        // ��λ��¼��ӽ������Ǹ�ֵ��Tֵ��
        NODISCARD PickRecord GetClosestNonnegative() const;

        // ��λ��¼��ӽ���������ֵ��Tֵ��
        NODISCARD PickRecord GetClosestNonpositive() const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_PICKING_PICKER_H
