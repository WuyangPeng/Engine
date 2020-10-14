// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/22 17:33)

#include "Rendering/RenderingExport.h"

#include "LoadVisual.h"
#include "VisualData.h"
#include "Visual.h"
#include "Polypoint.h"
#include "Polysegment.h"
#include "TrianglesFan.h"
#include "TrianglesMesh.h"
#include "TrianglesStrip.h"
#include "CoreTools/FileManager/ReadFileManager.h"  

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
 
using std::make_shared;
using CoreTools::ReadFileManager;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26409)
Rendering::LoadVisual
	::LoadVisual(const System::String& name)
	:m_Data{ make_shared<VisualData>() }
{
	LoadFromFile(name);

	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::LoadVisual
	::IsValid() const noexcept
{
	if (m_Data != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Rendering::VisualPrimitiveType Rendering::LoadVisual
	::GetPrimitiveType() const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Data->GetPrimitiveType();
}

Rendering::VertexFormatSharedPtr Rendering::LoadVisual
	::GetVertexFormat()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Data->GetVertexFormat();
}

Rendering::VertexBufferSharedPtr Rendering::LoadVisual
	::GetVertexBuffer()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Data->GetVertexBuffer();
}

Rendering::IndexBufferSharedPtr Rendering::LoadVisual
	::GetIndexBuffer()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Data->GetIndexBuffer();
}

void Rendering::LoadVisual
	::LoadFromFile(const System::String& name)
{
	ReadFileManager manager{ name };

	auto type = 0;

	manager.Read(sizeof(int), &type);	

	if (System::EnumCastUnderlying(VisualPrimitiveType::None) < type && type < System::EnumCastUnderlying(VisualPrimitiveType::MaxQuantity))
	{	
		auto vertexFormat =	VertexFormat::LoadFromFile(manager);

		VertexBufferSharedPtr vertexBuffer{ std::make_shared<VertexBuffer>() };

		vertexBuffer->ReadFromFile(manager,vertexFormat);

		IndexBufferSharedPtr indexBuffer{ std::make_shared<IndexBuffer>() };
		indexBuffer->ReadFromFile(manager);

		m_Data->SetPrimitiveType(System::UnderlyingCastEnum<VisualPrimitiveType>(type));
		m_Data->SetVertexFormat(vertexFormat);
		m_Data->SetVertexBuffer(vertexBuffer);

		if (indexBuffer->GetNumElements() != 0)
			m_Data->SetIndexBuffer(indexBuffer);
		else
			m_Data->SetIndexBuffer(IndexBufferSharedPtr{});
	}
}

Rendering::VisualSharedPtr Rendering::LoadVisual
	::CreateFromFile(const System::String& name) 
{
	LoadVisual loadVisual{ name };

	switch (loadVisual.GetPrimitiveType())
	{
	case VisualPrimitiveType::Polypoint:
            return VisualSharedPtr{ std::make_shared < Polypoint>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer()) };
	case VisualPrimitiveType::PolysegmentsDisjoint:
            return VisualSharedPtr{ std::make_shared < Polysegment>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), false) };
	case VisualPrimitiveType::PolysegmentsContiguous:
            return VisualSharedPtr{ std::make_shared < Polysegment>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), true) };
	case VisualPrimitiveType::TriangleMesh:
            return VisualSharedPtr{ std::make_shared < TrianglesMesh>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), loadVisual.GetIndexBuffer()) };
	case VisualPrimitiveType::TriangleStrip:
	    {
			auto indexBuffer = loadVisual.GetIndexBuffer();					
			if (!indexBuffer)
			{
                            return VisualSharedPtr{ std::make_shared < TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), 2) };
			}
			else
			{
                            return VisualSharedPtr{ std::make_shared < TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexBuffer) };
			}			
	    }
	case VisualPrimitiveType::TriangleFan:
	    {
		auto indexBuffer = loadVisual.GetIndexBuffer();
			if (!indexBuffer )
			{
                            return VisualSharedPtr{ std::make_shared < TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), 2) };
			}
			else
			{
                            return VisualSharedPtr{ std::make_shared < TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexBuffer) };
			}
	    }
				 
	default:
	    {
		     THROW_EXCEPTION(SYSTEM_TEXT("PrimitiveType¥ÌŒÛ£°"s));
	    }
	}
}

Rendering::VisualSharedPtr 
	Rendering::LoadVisual::CreateFromFile(const System::String& name, int indexSize)
{
	LoadVisual loadVisual{ name };

	switch (loadVisual.GetPrimitiveType())
	{	 
	case VisualPrimitiveType::TriangleStrip:		
		return VisualSharedPtr{ std::make_shared < TrianglesStrip>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexSize) };
	case VisualPrimitiveType::TriangleFan:		
		return VisualSharedPtr{ std::make_shared < TrianglesFan>(loadVisual.GetVertexFormat(), loadVisual.GetVertexBuffer(), indexSize) };
	default:
	    {
		     THROW_EXCEPTION(SYSTEM_TEXT("PrimitiveType¥ÌŒÛ£°"s));
	    }
	}
}

 #include STSTEM_WARNING_POP