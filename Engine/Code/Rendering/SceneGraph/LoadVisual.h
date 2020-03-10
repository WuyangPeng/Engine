// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 11:23)

#ifndef RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
#define RENDERING_SCENE_GRAPH_LOAD_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Visual.h"
#include "Flags/VisualFlags.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>

RENDERING_EXPORT_SHARED_PTR(VisualData);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace CoreTools
{
	class ReadFileManager;
}

namespace Rendering
{
	class Visual;

	class RENDERING_DEFAULT_DECLARE LoadVisual : private boost::noncopyable
	{
	public:
		using ClassType = LoadVisual;
		using ClassShareType = CoreTools::NonCopyClasses;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		explicit LoadVisual(const System::String& name);

		CLASS_INVARIANT_DECLARE;

		VisualPrimitiveType GetPrimitiveType() const;
		 
		VertexFormatSmartPointer GetVertexFormat();		 
		VertexBufferSmartPointer GetVertexBuffer();	 
		IndexBufferSmartPointer GetIndexBuffer();

		static VisualSmartPointer CreateFromFile(const System::String& name);
		static VisualSmartPointer CreateFromFile(const System::String& name, int indexSize);

	private:
		using VisualDataPtr = std::shared_ptr<VisualData>;

	private:
		void LoadFromFile(const System::String& name);	

	private:
		VisualDataPtr m_Data;
	};
}

#endif // RENDERING_SCENE_GRAPH_LOAD_VISUAL_H
