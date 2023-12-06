/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/27 11:06)

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

        /// Ԥ��������ģ�͵�����֮��Ӧ�ã�������ͼ����֮ǰӦ�á�
        /// �����ڱ任�������������ķ��䡣Ĭ��ֵΪ��λ����
        void SetPreViewMatrix(const Matrix& aPreViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        /// ��ͶӰ����������Ļ�ռ�任��������Ⱦͼ��ķ��䡣Ĭ��ֵΪ��λ����
        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;
        NODISCARD Matrix GetProjectionViewMatrix(const Matrix& matrix) noexcept;
        NODISCARD float GetEpsilon() const noexcept;

    private:
        // �������Ԥ������
        Matrix preViewMatrix;
        // ָʾ�û��Ƿ�ָ���˷ǵ�λ��Ԥ��ͼ����
        bool preViewIsIdentity;

        // ��Ӱ���ĺ�ͶӰ����
        Matrix postProjectionMatrix;
        // ָʾ�û��Ƿ�ָ���˷ǵ�λ�ĺ�ͶӰ����
        bool postProjectionIsIdentity;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_MATRIX_H
