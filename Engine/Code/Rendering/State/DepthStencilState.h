///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:11)

#ifndef RENDERING_STATE_DEPTH_STENCIL_STATE_H
#define RENDERING_STATE_DEPTH_STENCIL_STATE_H

#include "Rendering/RenderingDll.h"

#include "DepthStencilStateFace.h"
#include "DrawingState.h"
#include "StateFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthStencilState : public DrawingState
    {
    public:
        using ClassType = DepthStencilState;
        using ParentType = DrawingState;

    public:
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;

    private:
        enum class DepthStencilStateCreate
        {
            Init,
        };

    public:
        NODISCARD static DepthStencilStateSharedPtr Create(const std::string& name);
        explicit DepthStencilState(DepthStencilStateCreate depthStencilStateCreate, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DepthStencilState);

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD bool IsDepthEnable() const noexcept;
        void SetDepthEnable(bool aDepthEnable) noexcept;

        NODISCARD DepthStencilStateWriteMask GetWriteMask() const noexcept;
        void SetWriteMask(DepthStencilStateWriteMask depthStencilStateWriteMask) noexcept;

        NODISCARD DepthStencilStateComparison GetComparison() const noexcept;
        void SetComparison(DepthStencilStateComparison depthStencilStateComparison) noexcept;

        NODISCARD bool IsStencilEnable() const noexcept;
        void SetStencilEnable(bool aStencilEnable) noexcept;

        NODISCARD int GetStencilReadMask() const noexcept;
        void SetStencilReadMask(int aStencilReadMask) noexcept;

        NODISCARD int GetStencilWriteMask() const noexcept;
        void SetStencilWriteMask(int aStencilWriteMask) noexcept;

        NODISCARD DepthStencilStateFace GetFrontFace() const noexcept;
        NODISCARD DepthStencilStateFace GetBackFace() const noexcept;

        void SetFrontFaceFail(DepthStencilStateOperation fail) noexcept;
        void SetFrontFaceDepthFail(DepthStencilStateOperation depthFail) noexcept;
        void SetFrontFacePass(DepthStencilStateOperation pass) noexcept;
        void SetFrontFaceComparison(DepthStencilStateComparison aComparison) noexcept;

        void SetBackFaceFail(DepthStencilStateOperation fail) noexcept;
        void SetBackFaceDepthFail(DepthStencilStateOperation depthFail) noexcept;
        void SetBackFacePass(DepthStencilStateOperation pass) noexcept;
        void SetBackFaceComparison(DepthStencilStateComparison aComparison) noexcept;

        NODISCARD int GetReference() const noexcept;
        void SetReference(int aReference) noexcept;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        void CheckDepthStencilState();

    private:
        bool depthEnable;
        DepthStencilStateWriteMask writeMask;
        DepthStencilStateComparison comparison;
        bool stencilEnable;
        int stencilReadMask;
        int stencilWriteMask;
        DepthStencilStateFace frontFace;
        DepthStencilStateFace backFace;
        int reference;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DepthStencilState);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DepthStencilState);
}

#endif  // RENDERING_STATE_DEPTH_STENCIL_STATE_H
