///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/State/OpenGLDepthStencilStateFace.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDepthStencilStateImpl
    {
    public:
        using ClassType = OpenGLDepthStencilStateImpl;
        using OpenGLInt = System::OpenGLInt; 
        using DepthStencilStateMode = System::DepthStencilStateMode;

    public:
        OpenGLDepthStencilStateImpl() noexcept;
        explicit OpenGLDepthStencilStateImpl(const DepthStencilState& depthStencilState);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static DepthStencilStateMode GetDepthStencilStateMode(DepthStencilStateComparison depthStencilStateComparison);
        NODISCARD static System::DepthStencilStateOperation GetDepthStencilStateOperation(DepthStencilStateOperation depthStencilStateOperation);
        NODISCARD static System::DepthStencilStateWriteMask GetDepthStencilStateWriteMask(DepthStencilStateWriteMask depthStencilStateWriteMask);

        NODISCARD bool IsDepthEnable() const noexcept;
        void SetDepthEnable(bool aDepthEnable) noexcept;

        NODISCARD System::DepthStencilStateWriteMask GetWriteMask() const noexcept;
        void SetWriteMask(System::DepthStencilStateWriteMask aWriteMask) noexcept;

        NODISCARD DepthStencilStateMode GetComparison() const noexcept;
        void SetComparison(DepthStencilStateMode aComparison) noexcept;

        NODISCARD bool IsStencilEnable() const noexcept;
        void SetStencilEnable(bool aStencilEnable) noexcept;

        NODISCARD OpenGLInt GetStencilReadMask() const noexcept;
        void SetStencilReadMask(OpenGLInt aStencilReadMask) noexcept;

        NODISCARD OpenGLInt GetStencilWriteMask() const noexcept;
        void SetStencilWriteMask(OpenGLInt aStencilWriteMask) noexcept;

        NODISCARD OpenGLInt GetReference() const noexcept;
        void SetReference(OpenGLInt aReference) noexcept;

        NODISCARD System::DepthStencilStateOperation GetFrontOnFail() const noexcept;
        void SetFrontOnFail(System::DepthStencilStateOperation onFail) noexcept;

        NODISCARD System::DepthStencilStateOperation GetFrontOnZFail() const noexcept;
        void SetFrontOnZFail(System::DepthStencilStateOperation onZFail) noexcept;

        NODISCARD System::DepthStencilStateOperation GetFrontOnZPass() const noexcept;
        void SetFrontOnZPass(System::DepthStencilStateOperation onZPass) noexcept;

        NODISCARD System::DepthStencilStateMode GetFrontComparison() const noexcept;
        void SetFrontComparison(System::DepthStencilStateMode aComparison) noexcept;

        NODISCARD System::DepthStencilStateOperation GetBackOnFail() const noexcept;
        void SetBackOnFail(System::DepthStencilStateOperation onFail) noexcept;

        NODISCARD System::DepthStencilStateOperation GetBackOnZFail() const noexcept;
        void SetBackOnZFail(System::DepthStencilStateOperation onZFail) noexcept;

        NODISCARD System::DepthStencilStateOperation GetBackOnZPass() const noexcept;
        void SetBackOnZPass(System::DepthStencilStateOperation onZPass) noexcept;

        NODISCARD System::DepthStencilStateMode GetBackComparison() const noexcept;
        void SetBackComparison(System::DepthStencilStateMode aComparison) noexcept;

    private:
        bool depthEnable;
        System::DepthStencilStateWriteMask writeMask;
        DepthStencilStateMode comparison;
        bool stencilEnable;
        OpenGLInt stencilReadMask;
        OpenGLInt stencilWriteMask;
        OpenGLDepthStencilStateFace frontFace;
        OpenGLDepthStencilStateFace backFace;
        OpenGLInt reference;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_IMPL_H
