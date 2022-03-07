// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/23 10:13)

#ifndef RENDERING_CONTROLLERS_IKJOINT_IMPL_H
#define RENDERING_CONTROLLERS_IKJOINT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/SceneGraph/Spatial.h"

#include <vector>

namespace CoreTools
{
    class BufferTarget;
    class BufferSource;
    class ObjectLink;
    class ObjectRegister;
}

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE IKJointImpl
    {
    public:
        using ClassType = IKJointImpl;
        using AVector = Mathematics::AVectorF;
        using IKGoalSharedPtrVector = std::vector<IKGoalSharedPtr>;
        using Object = CoreTools::Object;
        using MatrixRotationAxis = Mathematics::MatrixRotationAxis;

    public:
        IKJointImpl() noexcept;
        IKJointImpl(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals);

        CLASS_INVARIANT_DECLARE;

        int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        // Joint���¡�
        const AVector GetAxis(MatrixRotationAxis axisIndex) const;
        void UpdateWorldTransform();
        void UpdateWorldRotateAndTranslate();
        bool UpdateLocalTranslate(MatrixRotationAxis axisIndex);
        bool UpdateLocalRotate(MatrixRotationAxis axisIndex);

        const ConstSpatialSharedPtr GetObjectSharedPtr() const noexcept;
        const ConstIKGoalSharedPtr GetGoalsSharedPtr(int index) const;
        int GetGoalsNum() const;

        void SetAllowTranslation(MatrixRotationAxis axisIndex, bool allowTranslation);
        void SetAllowRotation(MatrixRotationAxis axisIndex, bool allowRotation);

        bool IsAllowTranslation(MatrixRotationAxis axisIndex) const;
        bool IsAllowRotation(MatrixRotationAxis axisIndex) const;

    private:
        void Init() noexcept;

    private:
        // ����iΪjoint�ĸ�����axis[i]��
        static const int sm_NumAxis = 3;

        bool m_AllowTranslation[sm_NumAxis];  // Ĭ�� = false
        float m_MinTranslation[sm_NumAxis];  // Ĭ�� = -�����
        float m_MaxTranslation[sm_NumAxis];  // Ĭ�� = +�����
        bool m_AllowRotation[sm_NumAxis];  // Ĭ�� = false
        float m_MinRotation[sm_NumAxis];  // Ĭ�� = -�����
        float m_MaxRotation[sm_NumAxis];  // Ĭ�� = +�����

        // ����Ķ���
        SpatialSharedPtr m_Object;

        // Ӱ�챾joint��Ŀ�ꡣ
        IKGoalSharedPtrVector m_Goals;
    };
}

#endif  // RENDERING_CONTROLLERS_IKJOINT_IMPL_H
