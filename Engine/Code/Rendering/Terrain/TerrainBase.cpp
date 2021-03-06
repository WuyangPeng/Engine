// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 10:52)

#include "Rendering/RenderingExport.h"

#include "TerrainBase.h"
#include "System/CharacterString/FormatStringDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/CharacterString/StringConversion.h"

#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
 #include "System/Helper/PragmaWarning.h"
 #include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TerrainBase);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TerrainBase);

Rendering::TerrainBase
	::TerrainBase(const System::String& heightName, VertexFormatSharedPtr vformat, CameraSharedPtr camera )
    : mMode(0),mVFormat(vformat), mCameraRow(-1), mCameraCol(-1), mCamera(camera)
{
    // Load global terrain information.
    LoadHeader(heightName);

    // Load terrain pages.
	mPages = NEW2<TerrainPageSharedPtr>(mNumCols, mNumRows);
    int row = 0, col = 0;
    for (row = 0; row < mNumRows; ++row)
    {
        for (col = 0; col < mNumCols; ++col)
        {
            char temp[64];
			System::SNPrintf(temp, 64, 64, "%d.%d", row, col);
            std::string heightSuffix(temp);
			LoadPage(row, col, heightName, CoreTools::StringConversion::MultiByteConversionStandard( heightSuffix));
        }
    }

    // Attach the terrain pages to the terrain node.

//    mChild.resize(mNumRows*mNumCols);
    for (row = 0; row < mNumRows; ++row)
    {
        for (col = 0; col < mNumCols; ++col)
        {
            AttachChild(mPages[row][col]);
        }
    }
}

