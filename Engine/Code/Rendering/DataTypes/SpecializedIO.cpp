// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/18 15:32)

#include "Rendering/RenderingExport.h"

#include "SpecializedIO.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <> 
void CoreTools::BufferSource
	::ReadAggregate(Rendering::Transform& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;	;

	auto isIdentity = ReadBool();  
	auto isRotationOrScaleMatrix = ReadBool();
	auto isUniformScale = ReadBool();

	if(isIdentity)
	{
	    datum.MakeIdentity();
	}
	else if(isRotationOrScaleMatrix)
	{
	    if(isUniformScale)
	    {
	        Rendering::Transform::Matrix rotate;
			auto scale = 0.0f;
	        Rendering::Transform::APoint translate;

	        ReadAggregate(rotate);
	        Read(scale);
	        ReadAggregate(translate);

	        datum.SetRotate(rotate);
	        datum.SetUniformScale(scale);
	        datum.SetTranslate(translate);
	    }
	    else
	    {
	        Rendering::Transform::Matrix rotate;
	        Rendering::Transform::APoint scale;
	        Rendering::Transform::APoint translate;

	        ReadAggregate(rotate);
	        ReadAggregate(scale);
	        ReadAggregate(translate);

	        datum.SetRotate(rotate);
	        datum.SetScale(scale);
	        datum.SetTranslate(translate);
	    }
	}
	else
	{
	     Rendering::Transform::Matrix matrix;
	     Rendering::Transform::APoint translate;

	     ReadAggregate(matrix);
	     ReadAggregate(translate);

	     datum.SetMatrix(matrix);
	     datum.SetTranslate(translate);
	}
}

template <> 
void CoreTools::BufferTarget
	::WriteAggregate (const Rendering::Transform& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	auto isIdentity = datum.IsIdentity ();  
	auto isRotationOrScaleMatrix = datum.IsRotationOrScaleMatrix ();
	auto isUniformScale = datum.IsUniformScale ();

	WriteBool(isIdentity);
	WriteBool(isRotationOrScaleMatrix);
	WriteBool(isUniformScale);

	if(isIdentity)
	{
	     
	}
	else if(isRotationOrScaleMatrix)
	{
	    if(isUniformScale)
	    {
	        WriteAggregate(datum.GetRotate());
	        Write(datum.GetUniformScale ());
			WriteAggregate(datum.GetTranslate());
	    }
	    else
	    {
	        WriteAggregate(datum.GetRotate());
	        WriteAggregate(datum.GetScale ());
	        WriteAggregate(datum.GetTranslate());
	    }
	}
	else
	{
	     WriteAggregate(datum.GetMatrix());
	     WriteAggregate(datum.GetTranslate());
	}
}

template <> 
void CoreTools::BufferSource
	::ReadAggregate(Rendering::Bound& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	Rendering::Transform::APoint center;
	auto radius = 0.0f;	

	ReadAggregate(center);
	Read(radius);
 
    datum.SetCenter (center);
    datum.SetRadius (radius);
}

template <> 
void CoreTools::BufferTarget
	::WriteAggregate (const Rendering::Bound& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	WriteAggregate(datum.GetCenter());
	Write(datum.GetRadius());
} 

template <> 
void CoreTools::BufferSource
	::ReadAggregate(Rendering::Colour<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	float colour[4]   { 0.0f,0.0f,0.0f,0.0f }; 

	Read(4, colour); 

	datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
}

template <> 
void CoreTools::BufferTarget
	::WriteAggregate (const Rendering::Colour<float>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	WriteWithoutNumber(4, datum.GetPoint());
} 

template <> 
void CoreTools::BufferSource
	::ReadAggregate(Rendering::Colour<unsigned>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	uint32_t colour[4]   { 0,0,0,0 }; 

	Read(4, colour); 

	datum.SetColour(colour[0], colour[1], colour[2], colour[3]);
}

template <> 
void CoreTools::BufferTarget
	::WriteAggregate (const Rendering::Colour<unsigned>& datum)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	WriteWithoutNumber(4, datum.GetPoint());
} 

