// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/19 19:23)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

#include "Rendering/SceneGraph/Spatial.h"

#include "System/Helper/PragmaWarning/Operators.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordImpl : private boost::totally_ordered<PickRecordImpl>
    {
    public:
        using ClassType = PickRecordImpl;

    public:
        // ������֧��const static PickRecord��Picker���졣
        PickRecordImpl() noexcept;
        PickRecordImpl(const PickRecordImpl& rhs);
        PickRecordImpl& operator=(const PickRecordImpl& rhs);
        PickRecordImpl(PickRecordImpl&& rhs) = default;
        PickRecordImpl& operator=(PickRecordImpl&& rhs) = default;
        ~PickRecordImpl() = default;

        CLASS_INVARIANT_DECLARE;

        ConstSpatialSmartPointer GetIntersected() const noexcept;
        float GetParameter() const noexcept;
        int GetTriangle() const noexcept;
        float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSmartPointer& intersected) noexcept;
        void SetParameter(float parameter) noexcept;
        void SetTriangle(int triangle) noexcept;
        void SetBary(float firstBary, float secondBary);

    private:
        // �ָ�Ķ���
        ConstSpatialSmartPointer m_Intersected;

        // �����������P + t * D����������Աm_Parameter�ǲ���t�ڽ����ֵ��
        float m_Parameter;

        // �����ཻ�������ε�������
        int m_Triangle;

        static const int sm_BarySize = 3;

        // ������������ꡣ���е���������[0,1]��b0 + b1 + b2 = 1��
        float m_Bary[sm_BarySize];
    };

    bool operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
    bool operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
