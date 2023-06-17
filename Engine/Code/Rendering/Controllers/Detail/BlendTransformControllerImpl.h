///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Controllers/TransformController.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BlendTransformControllerImpl
    {
    public:
        using ClassType = BlendTransformControllerImpl;
        using Object = CoreTools::Object;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;
        using ObjectSharedPtr = CoreTools::ObjectSharedPtr;
        using ConstObjectSharedPtr = CoreTools::ConstObjectSharedPtr;

    public:
        BlendTransformControllerImpl() noexcept;
        BlendTransformControllerImpl(const TransformControllerSharedPtr& firstController,
                                     const TransformControllerSharedPtr& secondController,
                                     bool rotationScaleMatrices,
                                     bool geometricRotation = false,
                                     bool geometricScale = false) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        NODISCARD ObjectSharedPtr GetObjectByName(const std::string& name);
        NODISCARD std::vector<ObjectSharedPtr> GetAllObjectsByName(const std::string& name);
        NODISCARD ConstObjectSharedPtr GetConstObjectByName(const std::string& name) const;
        NODISCARD std::vector<ConstObjectSharedPtr> GetAllConstObjectsByName(const std::string& name) const;

        // 权重w是一个数字的量0 <= w <= 1。
        NODISCARD ConstTransformControllerSharedPtr GetFirstController() const noexcept;
        NODISCARD ConstTransformControllerSharedPtr GetSecondController() const noexcept;
        NODISCARD bool IsRotationScaleMatrices() const noexcept;
        void SetWeight(float aWeight) noexcept;
        NODISCARD float GetWeight() const noexcept;

        NODISCARD bool IsGeometricRotation() const noexcept;
        NODISCARD bool IsGeometricScale() const noexcept;

        void SetObject(ControllerInterface* object);
        bool Update(double applicationTime);

        NODISCARD APoint GetBlendTranslate() const;
        NODISCARD Matrix GetBlendQuaternion() const;
        NODISCARD APoint GetBlendScale() const;
        NODISCARD Matrix GetMatrix() const;

    private:
        CoreTools::ObjectAssociated<TransformController> firstController;
        CoreTools::ObjectAssociated<TransformController> secondController;
        float weight;
        bool rotationScaleMatrices;
        bool geometricRotation;
        bool geometricScale;
    };
}

#endif  // RENDERING_CONTROLLERS_BLEND_TRANSFORM_CONTROLLER_IMPL_H
