/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/04 10:27)

#ifndef RENDERING_PICKING_PICKER_IMPL_H
#define RENDERING_PICKING_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Rendering/Picking/PickRecordContainer.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickerImpl
    {
    public:
        using ClassType = PickerImpl;

        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Line3 = Mathematics::Line3<float>;

    public:
        explicit PickerImpl(int numThreads);

        CLASS_INVARIANT_DECLARE;

        void SetMaxDistance(float aMaxDistance) noexcept;
        NODISCARD float GetMaxDistance() const noexcept;

        void operator()(Spatial& scene,
                        const APoint& aOrigin,
                        const AVector& aDirection,
                        float aTMin,
                        float aTMax);

        NODISCARD bool IsRecordsExist() const noexcept;

        /// ��������������������Լ���ļ�¼��
        /// ����Ӧ����0 < records.GetSize()ʱ���á�

        /// ��λ��¼����С����ֵ��Tֵ��
        NODISCARD PickRecord GetClosestToZero() const;

        /// ��λ��¼��ӽ������Ǹ�ֵ��Tֵ��
        NODISCARD PickRecord GetClosestNonnegative() const;

        /// ��λ��¼��ӽ���������ֵ��Tֵ��
        NODISCARD PickRecord GetClosestNonpositive() const;

    private:
        // ѡ�����ݹ���������볡����
        void ExecuteRecursive(Spatial& object);

    private:
        int numThreads;

        float maxDistance;

        APoint origin;
        AVector direction;
        float tMin;
        float tMax;

        // �������еļ�¼��ѡ�������
        PickRecordContainer records;
    };
}

#endif  // RENDERING_PICKING_PICKER_IMPL_H
