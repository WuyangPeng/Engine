// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:18)

#include "AssistTools/AssistToolsExport.h"

#include "FxCompiler.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "System/Helper/PragmaWarning/Disable4996.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"

#include <fstream>
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26493)
#include SYSTEM_WARNING_DISABLE(26409)
const std::string AssistTools::FxCompiler
	::msVProfileName[Rendering::ShaderFlags::MaxProfiles] =
{
    "",
    "vs_1_1",
    "vs_2_0",
    "vs_3_0",
    "arbvp1"
};

const std::string AssistTools::FxCompiler
	::msPProfileName[Rendering::ShaderFlags::MaxProfiles] =
{
    "",
    "ps_1_1",
    "ps_2_0",
    "ps_3_0",
    "arbfp1"
};

const std::string AssistTools::FxCompiler
	::msVTName[System::EnumCastUnderlying(Rendering::ShaderFlags::VariableType::Quantity)] =
{
    "VT_NONE",

    "VT_FLOAT",
    "VT_FLOAT1",   "VT_FLOAT2",   "VT_FLOAT3",   "VT_FLOAT4",
    "VT_FLOAT1X1", "VT_FLOAT1X2", "VT_FLOAT1X3", "VT_FLOAT1X4",
    "VT_FLOAT2X1", "VT_FLOAT2X2", "VT_FLOAT2X3", "VT_FLOAT2X4",
    "VT_FLOAT3X1", "VT_FLOAT3X2", "VT_FLOAT3X3", "VT_FLOAT3X4",
    "VT_FLOAT4X1", "VT_FLOAT4X2", "VT_FLOAT4X3", "VT_FLOAT4X4",

    "VT_HALF",
    "VT_HALF1",    "VT_HALF2",    "VT_HALF3",    "VT_HALF4",
    "VT_HALF1X1",  "VT_HALF1X2",  "VT_HALF1X3",  "VT_HALF1X4",
    "VT_HALF2X1",  "VT_HALF2X2",  "VT_HALF2X3",  "VT_HALF2X4",
    "VT_HALF3X1",  "VT_HALF3X2",  "VT_HALF3X3",  "VT_HALF3X4",
    "VT_HALF4X1",  "VT_HALF4X2",  "VT_HALF4X3",  "VT_HALF4X4",

    "VT_INT",
    "VT_INT1",     "VT_INT2",     "VT_INT3",     "VT_INT4",
    "VT_INT1X1",   "VT_INT1X2",   "VT_INT1X3",   "VT_INT1X4",
    "VT_INT2X1",   "VT_INT2X2",   "VT_INT2X3",   "VT_INT2X4",
    "VT_INT3X1",   "VT_INT3X2",   "VT_INT3X3",   "VT_INT3X4",
    "VT_INT4X1",   "VT_INT4X2",   "VT_INT4X3",   "VT_INT4X4",

    "VT_FIXED",
    "VT_FIXED1",   "VT_FIXED2",   "VT_FIXED3",   "VT_FIXED4",
    "VT_FIXED1X1", "VT_FIXED1X2", "VT_FIXED1X3", "VT_FIXED1X4",
    "VT_FIXED2X1", "VT_FIXED2X2", "VT_FIXED2X3", "VT_FIXED2X4",
    "VT_FIXED3X1", "VT_FIXED3X2", "VT_FIXED3X3", "VT_FIXED3X4",
    "VT_FIXED4X1", "VT_FIXED4X2", "VT_FIXED4X3", "VT_FIXED4X4",

    "VT_BOOL",
    "VT_BOOL1",    "VT_BOOL2",    "VT_BOOL3",    "VT_BOOL4",
    "VT_BOOL1X1",  "VT_BOOL1X2",  "VT_BOOL1X3",  "VT_BOOL1X4",
    "VT_BOOL2X1",  "VT_BOOL2X2",  "VT_BOOL2X3",  "VT_BOOL2X4",
    "VT_BOOL3X1",  "VT_BOOL3X2",  "VT_BOOL3X3",  "VT_BOOL3X4",
    "VT_BOOL4X1",  "VT_BOOL4X2",  "VT_BOOL4X3",  "VT_BOOL4X4"
};

const std::string AssistTools::FxCompiler
	::msVSName[System::EnumCastUnderlying(Rendering::ShaderFlags::VariableSemantic::Quantity)] =
{
    "VS_NONE",
    "VS_POSITION",
    "VS_BLENDWEIGHT",
    "VS_NORMAL",
    "VS_COLOR0",
    "VS_COLOR1", 
    "VS_FOGCOORD",
    "VS_PSIZE",
    "VS_BLENDINDICES",
    "VS_TEXCOORD0",
    "VS_TEXCOORD1",
    "VS_TEXCOORD2",
    "VS_TEXCOORD3",
    "VS_TEXCOORD4",
    "VS_TEXCOORD5",
    "VS_TEXCOORD6",
    "VS_TEXCOORD7",
    "VS_FOG",
    "VS_TANGENT",
    "VS_BINORMAL",
    "VS_COLOR2",
    "VS_COLOR3",
    "VS_DEPTH0"
};

const std::string AssistTools::FxCompiler
	::msSTName[System::EnumCastUnderlying(Rendering::ShaderFlags::SamplerType::Quantity)] =
{
    "ST_NONE",
    "ST_1D",
    "ST_2D",
    "ST_3D",
    "ST_CUBE"
};

