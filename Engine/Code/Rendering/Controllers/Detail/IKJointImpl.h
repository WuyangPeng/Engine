///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_IKJOINT_IMPL_H
#define RENDERING_CONTROLLERS_IKJOINT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/Flags/MatrixFlags.h"
#include "Rendering/Controllers/IKGoal.h"
#include "Rendering/SceneGraph/Spatial.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE IKJointImpl
    {
    public:
        using ClassType = IKJointImpl;
        using AVector = Mathematics::AVectorF;
        using IKGoalSharedPtrVector = std::vector<CoreTools::ObjectAssociated<IKGoal>>;
        using Object = CoreTools::Object;
        using MatrixRotationAxis = Mathematics::MatrixRotationAxis;

    public:
        IKJointImpl() noexcept;
        IKJointImpl(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        // Joint���¡�
        NODISCARD AVector GetAxis(MatrixRotationAxis axisIndex) const;
        void UpdateWorldTransform();
        void UpdateWorldRotateAndTranslate() noexcept(gAssert < 2 || gRenderingAssert < 2);
        NODISCARD bool UpdateLocalTranslate(MatrixRotationAxis axisIndex);
        NODISCARD bool UpdateLocalRotate(MatrixRotationAxis axisIndex);

        NODISCARD ConstSpatialSharedPtr GetObjectSharedPtr() const noexcept;
        NODISCARD ConstIKGoalSharedPtr GetGoalsSharedPtr(int index) const;
        NODISCARD int GetGoalsNum() const;

        void SetAllowTranslation(MatrixRotationAxis axisIndex, bool aAllowTranslation);
        void SetAllowRotation(MatrixRotationAxis axisIndex, bool aAllowRotation);

        NODISCARD bool IsAllowTranslation(MatrixRotationAxis axisIndex) const;
        NODISCARD bool IsAllowRotation(MatrixRotationAxis axisIndex) const;

    private:
        // ����iΪjoint�ĸ�����axis[i]��
        static const int numAxis = 3;

        std::array<bool, numAxis> allowTranslation;  // Ĭ�� = false
        std::array<float, numAxis> minTranslation;  // Ĭ�� = -�����
        std::array<float, numAxis> maxTranslation;  // Ĭ�� = +�����
        std::array<bool, numAxis> allowRotation;  // Ĭ�� = false
        std::array<float, numAxis> minRotation;  // Ĭ�� = -�����
        std::array<float, numAxis> maxRotation;  // Ĭ�� = +�����

        // ����Ķ���
        CoreTools::ObjectAssociated<Spatial> object;

        // Ӱ�챾joint��Ŀ�ꡣ
        IKGoalSharedPtrVector goals;
    };
}

#endif  // RENDERING_CONTROLLERS_IKJOINT_IMPL_H
