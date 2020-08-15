// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 16:01)

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "VertexBufferAccessor.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/Renderers/RendererManager.h" 
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26486)
CORE_TOOLS_RTTI_DEFINE(Rendering,VertexBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering,VertexBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering,VertexBuffer); 
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, VertexBuffer);

Rendering::VertexBuffer
	::VertexBuffer() noexcept
	:ParentType{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBuffer
	::VertexBuffer( int numVertices, int vertexSize,BufferUsage usage)
	:ParentType{ numVertices,vertexSize,usage }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexBuffer
	::~VertexBuffer ()
{
	EXCEPTION_TRY
	{
            RENDERER_MANAGE_SINGLETON.UnbindAll(this); 
	}
	EXCEPTION_ALL_CATCH(Rendering)
    

	RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering,VertexBuffer)

void Rendering::VertexBuffer
	::SaveToFile(WriteFileManager& outFile, const ConstVertexFormatSmartPointer& vertexformat) const 
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	ParentType::SaveHeadToFile(outFile);
	ParentType::SaveBufferDataToFile(outFile, vertexformat);	
}

void Rendering::VertexBuffer
	::ReadFromFile(ReadFileManager& inFile, const ConstVertexFormatSmartPointer& vertexformat)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::ReadHeadFromFile(inFile);
	ParentType::ReadBufferDataFromFile(inFile, vertexformat);
}

void Rendering::VertexBuffer
	::ClearModelNormals(const VertexBufferAccessor& vertexBufferAccessor)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(),"VertexBufferAccessor关联的VertexBuffer不是this！");	
	 
	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstNormal = reinterpret_cast<float*>(data);
		auto secondNormal = firstNormal + 1;
		auto thirdNormal = secondNormal + 1;

		*firstNormal = 0.0f;
		*secondNormal = 0.0f;
		*thirdNormal = 0.0f;
	}
}
	
void Rendering::VertexBuffer
	::NormalizeModelNormals(const VertexBufferAccessor& vertexBufferAccessor) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(),"VertexBufferAccessor关联的VertexBuffer不是this！");	

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstNormal = reinterpret_cast<float*>(data);
		auto secondNormal = firstNormal + 1;
		auto thirdNormal = secondNormal + 1;

		AVector vector{ *firstNormal, *secondNormal, *thirdNormal };
		vector.Normalize();		

		*firstNormal = vector[0];
		*secondNormal = vector[1];
		*thirdNormal = vector[2];
	}
}


void Rendering::VertexBuffer
	::AddTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& normal) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");	

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstNormal = reinterpret_cast<float*>(data);
		auto secondNormal = firstNormal + 1;
		auto thirdNormal = secondNormal + 1;

		AVector sum{ *firstNormal, *secondNormal, *thirdNormal };
		sum += normal;

		*firstNormal = sum[0];
		*secondNormal = sum[1];
		*thirdNormal = sum[2];
	}
}


void Rendering::VertexBuffer
	::SetTriangleTangent(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& tangent) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetTangentExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstTangent = reinterpret_cast<float*>(data);
		auto secondTangent = firstTangent + 1;
		auto thirdTangent = secondTangent + 1;

		*firstTangent = tangent[0];
		*secondTangent = tangent[1];
		*thirdTangent = tangent[2];
	}
}


void Rendering::VertexBuffer
	::SetTriangleBinormal(const VertexBufferAccessor& vertexBufferAccessor, int index, const AVector& binormal) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetBinormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstBinormal = reinterpret_cast<float*>(data);
		auto secondBinormal = firstBinormal + 1;
		auto thirdBinormal = secondBinormal + 1;

		*firstBinormal = binormal[0];
		*secondBinormal = binormal[1];
		*thirdBinormal = binormal[2];
	}
}

void Rendering::VertexBuffer
	::ClearTangent(const VertexBufferAccessor& vertexBufferAccessor) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto excursion = vertexBufferAccessor.GetTangentExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstTangent = reinterpret_cast<float*>(data);
		auto secondTangent = firstTangent + 1;
		auto thirdTangent = secondTangent + 1;

		*firstTangent = 0.0f;
		*secondTangent = 0.0f;
		*thirdTangent = 0.0f;
	}
}


void Rendering::VertexBuffer
	::ClearBinormal(const VertexBufferAccessor& vertexBufferAccessor) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto excursion = vertexBufferAccessor.GetBinormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstBinormal = reinterpret_cast<float*>(data);
		auto secondBinormal = firstBinormal + 1;
		auto thirdBinormal = secondBinormal + 1;

		*firstBinormal = 0.0f;
		*secondBinormal = 0.0f;
		*thirdBinormal = 0.0f;
	}
}


void Rendering::VertexBuffer
	::SetTextureCoordStandard(const VertexBufferAccessor& vertexBufferAccessor) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	for (auto index = 0; index < numVertices; ++index)
	{
		const auto excursion = vertexBufferAccessor.GetTextureCoordExcursion(0,index);
		auto data = GetAccessWriteData(excursion);

		auto firstTextureCoord = reinterpret_cast<float*>(data);
		auto secondTextureCoord = firstTextureCoord + 1;
	 
		if (index % 4 == 0 || index % 4 == 3)
		{
			*firstTextureCoord = 0.0f;
		}
		else
		{
			*firstTextureCoord = 1.0f;
		}

		if (index % 4 == 0 || index % 4 == 1)
		{
			*secondTextureCoord = 0.0f;
		}
		else
		{
			*secondTextureCoord = 1.0f;
		}		 
	}
}

void Rendering::VertexBuffer
	::SetPosition(const VertexBufferAccessor& vertexBufferAccessor, int index, const APoint& position) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetPositionExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstPosition = reinterpret_cast<float*>(data);
		auto secondPosition = firstPosition + 1;
		auto thirdPosition = secondPosition + 1;

		*firstPosition = position[0];
		*secondPosition = position[1];
		*thirdPosition = position[2];
	}
}

void Rendering::VertexBuffer
	::SetTextureCoord(const VertexBufferAccessor& vertexBufferAccessor,int index, const Vector2D& textureCoord,int unit) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetTextureCoordExcursion(unit, index);
		auto data = GetAccessWriteData(excursion);

		auto firstTextureCoord = reinterpret_cast<float*>(data);
		auto secondTextureCoord = firstTextureCoord + 1;

		*firstTextureCoord = textureCoord[0];
		*secondTextureCoord = textureCoord[1];
	}
}

void Rendering::VertexBuffer
	::SetTriangleNormal(const VertexBufferAccessor& vertexBufferAccessor,int index, const AVector& normal) 
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
	RENDERING_ASSERTION_1(vertexBufferAccessor.GetData() == GetReadOnlyData(), "VertexBufferAccessor关联的VertexBuffer不是this！");	

	const auto numVertices = vertexBufferAccessor.GetNumVertices();

	if (0 <= index && index < numVertices)
	{
		const auto excursion = vertexBufferAccessor.GetNormalExcursion(index);
		auto data = GetAccessWriteData(excursion);

		auto firstNormal = reinterpret_cast<float*>(data);
		auto secondNormal = firstNormal + 1;
		auto thirdNormal = secondNormal + 1;

		*firstNormal = normal[0];
		*secondNormal = normal[1];
		*thirdNormal = normal[2];
	}
}

Rendering::VertexBufferSmartPointer
	Rendering::VertexBuffer::Clone() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return VertexBufferSmartPointer{ std::make_shared<ClassType>(*this) };
}

#include STSTEM_WARNING_POP