AssistTools::FxCompiler
	::FxCompiler(const std::string& fxName, bool alreadyCompiled)
    :mActiveProfile(0),
     mEffect(0),
     mAlreadyCompiled(alreadyCompiled)
{
    if (!mAlreadyCompiled)
    {
        // Use a command interpreter to compile the shaders using the Cg
        // compiler.
        bool compileSucceeded = false;
        std::string command;
        int i;
		for (i = 1; i < Rendering::ShaderFlags::MaxProfiles; ++i)
        {
            // Delete the old vertex shader output (if it exists).
            command = "del " + fxName + "." + msVProfileName[i] + ".txt";
            system(command.c_str());

            // Compile the vertex shader.
            command = "cgc -profile " + msVProfileName[i];
            if (i == 1)
            {
                // VS_1_1 requires profile options for DX9 not to barf when
                // trying to assemble the program.
                command += " -profileopts dcls";
            }
            command += " -entry v_" + fxName + " -o " + fxName + ".";
            command += msVProfileName[i] + ".txt " + fxName + ".fx";
            const int cgVStatus = system(command.c_str());

            // Delete the old pixel shader output (if it exists).
            command = "del " + fxName + "." + msPProfileName[i] + ".txt";
            system(command.c_str());

            // Compile the pixel shader.
            command = "cgc -profile " + msPProfileName[i];
            command += " -entry p_" + fxName + " -o " + fxName + ".";
            command += msPProfileName[i] + ".txt " + fxName + ".fx";
            const int cgPStatus = system(command.c_str());

            if (cgVStatus == 0 && cgPStatus == 0)
            {
                // At least one profile compiled.
                compileSucceeded = true;
                Messages.push_back("The profile pair " + msVProfileName[i] +
                    " and " + msPProfileName[i] + " compiled.\n");
            }
            else
            {
                // Delete the output file when only one of the shaders
                // compiled.
                if (cgVStatus == 0)
                {
                    // The vertex shader compiled but the pixel shader did
                    // not.
                    command = "del " + fxName + "." + msVProfileName[i] +
                        ".txt";
                    system(command.c_str());
                }
                else
                {
                    Messages.push_back("Profile " + msVProfileName[i] +
                        " did not compile.\n");
                }

                if (cgPStatus == 0)
                {
                    // The pixel shader compiled but the vertex shader did
                    // not.
                    command = "del " + fxName + "." + msPProfileName[i];
                    command += ".txt";
                    system(command.c_str());
                }
                else
                {
                    Messages.push_back("Profile " + msPProfileName[i] +
                        " did not compile.\n");
                }
                Messages.push_back("The profile pair " + msVProfileName[i] +
                    " and " + msPProfileName[i] + " did not compile.\n");
            }
        }

        if (!compileSucceeded)
        {
            Messages.push_back("All profiles failed to compile.\n");
            return;
        }
    }

    InitializeMaps();

	Program vProgram[Rendering::ShaderFlags::MaxProfiles];
	Program pProgram[Rendering::ShaderFlags::MaxProfiles];
	for (int i = 1; i < Rendering::ShaderFlags::MaxProfiles; ++i)
    {
        mActiveProfile = i;

        std::string inVName = fxName + "." + msVProfileName[i] + ".txt";
        const bool hasVProfile = Parse(inVName, msVProfileName[i], vProgram[i]);

        std::string inPName = fxName + "." + msPProfileName[i] + ".txt";
        const bool hasPProfile = Parse(inPName, msPProfileName[i], pProgram[i]);

        if (hasVProfile && hasPProfile)
        {
            if (mEffect == 0)
            {
                if (!CreateEffect(vProgram[i], pProgram[i]))
                {
                    return;
                }
            }
            else
            {
                if (!UpdateEffect(vProgram[i], pProgram[i]))
                {
                    return;
                }
            }
        }
    }

    if (mEffect)
    {
		CoreTools::WriteFileManager writeFileManager(CoreTools::StringConversion::MultiByteConversionStandard(fxName + ".wmfx"));
		mEffect->SaveVisualTechnique(writeFileManager);
    }
}

AssistTools::FxCompiler
	::~FxCompiler()   noexcept
{

#include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26447)
    DELETE0(mEffect);
    #include STSTEM_WARNING_POP
}

