/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
#define RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraMatrix
    {
    public:
        using ClassType = CameraMatrix;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;

    public:
        explicit CameraMatrix(float epsilon) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 预览矩阵在模型到世界之后应用，但在视图矩阵之前应用。
        /// 它用于变换，例如世界对象的反射。默认值为单位矩阵。
        void SetPreViewMatrix(const Matrix& aPreViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        /// 后投影矩阵用于屏幕空间变换，例如渲染图像的反射。默认值为单位矩阵。
        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        NODISCARD Matrix GetProjectionViewMatrix(const Matrix& matrix) noexcept;
        NODISCARD float GetEpsilon() const noexcept;

    private:
        // 摄像机的预览矩阵。
        Matrix preViewMatrix;
        // 指示用户是否指定了非单位的预视图矩阵。
        bool preViewIsIdentity;

        // 摄影机的后投影矩阵。
        Matrix postProjectionMatrix;
        // 指示用户是否指定了非单位的后投影矩阵。
        bool postProjectionIsIdentity;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
