///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:10)

#ifndef RENDERING_SCENE_GRAPH_PICKER_H
#define RENDERING_SCENE_GRAPH_PICKER_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

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
        Picker(const Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsRecordsExist() const noexcept;

        // ��������������������Լ���ļ�¼��
        // ����Ӧ����0 < m_Records.GetSize()ʱ���á�

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

#endif  // RENDERING_SCENE_GRAPH_PICKER_H
