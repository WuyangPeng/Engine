///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PointControllerImpl
    {
    public:
        using ClassType = PointControllerImpl;
        using AVector = Mathematics::AVectorF;

    public:
        explicit PointControllerImpl(int numPoints);
        PointControllerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        // 点运动，在该系统的模型空间。速度矢量应为单位的长度。
        // 其中点代表一个刚体在应用程序，
        // 你可以选择该系统的原点为点的质量中心和
        // 坐标轴对应于惯性张量的主方向。
        NODISCARD int GetNumPoints() const noexcept;
        NODISCARD float GetPointLinearSpeed(int index) const;
        NODISCARD float GetPointAngularSpeed(int index) const;
        NODISCARD AVector GetPointLinearAxis(int index) const;
        NODISCARD AVector GetPointAngularAxis(int index) const;

        void SetPointLinearSpeed(int index, float pointLinearSpeed);
        void SetPointAngularSpeed(int index, float pointAngularSpeed);
        void SetPointLinearAxis(int index, const AVector& pointLinearAxis);
        void SetPointAngularAxis(int index, const AVector& pointAngularAxis);

        NODISCARD float GetSystemLinearSpeed() const noexcept;
        void SetSystemLinearSpeed(float aSystemLinearSpeed) noexcept;
        NODISCARD float GetSystemAngularSpeed() const noexcept;
        void SetSystemAngularSpeed(float aSystemAngularSpeed) noexcept;
        NODISCARD AVector GetSystemLinearAxis() const noexcept;
        void SetSystemLinearAxis(const AVector& aSystemLinearAxis) noexcept;
        NODISCARD AVector GetSystemAngularAxis() const noexcept;
        void SetSystemAngularAxis(const AVector& aSystemAngularAxis) noexcept;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    private:
        // 系统的运动，在局部坐标。速度矢量应为单位的长度。
        float systemLinearSpeed;
        float systemAngularSpeed;
        AVector systemLinearAxis;
        AVector systemAngularAxis;

        int numPoints;
        std::vector<float> pointLinearSpeeds;
        std::vector<float> pointAngularSpeeds;
        std::vector<AVector> pointLinearAxes;
        std::vector<AVector> pointAngularAxes;
    };
}

#endif  // RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
