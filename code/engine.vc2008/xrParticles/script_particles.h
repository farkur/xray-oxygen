////////////////////////////////////////////////////////////////////////////
//	Module 		: script_particles.h
//	Created 	: 27.07.2004
//  Modified 	: 27.07.2004
//	Author		: Alexander Maximchuk
//	Description : XRay Script particles class
////////////////////////////////////////////////////////////////////////////
#pragma once
#include "../xrScripts/export/script_export_space.h"
#include "../xrParticles/psystem.h"
#include "../xrParticles/ParticlesObject.h"

// refs
class CObjectAnimator;
class CScriptParticles;

class PARTICLES_API CScriptParticlesCustom: public CParticlesObject
{
	CObjectAnimator*			m_animator;
	virtual						~CScriptParticlesCustom();
	CScriptParticles*			m_owner;
public:
								CScriptParticlesCustom(CScriptParticles* owner, LPCSTR caParticlesName);
	virtual void				shedule_Update		(u32 dt);

	void						LoadPath			(LPCSTR caPathName);
	void						StartPath			(bool looped);
	void						StopPath			();
	void						PausePath			(bool val);
	virtual void				PSI_internal_delete	();
	virtual void				PSI_destroy			();
			void				remove_owner		();
};

class PARTICLES_API CScriptParticles
{
 private:
	 Matrix4x4					m_transform;
public:
	CScriptParticlesCustom*		m_particles;
								CScriptParticles	(LPCSTR caParticlesName);
	virtual						~CScriptParticles	();

	void						Play				();
	void						PlayAtPos			(const Fvector &pos);
	void						Stop				();
	void						StopDeffered		();

	bool						IsPlaying			() const;
	bool						IsLooped			() const;
	void						SetDirection		(const Fvector &dir);
 	void						SetOrientation		(float yaw, float pitch, float roll);
 	Fvector						LastPosition		() const { return m_transform.w; }

	void						MoveTo				(const Fvector &pos, const Fvector& vel);

	void						LoadPath			(LPCSTR caPathName);
	void						StartPath			(bool looped);
	void						StopPath			();
	void						PausePath			(bool val);

	DECLARE_SCRIPT_REGISTER_FUNCTION
};
add_to_type_list(CScriptParticles)
#undef script_type_list
#define script_type_list save_type_list(CScriptParticles)