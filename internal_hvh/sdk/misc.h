#pragma once

class QAngle;
class Vector;

class NoticeText_t
{
public:
	wchar_t m_nString[ 512 ]; //0x0000 
	char pad_0x0400[ 0xC ]; //0x0400
	float set; //0x040C
	float m_flStartTime; //0x0410 
	float m_flStartTime2; //0x0414 
	float m_flLifeTimeModifier; //0x0418 
	char pad_0x041C[ 0x4 ]; //0x041C
}; //Size=0x420

class SFHudDeathNoticeAndBotStatus
{
public:
	char pad_0x00[ 0x68 ];
	CUtlVector<NoticeText_t>m_nDeathNotices;
};

extern SFHudDeathNoticeAndBotStatus* g_pDeathNotice;

class CUserCmd
{
public:
	virtual ~CUserCmd() {};
	int		command_number;
	int		tick_count;
	QAngle	viewangles;
	Vector	aimdirection;
	float	forwardmove;
	float	sidemove;
	float	upmove;
	int		buttons;
	byte    impulse;
	int		weaponselect;
	int		weaponsubtype;
	int		random_seed;
	short	mousedx;
	short	mousedy;
	bool	hasbeenpredicted;
	char	pad_0x4C[ 0x18 ];
};

class CCSWeaponData
{
public:

	virtual	~CCSWeaponData() {};

	//char		pad_vtable[ 0x4 ];		// 0x0
	char*		consoleName;			// 0x4
	char		pad_0[ 0xc ];			// 0x8
	int32_t		iMaxClip1;				// 0x14
	int32_t		iMaxClip2;				// 0x18
	int32_t		iDefaultClip1;			// 0x1c
	int32_t		iDefaultClip2;			// 0x20
	int32_t		iPrimaryReserveAmmoMax; // 0x24
	int32_t		iSecondaryReserveAmmoMax; // 0x28
	char*		szWorldModel;			// 0x2c
	char*		szViewModel;			// 0x30
	char*		szDroppedModel;			// 0x34
	char		pad_9[ 0x50 ];			// 0x38
	char*		szHudName;				// 0x88
	char*		szWeaponName;			// 0x8c
	char		pad_11[ 0x2 ];			// 0x90
	bool		bIsMeleeWeapon;			// 0x92
	char		pad_12[ 0x9 ];			// 0x93
	float_t		flWeaponWeight;			// 0x9c
	char		pad_13[ 0x2c ];			// 0xa0
	int32_t		iWeaponType;			// 0xcc
	int32_t		iWeaponPrice;			// 0xd0
	int32_t		iKillAward;				// 0xd4
	char		pad_16[ 0x4 ];			// 0xd8
	float_t		flCycleTime;			// 0xdc
	float_t		flCycleTimeAlt;			// 0xe0
	char		pad_18[ 0x8 ];			// 0xe4
	bool		bFullAuto;				// 0xec
	char		pad_19[ 0x3 ];			// 0xed
	int32_t		iDamage;				// 0xf0
	float_t		flArmorRatio;			// 0xf4
	int32_t		iBullets;				// 0xf8
	float_t		flPenetration;			// 0xfc
	char		pad_23[ 0x8 ];			// 0x100
	float_t		flWeaponRange;			// 0x108
	float_t		flRangeModifier;		// 0x10c
	float_t		flThrowVelocity;		// 0x110
	char		pad_26[ 0xc ];			// 0x114
	bool		bHasSilencer;			// 0x120
	char		pad_27[ 0xb ];			// 0x121
	char*		szBulletType;			// 0x12c
	float_t		flMaxSpeed;				// 0x130
	float_t		flMaxSpeedAlt;			// 0x134
	float		flSpread;				// 0x138
	float		flSpreadAlt;			// 0x13C
	float		flInaccuracyCrouch;		// 0x140
	float		flInaccuracyCrouchAlt;	// 0x144
	float		flInaccuracyStand;		// 0x148
	float		flInaccuracyStandAlt;	// 0x14C
	char		pad_29[ 0x34 ];			// 0x150
	int32_t		iRecoilSeed;			// 0x184
};

