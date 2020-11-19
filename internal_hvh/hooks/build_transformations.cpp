#include "../include_cheat.h"

void __fastcall hooks::build_transformations(void * ecx, void * edx, CStudioHdr * hdr, Vector * pos, Quaternion * q, const matrix3x4_t & transform, int32_t mask, byte * computed)
{
	 //backup bone flags.
	const auto backup_bone_flags = hdr->m_boneFlags;
	
	// stop procedural animations.
	for ( auto i = 0; i < hdr->m_boneFlags.Count(); i++ )
		hdr->m_boneFlags.Element(i) &= BONE_ALWAYS_PROCEDURAL;
	
	orig_build_transformations( ecx, hdr, pos, q, transform, mask, computed );
	
	// restore bone flags.
	hdr->m_boneFlags = backup_bone_flags;
}