void AssistTools::FxCompiler
	::InitializeMaps()
{
	mVariableTypes.insert(std::make_pair("float", Rendering::ShaderFlags::VariableType::Float));
	mVariableTypes.insert(std::make_pair("float1", Rendering::ShaderFlags::VariableType::Float1));
	mVariableTypes.insert(std::make_pair("float2", Rendering::ShaderFlags::VariableType::Float2));
	mVariableTypes.insert(std::make_pair("float3", Rendering::ShaderFlags::VariableType::Float3));
	mVariableTypes.insert(std::make_pair("float4", Rendering::ShaderFlags::VariableType::Float4));
	mVariableTypes.insert(std::make_pair("float1x1", Rendering::ShaderFlags::VariableType::Float1X1));
	mVariableTypes.insert(std::make_pair("float1x2", Rendering::ShaderFlags::VariableType::Float1X2));
	mVariableTypes.insert(std::make_pair("float1x3", Rendering::ShaderFlags::VariableType::Float1X3));
	mVariableTypes.insert(std::make_pair("float1x4", Rendering::ShaderFlags::VariableType::Float1X4));
	mVariableTypes.insert(std::make_pair("float2x1", Rendering::ShaderFlags::VariableType::Float2X1));
	mVariableTypes.insert(std::make_pair("float2x2", Rendering::ShaderFlags::VariableType::Float2X2));
	mVariableTypes.insert(std::make_pair("float2x3", Rendering::ShaderFlags::VariableType::Float2X3));
	mVariableTypes.insert(std::make_pair("float2x4", Rendering::ShaderFlags::VariableType::Float2X4));
	mVariableTypes.insert(std::make_pair("float3x1", Rendering::ShaderFlags::VariableType::Float3X1));
	mVariableTypes.insert(std::make_pair("float3x2", Rendering::ShaderFlags::VariableType::Float3X2));
	mVariableTypes.insert(std::make_pair("float3x3", Rendering::ShaderFlags::VariableType::Float3X3));
	mVariableTypes.insert(std::make_pair("float3x4", Rendering::ShaderFlags::VariableType::Float3X4));
	mVariableTypes.insert(std::make_pair("float4x1", Rendering::ShaderFlags::VariableType::Float4X1));
	mVariableTypes.insert(std::make_pair("float4x2", Rendering::ShaderFlags::VariableType::Float4X2));
	mVariableTypes.insert(std::make_pair("float4x3", Rendering::ShaderFlags::VariableType::Float4X3));
	mVariableTypes.insert(std::make_pair("float4x4", Rendering::ShaderFlags::VariableType::Float4X4));

	mVariableTypes.insert(std::make_pair("half", Rendering::ShaderFlags::VariableType::Half));
	mVariableTypes.insert(std::make_pair("half1", Rendering::ShaderFlags::VariableType::Half1));
	mVariableTypes.insert(std::make_pair("half2", Rendering::ShaderFlags::VariableType::Half2));
	mVariableTypes.insert(std::make_pair("half3", Rendering::ShaderFlags::VariableType::Half3));
	mVariableTypes.insert(std::make_pair("half4", Rendering::ShaderFlags::VariableType::Half4));
	mVariableTypes.insert(std::make_pair("half1x1", Rendering::ShaderFlags::VariableType::Half1X1));
	mVariableTypes.insert(std::make_pair("half1x2", Rendering::ShaderFlags::VariableType::Half1X2));
	mVariableTypes.insert(std::make_pair("half1x3", Rendering::ShaderFlags::VariableType::Half1X3));
	mVariableTypes.insert(std::make_pair("half1x4", Rendering::ShaderFlags::VariableType::Half1X4));
	mVariableTypes.insert(std::make_pair("half2x1", Rendering::ShaderFlags::VariableType::Half2X1));
	mVariableTypes.insert(std::make_pair("half2x2", Rendering::ShaderFlags::VariableType::Half2X2));
	mVariableTypes.insert(std::make_pair("half2x3", Rendering::ShaderFlags::VariableType::Half2X3));
	mVariableTypes.insert(std::make_pair("half2x4", Rendering::ShaderFlags::VariableType::Half2X4));
	mVariableTypes.insert(std::make_pair("half3x1", Rendering::ShaderFlags::VariableType::Half3X1));
	mVariableTypes.insert(std::make_pair("half3x2", Rendering::ShaderFlags::VariableType::Half3X2));
	mVariableTypes.insert(std::make_pair("half3x3", Rendering::ShaderFlags::VariableType::Half3X3));
	mVariableTypes.insert(std::make_pair("half3x4", Rendering::ShaderFlags::VariableType::Half3X4));
	mVariableTypes.insert(std::make_pair("half4x1", Rendering::ShaderFlags::VariableType::Half4X1));
	mVariableTypes.insert(std::make_pair("half4x2", Rendering::ShaderFlags::VariableType::Half4X2));
	mVariableTypes.insert(std::make_pair("half4x3", Rendering::ShaderFlags::VariableType::Half4X3));
	mVariableTypes.insert(std::make_pair("half4x4", Rendering::ShaderFlags::VariableType::Half4X4));

	mVariableTypes.insert(std::make_pair("int", Rendering::ShaderFlags::VariableType::Int));
	mVariableTypes.insert(std::make_pair("int1", Rendering::ShaderFlags::VariableType::Int1));
	mVariableTypes.insert(std::make_pair("int2", Rendering::ShaderFlags::VariableType::Int2));
	mVariableTypes.insert(std::make_pair("int3", Rendering::ShaderFlags::VariableType::Int3));
	mVariableTypes.insert(std::make_pair("int4", Rendering::ShaderFlags::VariableType::Int4));
	mVariableTypes.insert(std::make_pair("int1x1", Rendering::ShaderFlags::VariableType::Int1X1));
	mVariableTypes.insert(std::make_pair("int1x2", Rendering::ShaderFlags::VariableType::Int1X2));
	mVariableTypes.insert(std::make_pair("int1x3", Rendering::ShaderFlags::VariableType::Int1X3));
	mVariableTypes.insert(std::make_pair("int1x4", Rendering::ShaderFlags::VariableType::Int1X4));
	mVariableTypes.insert(std::make_pair("int2x1", Rendering::ShaderFlags::VariableType::Int2X1));
	mVariableTypes.insert(std::make_pair("int2x2", Rendering::ShaderFlags::VariableType::Int2X2));
	mVariableTypes.insert(std::make_pair("int2x3", Rendering::ShaderFlags::VariableType::Int2X3));
	mVariableTypes.insert(std::make_pair("int2x4", Rendering::ShaderFlags::VariableType::Int2X4));
	mVariableTypes.insert(std::make_pair("int3x1", Rendering::ShaderFlags::VariableType::Int3X1));
	mVariableTypes.insert(std::make_pair("int3x2", Rendering::ShaderFlags::VariableType::Int3X2));
	mVariableTypes.insert(std::make_pair("int3x3", Rendering::ShaderFlags::VariableType::Int3X3));
	mVariableTypes.insert(std::make_pair("int3x4", Rendering::ShaderFlags::VariableType::Int3X4));
	mVariableTypes.insert(std::make_pair("int4x1", Rendering::ShaderFlags::VariableType::Int4X1));
	mVariableTypes.insert(std::make_pair("int4x2", Rendering::ShaderFlags::VariableType::Int4X2));
	mVariableTypes.insert(std::make_pair("int4x3", Rendering::ShaderFlags::VariableType::Int4X3));
	mVariableTypes.insert(std::make_pair("int4x4", Rendering::ShaderFlags::VariableType::Int4X4));

	mVariableTypes.insert(std::make_pair("fixed", Rendering::ShaderFlags::VariableType::Fixed));
	mVariableTypes.insert(std::make_pair("fixed1", Rendering::ShaderFlags::VariableType::Fixed1));
	mVariableTypes.insert(std::make_pair("fixed2", Rendering::ShaderFlags::VariableType::Fixed2));
	mVariableTypes.insert(std::make_pair("fixed3", Rendering::ShaderFlags::VariableType::Fixed3));
	mVariableTypes.insert(std::make_pair("fixed4", Rendering::ShaderFlags::VariableType::Fixed4));
	mVariableTypes.insert(std::make_pair("fixed1x1", Rendering::ShaderFlags::VariableType::Fixed1X1));
	mVariableTypes.insert(std::make_pair("fixed1x2", Rendering::ShaderFlags::VariableType::Fixed1X2));
	mVariableTypes.insert(std::make_pair("fixed1x3", Rendering::ShaderFlags::VariableType::Fixed1X3));
	mVariableTypes.insert(std::make_pair("fixed1x4", Rendering::ShaderFlags::VariableType::Fixed1X4));
	mVariableTypes.insert(std::make_pair("fixed2x1", Rendering::ShaderFlags::VariableType::Fixed2X1));
	mVariableTypes.insert(std::make_pair("fixed2x2", Rendering::ShaderFlags::VariableType::Fixed2X2));
	mVariableTypes.insert(std::make_pair("fixed2x3", Rendering::ShaderFlags::VariableType::Fixed2X3));
	mVariableTypes.insert(std::make_pair("fixed2x4", Rendering::ShaderFlags::VariableType::Fixed2X4));
	mVariableTypes.insert(std::make_pair("fixed3x1", Rendering::ShaderFlags::VariableType::Fixed3X1));
	mVariableTypes.insert(std::make_pair("fixed3x2", Rendering::ShaderFlags::VariableType::Fixed3X2));
	mVariableTypes.insert(std::make_pair("fixed3x3", Rendering::ShaderFlags::VariableType::Fixed3X3));
	mVariableTypes.insert(std::make_pair("fixed3x4", Rendering::ShaderFlags::VariableType::Fixed3X4));
	mVariableTypes.insert(std::make_pair("fixed4x1", Rendering::ShaderFlags::VariableType::Fixed4X1));
	mVariableTypes.insert(std::make_pair("fixed4x2", Rendering::ShaderFlags::VariableType::Fixed4X2));
	mVariableTypes.insert(std::make_pair("fixed4x3", Rendering::ShaderFlags::VariableType::Fixed4X3));
	mVariableTypes.insert(std::make_pair("fixed4x4", Rendering::ShaderFlags::VariableType::Fixed4X4));

	mVariableTypes.insert(std::make_pair("bool", Rendering::ShaderFlags::VariableType::Bool));
	mVariableTypes.insert(std::make_pair("bool1", Rendering::ShaderFlags::VariableType::Bool1));
	mVariableTypes.insert(std::make_pair("bool2", Rendering::ShaderFlags::VariableType::Bool2));
	mVariableTypes.insert(std::make_pair("bool3", Rendering::ShaderFlags::VariableType::Bool3));
	mVariableTypes.insert(std::make_pair("bool4", Rendering::ShaderFlags::VariableType::Bool4));
	mVariableTypes.insert(std::make_pair("bool1x1", Rendering::ShaderFlags::VariableType::Bool1X1));
	mVariableTypes.insert(std::make_pair("bool1x2", Rendering::ShaderFlags::VariableType::Bool1X2));
	mVariableTypes.insert(std::make_pair("bool1x3", Rendering::ShaderFlags::VariableType::Bool1X3));
	mVariableTypes.insert(std::make_pair("bool1x4", Rendering::ShaderFlags::VariableType::Bool1X4));
	mVariableTypes.insert(std::make_pair("bool2x1", Rendering::ShaderFlags::VariableType::Bool2X1));
	mVariableTypes.insert(std::make_pair("bool2x2", Rendering::ShaderFlags::VariableType::Bool2X2));
	mVariableTypes.insert(std::make_pair("bool2x3", Rendering::ShaderFlags::VariableType::Bool2X3));
	mVariableTypes.insert(std::make_pair("bool2x4", Rendering::ShaderFlags::VariableType::Bool2X4));
	mVariableTypes.insert(std::make_pair("bool3x1", Rendering::ShaderFlags::VariableType::Bool3X1));
	mVariableTypes.insert(std::make_pair("bool3x2", Rendering::ShaderFlags::VariableType::Bool3X2));
	mVariableTypes.insert(std::make_pair("bool3x3", Rendering::ShaderFlags::VariableType::Bool3X3));
	mVariableTypes.insert(std::make_pair("bool3x4", Rendering::ShaderFlags::VariableType::Bool3X4));
	mVariableTypes.insert(std::make_pair("bool4x1", Rendering::ShaderFlags::VariableType::Bool4X1));
	mVariableTypes.insert(std::make_pair("bool4x2", Rendering::ShaderFlags::VariableType::Bool4X2));
	mVariableTypes.insert(std::make_pair("bool4x3", Rendering::ShaderFlags::VariableType::Bool4X3));
	mVariableTypes.insert(std::make_pair("bool4x4", Rendering::ShaderFlags::VariableType::Bool4X4));

	mSemantics.insert(std::make_pair("POSITION", Rendering::ShaderFlags::VariableSemantic::Position));
	mSemantics.insert(std::make_pair("POSITION0", Rendering::ShaderFlags::VariableSemantic::Position));
	mSemantics.insert(std::make_pair("BLENDWEIGHT", Rendering::ShaderFlags::VariableSemantic::BlendWeight));
	mSemantics.insert(std::make_pair("NORMAL", Rendering::ShaderFlags::VariableSemantic::Normal));
	mSemantics.insert(std::make_pair("NORMAL0", Rendering::ShaderFlags::VariableSemantic::Normal));
	mSemantics.insert(std::make_pair("COLOR", Rendering::ShaderFlags::VariableSemantic::Color0));
	mSemantics.insert(std::make_pair("COLOR0", Rendering::ShaderFlags::VariableSemantic::Color0));
	mSemantics.insert(std::make_pair("COLOR1", Rendering::ShaderFlags::VariableSemantic::Color1));
	mSemantics.insert(std::make_pair("FOGCOORD", Rendering::ShaderFlags::VariableSemantic::FogCoord));
	mSemantics.insert(std::make_pair("PSIZE", Rendering::ShaderFlags::VariableSemantic::PSize));
	mSemantics.insert(std::make_pair("BLENDINDICES", Rendering::ShaderFlags::VariableSemantic::BlendIndices));
	mSemantics.insert(std::make_pair("TEXCOORD0", Rendering::ShaderFlags::VariableSemantic::TextureCoord0));
	mSemantics.insert(std::make_pair("TEXCOORD1", Rendering::ShaderFlags::VariableSemantic::TextureCoord1));
	mSemantics.insert(std::make_pair("TEXCOORD2", Rendering::ShaderFlags::VariableSemantic::TextureCoord2));
	mSemantics.insert(std::make_pair("TEXCOORD3", Rendering::ShaderFlags::VariableSemantic::TextureCoord3));
	mSemantics.insert(std::make_pair("TEXCOORD4", Rendering::ShaderFlags::VariableSemantic::TextureCoord4));
	mSemantics.insert(std::make_pair("TEXCOORD5", Rendering::ShaderFlags::VariableSemantic::TextureCoord5));
	mSemantics.insert(std::make_pair("TEXCOORD6", Rendering::ShaderFlags::VariableSemantic::TextureCoord6));
	mSemantics.insert(std::make_pair("TEXCOORD7", Rendering::ShaderFlags::VariableSemantic::TextureCoord7));
	mSemantics.insert(std::make_pair("FOG", Rendering::ShaderFlags::VariableSemantic::Fog));
	mSemantics.insert(std::make_pair("TANGENT", Rendering::ShaderFlags::VariableSemantic::Tangent));
	mSemantics.insert(std::make_pair("BINORMAL", Rendering::ShaderFlags::VariableSemantic::Binormal));
	mSemantics.insert(std::make_pair("COLOR2", Rendering::ShaderFlags::VariableSemantic::Color2));
	mSemantics.insert(std::make_pair("COLOR3", Rendering::ShaderFlags::VariableSemantic::Color3));
	mSemantics.insert(std::make_pair("DEPTH0", Rendering::ShaderFlags::VariableSemantic::Depth0));

	mSamplerTypes.insert(std::make_pair("sampler1D", Rendering::ShaderFlags::SamplerType::Sampler1D));
	mSamplerTypes.insert(std::make_pair("sampler2D", Rendering::ShaderFlags::SamplerType::Sampler2D));
	mSamplerTypes.insert(std::make_pair("samplerSHADOW", Rendering::ShaderFlags::SamplerType::Sampler2D));
	mSamplerTypes.insert(std::make_pair("sampler3D", Rendering::ShaderFlags::SamplerType::Sampler3D));
	mSamplerTypes.insert(std::make_pair("samplerCUBE", Rendering::ShaderFlags::SamplerType::SamplerCube));
}

