﻿#ifndef ObjectAnimatorH
#define ObjectAnimatorH
#pragma once

#include "motion.h"

// refs
class ENGINE_API CObjectAnimator
{
private:
	using MotionVec = xr_vector<COMotion*>;
protected:
	bool				bLoop;

    shared_str			m_Name;
    
	Matrix4x4			m_XFORM;
    SAnimParams			m_MParam;
	MotionVec			m_Motions;
    float				m_Speed;

    COMotion*			m_Current;
	void				LoadMotions		(LPCSTR fname);
	void				SetActiveMotion	(COMotion* mot);
	COMotion*			FindMotionByName(LPCSTR name);
public:
						CObjectAnimator	();
	virtual				~CObjectAnimator();

	void				Clear			();
	void				Load			(LPCSTR name);
    IC LPCSTR			Name			() const {return *m_Name;}
    float&				Speed			(){return m_Speed;}

	COMotion*			Play			(bool bLoop, LPCSTR name=0);
	void				Pause			(bool val){return m_MParam.Pause(val);}
	void				Stop			();
	IC BOOL				IsPlaying		() const {return m_MParam.bPlay;}

    IC const Matrix4x4&	XFORM			() const {return m_XFORM;}
	float				GetLength		() const;
	// Update
	void				Update			(float dt);
    void				DrawPath		();
};

#endif //ObjectAnimatorH
