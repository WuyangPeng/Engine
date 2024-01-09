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
        using StateMode = System::DepthStencilStateMode;
        using StateOperation = System::DepthStencilStateOperation;
        using StateWriteMask = System::DepthStencilStateWriteMask;

    public:
        OpenGLDepthStencilStateImpl() noexcept;
        explicit OpenGLDepthStencilStateImpl(const DepthStencilState& depthStencilState);

        CLASS_INVARIANT_DECLARE;

        NODISCARD static StateMode GetDepthStencilStateMode(DepthStencilStateComparison depthStencilStateComparison);
        NODISCARD static StateOperation GetDepthStencilStateOperation(DepthStencilStateOperation depthStencilStateOperation);
        NODISCARD static StateWriteMask GetDepthStencilStateWriteMask(DepthStencilStateWriteMask depthStencilStateWriteMask);

        NODISCARD bool IsDepthEnable() const noexcept;
        void SetDepthEnable(bool aDepthEnable) noexcept;

        NODISCARD StateWriteMask GetWriteMask() const noexcept;
        void SetWriteMask(StateWriteMask aWriteMask) noexcept;

        NODISCARD StateMode GetComparison() const noexcept;
        void SetComparison(StateMode aComparison) noexcept;

        NODISCARD bool IsStencilEnable() const noexcept;
        void SetStencilEnable(bool aStencilEnable) noexcept;

        NODISCARD OpenGLInt GetStencilReadMask() const noexcept;
        void SetStencilReadMask(OpenGLInt aStencilReadMask) noexcept;

        NODISCARD OpenGLInt GetStencilWriteMask() const noexcept;
        void SetStencilWriteMask(OpenGLInt aStencilWriteMask) noexcept;

        NODISCARD OpenGLInt GetReference() const noexcept;
        void SetReference(OpenGLInt aReference) noexcept;

        NODISCARD StateOperation GetFrontOnFail() const noexcept;
        void SetFrontOnFail(StateOperation onFail) noexcept;

        NODISCARD StateOperation GetFrontOnZFail() const noexcept;
        void SetFrontOnZFail(StateOperation onZFail) noexcept;

        NODISCARD StateOperation GetFrontOnZPass() const noexcept;
        void SetFrontOnZPass(StateOperation onZPass) noexcept;

        NODISCARD StateMode GetFrontComparison() const noexcept;
        void SetFrontComparison(StateMode aComparison) noexcept;

        NODISCARD StateOperation GetBackOnFail() const noexcept;
        void SetBackOnFail(StateOperation onFail) noexcept;

        NODISCARD StateOperation GetBackOnZFail() const noexcept;
        void SetBackOnZFail(StateOperation onZFail) noexcept;

        NODISCARD StateOperation GetBackOnZPass() const noexcept;
        void SetBackOnZPass(StateOperation onZPass) noexcept;

        NODISCARD StateMode GetBackComparison() const noexcept;
        void SetBackComparison(StateMode aComparison) noexcept;

    private:
        bool depthEnable;
        StateWriteMask writeMask;
        StateMode comparison;
        bool stencilEnable;
        OpenGLInt stencilReadMask;
        OpenGLInt stencilWriteMask;
        OpenGLDepthStencilStateFace frontFace;
        OpenGLDepthStencilStateFace backFace;
        OpenGLInt reference;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_IMPL_H
