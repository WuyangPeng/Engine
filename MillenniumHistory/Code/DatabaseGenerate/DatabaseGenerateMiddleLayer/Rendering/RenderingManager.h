/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 22:55)

#ifndef DATABASE_GENERATE_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H
#define DATABASE_GENERATE_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/DatabaseGenerateMiddleLayerDll.h"

#include "DatabaseGenerate/DatabaseGenerateMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/RenderingManagerInterface.h"

namespace DatabaseGenerateMiddleLayer
{
    class DATABASE_GENERATE_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager final : public Framework::RenderingManagerInterface
    {
    public:
        using ClassType = RenderingManager;
        using ParentType = Framework::RenderingManagerInterface;

    public:
        RenderingManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool Idle(int64_t timeDelta) override;
    };
}

#endif  // DATABASE_GENERATE_MIDDLE_LAYER_RENDERING_RENDERING_MANAGER_H
