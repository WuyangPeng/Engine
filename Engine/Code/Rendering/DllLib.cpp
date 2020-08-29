//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/16 15:03)

// 渲染库（Rendering）位于引擎的第四层，
// 只允许调用引擎中的System、CoreTools、Mathematics库，并使用boost和其他渲染相关的工具库。

// 渲染库包含以下模块：
// 1.	Helper（帮助）
// 2.   DataTypes（数据类型）
// 3.	Resources（资源）
// 4.	SceneGraph（场景图）
// 5.	Controllers（控制器）
// 6.	ShaderFloats（浮点着色器）
// 7.	Detail（细节）
// 8.	Shaders（着色器）
// 9.	LocalEffects（局部特效）
// 10.	GlobalEffects（全局特效）
// 11.	CurvesSurfaces（曲线曲面）
// 12.	Illumination（光照）
// 13.	ImageProcessing（图像处理）
// 14.	Picture（图像）
// 15.	Sorting（排序）
// 16.	Terrain（地形处理）
// 17.	Vertex（顶点）
// 18.	TextFonts（文本及字体）
// 19.	ConsoleGraph（控制台图形）
// 20.	OpenGLAPI（OpenGLAPI）
// 21.	DirectAPI（DirectAPI）
// 22.	Renderers（渲染器）
// 23.	OpenGLRenderer（OpenGL渲染器）
// 24.	Dx9Renderer（Dx9渲染器）
// 25.	AglRenderer（Agl渲染器）
// 26.	GlutRenderer（Glut渲染器）
// 27.	GlxRenderer（Glx渲染器）
// 28.	WglRenderer（Wgl渲染器）
// 29.	Lib3ds（Lib3ds）
// 30.	Abuse（Abuse）
// 31.	Demogl（demogl）
// 32.	DevIL（DevIL）
// 33.	FBX（FBX）
// 34.	JPEG（JPEG）
// 35.	TIFF（TIFF）
// 36.	Openvidia（openvidia）
// 37.	Nethack（nethack）
// 38.	Wing（wing）
// 39.	Wargamer（wargamer）
// 40.	Nvtoolkit（nvtoolkit）

#include "Rendering/RenderingExport.h"

#include "Rendering/Rendering.h"

#ifndef BUILDING_RENDERING_STATIC

    #include "DllLib.h"

#else  // BUILDING_RENDERING_STATIC

    namespace Rendering
    {
        void StaticDllLib() noexcept
        {

        }
    }

#endif  // !BUILDING_RENDERING_STATIC
