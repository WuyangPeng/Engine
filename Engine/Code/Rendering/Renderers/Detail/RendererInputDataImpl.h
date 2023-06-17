///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:35)

#ifndef FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H
#define FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "CoreTools/Contract/ContractFwd.h"

#include <memory>

namespace Rendering
{
    class RendererInputDataImpl
    {
    public:
        using ClassType = RendererInputDataImpl;
        using RendererInputSharedPtr = std::shared_ptr<RendererInput>;

    public:
        explicit RendererInputDataImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        void Rebuild(RendererTypes type);

    private:
        RendererInputSharedPtr rendererInput;
    };
}

#endif  // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_IMPL_H
