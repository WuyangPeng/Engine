///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 16:35)

#ifndef RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
#define RENDERING_CONTROLLERS_MORPH_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "ControllerKeyInfo.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(MorphController, MorphControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE MorphController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MorphController);
        using ParentType = Controller;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        // 顶点的数目，变形的目标，被固定对象的生存期的键。
        // 构造函数做一些创建控制器的工作。
        // 每个目标顶点，时间，和权重都必须由相应的成员访问分配。

        // numVertices: 每个目标的顶点的数量。所有的目标具有相同数量的顶点。

        // numTargets:  变形的目标数

        // numKeys:  键的数目，每个键发生在一个特定的时间。

        MorphController(int numVertices, int numTargets, int numKeys);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MorphController);

        // 调用构造函数后，您必须使用这些函数设置顶点数组，时间和权重。
        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumTargets() const noexcept;
        NODISCARD int GetNumKeys() const noexcept;
        NODISCARD APoint GetVertices(int target, int vertices) const;
        NODISCARD float GetTimes(int key) const;
        NODISCARD float GetWeights(int key, int target) const;

        void SetVertices(int target, int vertices, const APoint& point);
        void SetTimes(int key, float times);
        void SetWeights(int key, int target, float weights);

        // 动画更新。应用程序时间以毫秒为单位。
        NODISCARD bool Update(double applicationTime) override;
        void SetObject(ControllerInterface* object) override;
        void SetObjectInCopy(ControllerInterface* object) override;

        NODISCARD ControllerInterfaceSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    protected:
        // 查找边界上的键。
        NODISCARD ControllerKeyInfo GetKeyInfo(float ctrlTime) noexcept;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(MorphController);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(MorphController);
}

#endif  // RENDERING_CONTROLLERS_MORPH_CONTROLLER_H
