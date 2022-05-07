///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 10:42)

#ifndef FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H
#define FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

RENDERING_EXPORT_UNIQUE_PTR(RendererInputData);
RENDERING_NON_COPY_EXPORT_IMPL(RendererInputDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererInputData : public CoreTools::Singleton<RendererInputData>
    {
    public:
        NON_COPY_TYPE_DECLARE(RendererInputData);
        using ParentType = Singleton<RendererInputData>;
        using RendererTypes = Rendering::RendererTypes;

    private:
        enum class RendererInputDataCreate
        {
            Init,
        };

    public:
        explicit RendererInputData(RendererInputDataCreate rendererInputDataCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(RendererInputData);

        CLASS_INVARIANT_DECLARE;

        void Rebuild(RendererTypes type);

    private:
        using RendererInputDataUniquePtr = std::unique_ptr<RendererInputData>;

    private:
        static RendererInputDataUniquePtr rendererInputData;
        PackageType impl;
    };
}

#define RENDERER_INPUT_DATA_SINGLETON Rendering::RendererInputData::GetSingleton()

#endif  // FRAMEWORK_APPLICATION_RENDERER_INPUT_DATA_H
