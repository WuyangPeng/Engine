///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:10)

#ifndef FRAMEWORK_APPLICATION_RENDERER_DATA_H
#define FRAMEWORK_APPLICATION_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

RENDERING_EXPORT_UNIQUE_PTR(RendererData);
RENDERING_NON_COPY_EXPORT_IMPL(RendererDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererData : public CoreTools::Singleton<RendererData>
    {
    public:
        NON_COPY_TYPE_DECLARE(RendererData);
        using ParentType = Singleton<RendererData>;
        using Colour = Rendering::Colour<float>;
        using TextureFormat = Rendering::TextureFormat;
        using WindowStyles = System::WindowsStyles;

    private:
        enum class RendererDataCreate
        {
            Init,
        };

    public:
        explicit RendererData(RendererDataCreate rendererDataCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(RendererData);

        CLASS_INVARIANT_DECLARE;

        void LoadConfiguration(const std::string& fileName);

        void ClearColor();
        void Resize(int width, int height);

        void DrawMessage(int x, int y, const Colour& color, const std::string& message);

        NODISCARD TextureFormat GetColorFormat() const;
        NODISCARD TextureFormat GetDepthStencilFormat() const;
        NODISCARD int GetNumMultisamples() const;
        NODISCARD Colour GetClearColor() const;

        NODISCARD std::string GetWindowTitle() const;
        NODISCARD int GetXPosition() const;
        NODISCARD int GetYPosition() const;
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD bool IsAllowResize() const;

    private:
        using RendererDataUniquePtr = std::unique_ptr<RendererData>;

    private:
        static RendererDataUniquePtr rendererData;
        PackageType impl;
    };
}

#define RENDERER_DATA_SINGLETON Rendering::RendererData::GetSingleton()

#endif  // FRAMEWORK_APPLICATION_RENDERER_DATA_H
