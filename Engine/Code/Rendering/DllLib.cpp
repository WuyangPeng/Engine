//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.0.0 (2020/08/16 15:03)

// ��Ⱦ�⣨Rendering��λ������ĵ��Ĳ㣬
// ֻ������������е�System��CoreTools��Mathematics�⣬��ʹ��boost��������Ⱦ��صĹ��߿⡣

// ��Ⱦ���������ģ�飺
// 1.	Helper��������
// 2.   DataTypes���������ͣ�
// 3.	Resources����Դ��
// 4.	SceneGraph������ͼ��
// 5.	Controllers����������
// 6.	ShaderFloats��������ɫ����
// 7.	Detail��ϸ�ڣ�
// 8.	Shaders����ɫ����
// 9.	LocalEffects���ֲ���Ч��
// 10.	GlobalEffects��ȫ����Ч��
// 11.	CurvesSurfaces���������棩
// 12.	Illumination�����գ�
// 13.	ImageProcessing��ͼ����
// 14.	Picture��ͼ��
// 15.	Sorting������
// 16.	Terrain�����δ���
// 17.	Vertex�����㣩
// 18.	TextFonts���ı������壩
// 19.	ConsoleGraph������̨ͼ�Σ�
// 20.	OpenGLAPI��OpenGLAPI��
// 21.	DirectAPI��DirectAPI��
// 22.	Renderers����Ⱦ����
// 23.	OpenGLRenderer��OpenGL��Ⱦ����
// 24.	Dx9Renderer��Dx9��Ⱦ����
// 25.	AglRenderer��Agl��Ⱦ����
// 26.	GlutRenderer��Glut��Ⱦ����
// 27.	GlxRenderer��Glx��Ⱦ����
// 28.	WglRenderer��Wgl��Ⱦ����
// 29.	Lib3ds��Lib3ds��
// 30.	Abuse��Abuse��
// 31.	Demogl��demogl��
// 32.	DevIL��DevIL��
// 33.	FBX��FBX��
// 34.	JPEG��JPEG��
// 35.	TIFF��TIFF��
// 36.	Openvidia��openvidia��
// 37.	Nethack��nethack��
// 38.	Wing��wing��
// 39.	Wargamer��wargamer��
// 40.	Nvtoolkit��nvtoolkit��

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
