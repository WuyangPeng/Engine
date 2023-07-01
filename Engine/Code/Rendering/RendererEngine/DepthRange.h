///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/21 11:24)
///
///	��Ԫ���ԣ�Pass

#ifndef RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H
#define RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

/// �Ӵ�������ͼ�������ȷ�ΧΪ[zMin��zMax]��
/// DirectX��ȷ�ΧΪ[0, 1] ���Ӽ���
/// OpenGL��ȷ�Χ��[-1, 1] ���Ӽ���
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthRange final
    {
    public:
        using ClassType = DepthRange;

    public:
        DepthRange() noexcept;
        DepthRange(float zMin, float zMax);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD float GetZMin() const noexcept;
        NODISCARD float GetZMax() const noexcept;

    private:
        float zMin;
        float zMax;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H
