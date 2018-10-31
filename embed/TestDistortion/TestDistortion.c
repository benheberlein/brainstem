/* ------------------------------------------------------------
author: "JOS, revised by RM"
name: "distortion"
version: "0.0"
Code generated with Faust 2.11.10 (https://faust.grame.fr)
Compilation options: c, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __TestDistortion_H__
#define  __TestDistortion_H__

/************************************************************************
 ************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------

    This is sample code. This file is provided as an example of minimal
    FAUST architecture file. Redistribution and use in source and binary
    forms, with or without modification, in part or in full are permitted.
    In particular you can create a derived work of this FAUST architecture
    and distribute that work under terms of your choice.

    This sample code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/

#include <math.h>
//#include "faust/gui/CGlue.h"
//#include "faust/gui/SoundUI.h"

#define max(a,b) ((a < b) ? b : a)
#define min(a,b) ((a < b) ? a : b)

/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


/******************************************************************************
*******************************************************************************

			ABSTRACT USER INTERFACE

*******************************************************************************
*******************************************************************************/

//----------------------------------------------------------------------------
//  FAUST generated signal processor
//----------------------------------------------------------------------------

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdlib.h>

static float TestDistortion_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS TestDistortion
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	float fRec1[2];
	FAUSTFLOAT fHslider1;
	float fRec2[2];
	float fVec0[2];
	float fRec0[2];
	int fSamplingFreq;
	
} TestDistortion;

TestDistortion* newTestDistortion() { 
	TestDistortion* dsp = (TestDistortion*)malloc(sizeof(TestDistortion));
	return dsp;
}

void deleteTestDistortion(TestDistortion* dsp) { 
	free(dsp);
}

//void metadataTestDistortion(MetaGlue* m) { 
//	m->declare(m->metaInterface, "author", "JOS, revised by RM");
//	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
//	m->declare(m->metaInterface, "basics.lib/version", "0.0");
//	m->declare(m->metaInterface, "description", "Distortion demo application.");
//	m->declare(m->metaInterface, "filename", "TestDistortionDemo");
//	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
//	m->declare(m->metaInterface, "filters.lib/version", "0.0");
//	m->declare(m->metaInterface, "misceffects.lib/name", "Faust Math Library");
//	m->declare(m->metaInterface, "misceffects.lib/version", "2.0");
//	m->declare(m->metaInterface, "name", "distortion");
//	m->declare(m->metaInterface, "signals.lib/name", "Faust Signal Routing Library");
//	m->declare(m->metaInterface, "signals.lib/version", "0.0");
//	m->declare(m->metaInterface, "version", "0.0");
//}

int getSampleRateTestDistortion(TestDistortion* dsp) { return dsp->fSamplingFreq; }

int getNumInputsTestDistortion(TestDistortion* dsp) {
	return 1;
	
}
int getNumOutputsTestDistortion(TestDistortion* dsp) {
	return 1;
	
}
int getInputRateTestDistortion(TestDistortion* dsp, int channel) {
	int rate;
	switch (channel) {
		case 0: {
			rate = 1;
			break;
		}
		default: {
			rate = -1;
			break;
		}
		
	}
	return rate;
	
}
int getOutputRateTestDistortion(TestDistortion* dsp, int channel) {
	int rate;
	switch (channel) {
		case 0: {
			rate = 1;
			break;
		}
		default: {
			rate = -1;
			break;
		}
		
	}
	return rate;
	
}

void classInitTestDistortion(int samplingFreq) {
	
}

void instanceResetUserInterfaceTestDistortion(TestDistortion* dsp) {
	dsp->fCheckbox0 = (FAUSTFLOAT)0.0f;
	dsp->fHslider0 = (FAUSTFLOAT)0.0f;
	dsp->fHslider1 = (FAUSTFLOAT)0.0f;
	
}

void instanceClearTestDistortion(TestDistortion* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			dsp->fRec1[l0] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			dsp->fRec2[l1] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			dsp->fVec0[l2] = 0.0f;
			
		}
		
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			dsp->fRec0[l3] = 0.0f;
			
		}
		
	}
	
}

void instanceConstantsTestDistortion(TestDistortion* dsp, int samplingFreq) {
	dsp->fSamplingFreq = samplingFreq;
	
}

void instanceInitTestDistortion(TestDistortion* dsp, int samplingFreq) {
	instanceConstantsTestDistortion(dsp, samplingFreq);
	instanceResetUserInterfaceTestDistortion(dsp);
	instanceClearTestDistortion(dsp);
}

void initTestDistortion(TestDistortion* dsp, int samplingFreq) {
	classInitTestDistortion(samplingFreq);
	instanceInitTestDistortion(dsp, samplingFreq);
}

//void buildUserInterfaceTestDistortion(TestDistortion* dsp, UIGlue* ui_interface) {
//	ui_interface->declare(ui_interface->uiInterface, 0, "tooltip", "Reference:   https://ccrma.stanford.edu/~jos/pasp/Cubic_Soft_Clipper.html");
//	ui_interface->openVerticalBox(ui_interface->uiInterface, "CUBIC NONLINEARITY cubicnl");
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox0, "0", "");
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox0, "tooltip", "When this is checked, the   nonlinearity has no effect");
//	ui_interface->addCheckButton(ui_interface->uiInterface, "Bypass", &dsp->fCheckbox0);
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "1", "");
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "tooltip", "Amount of distortion");
//	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Drive", &dsp->fHslider1, 0.0f, 0.0f, 1.0f, 0.00999999978f);
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "2", "");
//	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "tooltip", "Brings in even harmonics");
//	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Offset", &dsp->fHslider0, 0.0f, 0.0f, 1.0f, 0.00999999978f);
//	ui_interface->closeBox(ui_interface->uiInterface);
//	
//}

void computeTestDistortion(TestDistortion* dsp, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* output0 = outputs[0];
	int iSlow0 = (int)(float)dsp->fCheckbox0;
	float fSlow1 = (0.00100000005f * (float)dsp->fHslider0);
	float fSlow2 = (0.00100000005f * (float)dsp->fHslider1);
	/* C99 loop */
	{
		int i;
		for (i = 0; (i < count); i = (i + 1)) {
			dsp->fRec1[0] = (fSlow1 + (0.999000013f * dsp->fRec1[1]));
			dsp->fRec2[0] = (fSlow2 + (0.999000013f * dsp->fRec2[1]));
			float fTemp0 = (float)input0[i];
			float fTemp1 = max(-1.0f, min(1.0f, (dsp->fRec1[0] + (powf(10.0f, (2.0f * dsp->fRec2[0])) * (iSlow0?0.0f:fTemp0)))));
			float fTemp2 = (fTemp1 * (1.0f - (0.333333343f * TestDistortion_faustpower2_f(fTemp1))));
			dsp->fVec0[0] = fTemp2;
			dsp->fRec0[0] = (((0.995000005f * dsp->fRec0[1]) + fTemp2) - dsp->fVec0[1]);
			output0[i] = (FAUSTFLOAT)(iSlow0?fTemp0:dsp->fRec0[0]);
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			
		}
		
	}
	
}

#ifdef __cplusplus
}
#endif


//int main(int argc, char *argv[])
//{
////    TestDistortion* dsp = newmydsp();
////    deletemydsp(dsp);
//}

#endif
