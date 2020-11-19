#include "../include_cheat.h"

void _fastcall hooks::do_extra_bone_processing( void* ecx, void* edx, CStudioHdr* hdr, Vector* pos, Quaternion* q, const matrix3x4_t& matrix, byte* boneComputed, CIKContext* context )
{
	/*if ( g_pLocalPlayer && ecx == g_pLocalPlayer )
		return;*/

	auto player = reinterpret_cast< C_CSPlayer* >( ecx );

	if ( player->get_effects() & EF_NOINTERP )
		return;

	const auto animstate = player->get_anim_state();
	if ( !animstate || animstate->pBaseEntity )
		return orig_do_extra_bone_processing(ecx, hdr, pos, q, matrix, boneComputed, context);

	const auto on_ground = animstate->m_bOnGround;

	animstate->m_bOnGround = false;

	orig_do_extra_bone_processing( ecx, hdr, pos, q, matrix, boneComputed, context );

	animstate->m_bOnGround = on_ground;
}