///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 16:16)

#ifndef RENDERING_SCENE_GRAPH_PICKER_IMPL_H
#define RENDERING_SCENE_GRAPH_PICKER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/SceneGraph/PickRecordContainer.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickerImpl
    {
    public:
        using ClassType = PickerImpl;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;

    public:
        // ���Բ������ĳɷ���P + t * D��
        // P��һ����ĳɷ�(P��ԭ��),D��һ����λ���ȷ���,
        // t��һ��������[tmin,tmax]�ı��������� tmin < tmax��
        // P��Dֵ�������������ꡣtmin��tmax��ѡ������
        // ֱ��:  tmin = -Mathf::maxReal, tmax = Mathf::maxReal
        // ����:  tmin = 0, tmax = Mathematics::Mathf::maxReal
        // �߶�:  tmin = 0, tmax > 0;
        PickerImpl(const Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax);

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
        // ѡ�����ݹ���������볡����
        void ExecuteRecursive(const Spatial& object);

    private:
        APoint origin;
        AVector direction;
        float tMin;
        float tMax;

        // �������еļ�¼��ѡ�������
        PickRecordContainer records;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICKER_IMPL_H