Rendering::TerrainBase
	::~TerrainBase ()
{
	EXCEPTION_TRY
{
for (int row = 0; row < mNumRows; ++row)
    {
        for (int col = 0; col < mNumCols; ++col)
        {
            mPages[row][col].reset();
        }
    }
    DELETE2(mPages);
}
EXCEPTION_ALL_CATCH(Rendering) 
    
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase
	::GetPage(int row, int col)
{
    if (0 <= row && row < mNumRows && 0 <= col && col < mNumCols)
    {
        return mPages[row][col];
    }

    RENDERING_ASSERTION_0(false, "Invalid row or column index\n");
	return TerrainPageSharedPtr();
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase
	::GetCurrentPage(float x, float y) const noexcept
{
    const float invLength = 1.0f/(mSpacing*(float)(mSize - 1));

    int col = (int)Mathematics:: FloatMath::Floor(x*invLength);
    col %= mNumCols;
    if (col < 0)
    {
        col += mNumCols;
    }

	int row = (int)Mathematics::FloatMath::Floor(y*invLength);
    row %= mNumRows;
    if (row < 0)
    {
        row += mNumRows;
    }

    return mPages[row][col];
}

float Rendering::TerrainBase
	::GetHeight (float x, float y) const
{
	TerrainPageSharedPtr page = GetCurrentPage(x, y);

    // Subtract off the translation due to wrap-around.
    x -= page->GetLocalTransform().GetTranslate()[0];
	y -= page->GetLocalTransform().GetTranslate()[1];

    return page->GetHeight(x, y);
}

Mathematics::FloatAVector Rendering::TerrainBase
	::GetNormal(float x, float y) const
{
    const float xp = x + mSpacing;
    const float xm = x - mSpacing;
   const float yp = y + mSpacing;
    const float ym = y - mSpacing;

	TerrainPageSharedPtr page = GetCurrentPage(xp, y);
    float xtmp = xp - page->GetLocalTransform().GetTranslate()[0];
	float ytmp = y - page->GetLocalTransform().GetTranslate()[1];
   const float hpz = page->GetHeight(xtmp,ytmp);

    page = GetCurrentPage(xm, y);
	xtmp = xm - page->GetLocalTransform().GetTranslate()[0];
	ytmp = y - page->GetLocalTransform().GetTranslate()[1];
   const float hmz = page->GetHeight(xtmp,ytmp);

    page = GetCurrentPage(x, yp);
	xtmp = x - page->GetLocalTransform().GetTranslate()[0];
	ytmp = yp - page->GetLocalTransform().GetTranslate()[1];
   const float hzp = page->GetHeight(xtmp,ytmp);

    page = GetCurrentPage(x, ym);
	xtmp = x - page->GetLocalTransform().GetTranslate()[0];
	ytmp = ym - page->GetLocalTransform().GetTranslate()[1];
   const float hzm = page->GetHeight(xtmp,ytmp);

	Mathematics::FloatAVector normal(hmz - hpz, hzm - hzp, 1.0f);
    normal.Normalize();
    return normal;
}

void Rendering::TerrainBase
	::LoadHeader (const System::String& heightName)
{
    // Load the data into temporary variables.  EndianCopy uses memcpy, so
    // if you were to load directly into the class members and use memcpy,
    // the source and destination overlap, in which case memcpy results are
    // unpredictable.
	System::String fileName = heightName + SYSTEM_TEXT(".wmhf");
    CoreTools::ReadFileManager header(fileName);
   // RENDERING_ASSERTION_0(header, "Cannot open file %s\n", fileName);

    header.Read(sizeof(int), &mNumRows);
    header.Read(sizeof(int), &mNumCols);

    unsigned short size;
    header.Read(sizeof(unsigned short), &size);
    mSize = (int)size;

    header.Read(sizeof(float), &mMinElevation);
    header.Read(sizeof(float), &mMaxElevation);
    header.Read(sizeof(float), &mSpacing);

   
}

void Rendering::TerrainBase
	::LoadPage(int row, int col, const System::String& heightName, const System::String& heightSuffix)
{
    const int numHeights = mSize*mSize;
    unsigned short* heights = NEW1<unsigned short>(numHeights);
	System::String fileName = heightName + SYSTEM_TEXT(".") + heightSuffix + SYSTEM_TEXT(".wmhf");
	CoreTools::ReadFileManager heightFile(fileName);
   
	if (heightFile.GetFileByteSize() > 0)
    {
        heightFile.Read(sizeof(unsigned short), numHeights, heights);
        
    }
    else
    {
        memset(heights, 0, numHeights*sizeof(unsigned short));
    }

  const  float length = mSpacing*(float)(mSize - 1);
   Mathematics::  Float2 origin(col*length, row*length);
   TerrainPageSharedPtr page(std::make_shared<TerrainPage>(mVFormat, mSize, heights, origin, mMinElevation, mMaxElevation, mSpacing));

    mPages[row][col] = page;
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase
	::ReplacePage(int row, int col, const System::String& heightName, const System::String& heightSuffix)
{
    if (0 <= row && row < mNumRows && 0 <= col && col < mNumCols)
    {
		TerrainPageSharedPtr save = mPages[row][col];
        LoadPage(row, col, heightName, heightSuffix);
        return save;
    }

    RENDERING_ASSERTION_0(false, "Invalid row or column index\n");
	return TerrainPageSharedPtr();
}

Rendering::TerrainPageSharedPtr Rendering::TerrainBase
	::ReplacePage(int row, int col, TerrainPageSharedPtr newPage)
{
    if (0 <= row && row < mNumRows && 0 <= col && col < mNumCols)
    {
		TerrainPageSharedPtr save = mPages[row][col];
        mPages[row][col] = newPage;
        return save;
    }

    RENDERING_ASSERTION_0(false, "Invalid row or column index\n");
	return TerrainPageSharedPtr();
}

void Rendering::TerrainBase
	::OnCameraMotion ()
{
    RENDERING_ASSERTION_0(mCamera != 0, "Camera must exist\n");
    if (!mCamera )
    {
        return;
    }

    // Get camera location/direction in model space of terrain.
   Mathematics:: FloatAPoint worldEye = mCamera->GetPosition();
   Mathematics::FloatAVector worldDir = mCamera->GetDirectionVector();
   Mathematics::FloatAPoint modelEye = GetWorldTransform().GetInverseMatrix()*worldEye;
   Mathematics::FloatAVector modelDir = GetWorldTransform().GetInverseMatrix()*worldDir;

    // Update the model-space origins of the terrain pages.  Start the
    // process by locating the page that contains the camera.
   const float length = mSpacing*(float)(mSize - 1);
   const float invLength = 1.0f/length;
	const int newCameraCol = (int)Mathematics::FloatMath::Floor(modelEye[0]*invLength);
	const int newCameraRow = (int)Mathematics::FloatMath::Floor(modelEye[1]*invLength);
    if (newCameraCol != mCameraCol || newCameraRow != mCameraRow)
    {
        mCameraCol = newCameraCol;
        mCameraRow = newCameraRow;

        // Translate page origins for toroidal wraparound.
       const int cminO = mCameraCol - mNumCols/2;
         int cminP = cminO % mNumCols;
        if (cminP < 0)
        {
            cminP += mNumCols;
        }

        const int rminO = mCameraRow - mNumRows/2;
        int rminP = rminO % mNumRows;
        if (rminP < 0)
        {
            rminP += mNumRows;
        }

        int rO = rminO, rP = rminP;
        for (int row = 0; row < mNumRows; ++row)
        {
            int cO = cminO, cP = cminP;
            for (int col = 0; col < mNumCols; ++col)
            {
                TerrainPageSharedPtr page = mPages[rP][cP];
				Mathematics::Float2 oldOrigin = page->GetOrigin();
				Mathematics::Float2 newOrigin(cO*length, rO*length);
                                Mathematics::FloatAPoint pageTrn(newOrigin[0] - oldOrigin[0],
                                                                 newOrigin[1] - oldOrigin[1],
											 page->GetLocalTransform().GetTranslate()[2]);
				 
				 page->SetLocalTransformTranslate(pageTrn);

                ++cO;
                if (++cP == mNumCols)
                {
                    cP = 0;
                }
            }

            ++rO;
            if (++rP == mNumRows)
            {
                rP = 0;
            }
        }
        Update();
    }
}



// Name support.

const CoreTools::ObjectSharedPtr Rendering::TerrainBase
	::GetObjectByName(const std::string& name)
{
	CoreTools::ObjectSharedPtr found = ParentType::GetObjectByName(name);
	if (found )
	{
		return found;
	}
	found = mVFormat->GetObjectByName(name);
	if (found )
	{
		return found;
	}
	found = mCamera->GetObjectByName(name);
	if (found )
	{
		return found;
	}
	 
	for (int row = 0; row < mNumRows; ++row)
	{
		for (int col = 0; col < mNumCols; ++col)
		{
			found = mPages[row][col]->GetObjectByName(name);
			if (found )
			{
				return found;
			}
			 
		}
	} 

	return CoreTools::ObjectSharedPtr();
}

const std::vector<CoreTools::ObjectSharedPtr> Rendering::TerrainBase
	::GetAllObjectsByName(const std::string& name)
{
	std::vector<CoreTools::ObjectSharedPtr> objects = ParentType::GetAllObjectsByName(name);

	std::vector<CoreTools::ObjectSharedPtr> pointerObjects = mVFormat->GetAllObjectsByName(name);
	objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	pointerObjects = mCamera->GetAllObjectsByName(name);
	objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

	for (int row = 0; row < mNumRows; ++row)
	{
		for (int col = 0; col < mNumCols; ++col)
		{
			pointerObjects = mPages[row][col]->GetAllObjectsByName(name);
			objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

		}
	}

	return objects;
}

const CoreTools::ConstObjectSharedPtr Rendering::TerrainBase
	::GetConstObjectByName(const std::string& name) const
{
	CoreTools::ConstObjectSharedPtr found = ParentType::GetConstObjectByName(name);
	if (found )
	{
		return found;
	}

	found = mVFormat->GetConstObjectByName(name);
	if (found )
	{
		return found;
	}
	found = mCamera->GetConstObjectByName(name);
	if (found )
	{
		return found;
	}

	for (int row = 0; row < mNumRows; ++row)
	{
		for (int col = 0; col < mNumCols; ++col)
		{
			found = mPages[row][col]->GetConstObjectByName(name);
			if (found )
			{
				return found;
			}

		}
	}

	return CoreTools::ConstObjectSharedPtr();
}

const std::vector<CoreTools::ConstObjectSharedPtr> Rendering::TerrainBase
	::GetAllConstObjectsByName(const std::string& name) const
{
	std::vector<CoreTools::ConstObjectSharedPtr> objects = ParentType::GetAllConstObjectsByName(name);

	std::vector<CoreTools::ConstObjectSharedPtr> pointerObjects = mVFormat->GetAllConstObjectsByName(name);
	objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
	pointerObjects = mCamera->GetAllConstObjectsByName(name);
	objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());

	for (int row = 0; row < mNumRows; ++row)
	{
		for (int col = 0; col < mNumCols; ++col)
		{
			pointerObjects = mPages[row][col]->GetAllConstObjectsByName(name);
			objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
			 
		}
	}

	return objects;
} 
// Streaming support.

Rendering::TerrainBase::TerrainBase (LoadConstructor value)
    :
    Node(value),
    mMode(0),
    mNumRows(0),
    mNumCols(0),
    mSize(0),
    mMinElevation(0.0f),
    mMaxElevation(0.0f),
    mSpacing(0.0f),
    mPages(0),
    mCameraRow(0),
    mCameraCol(0)
{
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TerrainBase::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ObjectInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

void Rendering::TerrainBase
	::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    Node::Load(source);

    source->Read(mMode);
    source->Read(mNumRows);
    source->Read(mNumCols);
    source->Read(mSize);
    source->Read(mMinElevation);
    source->Read(mMaxElevation);
    source->Read(mSpacing);
    source->Read(mCameraRow);
    source->Read(mCameraCol);
  //  source.ReadSharedPtr(mVFormat);
	//source.ReadSharedPtr(mCamera);

	mPages = NEW2<TerrainPageSharedPtr>(mNumCols, mNumRows);
    for (int row = 0; row < mNumRows; ++row)
    {
        for (int col = 0; col < mNumCols; ++col)
        {
			//source.ReadSharedPtr(mPages[row][col]);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::TerrainBase
	::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    Node::Link(source);

   // source.ResolveObjectSharedPtrLink(mVFormat);
	//source.ResolveObjectSharedPtrLink(mCamera);
    for (int row = 0; row < mNumRows; ++row)
    {
        for (int col = 0; col < mNumCols; ++col)
        {
			//source.ResolveObjectSharedPtrLink(mPages[row][col]);
        }
    }
}

void Rendering::TerrainBase
	::PostLink ()
{
    Node::PostLink();
}

uint64_t Rendering::TerrainBase
	::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
	const uint64_t id = Node::Register(target);
	if (0 < id)
    {
       // target.RegisterSharedPtr(mVFormat);
		//target.RegisterSharedPtr(mCamera);
        for (int row = 0; row < mNumRows; ++row)
        {
            for (int col = 0; col < mNumCols; ++col)
            {
				//target.RegisterSharedPtr(mPages[row][col]);
            }
        }
		return id;
    }
	return id;
}

void Rendering::TerrainBase
	::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    Node::Save(target);

    target->Write(mMode);
    target->Write(mNumRows);
    target->Write(mNumCols);
    target->Write(mSize);
    target->Write(mMinElevation);
    target->Write(mMaxElevation);
    target->Write(mSpacing);
    target->Write(mCameraRow);
    target->Write(mCameraCol);
   // target.WriteSharedPtr(mVFormat);
	//target.WriteSharedPtr(mCamera);

    for (int row = 0; row < mNumRows; ++row)
    {
        for (int col = 0; col < mNumCols; ++col)
        {
			//target.WriteSharedPtr(mPages[row][col]);
        }
    }

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::TerrainBase
	::GetStreamingSize () const
{
    int size = Node::GetStreamingSize();
	size += CORE_TOOLS_STREAM_SIZE(mMode);
    size += sizeof(mNumRows);
    size += sizeof(mNumCols);
    size += sizeof(mSize);
    size += sizeof(mMinElevation);
    size += sizeof(mMaxElevation);
    size += sizeof(mSpacing);
    size += sizeof(mCameraRow);
    size += sizeof(mCameraCol);
	size += CORE_TOOLS_STREAM_SIZE(mVFormat);
	size += CORE_TOOLS_STREAM_SIZE(mCamera);
	size += mNumRows*mNumCols*CORE_TOOLS_STREAM_SIZE(mPages[0][0]);
    return size;
}


 int Rendering::TerrainBase
	 ::GetRowQuantity () const noexcept
{
	return mNumRows;
}

 int Rendering::TerrainBase
	 ::GetColQuantity () const noexcept
{
	return mNumCols;
}

 int Rendering::TerrainBase
	 ::GetSize () const noexcept
{
	return mSize;
}

 float Rendering::TerrainBase
	 ::GetMinElevation () const noexcept
{
	return mMinElevation;
}

 float Rendering::TerrainBase
	 ::GetMaxElevation () const noexcept
{
	return mMaxElevation;
}

 float Rendering::TerrainBase
	 ::GetSpacing () const noexcept
{
	return mSpacing;
}

 #include STSTEM_WARNING_POP