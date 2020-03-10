// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:36)

#ifndef FRAMEWORK_APPLICATION_RENDERER_DATA_H
#define FRAMEWORK_APPLICATION_RENDERER_DATA_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "System/Window/Flags/WindowFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(RendererDataImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class Mutex;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE RendererData : public CoreTools::Singleton<RendererData>
	{
	public:
		SINGLETON_INITIALIZE_DECLARE(RendererData); 
		using Colour = Rendering::Colour<float>;
		using TextureFormat = Rendering::TextureFormat;
		using WindowStyles = System::WindowStyles;

	public:	
		CLASS_INVARIANT_DECLARE;

		void LoadConfiguration(const std::string& fileName);

		void ClearColor();
		void Resize(int width,int height);

		void DrawMessage (int x,int y,const Colour& color,const std::string& message);

		TextureFormat GetColorFormat() const;
		TextureFormat GetDepthStencilFormat() const;
		int GetNumMultisamples() const;
		Colour GetClearColor() const;

		const std::string GetWindowTitle() const;
		int GetXPosition () const;
		int GetYPosition () const;
		int GetWidth () const;
		int GetHeight () const;
		bool IsAllowResize() const;

	private:		
		SINGLETON_INSTANCE_DECLARE(RendererData);
		SINGLETON_IMPL_DECLARE(RendererData);
	};
}

#define RENDERER_DATA_SINGLETON Rendering::RendererData::GetSingleton()

#endif // FRAMEWORK_APPLICATION_RENDERER_DATA_H



	