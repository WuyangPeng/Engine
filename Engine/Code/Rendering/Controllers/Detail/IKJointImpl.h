///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

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

        // Joint更新。
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
        // 索引i为joint的父世界axis[i]。
        static const int numAxis = 3;

        std::array<bool, numAxis> allowTranslation;  // 默认 = false
        std::array<float, numAxis> minTranslation;  // 默认 = -无穷大
        std::array<float, numAxis> maxTranslation;  // 默认 = +无穷大
        std::array<bool, numAxis> allowRotation;  // 默认 = false
        std::array<float, numAxis> minRotation;  // 默认 = -无穷大
        std::array<float, numAxis> maxRotation;  // 默认 = +无穷大

        // 管理的对象。
        CoreTools::ObjectAssociated<Spatial> object;

        // 影响本joint的目标。
        IKGoalSharedPtrVector goals;
    };
}

#endif  // RENDERING_CONTROLLERS_IKJOINT_IMPL_H
