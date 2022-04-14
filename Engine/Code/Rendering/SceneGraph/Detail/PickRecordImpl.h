///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 16:31)

#ifndef RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
#define RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H

#include "System/Helper/PragmaWarning/Operators.h"
#include "Rendering/SceneGraph/Spatial.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PickRecordImpl : private boost::totally_ordered<PickRecordImpl>
    {
    public:
        using ClassType = PickRecordImpl;

    public:
        // ������֧��const static PickRecord��Picker���졣
        PickRecordImpl() noexcept;
        ~PickRecordImpl() noexcept = default;
        PickRecordImpl(const PickRecordImpl& rhs);
        PickRecordImpl& operator=(const PickRecordImpl& rhs);
        PickRecordImpl(PickRecordImpl&& rhs) noexcept;
        PickRecordImpl& operator=(PickRecordImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstSpatialSharedPtr GetIntersected() const noexcept;
        NODISCARD float GetParameter() const noexcept;
        NODISCARD int GetTriangle() const noexcept;
        NODISCARD float GetBary(int index) const;

        void SetIntersected(const ConstSpatialSharedPtr& aIntersected) noexcept;
        void SetParameter(float aParameter) noexcept;
        void SetTriangle(int aTriangle) noexcept;
        void SetBary(float firstBary, float secondBary);

    private:
        // �ָ�Ķ���
        ConstSpatialSharedPtr intersected;

        // �����������P + t * D����������Աm_Parameter�ǲ���t�ڽ����ֵ��
        float parameter;

        // �����ཻ�������ε�������
        int triangle;

        static const int barySize = 3;

        // ������������ꡣ���е���������[0,1]��b0 + b1 + b2 = 1��
        std::array<float, barySize> bary;
    };

    NODISCARD bool operator==(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
    NODISCARD bool operator<(const PickRecordImpl& lhs, const PickRecordImpl& rhs) noexcept;
}

#endif  // RENDERING_SCENE_GRAPH_PICK_RECORD_IMPL_H