class CViewSetup
{
public:
	int			x, x_old;
	int			y, y_old;
	int			width, width_old;
	int			height, height_old;
	bool		m_bOrtho;
	float		m_OrthoLeft;
	float		m_OrthoTop;
	float		m_OrthoRight;
	float		m_OrthoBottom;
	bool		m_bCustomViewMatrix;
	matrix3x4_t	m_matCustomViewMatrix;
	char		pad_0x68[ 0x48 ];
	float		fov;
	float		fovViewmodel;
	Vector		origin;
	QAngle		angles;
	float		zNear;
	float		zFar;
	float		zNearViewmodel;
	float		zFarViewmodel;
	float		m_flAspectRatio;
	float		m_flNearBlurDepth;
	float		m_flNearFocusDepth;
	float		m_flFarFocusDepth;
	float		m_flFarBlurDepth;
	float		m_flNearBlurRadius;
	float		m_flFarBlurRadius;
	int			m_nDoFQuality;
	int			m_nMotionBlurMode;
	float		m_flShutterTime;
	Vector		m_vShutterOpenPosition;
	QAngle		m_shutterOpenAngles;
	Vector		m_vShutterClosePosition;
	QAngle		m_shutterCloseAngles;
	float		m_flOffCenterTop;
	float		m_flOffCenterBottom;
	float		m_flOffCenterLeft;
	float		m_flOffCenterRight;
	int			m_EdgeBlur;
};

class VarMapEntry_t
{
public:
	unsigned short type;
	unsigned short m_bNeedsToInterpolate;	// Set to false when this var doesn't
											// need Interpolate() called on it anymore.
	void *data;
	void *watcher;
};

class Quaternion				// same data-layout as engine's vec4_t,
{								//		which is a float[4]
public:
	inline Quaternion( void ) {}
	inline Quaternion( float ix, float iy, float iz, float iw ) : x( ix ), y( iy ), z( iz ), w( iw ) {}

	inline void Init( float ix = 0.0f, float iy = 0.0f, float iz = 0.0f, float iw = 0.0f ) { x = ix; y = iy; z = iz; w = iw; }

	float* Base() { return ( float* )this; }
	const float* Base() const { return ( float* )this; }

	float x, y, z, w;
};

class ALIGN16 QuaternionAligned : public Quaternion
{
public:
	inline QuaternionAligned( void ) {};
	inline QuaternionAligned( float X, float Y, float Z, float W )
	{
		Init( X, Y, Z, W );
	}
public:
	explicit QuaternionAligned( const Quaternion &vOther )
	{
		Init( vOther.x, vOther.y, vOther.z, vOther.w );
	}

	QuaternionAligned& operator=( const Quaternion &vOther )
	{
		Init( vOther.x, vOther.y, vOther.z, vOther.w );
		return *this;
	}
};

class C_AnimationLayer
{
public:
	char  pad_0000[ 20 ];
	uint32_t m_nOrder; //0x0014
	uint32_t m_nSequence; //0x0018
	float_t m_flPrevCycle; //0x001C
	float_t m_flWeight; //0x0020
	float_t m_flWeightDeltaRate; //0x0024
	float_t m_flPlaybackRate; //0x0028
	float_t m_flCycle; //0x002C
	void *m_pOwner; //0x0030 // player's thisptr
	char  pad_0038[ 4 ]; //0x0034
};

class ClientClass;
class CEventInfo
{
public:
	uint16_t classID; //0x0000 0 implies not in use
	char pad_0002[ 2 ]; //0x0002 
	float fire_delay; //0x0004 If non-zero, the delay time when the event should be fired ( fixed up on the client )
	char pad_0008[ 4 ]; //0x0008
	ClientClass *pClientClass; //0x000C
	void *pData; //0x0010 Raw event data
	char pad_0014[ 48 ]; //0x0014
}; //Size: 0x0044

class C_TEFireBullets
{
public:
	char pad[ 12 ];
	int		m_iPlayer; //12
	int _m_iItemDefinitionIndex;
	Vector	_m_vecOrigin;
	QAngle	m_vecAngles;
	int		_m_iWeaponID;
	int		m_iMode;
	int		m_iSeed;
	float	m_flSpread;
};

struct Item_t
{
	Item_t( std::string model, std::string icon = "" ) :
		model( model ),
		icon( icon )
	{
	}

	std::string model;
	std::string icon;
};

struct WeaponName_t
{
	WeaponName_t( int definition_index, std::string name ) :
		definition_index( definition_index ),
		name( name )
	{
	}

	int definition_index = 0;
	std::string name = nullptr;
};

struct QualityName_t
{
	QualityName_t( int index, std::string name ) :
		index( index ),
		name( name )
	{
	}

	int index = 0;
	std::string name;
};