bool AssistTools::FxCompiler
	::Parse(const std::string& fileName, const std::string& profileName, Program& program)
{
    std::ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        // If the file does not exist, the assumption is that the profile does
        // not support the shader (in which case, the Cg compiler failed).
        Messages.push_back("Profile " + profileName + " not supported.\n");
        return false;
    }

    program.Text = "";

    while (!inFile.eof())
    {
        std::string line;
        getline(inFile, line);
        if (line.empty())
        {
            continue;
        }

        // Any uncommented lines are part of the program text.
        if (line[0] != '/' && line[0] != '#')
        {
            program.Text += line + "\n";
            continue;
        }

        std::vector<std::string> tokens;
        std::string::size_type begin;

        // Get a variable line from the Cg output file.
        begin = line.find("var", 0);
        if (begin != std::string::npos)
        {
            GetTokens(line, begin, tokens);
            if (tokens.size() >= 2 && tokens[0] == "var")
            {
                std::string used = tokens.back();
                if (used == "0" || used == "1")
                {
                    if (used == "1")
                    {
                        program.Variables.push_back(tokens);
                    }
                    continue;
                }
            }
            inFile.close();
            ReportError("Invalid variable line", &tokens);
            return false;
        }

        // Get the profile name.
        begin = line.find("profile", 0);
        if (begin != std::string::npos)
        {
            GetTokens(line, begin, tokens);
            if (tokens.size() >= 2 && tokens[0] == "profile")
            {
                // When the user has already compiled the programs, it is
                // because a profile is a special one.  The "!!ARBfp1.0"
                // string and the last token of "#profile specialProfile"
                // most likely do not match, so do not compare them.
                if (mAlreadyCompiled || tokens[1] == profileName)
                {
                    continue;
                }
            }
            inFile.close();
            ReportError("Invalid profile line", &tokens);
            return false;
        }

        // Get the program name.
        begin = line.find("program", 0);
        if (begin != std::string::npos)
        {
            GetTokens(line, begin, tokens);
            if (tokens.size() >= 2 && tokens[0] == "program")
            {
                program.Name = tokens[1];
                continue;
            }
            inFile.close();
            ReportError("Invalid program line", &tokens);
            return false;
        }
    }

    inFile.close();
    return true;
}

