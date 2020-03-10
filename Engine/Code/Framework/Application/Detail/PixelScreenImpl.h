// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:04)

#ifndef FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H
#define FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Renderers/Renderer.h"
#include "Framework/WindowCreate/WindowSize.h" 

#include <vector>

namespace Rendering
{
	class Renderer;
}

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE PixelScreenImpl
	{
	public:
		using ClassType = PixelScreenImpl;
		using Colour = Rendering::Colour<unsigned char>;
		using Renderer = Rendering::Renderer;

	public:
		explicit PixelScreenImpl(const WindowSize& size);
	
		CLASS_INVARIANT_DECLARE;

		void Resize(const WindowSize& size, const Colour& color);

		void Draw(const Rendering::RendererSmartPointer& renderer);

		void ClearScreen(const Colour& color);

        // ��������ֻ��ơ��������Ի��Ƶ�������Ļ������������֮ǰ��
        // ��Ļ�����Ƶ�����һ�����л�������
        // ��ֻ��Ҫ��Ӧ�ó������DoFlip (true)һ�εġ�Ĭ��ֵ�ǡ�false����
		void DoFlip (bool doFlip);

		bool IsDoFlip() const;
	
		// ����λ��(x,y)������Ϊָ������ɫ��
		void SetPixel (int x, int y, const Colour& color);

		// �������� (x',y') �� x - thick <= x' <= x + thick ��
		// y - thick <= y' <= y + thick.
		void SetThickPixel (int x, int y, int thick, const Colour& color);

		// ��ȡλ��(x,y)��������ɫ�� 
		const Colour GetPixel (int x, int y) const;
 
		// ʹ��Bresenham�㷨��������Ϊָ���ĵ���ɫ�ӻ���(beginX, beginY) �� (endX, endY)��
		// ���㷨����ƫ��ģ�ͨ��DrawLine(beginX, beginY, endX, endY)�趨�����ز�һ��
		// ͬDrawLine(endX, endY, beginX, beginY)���õ���ͬ��
		// TODO��ʵ���е��㷨���Ա���ƫ�
		void DrawLine (int beginX, int beginY,int endX, int endY,const Colour& color);

        // ʹ��ָ������ɫ�����������Ρ�solid����ָʾ�Ƿ������Ρ�
		void DrawRectangle (int xMin, int yMin, int xMax,int yMax, const Colour& color, bool solid = false);
 
		// ʹ��Bresenham�㷨����������(xCenter,yCenter)��ָ�����뾶����
		// ��ʹ��ָ������ɫ��Բ��'solid'����ָʾ�Ƿ����Ȧ��
		void DrawCircle (int xCenter, int yCenter, int radius,const Colour& color, bool solid = false);
 
        // ��ˮ���һ������ͨ���ı���������ɫ������ɫ��Ϊ��ǰ��ɫ����
        // ��䴦��4������Ҳ����˵����(x,y)�����ʣ���(x + 1,y), (x,y - 1), �� (x,y + 1)
        // �����ʣ���Ϊ����������Ļ�ı߽磩���ú���ͨ��ʹ��ջ��
        // �Ӷ������������ĵݹ���ۺ͵��ö�ջ����Ŀ��ܡ�
		void Fill (int x, int y, const Colour& foreColor,const Colour& backColor);	

	private:
	    using ColourVector = std::vector<Colour>;

	private:
		void DrawSolidCircle (int xCenter, int yCenter, int radius,const Colour& color);
		void DrawHollowCircle (int xCenter, int yCenter, int radius,const Colour& color);

	private:
		int m_ScreenWidth;
		int m_ScreenHeight;
		ColourVector m_Screen;
		bool m_DoFlip;
	};
}

#endif // FRAMEWORK_APPLICATION_PIXEL_SCREEN_IMPL_H



	