void AssistTools::FxCompiler
	::GetTokens(const std::string& line,std::string::size_type begin, std::vector<std::string>& tokens)
{
    while (begin != std::string::npos)
    {
        // Skip over the token.
       const  std::string::size_type end = line.find(" ", begin);

        // Extract the token.
        std::string token = line.substr(begin, end - begin);
        tokens.push_back(token);

        // Skip over white space.
        begin = line.find_first_not_of(" ", end);
    }
}

bool AssistTools::FxCompiler
	::CreateEffect(const Program& vProgram, const Program& pProgram)
{
    InputArray vInputs, pInputs;
    OutputArray vOutputs, pOutputs;
    ConstantArray vConstants, pConstants;
    SamplerArray vSamplers, pSamplers;

    if (!Process(vProgram, vInputs, vOutputs, vConstants, vSamplers))
    {
        return false;
    }

    if (!Process(pProgram, pInputs, pOutputs, pConstants, pSamplers))
    {
        return false;
    }

	mVShader = boost::polymorphic_pointer_cast<Rendering::VertexShader>(CreateShader(true, vProgram, vInputs, vOutputs,
		vConstants, vSamplers));

	mPShader =  boost::polymorphic_pointer_cast<Rendering::PixelShader>(CreateShader(false, pProgram, pInputs, pOutputs,
		pConstants, pSamplers));

	Rendering::VisualPassSmartPointer pass(NEW0 Rendering::VisualPass());
    pass->SetVertexShader(mVShader);
    pass->SetPixelShader(mPShader);

    // TODO.  Once Cg FX files are parsed, the global state from each pass
    // should be set here.  For now, the application is responsible for
    // setting the global state after the *.wmfx file is loaded.
	pass->SetAlphaState(Rendering::AlphaStateSmartPointer(NEW0 Rendering::AlphaState()));
	pass->SetCullState(Rendering::CullStateSmartPointer(NEW0 Rendering::CullState()));
	pass->SetDepthState(Rendering::DepthStateSmartPointer(NEW0 Rendering::DepthState()));
	pass->SetOffsetState(Rendering::OffsetStateSmartPointer(NEW0 Rendering::OffsetState()));
	pass->SetStencilState(Rendering::StencilStateSmartPointer(NEW0 Rendering::StencilState()));
	pass->SetWireState(Rendering::WireStateSmartPointer(NEW0 Rendering::WireState()));

    // TODO.  Once Cg FX files are parsed, we might have multiple techniques
    // or multiple passes per technique.
	Rendering::VisualTechniqueSmartPointer technique(NEW0 Rendering::VisualTechnique());
    technique->InsertPass(pass);

	mEffect = NEW0 Rendering::VisualEffect();
    mEffect->InsertTechnique(technique);
    return true;
}

bool AssistTools::FxCompiler
	::UpdateEffect(const Program& vProgram, const Program& pProgram)
{
    InputArray vInputs, pInputs;
    OutputArray vOutputs, pOutputs;
    ConstantArray vConstants, pConstants;
    SamplerArray vSamplers, pSamplers;

    if (!Process(vProgram, vInputs, vOutputs, vConstants, vSamplers))
    {
        return false;
    }

    if (!Process(pProgram, pInputs, pOutputs, pConstants, pSamplers))
    {
        return false;
    }

    if (!UpdateShader(mVShader.get(), vProgram, vInputs, vOutputs, vConstants,vSamplers))
    {
        return false;
    }

    if (!UpdateShader(mPShader.get(), pProgram, pInputs, pOutputs, pConstants,
        pSamplers))
    {
        return false;
    }

    return true;
}

bool AssistTools::FxCompiler
	::Process(const Program& program, InputArray& inputs,
              OutputArray& outputs, ConstantArray& constants, SamplerArray& samplers)
{
    // Variable lines are one of the following:
    //   var TYPE NAME : $vin.SEMANTIC  : inputType           : index : 1
    //   var TYPE NAME : $vout.SEMANTIC : outputType          : index : 1
    //   var TYPE NAME :                : c[REGISTER]         : index : 1
    //   var TYPE NAME :                : c[REGISTER], NUMREG : index : 1
    //   var TYPE NAME :                : texunit UNITNUMBER  : -1    : 1
    // The last field is "used", a value of "0" or "1".  However, the parser
    // stored in 'program' only those variables with a used value "1".  The
    // all-capitals identifiers are needed by the Wild Magic FX system.

    TokenArrays::const_iterator iter = program.Variables.begin();
    const TokenArrays::const_iterator end = program.Variables.end();
    for (/**/; iter != end; ++iter)
    {
        const TokenArray& tokens = *iter;

        // The token array has 10 or 11 tokens.
        if (tokens.size() < 10 || tokens.size() > 11)
        {
            ReportError("Invalid number of tokens", &tokens);
            return false;
        }

        // Get the variable type.
        Rendering::ShaderFlags::VariableType vartype = Rendering::ShaderFlags::VariableType::None;
        Rendering::ShaderFlags::SamplerType samtype = Rendering::ShaderFlags::SamplerType::None;
        std::string::size_type begin = tokens[1].find("sampler", 0);
        if (begin != std::string::npos)
        {
            const SamplerTypeMap::iterator iter2 = mSamplerTypes.find(tokens[1]);
            if (iter2 == mSamplerTypes.end())
            {
                ReportError("Invalid sampler type", &tokens);
                return false;
            }
            samtype = iter2->second;
        }
        else
        {
            const VariableTypeMap::iterator iter2 = mVariableTypes.find(tokens[1]);
            if (iter2 == mVariableTypes.end())
            {
                ReportError("Invalid variable type", &tokens);
                return false;
            }
            vartype = iter2->second;
        }

        // Get the variable name.
        std::string name = tokens[2];

        // Test whether the variable is a singleton or was declared as an
        // array.  If it is an array, we need to determine how many registers
        // it uses.  This requires processing variable lines with the same
        // variable index.
        bool varArray = false;
        begin = name.find("[", 0);
        if (begin != std::string::npos)
        {
            varArray = true;
            name = name.substr(0, begin);  // strip off "[register]"
        }
        else
        {
            varArray = false;
        }

        // Get the separator before the classifier.
        if (tokens[3] != ":")
        {
            ReportError("Expecting separator character at index 3", &tokens);
            return false;
        }

        // Get the classifier.
        begin = tokens[4].find("$vin.", 0);
        if (begin != std::string::npos)
        {
            // The variable is a shader input.
            if (!GetInput(tokens, name, vartype, inputs))
            {
                return false;
            }
            continue;
        }

        begin = tokens[4].find("$vout.", 0);
        if (begin != std::string::npos)
        {
            // The variable is a shader output.
            if (!GetOutput(tokens, name, vartype, outputs))
            {
                return false;
            }
            continue;
        }

        if (tokens[4] == ":")
        {
            begin = tokens[1].find("sampler", 0);
            if (begin != std::string::npos)
            {
                // The variable is a shader sampler.
                if (!GetSampler(tokens, name, samtype, samplers))
                {
                    return false;
                }
            }
            else
            {
                // The variable is a shader constant.
                if (varArray)
                {
                    if (constants.size() > 0 && name == constants.back().Name)
                    {
                        // This is another occurrence of the array variable.
                        // Just increment the register count.
                        ++constants.back().NumRegistersUsed;
                    }
                    else
                    {
                        // Create the constant with the first occurrence of
                        // the array variable.
                        if (!GetConstant(tokens, name, vartype, constants))
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    if (!GetConstant(tokens, name, vartype, constants))
                    {
                        return false;
                    }
                }
            }
            continue;
        }

        ReportError("Failed to find classifier", &tokens);
        return false;
    }

    return true;
}

bool AssistTools::FxCompiler
	::GetInput(const TokenArray& tokens, const std::string& name,
               Rendering::ShaderFlags::VariableType type, InputArray& inputs)
{
    constexpr std::string::size_type begin = 5;  // skip over "$vin."
    std::string semanticName = tokens[4].substr(begin, std::string::npos);
    const SemanticMap::iterator siter = mSemantics.find(semanticName);
    if (siter == mSemantics.end())
    {
        ReportError("Invalid $vin classifier", &tokens);
        return false;
    }

    Input input;
    input.Name = name;
    input.Type = type;
    input.Semantic = siter->second;
    inputs.push_back(input);
    return true;
}

bool AssistTools::FxCompiler
	::GetOutput(const TokenArray& tokens, const std::string& name,
                Rendering::ShaderFlags::VariableType type, OutputArray& outputs)
{
    constexpr std::string::size_type begin = 6;  // skip over "$vout."
    std::string semanticName = tokens[4].substr(begin, std::string::npos);
    const SemanticMap::iterator siter = mSemantics.find(semanticName);
    if (siter == mSemantics.end())
    {
        ReportError("Invalid $vout classifier", &tokens);
        return false;
    }

    Output output;
    output.Name = name;
    output.Type = type;
    output.Semantic = siter->second;
    outputs.push_back(output);
    return true;
}

bool AssistTools::FxCompiler
	::GetConstant(const TokenArray& tokens,
                  const std::string& name, Rendering::ShaderFlags::VariableType type,
				  ConstantArray& constants)
{
    std::string::size_type begin = 0, end = 0;

    if (tokens[5].size() < 4
    ||  tokens[5][0] != 'c'
    ||  tokens[5][1] != '['
    ||  (end = tokens[5].find("]", 0)) == std::string::npos)
    {
        ReportError("Expecting 'c[register]' token", &tokens);
        return false;
    }

    // Get the base register for the constant.
    begin = 2; // character after '['
    std::string number = tokens[5].substr(begin, end - begin);
    const int baseRegister = atoi(number.c_str());
    if (baseRegister == 0 && number != "0")
    {
        ReportError("Invalid base register", &tokens);
        return false;
    }

    // Get the number of registers used by the constant.
    int numRegistersUsed = 0;
    if (tokens[5].find(",", 0) == std::string::npos)
    {
        // The constant uses one register.
        numRegistersUsed = 1;
    }
    else
    {
        // The constant uses more than one register.
        numRegistersUsed = atoi(tokens[6].c_str());
        if (numRegistersUsed == 0)
        {
            ReportError("Invalid number of registers", &tokens);
            return false;
        }
    }

    Constant constant;
    constant.Name = name;
    constant.Type = type;
    constant.BaseRegister = baseRegister;
    constant.NumRegistersUsed = numRegistersUsed;
    constants.push_back(constant);
    return true;
}

bool AssistTools::FxCompiler
	::GetSampler(const TokenArray& tokens,
                 const std::string& name, Rendering::ShaderFlags::SamplerType type, SamplerArray& samplers)
{
    int unit = 0;

    if (mActiveProfile != 1)
    {
        if (tokens[5] != "texunit")
        {
            ReportError("Expecting 'texunit' token", &tokens);
            return false;
        }

        // Get the texture unit for the sampler.
        unit = atoi(tokens[6].c_str());
        if (unit == 0 && tokens[6] != "0")
        {
            ReportError("Invalid texture unit", &tokens);
            return false;
        }
    }
    else  // ps_1_1 (vs_1_1 does not support textures)
    {
        // Get the texture unit for the sampler.
        unit = atoi(tokens[5].c_str());
        if (unit == 0 && tokens[5] != "0")
        {
            ReportError("Invalid texture unit", &tokens);
            return false;
        }
    }

    Sampler sampler;
    sampler.Name = name;
    sampler.Type = type;
    sampler.Unit = unit;
    sampler.Filter = Rendering::ShaderFlags::SamplerFilter::Nearest;
    sampler.Coordinate[0] = Rendering::ShaderFlags::SamplerCoordinate::ClampEdge;
    sampler.Coordinate[1] = Rendering::ShaderFlags::SamplerCoordinate::ClampEdge;
    sampler.Coordinate[2] = Rendering::ShaderFlags::SamplerCoordinate::ClampEdge;
    sampler.LodBias = 0.0f;
    sampler.Anisotropy = 1.0f;
    sampler.BorderColor = Mathematics::Float4(0.0f, 0.0f, 0.0f, 0.0f);
    samplers.push_back(sampler);
    return true;
}

Rendering::ShaderBaseSmartPointer AssistTools::FxCompiler
	::CreateShader(bool isVShader, const Program& program,
                   InputArray& inputs, OutputArray& outputs, ConstantArray& constants,
				   SamplerArray& samplers)
{
    const int numInputs = (int)inputs.size();
    const  int numOutputs = (int)outputs.size();
    const int numConstants = (int)constants.size();
    const int numSamplers = (int)samplers.size();

    Rendering::ShaderBaseSmartPointer shader;
    if (isVShader)
    {
        shader.reset(NEW0 Rendering::VertexShader(program.Name, numInputs, numOutputs,
            numConstants, numSamplers));
    }
    else
    {
        shader.reset(NEW0 Rendering::PixelShader(program.Name, numInputs, numOutputs,
            numConstants, numSamplers));
    }

    int i;
    for (i = 0; i < numInputs; ++i)
    {
        const Input& input = inputs[i];
        shader->SetInput(i, input.Name, input.Type, input.Semantic);
    }

    for (i = 0; i < numOutputs; ++i)
    {
        const Output& output = outputs[i];
        shader->SetOutput(i, output.Name, output.Type, output.Semantic);
    }

	Rendering::ShaderProfileDataSmartPointer 
		profile(NEW0 Rendering::ShaderProfileData(mActiveProfile,mActiveProfile));

    for (i = 0; i < numConstants; ++i)
    {
        const Constant& constant = constants[i];
        shader->SetConstant(i, constant.Name, constant.NumRegistersUsed);

		
		profile->SetBaseRegister(mActiveProfile, i, constant.BaseRegister);
    }

    for (i = 0; i < numSamplers; ++i)
    {
        const Sampler& sampler = samplers[i];
        shader->SetSampler(i, sampler.Name, sampler.Type);
        shader->SetFilter(i, sampler.Filter);
        shader->SetCoordinate(i, 0, sampler.Coordinate[0]);
        shader->SetCoordinate(i, 1, sampler.Coordinate[1]);
        shader->SetCoordinate(i, 2, sampler.Coordinate[2]);
        shader->SetLodBias(i, sampler.LodBias);
        shader->SetAnisotropy(i, sampler.Anisotropy);
        const Rendering::Colour<float> borderColor(sampler.BorderColor.GetFirstValue(),
			sampler.BorderColor.GetSecondValue(),sampler.BorderColor.GetThirdValue(),
			sampler.BorderColor.GetFourthValue());

        shader->SetBorderColor(i, borderColor);
        profile->SetTextureUnit(mActiveProfile, i, sampler.Unit);
    }

    profile->SetProgram(mActiveProfile, program.Text);

	shader->SetProfile(profile);
    return shader;
}

bool AssistTools::FxCompiler
	::UpdateShader(Rendering::ShaderBase* shader, const Program& program,
                   InputArray& inputs, OutputArray& outputs, ConstantArray& constants,
				   SamplerArray& samplers)
{
    const int numInputs = (int)inputs.size();
    if (numInputs != shader->GetNumInputs())
    {
        ReportError("Mismatch in number of inputs.\n");
        return false;
    }

    const int numOutputs = (int)outputs.size();
    if (numOutputs != shader->GetNumOutputs())
    {
        ReportError("Mismatch in number of outputs.\n");
        return false;
    }

    const int numConstants = (int)constants.size();
    if (numConstants != shader->GetNumConstants())
    {
        ReportError("Mismatch in number of constants.\n");
        return false;
    }

    const int numSamplers = (int)samplers.size();
    if (numSamplers != shader->GetNumSamplers())
    {
        ReportError("Mismatch in number of samplers.\n");
        return false;
    }

    std::string message;
    int i;
    for (i = 0; i < numInputs; ++i)
    {
        const Input& input = inputs[i];
        if (input.Name != shader->GetInputName(i))
        {
            message =  "Mismatch in input names '" +
                input.Name +
                "' and '" +
                shader->GetInputName(i);

            ReportError(message);
            return false;
        }
        if (input.Type != shader->GetInputType(i))
        {
            message =  "Mismatch in input types '" +
                msVTName[System::EnumCastUnderlying(input.Type)] +
                "' and '" +
                msVTName[System::EnumCastUnderlying(shader->GetInputType(i))];

            ReportError(message);
            return false;
        }
        if (input.Semantic != shader->GetInputSemantic(i))
        {
            message =  "Mismatch in input semantics '" +
                msVSName[System::EnumCastUnderlying(input.Semantic)] +
                "' and '" +
                msVSName[System::EnumCastUnderlying(shader->GetInputSemantic(i))];

            ReportError(message);
            return false;
        }
    }

    for (i = 0; i < numOutputs; ++i)
    {
        const Output& output = outputs[i];
        if (output.Name != shader->GetOutputName(i))
        {
            message =  "Mismatch in output names '" +
                output.Name +
                "' and '" +
                shader->GetOutputName(i);

            ReportError(message);
            return false;
        }
        if (output.Type != shader->GetOutputType(i))
        {
            message =  "Mismatch in output types '" +
                msVTName[System::EnumCastUnderlying(output.Type)] +
                "' and '" +
                msVTName[System::EnumCastUnderlying(shader->GetOutputType(i))];

            ReportError(message);
            return false;
        }
        if (output.Semantic != shader->GetOutputSemantic(i))
        {
            message =  "Mismatch in output semantics '" +
                msVSName[System::EnumCastUnderlying(output.Semantic)] +
                "' and '" +
                msVSName[System::EnumCastUnderlying(shader->GetOutputSemantic(i))];

            ReportError(message);
            return false;
        }
    }

	Rendering::ShaderProfileDataSmartPointer 
		profile(NEW0 Rendering::ShaderProfileData(mActiveProfile,mActiveProfile));

    for (i = 0; i < numConstants; ++i)
    {
        const  Constant& constant = constants[i];
        if (constant.Name != shader->GetConstantName(i))
        {
            message =  "Mismatch in constant names '" +
                constant.Name +
                "' and '" +
                shader->GetConstantName(i);

            ReportError(message);
            return false;
        }
        if (constant.NumRegistersUsed != shader->GetNumRegistersUsed(i))
        {
            char number0[8], number1[8];
            sprintf(number0, "%d", constant.NumRegistersUsed);
            sprintf(number1, "%d", shader->GetNumRegistersUsed(i));
            message =  "Mismatch in constant registers used '" +
                std::string(number0) +
                "' and '" +
                std::string(number1);

            ReportError(message);
            return false;
        }
        profile->SetBaseRegister(mActiveProfile, i, constant.BaseRegister);
    }

    for (i = 0; i < numSamplers; ++i)
    {
        const Sampler& sampler = samplers[i];
        if (sampler.Name != shader->GetSamplerName(i))
        {
            message =  "Mismatch in sampler names '" +
                sampler.Name +
                "' and '" +
                shader->GetSamplerName(i);

            ReportError(message);
            return false;
        }
        if (sampler.Type != shader->GetSamplerType(i))
        {
            message =  "Mismatch in sampler types '" +
                msSTName[System::EnumCastUnderlying(sampler.Type)] +
                "' and '" +
                msSTName[System::EnumCastUnderlying(shader->GetSamplerType(i))];

            ReportError(message);
            return false;
        }
        profile->SetTextureUnit(mActiveProfile, i, sampler.Unit);
    }

    profile->SetProgram(mActiveProfile, program.Text);

	shader->SetProfile(profile);
    return true;
}

void AssistTools::FxCompiler
	::ReportError(const std::string& message,
                  const TokenArray* tokens)
{
    Messages.push_back(message);
    if (tokens)
    {
        Messages.push_back(":");
        for (int i = 0; i < (int)tokens->size(); ++i)
        {
            Messages.push_back(" " + (*tokens)[i]);
        }
    }
    Messages.push_back("\n");

    ASSERTION_0(false, "FxCompiler error.\n");
}



// FxCompiler::Program

AssistTools::FxCompiler::Program
	::Program() noexcept
    :Name{},
    Text{}
{
}

#include STSTEM_WARNING_POP